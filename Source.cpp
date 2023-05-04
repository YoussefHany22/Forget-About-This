#pragma warning(disable : 4996)
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_map>
#include <string.h>
#include "user.h"
#include "Admin.h"
#include <fstream>
using namespace std;
deque<user>UserQueue;
unordered_map <string, user>::iterator it;
unordered_map<string,Admin>AdminTable;
unordered_map<string,user>UserTable;
user selectedUser = user();
Admin currentAdmin = Admin();
user currentUser = user();
user readingFromFile = user();//testing name, will be changed!

bool isUser = false;
bool isAdmin = false;
void Register();
void Login();
void main()
{
	// read from file into program
	ifstream UserTableFile; //input file
	UserTableFile.open("UserMap.txt");
	if (!UserTableFile.is_open())
	{
		cout << "can't open file ";
	}

	while (UserTableFile >> readingFromFile.UName>> readingFromFile.)
	{


	}
	UserTableFile.close(); // closing file
	//write to file from program
	ofstream output;
	output.open("UserMap.txt"); // open file
	// check if file is open
	if (!output.is_open()) { cout << "can't open file "; }

	

		output.close();













	int choice;
	char agree;
	while (true)
	{
		cout << "Enter your choice:\n1)Register\n2)Login\n3)Display Current User\n4)displayQueue Test\n5)Apply for Vaccine\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Register();
			break;
		}
		case 2:
		{
			Login();
		
			break;
		}
		case 3:
		{

			currentUser.displayUser();
			cout << "Would you like to display your Vaccine Status?\n";
			cin >> agree;
			if (agree == 'y' || 'Y')
			{
				currentUser.vaccineStatus();
			}
			break;
		
		}
		case 4:
		{
			UserQueue[0].displayUser();
			break;
		}
		case 5:
		{
			if (currentUser.applyForVaccine==true)
			{
				cout << "You Already Applied for Vaccine MF!\n";
			}
			else
			{
				currentUser.AddToVaccineQueue(currentUser,UserQueue);
			}
			break;
		}
		default:
			break;
		}
	}
	while (isUser)
	{
		
	}
}

void Register()
{
	selectedUser.addUser(UserTable,UserQueue);
}
void Login()
{
	
	string id, password;
	cout << "PLEASE enter your ID followed by passowrd!\n";
	cin >> id >> password;
	it = UserTable.find(id);
	if (it != UserTable.end())
	{
		if (UserTable.at(id).getPass() == password)
		{
			currentUser = UserTable.at(id);
			cout << "Login Successful!";
			isUser = true;
		}
		else {
			cout << "Incorrect Password ";
		}
	}
	else
	{
		cout << "Incorrect National ID";
	}
}








