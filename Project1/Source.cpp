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
	int type = 0;//складское, жилое, промышленное
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

		cout << "Ви не ввели з яким файлом ви хочете працювати!" << endl << endl;
		
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
	regex reg(" *([Вв]ул)?( |\\.)? *[А-ЯЁІЇ][а-яёії]+ *(кв)?(\\.)? *[0-9]+ *");
	while (true)
	{
		cout << "\nВведіть адресу(Гладкова 1): ";
		getline(cin, str);
		if (regex_match(str, reg))
		{
			str = regex_replace(str, std::regex(" {2,}"), " ");
			str = regex_replace(str, regex("(вул)?.*([А-ЯЁІ][а-яёі]+ ).*([0-9]+)"), "$2$3");
			cout << str;
			strcpy(struc.adress, str.c_str());
			return;
		}
		else
		{
			std::cout << "\nНеправильно вказаний адрес!";
		}
	}
}
void set_type()
{
	int t = 0;
	while (true)
	{
		cout << "\nВиберіть тип приміщення(1-складське, 2-житлове, 3-промислове)";
		cin >> t;
		if (t == 1 || t==2||t==3)
		{
			struc.type = t;
			return;
		}
		cout << "Такого типу не існує";
	}
}
void set_v()
{
	int t = 0;
	while (true)
	{
		cout << "\nВкажіть площину приміщення: ";
		cin >> t;
		if (t>0)
		{
			struc.v = t;
			return;
		}
		cout << "\nНеправильно вказано площу";
	}

}
void set_cost()
{
	int t = 0;
	while (true)
	{
		cout << "\nВкажіть вартість оренди за м^2: ";
		cin >> t;
		if (t > 0)
		{
			struc.cost = t;
			return;
		}
		cout << "\nНеправильно вказано вартість";
	}

}
void set_FIO()
{
	string str;
	regex reg(" *[А-ЯЁІЇ][а-яёії]{0,8} +[А-ЯЁІЇ]([а-яёії]+)? *\\.? *[А-ЯЁ]([а-яёії]+)? *\\.? *");
	while (true)
	{
		cout << "\nВведіть ПІБ(Іванов І.І.): ";
		getline(cin, str);
		if (regex_match(str, reg))
		{
			str = regex_replace(str, std::regex(" {2,}"), " ");
			str = regex_replace(str, std::regex(" ([А-ЯЁІЇ][а-яёії]{0,8}).*([А-ЯЁІЇ])([а-яёії]+)? *([А-ЯЁІЇ])([а-яёії]+)? *"), "$1 $2\.$4\.");
			//str = regex_replace(str, regex("([А-ЯЁ]\.) *([А-ЯЁ]\.)"), "$1$2");
			//str = regex_replace(str, std::regex("([А-ЯЁІЇ])[^а-яёії]*(\\.)?"), "$1\.");
			strcpy(struc.FIO, str.c_str());
			return;
		}
		else
		{
			std::cout << "\nНеправильно вказаний ПІБ!";
		}
	}
}
void set_numb()
{
	string str;
	regex reg(".*0[0-9]{9}.*");
	while (true)
	{
		cout << "\nВведіть номер телефону(0961234567): ";
		getline(cin, str);
		if (regex_match(str, reg))
		{
			str = regex_replace(str, std::regex(".*?(0[0-9]{9}).*?"), "$1");
			strcpy(struc.numb, str.c_str());
			return;
		}
		else
		{
			std::cout << "\nНеправильно вказаний номер!";
		}
	}
}


//////////////////
void _setfilename()
{
	system("cls");
	cout << "Введіть назву файла: ";
	cin.getline(FileName, 100);

	if ((f = fopen(FileName, "r")) == NULL)
	{
		//fclose(f);
		
		for (int i = 0,var=0;;)
		{
			cout << "Такого файлу не існує!" << endl
				<< "Створити новий файл із цим ім'ям?" << endl;

			if (i == 0)cout << "-->";
			cout << "\tТак\n";
			if (i == 1)cout << "-->";
			cout << "\tНі\n";

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
			cout << endl << "Помилка відкриття файлу";
			_getch();
			return;
		}
		if (FileSize < 1)
		{
			cout << "Пустий файл" << endl;
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
				cout << "Складське";
				sym(0, 4);
				break;
			case 2:
				sym(0, 1);
				cout << "Житлове";
				sym(0, 6);
				break;
			case 3:
				sym(0, 1);
				cout << "Промислове";
				sym(0, 3);
				break;
			default:
				sym(0, 1);
				cout << "Ошибка!";
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
		cout << "Введіть номер приміщення, котре потребує коректування: ";
		int num=-1;
		while (num<0 || num>FileSize-1)
		{
			cin >> num;
			if (num<0 || num>FileSize - 1) cout << "Помилка!\nВведіть правильний номер: ";


		}
		for (int i = 0; i <= num; i++)
		{
			fread(&struc, sizeof(str), 1, f);
		}
			
		fseek(f, -1 * sizeof(str), SEEK_CUR);

		for (int i = 0, var = 0;;)
		{
			system("cls");
			cout << "Що потрібно скорегувати:" << endl;
			if (i == 0)cout << "-->";
			cout << "\tВсю запис" << endl;
			if (i == 1)cout << "-->";
			cout << "\tАдресу" << endl;
			if (i == 2)cout << "-->";
			cout << "\tТип приміщення" << endl;
			if (i == 3)cout << "-->";
			cout << "\tПлощину" << endl;
			if (i == 4)cout << "-->";
			cout << "\tВартість" << endl;
			if (i == 5)cout << "-->";
			cout << "\tПІБ" << endl;
			if (i == 6)cout << "-->";
			cout << "\tномер телефону" << endl;

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

		cout << "Повна вартість приміщення: " << (struc.v * struc.cost) << endl;

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

		cout << "Введіть номер приміщення, котру хочете видалити: ";
		cin >> num;
		if (num < 0 || num >= FileSize)
		{
			cout << "Неправильний номер запису!" << endl;
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
			cout << "За яким признаком сортувати?" << endl;

			if (i == 0)cout << "-->";
			cout << "\tза площею приміщення\n";
			if (i == 1)cout << "-->";
			cout << "\tЗа вартістю\n";

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
					cout << "За яким признаком сортувати?" << endl << "\tза площею приміщення\n";

					if (i == 0)cout << "-->";
					cout << "\t\tза зростанням\n";
					if (i == 1)cout << "-->";
					cout << "\t\tпо спаданню\n";

					cout << "\tЗа вартістю\n";
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
					cout << "За яким признаком сортувати?" << endl << "\tза площею приміщення\n\tЗа вартістю\n";

					if (i == 0)cout << "-->";
					cout << "\t\tза зростанням\n";
					if (i == 1)cout << "-->";
					cout << "\t\tпо спаданню\n";

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
		cout << "Виберіть тип приміщень, котре буде виводитися(1-складське, 2-житлове, 3-промислове): ";
		cin >> var;
		if (var >= 1 && var <= 3) break;
		cout << "\tТакого типу не існує!\n";
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
		cout << "приміщень за даним типом не було знайдено!\n";
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
					cout << "Складське";
					sym(0, 4);
					break;
				case 2:
					sym(0, 1);
					cout << "Житлове";
					sym(0, 6);
					break;
				case 3:
					sym(0, 1);
					cout << "Промислове";
					sym(0, 3);
					break;
				default:
					sym(0, 1);
					cout << "Ошибка!";
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
		cout << "Введіть площу приміщень, котре буде виводитися: ";
		cin >> var;
		if (var > -1) break;
		cout << "\tНеправильно вказана площа!\n";
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
		cout << "Приміщень за даною площею не було знайдено!\n";
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
					cout << "Складське";
					sym(0, 4);
					break;
				case 2:
					sym(0, 1);
					cout << "Житлове";
					sym(0, 6);
					break;
				case 3:
					sym(0, 1);
					cout << "Промислове";
					sym(0, 3);
					break;
				default:
					sym(0, 1);
					cout << "Ошибка!";
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
		cout << "Введіть вартість приміщень, котре буде виводитися: ";
		cin >> var;
		if (var > -1) break;
		cout << "\tНеправильно вказана вартість!\n";
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
		cout << "Приміщень за даною ватістю не було знайдено!\n";
		return;
	}
	else
	{
		cout << "Було знайдено " << count << " приміщень(-ня) за данною вартістю.\n";
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
		cout << "Помилка при підсчитуванні";
		system("pause");
		_file_size();
		zapyt4();
	}
	else
	{
		system("cls");
		cout << "Складських приміщень: " << 100. / FileSize * t1 << "%" << endl
			<< "Житлових приміщень: " << 100. / FileSize * t2 << "%"<< endl
			<< "Промислових приміщень: " << 100. / FileSize * t3 << "%" << endl;
	}
	fclose(f);
}
void zapyt5() {
	int type = 0, v = 0, cost = 0, count = 0;
	system("cls");
	while (true) {
		cout << "Виберіть тип приміщень, котре буде виводитися(1-складське, 2-житлове, 3-промислове): ";
		cin >> type;
		if (type >= 1 && type <= 3) break;
		cout << "\tТакого типу не існує!\n";
		system("pause");
	}
	while (true) {
		//system("cls");
		cout << "Введіть площу приміщень, котре буде виводитися: ";
		cin >> v;
		if (v > -1) break;
		cout << "\tНеправильно вказана площа!\n";
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
	if (count > 0)	cout << "Середня вартість обраних приміщень: " << cost / count << endl;
	else cout << "Приміщень за данними параметрами не було знайдено!" << endl;

	fclose(f);
}
void _zapyt()
{
	char menu[5][100] = {
		"Запит №1\n\t\tприміщення за обраним типом",
		"Запит №2\n\t\tприміщення за введеною загальною площею",
		"Запит №3\n\t\tзагальна кількість усіх приміщень, орендну вартість яких введено з клавіатури",
		"Запит №4\n\t\tвідсоткове співвідношення за типами",
		"Запит №5\n\t\tсередня вартість приміщення певного типу та певної площи"
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
		"Ввести назву файлу",
		"Перегляд існуючих приміщень",
		"Коректування існуючого приміщення",
		"Додавання приміщень",
		"Видалення приміщень",
		"Сортування приміщень",
		"Виконання запитів",
		"Завершення роботи" };


	

	int choise = 0, key = 0;
	do
	{
		for (int i = 0; i < 8; i++)
		{
			if (choise == i) cout << "-->\t";
			else cout << "\t";
			cout << menu[i] << endl;
		}

		if (FileName[0] == '\0')	cout << "\n\n\tФайл не вказаний\n";
		else cout << "\n\n\tВи працюєте із файлом: \t" << FileName << "\n\tКількість приміщень у файлі: " << FileSize << endl;


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

//шапка 1-начало, 0-конец
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
			cout << "№";
			sym(0, 1);

			sym(5);

			sym(0, 1);
			cout << "Адреса";
			sym(0, 12);

			sym(5);

			sym(0, 5);
			cout << "Тип";
			sym(0, 6);

			sym(5);

			sym(0, 3);
			cout << "Площа";
			sym(0, 3);

			sym(5);

			sym(0, 3);
			cout << "вартість";
			sym(0, 4);

			sym(5);

			sym(0, 2);
			cout << "ПІБ власника";
			sym(0, 2);

			sym(5);

			sym(0, 1);
			cout << "Номер телефону";
			sym(0, 1);

			sym(5);

			sym(0, 3);
			cout << "Повна";
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
			cout << "приміщення";
			sym(0, 2);

			sym(5);

			sym(0, 1);
			cout << "приміщення";
			//sym(0, 0);

			sym(5);

			sym(0, 1);
			cout << "оренди за м^2";
			sym(0, 1);

			sym(5);

			sym(0, 16);

			sym(5);

			sym(0, 16);

			sym(5);

			sym(0, 1);
			cout << "вартість";
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