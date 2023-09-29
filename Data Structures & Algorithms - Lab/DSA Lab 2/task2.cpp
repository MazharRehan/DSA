#include<iostream>
using namespace std;

class Vehicle
{
	int wheels;
public:
	Vehicle()
	{
		wheels = 0;
	}
	~Vehicle() {  }
	Vehicle(int w) : wheels(w) {  }
	Vehicle(const Vehicle& v) : wheels(v.wheels) {  }

	void input()
	{
		cout << "Enter Number of wheels of Vehicle: ";
		cin >> wheels;
	}
	int getWheels()
	{
		return wheels;
	}

};

class Bike : public Vehicle
{
	double height;
	bool seftStart, discBrake;

public:
	static int numberOfBikes;
	Bike()
	{
		height = 0.0;
		seftStart = discBrake = 0;
	}
	Bike(double h, bool sT, bool dB) : height(h), seftStart(sT), discBrake(dB)
	{	}
	Bike(const Bike & b) : height(b.height), seftStart(b.seftStart), discBrake(b.discBrake)
	{	}

	~Bike()
	{  }

	void display()
	{
		cout << "Height : " << height
			<< "\nSelf Start: " << seftStart
			<< "\nDisk Brake: " << discBrake
			<< "\nNumber of Bikes: " << numberOfBikes << endl;
	}

};

class Car : public Vehicle
{
	int noOfDoors, noOfSeats;
	string trasmission;
public:
	static int numberOfCars;
	Car()
	{
		noOfDoors = noOfSeats = 0;
		trasmission = "";
	}
	Car(int nOD, int nOS, string t) : noOfDoors(nOD), noOfSeats(nOS), trasmission(t)
	{	}
	Car(const Car& c) : noOfDoors(c.noOfDoors), noOfSeats(c.noOfSeats), trasmission(c.trasmission)
	{	 }

	~Car()
	{  }

	void display()
	{
		cout << "Number of Doors: " << noOfDoors
			<< "\nNumber of Seats: " << noOfSeats
			<< "\nNumber of Cars: " << numberOfCars
			<< "\nTransaction: " << trasmission << endl;
	}

};


int Bike::numberOfBikes = 20;
int Car::numberOfCars = 100;

int main()
{
	Vehicle v;

	v.input();

	if (v.getWheels() == 2)
	{
		Bike b(2.9, true, 1);
		b.display();
	}
	else if (v.getWheels() == 4)
	{
		Car c(4, 5, "Auto");
		c.display();
	}

	return 0;
}
