/*
Завдання  3.
Утворити список(list) з випадкових цілих чисел(generate).
Помножити кожен елемент списку на введене з клавіатури деяке число(transform, лямбда із  захопленням).
Утворити  2 нових списки: з парних та непарних елементів вихідного(copy_if, ітератор вставки).
Видалити  елементи першого списку, які є від’ємними числами.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime>


using namespace std;



void print(const list<int> l, string text = "")
{
	cout << text;
	for (int elem : l)
		cout << elem << "\t";
	cout << endl << endl;
}

// Утворити список(list) з випадкових цілих чисел(generate).
void create(list<int> & l)
{
	generate(l.begin(), l.end(), []() { return rand() % 99 - 25; });
	print(l, "create:\t\t");
}

// Помножити кожен елемент списку на введене з клавіатури деяке число(transform, лямбда із  захопленням).
void multiple(list<int> & l, int mul)
{
	transform(l.begin(), l.end(), l.begin(), [mul](int num) {return num * mul; });
	print(l, "multiple x " + to_string(mul) + ":\t");
}

//  Утворити  2 нових списки: з парних та непарних елементів вихідного(copy_if, ітератор вставки).
void twolist(list<int> & l)
{
	int count = 0;
	for (auto elem : l)
		if (elem % 2 == 0)
			++count;
	list<int> pair (count);
	list<int> odd (l.size() - count);
	copy_if(l.begin(), l.end(), pair.begin(), [](int elem) {return elem % 2 == 0; });
	print(pair, "pair:\t\t");
	copy_if(l.begin(), l.end(), odd.begin(), [](int elem) {return (elem % 2 == 1 || elem % 2 == -1); });
	print(odd, "odd:\t\t");
}

// Видалити  елементи першого списку, які є від’ємними числами.
void delMinus(list<int> & l)
{
	for (auto it = l.begin(); it != l.end();) 
	{
		if (*it < 0) 
			it = l.erase(it);
		else 
			++it;
	}
	print(l, "without minus:\t");
}




int main()
{
	srand(unsigned(time(0)));

	list<int> l(10);
	create(l);
	multiple(l, 3);
	twolist(l);
	delMinus(l);


	cout << endl;
	system("pause");
	return 0;
}
