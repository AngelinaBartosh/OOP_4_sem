#pragma once
#include <exception>

using namespace std;

class MoneyException : public exception
{
public:
	MoneyException() : exception("�������� ������ ����� ��������� �����") {}
	MoneyException(const char* message) : exception(message) {}
};
