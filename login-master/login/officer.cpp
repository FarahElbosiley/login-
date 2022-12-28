#include<iostream>
#include<fstream>
#include<string>
#include "Header.h"

using namespace std;


void officer() {
	string username, pass, u, p;
	int t = 0;
	cout << "Enter your username:"; cin >> username;
	cout << "Enter your password:"; cin >> pass;
	ifstream read("D:\ASU ENG\programming\New folder\login-master\Officer.txt");
	while (read >> u >> p) {
		if (u == username && p == pass) {
			t = 1;
			break;
		}
	}
	read.close();
	if (t == 1) {
		cout << "------------------------------------------\nLogin succesful.\n------------------------------------------" << endl;
	}
	else {
		cout << "------------------------------------------\nLogin error, try again.\n------------------------------------------" << endl;
		officer();
	}
}

void main_screen_officer() {
	while (1)
	{
		int a;
		cout << "Choose an action:\n 1.Display Record\n 2.update\n 3.search\n 4.Exit\n _________________________________" << endl;
		cin >> a;
		switch (a) {
		case 1:
			display_record();
			break;
		case 2:
			update_record();
			break;
		case 3:
			search_record();
			break;
		case 4:
			cout << "\n Exiting...\n____________________________________" << endl;
			exit(0);
			break;
		}
	}
}






