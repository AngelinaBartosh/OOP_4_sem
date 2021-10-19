#pragma once

#include <string>
#include <vector>

#include "Order.h"

class BookStore
{
public:
	BookStore(string name = "") : name(name)
	{
		cout << "Работает конструктор BookStore" << endl;
	}
	BookStore(const BookStore& store) :
		name(store.name), orders(store.orders) {}
	~BookStore()
	{
		cout << "Работает деструктор BookStore" << endl;
	}

	void setName(string name) { this->name = name; }
	string getName() const { return name; }
	void setOrders(vector<Order> orders) { this->orders = orders; }
	vector<Order> getOrders() const { return orders; }

	void menu();

	void addOrder();
	void showOrders();
	void removeOrder();

private:
	string name;
	vector<Order> orders;
};
