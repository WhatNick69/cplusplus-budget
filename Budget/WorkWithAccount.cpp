#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include "OperationsWithBud.h"

using namespace std;

bool checkForUnique(int* buds, int count, int id);
double enterSum();
bool whatToDo();
void balanceForEachAccounts(int* budsID,double* budsCash, int countOfBuds);
void balanceForAllAccounts(double* budsCash, int countOfBuds);

// Ввод количества аккаунтов
int enteringCountOfAccount() {
	int value;
	cout << "Enter count of accounts: ";
	cin >> value;

	while (value <= 0)
	{
		cout << "Error! Please try again to enter a count of accounts!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter count of accounts: ";
		cin >> value;
	}
	cout << "Entering count of accounts has been successfully entered!\n\n";
	return value;
}

// Присваиваем ID аккаунту
void accountID(int* refOfAccount, int* buds, int count,int number)
{
	int id = 0;
	cout << "Enter ID for account #"<<number<<": ";
	cin >> id;

	while (id <= 0 || !checkForUnique(buds,count, id))
	{
		cout << "Error! Please try again to enter ID for account #" << number;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nEnter ID for account #" << number << ": ";
		cin >> id;
	}
	*refOfAccount = id;
}

// Проверить ID аккаунтов на уникальность
bool checkForUnique(int* buds, int count, int id)
{
	for (int i = 0; i < count; i++) 
	{
		int temp = *(buds + i);
		if (temp == id) return false;
	}
	return true;
}

// Присваиваем ID каждому аккаунту из массива аккаунтов
void idToEachAccount(int* buds, int count)
{
	int i = 0;
	for (int i = 0; i<count; i++)
	{
		accountID(buds + i,buds,count,i);
	}
	cout << "Entering ID for all accounts has been completed!";
}

// Вводим требуемый ID аккаунта
int enterWantedID() 
{
	int id = 0;
	cout << "\nEnter account`s ID: ";
	cin >> id;

	return id;
}

// Работа пользователя с аккаунтами
void userWork(int* budsID, double* budsCash, int countOfBuds)
{
	while (!whatToDo()) 
	{
		int id = enterWantedID();
		double sum = enterSum();
		detectOperation(budsID,budsCash,countOfBuds,id,sum);
	}
	balanceForEachAccounts(budsID,budsCash,countOfBuds);
	balanceForAllAccounts(budsCash, countOfBuds);
}

// Выйти или продолжить
bool whatToDo() 
{
	char c;
	cout << "\n\nExit? Y/N: ";
	cin.get(c) >> c;
	
	if (c == 'y') return true;
	else return false;
}

// Ввод суммы
double enterSum() {
	double value;
	cout << "Enter the sum: ";
	cin >> value;

	while (cin.fail())
	{
		cout << "Error! Please try again to enter a correct sum!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter the sum: ";
		cin >> value;
	}
	return value;
}
