#include "Header.h"

int checkInt(char num = 9)
{
	int k = 1;
	string str;
	while (true)
	{
		k = 1;
		getline(cin, str);
		while (true)
		{
			if (str.size() == 0)
			{
				cout << "�������� ������ �����! ���������� ��� ���: ";
				getline(cin, str);
			}
			else break;
		}
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > num)
			{
				cout << "�������� ������ �����! ���������� ��� ���: ";
				k = 0;
				break;
			}
		}
		if (k == 1)
			break;
	}
	k = atoi(str.c_str());
	return k;
}

float checkFloat()
{
	float d;
	bool k;
	string str;
	while (true)
	{
		k = true;
		getline(cin, str);
		while (true)
		{
			if (str.size() == 0)
			{
				cout << "�������� ������ �����! ���������� ��� ���: ";
				getline(cin, str);
			}
			else break;
		}
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '/' || str[i] == ',')
			{
				cout << "�������� ������ �����! ���������� ��� ���: ";
				k = false;
				break;
			}
			if (str[i] < '.' || str[i] > '9')
			{
				cout << "�������� ������ �����! ���������� ��� ���: ";
				k = false;
				break;
			}
		}
		if (k == true)
			break;
	}
	d = atof(str.c_str());
	return d;
}

void systemPause() {
	system("pause");
	system("cls");
}