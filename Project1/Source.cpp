#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include<conio.h>
#include<windows.h>
#include<string>
#include<regex>
using namespace std;


struct str
{
	char adress[19] = { "0\0" };
	int type = 0;//���������, �����, ������������
	int v = 0;
	int cost = 0;
	char FIO[15] = { "0\0" };
	char numb[11] = { "0\0" };
} struc;

FILE* f;
char FileName[100] = "\0";
int FileSize = 1;

bool isFileName()
{
	if (FileName[0] == '\0')
	{

		cout << "�� �� ����� � ���� ������ �� ������ ���������!" << endl << endl;
		
		return false;
	}
	else return true;
}

void _file_size()
{
	FileSize = 0;
	f = fopen(FileName, "rb");
	while (!feof(f))
	{
		fread(&struc, sizeof(str), 1, f);
		FileSize++;
	}
	FileSize--;
	fclose(f);

}

//////////////////

void sym(int num, int count = 1);
void st(bool a);
int leng(int a)
{
	int l = 0;
	bool var = false;
	while (a)
	{
		a /= 10;
		l++;
		var = true;
	}
	if (var)
	{
		l--;
	}
	return l;
} 


void set_adress()
{
	string str;
	regex reg(" *([��]��)?( |\\.)? *[�-ߨ��][�-����]+ *(��)?(\\.)? *[0-9]+ *");
	while (true)
	{
		cout << "\n������ ������(�������� 1): ";
		getline(cin, str);
		if (regex_match(str, reg))
		{
			str = regex_replace(str, std::regex(" {2,}"), " ");
			str = regex_replace(str, regex("(���)?.*([�-ߨ�][�-���]+ ).*([0-9]+)"), "$2$3");
			cout << str;
			strcpy(struc.adress, str.c_str());
			return;
		}
		else
		{
			std::cout << "\n����������� �������� �����!";
		}
	}
}
void set_type()
{
	int t = 0;
	while (true)
	{
		cout << "\n������� ��� ���������(1-���������, 2-�������, 3-����������)";
		cin >> t;
		if (t == 1 || t==2||t==3)
		{
			struc.type = t;
			return;
		}
		cout << "������ ���� �� ����";
	}
}
void set_v()
{
	int t = 0;
	while (true)
	{
		cout << "\n������ ������� ���������: ";
		cin >> t;
		if (t>0)
		{
			struc.v = t;
			return;
		}
		cout << "\n����������� ������� �����";
	}

}
void set_cost()
{
	int t = 0;
	while (true)
	{
		cout << "\n������ ������� ������ �� �^2: ";
		cin >> t;
		if (t > 0)
		{
			struc.cost = t;
			return;
		}
		cout << "\n����������� ������� �������";
	}

}
void set_FIO()
{
	string str;
	regex reg(" *[�-ߨ��][�-����]{0,8} +[�-ߨ��]([�-����]+)? *\\.? *[�-ߨ]([�-����]+)? *\\.? *");
	while (true)
	{
		cout << "\n������ ϲ�(������ �.�.): ";
		getline(cin, str);
		if (regex_match(str, reg))
		{
			str = regex_replace(str, std::regex(" {2,}"), " ");
			str = regex_replace(str, std::regex(" ([�-ߨ��][�-����]{0,8}).*([�-ߨ��])([�-����]+)? *([�-ߨ��])([�-����]+)? *"), "$1 $2\.$4\.");
			//str = regex_replace(str, regex("([�-ߨ]\.) *([�-ߨ]\.)"), "$1$2");
			//str = regex_replace(str, std::regex("([�-ߨ��])[^�-����]*(\\.)?"), "$1\.");
			strcpy(struc.FIO, str.c_str());
			return;
		}
		else
		{
			std::cout << "\n����������� �������� ϲ�!";
		}
	}
}
void set_numb()
{
	string str;
	regex reg(".*0[0-9]{9}.*");
	while (true)
	{
		cout << "\n������ ����� ��������(0961234567): ";
		getline(cin, str);
		if (regex_match(str, reg))
		{
			str = regex_replace(str, std::regex(".*?(0[0-9]{9}).*?"), "$1");
			strcpy(struc.numb, str.c_str());
			return;
		}
		else
		{
			std::cout << "\n����������� �������� �����!";
		}
	}
}


//////////////////
void _setfilename()
{
	system("cls");
	cout << "������ ����� �����: ";
	cin.getline(FileName, 100);

	if ((f = fopen(FileName, "r")) == NULL)
	{
		//fclose(f);
		
		for (int i = 0,var=0;;)
		{
			cout << "������ ����� �� ����!" << endl
				<< "�������� ����� ���� �� ��� ��'��?" << endl;

			if (i == 0)cout << "-->";
			cout << "\t���\n";
			if (i == 1)cout << "-->";
			cout << "\tͳ\n";

			var = _getch();
			//skip 224 
			if (var == 224) var = _getch();
			//up
			if (var == 72 && i > 0) i--;
			//down
			if (var == 80 && i < 1) i++;
			//enter
			if (var == 13 && i == 0)
			{
				f = fopen(FileName, "wb");
				fclose(f);
				_file_size();
				return;
			}
			if (var == 13 && i == 1)
			{
				_setfilename();
				return;
			}
			//esc
			if (var == 27) return;
			system("cls");
		}
	}
	_file_size();
}

void _show()
{
	if (isFileName())
	{
		if ((f = fopen(FileName, "rb")) == NULL)
		{
			cout << endl << "������� �������� �����";
			_getch();
			return;
		}
		if (FileSize < 1)
		{
			cout << "������ ����" << endl;
			return;
		}
		rewind(f);
		st(true);
		for (int i = 0; i < FileSize; i++)
		{
			fread(&struc, sizeof(str), 1, f);

			sym(9);

			sym(0, 1);
			cout << i;
			sym(0, 1);

			sym(9);

			sym(0, 1);
			cout << struc.adress;
			sym(0, 18 - strlen(struc.adress));

			sym(9);

			switch (struc.type)
			{
			case 1:
				sym(0, 1);
				cout << "���������";
				sym(0, 4);
				break;
			case 2:
				sym(0, 1);
				cout << "�������";
				sym(0, 6);
				break;
			case 3:
				sym(0, 1);
				cout << "����������";
				sym(0, 3);
				break;
			default:
				sym(0, 1);
				cout << "������!";
				sym(0, 6);
				break;
			}

			sym(9);

			sym(0, 1);
			cout << struc.v;
			sym(0, 9 - leng(struc.v));

			sym(9);

			sym(0, 1);
			cout << struc.cost;
			sym(0, 13 - leng(struc.cost));

			sym(9);

			sym(0, 1);
			cout << struc.FIO;
			sym(0, 15 - strlen(struc.FIO));

			sym(9);

			sym(0, 1);
			for (int i = 0; i < 10; i++)
			{
				if (i == 0) cout << "(";
				if (i == 3) cout << ")";
				if (i == 6 || i == 8)cout << "-";
				cout << struc.numb[i];
			}
			//cout << struc.numb;
			sym(0, 11 - strlen(struc.numb));

			sym(9);

			sym(0, 1);
			cout << (struc.v * struc.cost);
			sym(0, 9 - leng(struc.v * struc.cost));

			sym(9);

			cout << endl;
		}
		st(false);

		fclose(f);
		
	}
}

void _corr()
{
	if (isFileName())
	{
		_show();
		f = fopen(FileName, "r+b");
		cout << "������ ����� ���������, ����� ������� ������������: ";
		int num=-1;
		while (num<0 || num>FileSize-1)
		{
			cin >> num;
			if (num<0 || num>FileSize - 1) cout << "�������!\n������ ���������� �����: ";


		}
		for (int i = 0; i <= num; i++)
		{
			fread(&struc, sizeof(str), 1, f);
		}
			
		fseek(f, -1 * sizeof(str), SEEK_CUR);

		for (int i = 0, var = 0;;)
		{
			system("cls");
			cout << "�� ������� �����������:" << endl;
			if (i == 0)cout << "-->";
			cout << "\t��� �����" << endl;
			if (i == 1)cout << "-->";
			cout << "\t������" << endl;
			if (i == 2)cout << "-->";
			cout << "\t��� ���������" << endl;
			if (i == 3)cout << "-->";
			cout << "\t�������" << endl;
			if (i == 4)cout << "-->";
			cout << "\t�������" << endl;
			if (i == 5)cout << "-->";
			cout << "\tϲ�" << endl;
			if (i == 6)cout << "-->";
			cout << "\t����� ��������" << endl;

			var = _getch();
			//skip 224 
			if (var == 224) var = _getch();
			//up
			if (var == 72 && i > 0) i--;
			//down
			if (var == 80 && i < 6) i++;
			//enter
			if (var == 13)
			{
				if (i == 1 || i == 0)
				{
					set_adress();
				}
				if (i == 2 || i == 0)
				{
					set_type();
				}
				if (i == 3 || i == 0)
				{
					set_v();
				}
				if (i == 4 || i == 0)
				{
					set_cost();
				}
				if (i == 5 || i == 0)
				{
					set_FIO();
				}
				if (i == 6 || i == 0)
				{
					set_numb();
				}
				
				std::fwrite(&struc, sizeof(str), 1, f);
				fclose(f);
				return;
			}
		}
			
		
	}
}

void _add()
{
	if (isFileName())
	{

		set_adress();

		set_type();

		set_v();

		set_cost();

		set_FIO();

		set_numb();

		cout << "����� ������� ���������: " << (struc.v * struc.cost) << endl;

		f = fopen(FileName, "ab");
		fwrite(&struc, sizeof(str), 1, f);
		fclose(f);
		_file_size();
	}
}

void _del()
{
	system("cls");
	int num = -1;
	if (isFileName())
	{
		_show();

		cout << "������ ����� ���������, ����� ������ ��������: ";
		cin >> num;
		if (num < 0 || num >= FileSize)
		{
			cout << "������������ ����� ������!" << endl;
			_del();
			return;
		}
		else
		{
			FILE* var = fopen("var", "wb");
			f = fopen(FileName, "rb");
			//write on "var"
			for (int i = 0; i < FileSize; i++)
			{
				fread(&struc, sizeof(str), 1, f);
				if (i != num)
				{
					fwrite(&struc, sizeof(str), 1, var);
				}
			}
			fclose(f);
			fclose(var);

			//write on FileName
			var = fopen("var", "rb");
			f = fopen(FileName, "wb");
			for (int i = 0; i < FileSize-1; i++)
			{
				fread(&struc, sizeof(str), 1, var);

				fwrite(&struc, sizeof(str), 1, f);
			}
			fclose(f);
			fclose(var);
			remove("var");
			_file_size();
		}
	}

}

void _sort()
{
	if (isFileName())
	{
		for (int i = 0, var = 0;;)
		{
			bool z = true;
			cout << "�� ���� ��������� ���������?" << endl;

			if (i == 0)cout << "-->";
			cout << "\t�� ������ ���������\n";
			if (i == 1)cout << "-->";
			cout << "\t�� �������\n";

			var = _getch();
			//skip 224 
			if (var == 224) var = _getch();
			//up
			if (var == 72 && i > 0) i--;
			//down
			if (var == 80 && i < 1) i++;
			//enter
			if (var == 13 && i == 0)
			{
				for (;;)
				{
					system("cls");
					cout << "�� ���� ��������� ���������?" << endl << "\t�� ������ ���������\n";

					if (i == 0)cout << "-->";
					cout << "\t\t�� ����������\n";
					if (i == 1)cout << "-->";
					cout << "\t\t�� ��������\n";

					cout << "\t�� �������\n";
					var = _getch();
					//skip 224 
					if (var == 224) var = _getch();
					//up
					if (var == 72 && i > 0) i--;
					//down
					if (var == 80 && i < 1) i++;
					//enter
					if (var == 13)
					{
						z = i;
						break;
					}
				}
				f = fopen(FileName, "r+b");
				str var;
				for (i = 0; i < FileSize; i++)
				{
					fread(&struc, sizeof(str), 1, f);
					fread(&var, sizeof(str), 1, f);
					if (((z)?(struc.v < var.v):(struc.v > var.v)))
					{
						fseek(f, -2 * sizeof(str), SEEK_CUR);
						fwrite(&(var), sizeof(str), 1, f);
						fwrite(&(struc), sizeof(str), 1, f);
						fseek(f, 0, SEEK_SET);
						i = 0;

					}
					fseek(f, -1 * sizeof(str), SEEK_CUR);
				}
				return;
			}
			if (var == 13 && i == 1)
			{
				for (;;)
				{
					system("cls");
					cout << "�� ���� ��������� ���������?" << endl << "\t�� ������ ���������\n\t�� �������\n";

					if (i == 0)cout << "-->";
					cout << "\t\t�� ����������\n";
					if (i == 1)cout << "-->";
					cout << "\t\t�� ��������\n";

					var = _getch();
					//skip 224 
					if (var == 224) var = _getch();
					//up
					if (var == 72 && i > 0) i--;
					//down
					if (var == 80 && i < 1) i++;
					//enter
					if (var == 13)
					{
						z = i;
						break;
					}
				}
				f = fopen(FileName, "r+b");
				str var;
				for (i = 0; i < FileSize; i++)
				{
					fread(&struc, sizeof(str), 1, f);
					fread(&var, sizeof(str), 1, f);
					if (((z) ? (struc.v * struc.cost < var.v * var.cost) : (struc.v * struc.cost > var.v * var.cost)))
					{
						fseek(f, -2 * sizeof(str), SEEK_CUR);
						fwrite(&(var), sizeof(str), 1, f);
						fwrite(&(struc), sizeof(str), 1, f);
						fseek(f, 0, SEEK_SET);
						i = 0;

					}
					fseek(f, -1 * sizeof(str), SEEK_CUR);
				}
				return;
			}
			system("cls");
		}
	}
}





void zapyt1() {

	int var = 0,
		count = 0;
	while (true) {
		system("cls");
		cout << "������� ��� ��������, ����� ���� ����������(1-���������, 2-�������, 3-����������): ";
		cin >> var;
		if (var >= 1 && var <= 3) break;
		cout << "\t������ ���� �� ����!\n";
		system("pause");
	}
	f = fopen(FileName, "rb");
	for (int i = 0; i < FileSize; i++)
	{
		fread(&struc, sizeof(str), 1, f);
		if (struc.type == var) count++;
	}

	rewind(f);

	if (count == 0)
	{
		cout << "�������� �� ����� ����� �� ���� ��������!\n";
		return;
	}
	else
	{
		st(true);
		for (int i = 0; i < FileSize; i++)
		{
			fread(&struc, sizeof(str), 1, f);
			if (struc.type == var)
			{
				sym(9);

				sym(0, 1);
				cout << i;
				sym(0, 1);

				sym(9);

				sym(0, 1);
				cout << struc.adress;
				sym(0, 18 - strlen(struc.adress));

				sym(9);

				switch (struc.type)
				{
				case 1:
					sym(0, 1);
					cout << "���������";
					sym(0, 4);
					break;
				case 2:
					sym(0, 1);
					cout << "�������";
					sym(0, 6);
					break;
				case 3:
					sym(0, 1);
					cout << "����������";
					sym(0, 3);
					break;
				default:
					sym(0, 1);
					cout << "������!";
					sym(0, 6);
					break;
				}

				sym(9);

				sym(0, 1);
				cout << struc.v;
				sym(0, 9 - leng(struc.v));

				sym(9);

				sym(0, 1);
				cout << struc.cost;
				sym(0, 13 - leng(struc.cost));

				sym(9);

				sym(0, 1);
				cout << struc.FIO;
				sym(0, 15 - strlen(struc.FIO));

				sym(9);

				sym(0, 1);
				cout << struc.numb;
				sym(0, 15 - strlen(struc.numb));

				sym(9);

				sym(0, 1);
				cout << (struc.v * struc.cost);
				sym(0, 9 - leng(struc.v * struc.cost));

				sym(9);

				cout << endl;
			}
		}
		st(false);
	}
	fclose(f);
}
void zapyt2() {
	int var = 0,
		count = 0;
	while (true) {
		system("cls");
		cout << "������ ����� ��������, ����� ���� ����������: ";
		cin >> var;
		if (var > -1) break;
		cout << "\t����������� ������� �����!\n";
		system("pause");
	}
	f = fopen(FileName, "rb");
	for (int i = 0; i < FileSize; i++)
	{
		fread(&struc, sizeof(str), 1, f);
		if (struc.v == var) count++;
	}

	rewind(f);

	if (count == 0)
	{
		cout << "�������� �� ����� ������ �� ���� ��������!\n";
		return;
	}
	else
	{
		st(true);
		for (int i = 0; i < FileSize; i++)
		{
			fread(&struc, sizeof(str), 1, f);
			if (struc.v == var)
			{
				sym(9);

				sym(0, 1);
				cout << i;
				sym(0, 1);

				sym(9);

				sym(0, 1);
				cout << struc.adress;
				sym(0, 18 - strlen(struc.adress));

				sym(9);

				switch (struc.type)
				{
				case 1:
					sym(0, 1);
					cout << "���������";
					sym(0, 4);
					break;
				case 2:
					sym(0, 1);
					cout << "�������";
					sym(0, 6);
					break;
				case 3:
					sym(0, 1);
					cout << "����������";
					sym(0, 3);
					break;
				default:
					sym(0, 1);
					cout << "������!";
					sym(0, 6);
					break;
				}

				sym(9);

				sym(0, 1);
				cout << struc.v;
				sym(0, 9 - leng(struc.v));

				sym(9);

				sym(0, 1);
				cout << struc.cost;
				sym(0, 13 - leng(struc.cost));

				sym(9);

				sym(0, 1);
				cout << struc.FIO;
				sym(0, 15 - strlen(struc.FIO));

				sym(9);

				sym(0, 1);
				cout << struc.numb;
				sym(0, 15 - strlen(struc.numb));

				sym(9);

				sym(0, 1);
				cout << (struc.v * struc.cost);
				sym(0, 9 - leng(struc.v * struc.cost));

				sym(9);

				cout << endl;
			}
		}
		st(false);
	}
	fclose(f);
}
void zapyt3() {
	int var = 0,
		count = 0;
	while (true) {
		system("cls");
		cout << "������ ������� ��������, ����� ���� ����������: ";
		cin >> var;
		if (var > -1) break;
		cout << "\t����������� ������� �������!\n";
		system("pause");
	}
	f = fopen(FileName, "rb");
	for (int i = 0; i < FileSize; i++)
	{
		fread(&struc, sizeof(str), 1, f);
		if (struc.v * struc.cost == var) count++;;
	}

	if (count == 0)
	{
		cout << "�������� �� ����� ������ �� ���� ��������!\n";
		return;
	}
	else
	{
		cout << "���� �������� " << count << " ��������(-��) �� ������ �������.\n";
	}
	fclose(f);
}
void zapyt4() {
	int t1 = 0, t2 = 0, t3 = 0;
	f = fopen(FileName, "rb");
	for (int i = 0; i < FileSize; i++)
	{
		fread(&struc, sizeof(str), 1, f);
		if (struc.type == 1) t1++;
		if (struc.type == 2) t2++;
		if (struc.type == 3) t3++;
	}
	if ((t1 + t2 + t3) != FileSize)
	{
		cout << "������� ��� �����������";
		system("pause");
		_file_size();
		zapyt4();
	}
	else
	{
		system("cls");
		cout << "���������� ��������: " << 100. / FileSize * t1 << "%" << endl
			<< "�������� ��������: " << 100. / FileSize * t2 << "%"<< endl
			<< "����������� ��������: " << 100. / FileSize * t3 << "%" << endl;
	}
	fclose(f);
}
void zapyt5() {
	int type = 0, v = 0, cost = 0, count = 0;
	system("cls");
	while (true) {
		cout << "������� ��� ��������, ����� ���� ����������(1-���������, 2-�������, 3-����������): ";
		cin >> type;
		if (type >= 1 && type <= 3) break;
		cout << "\t������ ���� �� ����!\n";
		system("pause");
	}
	while (true) {
		//system("cls");
		cout << "������ ����� ��������, ����� ���� ����������: ";
		cin >> v;
		if (v > -1) break;
		cout << "\t����������� ������� �����!\n";
		system("pause");
	}
	f = fopen(FileName, "rb");
	for (int i = 0; i < FileSize; i++)
	{
		fread(&struc, sizeof(str), 1, f);
		if (struc.type == type && struc.v == v)
		{
			cost += struc.v * struc.cost;
			count++;
		}
	}
		
	//system("cls");
	if (count > 0)	cout << "������� ������� ������� ��������: " << cost / count << endl;
	else cout << "�������� �� ������� ����������� �� ���� ��������!" << endl;

	fclose(f);
}
void _zapyt()
{
	char menu[5][100] = {
		"����� �1\n\t\t��������� �� ������� �����",
		"����� �2\n\t\t��������� �� �������� ��������� ������",
		"����� �3\n\t\t�������� ������� ��� ��������, ������� ������� ���� ������� � ���������",
		"����� �4\n\t\t��������� ������������ �� ������",
		"����� �5\n\t\t������� ������� ��������� ������� ���� �� ����� �����"
	};
	int choise = 0, key = 0;
	if (isFileName())
	{
		do
		{
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				if (choise == i) cout << "-->\t";
				else cout << "\t";
				cout << menu[i] << endl;
			}


			key = _getch();
			//skip 224 
			if (key == 224) key = _getch();
			//up
			if (key == 72 && choise > 0) choise--;
			//down
			if (key == 80 && choise < 4) choise++;
			//esc
			if (key == 27) return;
			//enter
			if (key == 13) {
				if (choise == 0) zapyt1();
				if (choise == 1) zapyt2();
				if (choise == 2) zapyt3();
				if (choise == 3) zapyt4();
				if (choise == 4) zapyt5();
				return;
			}
		} while (true);

	}
}

void (*funk[7])() = {
	_setfilename,
	_show,
	_corr,
	_add,
	_del,
	_sort,
	_zapyt};


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char menu[8][100] = {
		"������ ����� �����",
		"�������� �������� ��������",
		"������������ ��������� ���������",
		"��������� ��������",
		"��������� ��������",
		"���������� ��������",
		"��������� ������",
		"���������� ������" };


	

	int choise = 0, key = 0;
	do
	{
		for (int i = 0; i < 8; i++)
		{
			if (choise == i) cout << "-->\t";
			else cout << "\t";
			cout << menu[i] << endl;
		}

		if (FileName[0] == '\0')	cout << "\n\n\t���� �� ��������\n";
		else cout << "\n\n\t�� �������� �� ������: \t" << FileName << "\n\tʳ������ �������� � ����: " << FileSize << endl;


		key = _getch();
		//skip 224 
		if (key == 224) key = _getch();
		//up
		if (key == 72 && choise > 0) choise--;
		//down
		if (key == 80 && choise < 7) choise++;
		//enter
		if (key == 13 && choise != 7)
		{
			system("cls");
			funk[choise]();
			system("pause");
		}
		//exit
		if (key == 13 && choise == 7) return 0;


		system("cls");
	} while (true);





	//////////////////

	


	return 0;
}



void sym(int num, int count)
{
	SetConsoleOutputCP(866);
	//SetConsoleCP(1251);

	for (int i = 0; i < count; i++)
	{
		switch (num)
		{
		case 0:
			cout << " ";
			break;
		case 1:
			cout << "\xc9";
			break;
		case 2:
			cout << "\xcd";
			break;
		case 3:
			cout << "\xcb";
			break;
		case 4:
			cout << "\xbb";
			break;
		case 5:
			cout << "\xba";
			break;
		case 6:
			cout << "\xc8";
			break;
		case 7:
			cout << "\xca";
			break;
		case 8:
			cout << "\xbc";
			break;
		case 9:
			cout << "\xb3";
			break;
		case 10:
			cout << "\xc3";
			break;
		case 11:
			cout << "\xc4";
			break;
		case 12:
			cout << "\xc5";
			break;
		case 13:
			cout << "\xb4";
			break;
		case 14:
			cout << "\xc0";
			break;
		case 15:
			cout << "\xc1";
			break;
		case 16:
			cout << "\xd9";
			break;
		default:
			cout << "\\";
			break;
		}
	}
	SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);
}

//����� 1-������, 0-�����
void st(bool a)
{
	if (a)
	{
		{
			sym(1);
			sym(2, 3);//11num
			sym(3);
			sym(2, 19);//11adr
			sym(3);
			sym(2, 14);//11type
			sym(3);
			sym(2, 11);//11V
			sym(3);
			sym(2, 15);//1cost
			sym(3);
			sym(2, 16);//FIO
			sym(3);
			sym(2, 16);//phone
			sym(3);
			sym(2, 11);//all
			sym(4);
		}

		cout << endl;

		{
			sym(5);

			sym(0, 1);
			cout << "�";
			sym(0, 1);

			sym(5);

			sym(0, 1);
			cout << "������";
			sym(0, 12);

			sym(5);

			sym(0, 5);
			cout << "���";
			sym(0, 6);

			sym(5);

			sym(0, 3);
			cout << "�����";
			sym(0, 3);

			sym(5);

			sym(0, 3);
			cout << "�������";
			sym(0, 4);

			sym(5);

			sym(0, 2);
			cout << "ϲ� ��������";
			sym(0, 2);

			sym(5);

			sym(0, 1);
			cout << "����� ��������";
			sym(0, 1);

			sym(5);

			sym(0, 3);
			cout << "�����";
			sym(0, 3);

			sym(5);
		}

		cout << endl;

		{
			sym(5);

			sym(0, 3);

			sym(5);

			sym(0, 19);

			sym(5);

			sym(0, 2);
			cout << "���������";
			sym(0, 2);

			sym(5);

			sym(0, 1);
			cout << "���������";
			//sym(0, 0);

			sym(5);

			sym(0, 1);
			cout << "������ �� �^2";
			sym(0, 1);

			sym(5);

			sym(0, 16);

			sym(5);

			sym(0, 16);

			sym(5);

			sym(0, 1);
			cout << "�������";
			sym(0, 2);

			sym(5);
		};

		cout << endl;

		{
			sym(6);
			sym(2, 3);//11num
			sym(7);
			sym(2, 19);//11adr
			sym(7);
			sym(2, 14);//11type
			sym(7);
			sym(2, 11);//11V
			sym(7);
			sym(2, 15);//1cost
			sym(7);
			sym(2, 16);//FIO
			sym(7);
			sym(2, 16);//phone
			sym(7);
			sym(2, 11);//all
			sym(8);
		}

		cout << endl;

	}
	else
	{
		{
			sym(14);
			sym(11, 3);//11num
			sym(15);
			sym(11, 19);//11adr
			sym(15);
			sym(11, 14);//11type
			sym(15);
			sym(11, 11);//11V
			sym(15);
			sym(11, 15);//1cost
			sym(15);
			sym(11, 16);//FIO
			sym(15);
			sym(11, 16);//phone
			sym(15);
			sym(11, 11);//all
			sym(16);
		}

		cout << endl;
	}
}