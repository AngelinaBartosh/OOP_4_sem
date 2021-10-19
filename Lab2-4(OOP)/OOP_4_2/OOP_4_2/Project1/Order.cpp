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
	cout << "����� ����� " << num << endl;
	double gtprice = getTotalPrice();
	cout << setw(20) << "���" << setw(20) << "��������" << setw(20) << "���������" << setw(20) << "�����" << endl;

	for (auto& item : items) {
		cout << setw(20) << (item->getType() == Item::BookType ? "�����" : "�������")
			<< setw(20) << name << setw(20) << price << setw(20) << firm << endl;
		if (item.use_count() == 1)
			totalPrice = item->getPrice();
		else
			totalPrice = gtprice + item->getPrice();
	}
	cout << "�������� ��������� " << totalPrice << endl;
}

void Order::addBook()
{
	ofstream record("Book_Store.txt", ios::out);
	cout << "������� ��������" << endl;
	string name;
	cin.ignore(INT_MAX, '\n');
	getline(cin, name);
	cout << "������� ����" << endl;
	double price;
	price = Reader::getDouble();
	cout << "������� �����" << endl;
	string firm;
	getline(cin, firm);
	record << number << endl << name << endl << price << endl << firm << endl;
	cout << "������� ����� �������" << endl;
	int size = Reader::getInt();
	if (size < 1 || size > 700)
		throw runtime_error("�������� ����� �������");
	cout << "������� ����" << endl;
	string form;
	getline(cin, form);
	try {
		Item* item = new Book(price, firm, name, Book::Size(size), form);
		items.push_back(shared_ptr<Item>(item));
	}
	catch (...) {
		throw;//���������������
	}
	record.close();
}

void Order::addMagazine()
{
	ofstream record("Book_Store.txt", ios::out);
	cout << "������� ��������" << endl;
	string name;
	cin.ignore(INT_MAX, '\n');
	getline(cin, name);
	cout << "������� ����" << endl;
	double price;
	price = Reader::getDouble();
	cout << "������� �����" << endl;
	string firm;
	getline(cin, firm);
	record << number << endl << name << endl << price << endl << firm << endl;
	cout << "������� ����� �������" << endl;
	int size = Reader::getInt();
	if (size < 0 || size > 300) throw runtime_error("�������� ����� �������");
	int width;
	cout << "������� ���������� ������" << endl;
	width = Reader::getInt();
	if (width < 1 || width > 12) throw runtime_error("���������� ����������");
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
	cout << "������� ����� ������ ��� ��������������: " << endl;
	int n = Reader::getInt();
	ifstream reading("Buffer.txt");
	ofstream record("Book_Store.txt");
	while (reading >> num >> name >> price >> firm)
	{
		if (n != num)
		{
			cout << "��� ������ ������" << endl;
			record << num << endl << name << endl << price << endl << firm << endl;
		}
		else
		{
			cout << "������� ����� ������: " << endl;
			cout << "������� ��������" << endl;
			string name1;
			cin >> name1;
			cout << "������� ����" << endl;
			double price1;
			price1 = Reader::getDouble();
			cout << "������� �����" << endl;
			string firm1;
			cin >> firm1;
			cout << "������� ����� �������" << endl;
			int size1;
			size1 = Reader::getInt();
			if (size1 < 1 || size1 > 700)
				throw runtime_error("�������� ����� �������");
			cout << "������� ����" << endl;
			string form1;
			cin >> form1;
			record << num << endl << name1 << endl << price1 << endl << firm1 << endl;
			reading >> num >> name >> price >> firm;
		}
	}
	record.close();
	reading.close();
}
