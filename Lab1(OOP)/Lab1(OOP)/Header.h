#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<conio.h>
#include<string>

using namespace std;

template <class T>
class Status {
public:
	T* ptr;
	int counter;
};

template <class T>
class SmartPointer {
	Status<T>* smartPtr;
public:
	SmartPointer(T* ptr = 0);
	SmartPointer(const SmartPointer&);
	~SmartPointer();
	SmartPointer& operator=(const SmartPointer&);
	T* operator->() const;
	void showCounter() { cout << smartPtr->counter; }
};

template <class T>
SmartPointer<T>::SmartPointer(T* ptr) {
	if (!ptr) smartPtr = NULL;
	else {
		smartPtr = new Status<T>;
		smartPtr->ptr = ptr;
		smartPtr->counter = 1;
	}
}

template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj)
	:smartPtr(obj.smartPtr) {
	if (smartPtr) smartPtr->counter++;
}

template <class T>
SmartPointer<T>::~SmartPointer() {
	if (smartPtr) {
		smartPtr->counter--;
		if (smartPtr->counter <= 0) {

			delete smartPtr;
		}
	}
}

template <class T>
T* SmartPointer<T>::operator->() const {
	if (smartPtr) return smartPtr->ptr;
	else return NULL;
}
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& obj) {
	if (smartPtr) {
		smartPtr->counter--;
		if (smartPtr->counter <= 0) {
			delete smartPtr->ptr;
			delete smartPtr;
		}
	}
	smartPtr = obj.smartPtr;
	if (smartPtr) smartPtr->counter++;
	return *this;
}

bool checkWord(string name) {
	for (int i = NULL; i < name.length(); i++) {
		if ((name[i] >= 'А' && name[i] <= 'Я') || (name[i] >= 'а' && name[i] <= 'я') || name[i] == '.' || name[i] == ' ');
		else return false;
	}
	return true;
}
bool checkAge(char* str) {
	if (atoi(str) <= 100 && atoi(str) > 0) return true;
	else return false;
}

bool checkNumber(char* str) {
	if (atoi(str) > 0) return true;
	else return false;
}
class Order {
protected:
	string name;
	static int count;
public:
	static int getCount() { return count; }
	static int setCountMore() { return ++count; }
	static int setCountLittle() { return --count; }
	Order() {
		this->name = "";
	}
	string getName() { return this->name; }
};

class Document : public Order {
protected:
	int numberSoldOver;
	long int price;
	long int overCosts;
public:
	int getNumberSoldOver() { return this->numberSoldOver; }
	int getPrice() { return this->price; }
	int getOverCosts() { return this->overCosts; }
	void add();
	static void readData(Document*);
	void show();
	Document() { numberSoldOver = 0; price = 0; overCosts = 0; }
	static int curentIndex(Document* obj) {
		for (int i = 0; i < 10; i++) {
			if (obj[i].name == "") return i;
		}
	}
	static int currentName(Document* ptr, string name) {
		for (int i = 0; i < 10; i++) {
			if (ptr[i].name == name) return i;
		}
		return -1;
	}
	bool beginTransaction(Document& obj);

};

void Document::show() {
	cout << "Название: " << this->name << endl;
	cout << "Количество: " << this->numberSoldOver << endl;
	cout << "Стоимость: " << this->price << endl;
	cout << "Общая стоимость: " << this->overCosts << endl << endl;
}
void Document::readData(Document* ptr) {
	ifstream fin;
	fin.open("Docs.txt");
	if (fin.is_open()) {
		fin >> Document::count;
		for (int i = 0; i < count; i++) {
			fin >> ptr[i].name;
			fin >> ptr[i].numberSoldOver;
			fin >> ptr[i].overCosts;
			fin >> ptr[i].price;

		}
		cout << "Данные успешно считаны из файла." << endl;
	}
	else {
		cout << "Файл не открыт." << endl;
	}
}

bool Document::beginTransaction(Document& obj) {
	SmartPointer<Document> ptrCurrent(new Document);
	SmartPointer<Document> ptrPreviouse(new Document);
	ptrPreviouse = &obj;//obj - объект подлежащий редактированию

	ptrCurrent->add();//Функция добавления данных
	cout << "Вы подтверждаете изменения? (1/0): ";
	bool ch = false;
	cin >> ch;
	if (ch == false) return ch;
	else {
		obj.name = ptrCurrent->name;
		obj.numberSoldOver = ptrCurrent->numberSoldOver;
		obj.overCosts = ptrCurrent->overCosts;
		obj.price = ptrCurrent->price;
		return true;
	}
}
void Document::add()
{
	char number[100], price[100];
	string name;
	do {
		cout << "Введите название продукции: ";
		fseek(stdin, 0, SEEK_END);
		getline(cin, name);
	} while (!checkWord(name));
	do {
		cout << "Введите количество проданной продукции: ";
		fseek(stdin, 0, SEEK_END);
		cin.getline(number, 100);
	} while (!checkNumber(number));
	do {
		cout << "Введите цену проданной продукции: ";
		fseek(stdin, 0, SEEK_END);
		cin.getline(price, 100);
	} while (!checkNumber(number));
	this->name = name;
	this->price = atoi(price);
	this->numberSoldOver = atoi(number);
	this->overCosts = ((this->price) * (this->numberSoldOver));
}

class File : public Document {
public:
	static void saveData(Document* ptr) {
		ofstream fout;
		fout.open("Docs.txt");
		if (fout.is_open()) {
			fout << Document::count;
			for (int i = 0; i < count; i++) {
				fout << ptr[i].getName() << endl;
				fout << ptr[i].getNumberSoldOver() << " ";
				fout << ptr[i].getOverCosts() << " ";
				fout << ptr[i].getPrice();

			}
			cout << "Данные успешно сохранены." << endl;
		}
		else {
			cout << "Файл не открыт." << endl;
		}
	}



};