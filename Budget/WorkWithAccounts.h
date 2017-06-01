#include "stdafx.h"
#include <iostream>

using namespace std;

int enteringCountOfAccount() {
	int count;
	try
	{
		cout << "Enter count of accounts: ";
		cin >> count;
	}
	catch (const std::exception&)
	{
		cout << "Error! Count of accounts must be an integer value!\n";
		enteringCountOfAccount();
	}

	return count;
}