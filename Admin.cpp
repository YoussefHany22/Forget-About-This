#include "Admin.h"
Admin::Admin()
{ 
	nationalId = "";
	password = "";
	UName = "";
	gender = 'N';
	age = -1;

}
void Admin::displayAllUsers(vector<user>& AllUsers)
{
	for (int i = 0; i < AllUsers.size(); i++)
	{
		AllUsers[i].displayUser();
	}
}
void Admin::displayQueue(deque<user>& UsersInQueue)
{
	for (int i = 0; i < UsersInQueue.size(); i++)
	{
		UsersInQueue[i].displayUser();
	}

}
void Admin::DeleteAllUsers(vector<user>& UsersVector, deque<user>& UsersQueue)
{
	UsersVector.clear();
	UsersQueue.clear();
}

void Admin::DeleteUser(deque<user>&UserQueue,string ID)
{
	stack<user>UserStack;
	for (int i = 0; i < UserQueue.size(); i++)
	{
		if (UserQueue[i].getID() != ID)
		{
			UserStack.push(UserQueue[i]);
			UserQueue.pop_front();
		}
		else
		{
			UserQueue.pop_front();
			break;
		}
	}
	while (!UserStack.empty())
	{
		UserQueue.push_front(UserStack.top());
		UserStack.pop();
	}
}
void Admin::setID(string ID)
{
	this->nationalId = ID;
}
void Admin::setPass(string Pass)
{
	this->password = Pass;
}

void Admin::viewUser(vector<user>& UsersInFile, string id)
{
	for (int i = 0; i < UsersInFile.size(); i++)
	{
		if (UsersInFile[i].getID() == id)
		{
			UsersInFile[i].displayUser();
			break;
		}
	}
}
Admin::Admin(string id, string pass, string name, char gender, double age)
{
	this->age = age;
	this->gender = gender;
	nationalId = id;
	password = pass;
	UName = name;
}
void Admin::addAdmin(string id, string pass, string name, string gender, double age)
{

}
string Admin::getID()
{
	return nationalId;
}
string Admin::getPass()
{
	return password;
}
Admin::~Admin()
{
}
