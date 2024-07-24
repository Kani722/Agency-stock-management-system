#pragma once
#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>   // setw() functions

using namespace std;

class TempCustomer {
public:
	string name;
	int ctNo;
	TempCustomer* next;

	TempCustomer() { // Default constructor
		name = "";
		ctNo = 0;

	}
	TempCustomer(string name, int ctNo) { // Overloaded constructor
		this->name = name;
		this->ctNo = ctNo;
	}
};

class Transactions_List {
private:
	TempCustomer* head;
	TempCustomer* tail;
	int size;

public:
	Transactions_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertCustomer() {

		string Name;
		int Ctno;

		cout << "\n\t\t\tCustomer name                       : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
		getline(cin, Name);

		// Validate Ctno is to be a 10-digit integer including zero so, lenght == 9
		while (true) {
			cout << "\t\t\tCustomer contact number(0XXXXXXXXX) : ";
			if (cin >> Ctno && to_string(Ctno).length() == 9) {
				break;  // Exit the loop if a valid 10-digit integer is entered
			}
			else {
				cout << "\t\t\tInvalid input. Please enter a 10-digit integer having first digit zero." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		TempCustomer* temp = new TempCustomer(Name, Ctno);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}

	void insertSupplier() {

		string Name;
		int Ctno;

		cout << "\n\t\t\tSupplier name                       : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input 
		getline(cin, Name);

		// Validate Ctno is to be a 10-digit integer including zero so, lenght == 9
		while (true) {
			cout << "\t\t\tSupplier contact number(0XXXXXXXXX) : ";
			if (cin >> Ctno && to_string(Ctno).length() == 9) {
				break;  // Exit the loop if a valid 10-digit integer is entered
			}
			else {
				cout << "\t\t\tInvalid input. Please enter a 10-digit integer having first digit zero." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		TempCustomer* temp = new TempCustomer(Name, Ctno);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void printCustomer() {

		TempCustomer* current = head;
		if (head == NULL) {
			cout << "\n\t# There is no customer to print." << endl;
		}
		else {
			cout << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\t\t|     [CUSTOM NAME]    |    [CONTACT NUMBER]    |" << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			for (int i = 0; i < size; i++) {
				cout << "\t\t\t\t\t\t\t" << "|" << setw(21) << current->name << " |           " << setw(12) << current->ctNo << " |" << endl;  // Ctno should be less than 10
				cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
				current = current->next;
			}
			cout << endl;
		}
	}
	void printSupplier() {
		TempCustomer* current = head;
		if (head == NULL) {
			cout << "\n\t# There is no supplier to print." << endl;
		}
		else {
			cout << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\t\t|     [SUPPLY NAME]    |    [CONTACT NUMBER]    |" << endl;
			cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
			for (int i = 0; i < size; i++) {
				cout << "\t\t\t\t\t\t\t" << "|" << setw(21) << current->name << " |           " << setw(12) << current->ctNo << " |" << endl;  // Ctno should be less than 10
				cout << "\t\t\t\t\t\t\t+-----------------------------------------------+" << endl;
				current = current->next;
			}
			cout << endl;
		}
	}
	void delete_First() {
		if (head == NULL)
			cout << "Empty" << endl;
		else {
			TempCustomer* temp = head;

			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				delete temp;
				size--;
			}
		}

	}

	void delete_Last() {

		if (head == NULL)
			cout << "Empty" << endl;
		else {
			TempCustomer* temp = tail;

			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				TempCustomer* current = head;

				for (int i = 0; i < size - 2; i++) {
					current = current->next;
				}
				tail = current;
				tail->next = NULL;
				delete temp;
				size--;
			}
		}

	}

	void deleteCustomer(int pos) {   // deleteCoustomer at ------> we are only this for detele operation
		if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no customer at this position." << endl;
		}
		else if (pos == 0) {
			delete_First();
		}
		else if (pos == size - 1) {
			delete_Last();
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			TempCustomer* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}
	void deleteSupplier(int pos) { // deleteSupplier at ------> we are only this for detele operation
		if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no supplier at this position." << endl;
		}
		else if (pos == 0) {
			delete_First();
		}
		else if (pos == size - 1) {
			delete_Last();
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			TempCustomer* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}
	void editCustomer(int pos) {


		if (head == NULL) {
			cout << "\n\t# No customer to edit." << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no customer at this position." << endl;
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			string new_Name;
			cout << "\n\t\t# Give the new customer name for             : " << current->name << " : ";
			cin >> new_Name;
			current->name = new_Name;
			cout << "\n\t\t# Give the new custom contact no(0XXXXXXXXX) : ";
			cin >> current->ctNo;
		}
	}
	void editSupplier(int pos) {
		if (head == NULL) {
			cout << "\n\t# No supplier to edit." << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no supplier at this position." << endl;
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			string new_Name;
			cout << "\n\t\t# Give the new supplier name for             : " << current->name << " : ";
			cin >> new_Name;
			current->name = new_Name;
			cout << "\n\t\t# Give the new supply contact no(0XXXXXXXXX) : ";
			cin >> current->ctNo;
		}
	}
};

class TempItem {
public:
	string name;
	int barcode;
	float costPrice;
	float sellPrice;
	int quantity;
	TempItem* next;

	TempItem() { // Default  constructor
		name = "";
		quantity = 0;
	}
	TempItem(string name, int barcode, float sellPrice) { // Overloaded constructor
		this->name = name;
		this->barcode = barcode;
		this->sellPrice = sellPrice;

	}
};

class Items_List {
private:
	TempItem* head;
	TempItem* tail;
	int size;

public:
	Items_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertItem() {
		string name;
		int barcode;
		float sellPrice;  // *Changed the data type to int

		cout << "\n\t\t\tItem name              : ";
		cin >> name;

		// Validate barcode is to be an integer
		while (true) {
			cout << "\t\t\tItem barcode           : ";
			if (cin >> barcode) {
				break;
			}
			else {
				cout << "\t\t\tInvalid input. Please enter an integer for the barcode." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Validate sellPrice is to be an integer
		while (true) {
			cout << "\t\t\tItem sellPrice (Rs/-)  : ";
			if (cin >> sellPrice) {
				break;
			}
			else {
				cout << "\t\t\tInvalid input. Please enter an integer for the sellPrice." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		TempItem* temp = new TempItem(name, barcode, sellPrice);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void printItem_list() {
		TempItem* temp = head;
		if (head == NULL) {
			cout << "\n\t# No item to print." << endl;
		}
		else {
			cout << endl;
			cout << "\t\t\t\t\t\t\t+-------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "\t\t\t\t\t\t\t|     [ITEM NAME]     |    [BARCODE]   |  [COST PRICE  (Rs/-)]  |  [SELL PRICE  (Rs/-)]   |   [QUANTITY]      | " << endl;
			cout << "\t\t\t\t\t\t\t+-------------------------------------------------------------------------------------------------------------+" << endl;
			for (int i = 0; i < size; i++) {
				cout << "\t\t\t\t\t\t\t" << "|" << setw(20) << temp->name << " |   " << setw(12) << temp->barcode << " |             " << setw(10) << temp->costPrice << " |              " << setw(10) << temp->sellPrice << " |    " << setw(14) << temp->quantity << " |" << endl;
				cout << "\t\t\t\t\t\t\t+-------------------------------------------------------------------------------------------------------------+" << endl;

				temp = temp->next;
			}
			cout << endl;
		}
	}

	void delete_First() {
		if (head == NULL)
			cout << "Empty" << endl;
		else {
			TempItem* temp = head;

			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				delete temp;
				size--;
			}
		}
	}

	void delete_Last() {

		if (head == NULL)
			cout << "Empty" << endl;
		else {
			TempItem* temp = tail;

			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				TempItem* current = head;

				for (int i = 0; i < size - 2; i++) {
					current = current->next;
				}
				tail = current;
				tail->next = NULL;
				delete temp;
				size--;
			}
		}
	}

	void deleteItem(int pos) {    // deleteItem -----> we are only this for detele operation
		if (pos < 0 || pos >= size) {
			cout << "\n\t# Invalid position. There is no item at this position." << endl;
		}
		else if (pos == 0) {
			delete_First();
		}
		else if (pos == 0) {
			delete_First();
		}
		else {
			TempItem* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			TempItem* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}

	void editItem(int code) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				string new_Name;
				float newSellPrice;
				cout << "\n\t\t# Give the new item name for " << current->name << "   : ";
				cin >> new_Name;
				current->name = new_Name;
				cout << "\t\t# Give the item Sell price          : ";
				cin >> newSellPrice;
				current->sellPrice = newSellPrice;
				break;
			}
			else {
				current = current->next;
			}
		}
	}

	void searchInReceiveItem(int code, int quant, int totalPrice) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				// Update quantity
				current->quantity += quant;

				// Update cost price
				current->costPrice = ((current->costPrice * (current->quantity - quant)) + totalPrice) / current->quantity;

				break;
			}
			else {
				current = current->next;
			}
		}
	}

	void searchInSaleItem(int code, int quant) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				current->quantity -= quant; // update quantity
				break;
			}
			else {
				current = current->next;
			}
		}
	}

	float searchSellPrice(int code) {
		TempItem* current = head;

		while (current != NULL) {
			if (current->barcode == code) {
				return current->sellPrice;
			}
			else {
				current = current->next;
			}
		}
	}
};
