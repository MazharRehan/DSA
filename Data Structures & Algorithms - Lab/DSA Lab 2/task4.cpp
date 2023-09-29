#include<iostream>
using namespace std;

template <typename T>
T calSum(T* arr, int s)
{
	T sum = 0;
	for (int i = 0; i < s; i++)
	{
		sum += arr[i];
	}

	return sum;
}
template <typename T>
void input(T* arr, int s)
{
	cout << "Array size is "<< s << endl;
	cout << "Input the array Elements" << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
}

int main()
{
	const int size = 7;
	int arr[size] = { 0 };
	int sum = 0;
	float avg = 0.0;

	input(arr, size);
	sum = calSum<int>(arr, size);
	avg = sum / size;

	cout << "Sum = " << sum	<< "\nAverage = " << avg << endl;

	return 0;
}
