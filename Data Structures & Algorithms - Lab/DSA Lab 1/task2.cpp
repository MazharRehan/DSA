#include<iostream>
#include<fstream>
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
	void input(ifstream&);
	void inputMatrix(ifstream&);
	void dispaly();
	void addMatrices();
	void subMatrices();
	void addConst(ifstream&);
	void multiplayMatrices();
	void delete2D(int**, int, int);


};
void Matrix::input(ifstream& fin)
{
	fin >> rows;	//read number of rows
	fin >> columns; 	//read number of columns
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
void Matrix::inputMatrix(ifstream& fin)
{
	// read first matrix
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			fin >> x[i][j];
		}
	}
	
	// read 2nd matrix
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			fin >> y[i][j];
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
void  Matrix::addConst(ifstream& fin)
{
	int  choice;
	fin >> choice;

	int value;
	fin >> value;


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

	if (!choice)
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
		{
			for (int j = 0; j < columns; j++)
			{
				for (int k = 0; k < columns; k++)
				{
					result[i][j] = x[i][k] + y[k][j];
				}
			}
			cout << endl;
		}

		cout << "Multilication of two matrices is::" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				cout << result[i][j] << " ";

			cout << endl;
		}
	}
}

void  Matrix::delete2D(int** arr, int r, int c)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
		arr[i] = NULL;
	}

	delete[]arr;
	arr = NULL;
}

int main()
{
	Matrix obj;

	ifstream fin;
	fin.open("Data.txt");

	if (fin.is_open())
	{
		obj.input(fin);
		obj.inputMatrix(fin);

		int option = 0;
		do
		{
			cout << "Please select from the given Options"
				<< "\n 1 : Display Matrix"
				<< "\n 2 : Add Matrices"
				<< "\n 3 : Subtract Matrices"
				<< "\n 4 : Add a Constant value to Matrix"
				<< "\n 5 : Multiply Matrices"
				<< "\n 0 : Exit\n__";
			cin >> option;

			 if (option == 1)
				obj.dispaly();
			else if (option == 2)
				obj.addMatrices();
			else if (option == 3)
				obj.subMatrices();
			else if (option == 4)
				obj.addConst(fin);
			else if (option == 5)
				obj.multiplayMatrices();

		} while (option != 0);
	}
	else
		cout << "File not found" << endl;


	fin.close();

	return 0;
}
