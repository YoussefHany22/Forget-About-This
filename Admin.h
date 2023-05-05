#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_map>
#include <string.h>
#include "user.h"
using namespace std;
 class Admin
{
	string nationalId;
	string password;
	void addAdmin(string id, string pass, string name, string gender, double age);

public:
	string UName;
	char gender;
	double age;
	string getID();
	string getPass();
	void DeleteAllUsers(vector<user>&UsersVector,deque<user>&UsersQueue);
	void viewUser(vector<user> &UsersInFile,string id);
	void displayAllUsers(vector<user>& UsersInFile);
	void displayQueue(deque<user>&UsersInQueue);
	void DeleteUser(deque<user>& UserQueue, string ID);
	void setPass(string Pass);
	void setID(string ID);
	Admin();
	Admin(string id, string pass, string name, char gender, double age);
	~Admin();
};

