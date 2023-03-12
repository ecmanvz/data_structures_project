/**
* @file Test.cpp
* @description Faktöriyel hesaplama
* @date 2.08.2022
* @author Ecem 
*/


#include "ArrayList.hpp"
#include <fstream>

void AddValuesToList(int value, ArrayList* list) {
	while (true) {
		list->add(value % 10);
		value /= 10;
		if (value == 0) break;
	}
}

int main()
{
	ArrayList* list = new ArrayList();
	int sayi;
	cin >> sayi;

	AddValuesToList(1, list);

	for (int faktorCarpan = 1; faktorCarpan <= sayi; faktorCarpan++) {

		ArrayList* tmp = new ArrayList();
		ArrayList* newList = new ArrayList();


		int carpan = faktorCarpan;

		while (true) {
			int temp = carpan % 10;
			int overflow = 0;

			for (int i = 0; i < list->size(); i++) {
				tmp->add(((list->elementAt(i) * temp) + overflow) % 10);
				overflow = ((list->elementAt(i) * temp) + overflow) / 10;
			}

			if (overflow > 0)
				tmp->add(overflow);

			newList = *newList + *tmp;

			tmp->clear();
			carpan /= 10;

			if (carpan == 0) break;
		}

		delete tmp;
		delete list;
		list = newList;
	}
	ofstream file("Sonuc.txt");
	if (file.is_open())
	{
		file << *list;
		file.close();
	}

	delete list;
	return 0;
}
