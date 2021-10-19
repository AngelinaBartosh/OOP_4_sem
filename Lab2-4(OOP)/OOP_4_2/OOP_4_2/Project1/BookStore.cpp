#include "BookStore.h"

void BookStore::menu()
{
	int choice = -1;
	while (choice != 0) {
		system("cls");
		cout << "������� �������: " << name << endl;
		cout << "1. ���������� �����" << endl
			<< "2. ������� ���������� � ������" << endl
			<< "3. ������ �������" << endl
			<< "0. �����" << endl;
		while (true) {
			try {
				cin >> choice;
				if (choice < 0 || choice > 4) {
					throw runtime_error("������������ ����� ����");
				}
				break;
			}
			catch (runtime_error e) {
				cout << e.what() << endl;
			}
		}
		switch (choice) {
		case 1:
			addOrder();
			break;
		case 2:
			removeOrder();
			break;
		case 3:
			showOrders();
			break;
		}
		system("pause");
	}
}


void BookStore::addOrder()
{
	cout << "������� ���������� �������" << endl;
	int count = Reader::getInt();
	try {
		Order* os = new Order[count];
		int good = 0;
		for (int i = 0; i < count; i++) {
			try {
				int choice = -1;
				while (choice != 1) {
					system("cls");
					cout << "���������� ������ " << i + 1 << " �� " << count << endl;
					cout << "1. ��������� �����" << endl
						<< "2. �������� �����" << endl
						<< "3. �������� ������" << endl
						<< "4. ����������� �����" << endl
						<< "5. ������������� �����" << endl;
					while (true) {
						try {
							cin >> choice;
							if (choice < 1 || choice > 5) {
								throw runtime_error("������������ ����� ����");
							}
							break;
						}
						catch (runtime_error e) {
							cout << e.what() << endl;
						}
					}
					switch (choice) {
					case 1:
						if (os[i].getItems().size() == 0)
							throw exception("��� �������");
						break;
					case 2:
						os[i].addBook();
						cout << "����� ���������" << endl;
						break;
					case 3:
						os[i].addMagazine();
						cout << "������ ��������" << endl;
						break;
					case 4:
						if (os[i].getItems().size() == 0)
							cout << "����� ����" << endl;
						else
							os[i].printInfo();
						break;
					case 5:
						os[i].editData();
						break;
					}
					system("pause");
				}
				good++;
				cout << "����� ��������" << endl;
			}
			catch (MoneyException e) {
				cout << e.what() << endl;
				os[i].clearItems();
			}
			catch (exception e) {
				cout << e.what() << endl;
				cout << "����� �� ��� ��������" << endl;
				os[i].clearItems();
			}
			system("pause");
		}

		for (int i = 0; i < count; i++) {
			if (!os[i].getItems().empty())
				orders.push_back(os[i]);
		}

		cout << "��������� �������: " << good << endl;
	}
	catch (bad_alloc e) { //� new
		cout << "�������� ����������" << endl;
	}
}


void BookStore::showOrders()
{
	if (orders.size() == 0) {
		cout << "��� �������" << endl;
		return;
	}
	for (auto& order : orders) {
		order.printInfo();
		cout << endl;
	}
}


void BookStore::removeOrder()
{
	if (orders.size() == 0) {
		cout << "��� �������" << endl;
		return;
	}
	cout << "������� ����� ������ ��� ��������" << endl;
	showOrders();
	int index = Reader::getInt() - 1;
	try {
		Order& order = orders.at(index);
		cout << "��������� �����" << endl;
		order.printInfo();
		orders.erase(orders.begin() + index);
		cout << "����� ������" << endl;
	}
	catch (out_of_range e) {
		cout << "�������� �����" << endl;
	}
}
