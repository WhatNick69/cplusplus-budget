// Budget.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "OperationsWithBud.h"
#include "WorkWithAccount.h"

using namespace std;

// Следует применять ООП при создании аккаунтов
// но я пока хз, как создавать объекты класса в C++
int main()
{
	int countOfAccounts = enteringCountOfAccount(); // задаем число аккаунтов
	int* budsID = createBudsID(countOfAccounts); // создаем массив аккаунтов для ID
	double* budsCash = createBudsCash(countOfAccounts); // создаем массив аккаунтов с денежными суммами
	idToEachAccount(budsID,countOfAccounts); // присваиваем ID каждому из аккаунтов

	userWork(budsID, budsCash,countOfAccounts); // работа с аккаунтами
	system("pause");
    return 0;
}


