# C++ ID Generator for Data Structures Lab

## Overview

This C++ program serves as an ID generator tailored for Data Structures, implementing specific rules for ID creation. The program consists of two main functions, `buatIDBaru` and `buatIDOrder`, responsible for generating unique driver IDs (`ID SUPIR`) and order IDs (`ID Order`), respectively.

## Features

### ID Rules:

**1. ID GENERATOR FOR DRIVER:**
   - The ID consists of 5 digits.
   - The first two digits represent the absolute difference between the first and last letters of the driver's name.
   - The third digit signifies the gender of the driver (1 for male, 0 for female).
   - The fourth digit is obtained by summing the last digits of the driver's birthdate (day, month, and year) and taking the modulus of 9.
   - The fifth digit is initially set to 0. In case of duplicate IDs, this digit is incremented. If it reaches 9, it resets to 0, and an additional digit is added to the ID.
  
  ### Example:
   - Driver: Sugeng Pangestu
   - Name : Sugeng Pangestu -> S-u = 19-21 = 2
   - Gender: Male (1)
   - Birthdate: 21-02-1999 (last digits sum: 1+2+9 = 12, modulus 9 = 3)
   - Initial fifth digit: 0
   So, the generated ID SUPIR: 02130

**2. ID GENERATOR FOR DRIVER AND ORDER:**
   - The ID consists of 10 digits.
   - The first two digits represent the alphabetical order of the first character on the license plate of the taxi.
   - Digits 3 to 7 represent the driver's ID. For example, for the driver "Sugeng Pangestu," the first 7 digits would be 1216130.
   - Digits 8 and 9 are obtained from the order's destination, considering the last 2 characters. For instance, for the destination "Ketintang," the next 2 digits would be 21.
   - The last digit is derived from the sum of the alphabetical order of all characters in the customer's name, with the last digit taken if the sum is more than one digit.

   ### Example:
   Driver: Sugeng Pangestu -> 02130
   - License Plate: L 1996 YZ -> L = 12
   - Destination: Ketintang -> n + g = 7 + 14 = 21
   - Customer Name: Komeng -> sum of komeng and take the last digit of that sum = 5
   So, the generated ID Order is 1202130215

### Known Problem

- The program was initially unable to generate a 6-digit ID. The latest version has fixed this issue by resetting the fifth digit to 0 and adding an additional digit when it reaches 9, ensuring the creation of a 6-digit ID as needed.

## How to Use

1. Modify the test data for the driver (`namaSupir`, `genderSupir`, `tanggalLahirSupir`) and customer (`platNomor`, `tujuan`, `namaPelanggan`) in the `main` function.
2. Run the program to generate the Driver ID (`ID SUPIR`) and Order ID (`ID Order`).
3. Review the console output for the generated IDs.

## Requirements

- C++ compiler
- Standard C++ libraries

## Disclaimer

This program assumes proper input data adherence to avoid errors and unexpected behavior.
Feel free to use and modify this program for your educational purposes. If you encounter any issues or have suggestions for improvement, please let us know.
Happy coding!
