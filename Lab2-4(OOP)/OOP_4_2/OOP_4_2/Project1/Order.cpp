#include "Order.h"
#include <fstream> 

int Order::currentNumber = 0;
void copy();

void Order::addItem(shared_ptr<Item> item)
{
	items.push_back(item);
	totalPrice += item->getPrice();
}

void Order::printInfo()
{
	ifstream reading("Book_Store.txt");
	int num;
	string name;
	double price;
	string firm;
	while (reading)
	{
		reading >> num >> name >> price >> firm;
	}
	reading.close();
	cout << "Заказ номер " << num << endl;
	double gtprice = getTotalPrice();
	cout << setw(20) << "Тип" << setw(20) << "Название" << setw(20) << "Стоимость" << setw(20) << "Фирма" << endl;

	for (auto& item : items) {
		cout << setw(20) << (item->getType() == Item::BookType ? "Книги" : "Журналы")
			<< setw(20) << name << setw(20) << price << setw(20) << firm << endl;
		if (item.use_count() == 1)
			totalPrice = item->getPrice();
		else
			totalPrice = gtprice + item->getPrice();
	}
	cout << "Итоговая стоимость " << totalPrice << endl;
}

void Order::addBook()
{
	ofstream record("Book_Store.txt", ios::out);
	cout << "Введите название" << endl;
	string name;
	cin.ignore(INT_MAX, '\n');
	getline(cin, name);
	cout << "Введите цену" << endl;
	double price;
	price = Reader::getDouble();
	cout << "Введите фирму" << endl;
	string firm;
	getline(cin, firm);
	record << number << endl << name << endl << price << endl << firm << endl;
	cout << "Введите объем страниц" << endl;
	int size = Reader::getInt();
	if (size < 1 || size > 700)
		throw runtime_error("Неверный объем страниц");
	cout << "Введите жанр" << endl;
	string form;
	getline(cin, form);
	try {
		Item* item = new Book(price, firm, name, Book::Size(size), form);
		items.push_back(shared_ptr<Item>(item));
	}
	catch (...) {
		throw;//перенаправление
	}
	record.close();
}

void Order::addMagazine()
{
	ofstream record("Book_Store.txt", ios::out);
	cout << "Введите название" << endl;
	string name;
	cin.ignore(INT_MAX, '\n');
	getline(cin, name);
	cout << "Введите цену" << endl;
	double price;
	price = Reader::getDouble();
	cout << "Введите фирму" << endl;
	string firm;
	getline(cin, firm);
	record << number << endl << name << endl << price << endl << firm << endl;
	cout << "Введите объем страниц" << endl;
	int size = Reader::getInt();
	if (size < 0 || size > 300) throw runtime_error("Неверный объем страниц");
	int width;
	cout << "Введите количество товара" << endl;
	width = Reader::getInt();
	if (width < 1 || width > 12) throw runtime_error("Превышение количества");
	Item* item = new Magazines(price, firm, name, size, width);
	items.push_back(shared_ptr<Item>(item));
	record.close();
}

void copy()
{
	int num;
	string type;
	string name;
	double price;
	string firm;
	ifstream reading("Book_Store.txt");
	ofstream record("Buffer.txt");
	while (reading >> num >> name >> price >> firm)
	{
		record << num << endl << name << endl << price << endl << firm << endl;
	}
	record.close();
	reading.close();
}

void Order::editData()
{
	int num;
	string type;
	string name;
	double price;
	string firm;
	copy();
	cout << "Введите номер заказа для редактирования: " << endl;
	int n = Reader::getInt();
	ifstream reading("Buffer.txt");
	ofstream record("Book_Store.txt");
	while (reading >> num >> name >> price >> firm)
	{
		if (n != num)
		{
			cout << "Нет такого номера" << endl;
			record << num << endl << name << endl << price << endl << firm << endl;
		}
		else
		{
			cout << "Введите новые данные: " << endl;
			cout << "Введите название" << endl;
			string name1;
			cin >> name1;
			cout << "Введите цену" << endl;
			double price1;
			price1 = Reader::getDouble();
			cout << "Введите фирму" << endl;
			string firm1;
			cin >> firm1;
			cout << "Введите объем страниц" << endl;
			int size1;
			size1 = Reader::getInt();
			if (size1 < 1 || size1 > 700)
				throw runtime_error("Неверный объем страниц");
			cout << "Введите жанр" << endl;
			string form1;
			cin >> form1;
			record << num << endl << name1 << endl << price1 << endl << firm1 << endl;
			reading >> num >> name >> price >> firm;
		}
	}
	record.close();
	reading.close();
}
