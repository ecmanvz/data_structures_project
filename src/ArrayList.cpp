/**
* @file ArrayList.cpp
* @description Faktöriyel hesaplama
* @date 2.08.2022
* @author Ecem 
*/


#include "ArrayList.hpp"


void ArrayList::reserve(int newCapacity)
{
	int* tmp = new int[newCapacity];
	for (int i = 0; i < lenght; i++) tmp[i] = items[i];
	delete[] items;
	items = tmp;
	capacity = newCapacity;
}


ArrayList::ArrayList()
{
	lenght = 0;
	capacity = 1000;
	items = new int[capacity];
}

int ArrayList::size()const
{
	return lenght;
}

bool ArrayList::isEmpty()const
{
	return size() == 0;
}

void ArrayList::add(const int& item)
{
	insert(lenght, item);
}

void ArrayList::insert(int index, const int item)
{
	//if(index < 0 || index > lenght) throw;
	if (lenght == capacity) reserve(2 * capacity);
	for (int i = lenght - 1; i >= index; i--) items[i + 1] = items[i];
	items[index] = item;
	lenght++;
}

int ArrayList::indexOf(const int& item)
{
	for (int i = 0; i < lenght; i++) {
		if (items[i] == item) return i;
	}
	throw "Error";
}

const int& ArrayList::first()const
{
	if (isEmpty()) throw "Error";
	return items[0];
}

const int& ArrayList::last()const
{
	if (isEmpty()) throw "Error";
	return items[lenght - 1];
}

void ArrayList::clear()
{
	lenght = 0;
}

void ArrayList::remove(const int& item)
{
	int index = indexOf(item);
	removeAt(index);
}

void ArrayList::removeAt(int index)
{
	//if(index < 0 || index >= lenght) throw "Error";
	for (int i = index + 1; i < lenght; i++) items[i - 1] = items[i];
	lenght--;
}

bool ArrayList::find(const int& item)
{
	for (int i = 0; i < lenght; i++)
		if (items[i] == item) return true;
	return false;
}


const int& ArrayList::elementAt(int index)
{
	//if(index<0 || index>=lenght) throw "Error";
	return items[index];
}

ostream& operator<<(ostream& screen, ArrayList& right)
{
	for (int i = right.lenght - 1; i >= 0; i--) {
		screen << right.items[i];
	}
	return screen;
}

ArrayList* operator+(ArrayList& left, ArrayList& right)
{
	int overflow = 0;
	int i = 0;
	ArrayList* result = new ArrayList();

	while (i < left.size() && i < right.size()) {
		result->add((left.elementAt(i) + right.elementAt(i) + overflow) % 10);
		overflow = (left.elementAt(i) + right.elementAt(i)) > 9 ? 1 : 0;
		i++;
	}
	while (i < left.size()) {
		result->add((left.elementAt(i) + overflow) % 10);
		overflow = (left.elementAt(i) + overflow) > 9 ? 1 : 0;
		i++;
	}
	while (i < right.size()) {
		result->add((right.elementAt(i) + overflow) % 10);
		overflow = (right.elementAt(i) + overflow) > 9 ? 1 : 0;
		i++;
	}
	if (overflow == 1) result->add(1);

	return result;
}

ArrayList::~ArrayList()
{
	delete[] items;
}
