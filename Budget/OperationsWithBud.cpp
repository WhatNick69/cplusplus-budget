#include "stdafx.h"

// Создаем массив счетов и возвращаем на него ссылку
// 
int *createArray(int countOfBuds) 
{
	int* newArray = new int[countOfBuds];
	return newArray;
}