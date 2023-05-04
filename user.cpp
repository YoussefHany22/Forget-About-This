#include "user.h"
user::user(string UNameNEW, string nationalIdNEW, string passwordNEW, char genderNEW, int ageNEW, string countryNEW, string governorateNEW,int timesVaccinatedNew, bool isVaccined, bool applyForVaccine)
{
	UName = UNameNEW;
	nationalId = nationalIdNEW;
	password = passwordNEW;
	gender = genderNEW;
	age = ageNEW;
	country = countryNEW;
	governorate = governorateNEW;
	vaccineDosesRecieved = timesVaccinatedNew;
	this->isVaccined = isVaccined;
	this->applyForVaccine = applyForVaccine;
}

void user::addUser(unordered_map<string, user>& Users, deque<user>& UserQueue)
{
	char wasVaccinated, gender, applyForvac;
	int dosesRecieved, age;
	bool correctData = true, applyForVaccine=false, isFULLYVaccined;
	unordered_map <string, user>::iterator it;
	string nationalId, password, UName, country, governorate;
	cout << "Enter ID\t";
	cin >> nationalId;
	it = Users.find(nationalId);
	cout << "Enter Password\t";
	cin >> password;
	cout << "Enter Your Name\t";
	cin >> UName;
	cout << "Age\t";
	cin >> age;
	cout << "Gender\t";
	cin >> gender;
	cout << "Country\t";
	cin >> country;
	cout << "Governorate\t";
	cin >> governorate;//use enum function
	if (country != "Egypt")
	{
		cout << "Omak Ar3a\n";
		correctData = false;
	}
	if (gender == 'm' || gender == 'f' || gender == 'F' || gender == 'M')
	{


	}
	else
	{
		cout << "Gender incorrect,you netflix worshipper mother fucker\n";
		correctData = false;
	}
	if (it != Users.end())
	{

		cout << "dh 3ndha\n";
		correctData = false;

	}
	if (correctData) {
		cout << "Have you been Vaccinated before?(y/n)\n";
		cin >> wasVaccinated;
		if (wasVaccinated == 'y' || wasVaccinated == 'Y')
		{
			cout << "How many doses of the vaccine did you recieve?\n";
			cin >> dosesRecieved;
			if (dosesRecieved == 2)
			{
				cout << "\nYou Got All Doses..";
				isFULLYVaccined = true;
				applyForVaccine = false;
			}
			else
			{
				isFULLYVaccined = false;
				cout << "Would you like to apply for vaccination?\n";
				cin >> applyForvac;
				if (applyForvac == 'y' || applyForvac == 'Y')
				{
					applyForVaccine = true;
				}
				else {
					applyForVaccine = false;
					/*correctData = false;
					cout << "You must apply for Vaccine in order to register!";*/
				}

			}
		}
		else
		{

			dosesRecieved = 0;
			isFULLYVaccined = false;
			cout << "Would you like to apply for vaccination?\n";
			cin >> applyForvac;
			if (applyForvac == 'y' || applyForvac == 'Y')
			{
				applyForVaccine = true;
			}
			else {
				applyForVaccine = false;
				/*correctData = false;
				cout << "You must apply for Vaccine in order to register!";*/
			}
		}
	}
	if (correctData)
	{
		Users.insert({ nationalId, user(UName, nationalId, password, gender, age, country, governorate,dosesRecieved,isFULLYVaccined,applyForVaccine) });
	}
	if (applyForVaccine&&correctData)
	{
		AddToVaccineQueue(nationalId, Users, UserQueue);
	}
}

void user::vaccineStatus()
{
	string applyForVac, fullyVac;
	if (isVaccined)
	{
		fullyVac = "Fully Vaccinated.";
	}
	else
	{
		fullyVac = "Not Fully Vaccinated";
	}
	if (applyForVaccine)
	{
		applyForVac = "Applied";
	}else
	{
		applyForVac = "Not Applied";
	}
	cout << "Number of Doses Left: " << 2 - vaccineDosesRecieved << "\nApplication for vaccine: "<<applyForVac<<"\nVaccination Status:"<<fullyVac<<endl;
}
void user::displayUser()
{
	cout << "ID: " << getID() << "\nName: " << UName << "\nGender: " << gender << "\nAge: "<< age<<endl;
}
void user::AddToVaccineQueue(user IntoQueue,deque<user>&UserQueue)
{
	UserQueue.push_back(IntoQueue);
}
void user::AddToVaccineQueue(string id,unordered_map<string,user>&UserTable,deque<user>&UserQueue)
{
	
	
	
	
	UserQueue.push_back(UserTable.at(id));
}
user::user()
{
	UName = "-1";
	nationalId ="-1";
	password = "-1";
	gender = 'N';
	age = -1;
	country = "-1";
	governorate ="-1";
	vaccineDosesRecieved = -1;
	this->isVaccined = false;
	this->applyForVaccine = false;
}
string user::getID()
{
	return nationalId;
}
string user::getPass()
{
	return password;
}
user::~user()
{

}
user user::SearchUser(vector<user>& UsersInFile, string id)
{
	for (int i = 0; i < UsersInFile.size(); i++)
	{
		if (id == UsersInFile[i].getID())
		{
			return UsersInFile[i];
		}
	}
}