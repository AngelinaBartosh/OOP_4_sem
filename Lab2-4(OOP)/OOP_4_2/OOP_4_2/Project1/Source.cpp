#include <Windows.h>
#include <limits>

#include "BookStore.h"

void myTerm() {
	cout << "� �������� ������ ��������� ��������� ������" << endl;
	exit(-1);
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set_terminate(myTerm);
	cout << "������� �������� �������� ��������" << endl;
	string name;
	getline(cin, name);
	BookStore store(name);
	store.menu();
	return 0;
}