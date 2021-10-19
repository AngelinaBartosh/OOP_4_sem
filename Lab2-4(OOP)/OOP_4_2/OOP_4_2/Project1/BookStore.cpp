#include "BookStore.h"

void BookStore::menu()
{
	int choice = -1;
	while (choice != 0) {
		system("cls");
		cout << "Книжный магазин: " << name << endl;
		cout << "1. Обработать заказ" << endl
			<< "2. Удалить информацию о заказе" << endl
			<< "3. Список заказов" << endl
			<< "0. Выход" << endl;
		while (true) {
			try {
				cin >> choice;
				if (choice < 0 || choice > 4) {
					throw runtime_error("Неправильный пункт меню");
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
	cout << "Введите количество заказов" << endl;
	int count = Reader::getInt();
	try {
		Order* os = new Order[count];
		int good = 0;
		for (int i = 0; i < count; i++) {
			try {
				int choice = -1;
				while (choice != 1) {
					system("cls");
					cout << "Добавление заказа " << i + 1 << " из " << count << endl;
					cout << "1. Завершить заказ" << endl
						<< "2. Добавить книгу" << endl
						<< "3. Добавить журнал" << endl
						<< "4. Просмотреть заказ" << endl
						<< "5. Редактировать заказ" << endl;
					while (true) {
						try {
							cin >> choice;
							if (choice < 1 || choice > 5) {
								throw runtime_error("Неправильный пункт меню");
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
							throw exception("Нет товаров");
						break;
					case 2:
						os[i].addBook();
						cout << "Книга добавлена" << endl;
						break;
					case 3:
						os[i].addMagazine();
						cout << "Журнал добавлен" << endl;
						break;
					case 4:
						if (os[i].getItems().size() == 0)
							cout << "Заказ пуст" << endl;
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
				cout << "Заказ оформлен" << endl;
			}
			catch (MoneyException e) {
				cout << e.what() << endl;
				os[i].clearItems();
			}
			catch (exception e) {
				cout << e.what() << endl;
				cout << "Заказ не был добавлен" << endl;
				os[i].clearItems();
			}
			system("pause");
		}

		for (int i = 0; i < count; i++) {
			if (!os[i].getItems().empty())
				orders.push_back(os[i]);
		}

		cout << "Оформлено заказов: " << good << endl;
	}
	catch (bad_alloc e) { //с new
		cout << "Неверное количество" << endl;
	}
}


void BookStore::showOrders()
{
	if (orders.size() == 0) {
		cout << "Нет заказов" << endl;
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
		cout << "Нет заказов" << endl;
		return;
	}
	cout << "Введите номер заказа для удаления" << endl;
	showOrders();
	int index = Reader::getInt() - 1;
	try {
		Order& order = orders.at(index);
		cout << "Выбранный заказ" << endl;
		order.printInfo();
		orders.erase(orders.begin() + index);
		cout << "Заказ удален" << endl;
	}
	catch (out_of_range e) {
		cout << "Неверный номер" << endl;
	}
}
