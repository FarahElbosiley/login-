#pragma once
//login
void admin();
void officer();
void login();
void main_screen();

//access files
void load_data();
void criminal_save();
void crime_save();

//add record
void add_record();

//delete record
void delete_record();

//display record
void display_record();
void display_crime(int crime_num);
void display_criminal(int criminalindex);

//update record
void update_record(); //Farah

//search record
void search_record();
int search_criminal();
int search_crime();