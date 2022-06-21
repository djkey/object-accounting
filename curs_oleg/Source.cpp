// ����� ��� ���������� ������ C �������� ������� 
#define _CRT_SECURE_NO_WARNINGS
//cin cout
#include<iostream>
// ����� lkz _getch()
#include<windows.h>
//� ��� �������
#include<string>
//��� ��� ���������� ��������� ������� ������������ ��� �������� ��������
#include<regex>
//��� �� ����� ��� ���� ������
#include <conio.h>
//��� ���������� �������
#include<algorithm>
//������
#include<vector>


using namespace std;

// ����� ��� ������ �������� �������; ��������� ����� ������� � �� ������� ��� ��� �������
inline void OutputASCII(int str,int count=1)
{
	SetConsoleOutputCP(866);
	for(int i=0;i<count;i++)
		cout << (char)str;
	SetConsoleOutputCP(1251);
}

// ������� � �������� ������; ��������� ������ ����� � ������� [0] ��� ���������, � ��������� ��� ������ ������ � ����� ������������ ������ �������
// ������� ���������� ����� ������ ������ �� 1 �� count-1
int menu(string menu[], int count)
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

		cout <<"\n\n\n\n\t\t";
		OutputASCII(24);
		OutputASCII(25);
		cout << ": ��������� ����";
		cout << "\n\t\tEnter: ������ �����";
		cout << "\n\t\tEsc: �������� ���� ����";

		key = _getch();

		if (key == 224) key = _getch();
		if (key == 72 && choise > 1) choise--;
		if (key == 80 && choise < count-1) choise++;
		if (key == 27) return -1;
		if (key == 13)
		{
			system("cls");
			return choise;
		}
		system("cls");
	} while (true);
}


//��������� � ������� �������� ���� � � �������
// ��� ����������� ������ � ��������� ��������� � ? � ��������
struct MyDate
{
	//����� � ������� �������� ����
	int year;
	int month;
	int day;
	//��������������� ������ � ����������������� ����� ��� ������ � �������
	string date;

	//������� ����� ����
	/*
	  \\D - ����� ����� ����� �����
	  [0-9] - ����� ������ �� ��������� [0-9] 
	  {1,2} - ���������� ���������� ����������� ����� �� 1 �� 2
	  + - ���������� ���������� �� 1 � ������
	  * - ���������� ���������� �� 0 � ������
	*/

	/*
	regex_match - ���� ������ ��������� � ���������� ���������� �� TRUE, ���� ��� �� FALSE
	regex_replace - ������ � ������ ��������� ���������� ��������� () - ��������� �������� �����, $n - �������� ������� � ������ ������ n ����
	*/
	void set()
	{
		string str, str1, str2, str3;
		regex reg("\\D*[0-9]{1,2}\\D+[0-9]{1,2}\\D+[0-9]{4}\\D*");
		while (true)
		{
			cout << "\n������ ����(���� ����� ��): ";
			getline(cin, str);
			if (regex_match(str, reg))
			{
				str1 = regex_replace(str, regex("\\D*([0-9]{1,2})\\D*([0-9]{1,2})\\D*([0-9]{4})\\D*"), "$1");

				str2 = regex_replace(str, regex("\\D*([0-9]{1,2})\\D*([0-9]{1,2})\\D*([0-9]{4})\\D*"), "$2");
				str2 = regex_replace(str2, regex("([0]{0,1})([0-9]{1,2})"), "$2");

				str3 = regex_replace(str, regex("\\D*([0-9]{1,2})\\D*([0-9]{1,2})\\D*([0-9]{4})\\D*"), "$3");

				str = regex_replace(str, regex("\\D*([0-9]{1,2})\\D*([0-9]{1,2})\\D*([0-9]{4})\\D*"), "$1.$2.$3");
				if (regex_match(str, regex("([0-9])\\.([0-9]{1,2})\\.([0-9]{4})")))
				{
					str.insert(0, " ");
				}
				if (regex_match(str, regex("(.[0-9])\\.([0-9])\\.([0-9]{4})")))
				{
					str.insert(3, "0");
				}
				

				this->day = stoi(str1);
				this->month = stoi(str2);
				this->year = stoi(str3);
				if (this->chek())
				{
					this->date = str;
					return;
				}
			}
			else
			{
				cout << "\n���� � ������ ����� �� ��������!";
			}
		}
	};
	// �������� ����������  </==
	/*
		��� �������:
			MyDate t1,t2;
			if(t1==t2) - t1 ���������� ����������� this->
						 t2 ���������� date2
	*/
	bool operator<(MyDate date2)
	{
		if (this->year < date2.year)
		{
			return true;
		}
		if ((this->year == date2.year) && this->month < date2.month)
		{
			return true;
		}
		if (((this->year == date2.year) && this->month == date2.month) && this->day < date2.day)
		{
			return true;
		}
		return false;
	};
	bool operator==(MyDate date2)
	{
		if (this->year == date2.year && 
			this->month == date2.month && 
			this->day == date2.day) 
				return true;
		return false;
	}
private :
	//��������� ������� ��� �������� ������������� ����
	// ��������� �������� ��� � ����� ������� ������ �� MyDate
	bool chek()
	{
		int max_day = 28;
		if (year < 1900||year>3000)
		{
			cout << "\n������������ ��!";
			return false;
		}
		if (month < 1 || month>12)
		{
			cout << "\n����������� ������ �����. ³� ������� ���� � �������� 1-12";
			return false;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) max_day = 31;
		if (month == 4 || month == 6 || month == 9 || month == 11) max_day = 30;
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) max_day = 29;
		if (month == 2 && !((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) max_day = 28;

		if (day<0 || day>max_day)
		{
			cout << "\n����������� ������ ����. ³� ������� ���� � �������� 1-" << max_day;
			return false;
		}
		return true;
	}
};
//�������� ���������
struct MyStruct
{
	string bong_name;
	string material;
	string color;
	double price;
	int count;
	MyDate date;
	string PIB;
	double cost;
	//������� ����� ���� ������� ����� ���������
	void set_bong_name()
	{
		string var;
		regex reg("[^�-ߨ���-����]*[�-ߨ���-����]+[^�-ߨ���-����]*");
		while (true)
		{
			cout << "\n������ ����� �����: ";
			getline(cin, var);
			if (regex_match(var, reg))
			{
				var = regex_replace(var, std::regex("[^�-ߨ���-����]*([�-ߨ���-����]+)[^�-ߨ���-����]*"), "$1");
				

				this->bong_name = var;
				return;
			}
			else 
			{
				cout << "\n����������� ����� ��� �����";
			}
		}
	};
	void set_material()
	{
		string mater[6] = { "������ �������: ",
			"����",
			"�����",
			"�������",
			"�����",
			"��������" };
		this->material = mater[menu(mater, 6)];
	};
	void set_color()
	{
		string col[7] = { "������ ����: ",
			"��������",
			"�������",
			"��������",
			"����",
			"������",
			"������" };
		this->color = col[menu(col, 7)];
	};
	void set_price()
	{
		string val;
		while (true)
		{
			cout << "\n������ ����: ";
			getline(cin, val);
			if (regex_match(val, ::regex("[1-9][0-9]*(\\.[0-9]+)?")))
			{
				this->price = stod(val);
				return;
			}
			else cout << "\n����������� ����";
		}
	};
	void set_count()
	{
		string val;
		while (true)
		{
			cout << "\n������ �������: ";
			getline(cin, val);
			if(regex_match(val,::regex("[1-9][0-9]*")))
			{
				this->count = stoi(val);
				return;
			}
			else
			{
				cout << "\n����������� �������";
			}
		}
	};
	void set_PIB()
	{
		string var;
		regex reg(" *[�-�ɨ��][�-�鸳�]+ +[�-�ɨ��][�-�鸳�]* *\\.? *[�-�ɨ��][�-�鸳�]* *\\.? *");
		while (true)
		{
			cout << "\n������ ϲ�(������ �.�.): ";
			getline(cin, var);
			if (regex_match(var, reg))
			{

				var = regex_replace(var, std::regex(" *([�-ߨ��][�-����]+) +([�-ߨ��])[�-����]* *\\.? *([�-ߨ])[�-����]* *\\.? *"), "$1 $2\.$3\.");
				this->PIB = var;
				return;
			}
			else
			{
				std::cout << "\n����������� �������� ϲ�!";
			}
		}
	};
	void set_cost()
	{
		this->cost = this->price * this->count;
	};
} bong;

	
// ��� ������ � ������
FILE* f;
char filename[] = { "bong.byte" };
int filesize = 1;

//������� ������ ��������� ���������� �������� � �����, � ���� ��� ��� �� ������� ����� ������ ����
void _file_size()
{
	filesize = 0;
	f = fopen(filename, "rb");
	if (f == NULL)
	{
		f = fopen(filename, "wb");
		fclose(f);
		return;
	}
	while (!feof(f))
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		filesize++;
	}
	// �������� ���������� ��-�� ���� ��� feof- �������� ������ �� ������� ����� � ������������� ������ ����� ��� ����� �� �������
	filesize--;
	fclose(f);

}


//������� ���� � �����
int leng(int a)
{
	int l = 0;
	while (a)
	{
		a /= 10;
		l++;
	}
	
	return l;
}
//���� ����� ������ ��� �������� ����� 
//������� ���������� ���� ����� ����� + 3 (�� ����� � �� 2 ����� ����� �����)
int leng(double a)
{
	int num = int(a*100);
	int l = 0;
	bool var = false;
	while (num)
	{
		num /= 10;
		l++;
		var = true;
	}
	if (var)
	{
		l++;
	}
	return l;
}

// ����� � ��������� ���� ����� ������� � ������ ����� ����������� � ���� ���������
struct FieldSize {
	//������� ����� �� ������� (����� �������� ����� ����������� � �������)
	int bong_name=6;
	int material=10;
	int color=7;
	int price=6;
	int count=11;
	int date=6;
	int PIB=5;
	int cost=10;
	//������� ��� ��������������� ������� �����, ���������� �� ����� �����
	void resize()
	{
		this-> bong_name = 6;
		this-> material = 10;
		this-> color = 7;
		this-> price = 6;
		this-> count = 11;
		this-> date = 6;
		this-> PIB = 5;
		this-> cost = 10;
		f = fopen(filename, "rb");
		for (int i = 0; i < filesize; i++)
		{
			fread(&bong, sizeof(MyStruct), 1, f);
			//bong_name
			if (this->bong_name-2 < bong.bong_name.size()) 
				this->bong_name = bong.bong_name.size() + 2;
			//material
			if (this->material-2 < bong.material.size()) 
				this->material = bong.material.size() + 2;
			//color
			if (this->color-2 < bong.color.size()) 
				this->color = bong.color.size() + 2;
			//price
			if (this->price-2 < leng(bong.price)) 
				this->price = leng(bong.price) + 2;
			//count
			if (this->count-2 < leng(bong.count)) 
				this->count = leng(bong.count) + 2;
			//date
			if (this->date-2 < bong.date.date.size()) 
				this->date = bong.date.date.size() + 2;
			//PIB
			if (this->PIB-2 < bong.PIB.size()) 
				this->PIB = bong.PIB.size() + 2;

			//cost
			if (this->cost-2 < leng(bong.cost))
				this->cost = leng(bong.cost) + 2;


		}
		fclose(f);
	};

} fieldsize;

// ����� ����� � ������� �������
void table(bool x)
{
	int symb[] = { 3,
			fieldsize.bong_name,
			fieldsize.material,
			fieldsize.color,
			fieldsize.price,
			fieldsize.count,
			fieldsize.date,
			fieldsize.PIB,
			fieldsize.cost };
	if (x)
	{
		fieldsize.resize();
		{
			string name[] = { "�",
				"����",
				"�������",
				"����",
				"ֳ��",
				"ʳ������",
				"����",
				"ϲ�",
				"�������" };
			//������ �����
			{
				OutputASCII(201);
				for (int i = 0; i < 9; i++)
				{
					OutputASCII(205, symb[i]);
					if (i != 8) OutputASCII(203);
				}
				OutputASCII(187);
			}

			cout << endl;
			//������ �����
			{
				OutputASCII(186);
				for (int i = 0; i < 9; i++)
				{
					OutputASCII(32, (symb[i] - name[i].size()) / 2);
					cout << name[i];
					OutputASCII(32, (symb[i] - name[i].size()) / 2 + (symb[i] - name[i].size()) % 2);

					OutputASCII(186);
				}
			}

			cout << endl;

			//������ �����
			{

				OutputASCII(204);

				for (int i = 0; i < 9; i++)
				{
					OutputASCII(205, symb[i]);
					if (i != 8) OutputASCII(206);
				}
				OutputASCII(185);
			}

			cout << endl;
		}
	}
	else
	{
		OutputASCII(200);

		for (int i = 0; i < 9; i++)
		{
			OutputASCII(205, symb[i]);
			if (i != 8) OutputASCII(202);
		}
		OutputASCII(188);
		cout << endl;
	}
}

// ����� ���� �������
void Show()
{
	
	_file_size();
	
	if (filesize < 1)
	{
		cout << "\n������ ����\n";
		system("pause");
		return;
	}

	fieldsize.resize();

	int symb[] = { 3,
		fieldsize.bong_name,
		fieldsize.material,
		fieldsize.color,
		fieldsize.price,
		fieldsize.count,
		fieldsize.date,
		fieldsize.PIB,
		fieldsize.cost };
	
	//�����
	table(true);
	
	f = fopen(filename, "rb");
	rewind(f);

	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		string name[] = { to_string(i+1),
						bong.bong_name,
						bong.material,
						bong.color,
						to_string(int(bong.price * 100)).insert(to_string(int(bong.price * 100)).size() - 2,"."),
						to_string(bong.count),
						bong.date.date,
						bong.PIB,
						to_string(int(bong.cost * 100)).insert(to_string(int(bong.cost * 100)).size() - 2,".") };

		OutputASCII(186);
		for (int i = 0; i < 9; i++)
		{
			OutputASCII(32);
			cout << name[i];
			OutputASCII(32, (symb[i] - name[i].size()) - 1);

			OutputASCII(186);
		}
			cout << endl;
	}

	//������
	table(false);

	system("pause");

	fclose(f);

	
}

//������������� ������
void editOrder()
{
	_file_size();
	string* mmenu = new string[filesize + 1];
	f = fopen(filename, "r+b");

	mmenu[0] = "\n��� ����� �� ������ �����������";
	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);

		mmenu[i+1] = to_string(i+1) + ": " + bong.bong_name;
	}
	int count=menu(mmenu, filesize+1);

	if (count == -1)
	{
		fclose(f);
		return;
	}

	rewind(f);
	for (int i = 0; i < count; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
	}
	fseek(f, -1 * sizeof(MyStruct), SEEK_CUR);

	string smenu[] = { "\n�� ������� �����������?",
					"����� �����: " + bong.bong_name,
					"�������: " + bong.material,
					"����: " + bong.color,
					"ֳ��: " + to_string(int(bong.price * 100)).insert(to_string(int(bong.price * 100)).size() - 2,"."),
					"ʳ������: " + to_string(bong.count),
					"����: " + bong.date.date,
					"ϲ�: " + bong.PIB };


	switch (menu(smenu,8))
	{
	case 1:
		bong.set_bong_name();
		break;
	case 2:
		bong.set_material();
		break;
	case 3:
		bong.set_color();
		break;
	case 4:
		bong.set_price();
		bong.set_cost();
		break;
	case 5:
		bong.set_count();
		bong.set_cost();
		break;
	case 6:
		bong.date.set();
		break;
	case 7:
		bong.set_PIB();
		break;
	}
	fwrite(&bong, sizeof(MyStruct), 1, f);
	fclose(f);

}
//���������� ����� ������
void addOrder()
{
	_file_size();
	bong.set_bong_name();
	bong.set_material();
	bong.set_color();
	bong.set_price();
	bong.set_count();
	bong.date.set();
	bong.set_PIB();
	bong.set_cost();
	f = fopen(filename, "ab");
	fwrite(&bong, sizeof(MyStruct), 1, f);
	fclose(f);
	_file_size();
}
//��������
void del()
{
	_file_size();
	int count=-1;
	string delmenu[] = { "\n�� ���� ������� �������� �����:",
						"�� ������� � ������",
						"�� ������ �����" };

	f = fopen(filename, "r+b");

	count = menu(delmenu, 3);

	if (count == -1) return;
	if (count == 1)
	{
		count = -1;
		while (count<1 || count>filesize)
		{
			cout << "������ ����� ������: ";
			cin >> count;
			if (count<1 || count>filesize) cout << "������ �� ����� ������� �� ����!\n\n";
		}
	}
	else
	{
		string* nmenu = new string[filesize + 1];

		nmenu[0] = "\n��� ����� �� ������ ��������";
		for (int i = 0; i < filesize; i++)
		{
			fread(&bong, sizeof(MyStruct), 1, f);
			nmenu[i + 1] = bong.bong_name;
		}

		count = menu(nmenu, filesize + 1);
	}
	fclose(f);
	if (count == -1) return;


	FILE* var = fopen("var", "wb");
	f = fopen(filename, "rb");

	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		if (i != count-1)
		{
			fwrite(&bong, sizeof(MyStruct), 1, var);
		}
	}

	fclose(f);
	fclose(var);

	var = fopen("var", "rb");
	f = fopen(filename, "wb");

	for (int i = 0; i < filesize - 1; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, var);

		fwrite(&bong, sizeof(MyStruct), 1, f);
	}

	fclose(f);
	fclose(var);
	remove("var");
	_file_size();

};

//����� ��� ���������� ������� � ������� sort()
bool compare_date(MyStruct a, MyStruct b) {
	
		return (a.date < b.date);
}
bool compare_cost(MyStruct a, MyStruct b) {

		return(a.cost < b.cost);

}

//����������
void sort()
{
	_file_size();
	string mmenu[] = { "\n�� ���� ������� ���������?",
					"�� ������� ��������",
					"�� ����� ���������" };
	int count=menu(mmenu, 3);
	if (count == -1) return;
	f = fopen(filename, "rb");

	vector <MyStruct> var;
	int i = 0;
	for (i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		var.push_back(bong);
	}
	fclose(f);

	if(count==1)
		sort(var.begin(), var.end(),compare_cost);
	if(count==2)
		sort(var.begin(), var.end(), compare_date);

	f = fopen(filename, "wb");
	for (i = 0; i < filesize; i++)
	{
		fwrite(&var[i],sizeof(MyStruct),1,f);
	}
	fclose(f);
};

//�������
void zapyt1()
{
	_file_size();
	fieldsize.resize();
	int symb[] = { 3,
		fieldsize.bong_name,
		fieldsize.material,
		fieldsize.color,
		fieldsize.price,
		fieldsize.count,
		fieldsize.date,
		fieldsize.PIB,
		fieldsize.cost };
	//�������� ���� �������� ����i� � ������ ����
	MyDate var;
	var.set();


	cout << endl;
	vector <MyStruct> zapr;
	f = fopen(filename, "rb");
	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		if (bong.date == var) zapr.push_back(bong);
	}
	fclose(f);

	if (zapr.empty())
	{
		cout << "������ � ����� ����� �� ��������!\n";
		system("pause");
		return;
	}
	else
	{
		table(true);
		for (int i = 0; i < zapr.size(); i++)
		{					
			string name[] = { to_string(i + 1),
				zapr[i].bong_name,
				zapr[i].material,
				zapr[i].color,
				to_string(int(zapr[i].price * 100)).insert(to_string(int(zapr[i].price * 100)).size() - 2,"."),
				to_string(zapr[i].count),
				zapr[i].date.date,
				zapr[i].PIB,
				to_string(int(zapr[i].cost * 100)).insert(to_string(int(zapr[i].cost * 100)).size() - 2,".") };

			OutputASCII(186);

			for (int i = 0; i < 9; i++)
			{
				OutputASCII(32);
				cout << name[i];
				OutputASCII(32, (symb[i] - name[i].size()) - 1);

				OutputASCII(186);
			}
			cout << endl;
			
		}
		table(false);
	}
	
	
	cout << endl;
	system("pause");
}
void zapyt2()
{
	//������ ��������, � ���� ��������� �������� ������� �����
	_file_size();
	string mater[5] = { 
					"����",
					"�����",
					"�������",
					"�����",
					"��������" };

	int count[5] = { 0,0,0,0,0 };

	f = fopen(filename, "rb");
	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		for (int j = 0; j < 5; j++)
		{
			if (bong.material == mater[j])
				count[j] += bong.count;
		}

	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if (count[i] < count[j])
			{
				swap(mater[i], mater[j]);
				swap(count[i], count[j]);
			}
		}
	}

	cout << endl;
	for(int i=0;i<5;i++)
		cout << "     " << mater[i] << ":\t" << count[i] << endl;
	cout << endl << endl;


	system("pause");
	system("cls");
}
void zapyt3()
{
	_file_size();
	//������� ���������� ����  ��������
	string col[6] = { 
					"��������",
					"�������",
					"��������",
					"����",
					"������",
					"������" };

	int zapr[6] = { 0,0,0,0,0,0 };
	int count[6] = { 0,0,0,0,0,0 };
	string min_color[2];
	int min_zap, min_count;

	f = fopen(filename, "rb");

	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		for (int j = 0; j < 6; j++)
		{
			if (bong.color == col[j])
			{
				zapr[j]++;
				count[j] += bong.count;
			}
		}
	}
	min_color[0] = col[0];
	min_color[1] = col[0];
	min_zap = zapr[0];
	min_count = count[0];
	for (int i = 1; i < 6; i++)
	{
		if (min_zap >= zapr[i])
		{
			min_zap = zapr[i];
			min_color[0] = col[i];
		}
		if (min_count >= count[i])
		{
			min_count = count[i];
			min_color[1] = col[i];

		}
	}

	//out
	cout << "\n������� ���������� ���� �� ���������� ��������:\n\t" << min_color[0] << ": " << min_zap << " �����"
		<< "\n\n������� ���������� ���� �� ������� � �������:\n\t" << min_color[1] << ": " << min_count<< " �����"
		<< endl << endl;


	system("pause");
	system("cls");
}
void zapyt4()
{
	//��������� ������������  ��� ������������ �������� (�� �i������ ��������)
	_file_size();
	string mater[5] = {
					"����",
					"�����",
					"�������",
					"�����",
					"��������" };

	int count[5] = { 0,0,0,0,0 };

	f = fopen(filename, "rb");
	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);
		for (int j = 0; j < 5; j++)
		{
			if (bong.material == mater[j])
			{
				count[j]++;
			}
		}
	}
	
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "\t" << mater[i] << ": " << ((100. * count[i]) / filesize) << "%" << endl;
	}

	cout << endl << endl;

	system("pause");

}
void zapyt5()
{
	_file_size();
	//�������������i ����������i ����� �� ��������
	vector<string> people;
	vector<double> sum;
	vector<string>::iterator it;

	f = fopen(filename, "rb");

	for (int i = 0; i < filesize; i++)
	{
		fread(&bong, sizeof(MyStruct), 1, f);

		it = find(people.begin(), people.end(), bong.PIB);
		if (it != people.end())
		{
			sum[distance(people.begin(), it)] += bong.cost;
		}
		else
		{
			people.push_back(bong.PIB);
			sum.push_back(bong.cost);
		}
		
	}

	for (int i = 0; i < people.size(); i++)
	{
		for (int j = i; j < people.size(); j++)
		{
			if (sum[i] < sum[j])
			{
				swap(people[i], people[j]);
				swap(sum[i], sum[j]);
			}
		}
	}

	cout << endl;
	for (int i = 0; i < people.size() && i < 3; i++)
	{
		cout << "\t�" << i + 1 << "\t" << people[i] << ":\t" << sum[i] <<" ���" << endl;
	}
	cout << endl << endl;
	system("pause");

}

//������ ����� ��� �������� ������� ������� ZAP[]
void (*ZAP[5])()
{
	zapyt1,
	zapyt2,
	zapyt3,
	zapyt4,
	zapyt5
};

//���� ��� ������ �������
void zapyt()
{
	string list[] = { "\n������� �����: ",
						"����� 1:\n\t\t�������� ���� �������� ����i� � ������ ����",
						"����� 2:\n\t\t������ ��������, � ���� ��������� �������� ������� �����",
						"����� 3:\n\t\t������� ���������� ����  ��������",
						"����� 4:\n\t\t��������� ������������  ��� ������������ �������� (�� �i������ ��������)",
						"����� 5:\n\t\t�������������i ����������i ����� �� ��������" };
	int count = menu(list,6);
	if (count == -1)return;
	ZAP[count-1]();
};

//������� ������� _MAIN_[]
void (*_MAIN_[6])()
{
	addOrder,
	editOrder,
	Show,
	del,
	sort,
	zapyt
};

//������ ����������� ���������
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	string main_menu[] = { "\n���� �������� ������ � ������������� ������� �����\n\t\t\t\t��-20-2\n\t\t\t\t������ ����",
					"��������� ���� �������� �����",
					"����������� ����� ��� �������� ����i�",
					"�������� �����",
					"��������� ����������",
					"���������� ������",
					"������� ������"};
	int choise;
	do {
		system("cls");
		choise = menu(main_menu, 7);
		if (choise == -1)return 0;
		_MAIN_[choise - 1]();
	} while (true);
	
	
	
	return 0;
}