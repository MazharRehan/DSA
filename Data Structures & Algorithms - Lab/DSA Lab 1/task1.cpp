#include<iostream>
using namespace std;

class Matrix
{
	int rows, columns;
	int** x;
	int** y;
	int** result;
	void assign2D();
public:
	Matrix()
	{
		rows = 0;
		columns = 0;
		x = NULL;
		y = NULL;
	}
	~Matrix()
	{
		delete2D(x, rows, columns);
		delete2D(y, rows, columns);
	}
	void input();
	void inputMatrix();
	void dispaly();
	void addMatrices();
	void subMatrices();
	void addConst();
	void multiplayMatrices();
	void delete2D(int**, int, int);


};
void Matrix::input()
{
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> columns;

	assign2D();
}
void Matrix::assign2D()
{
	x = new int* [rows];
	y = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		x[i] = new int[columns];
		y[i] = new int[columns];
	}
}
void Matrix::inputMatrix()
{
	cout << "\nInput Elements of the following matrices" << endl;

	cout << "For 1st Matrix::" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "(" << i << "," << j << ") ";
			cin >> x[i][j];
		}
	}

	cout << "For 2st Matrix::" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "(" << i << "," << j << ") ";
			cin >> y[i][j];
		}
	}
}

void Matrix::dispaly()
{
	cout << "1st Matrix::" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << x[i][j] << " ";

		cout << endl;
	}


	cout << "\n2nd Matrix::" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << y[i][j] << " ";

		cout << endl;
	}

}

void  Matrix::addMatrices()
{
	result = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new int[columns];
	}

	// Addition
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			result[i][j] = x[i][j] + y[i][j];
		cout << endl;
	}

	cout << "Addition of two matrices is::" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << result[i][j] << " ";

		cout << endl;
	}

	delete2D(result, rows, columns);
}
void  Matrix::subMatrices()
{
	result = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		result[i] = new int[columns];
	}

	// Subtraction
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			result[i][j] = x[i][j] - y[i][j];
		cout << endl;
	}

	cout << "Subraction of two matrices is::" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << result[i][j] << " ";

		cout << endl;
	}

	delete2D(result, rows, columns);
}
void  Matrix::addConst()
{
	int choice;
	cout << "Please select a matrix to add constant value:\n1-Matrix A\n 2-Matrix B\n__ " << endl;
	cin >> choice;
	int value;
	cout << "Input a constant value: ";
	cin >> value;

	result = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new int[columns];
	}

	if (choice)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				result[i][j] = x[i][j] + value;
			cout << endl;
		}
	}
	
	if (choice==2)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				result[i][j] = y[i][j] + value;
			cout << endl;
		}
	}

	cout << "Addition of " << value << "to a matrix is::" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << result[i][j] << " ";

		cout << endl;
	}

	delete2D(result, rows, columns);
}

void  Matrix::multiplayMatrices()
{

	if (rows != columns)
	{
		cout << "Multiplication is not possible for given matrices." << endl;
	}
	else
	{
		result = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			result[i] = new int[columns];
		}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				for (int k = 0; k < columns; k++)
					result[i][j] = x[i][k] + y[k][j];
					
		cout << endl;
		

		cout << "Multilication of two matrices is::" << endl;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)				
				cout << result[i][j] << " ";
		cout << endl;
	}
}

void  Matrix::delete2D(int** arr, int r, int c)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
		arr[i] = NULL;
	}

	delete[]arr;
	arr = NULL;
}

int main()
{
	Matrix obj;

	obj.input();
	obj.inputMatrix();

	int option = 0;
	do
	{
		cout << "Please select from the given Options"
			<< "\n1: Input Matrix"
			<< "\n2 : Display Matrix"
			<< "\n3 : Add Matrices"
			<< "\n4 : Subtract Matrices"
			<< "\n5 : Add a Constant value to Matrix"
			<< "\n6 : Multiply Matrices"
			<< "\n7 : Exit\n__";
		cin >> option;

		if (option == 1)
			obj.inputMatrix();
		else if (option == 2)
			obj.dispaly();
		else if (option == 3)
			obj.addMatrices();
		else if (option == 4)
			obj.subMatrices();
		else if (option == 5)
			obj.addConst();
		else if (option == 6)
			obj.multiplayMatrices();

	} while (option != 7);



	return 0;
}
