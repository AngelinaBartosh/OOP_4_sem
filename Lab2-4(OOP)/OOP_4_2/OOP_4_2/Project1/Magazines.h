#pragma once
#include "Items.h"

class Magazines : public Item
{
public:
	Magazines(double price = 0, string firm = "", string name = "", int size = 0, int width = 0) :
		Item(price, firm, name), size(size), width(width)
	{
		cout << "Работает конструктор Magazines" << endl;
	}
	Magazines(const Magazines& shoes) : Item(shoes),
		size(shoes.size), width(shoes.width) {}
	~Magazines()
	{
		cout << "Работает деструктор Magazines" << endl;
	}

	void setSize(int size) { this->size = size; }
	int getSize() const { return size; }
	void setWidth(int type) { this->width = width; }
	int getWidth() const { return width; }

	Type getType() const { return MagazinesType; }

private:
	int size;
	int width;
};
