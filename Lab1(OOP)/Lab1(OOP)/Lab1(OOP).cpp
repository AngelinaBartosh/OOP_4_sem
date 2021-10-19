
#include "Header.h"
int Order::count = NULL;
int checkChoise() {
	char temp;
	cout << "Введите нужное поле: ";
	do {
		temp = _getch();
	} while (!(temp > '0' && temp < '6'));
	cout << temp;
	system("cls");
	return atoi(&temp);
}





int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 && cls");
	Document* doc = new Document[10];
	Document::readData(doc);
	system("cls");
	int choise = NULL, i = NULL;
	string str;
	while (choise != 5) {
		cout << "1. Добавить товар в отчет.\n"
			"2. Редактирование данных.\n"
			"3. Сохранение данных.\n"
			"4. Показать отчет.\n"
			"5. Выход.\n";
		choise = checkChoise();
		switch (choise)
		{
		case 1:
			i = Document::getCount();
			if (i < 10) {
				doc[i].add();
				Document::setCountMore();
			}
			else cout << "Функция недоступна." << endl;
			system("pause && cls");
			break;
		case 2:
			cout << "Введите название товара: ";
			fseek(stdin, 0, SEEK_END);
			getline(cin, str);
			i = Document::currentName(doc, str);
			if (i == -1) cout << "Объект не найден." << endl;
			else {
				cout << "Объект найден." << endl;
				if (doc->beginTransaction(doc[i])) cout << "Транзакция прошла успешно" << endl;
				else cout << "Транзакция отменена" << endl;
			}
			system("pause && cls");
			break;
		case 3:
			if (Document::getCount() == 0) cout << "Функция недоступна." << endl;
			else File::saveData(doc);
			system("pause && cls");
			break;
		case 4:
			if (Document::getCount() == NULL) cout << "Функция недоступна." << endl;
			else
				for (int k = NULL; k < Document::getCount(); k++)
					doc[k].show();
			system("pause && cls");
			break;
		case 5:
			break;
		default:
			cout << "Вы ввели неверное занчение." << endl;
			break;
		}
	}
}