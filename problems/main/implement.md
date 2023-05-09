# Implementation

To implement the described functionality, a program can be designed with the following steps:

1. Declare a structure to hold the shoe inventory information, including stock number, style number, quantity in different sizes, and price.
2. Declare an array of the structure with a maximum number of items to be stored in the inventory.
3. Use a loop to keep the program running indefinitely until the user chooses to exit.
4. Within the loop, present the user with a menu of choices: enter a new record, display a record, change the price of the stock item, or change the number on hand.
5. Depending on the user's choice, prompt for the necessary information to perform the selected operation.
6. For entering a new record, prompt the user for the stock number, style number, quantity in different sizes, and price. Store the information in the next available slot in the inventory array.
7. For displaying a record, prompt the user for the stock number or style number and search the inventory array for the matching record. If found, display all the information for the record.
8. For changing the price of a stock item, prompt the user for the stock number or style number and the new price. If found, update the price for the matching record.
9. For changing the number on hand, prompt the user for the stock number or style number and the sizes to be changed. If found, prompt for the new quantity in each size and update the inventory accordingly.
10. After each operation, display the current inventory to the user to show the changes made.

By implementing the above steps, the program will be able to keep track of changes in the shoe inventory and allow the user to perform various operations on the inventory data.
