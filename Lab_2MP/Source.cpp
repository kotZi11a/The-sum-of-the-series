#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;

double write_double()    //������� ����� � �������� �����
{
	while (bool inp = 1)
	{
		int i;
		vector<char> char_array;  // ������ ������� ����� ������� ������� �������� � ����������
		double a = 0;
		char_array.clear();  // �������� ������� ���� ����� ������� �������� ��������

		for (i = 0; i != -1; i++)  // ���� �� ����� ���� � ������
		{
			char sim = _getch();  // ���������� ������� � ����������
			if (sim != '\r')
			{
				if (sim == '\b' && char_array.size()  != 0)
				{
					cout << sim << ' ' << sim;
					char_array.pop_back();
				}
				if (sim == '.' || sim == '-' || sim <= '9' && sim >='0') // ������� �������
				{
					cout << sim;
					char_array.push_back(sim); // ������ �������� � ������
				}
			}
			else
			{
				cout << endl;
				i = -2;
			}
		}
		string number(char_array.begin(), char_array.end()); // ������ ��������� �������� �� �������
		int negat = number.find_first_of('-', 0);
		if (negat > 0 || number.find_first_of('.') != number.find_last_of('.'))
			number = "";
		if (number != "0")
		{
			int p = number.find_first_not_of('0', 0); // ���������� ������� ������� ��������� �� 0
			if (p != 1)
			{
				number = number.erase(0, p);
			}
		}
		int s = size(number);  // ���������� s ��������� �������� ����� ������ number
		if (number == "" || number[0] == '.' || s > 17) // �������� ������
		{
			cout << "Error. Write again: ";
			inp = 1;
		}
		else
		{
			a = stod(number); // ���������� � ��������� ����� ������
			inp = 0;
			return a;
		}
	}
}

int main()
{
	bool begin = true;
	while (begin)
	{
		long double a = -1;
		bool inp = 0;
		cout << "Write positive number a  = ";
		while (a <= 0) // ���� ��� ����� � � �������� ������������ �� ���
		{
			a = write_double(); // ���� �
			if (a <= 0) // �������� ������������ � ��� ���
				cout << "Error. Write positive number a  = ";
		}
		long double x = 0;
		cout << "Write number -1 < x < 1  x = ";
		while (inp == 0) // ���� ��� ����� � � ��������
		{
			x = write_double(); // ���� �
			int check = 1;
			if (x > -check && x < check) // ��������� �� ����� � � ��������� �� -1 �� 1
				inp = 1;
			else
				cout << "Error. Write number -1 < x < 1 x = ";
		}
		long double An, S = 0;
		if (abs(a - (int)a) > 0) // ����� ����� ��� �������
		{
			long double En = 0;
			long long n = 0;
			do
			{
				An = pow(x, 2 * n + 1) / (2 * n + 1); // ��������� �n
				S += An; // ����� ���� �����
				En = abs(pow(x, 2 * (n + 1) + 1) / (2 * (n + 1) + 1) / S); // ���������� �����������
				cout << fixed << "n = " << n << " A" << n << " = " << An << " S" << n << " = " << S << " En = " << En << " \n";
				n = n + 1;
			} while (En > a);
		}
		else
		{
			long double En = 0;
			for (long long n = 0; n != a; n++)
			{
				An = pow(x, 2 * n + 1) / (2 * n + 1); // ��������� �n
				S += An; // ����� ���� �����
				En = abs(pow(x, 2 * (n + 1) + 1) / (2 * (n + 1) + 1) / S); // ���������� �����������
				cout << fixed << "n = " << n << " A" << n << " = " << An << " S" << n << " = " << S << " En = " << En << " \n";
			}
		}
		cout << endl << "Continue? (Y/N) "; // �������� ���������� ��������� ��� ���
		char end = 0;
		while (end != 'y' && end != 'n' && end != 'Y' && end != 'N')
		{
			end = _getch();
		}
		cout << end << endl;
		begin = (end == 'y' || end == 'Y'); // ������� �����������
	}
}
