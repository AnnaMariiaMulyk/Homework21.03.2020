#pragma once
#include<string>
using namespace std;

struct user
{
	string login;
	string password;
	string email;
};
void init();

void signIn();
void signUp();