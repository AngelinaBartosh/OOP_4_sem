#include <Windows.h>
#include <limits>

#include "BookStore.h"

void myTerm() {
	cout << "В процессе работы программы произошла ошибка" << endl;
	exit(-1);
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set_terminate(myTerm);
	cout << "Введите название книжного магазина" << endl;
	string name;
	getline(cin, name);
	BookStore store(name);
	store.menu();
	return 0;
}