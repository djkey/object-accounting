#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>

using namespace std;

int l_table = 122;

string DateToString(struct tm date)
{
    string date_s;
    stringstream converter;

    converter << date.tm_mday << "." << date.tm_mon << "." << date.tm_year;
    converter >> date_s;

    return date_s;
}
struct tm StringToDate(string date_s)
{
    struct tm date;
    stringstream converter;

    for (int i = 0; i < date_s.size(); i++)
        if (date_s[i] == '.')
            date_s[i] = ' ';

    converter << date_s;
    converter >> date.tm_mday;
    converter >> date.tm_mon;
    converter >> date.tm_year;

    return date;
}
bool DiffDate(struct tm a, struct tm b)
{
    if (a.tm_year < b.tm_year || a.tm_year == b.tm_year && a.tm_mon < b.tm_mon || a.tm_year == b.tm_year && a.tm_mon == b.tm_mon && a.tm_mday <= b.tm_mday)
        return true;
    else
        return false;
}

inline void OutputASCII(string str)
{
    SetConsoleOutputCP(866);
    cout << str;
    SetConsoleOutputCP(1251);
}

int CorrectInt()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord, coord_2;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    coord = csbi.dwCursorPosition;
    
    int number;
    char ch;
    bool correct = true;

    while (true)
    {
        correct = true;
        cin >> number;

        if (cin.get() != '\n')
            correct = false;

        if (cin.fail() || !correct)
        {
            coord_2.X = csbi.dwCursorPosition.X + 20;
            coord_2.Y = csbi.dwCursorPosition.Y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_2);

            cout << " " << " �������!";
            system("pause");

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            for (int i = 0; i < 74; i++)
                cout << " ";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            std::cin.clear();
            if (cin.fail() || !correct)
                std::cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}
float CorrectFloat()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord, coord_2;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    coord = csbi.dwCursorPosition;

    float number;
    char ch;
    bool correct = true;

    while (true)
    {
        correct = true;
        cin >> number;

        if (cin.get() != '\n')
            correct = false;

        if (cin.fail() || !correct || number < 0)
        {
            coord_2.X = csbi.dwCursorPosition.X + 20;
            coord_2.Y = csbi.dwCursorPosition.Y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_2);

            cout << " " << " �������!";
            system("pause");

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            for (int i = 0; i < 74; i++)
                cout << " ";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            std::cin.clear();
            if (cin.fail() || !correct)
                std::cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}
int CorrectYear()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord, coord_2;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    coord = csbi.dwCursorPosition;

    int number;
    char ch;
    bool correct = true;

    while (true)
    {
        correct = true;
        cin >> number;

        if (cin.get() != '\n')
            correct = false;

        if (cin.fail() || number < 1990 || number > 2100 || !correct)
        {
            coord_2.X = csbi.dwCursorPosition.X + 20;
            coord_2.Y = csbi.dwCursorPosition.Y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_2);

            cout << " " << " �������!";
            system("pause");

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            for (int i = 0; i < 74; i++)
                cout << " ";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            std::cin.clear();
            if (cin.fail() || !correct)
                std::cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}
int CorrectMonth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord, coord_2;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    coord = csbi.dwCursorPosition;

    int number;
    char ch;
    bool correct = true;

    while (true)
    {
        correct = true;
        cin >> number;

        if (cin.get() != '\n')
            correct = false;

        if (cin.fail() || number < 1 || number > 12 || !correct)
        {
            coord_2.X = csbi.dwCursorPosition.X + 20;
            coord_2.Y = csbi.dwCursorPosition.Y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_2);

            cout << " " << " �������!";
            system("pause");

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            for (int i = 0; i < 74; i++)
                cout << " ";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            std::cin.clear();
            if (cin.fail() || !correct)
                std::cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}
int CorrectDay(int month)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord, coord_2;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    coord = csbi.dwCursorPosition;

    int number;
    char ch;
    bool correct = true;

    while (true)
    {
        correct = true;
        cin >> number;

        if (cin.get() != '\n')
            correct = false;

        if (cin.fail() || number < 1 || number > 31 || number > 28 && month == 2 || !correct)
        {
            coord_2.X = csbi.dwCursorPosition.X + 20;
            coord_2.Y = csbi.dwCursorPosition.Y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_2);

            cout << " " << " �������!";
            system("pause");

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            for (int i = 0; i < 74; i++)
                cout << " ";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            std::cin.clear();
            if (cin.fail() || !correct)
                std::cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}
string CorrectString()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord, coord_2;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    coord = csbi.dwCursorPosition;

    string str, str_buf;
    bool correct;
    stringstream ss;

    while (true)
    {
        correct = true;
        str.clear();
        while (str.empty())
            getline(cin, str);

        for (int j = 0; j < str.size(); j++)
        {
            if ((str[j] >= 33 && str[j] <= 64 || str[j] >= 91 && str[j] <= 96 || str[j] >= 123 && str[j] <= 127) && str[j] != ' ')
            {
                if (str[j] == 46)
                    continue;
                else
                    correct = false;
            }
        }

        if (str.size() > 40)
            correct = false;

        if (correct)
        {
            ss << str;
            str.clear();

            while (ss >> str_buf)
            {
                str_buf.at(0) = toupper(str_buf.at(0));
                str = str + " " + str_buf;
            }
            return str;
        }
        else
        {
            coord_2.X = csbi.dwCursorPosition.X + 20 + str.size();
            coord_2.Y = csbi.dwCursorPosition.Y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_2);

            cout << " " << " �������!";
            system("pause");

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            for (int i = 0; i < 74 + str.size(); i++)
                cout << " ";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }
    }
}

struct bong
{
    string title;
    int material;
    int color;
    float price;
    int count;
    string data;
    string fio;
    float totalPrice;
};

vector <string> listMaterials = { "�����", "�����", "����", "������" };
vector <string> listColors = { "������" };

vector <bong> listBongs;

void GetTable()
{
    string V_pod; //������� ����� �������
    string S_pod; //������� ����� �������
    string N_pod; //������ ����� �������

    string stick;
    stick = stick + (char)186;
    /////////////////////////////////////////////
    //��������� ���������� ������� ��� ���������
    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            V_pod = V_pod + (char)201;
        if (i < l_table - 2)
            V_pod = V_pod + (char)205;
        if (i == l_table - 1)
            V_pod = V_pod + (char)187;
    }

    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            S_pod = S_pod + (char)204;
        if (i < l_table - 2)
            S_pod = S_pod + (char)205;
        if (i == l_table - 1)
            S_pod = S_pod + (char)185;
    }

    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            N_pod = N_pod + (char)200;
        if (i < l_table - 2)
            N_pod = N_pod + (char)205;
        if (i == l_table - 1)
            N_pod = N_pod + (char)188;
    }
    /////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //������� ������� ���� ��� ����, � ���� ���, �� ��������� ��� ������ ����
    if (!listBongs.empty())
    {
        OutputASCII(V_pod); cout << endl;
        OutputASCII(stick); cout << " �  ";
        OutputASCII(stick); cout << "      ϲ� ���������      ";
        OutputASCII(stick); cout << "�������";
        OutputASCII(stick); cout << "     ����     ";
        OutputASCII(stick); cout << " ������� (���) ";
        OutputASCII(stick); cout << " �i���i��� (��) ";
        OutputASCII(stick); cout << " ���� ���������� ";
        OutputASCII(stick); cout << " ����� (���) ";
        OutputASCII(stick); cout << endl;

        OutputASCII(S_pod); cout << endl;

        for (int i = 0; i < listBongs.size(); i++)
        {
            OutputASCII(stick); cout << right << setw(4) << i + 1;
            OutputASCII(stick); cout << left << setw(25) << listBongs.at(i).fio;
            OutputASCII(stick); cout << right << setw(8) << listMaterials.at(listBongs.at(i).material - 1);
            OutputASCII(stick); cout << setw(14) << listBongs.at(i).title;
            OutputASCII(stick); cout << setw(16) << listBongs.at(i).price;
            OutputASCII(stick); cout << setw(16) << listBongs.at(i).count;
            OutputASCII(stick); cout << setw(17) << listBongs.at(i).data;
            OutputASCII(stick); cout << setw(13) << listBongs.at(i).price * listBongs.at(i).count;
            OutputASCII(stick); cout << endl;

            if (listBongs.size() != i + 1)
            {
                OutputASCII(S_pod);
                cout << endl;
            }
        }
        OutputASCII(N_pod); cout << endl;
    }
    else
        cout << "������ ����!\n";
    //////////////////////////////////////////////////////////////////////////
}

void GetTable(int i)
{
    string V_pod; //������� ����� �������
    string S_pod; //������� ����� �������
    string N_pod; //������ ����� �������

    string stick;
    stick = stick + (char)186;
    /////////////////////////////////////////////
    //��������� ���������� ������� ��� ���������
    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            V_pod = V_pod + (char)201;
        if (i < l_table - 2)
            V_pod = V_pod + (char)205;
        if (i == l_table - 1)
            V_pod = V_pod + (char)187;
    }

    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            S_pod = S_pod + (char)204;
        if (i < l_table - 2)
            S_pod = S_pod + (char)205;
        if (i == l_table - 1)
            S_pod = S_pod + (char)185;
    }

    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            N_pod = N_pod + (char)200;
        if (i < l_table - 2)
            N_pod = N_pod + (char)205;
        if (i == l_table - 1)
            N_pod = N_pod + (char)188;
    }
    /////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //������� ������� ���� ��� ����, � ���� ���, �� ��������� ��� ������ ����
    OutputASCII(V_pod); cout << endl;
    OutputASCII(stick); cout << " �  ";
    OutputASCII(stick); cout << "      ϲ� ���������      ";
    OutputASCII(stick); cout << "�������";
    OutputASCII(stick); cout << "     ����     ";
    OutputASCII(stick); cout << " ������� (���) ";
    OutputASCII(stick); cout << " �i���i��� (��) ";
    OutputASCII(stick); cout << " ���� ���������� ";
    OutputASCII(stick); cout << " ����� (���) ";
    OutputASCII(stick); cout << endl;

    OutputASCII(S_pod); cout << endl;

    OutputASCII(stick); cout << right << setw(4) << i + 1;
    OutputASCII(stick); cout << left << setw(25) << listBongs.at(i).fio;
    OutputASCII(stick); cout << right << setw(8) << listMaterials.at(listBongs.at(i).material - 1);
    OutputASCII(stick); cout << setw(14) << listBongs.at(i).title;
    OutputASCII(stick); cout << setw(16) << listBongs.at(i).price;
    OutputASCII(stick); cout << setw(16) << listBongs.at(i).count;
    OutputASCII(stick); cout << setw(17) << listBongs.at(i).data;
    OutputASCII(stick); cout << setw(13) << listBongs.at(i).price * listBongs.at(i).count;
    OutputASCII(stick); cout << endl;

    OutputASCII(N_pod); cout << endl;
    //////////////////////////////////////////////////////////////////////////
}

void GetTable(vector <int> list)
{
    string V_pod; //������� ����� �������
    string S_pod; //������� ����� �������
    string N_pod; //������ ����� �������

    string stick;
    stick = stick + (char)186;
    /////////////////////////////////////////////
    //��������� ���������� ������� ��� ���������
    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            V_pod = V_pod + (char)201;
        if (i < l_table - 2)
            V_pod = V_pod + (char)205;
        if (i == l_table - 1)
            V_pod = V_pod + (char)187;
    }

    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            S_pod = S_pod + (char)204;
        if (i < l_table - 2)
            S_pod = S_pod + (char)205;
        if (i == l_table - 1)
            S_pod = S_pod + (char)185;
    }

    for (int i = 0; i < l_table; i++)
    {
        if (i == 0)
            N_pod = N_pod + (char)200;
        if (i < l_table - 2)
            N_pod = N_pod + (char)205;
        if (i == l_table - 1)
            N_pod = N_pod + (char)188;
    }
    /////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //������� ������� ���� ��� ����, � ���� ���, �� ��������� ��� ������ ����
    if (!list.empty())
    {
        OutputASCII(V_pod); cout << endl;
        OutputASCII(stick); cout << " �  ";
        OutputASCII(stick); cout << "      ϲ� ���������      ";
        OutputASCII(stick); cout << "�������";
        OutputASCII(stick); cout << "     ����     ";
        OutputASCII(stick); cout << " ������� (���) ";
        OutputASCII(stick); cout << " �i���i��� (��) ";
        OutputASCII(stick); cout << " ���� ���������� ";
        OutputASCII(stick); cout << " ����� (���) ";
        OutputASCII(stick); cout << endl;

        OutputASCII(S_pod); cout << endl;

        for (int i = 0; i < list.size(); i++)
        {
            OutputASCII(stick); cout << right << setw(4) << i + 1;
            OutputASCII(stick); cout << left << setw(25) << listBongs.at(list.at(i)).fio;
            OutputASCII(stick); cout << right << setw(8) << listMaterials.at(listBongs.at(list.at(i)).material - 1);
            OutputASCII(stick); cout << setw(14) << listBongs.at(list.at(i)).title;
            OutputASCII(stick); cout << setw(16) << listBongs.at(list.at(i)).price;
            OutputASCII(stick); cout << setw(16) << listBongs.at(list.at(i)).count;
            OutputASCII(stick); cout << setw(17) << listBongs.at(list.at(i)).data;
            OutputASCII(stick); cout << setw(13) << listBongs.at(i).price * listBongs.at(i).count;
            OutputASCII(stick); cout << endl;

            if (list.size() != i + 1)
            {
                OutputASCII(S_pod);
                cout << endl;
            }
        }
        OutputASCII(N_pod); cout << endl;
    }
    else
        cout << "������ ����!\n";
    //////////////////////////////////////////////////////////////////////////
}

vector <int> searchBytitle(string title)
{
    vector <int> listOrdersBytitle;

    for (int i = 0; i < listBongs.size(); i++)
        if (title == listBongs.at(i).title)
            listOrdersBytitle.push_back(i);

    return listOrdersBytitle;
}

vector <int> searchByDatePeriod(struct tm date_b, struct tm date_e)
{
    vector <int> list;

    for (int i = 0; i < listBongs.size(); i++)
        if (DiffDate(date_b, StringToDate(listBongs.at(i).data)) && DiffDate(StringToDate(listBongs.at(i).data), date_e))
            list.push_back(i);

    return list;
}

void Sort(int count)
{
    //���������� �� ����
    if (count == 1)
        for (int i = 0; i < listBongs.size() - 1; i++)
            for (int j = i + 1; j < listBongs.size(); j++)
                if (DiffDate(StringToDate(listBongs[i].data), StringToDate(listBongs[j].data)))
                    swap(listBongs[i], listBongs[j]);

    //���������� �� ��������� ��������
    if (count == 2)
        for (int i = 0; i < listBongs.size() - 1; i++)
            for (int j = i + 1; j < listBongs.size(); j++)
                if (listBongs[i].price * listBongs[i].count < listBongs[j].price * listBongs[j].count)
                    swap(listBongs[i], listBongs[j]);
}


void AddtoFile(ofstream& fout)
{
    for (int i = 0; i < listBongs.size(); i++)
        fout << listBongs.at(i).fio << "|" << listBongs.at(i).material << "|" << listBongs.at(i).title << "|" << listBongs.at(i).price << "|" << listBongs.at(i).count << "|" << listBongs.at(i).data << endl;

    fout.close();
}

void AddInBuffer(ifstream& fin)
{
    listBongs.clear();

    stringstream ss;
    string str;

    while (getline(fin, str))
    {
        bong tmp;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '|')
                str[i] = ' ';

            else if (str[i] == ' ')
                str[i] = '|';
        }

        ss << str;
        ss >> tmp.fio;
        for (int i = 0; i < tmp.fio.size(); i++)
            if (tmp.fio[i] == '|')
                tmp.fio[i] = ' ';
        ss >> tmp.material;
        ss >> tmp.title;
        for (int i = 0; i < tmp.title.size(); i++)
            if (tmp.title[i] == '|')
                tmp.title[i] = ' ';
        ss >> tmp.price;
        ss >> tmp.count;
        ss >> tmp.data;

        str.clear();
        ss.clear();

        listBongs.push_back(tmp);
    }
}

void addOrder()
{
    cout << "������� �� ��������� ������? (1 - ��� / 0 - ͳ): ";
    int answer = -1;

    answer = CorrectInt();

    while (answer < 0 || answer > 1)
    {
        cout << "������ ��������! ��������� �� ���: ";
        answer = CorrectInt();
    }

    if (!answer)
        return;

    system("cls");

    while (answer)
    {
        bong tmp;

        cout << "### ��������� ������" << endl << endl;

        cout << "������ ϲ� �볺���: ";
        tmp.fio = CorrectString();

        cout << "������ ������� �����:" << endl;
        for (int i = 0; i < listMaterials.size(); i++)
            cout << i + 1 << ". " << listMaterials.at(i) << endl;
        cout << "> ";

        tmp.material = CorrectInt();
        while (tmp.material < 0 || tmp.material > listMaterials.size())
        {
            cout << "������ ��������! ��������� �� ���: ";
            tmp.material = CorrectInt();
        }

        cout << "������ ����� �����: ";
        tmp.title = CorrectString();

        cout << "������ �������: ";
        tmp.price = CorrectFloat();

        cout << "������ ������� �����: ";
        tmp.count = CorrectInt();


        cout << "�������� ����:" << endl;
        cout << "\t ��: ";
        int tmp_year = CorrectYear();
        cout << "\t �����: ";
        int tmp_mounth = CorrectMonth();
        cout << "\t ����: ";
        int tmp_day = CorrectDay(tmp_mounth);

        stringstream ss;
        ss << tmp_day << "." << tmp_mounth << "." << tmp_year;
        ss >> tmp.data;

        listBongs.push_back(tmp);

        cout << "### ����!" << endl << endl;

        cout << "���������� ��������� ������? (1 - ��� / 0 - ͳ): ";
        answer = CorrectInt();

        while (answer < 0 || answer > 1)
        {
            cout << "������ ��������! ��������� �� ���: ";
            answer = CorrectInt();
        }

        system("cls");
    }
}

void editOrder()
{
    cout << "������� �� ����������� ������? (1 - ��� / 0 - ͳ): ";
    int answer = -1;

    answer = CorrectInt();

    while (answer < 0 || answer > 1)
    {
        cout << "������ ��������! ��������� �� ���: ";
        answer = CorrectInt();
    }

    if (!answer)
        return;

    system("cls");

    while (answer)
    {
        cout << "### ����������� ������" << endl << endl;

        GetTable();
        cout << endl;

        cout << "������ ����� ������ ��� �����������: ";
        int number = CorrectInt();

        while (number - 1 < 0 || number > listBongs.size())
        {
            cout << "������ ��������! ��������� �� ���: ";
            number = CorrectInt();
        }

        while (answer)
        {
            cout << endl << "������� �����:" << endl;
            GetTable(number - 1);
            cout << endl;

            cout << "������ ���� ��� �����������:" << endl;
            cout << "1. ϲ� �볺���" << endl;
            cout << "2. �������" << endl;
            cout << "3. ����" << endl;
            cout << "4. �������" << endl;
            cout << "5. ʳ������" << endl;
            cout << "6. ����" << endl;
            cout << "7. ���" << endl;
            cout << "0. ��������� ����������� ������" << endl;
            cout << "> ";

            int number_menu = CorrectInt();
            while (number_menu < 0 || number_menu > 7)
            {
                cout << "������ ��������! ��������� �� ���: ";
                number_menu = CorrectInt();
            }

            switch (number_menu)
            {
            case 1:
            {
                cout << "������ ϲ� �볺���: ";
                listBongs.at(number - 1).fio = CorrectString();

                break;
            }
            case 2:
            {
                cout << "������ ������� �����:" << endl;
                for (int i = 0; i < listMaterials.size(); i++)
                    cout << i + 1 << ". " << listMaterials.at(i) << endl;
                cout << "> ";

                listBongs.at(number - 1).material = CorrectInt();
                while (listBongs.at(number - 1).material < 0 || listBongs.at(number - 1).material > listMaterials.size())
                {
                    cout << "������ ��������! ��������� �� ���: ";
                    listBongs.at(number - 1).material = CorrectInt();
                }

                break;
            }
            case 3:
            {
                cout << "������ ����� �����: ";
                listBongs.at(number - 1).title = CorrectString();

                break;
            }
            case 4:
            {
                cout << "������ �������: ";
                listBongs.at(number - 1).price = CorrectFloat();

                break;
            }
            case 5:
            {
                cout << "������ �������: ";
                listBongs.at(number - 1).count = CorrectInt();

                break;
            }
            case 6:
            {
                cout << "�������� ����:" << endl;
                cout << "\t ��: ";
                int tmp_year = CorrectYear();
                cout << "\t �����: ";
                int tmp_mounth = CorrectMonth();
                cout << "\t ����: ";
                int tmp_day = CorrectDay(tmp_mounth);

                stringstream ss;
                ss << tmp_day << "." << tmp_mounth << "." << tmp_year;
                ss >> listBongs.at(number - 1).data;

                break;
            }
            case 7:
            {
                cout << "������ ϲ� �볺���: ";
                listBongs.at(number - 1).fio = CorrectString();

                cout << "������ �������:" << endl;
                for (int i = 0; i < listMaterials.size(); i++)
                    cout << i + 1 << ". " << listMaterials.at(i) << endl;
                cout << "> ";

                listBongs.at(number - 1).material = CorrectInt();
                while (listBongs.at(number - 1).material < 0 || listBongs.at(number - 1).material > listMaterials.size())
                {
                    cout << "������ ��������! ��������� �� ���: ";
                    listBongs.at(number - 1).material = CorrectInt();
                }

                cout << "������ ����� �����: ";
                listBongs.at(number - 1).title = CorrectString();

                cout << "������ �������: ";
                listBongs.at(number - 1).price = CorrectFloat();

                cout << "������ �������: ";
                listBongs.at(number - 1).count = CorrectInt();


                cout << "�������� ����:" << endl;
                cout << "\t ��: ";
                int tmp_year = CorrectYear();
                cout << "\t �����: ";
                int tmp_mounth = CorrectMonth();
                cout << "\t ����: ";
                int tmp_day = CorrectDay(tmp_mounth);

                stringstream ss;
                ss << tmp_day << "." << tmp_mounth << "." << tmp_year;
                ss >> listBongs.at(number - 1).data;

                break;
            }
            case 0:
            {
                answer = 0;
                break;
            }
            }

            system("cls");
        }

        cout << "���������� ����������� ������? (1 - ��� / 0 - ͳ): ";
        answer = CorrectInt();

        while (answer < 0 || answer > 1)
        {
            cout << "������ ��������! ��������� �� ���: ";
            answer = CorrectInt();
        }

        system("cls");
    }
}

void deleteOrders()
{
    cout << "������� �� ��������� ������? (1 - ��� / 0 - ͳ): ";
    int answer = -1;

    answer = CorrectInt();

    while (answer < 0 || answer > 1)
    {
        cout << "������ ��������! ��������� �� ���: ";
        answer = CorrectInt();
    }

    if (!answer)
        return;

    system("cls");

    while (answer)
    {
        cout << "### ��������� ������" << endl << endl;

        cout << "������ ��� ���������:" << endl;
        cout << "\t1. �� ������� ������" << endl;
        cout << "\t2. �� ������ �����" << endl;
        cout << "> ";

        answer = CorrectInt();

        while (answer < 1 || answer > 2)
        {
            cout << "������ ��������! ��������� �� ���: ";
            answer = CorrectInt();
        }

        system("cls");

        GetTable();
        cout << endl;

        switch (answer)
        {
        case 1:
        {
            cout << "������ ����� ������, ���� ������ ��������: ";
            int number = CorrectInt();

            while (number - 1 < 0 || number > listBongs.size())
            {
                cout << "������ ��������! ��������� �� ���: ";
                number = CorrectInt();
            }

            cout << endl << "������� �����:" << endl;
            GetTable(number - 1);
            cout << endl;

            cout << endl << "�� ����� ������ �������� ��� �����? (1 - ��� / 0 - ͳ): ";
            answer = CorrectInt();

            while (answer < 0 || answer > 1)
            {
                cout << "������ ��������! ��������� �� ���: ";
                answer = CorrectInt();
            }

            switch (answer)
            {
            case 1:
            {
                listBongs.erase(listBongs.begin() + number - 1);
                break;
            }
            case 2:
            {
                cout << "��������� ���������!" << endl;
                break;
            }
            }

            break;
        }
        case 2:
        {
            cout << "������ ����� �����: ";
            vector <int> listOrdersBytitle = searchBytitle(CorrectString());

            if (listOrdersBytitle.size() == 0)
                cout << "������ �� ��������!" << endl;
            else
            {
                cout << "������� ������:" << endl;
                GetTable(listOrdersBytitle);
                cout << endl;

                int answer_del = -1;

                if (listOrdersBytitle.size() > 1)
                {
                    cout << "�������� �� ������, �� ������ ������ � ������? (1 - �� / 2 - ������): ";
                    answer_del = CorrectInt();

                    while (answer_del < 1 || answer_del > 2)
                    {
                        cout << "������ ��������! ��������� �� ���: ";
                        answer_del = CorrectInt();
                    }
                }
                else
                    answer_del = 1;

                switch (answer_del)
                {
                case 1:
                {
                    cout << endl << "�� ������ �������� �� ������? (1 - ��� / 0 - ͳ): ";
                    answer = CorrectInt();

                    while (answer < 0 || answer > 1)
                    {
                        cout << "������ ��������! ��������� �� ���: ";
                        answer = CorrectInt();
                    }

                    switch (answer)
                    {
                    case 1:
                    {
                        for (int i = 0; i < listOrdersBytitle.size(); i++)
                            listBongs.erase(listBongs.begin() + listOrdersBytitle.at(i));
                        break;
                    }
                    case 2:
                    {
                        cout << "��������� ���������!" << endl;
                        break;
                    }
                    }

                    break;
                }
                case 2:
                {
                    cout << "������ ����� ������, ���� ������ ��������: ";
                    int number = CorrectInt();

                    while (number - 1 < 0 || number > listOrdersBytitle.size())
                    {
                        cout << "������ ��������! ��������� �� ���: ";
                        number = CorrectInt();
                    }

                    cout << endl << "������� �����:" << endl;
                    GetTable(listOrdersBytitle.at(number - 1));
                    cout << endl;

                    cout << endl << "�� ����� ������ �������� ��� �����? (1 - ��� / 0 - ͳ): ";
                    answer = CorrectInt();

                    while (answer < 0 || answer > 1)
                    {
                        cout << "������ ��������! ��������� �� ���: ";
                        answer = CorrectInt();
                    }

                    switch (answer)
                    {
                    case 1:
                    {
                        listBongs.erase(listBongs.begin() + listOrdersBytitle.at(number - 1));
                        break;
                    }
                    case 2:
                    {
                        cout << "��������� ���������!" << endl;
                        break;
                    }
                    }

                    break;
                }
                }
            }

            break;
        }
        }

        cout << endl << "### ����!" << endl << endl;

        cout << endl << "���������� ���������? (1 - ��� / 0 - ͳ): ";
        answer = CorrectInt();

        while (answer < 0 || answer > 1)
        {
            cout << "������ ��������! ��������� �� ���: ";
            answer = CorrectInt();
        }

        if (!answer)
            return;

        system("cls");
    }
}

void Zaput1()
{
    float* listCounters = new float[listMaterials.size()];

    for (int i = 0; i < listMaterials.size(); i++)
        listCounters[i] = 0;

    for (int i = 0; i < listBongs.size(); i++)
        listCounters[listBongs.at(i).material - 1] += 1;

    cout << "³�������� ������������ �������� ����� �� ���������:" << endl << endl;
    for (int i = 0; i < listMaterials.size(); i++)
        cout << listMaterials.at(i) << ": " << listCounters[i] / ((float)listBongs.size() / 100) << "%" << endl;

    delete listCounters;

    system("pause");
}

int main()
{
    ifstream fin;
    ofstream fout;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //SetColor(Black, White);
    system("cls");

    fin.open("orders.txt");

    if (fin.is_open())
    {
        int answer;

        while (true)
        {
            cout << "���������� ����� � �������� ����, �� ������������ ����? (1 - ���������� / 0 - ������������)\n";
            cin >> answer;

            if (answer == 0)
            {
                fin.close();
                fout.open("baza.txt", ios_base::trunc);
                fout.close();
                break;
            }
            else if (answer == 1)
            {
                break;
            }
            else
            {
                cout << "       �������! ��������� �� ���: .\n";
                cin >> answer;
            }
        }
    }
    else
    {
        fout.open("orders.txt");
        fout.close();
        fin.open("orders.txt");
    }

    AddInBuffer(fin);

    while (true)
    {
        system("cls");

        cout << "### ���� ###" << endl << endl;

        cout << "1. ��������� ������" << endl;
        cout << "2. ����������� ������" << endl;
        cout << "3. ��������� ������" << endl;
        cout << "4. �������� ��� ������" << endl;
        cout << "5. ���������� ������" << endl;
        cout << "6. ������" << endl;
        cout << "0. �����" << endl;
        cout << "> ";

        int number_menu = CorrectInt();

        while (number_menu < 0 || number_menu > 6)
        {
            cout << "������ ��������! ��������� �� ���: ";
            number_menu = CorrectInt();
        }

        switch (number_menu)
        {
        case 1:
        {
            system("cls");
            addOrder();
            fout.open("orders.txt", ios_base::trunc);
            AddtoFile(fout);
            break;
        }
        case 2:
        {
            system("cls");
            editOrder();
            fout.open("orders.txt", ios_base::trunc);
            AddtoFile(fout);
            break;
        }
        case 3:
        {
            system("cls");
            deleteOrders();
            fout.open("orders.txt", ios_base::trunc);
            AddtoFile(fout);
            break;
        }
        case 4:
        {
            system("cls");
            GetTable();
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            cout << "### ����������" << endl << endl;

            cout << "������ ��� ����������:" << endl;
            cout << "\t1. �� �����" << endl;
            cout << "\t2. �� ��������� �������" << endl;
            cout << "> ";

            int number = CorrectInt();
            while (number < 1 || number > 2)
            {
                cout << "������ ��������! ��������� �� ���: ";
                number = CorrectInt();
            }

            Sort(number);

            fout.open("orders.txt", ios_base::trunc);
            AddtoFile(fout);

            cout << "### ����!" << endl;
            system("pause");

            break;
        }
        case 6:
        {
            int number = 1;

            while (number)
            {
                system("cls");
                cout << "### ������" << endl << endl;

                cout << "1. ������ �����" << endl;
                cout << "2. ������ �����" << endl;
                cout << "3. ����� �����" << endl;
                cout << "4. ��������� �����" << endl;
                cout << "5. �\'���� �����" << endl;
                cout << "0. �����" << endl;
                cout << "> ";

                number = CorrectInt();
                while (number < 0 || number > 5)
                {
                    cout << "������ ��������! ��������� �� ���: ";
                    number = CorrectInt();
                }

                switch (number)
                {
                case 1:
                {
                    Zaput1();
                    system("cls");
                    break;
                }
                case 2:
                {
                    system("cls");

                    break;
                }
                case 3:
                {
                    system("cls");

                    break;
                }
                case 4:
                {
                    system("cls");

                    break;
                }
                case 5:
                {
                    system("cls");

                    break;
                }
                }
            }
            break;
        }
        case 0:
        {
            return 0;
            break;
        }
        }
    }
    return 0;
}