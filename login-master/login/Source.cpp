#include<iostream>
#include<fstream>
#include<string>
#include "Header.h"
using namespace std;

int main() {
	load_data();
	login();
}

void login() {
	cout << " 1.login as admin\n 2.login as officer\n select your choice, input an integer:\n________________________________________" << endl;
	int choice;
	do {
		cin >> choice;
		switch (choice) {
		case 1:
			admin();
			break;
		case 2:
			officer();
			break;
		default:
			cout << "invalid choice, please try again." << endl;
		}
	} while (choice > 2);
}