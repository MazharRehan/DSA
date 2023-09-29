#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class Employee
{
	string  name;
	int id, age;
public:
	int calculateSalary()
	{
		return 0;
	}
	void input()
	{
		cout << "Enter Name: ";
		getline(cin, name);
		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter Age: ";
		cin >> age;
	}
};

class Manager : public Employee
{
public:
	Manager()
	{

	}
	float generalSal()
	{
		int sal = rand() % 10000;
		if(sal<1000)
			sal+=1000;
		return sal;
	}
	float assitantSal()
	{
		return (rand() % 30000) + 20000;
	}
	float marketingSal()
	{
		return (rand() % 80000) + 50000;
	}
};

class Developer : public Employee
{
public:
	Developer()
	{

	}
	float webSal()
	{
		return (rand() % 200000) + 100000;
	}
	float mobileSal()
	{
		return (rand() % 200000) + 150000;
	}
	float gameSal()
	{
		return (rand() % 300000) + 100000;
	}

};

int main()
{
	srand(time(0));

	Manager m;
	Developer d;

	cout << "Enter the following info of Manager: " << endl;
	m.input();

	cout << endl;
	cout << "Manager Salary::" << endl;
	cout << "General Manager: " << m.generalSal() << endl;
	cout << "Assistent Manager: " << m.assitantSal() << endl;
	cout << "Marketing Manager: " << m.marketingSal() << endl << endl;

	cout << "Enter the following info of Developer: " << endl;
	cin.ignore();
	d.input();

	cout << endl;
	cout << "Developers Salary:: " << endl;
	cout << "Game Daveloper: " << d.gameSal() << endl;
	cout << "Web Daveloper: " << d.webSal() << endl;
	cout << "Mobile Daveloper: " << d.mobileSal() << endl;

	system("pause");
	return 0;
}
