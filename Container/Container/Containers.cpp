#include "Containers.h"
#include <iostream>
using namespace std;

MyArray::MyArray(int n)
{
	size = n;
	ar = new int[size];
	for (int i = 0; i < size; i++) 
	{
		ar[i] = 0;
	}
}

MyArray::MyArray(const MyArray & ar)
{
	int* tmp = new int [];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = this[i];
	}
}

int MyArray::getSize() const
{
	int n = 0;
	for (int i = 0; i < getCapacity(); i++)
	{
		if (ar[i] == NULL) n++;

	}
}

int MyArray::getCapacity() const
{
	return size;
}

void MyArray::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << "\n";
	}
}

void MyArray::addCapacity(int n)
{
	int* ptr = new int[size+n];
	for (int i = 0; i < size + n; i++)
	{
		if (ar[i] !== NULL)
			ptr[i] = ar[i];
		else
			ptr[i] = 0;
	}
}

int & MyArray::operator[](int index)
{
	return ar[index];
}

MyArray & MyArray::operator=(const MyArray & ar1)
{
	delete[] ar;
	ar = new int[ar1.getCapacity()];
	for (int i = 0; i < ar1.getCapacity(); i++) {
		ar[i] = ar1.ar[i];
	}
	return *this;
}

MyArray::~MyArray()
{
	delete[] ar;
}
