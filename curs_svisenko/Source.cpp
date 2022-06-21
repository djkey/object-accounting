#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include <regex>
#include<windows.h>
#include<sstream>
#include <conio.h>
#include<vector>
#include<algorithm>
#include<stdio.h>


using namespace std;

inline void symb(int str, int count = 1)
{
	SetConsoleOutputCP(866);
	for (int i = 0; i < count; i++)
		cout << (char)str;
	SetConsoleOutputCP(1251);
}
int _menu(string menu[], int count)
{
	int choise = 1,
		key = 0;
	do
	{
		cout << menu[0] << endl << endl;
		for (int i = 1; i < count; i++)
		{
			if (choise == i) cout << "-->\t   ";
			else cout << "\t";
			cout << menu[i] << endl;
		}

		key = _getch();

		if (key == 224) key = _getch();
		if (key == 72 && choise > 1) choise--;
		if (key == 80 && choise < count - 1) choise++;
		if (key == 27) return count;
		if (key == 13)
		{
			system("cls");
			return choise;
		}
		system("cls");
	} while (true);
}

enum CLASS
{
	E = 400,
	M=1000,
	B=2000,
	S=3000
};
struct my_date
{

	int day;
	int mon;
	int year;
	bool high_year;
	void set()
	{
		string str, str1, str2, str3;
		regex reg("\\D*[0-9]{1,2}\\D+[0-9]{1,2}\\D+[0-9]{4}\\D*");
		while (true)
		{
			getline(cin, str);
			if (regex_match(str, reg))
			{
				str1 = regex_replace(str, regex("\\D*([0-9]{1,2})\\D+([0-9]{1,2})\\D+([0-9]{4})\\D*"), "$1");
				str2 = regex_replace(str, regex("\\D*([0-9]{1,2})\\D+([0-9]{1,2})\\D+([0-9]{4})\\D*"), "$2");
				str3 = regex_replace(str, regex("\\D*([0-9]{1,2})\\D+([0-9]{1,2})\\D+([0-9]{4})\\D*"), "$3");

				this->day = stoi(str1);
				this->mon = stoi(str2);
				this->year = stoi(str3);
				is_high_year();
				if (this->chek()) return;
			}
			else
			{
				cout << "\nДату у вашому виразі не знайдено!";
			}
		}
	};
	string get()
	{
		ostringstream oss;
		string d;
		if (this->day < 10) oss<< "0";
		oss<<this->day<<".";
		if (this->mon < 10) oss<< "0";
		oss << (this->mon) << ".";
		oss << this->year;
		return oss.str();

	}
	bool operator>(my_date date2)
	{
		if (this->year > date2.year)
		{
			return true;
		}
		if ((this->year == date2.year) && this->mon > date2.mon)
		{
			return true;
		}
		if (((this->year == date2.year) && this->mon == date2.mon) && this->day > date2.day)
		{
			return true;
		}
		return false;
	};
	bool operator<(my_date date2)
	{
		if (this->year < date2.year)
		{
			return true;
		}
		if ((this->year == date2.year) && this->mon < date2.mon)
		{
			return true;
		}
		if (((this->year == date2.year) && this->mon == date2.mon) && this->day < date2.day)
		{
			return true;
		}
		return false;
	};
	bool operator==(my_date date2)
	{
		if (this->year == date2.year &&
			this->mon == date2.mon &&
			this->day == date2.day)
			return true;
		return false;
	}
	int operator-(my_date date2)
	{
		int var=0;
		if (this->year == date2.year)
		{
			if (this->mon == date2.mon)
			{
				var = this->day - date2.day;
				return abs(var);
			}
			else
			{
				//год== месяц!=
				for (int i = 1; i < this->mon; i++)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) var += 31;
					if (i == 4 || i == 6 || i == 9 || i == 11) var += 30;
					if (i == 2) var += 28 + high_year;
				}
				var += this->day;
				for (int i = 1; i < date2.mon; i++)
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) var -= 31;
					if (i == 4 || i == 6 || i == 9 || i == 11) var -= 30;
					if (i == 2) var -= (28 + is_high_year(date2.year));
				}
				var -= date2.day;
				return abs(var);
			}
		}
		else
		{
			for (int i = 1900; i < this->year; i++)
			{
				var += 365 + is_high_year(i);
			}
			for (int i = 1; i < this->mon; i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) var += 31;
				if (i == 4 || i == 6 || i == 9 || i == 11) var += 30;
				if (i == 2) var += 28 + high_year;
			}
			var += this->day;
			for (int i = 1900; i < date2.year; i++)
			{
				var -= (365 + is_high_year(i));
			}
			for (int i = 1; i < date2.mon; i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) var -= 31;
				if (i == 4 || i == 6 || i == 9 || i == 11) var -= 30;
				if (i == 2) var -= (28 + is_high_year(date2.year));
			}
			var -= date2.day;

			return abs(var);
		}
	}
private:
	void is_high_year()
	{
		if ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0) this->high_year = true;
		else this->high_year = false;
	}
	bool is_high_year(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
		else return false;
	}
	bool chek()
	{
		int max_day = 28;
		if (this->year < 1900 || this->year>3000)
		{
			cout << "\nНеправильний рік!";
			return false;
		}
		if (this->mon < 1 || this->mon>12)
		{
			cout << "\nНеправильно вказан місяць. Він повинен бути в диапазоні 1-12";
			return false;
		}
		if (this->mon == 1 || this->mon == 3 || this->mon == 5 || this->mon == 7 || this->mon == 8 || this->mon == 10 || this->mon == 12) max_day = 31;
		if (this->mon == 4 || this->mon == 6 || this->mon == 9 || this->mon == 11) max_day = 30;
		if (this->mon == 2) max_day = 28 + high_year;

		if (this->day<0 || this->day>max_day)
		{
			cout << "\nНеправильно вказан день. Він повинен бути в диапазоні 1-" << max_day;
			return false;
		}
		return true;
	}
};
struct STR
{
	string PIB;
	CLASS clas;
	string marka;
	my_date date_start;
	my_date date_end;

	void chek_dates()
	{
		if (this->date_start > this->date_end)
			swap(this->date_start, this->date_end);
	}

	void set_PIB()
	{
		string var;
		regex reg(" *[А-ЯЙЁІЇ][а-яйёії]+ +[А-ЯЙЁІЇ][а-яйёії]* *\\.? *[А-ЯЙЁІЇ][а-яйёії]* *\\.? *");
		while (true)
		{
			cout << "\nВведіть ПІБ(Іванов І.І.): ";
			getline(cin, var);
			if (regex_match(var, reg))
			{

				var = regex_replace(var, std::regex(" *([А-ЯЁІЇ][а-яёії]+) +([А-ЯЁІЇ])[а-яёії]* *\\.? *([А-ЯЁІЇ])[а-яёії]* *\\.? *"), "$1 $2\.$3\.");
				this->PIB = var;
				return;
			}
			else
			{
				std::cout << "\nНеправильно вказаний ПІБ!";
			}
		}
	};
	void set_clas()
	{
		string menu[] = {
			"Виберіть класс авто",
			"E",
			"M",
			"B",
			"S"
		};

		switch (_menu(menu, 5))
		{
		case 1:
			this->clas = E;
			break;
		case 2:
			this->clas = M;
			break;
		case 3:
			this->clas = B;
			break;
		case 4:
			this->clas = S;
			break;
		}
	}
	void set_marka()
	{
		string var;
		regex reg(" *[A-Za-z]+ +[A-Za-z0-9]+ *");
		while (true)
		{
			cout << "\nВведіть марку та модель авто: ";
			getline(cin, var);
			if (regex_match(var, reg))
			{

				var = regex_replace(var, std::regex(" *([A-Za-z]+) +([A-Za-z0-9]+) *"), "$1 $2");
				this->marka = var;
				return;
			}
			else
			{
				std::cout << "\nМарку та модель авто  не знайдено!";
			}
		}
	};
	void set_dates()
	{
		cout << "Введіть дату початку періоду оренди: ";
		this->date_start.set();
		cout << "Введіть дату кінця періоду оренди: ";
		this->date_end.set();
		chek_dates();
	}

	string get_PIB()
	{
		return this->PIB;
	}
	string get_clas()
	{
		switch (clas)
		{
		case 400:
			return "E";
			break;
		case 1000:
			return "M";
			break;
		case 2000:
			return "B";
			break;
		case 3000:
			return "S";
			break;
		}
	}
	string get_marka()
	{
		return this->marka;
	}
	string get_date_start()
	{
		return this->date_start.get();
	}
	string get_date_end()
	{
		return this->date_end.get();
	}
	string get_day()
	{
		ostringstream oss;
		oss << (this->date_start - this->date_end);
		return oss.str();
	}
	string get_price()
	{
		ostringstream oss;
		oss << clas;
		return oss.str();
	}
	string get_vart()
	{
		ostringstream oss;
		oss << (this->clas * (this->date_start - this->date_end));
		return oss.str();
	}
} avto;
struct FieldSize {
	int PIB = 12;
	int clas = 6;
	int marka = 14;
	int date_start = 9;
	int date_end = 7;
	int day = 11;
	int price = 12;
	int vart= 10;
	void resize(vector<STR>& file)
	{
		this-> PIB = 12;
		this-> clas = 6;
		this-> marka = 14;
		this-> date_start = 9;
		this-> date_end = 7;
		this-> day = 11;
		this-> price = 12;
		this-> vart = 10;
		for (int i = 0; i < file.size(); i++)
		{
			
			if (this->PIB - 2 < file[i].get_PIB().size())
				this->PIB = file[i].get_PIB().size() + 2;
			
			if (this->clas - 2 < file[i].get_clas().size())
				this->clas = file[i].get_clas().size() + 2;

			if (this->marka - 2 < file[i].get_marka().size())
				this->marka = file[i].get_marka().size() + 2;

			if (this->date_start - 2 < file[i].get_date_start().size())
				this->date_start = file[i].get_date_start().size() + 2;

			if (this->date_end - 2 < file[i].get_date_end().size())
				this->date_end = file[i].get_date_end().size() + 2;

			if (this->day - 2 < file[i].get_day().size())
				this->day = file[i].get_day().size() + 2;

			if (this->price - 2 < file[i].get_price().size())
				this->price = file[i].get_price().size() + 2;

			if (this->vart - 2 < file[i].get_vart().size())
				this->vart = file[i].get_vart().size() + 2;


		}
	};

} table_config;

void table(bool x,vector<STR>&file)
{
	table_config.resize(file);
	int size[] = { 3,
			table_config.PIB,
			table_config.clas,
			table_config.marka,
			table_config.date_start,
			table_config.date_end,
			table_config.day,
			table_config.price,
			table_config.vart
	};
	if (x)
	{
		{
			//первая линия
			{
				symb(201);
				for (int i = 0; i < 9; i++)
				{
					symb(205, size[i]);
					if (i != 8) symb(203);
				}
				symb(187);
			}

			cout << endl;

			string name[] = { "№",
				"ПІБ",
				"Клас",
				"Марка/Модель",
				"Дата",
				"Дата",
				"Кількість",
				"Вартість",
				"Вартість" };
			//вторая линия
			{
				symb(186);
				for (int i = 0; i < 9; i++)
				{
					symb(32, (size[i] - name[i].size()) / 2);
					cout << name[i];
					symb(32, (size[i] - name[i].size()) / 2 + (size[i] - name[i].size()) % 2);

					symb(186);
				}
			}

			cout << endl;

			string name2[] = { "",
				"орендатора",
				"авто",
				"авто",
				"початку",
				"кінця",
				"днів",
				"одного дня",
				"оренди" };
			//третья линия
			{
				symb(186);
				for (int i = 0; i < 9; i++)
				{
					symb(32, (size[i] - name2[i].size()) / 2);
					cout << name2[i];
					symb(32, (size[i] - name2[i].size()) / 2 + (size[i] - name2[i].size()) % 2);

					symb(186);
				}
			}

			cout << endl;

			//четвёртая линия
			{

				symb(204);

				for (int i = 0; i < 9; i++)
				{
					symb(205, size[i]);
					if (i != 8) symb(206);
				}
				symb(185);
			}

			cout << endl;
		}
	}
	else
	{
		symb(200);

		for (int i = 0; i < 9; i++)
		{
			symb(205, size[i]);
			if (i != 8) symb(202);
		}
		symb(188);
		cout << endl;
	}
}

void show(vector<STR>& file)
{
	if (file.empty())
	{
		cout << "Пустий файл!";
		return;
	}
	
	table(1, file);

	table_config.resize(file);
	int size[] = { 3,
			table_config.PIB,
			table_config.clas,
			table_config.marka,
			table_config.date_start,
			table_config.date_end,
			table_config.day,
			table_config.price,
			table_config.vart
	};

	for (int i = 0; i < file.size(); i++)
	{
		string name[] = { to_string(i + 1),
						file[i].get_PIB(),
						file[i].get_clas(),
						file[i].get_marka(),
						file[i].get_date_start(),
						file[i].get_date_end(),
						file[i].get_day(),
						file[i].get_price(),
						file[i].get_vart()
		};

		symb(186);
		for (int i = 0; i < 9; i++)
		{
			symb(32);
			cout << name[i];
			symb(32, (size[i] - name[i].size()) - 1);

			symb(186);
		}
		cout << endl;
	}


	table(0, file);
}
void add(vector<STR>& file)
{
	avto.set_PIB();
	system("cls");
	avto.set_clas();
	system("cls");
	avto.set_marka();
	system("cls");
	avto.set_dates();
	system("cls");
	file.push_back(avto);
}
void corr(vector<STR>& file)
{
	string* mmenu = new string[file.size() + 1];
	mmenu[0] = "\nЯку запис ви хочите скорегувати";
	for (int i = 0; i < file.size(); i++)
	{
		mmenu[i + 1] = to_string(i + 1) + ": " + file[i].get_PIB();
	}

	int count = _menu(mmenu, file.size() + 1) - 1;

	string smenu[] = { "\nЩо потрібно скорегувати?",
					"ПІБ: " + file[count].get_PIB(),
					"Клас авто: " + file[count].get_clas(),
					"Марку та модель автомобілю: " + file[count].get_marka(),
					"Дата початку періоду оренди: " + file[count].get_date_start(),
					"Дата кінця періоду оренди: " + file[count].get_date_end(),
					"Змінити усі поля"
	};

	switch (_menu(smenu,7))
	{
	case 1:
		file[count].set_PIB();
		break;
	case 2:
		file[count].set_clas();
		break;
	case 3:
		file[count].set_marka();
		break;
	case 4:
		cout << "\nВведіть дату: ";
		file[count].date_start.set();
		file[count].chek_dates();
		break;
	case 5:
		cout << "\nВведіть дату: ";
		file[count].date_end.set();
		file[count].chek_dates();
		break;
	case 6:
		file[count].set_PIB();
		file[count].set_clas();
		file[count].set_marka();
		file[count].set_dates();
		break;
	}

}
void del(vector<STR>& file)
{
	string del_menu[] = { "\nЗа яким ознаком видалити запис:",
						"за номером у списку",
						"за назвою марки та моделі автомобіля" };
	int count = _menu(del_menu, 3) - 1;
	if (!count)
	{
		int index;
		do {
			cout << "Введіть номер: ";
			cin >> index;
			if (index < 1 || index > file.size()) cout << "Помилка\n\n";
		} while (index < 1 || index > file.size());
		index--;
		file.erase(file.begin() + index);
	}
	else
	{
		string s;
		vector <int> index;
		cout << "Введіть марку чи модель авто: ";
		cin >> s;
		for (int i = 0; i < file.size(); i++)
		{
			if (file[i].get_marka().find(s) != file[i].get_marka().npos)
				index.push_back(i);
		}
		for (int i = index.size()-1; i >= 0; i--)
		{
			file.erase(file.begin() + index[i]);
		}
	}
}

bool compare_PIB_UP(STR a, STR b)
{
	if (strcmp(a.get_PIB().c_str(), b.get_PIB().c_str()) > 0) return true;
	return false;
}
bool compare_PIB_DOWN(STR a, STR b)
{
	if (strcmp(a.get_PIB().c_str(), b.get_PIB().c_str()) < 0) return true;
	return false;
}
bool compare_vart_UP(STR a, STR b)
{
	return (stoi(a.get_vart()) > stoi(b.get_vart()));
}
bool compare_vart_DOWN(STR a, STR b)
{
	return (stoi(a.get_vart()) < stoi(b.get_vart()));
}
void sort(vector<STR> &file)
{
	string menu[] = { "\nЗа яким ознаком сортувати?",
	"ПІБ",
	"вартістю оренди за весь період" };
	string smenu[3] = { "","за зростанню","по спаданню" };
	int count = _menu(menu, 3)-1;
	if (!count)
	{
		smenu[0] = "ПІБ";
		int typ = _menu(smenu, 3);
		if(typ==1)
			sort(file.begin(), file.end(), compare_PIB_DOWN);
		else
			sort(file.begin(), file.end(), compare_PIB_UP);

	}
	else
	{
		smenu[0] = "вартість оренди";
		int typ = _menu(smenu, 3);
		if (typ == 1)
			sort(file.begin(), file.end(), compare_vart_DOWN);
		else
			sort(file.begin(), file.end(), compare_vart_UP);

	}
}

void skip(vector<STR>& file)
{
	return;
}

void zap1(vector<STR>& file)
{//Виведення всіх замовлень орендатора, ПІБ якого введено з клавіатури

	bool empty = true;

	avto.set_PIB();


	int size[] = { 3,
			table_config.PIB,
			table_config.clas,
			table_config.marka,
			table_config.date_start,
			table_config.date_end,
			table_config.day,
			table_config.price,
			table_config.vart
	};

	for (int i = 0; i < file.size(); i++)
	{
		if (file[i].get_PIB() == avto.get_PIB())
		{
			empty = false;
			break;
		}
	}
	if (!empty)
	{
		table(1, file);

		for (int i = 0; i < file.size(); i++)
		{
			if (file[i].get_PIB() == avto.get_PIB())
			{
				string name[] = { to_string(i + 1),
							file[i].get_PIB(),
							file[i].get_clas(),
							file[i].get_marka(),
							file[i].get_date_start(),
							file[i].get_date_end(),
							file[i].get_day(),
							file[i].get_price(),
							file[i].get_vart()
				};

				symb(186);
				for (int i = 0; i < 9; i++)
				{
					symb(32);
					cout << name[i];
					symb(32, (size[i] - name[i].size()) - 1);

					symb(186);
				}
				cout << endl;
			}
		}
		table(0, file);
	}

}
void zap2(vector<STR>& file)
{//Загальна кількість днів оренди обраного класу автомобілів
	avto.set_clas();
	int size = 0;
	for (int i = 0; i < file.size(); i++)
	{
		if (file[i].get_clas() == avto.get_clas())
			size += stoi(file[i].get_day());
	}
	cout << avto.get_clas() << ": " << size << endl;
}
void zap3(vector<STR>& file)
{//Середня вартість всього періоду оренди автомобілів кожного класу
	string mas[4] = { "E","M","B","S" };

	int count[4] = { 0,0,0,0 };
	int vart[4] = { 0,0,0,0 };

	for (int i = 0; i < file.size(); i++)
	{
		for (int j = 0; j < 4; j++)
			if (file[i].get_clas() == mas[j])
			{
				vart[j] += stoi(file[i].get_vart());
				count[j]++;
			}
	}

	for (int i = 0; i < 4; i++)
	{
		if (count[i] != 0)
			cout << mas[i] << ": " << (vart[i] / count[i]);
		else
			cout << mas[i] << ": " << "автомобілів цього класу не знайдено";
		cout << endl;
	}

}
void zap4(vector<STR>& file)
{//Підрахування кількості автомобілів кожного класу та визначення найпопулярнішого класу
	string mas[4] = { "E","M","B","S" };

	int count[4] = { 0,0,0,0 };

	for (int i = 0; i < file.size(); i++)
	{
		for(int j=0;j<4;j++)
			if (file[i].get_clas() == mas[j])
				count[j]++;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << mas[i] << ": " << count[i] << endl;
	}


}
void zap5(vector<STR>& file)
{//Визначення найприбутковішого замовлення
	int max = stoi(file[0].get_vart()), 
		index = 0;
	for (int i = 1; i < file.size(); i++)
	{
		if (max < stoi(file[i].get_vart()))
		{
			max = stoi(file[i].get_vart());
			index = i;
		}
	}
	cout << "Найприбуткове замовлення\n"
		<< "№: " << index+1 << endl
		<< "ПІБ орендодатора: " << file[index].get_PIB() << endl
		<< "Клас авто: " << file[index].get_clas() << endl
		<< "Марка та модель авто: " << file[index].get_marka() << endl
		<< "Дата початку періоду оренди: " << file[index].get_date_start() << endl
		<< "Дата кінця періоду оренди: " << file[index].get_date_end() << endl
		<< "Кількість днів оренди: " << file[index].get_day() << endl
		<< "Вартість одного дня оренди: " << file[index].get_price() << endl
		<< "Вартість оренди за весь період: " << file[index].get_vart() << endl;

}
void (*zap[6])(vector<STR>& file)
{
	zap1,
	zap2,
	zap3,
	zap4,
	zap5,
	skip
};
void zapyt(vector<STR>& file)
{
	string menu[] = { "Виберіть запит:",
		"Виведення всіх замовлень орендатора, ПІБ якого введено з клавіатури",
		"Загальна кількість днів оренди обраного класу автомобілів",
		"Середня вартість всього періоду оренди автомобілів кожного класу",
		"Підрахування кількості автомобілів кожного класу та визначення найпопулярнішого класу",
		"Визначення найприбутковішого замовлення"
	};

	zap[_menu(menu, 6)-1](file);
}
void (*start[7])(vector<STR>& file)
{
	show,
	add,
	corr,
	del,
	sort,
	zapyt,
	skip
};

void read_file(vector<STR>& file)
{
	FILE* f = fopen("bin", "rb");
	if (f)
	{
		for (int i = 0; !feof(f); i++)
		{
			fread(&avto, sizeof(STR), 1, f);
			file.push_back(avto);
		}
		file.pop_back();
	}
	else
	{
		f = fopen("bin", "wb");
	}
	fclose(f);
}
void safe_file(vector<STR>& file)
{
	FILE* f = fopen("bin", "wb");
	for (int i = 0; i < file.size(); i++)
	{
		avto = file[i];
		fwrite(&avto, sizeof(STR), 1, f);
	}

	fclose(f);
}

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<STR> file;

	read_file(file);
	string menu[] = { "\nВиберіть операцію:",
	"Перегляд існуючого файлу",
	"Додавання оренди",
	"Редагування записів",
	"Видалення записів",
	"Сорування інформації",
	"Виконання запитів",
	"Вихід із програми"};
	while (true)
	{
		system("cls");
		int count=_menu(menu, 8);
		if (count == 7)	break;
		else
		{
			start[count - 1](file);
			system("pause");
		}
	}


	safe_file(file);
	file.clear();
	return;
}