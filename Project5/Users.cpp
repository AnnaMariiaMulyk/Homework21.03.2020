#include "Users.h"
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>

using namespace std;


list<user> users;
const string fileName = "users.txt";

void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOPen = fin.is_open();

	if (isOPen == false) {
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		user oldUser;
		while (!fin.eof()) {
			currentString++;
			getline(fin, data);

			if (currentString == 1) {
				oldUser.login = data;

			}
			else if (currentString == 2)
			{
				oldUser.password = data;
			}
			else if (currentString == 3)
			{
				oldUser.email = data;
				currentString = 0;
				users.push_back(oldUser);
				oldUser = user();
			}

		}

	}
	fin.close();

}

void signIn()
{
	user temp;
	cout << "\tSIGN IN" << endl;
	cout << "Login: ";
	cin >> temp.login;
	cout << "Password: ";
	cin >> temp.password;
	
	for (user item : users)
	{
		if (item.login == temp.login && item.password == temp.password)
		{
			cout << "Hello " << item.login << endl;
		}
		else
		{
			cout << "Error: can not find user with this login or password!" << endl;
			cout << "Try again." << endl;
		}
	}

}



void signUp()
{
	cout << "\tSIGN UP" << endl;
	user newUser;
	cout << "Enter login: ";
	cin >> newUser.login;
	cout << "Enter password: ";
	cin >> newUser.password;
	cout << "Enter email: ";
	cin >> newUser.email;
	
	for (user item : users)
	{
		if (item.login == newUser.login)
		{
			cout << "Error: user with this login is already exist!" << endl;
		}
		else
		{
			ofstream fout;
			fout.open(fileName, fstream::app);

			bool isOpen = fout.is_open();
			if (isOpen == false)
			{
				cout << "Error: can not open file!" << endl;
			}
			else
			{
				fout << newUser.login << endl;
				fout << newUser.password << endl;
				fout << newUser.email << endl;
			}
			fout.close();
		}
	}
		

}