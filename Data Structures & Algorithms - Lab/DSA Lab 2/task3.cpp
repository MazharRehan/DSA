// task 3:

#include<iostream>
#include<string>
using namespace std;

class Student
{
	string name, regNo;
	int semester;
	string courses[5];
public:
	Student(): courses{""}
	{
		semester = 0;
		name = "";
		regNo = "";
	}
	void input()
	{
		cout << "Input student's info\nEnter Name: ";
		getline(cin, name);
		cout << "Registration Number: ";
		//cin.ignore();
		getline(cin, regNo);
		cout << "Courses: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Course " << i + 1 << " _ ";
			//cin.ignore();
			getline(cin, courses[i]);
		}
		cout << endl;
	}
	void display()
	{
		cout << "\n```````````` Student's Info ```````````"
			<< "\nName: " << name
			<< "\nRegistration number: " << regNo
			<< "\nCourses:\t";
		for (int i = 0; i < 5; i++)
			cout << courses[i] << "\t";;
		cout << endl;
	}
};

class Teacher
{
	string name, address;
	Student* _student;
public:
	Teacher()
	{
		name = "";
		address = "";
	}
	Teacher(Student& obj)
	{
		_student = &obj;
		name = "";
		address = "";
		_student->input();
	}
	void input()
	{
		cout << "Input Teacher's Info:"
			<< "\nName: ";
		getline(cin, name);
		cout << "Address: ";
		getline(cin, address);
	}
	void displayTS()
	{
		cout << "\n`````` Teacher's Info ```````"
			<< "\nName: " << name
			<< "\nAddress: " << address << endl;
		_student->display();
	}
};

int main()
{
	Student studObj;
	Teacher teachObj(studObj);

	teachObj.input();

	teachObj.displayTS();


	return 0;
}
