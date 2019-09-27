#include "Containers.h"
#include <iostream>
using namespace std;

MyArray::MyArray()
{
}

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
	size = ar.size;
	int* tmp = new int [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = ar.ar[i];
	}
	this->ar = tmp;
}

int MyArray::getSize() const
{
	return size;
}

int MyArray::getCapacity() const
{
	return size;
}

void MyArray::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
}

void MyArray::addCapacity(int n)
{
	int* tmp = new int[size + n];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = ar[i];
	}
	for (int i = size; i < size + n; i++)
	{
		tmp[i] = 0;
	}
	delete[] ar;
	ar = tmp;
	size = size + n;
	delete[] tmp;
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

Container::~Container()
{
}
