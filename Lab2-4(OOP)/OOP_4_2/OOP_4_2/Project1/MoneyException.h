#pragma once
#include <exception>

using namespace std;

class MoneyException : public exception
{
public:
	MoneyException() : exception("Неверный формат ввода количеста денег") {}
	MoneyException(const char* message) : exception(message) {}
};
