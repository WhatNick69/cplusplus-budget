// Budget.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "OperationsWithBud.h"

using namespace std;

int main()
{
	int* buds = initBuds(10);
	cout << "0x" << *(buds+1) << "\n";
	system("pause");
    return 0;
}

