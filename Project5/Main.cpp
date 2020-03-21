#include <iostream>
#include <string>
#include <fstream>
#include "Users.h"
using namespace std;

int menu(int *ptrchoisemenu)
{
	cout << "\tMENU" << endl;
	cout << "1. Sign in" << endl;
	cout << "2. Sign up" << endl;
	cout << "3. Exit" << endl;
	cout << endl;
	cout << "Enter action: ";
	cin >> *ptrchoisemenu;

	return *ptrchoisemenu;
}

int main()
{
	init();
	int choiseMenu = 0;
	int* ptrchoisemenu = &choiseMenu;
	do {
		choiseMenu = menu(&choiseMenu);

		switch (choiseMenu)
		{
		case 1:
			signIn();
			break;
		case 2:
			signUp();
			break;
		case 3:
			cout << "GOODBYE!" << endl;
		default:
			break;
		}
	} while (choiseMenu != 3);


	system("pause");
	return 0;
}
