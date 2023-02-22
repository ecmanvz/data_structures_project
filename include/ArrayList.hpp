/**
* @file ArrayList.hpp
* @description Faktöriyel hesaplama
* @course 1.Öğretim A 
* @assignment 1.Ödev
* @date 2.08.2022
* @author Ecem AMANVERMEZ
*/


#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>

using namespace std;

class ArrayList {
private:
	int* items;
	int lenght;
	int capacity;

	void reserve(int newCapacity);

public:

	ArrayList();

	int size()const;

	bool isEmpty()const;

	void add(const int& item);

	void insert(int index, const int item);

	int indexOf(const int& item);

	const int& first()const;

	const int& last()const;

	void clear();

	void remove(const int& item);

	void removeAt(int index);

	bool find(const int& item);


	const int& elementAt(int index);

	friend ostream& operator<<(ostream& screen, ArrayList& right);

	friend ArrayList* operator+(ArrayList& leftt, ArrayList& right);

	~ArrayList();
};



#endif