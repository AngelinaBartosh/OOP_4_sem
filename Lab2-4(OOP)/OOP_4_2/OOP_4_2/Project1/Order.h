#pragma once

#include <vector>
#include <memory>

#include "Magazines.h"
#include "Book.h"

class Order
{
public:
	Order() : number(++currentNumber), totalPrice(0)
	{
		cout << "Работает конструктор Order" << endl;
	}
	Order(const Order& order) :
		items(order.items), totalPrice(order.totalPrice), number(order.number) {}
	~Order()
	{
		cout << "Работает деструктор Order" << endl;
	}

	void setItems(vector<shared_ptr<Item>> items) { this->items = items; }
	vector<shared_ptr<Item>> getItems() const { return items; }
	void setTotalPrice(double totalPrice) { this->totalPrice = totalPrice; }
	double getTotalPrice() const { return totalPrice; }
	void setNumber(int number) { this->number = number; }
	int getNumber() const { return number; }

	void addItem(shared_ptr<Item> item);
	void printInfo();

	void addBook();
	void addMagazine();
	void editData();
	void clearItems() { if (!items.empty()) items.clear(); }

	static int currentNumber;

private:
	vector<shared_ptr<Item>> items;
	double totalPrice;
	int number;
};
