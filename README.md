To run the code in the terminal, follow these steps:
1. **Preliminary steps:**

	-- a. Make sure you are in the src folder (`cd src`). 

	-- b. Then compile using: `g++ -g *.cpp -o main`

	-- c. Run the program using: `./main`
2. Enter a US zip code, then press ENTER (RETURN on Mac).
3. The program will print the 10 closest homes to your zip code, based on locations listed in the real_estate.csv file. For each location there is information on its address, city, state, its distance to your zip code, the year it was built (if known), whether it is available for lease/rent or for purchase/ownership, the number of parking spaces, and whether it is ADA compliant. If you wish to enter another zip code, run the program again using `./main`.