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


bool isUser = false;
bool isAdmin = false;
void Register();
void Login();
void LoadUserMap();
void LoadAdminMap();
void SaveUserMap();
void SaveAdminMap();
void main()
{   
	LoadUserMap();
	LoadAdminMap();
	AdminTable.at("1131")=AdminTable.at("5523");
	SaveAdminMap();
	SaveUserMap();
	

	//int choice;
	//char agree;
	//while (true)
	//{
	//	cout << "Enter your choice:\n1)Register\n2)Login\n3)Display Current User\n4)displayQueue Test\n5)Apply for Vaccine\n";
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 1:
	//	{
	//		Register();
	//		break;
	//	}
	//	case 2:
	//	{
	//		Login();
	//	
	//		break;
	//	}
	//	case 3:
	//	{

	//		currentUser.displayUser();
	//		cout << "Would you like to display your Vaccine Status?\n";
	//		cin >> agree;
	//		if (agree == 'y' ||agree== 'Y')
	//		{
	//			currentUser.vaccineStatus();
	//		}
	//		break;
	//	
	//	}
	//	case 4:
	//	{
	//		UserQueue[0].displayUser();
	//		break;
	//	}
	//	case 5:
	//	{
	//		if (currentUser.applyForVaccine==true)
	//		{
	//			cout << "You Already Applied for Vaccine MF!\n";
	//		}
	//		else
	//		{
	//			currentUser.AddToVaccineQueue(currentUser,UserQueue);
	//		}
	//		break;
	//	}
	//	default:
	//		break;
	//	}
	//}
	//while (isUser)
	//{
	//	
	//}
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
void LoadUserMap()
{
	user readingFromFile = user();//reads user from file to add copy in the user map

	// read from file into program
	ifstream UserTableFile; //input file
	UserTableFile.open("UserMap.txt");
	if (!UserTableFile.is_open())
	{
		cout << "\ncan't Load file! ";
	}
	else
	{
		string tempID, tempPass;
		while (UserTableFile >> tempID >> tempPass >> readingFromFile.UName
			>> readingFromFile.country >> readingFromFile.governorate
			>> readingFromFile.gender >> readingFromFile.applyForVaccine
			>> readingFromFile.isVaccined >> readingFromFile.age
			>> readingFromFile.vaccineDosesRecieved)
		{
			readingFromFile.setID(tempID);
			readingFromFile.setPass(tempPass);
			UserTable.insert({ readingFromFile.getID(),readingFromFile });
		}
		cout << "Loading Data Complete!\n";
	}
	UserTableFile.close(); // closing file
}
void SaveUserMap() 
{
	user writingToFile = user();//writes user to file from the unordered map

	/*write from program to file */
	ofstream UserTableFile;
	UserTableFile.open("UserMap.txt"); // open file
	// check if file is open
	if (!UserTableFile.is_open())
	{
		cout << "\ncan't Save file! ";
	}
	else
	{
		unordered_map<string, user>::iterator iter;
		for (auto iter = UserTable.begin(); iter != UserTable.end(); iter++)
		{
			writingToFile = iter->second;
			UserTableFile << writingToFile.getID() <<" " << writingToFile.getPass() << " " << writingToFile.UName << " "
			<< writingToFile.country << " " << writingToFile.governorate << " "
			<< writingToFile.gender << " " << writingToFile.applyForVaccine << " "
			<< writingToFile.isVaccined << " " << writingToFile.age << " "
		    << writingToFile.vaccineDosesRecieved << "\n";
		}
		cout << "\nSaving Succesful!";
	}
	UserTableFile.close();


}
void LoadAdminMap()
{
	Admin readingFromFile = Admin();//reads Admin from file to add copy in the AdminMap

	// read from file into program
	ifstream AdminTableFile; //input file
	AdminTableFile.open("AdminMap.txt");
	if (!AdminTableFile.is_open())
	{
		cout << "\ncan't Load file! ";
	}
	else
	{
		string tempID, tempPass;
		while (AdminTableFile >> tempID >> tempPass >> readingFromFile.UName
			>> readingFromFile.gender  >> readingFromFile.age)
		{
			readingFromFile.setID(tempID);
			readingFromFile.setPass(tempPass);
			AdminTable.insert({ readingFromFile.getID(),readingFromFile });
		}
		cout << "Loading Data Complete!\n";
	}
	AdminTableFile.close(); // closing file
}
void SaveAdminMap()
{
	Admin writingToFile = Admin();//writes Admin from the Admin map to file 

	/*write from program to file */
	ofstream AdminTableFile;
	AdminTableFile.open("AdminMap.txt"); // open file
	// check if file is open
	if (!AdminTableFile.is_open())
	{
		cout << "\ncan't Save file! ";
	}
	else
	{
		unordered_map<string, user>::iterator iter;
		for (auto iter = AdminTable.begin(); iter != AdminTable.end(); iter++)
		{
			writingToFile = iter->second;
			AdminTableFile << writingToFile.getID() << " " << writingToFile.getPass()
				<< " " << writingToFile.UName << " "<< writingToFile.gender << " " << writingToFile.age << " "<< "\n";
		}
		cout << "\nSaving Succesful!";
	}
	AdminTableFile.close();


}







