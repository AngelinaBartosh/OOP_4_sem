#include "Reader.h"
double Reader::getDouble() {
	double d;
	while (true) {
		cin >> d;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "¬ведите число с плавающей точкой" << endl;
		cin.ignore(10, '\n');
	}
	return d;
}

int Reader::getInt() {
	int n;
	while (true) {
		cin >> n;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "¬ведите целое число" << endl;
		cin.ignore(10, '\n');
	}
	return n;
}
