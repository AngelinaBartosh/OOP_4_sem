#pragma once
#include "Header.h"

class Book
{
private:
	string author;
	string name;
	int pagenumb;
public:
	Book(string authour = "", string name = "", int pagenumb = 0, int time = 0) :
		author(authour), name(name), pagenumb(pagenumb) {}
	string getAuthor() const {
		return author;
	}
	string getName() const {
		return name;
	}
	int getPagenumb() const {
		return pagenumb;
	}
	friend bool operator<(const Book& o1, const Book& o2) {
		return o1.author < o2.author;
	}
	/*string getStringToWrite() const {
		stringstream ss;
		ss << this->author << "|" << this->name << this->pagenumb;
		string str = ss.str();
		return str;
	}
	friend ostream& operator<<(ostream& os, list<Book>::iterator books) {
		stringstream ss;
		ss << books->getAuthor() << "|" << books->getName() << "|" << books->getPagenumb();
		string str = ss.str();
		os << ss << endl;
		return os;
	}*/
};
