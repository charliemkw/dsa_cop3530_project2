import React, { useState } from 'react';
import { MapContainer, TileLayer, Marker, Popup, useMap } from 'react-leaflet';
import 'leaflet/dist/leaflet.css';
import './App.css';
import L from 'leaflet';

// default marker icons
delete L.Icon.Default.prototype._getIconUrl;
L.Icon.Default.mergeOptions({
  iconRetinaUrl: require('leaflet/dist/images/marker-icon-2x.png'),
  iconUrl: require('leaflet/dist/images/marker-icon.png'),
  shadowUrl: require('leaflet/dist/images/marker-shadow.png'),
});

// map zoom/pan
function ChangeMapView({ center, zoom }) {
  const map = useMap();
  map.setView(center, zoom);
  return null;
}

function App() {
  const [address, setAddress] = useState('');// NEED TO CHANGE WHEN CHARLIE Is DONE WITH GEOCODING
  const [city, setCity] = useState('');
  const [state, setState] = useState('');
  const [zip, setZip] = useState('');
  const [mapCenter, setMapCenter] = useState([39.8283, -98.5795]); // middle of US
  const [mapZoom, setMapZoom] = useState(4);
  const [markers, setMarkers] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState('');
//display top 10 resumts
    const handleSearch = async () => {
      if (!zip || !/^\d{5}$/.test(zip)) {
        alert('Please enter a valid 5-digit ZIP code!');
        return;
      }
      setLoading(true);
      setError('');

      try {
        const response = await fetch('http://localhost:3001/api/find-locations', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ zipcode: zip })
        });
        const data = await response.json();
        const newMarkers = data.locations.map((loc, index) => ({
          id: index,
          position: [loc.latitude || mapCenter[0], loc.longitude || mapCenter[1]],
          name: loc.address,
          distance: `${loc.distance.toFixed(2)} miles`,
          city: loc.city,
          state: loc.state,
          parking: loc.parking_spaces,
          accessibility: loc.accessibility,
          owned: loc.owned

        }));
          setMarkers(newMarkers);
        } catch (err) {
          setError('Unable to connect to server');
        } finally {
          setLoading(false);
        }
      };





  return (
      <div className="App">
        <header className="App-header">
          <h1>🏠 ADA-Compliant Housing Finder</h1>
          <p>Team 38: Veronica Igwe, Jingtong Zeng, Charlie Willis</p>
        </header>

        <div className="main-container">

          {/* map on the left*/}
          <div className="map-section">
            <MapContainer
                center={mapCenter}
                zoom={mapZoom}
                style={{ height: '100%', width: '100%' }}
            >
              <ChangeMapView center={mapCenter} zoom={mapZoom} />
              <TileLayer
                  url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
                  attribution='&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
              />

              {/* User location marker (blue) */}
              {mapZoom > 4 && (
                  <Marker position={mapCenter}>
                    <Popup>
                      <strong>Your Location</strong><br />
                      {address}<br />
                      {city}, {state} {zip}
                    </Popup>
                  </Marker>
              )}

              {/* ADA Housing in red */}
              {markers.map(marker => (
                  <Marker key={marker.id} position={marker.position}>
                    <Popup>
                      <strong>{marker.name}</strong><br />
                      Distance: {marker.distance}<br />
                      <em>ADA Compliant</em>
                    </Popup>
                  </Marker>
              ))}
            </MapContainer>
          </div>

          {/* reseach and results on the right */}
          <div className="sidebar">
            <div className="search-section">
              <h2>Enter Your Address</h2>

              <div className="input-group">
                <label>Street Address</label>
                <input
                    type="text"
                    value={address}
                    onChange={(e) => setAddress(e.target.value)}
                    placeholder="123 Main Street"
                />
              </div>

              <div className="input-group">
                <label>City</label>
                <input
                    type="text"
                    value={city}
                    onChange={(e) => setCity(e.target.value)}
                    placeholder="Gainesville"
                />
              </div>

              <div className="input-row-small">
                <div className="input-group">
                  <label>State</label>
                  <input
                      type="text"
                      value={state}
                      onChange={(e) => setState(e.target.value)}
                      placeholder="FL"
                      maxLength="2"
                  />
                </div>

                <div className="input-group">
                  <label>Zip</label>
                  <input
                      type="text"
                      value={zip}
                      onChange={(e) => setZip(e.target.value)}
                      placeholder="32611"
                      maxLength="5"
                  />
                </div>
              </div>

              <button onClick={handleSearch} className="search-btn">
                🔍 Find ADA Housing
              </button>
            </div>

            {/* list of results */}
            <div className="results-section">
              <h3>Nearby ADA-Compliant Properties</h3>
              {markers.length === 0 ? (
                  <p className="no-results">Enter your address and click search to see results</p>
              ) : (
                  <div className="results-list">
                    {markers.map((marker, idx) => (
                        <div key={marker.id} className="result-item">
                          <div className="result-number">#{idx + 1}</div>
                          <div className="result-info">
                            <strong>{marker.name}</strong>
                            <p className="distance">📍 {marker.distance} away</p>
                          </div>
                        </div>
                    ))}
                  </div>
              )}
            </div>
          </div>
        </div>
      </div>
  );
}

export default App;