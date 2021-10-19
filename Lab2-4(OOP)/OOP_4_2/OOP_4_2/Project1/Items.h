#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Reader.h"


class Item
{
public:
	enum Type { BookType, MagazinesType };

	Item(double price = 0, string firm = "", string name = "") :
		price(price), firm(firm), name(name)
	{
		cout << "Работает конструктор Item" << endl;
	}
	Item(const Item& item) :
		price(item.price), firm(item.firm), name(item.name) {}
	~Item()
	{
		cout << "Работает деструктор Item" << endl;
	}

	void setPrice(double price) { this->price = price; }
	double getPrice() const { return price; }
	void setFirm(string firm) { this->firm = firm; }
	string getFirm() const { return firm; }
	void setName(string name) { this->name = name; }
	string getName() const { return name; }


	virtual Type getType() const = 0;

protected:
	double price;
	string firm;
	string name;

};
