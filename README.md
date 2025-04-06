# Project: Data-Stuctures_Hash-Table
> Imported from Project Folder; Spring 24

## Description
Code a data structure and algorithm to hold 100,000 student data entries as efficiently as possible; uses chaining hash function.. Functions included to support adding, searching, removing and updating student data entires. Also includes outputting to CSV file.

Link to presentation: https://docs.google.com/presentation/d/1ER2O8_GEnVhEl4CR3zxPsYWKNhucwZmYMAiwHIvGzc0/edit#slide=id.p

Below is an example of an output:
```
--------------Menu--------------
1. Insert a student
2. Search with student ID
3. Search with student name
4. Delete a student
5. Update a student
6. Write all data to desired file
7. Quit
Enter choice as a number:1

Enter an ID to insert: 112233
Enter name: John Doe
Enter DOB: 01/01/2000
Enter street: Awesome St
Enter city: Coolvile
Enter state: TX
Enter zip: 12345
Student added

--------------Menu--------------
1. Insert a student
2. Search with student ID
3. Search with student name
4. Delete a student
5. Update a student
6. Write all data to desired file
7. Quit
Enter choice as a number:6

Enter name of file: outputFile
Outputting hash table to file...
Data has been written to outputFile successfully.


outputFile.txt:
StudentID,Name,DOB,Street,City,State,Zip
112233,John Doe,01/01/2000,Awesome St,Coolvile,TX,12345
```

