const express = require('express'); const cors = require('cors'); const { spawn } = 
require('child_process'); const path = require('path'); const app = express(); const 
PORT = 3001; app.use(cors()); app.use(express.json()); app.post('/api/find-locations', 
(req, res) => {
    const { zipcode } = req.body;

    console.log(`Received request for zipcode: ${zipcode}`);

    if (!zipcode || !/^\d{5}$/.test(zipcode)) {
        return res.status(400).json({ error: 'Invalid ZIP code' });
    }

    const cppExecutablePath = path.join(__dirname, 'ada_finder'); const cppProcess = 
    spawn(cppExecutablePath);

    let stdout = ''; let stderr = '';

    cppProcess.stdout.on('data', (data) => {
        stdout += data.toString();
    });

    cppProcess.stderr.on('data', (data) => {
        stderr += data.toString();
    });

    cppProcess.on('close', (code) => {
        if (code !== 0) {
            return res.status(500).json({ error: 'Failed to process request' });
        }

        try {
            const locations = parseOutput(stdout); if (locations.length === 0) {
                return res.json({ error: `No locations found for ZIP ${zipcode}`, locations: 
[] });
            } res.json({ locations });
        } catch (error) {
            res.status(500).json({ error: 'Failed to parse results' });
        }
    });

    cppProcess.on('error', (error) => {
        res.status(500).json({ error: 'Failed to start backend process' });
    });

    cppProcess.stdin.write(`${zipcode}\n`); cppProcess.stdin.end(); }); function 
parseOutput(output) {
    const locations = []; const lines = output.split('\n'); let currentLocation = null; let 
    locationNumber = 0;

    for (let i = 0; i < lines.length; i++) {
        const line = lines[i].trim();

        if (line.includes('~~~ LOCATION #')) {
            if (currentLocation) {
                locations.push(currentLocation);
            } locationNumber++; currentLocation = {
                rank: locationNumber, address: '', city: '', state: '', distance: null, 
                parking_spaces: null, accessibility: '', owned: false, active: false
            };
        } else if (currentLocation && line) {
            if (line.includes(',') && !currentLocation.address) {
                const parts = line.split(',').map(p => p.trim()); if (parts.length >= 2) {
                    currentLocation.address = parts[0]; currentLocation.city = parts[1]; if 
                    (parts.length >= 3) {
                        currentLocation.state = parts[2];
                    }
                }
            } else if (line.includes('miles away')) {
                const match = line.match(/([\d.]+)\s*miles/); 
		if (match) {
                    currentLocation.distance = parseFloat(match[1]);
                }
            } else if (line.includes('available for')) {
                currentLocation.owned = line.includes('purchase'); 
		currentLocation.active = true;
            } else if (line.includes('parking spaces')) {
                const match = line.match(/(\d+)\s*parking spaces/); 
		if (match) {
                    currentLocation.parking_spaces = parseInt(match[1]);
                }
            } else if (line.includes('ACCESSIBILITY STATUS:')) {
                const match = line.match(/ACCESSIBILITY STATUS:\s*(.+)/); if (match) {
                    currentLocation.accessibility = match[1].trim();
                }
            }
        }
    }

    if (currentLocation){ 
	if (currentLocation.address) {
        locations.push(currentLocation);
}    }
	return locations;

} app.listen(PORT,()=> {
    console.log('Backend server running on http://localhost:3001');
});
