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
	void addAdmin(string id, string pass, string name, string gender, int age);

public:
	string UName;
	char gender;
	int age;
	string getID();
	string getPass();
	void DeleteAllUsers(vector<user>&UsersVector,deque<user>&UsersQueue);
	void viewUser(vector<user> &UsersInFile,string id);
	void displayAllUsers(vector<user>& UsersInFile);
	void displayQueue(deque<user>&UsersInQueue);
	void DeleteUser(deque<user>& UserQueue, string ID);
	Admin();
	Admin(string id,string pass,string name,char gender,int age);
	~Admin();
};

