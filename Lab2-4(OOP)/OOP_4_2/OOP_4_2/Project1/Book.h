#pragma once
#include "Items.h"
#include "MoneyException.h"

class Book : public Item
{
public:
	enum Size { A = 20, B = 25, C = 30, D = 35, E = 50, F = 100, G = 200 };
    Book(double price = 0, string firm = "", string name = "", Size size = A, string type = "") :
		Item(price, firm, name), size(size), form(form)
	{
		cout << "Работает конструктор Book" << endl;
		if (price < 0) throw MoneyException();//исключение в классе
	}
	Book(const Book& clothes) : Item(clothes),
		size(clothes.size), form(clothes.form) {}
	~Book()
	{
		cout << "Работает деструктор Book" << endl;
	}

	void setSize(Size size) { this->size = size; }
	Size getSize() const { return size; }
	void setForm(string form) { this->form = form; }
	string getForm() const { return form; }

	Type getType() const { return BookType; }

private:
	Size size;
	string form;
};
