#include <cstddef>
#include <iostream>
#include "Header.h"
#include <iomanip>

using namespace std;

void printMenu() {
	cout << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------------------------------------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t\t\t|                                          | Menu Table |                                             |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------------------------------------------------------------------------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [1] - Insert Customer | [2] - Print Customer   | [3] - Delete Customer    | [4] - Edit Customer     |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+-------------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [5] - Insert Supplier | [6] - Print Supplier   | [7] - Delete Supplier    | [8] - Edit Supplier     |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+-------------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [9] - Insert Item     | [10] - Print Item      | [11] - Delete Item       | [12] - Edit Item        |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+-------------------------+" << endl;
	cout << "\t\t\t\t\t\t\t| [13] - Receiving      | [14] - sale            | [15] - Clear the screen  | [16] - Print Menu table |" << endl;
	cout << "\t\t\t\t\t\t\t+-----------------------+------------------------+--------------------------+-------------------------+\n" << endl;
}
void receiving(Items_List& i1) {
	int barcode;
	int quantity;
	int totPrice;

	// Valid barcode is to be an integer
	while (true) {
		cout << "\n\t\t\tBarcode                      : ";
		if (cin >> barcode) {
			break;  // Exit from the loop if a valid integer is entered
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the barcode." << endl;
			cin.clear();  // Remove the error 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the the whole wrong input 
		}
	}

	// Valid quantity is to be an integer
	while (true) {
		cout << "\t\t\tQuantity                     : ";
		if (cin >> quantity) {
			break;
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the quantity." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	// Valid total Price is to be an number
	while (true) {
		cout << "\t\t\tTotal price of item (Rs/-)   : ";
		if (cin >> totPrice) {
			break;
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the total price." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	cout << endl;
	i1.searchInReceiveItem(barcode, quantity, totPrice);
}
void sale(Items_List& i1) {
	int barcode;
	int quantity;
	int subTotal;

	// Valid barcode is to be an integer
	while (true) {
		cout << "\n\t\t\tBarcode                          : ";
		if (cin >> barcode) {
			break;
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the barcode." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	// Valid quantity is to be an integer
	while (true) {
		cout << "\t\t\tQuantity                         : ";
		if (cin >> quantity) {
			break;
		}
		else {
			cout << "\t\t\tInvalid input. Please enter an integer for the quantity." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	cout << "\t\t\tSub Total price of item (Rs/-)   : " << i1.searchSellPrice(barcode) * quantity << endl;

	i1.searchInSaleItem(barcode, quantity);
}
void selectMenu(Transactions_List& t1, Transactions_List& t2, Items_List& i1) {
	string choice;
	cin >> choice;

	if (choice == "1") {
		t1.insertCustomer();
		//system("cls");
		//printMenu();
	}
	else if (choice == "2") {
		t1.printCustomer();
	}
	else if (choice == "3") {
		t1.printCustomer();
		int a;
		cout << "\n\t\t\t# Which customer do you want to delete choose position from above table : ";
		cin >> a;
		t1.deleteCustomer(a - 1);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully deleted choosed position" << endl;
	}
	else if (choice == "4") {
		t1.printCustomer();
		int b;
		cout << "\n\t\t\t# Which customer do you want to edit choose position from above table : ";
		cin >> b;
		t1.editCustomer(b - 1);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully editeded choosed position " << endl;

	}
	else if (choice == "5") {
		t2.insertSupplier();
		//system("cls");
		//printMenu();
	}
	else if (choice == "6") {
		t2.printSupplier();
	}
	else if (choice == "7") {
		t2.printSupplier();
		int c;
		cout << "\n\t\t\t# Which supplier do you want to delete choosed position from above table : ";
		cin >> c;
		t2.deleteSupplier(c - 1);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully deleted choosed position " << endl;
	}
	else if (choice == "8") {
		t2.printSupplier();
		int d;
		cout << "\n\t\t\t# Which supplier do you want to edit choose position from above table : ";
		cin >> d;
		t2.editSupplier(d - 1);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully editeded choosed position " << endl;
	}
	else if (choice == "9") {
		i1.insertItem();
		//system("cls");
		//printMenu();
	}
	else if (choice == "10") {
		i1.printItem_list();
	}
	else if (choice == "11") {
		i1.printItem_list();
		int e;
		cout << "\n\t\t\t# Which item do you want to delete choose position from above table : ";
		cin >> e;
		i1.deleteItem(e - 1);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully deleted choosed position " << endl;
	}
	else if (choice == "12") {
		i1.printItem_list();
		int f;
		cout << "\n\t\t\t# Which item do you want to edit choose BARCODE from above table : ";
		cin >> f;
		i1.editItem(f);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully editeded choosed position " << endl;
	}
	else if (choice == "13") {
		i1.printItem_list();
		receiving(i1);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully updated " << endl;
	}
	else if (choice == "14") {
		i1.printItem_list();
		sale(i1);
		//system("cls");
		//printMenu();
		cout << "\n\t\t\t# Successfully updated and calculated " << endl;
	}
	else if (choice == "15") {
		system("cls");
		printMenu();
	}
	else if (choice == "16") {
		printMenu();
	}
	else {
		cout << "\n\t\t# Invalid choice. Try again!\n";
	}

	cout << "\n\t\tChoose another option from the above list :  ";
	selectMenu(t1, t2, i1);
}

int main() {

	Transactions_List t1;	// This is for the customer object
	Transactions_List t2;	// This is for the supplier object
	Items_List i1;          // This is the item list object

	printMenu();
	cout << "\t\tGive the number from Menu table       :  ";;
	selectMenu(t1, t2, i1);
}
