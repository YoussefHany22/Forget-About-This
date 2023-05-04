#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_map>
#include <string.h>
using namespace std;
class user
{
	
	string nationalId;
	string password;
public:
	static int FNumber;
	static int MNumber;
	static int TotalNumber;
	string UName;
	char gender;
	int age;
	string country;
	string governorate;
	bool isVaccined;
	bool applyForVaccine;
	int vaccineDosesRecieved;
	string getID();
	string getPass();
	user();
	user(string UNameNEW, string nationalIdNEW, string passwordNEW, char genderNEW, int ageNEW, string countryNEW, string governorateNEW,int timesVaccinatedNew, bool isVaccined, bool applyForVaccine);
	void  vaccineStatus();
	void displayUser();
	void addUser(unordered_map<string, user>& Users ,deque<user>& UserQueue);
	user SearchUser(vector<user>&UsersInFile,string id);
	void AddToVaccineQueue(string id, unordered_map<string,user>& Users, deque<user>& UserQueue);
	void AddToVaccineQueue(user IntoQueue,deque<user>& UserQueue);
	~user();
};

