
#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
#include "Header.h"
#include "var.h"
using namespace std;

//var 
string name, criminal_ID , type, status , age, date, crime_ID;

//structs 
struct criminal {
	string name{ 0 };
	string criminal_ID{ 0 };
	int age{ 0 };
}criminals[num_of_criminals];                                                                                  //
 criminal* pcriminal =new criminal;     //pointer for criminal
struct crime {
	string crime_ID{ 0 };
	string type{ 0 };
	string status{ 0 };
	string date{ 0 };
}crimes[num_of_crimes];                                                                                 //
struct crime* pcrime= new crime; //pointer for crime

//load data
void load_data() {
	ifstream criminal_load("D:/ASU ENG/programming/New folder/login-master/Criminal.txt");  //opens criminal file
	if (criminal_load.is_open()) {
		while (criminal_load.peek() != EOF) {
			getline(criminal_load, criminal_ID);
			getline(criminal_load, name);
			getline(criminal_load, age);
			pcriminal->criminal_ID = criminal_ID;
			pcriminal->name = name;
			pcriminal->age = stoi(age);

			/*pcriminal->criminal_ID = criminals[num_of_criminals].criminal_ID;
			pcriminal->name = criminals[num_of_criminals].name;
			pcriminal->age = criminals[num_of_criminals].age;
			*/
			/*criminals[num_criminals].criminal_ID = criminal_ID;
			criminals[num_criminals].name = name;
			criminals[num_criminals].age = stoi(age);   */                                            //
			num_criminals++;

		}
		criminal_load.close();
	}
	ifstream crime_load("D:/ASU ENG/programming/New folder/login-master/Crime.txt");   //opens crime file
	if (crime_load.is_open()) {
		while (crime_load.peek() != EOF) {
			getline(crime_load, crime_ID);
			getline(crime_load, type);
			getline(crime_load, status);
			getline(crime_load, date);
			pcrime->crime_ID = crime_ID;
			pcrime->type = type;
			pcrime->status = status;
			pcrime->date = date;

			/*criminals[num_criminals].criminal_ID = criminal_ID;
			criminals[num_criminals].name = name;
			criminals[num_criminals].age = stoi(age);   */                                            //
			num_crimes++;

		}
		crime_load.close();
	}
}
//save data
void criminal_save() {
	ofstream criminal_save("D:/ASU ENG/programming/New folder/login-master/Criminal.txt", ios::app); //saves data to criminal file
	criminal_save << pcriminal->criminal_ID << "\n";                                                                   // criminals[num_criminals].criminal_ID <<endl;
	criminal_save << pcriminal->name << "\n";                                                                                         //  criminals[num_criminals].name << endl;
	criminal_save << pcriminal->age << "\n";                                                                                         //criminals[num_criminals].age << endl;
	criminal_save.close();
}
void crime_save(){
	ofstream crime_save("D:/ASU ENG/programming/New folder/login-master/Crime.txt", ios::app); //saves data to crime file
	crime_save << pcrime->crime_ID << "\n";
	crime_save << pcrime->type << "\n";
	crime_save << pcrime->status << "\n";
	crime_save << pcrime->date << "\n";
	crime_save.close();
}

void main_screen() {
	while (1)
	{
		int a;
		cout << "Choose an action:\n 1.Add Record\n 2.Delete record \n 3.Display Record\n 4.update\n 5.search\n 6.Exit\n _________________________________" << endl;
		cin >> a;
		switch (a) {
		case 1:
			add_record();
			break;
		case 2:
			delete_record();
			break;
		case 3:
			display_record();
			break;
		case 4:
			update_record();
			break;
		case 5:
			search_record();
			break;
		case 6:
			//save_data();
			cout << "\n Exiting...\n____________________________________" << endl;
			exit(0);
			break;
		}
	}
}


void admin() {   //admin login
	string username, pass, u, p;
	cout << "Enter your username:"; cin >> username;
	cout << "Enter your password:"; cin >> pass;
	ifstream read("D:/ASU ENG/programming/New folder/login-master/Admin.txt");
	while (read >> u >> p) {

		if (u == username && p == pass) {
			cout << "------------------------------------------\nLogin succesful.\n------------------------------------------" << endl;
			main_screen();
		}
	} 
	read.close();
	cout << "------------------------------------------\nLogin error, try again.\n------------------------------------------" << endl;
	admin();
}



//after login

void add_record() {
	int x;
	cout << " Press (1) to add new criminal\n Press (2) to add new crime\n------------------------------------------ " << endl;
	cin >> x;
	if (x != 1 && x != 2)
	{
		cout << "invalid option,please try again ";
		cin >> x;
	}
	if (x == 1) // todo write func
	{
			cout << " Enter the ID: ";
			cin >> pcriminal->criminal_ID;                                                  //criminals[num_criminals].criminal_ID;
			cout << endl;
			cout << " Enter the criminal name (First name_Last name): ";
			cin >> pcriminal->name;                                    //criminals[num_criminals].name;                      
			cout << endl;
			cout << " Enter the criminal age: ";
			cin >> pcriminal->age;                                                          //criminals[num_criminals].age;  //num_criminals++;
			cout << endl;
			criminal_save();
			num_criminals++;
			cout << "------------------------------------------\ncriminal record succesfully saved\n------------------------------------------" << endl;
			
	}
	else if (x == 2)
	{
		cout << " Enter the crime ID: ";
		cin >> pcrime->crime_ID;
		cout << endl;
		cout << " Enter the type of crime (Burglary/Fruad/Arson/Violence/Murder...etc) : ";
		cin >> pcrime->type;
		cout << endl;
		cout << " Enter Case status(closed/ongoing/unassigned): ";
		cin >> pcrime->status;
		cout << endl;
		cout << " Enter the crime date (dd/mm/yy): ";
		cin >> pcrime->date;
		cout << endl;
		crime_save();
		num_crimes++;
		cout << "------------------------------------------\ncrime record succesfully saved\n------------------------------------------" << endl;
	}
}

void delete_record() {

	void deletcrime();
	{
		int index, delete_option;
		cout << "Do you want to delete \n 1. criminal \n 2. crime" << endl;
		cin >> delete_option;
		while (delete_option != 1 && delete_option != 2)
		{
			cout << "invaild option" << endl;
			delete_record(); 
			// here removed break
		}
		system("cls");
		if (delete_option == 1)
		{
			index = search_criminal();
			display_criminal(index);
			int d;
			cout << "Do you want to delet this criminal's information? \n 1. Yes \n 2. No" << endl;
			cin >> d;
			while (d != 1 && d != 2)
			{
				cout << "Invalid option" << endl;
				cin >> d;
				break;
			}
			if (d == 1)
			{
				for (int i = index; i < num_criminals - 1; i++)
				{
					criminals[i].criminal_ID = criminals[i + 1].criminal_ID;
					criminals[i].name = criminals[i + 1].name;
					criminals[i].age = criminals[i + 1].age;
				}
				num_criminals--;
				criminal_save();
				cout << "Data has been deleted successfully" << endl;
			}
			// here delete else and break
		}
		else
		{
			int e; // here add the next 2 lines
			index = search_crime();
			display_crime(index);
			cout << "Do you want to delet this crime's information? \n 1. Yes \n 2. No" << endl;
			cin >> e;
			while (e != 1 && e != 2)
			{
				cout << "Invalid option" << endl;
				cin >> e;
				break;
			}
			if (e == 1)
			{
				for (int i = index; i < num_crimes - 1; i++)
				{
					crimes[i].crime_ID = crimes[i + 1].crime_ID;
					crimes[i].type = crimes[i + 1].type;
					crimes[i].status = crimes[i + 1].status;
					crimes[i].date = crimes[i + 1].date;
				}
				num_crimes--;
				crime_save();
				cout << "Data has been deleted successfully" << endl;
			}
			// here delete else and break
		}
	}
}

//display record
void display_record()
{
	int x;
	cout << "  press [1] to display all Criminals \n Press [2] Crimes \n Press [3] for displaying Both " << endl;;
	cin >> x;
	if (x != 1 && x != 2 && x != 3) {
		cout << "invalid option,please try again." << endl;
		display_record();
	}
	system("cls");
	if (x == 1)
	{
		for (int i = 0; i < num_criminals; i++)
		{
			display_criminal(i);
		}
	}
	else if (x == 2)
	{
		for (int i = 0; i < num_crimes; i++)
		{
			display_crime(i);
		}
	}
	else if (x == 3)
	{
		cout << "criminals:";
		int j = 0;
		while (j < num_criminals)
		{
			display_criminal(j);
			j++;
		}
		cout << "crimes:";
		int i = 0;
		while (i < num_crimes)
		{
			display_crime(i);
			i++;
		}
	}
}
void display_criminal(int criminalindex)
{
	pcriminal->criminal_ID = criminals[criminalindex].criminal_ID;
	pcriminal->name = criminals[criminalindex].name;
	pcriminal->age = criminals[criminalindex].age;

	cout << "Criminal ID: " << criminals[criminalindex].criminal_ID << endl;
	cout << "Name:" << criminals[criminalindex].name << endl;
	cout << "Age:" << criminals[criminalindex].age << endl;
}
void display_crime(int crime_num)
{
	cout << "Crime_ID:" << crimes[crime_num].crime_ID << endl;
	cout << "Crime type:" << crimes[crime_num].type << endl;
	cout << "Crime status:" << crimes[crime_num].status << endl;
	cout << "Crime date:" << crimes[crime_num].date << endl;
}





void update_record() {

	int updatecriminal, updatecrime, updateoption;
	cout << "Do you want to update? \n 1. criminal \n 2. crime" << endl;
	cin >> updateoption;
	while (updateoption != 1 && updateoption != 2)
	{
		cout << "Invaild option";
		update_record();
		break;
	}
	system("cls");
	if (updateoption == 1)
	{
		updatecriminal = search_criminal();
		string criminalID, newname;
		int criminalage, criminaloption;
		display_criminal(updatecriminal);
		cout << "Please enter number that you wanted to modify \n 1. criminal ID \n 2.criminal name \n 3. criminal age" << endl;
		cin >> criminaloption;
		switch (criminaloption)
		{
		case 1:
		{
			cout << "please enter the new criminal ID" << endl;
			cin >> criminalID;
			criminals[updatecriminal].criminal_ID = criminalID;
			cout << "Data has been modified successfully" << endl;
			break;
		}
		case 2:
		{
			cout << "please enter the new criminal name" << endl;
			cin >> newname;
			criminals[updatecriminal].name = newname;
			cout << "Data has been modified successfully" << endl;
			break;
		}
		case 3:
		{
			cout << "please enter the new criminal age" << endl;
			cin >> criminalage;
			criminals[updatecriminal].age = criminalage;
			cout << "Data has been modified successfully" << endl;
			break;
		}
		default:
		{
			cout << " Invaild option" << endl;
			display_criminal(updatecriminal);
		}
		}
		criminal_save();
	}
	else
	{
		updatecrime = search_crime();
		string crimetype, crimestatus, CrimeID, crimeday;
		int crimeoption;
		display_crime(updatecrime);
		cout << "Please enter the number that you want to modify \n 1. crime type \n 2. crime status \n 3. crime ID \n 4. the crime day" << endl;
		cin >> crimeoption;
		switch (crimeoption)
		{
		case 1:
		{
			cout << "Please enter the new crime type" << endl;
			cin >> crimetype;
			crimes[updatecrime].type = crimetype;
			cout << "Data has been modified successfully" << endl;
			break;
		}
		case 2:
		{
			cout << "Please enter the new crime status" << endl;
			cin >> crimestatus;
			crimes[updatecrime].status = crimestatus;
			cout << "Data has been modified successfully" << endl;
			break;
		}
		case 3:
		{
			cout << "Please enter the new crime ID" << endl;
			cin >> CrimeID;
			crimes[updatecrime].crime_ID = CrimeID;
			cout << "Data has been modified successfully" << endl;
			break;
		}
		case 4:
		{
			cout << "Please enter the new crime day" << endl;
			cin >> crimeday;
			crimes[updatecrime].date = crimeday;
			cout << "Data has been modified successfully" << endl;
			break;
		}
		default:
		{
			cout << " Invaild option" << endl;
			display_crime(updatecrime);
		}
		}
		crime_save();
	}
}


// search record
void search_record() {

	int displayindex, searchoption;
	do
	{
		cout << "Are you looking for \n 1. criminal \n 2. crime " << endl;
		cin >> searchoption;
		while (searchoption != 1 && searchoption != 2)
		{
			cout << "Invaild option" << endl;
			search_record(); // here 
			break;
		}
		system("cls");
		if (searchoption == 1)
		{
			displayindex = search_criminal();
			if (displayindex == -1)
				break;
			else
				display_criminal(displayindex);
		}
		else
		{
			displayindex = search_crime();
			if (displayindex == -1)
				break;
			else
				display_crime(displayindex);
		}

	} while (1);
}
	int search_criminal(){
		string searchcriminal;
		int sendback = -1;
		cout << "Please enter the criminal ID:";
		cin >> searchcriminal;
		for (int i = 0; i < num_criminals; i++)
		{
			if (searchcriminal == criminals[i].criminal_ID)
			{
				verify = true;
				sendback = i;
			}

		}
		if(sendback == -1)
		{
			cout << "Invaild criminal ID" << endl;
			search_criminal(); // here add this line
		}	
		return sendback;
	}
	int search_crime()
	{
		string searchcrime;
		int sendback = -1;
		cout << "Please enter the crime ID:";
		cin >> searchcrime; // here add cin
		for (int i = 0; i < num_crimes; i++)
		{
			if (searchcrime == crimes[i].crime_ID)
				sendback = i;
		}
		if (sendback == -1)
		{
			cout << "Invalid crime ID" << endl;
			search_crime(); // here add this line
		}
		return sendback;
	}




//ifstream ifs;
//ifs.open("C:/Users/Salma/OneDrive/Desktop/login/Admin.txt", std::ifstream::in);
//char c = ifs.get();
//while (ifs.good()) {
	//std::cout << c;
	//c = ifs.get();
//}
//ifs.close();
