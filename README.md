Overview

This C++ project implements a simple inventory management system. The system maintains a list of customers, suppliers, and items, and allows basic operations like insertion, deletion, editing, and searching. The primary classes involved are TempCustomer, Transactions_List, TempItem, and Items_List.

Classes and Their Functions

1. TempCustomer
   
A class representing a temporary customer or supplier in the system.

Attributes:

string name: The name of the customer/supplier.
int ctNo: The contact number of the customer/supplier.
TempCustomer* next: A pointer to the next customer/supplier in the list.
Constructors:
Default constructor: Initializes name to an empty string and ctNo to 0.
Overloaded constructor: Takes name and ctNo as parameters and initializes the respective attributes.

2. Transactions_List
   
A class that manages the list of customers or suppliers.

Attributes:

TempCustomer* head: Pointer to the first customer/supplier in the list.
TempCustomer* tail: Pointer to the last customer/supplier in the list.
int size: The current size of the list.
Functions:

insertCustomer(): Adds a new customer to the list.
insertSupplier(): Adds a new supplier to the list.
printCustomer(): Prints all customers in a formatted table.
printSupplier(): Prints all suppliers in a formatted table.
delete_First(): Deletes the first customer/supplier from the list.
delete_Last(): Deletes the last customer/supplier from the list.
deleteCustomer(int pos): Deletes a customer at a specific position.
deleteSupplier(int pos): Deletes a supplier at a specific position.
editCustomer(int pos): Edits the details of a customer at a specific position.
editSupplier(int pos): Edits the details of a supplier at a specific position.

3. TempItem
   
A class representing a temporary item in the system.

Attributes:

string name: The name of the item.
int barcode: The barcode of the item.
float costPrice: The cost price of the item.
float sellPrice: The selling price of the item.
int quantity: The quantity of the item.
TempItem* next: A pointer to the next item in the list.

Constructors:

Default constructor: Initializes name to an empty string, and quantity to 0.
Overloaded constructor: Takes name, barcode, and sellPrice as parameters and initializes the respective attributes.

4. Items_List
   
A class that manages the list of items.

Attributes:

TempItem* head: Pointer to the first item in the list.
TempItem* tail: Pointer to the last item in the list.
int size: The current size of the list.

Functions:

insertItem(): Adds a new item to the list.
printItem_list(): Prints all items in a formatted table.
delete_First(): Deletes the first item from the list.
delete_Last(): Deletes the last item from the list.
deleteItem(int pos): Deletes an item at a specific position.
editItem(int code): Edits the details of an item identified by the barcode.
searchInReceiveItem(int code, int quant, int totalPrice): Updates the quantity and cost price of an item based on a received shipment.
searchInSaleItem(int code, int quant): Updates the quantity of an item after a sale.
searchSellPrice(int code): Returns the selling price of an item identified by the barcode.

How to Use

Insertion: Use the insertCustomer(), insertSupplier(), or insertItem() functions to add new entries to the respective lists.
Printing: Use the printCustomer(), printSupplier(), or printItem_list() functions to view all entries in the lists.
Deletion: Use deleteCustomer(int pos), deleteSupplier(int pos), or deleteItem(int pos) to remove an entry from a specific position in the list.
Editing: Use editCustomer(int pos), editSupplier(int pos), or editItem(int code) to modify an existing entry.
Searching: Use searchInReceiveItem(int code, int quant, int totalPrice), searchInSaleItem(int code, int quant), or searchSellPrice(int code) to find or update specific items.

Future Enhancements

Implement error handling for invalid inputs and operations.
Add file handling for saving and loading data.
Enhance the user interface for easier navigation and usage.
Compilation
To compile the program, use a C++ compiler like g++:

Conclusion

This project provides a basic inventory management system with functionality for managing customers, suppliers, and items. It serves as a foundational project for learning linked lists and basic CRUD operations in C++.
