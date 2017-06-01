#include "stdafx.h"
#include <iostream>

void initMoneyForAllAccounts(int countOfBuds, double* budsCash);
void transCashForAccount(double* refAcc, double sum);
int findNumberByID(int* budsID, int countOfBuds, int id);
void printInfoAboutAccount(double* budsCash, int id, int number);

// Создаем массив счетов и возвращаем на него ссылку
int *createBudsID(int countOfBuds) 
{
	int* newArray = new int[countOfBuds];
	return newArray;
}

// Создаем денежный массив счетов
double *createBudsCash(int countOfBuds)
{
	double* newArray = new double[countOfBuds];
	initMoneyForAllAccounts(countOfBuds, newArray);
	return newArray;
}

// Инициализируем нулевой баланс всем аккаунтам
void initMoneyForAllAccounts(int countOfBuds,double* budsCash) 
{
	for (int i = 0; i < countOfBuds; i++) {
		*(budsCash + i) = 0;
	}
}

// Отслеживаем операцию (снятие/внесение средств)
void detectOperation(int* budsID, double* budsCash, int countOfBuds
	, int id, double sum)
{
	int idNumber = findNumberByID(budsID, countOfBuds, id);
	if (idNumber == -1) 
	{
		std::cout << "Account with this ID has`t found!\n";
		return;
	}
	transCashForAccount((budsCash +idNumber),sum);
	printInfoAboutAccount(budsCash,id,idNumber);
}

// Выводим информацию о аккаунте
void printInfoAboutAccount(double* budsCash,int id,int number)
{
	std::cout << "Account with ID" << id << ". He is have "
		<< *(budsCash + number) << "$ money";
}

// Проводим операцию с денежным счетом аккаунта
void transCashForAccount(double* refAcc,double sum)
{
	if (*refAcc + sum < 0) std::cout << "Transaction impossible!\n";
	else *refAcc += sum;
}

// Найти номер аккаунта по его ID
int findNumberByID(int* budsID, int countOfBuds, int id)
{
	int idNumber = -1;
	for (int i = 0; i < countOfBuds; i++)
	{
		if (*(budsID + i) == id) idNumber = i;
	}
	return idNumber;
}

void balanceForEachAccounts(int* budsID, 
	double* budsCash, int countOfBuds)
{
	for (int i = 0; i < countOfBuds; i++) {
		std::cout << "Account with ID" << *(budsID + i) << " have "
			<< *(budsCash + i) << "$\n";
	}
}

void balanceForAllAccounts(double* budsCash, int countOfBuds)
{
	double totalSum = 0;
	for (int i = 0; i < countOfBuds; i++) {
		totalSum += *(budsCash + i);
	}
	std::cout << "Total sum is: " << totalSum << "$\n";
}


