#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;
string path = "data.txt";
int count_line = 0;
int N = 0;

class student
{
public:

	int group;
	string faculti;
	student()
	{

	}
	int setGroup()
	{
		cout << "Please input group" << endl;
		int set_group;
		cin >> set_group;
		group = set_group;
		return group;
	}
	string setfaculti()
	{
		string a;
		cout << "Please input faculti student" << endl;
		cin >> a;
		faculti = a;
		return faculti;
	}
	int GetGroup()
	{
		return group;
	}
	string Getfaculti()
	{
		return faculti;
	}
	void Print_Student()
	{
		cout << "Number group is" << group << endl;
		cout << "Faculti student is " << faculti << endl;
	}
	string setfaculti_2(string a)
	{
		faculti = a;
		return faculti;
	}
	int set_group_2(int a)
	{
		group = a;
		return group;
	}
	~student()
	{

	}
};

class man
{
public:
	string setName()
	{
		string name_copy;
		cout << "Please input name student" << endl;
		cin >> name_copy;
		name = name_copy;
		return name;
	}
	string set_surename()
	{
		string fam_copy;
		cout << "Please input surename" << endl;
		cin >> fam_copy;
		fam = fam_copy;
		return fam;
	}
	string get_Name()
	{
		return name;
	}
	string get_surename()
	{
		return fam;
	}
	void Print_data()
	{
		string copy_name = get_Name();
		string copy_fam = get_surename();
		cout << "Name student is:" << copy_name << endl;
		cout << "Surename student is: " << copy_fam << endl;
	}
	string setName_2(string a)
	{
		name = a;
		return name;
	}
	string setSurename_2(string a)
	{
		fam = a;
		return fam;
	}
private:
	string name;
	string fam;
};

void Menu()
{
	cout << "Main menu" << '\t' << endl;
	cout << endl;
	cout << "1- Add new student in database " << endl;
	cout << "2- Filter student with number group " << endl;
	cout << "3- Sort with Alhabet student " << endl;
	cout << "4- Find student for surename " << endl;
	cout << "5- Output all student " << endl;
	cout << "6- Exit programe" << endl;
	cout << endl;
	cout << "Please input your solution :" << '\t' << endl;
}



void add(student*& database, man*& database_2, int& N)
{
	database_2[N].setName();
	database_2[N].set_surename();
	database[N].setfaculti();
	database[N].setGroup();
	cout << endl;
	cout << "Succesfull" << endl;
	++N;
}
void Find_with_surename(student*& database, man*& database_2, const int& N)
{
	string find_word;
	cout << "Please input surename student who you want finded" << endl;
	cin >> find_word;
	int a = 0;
	for (int i = 0; i < N; i++)
	{
		string surename_find;
		surename_find = database_2[i].get_surename();
		if (find_word == surename_find)
		{
			database_2[i].Print_data();
			database[i].Print_Student();
			++a;
		}
	}
	if (a == 0)
	{
		cout << "Thats student not study in university" << endl;
	}
}
void Filter(student*& database, man*& database_2, const int& N)
{
	int nubmer_group_copy;
	cout << "Please input number group who filter student" << endl;
	cin >> nubmer_group_copy;
	cout << "Filter students" << endl;
	for (int i = 0; i < N; i++)
	{
		int value = database[i].GetGroup();
		if (nubmer_group_copy == value)
		{
			database[i].Print_Student();
			database_2[i].Print_data();
		}
	}

}
void Sort_with_Albhabet(student*& database, man*& database_2, const int& N)
{
	set<string>names;
	for (int i = 0; i < N; i++)
	{
		string name_ = database_2[i].get_Name();
		names.insert(name_);
	}

	for (auto item : names)
	{
		if (item == "")
		{
			continue;
		}
		for (int j = 0; j < N; j++)
		{
			string name__;
			name__ = database_2[j].get_Name();
			if (name__ == item)
			{
				database_2[j].Print_data();
				database[j].Print_Student();
			}


		}
	}

}
void Output(student*& database, man*& database_2, const int& N)
{
	for (int i = 0; i < N; i++)
	{
		database_2[i].Print_data();
		database[i].Print_Student();
	}

}
void save(student*& database, man*& database_2, const int& N)
{
	fstream datainput;
	datainput.open(path, ios::out);
	for (int i = 0; i < N; i++)
	{
		string name, surenamess, faculti;
		int number;
		name = database_2[i].get_Name();
		surenamess = database_2[i].get_surename();
		faculti = database[i].Getfaculti();
		number = database[i].GetGroup();
		datainput << name << endl << surenamess << endl << faculti << endl << number << endl;
		cout << endl;
	}
	datainput.close();
}
void Value_N(int& N) {
	fstream read;
	read.open(path, ios::in);
	int count = 1;
	string per;
	while (read.peek() != EOF) {
		getline(read, per);
		++count;
		if (count % 4 == 0)
		{
			++N;
		}
	}
	count_line = count;
}
int string_to_int(string str)
{
	int result;
	istringstream iss(str, istringstream::in);
	iss >> result;
	return result;
}
void load_from_file(student*& database, man*& database_2)
{
	int index = 0;
	fstream datainput;
	datainput.open(path, ios::in);
	for (int j = 0; j < count_line - 1;)
	{
		j = j + 4;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
			{
				string line;
				getline(datainput, line);
				database_2[index].setName_2(line);
				break;
			}
			case 1:
			{
				string line;
				getline(datainput, line);
				database_2[index].setSurename_2(line);
				break;
			}
			case 2:
			{
				string line;
				getline(datainput, line);
				database[index].setfaculti_2(line);
				break;
			}
			case 3:
			{
				string line;
				getline(datainput, line);
				int b = string_to_int(line);
				database[index].set_group_2(b);
				break;
			}

			}
		}
		index++;
	}
	datainput.close();
}
int main()
{
	Value_N(N);
	student* database = new student[10000];
	man* database_2 = new man[10000];
	int  solution = 999;
	load_from_file(database, database_2);
	while (solution != 6)
	{
		Menu();
		cin >> solution;
		switch (solution)
		{
		case 1:
		{
			add(database, database_2, N);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			Filter(database, database_2, N);
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			Sort_with_Albhabet(database, database_2, N);
			system("pause");
			system("cls");
			break;
		}


		case 4:
		{
			Find_with_surename(database, database_2, N);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			Output(database, database_2, N);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			save(database, database_2, N);
			cout << "Exit" << endl;
			return 0;
		}

		}




	}

	return 0;
}