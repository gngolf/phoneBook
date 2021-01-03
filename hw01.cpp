// Grant Norton
// CS301 HW01
// Due June 12, 2019

#include<iostream>
#include<string>
using namespace std;


class MyVector {

private:
	struct Contact {
		string name;
		string phone;
	};

	Contact* list;
	int max_size;
	int list_size;

public:
	MyVector();
	~MyVector();
	void push_back(string name, string phone);
	void remove(string name, string phone);
	string get(string name);
	void clear();
};

MyVector::MyVector()
{
	max_size = 10;
	list_size = -1;
	list = new Contact[10];
}
MyVector::~MyVector()
{
	delete[] list;
}

void MyVector::push_back(string name, string phone)     // add new contact to the end of the list, 
{														// double list size when out of memory and copy original list to new one
	string addName = name;
	string addPhone = phone;
	if (list_size == (max_size - 1))
	{
		max_size = max_size * 2;
		Contact* temp = new Contact[max_size];

		for (int i = 0; i < list_size; i++) {
			temp[i] = list[i];
		}

		delete[] list;
		list = temp;
	}
	list_size += 1;
	list[list_size].name = addName;
	list[list_size].phone = addPhone;

};

void MyVector::remove(string name, string phone)     //swaps value to be removed with the last element of array and then decrements the list_size
{
	for (int i = 0; i <= list_size; i++) {
		if (name == list[i].name || phone == list[i].phone) {
			list[i] = list[list_size];
			list_size -= 1;
		}
	}
};

string MyVector::get(string name)     
{
	if (list_size == -1)
		return("NOT FOUND");
	else {
		for (int i = 0; i <= list_size; i++) {
			if (list[i].name == name)
			{
				return(list[i].phone);
			}

		}
	}
	return("NOT FOUND");
};

void MyVector::clear()
{
	list_size = -1;
};



int main()
{
	MyVector phoneBook;
	char choice;
	string name, phone;
	do {
		

		cout << "(A)dd Contact" << endl;
		cout << "(C)lear Contacts" << endl;
		cout << "(F)ind Contact" << endl;
		cout << "(Q)uit" << endl;
		cout << "(R)emove Contact" << endl << endl << endl;

		cout << "[ACFQR]: ";
		cin >> choice;
		choice = tolower(choice);
		
		if (choice == 'a') {
			
			cout << "Enter Name: ";
			cin >> name;
			cout << "Enter Phone: ";
			cin >> phone;
			phoneBook.push_back(name, phone);
			cout << name << " has been added to your phone book...";
			cout << endl << endl;
		}
		else if (choice == 'c') {
			phoneBook.clear();
		}
		else if (choice == 'f') {
			cout << "Enter Name: ";
			cin >> name;
			cout << "Phone: " << phoneBook.get(name) << endl << endl;
		}
		else if (choice == 'r') {
			cout << "Enter the name or phone number of the contact to be removed: ";
			cin >> name;
			phoneBook.remove(name, name);
		}
	} while (choice != 'q');
	
	return 0;
}


