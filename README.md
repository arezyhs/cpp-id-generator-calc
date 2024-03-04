# C++ ID Generator Calculator for Data Structures Lab

This C++ program is designed as an ID generator for Data Structures, following specific rules for ID creation. The ID generation is based on the following criteria:

### ID Rules:
- The ID consists of 5 digits.
- The first two digits represent the absolute difference between the first and last letters of the driver's name. For example, if the driver's name is "Sugeng Pangestu," and the first letter is 'S' and the last letter is 'U,' then the first two digits are 19 - 21, resulting in 02.
- The third digit is determined by the gender of the driver. If the driver is male, the third digit is 1; otherwise, it is 0. For instance, if Sugeng Pangestu is male, the first three digits of his ID would be 021.
- The fourth digit is obtained by summing the last digits of the driver's birthdate (day, month, and year) and taking the modulus of 9. For example, if Sugeng's birthdate is 21-02-1999, the first four digits would be 0213.
- The fifth digit is initially set to 0. In case of duplicate IDs, this digit will be incremented. If it reaches 9, it will reset to 0, and an additional digit will be added to the ID. This process continues until a unique ID is generated.

### Example:
   Driver: Sugeng Pangestu
   - Name : Sugeng Pangestu -> S-u = 19-21 = 2
   - Gender: Male (1)
   - Birthdate: 21-02-1999 (last digits sum: 1+2+9 = 12, modulus 9 = 3)
   - Initial fifth digit: 0

   So, the generated ID: 02130

Note: If duplicate IDs occur, the fifth digit will be incremented until a unique ID is obtained, and additional digits will be added as needed.

### Known Problem
- This calc unable to generate 6-digit-id. The program should properly reset the fifth digit to 0 and add an additional digit when it reaches 9, ensuring the creation of a 6-digit ID as needed.



