#pragma once
#include <cstdlib>

#include "GA.h"

double random0To1(int Ifinite);
int randomAtInterval(int lowerBound, int  upperBound);
void makeBigSmall(int &bigOne, int &smallOne);
bool getElite(individual a, individual b);
void swapInteger(int &a, int &b);

double random0To1(int Infinite)//interval [ 0, 1 ]
{
	return (rand() % Infinite) / double(Infinite + 1);
}

int randomAtInterval(int lowerBound, int  upperBound)//interval [ lowerBound, upperBound ]
{
	return (rand() % (upperBound - lowerBound + 1)) + lowerBound;
}

void makeBigSmall(int &bigOne, int &smallOne)
{
	int t = 0;
	if (bigOne < smallOne)
	{
		t = bigOne;
		bigOne = smallOne;
		smallOne = t;
	}
}
bool getElite(individual a, individual b)
{
	return (a.fitness > b.fitness);
}

void swapInteger(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
/*定位num在p中的位置*/
int getIndex(int *p, int size, int num)
{
	for (int i = 1; i <= size; i++)
	{
		if (p[i] == num)
			return i;
	}
	return -1;
}