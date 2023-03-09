// Hassan Jawwad 20L-1122 F Assignment 1
#include <iostream>
#include<cmath>
using namespace std;


int** MatrixAdd(int** MatrixA, int rowsA, int colsA, int** MatrixB, int rowsB, int colsB)
{

	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < colsA; j++)//each element of a array is added to the corresponding element of the second array 
		{
			MatrixA[i][j] = MatrixA[i][j] + MatrixB[i][j];//the sum is stored 
		}
	}

	return MatrixA;
}
int** MatrixSub(int** MatrixA, int rowsA, int colsA, int** MatrixB, int rowsB, int colsB)
{

	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < colsA; j++)//each element of the array is subtracted from corresponding element of the second array
		{
			MatrixA[i][j] = MatrixA[i][j] - MatrixB[i][j];//the difference is stored
		}
	}

	return MatrixA;
}
int** MatrixMul(int** MatrixA, int rowsA, int colsA, int** MatrixB, int rowsB, int colsB)
{


	int** C = new int* [rowsA];//2d dynamic array is initialized
	for (int i = 0; i < rowsA; i++)
	{
		C[i] = new int[colsB];
	}

	// Initializing elements of matrix C to 0
	for (int i = 0; i < rowsA; ++i)

	{
		for (int j = 0; j < colsB; ++j)
		{

			C[i][j] = 0;

		}
	}
	for (int i = 0; i < rowsA; ++i)

	{
		for (int j = 0; j < colsB; ++j)

		{
			for (int k = 0; k < colsB; ++k)
			{
				C[i][j] += MatrixA[i][k] * MatrixB[k][j];

			}
		}
	}

	return C;
}
int** MatrixTranspose(float** Matrix, int rows, int cols)
{

	int** A = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		A[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)//rows and columns are interchanged 
	{
		for (int j = 0; j < cols; j++)
		{
			A[i][j] = Matrix[j][i];//transpose of matrix is stored
		}
	}
	return A;

}
int** MatrixRotate(int** Matrix, int rows, int cols)
{
	int** A = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		A[i] = new int[cols];
	}
	for (int i = 0; i < rows / 2; i++)
	{
		for (int j = i; j < cols - i - 1; j++)
		{

			// Swap elements of each cycle
			// in clockwise direction
			int temp = Matrix[i][j];
			Matrix[i][j] = Matrix[rows - 1 - j][i];
			Matrix[rows - 1 - j][i] = Matrix[rows - 1 - i][rows - 1 - j];
			Matrix[rows - 1 - i][rows - 1 - j] = Matrix[j][rows - 1 - i];
			Matrix[j][rows - 1 - i] = temp;
		}
	}
	return Matrix;

}
int MatrixDet(int** Matrix, int rows, int cols)
{
	int d = 0;
	int** newMat = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		newMat[i] = new int[cols];
	}
	int c = 0, subi = 0, i = 0, j = 0, subj = 0;
	if (rows == 2)
	{
		return((Matrix[0][0] * Matrix[1][1]) - (Matrix[1][0] * Matrix[0][1]));
	}
	else
	{
		for (c = 0; c < rows; c++)
		{
			subi = 0;
			for (i = 1; i < cols; i++)
			{
				subj = 0;
				for (j = 0; j < cols; j++)
				{
					if (j == c)
					{
						continue;
					}
					newMat[subi][subj] = Matrix[i][j];
					subj++;
				}
				subi++;
			}
			d = d + (pow(-1, c) * Matrix[0][c] * MatrixDet(newMat, rows - 1, cols - 1));
		}
	}
	return d;
}


int main()
{
	int choice = 0;
	cout << "Enter 1 for multiplication of matrices!" << endl;
	cout << "Enter 2 for addition of matrices!" << endl;
	cout << "Enter 3 for subtraction of matrices!" << endl;
	cout << "Enter 4 for transpose of Matrix!" << endl;
	cout << "Enter 5 for matrix rotation!" << endl;
	cout << "Enter 6 for matrix determinant!" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice == 1)
	{
		//rows and columns are input by the user 
		int rows1, columns1, rows2, columns2;
		cout << "Enter the number of rows for first matrix: ";
		cin >> rows1;
		cout << endl;
		cout << "Enter the number of columns for first matrix: ";
		cin >> columns1;
		cout << endl;
		cout << "Enter the number of rows for second matrix: ";
		cin >> rows2;
		cout << endl;
		cout << "Enter the number of columns for second matrix: ";
		cin >> columns2;

		while (columns1 != rows2)
		{
			cout << "Error! column of first matrix not equal to row of second." << endl;
			cout << "Enter rows  for first matrix: ";
			cin >> rows1;
			cout << "Enter columns for the first matrix: ";
			cin >> columns1;
			cout << "Enter rows for second matrix: ";
			cin >> rows2;
			cout << "Enter columns for the second matrix: ";
			cin >> columns2;
		}
		int** arr = new int* [rows1];//dynamic 2D array is created 
		for (int i = 0; i < rows1; i++)
		{
			arr[i] = new int[columns1];
		}
		cout << endl;
		int** arr1 = new int* [rows2];//dynamic 2D array is created 
		for (int i = 0; i < rows2; i++)
		{
			arr1[i] = new int[columns2];
		}
		cout << endl;
		cout << "Enter the first 2D array:" << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr[i][j];
			}
		}

		cout << "Enter the second 2D array:" << endl;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr1[i][j];
			}
		}
		cout << endl;
		cout << "The first array is" << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "The second array is" << endl;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << arr1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		int** ptr = MatrixMul(arr, rows1, columns1, arr1, rows2, columns2);//function is called

		cout << "The product of the matrices are: " << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << ptr[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < rows1; i++)
		{
			delete[] arr[i];
		}
		arr = NULL;
		delete[]arr;
		for (int i = 0; i < rows2; i++)
		{
			delete[] arr1[i];
		}
		arr1 = NULL;
		delete[]arr1;

	}

	if (choice == 2)
	{
		//rows and columns are input by the user 
		int rows1, columns1, rows2, columns2;
		cout << "Enter the number of rows for first matrix: ";
		cin >> rows1;
		cout << endl;
		cout << "Enter the number of columns for first matrix: ";
		cin >> columns1;
		int** arr = new int* [rows1];//dynamic 2D array is created 
		for (int i = 0; i < rows1; i++)
		{
			arr[i] = new int[columns1];
		}

		cout << endl;

		cout << "Enter the number of rows for second matrix: ";
		cin >> rows2;
		cout << endl;
		cout << "Enter the number of columns for second matrix: ";
		cin >> columns2;
		int** arr1 = new int* [rows2];//dynamic 2D array is created 
		for (int i = 0; i < rows2; i++)
		{
			arr1[i] = new int[columns2];
		}
		cout << endl;

		cout << "Enter the first 2D array:" << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr[i][j];
			}
		}

		cout << "Enter the second 2D array:" << endl;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr1[i][j];
			}
		}
		cout << endl;
		cout << "The first array is" << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "The second array is" << endl;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << arr1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		MatrixAdd(arr, rows1, columns1, arr1, rows2, columns2);//function is called
		cout << "The sum is: " << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}


		for (int i = 0; i < rows1; i++)
		{
			delete[] arr[i];
		}
		arr = NULL;
		delete[]arr;
		for (int i = 0; i < rows2; i++)
		{
			delete[] arr1[i];
		}
		arr1 = NULL;
		delete[]arr1;



	}
	if (choice == 3)
	{
		//rows and columns are input by the user 
		int rows1, columns1, rows2, columns2;
		cout << "Enter the number of rows for first matrix: ";
		cin >> rows1;
		cout << endl;
		cout << "Enter the number of columns for first matrix: ";
		cin >> columns1;
		int** arr = new int* [rows1];//dynamic 2D array is created 
		for (int i = 0; i < rows1; i++)
		{
			arr[i] = new int[columns1];
		}

		cout << endl;

		cout << "Enter the number of rows for second matrix: ";
		cin >> rows2;
		cout << endl;
		cout << "Enter the number of columns for second matrix: ";
		cin >> columns2;
		int** arr1 = new int* [rows2];//dynamic 2D array is created 
		for (int i = 0; i < rows2; i++)
		{
			arr1[i] = new int[columns2];
		}
		cout << endl;

		cout << "Enter the first 2D array:" << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr[i][j];
			}
		}

		cout << "Enter the second 2D array:" << endl;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr1[i][j];
			}
		}
		cout << endl;
		cout << "The first array is" << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "The second array is" << endl;
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
			{
				cout << arr1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		MatrixSub(arr, rows1, columns1, arr1, rows2, columns2);//function is called
		cout << "The difference is: " << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}



		for (int i = 0; i < rows1; i++)
		{
			delete[] arr[i];
		}
		arr = NULL;
		delete[]arr;
		for (int i = 0; i < rows2; i++)
		{
			delete[] arr1[i];
		}
		arr1 = NULL;
		delete[]arr1;
	}

	if (choice == 4)
	{
		//rows and columns are input by the user 
		int rows, columns;
		cout << "Enter rows of the matrix: ";
		cin >> rows;
		cout << "Enter columns of the matrix: ";
		cin >> columns;
		cout << endl;
		float** arr = new float* [rows];
		for (int i = 0; i < rows; i++)//dynamic 2D array is created 
		{
			arr[i] = new float[columns];
		}

		cout << endl;
		cout << "Enter the 2D array:" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr[i][j];
			}
		}
		cout << "The original array is" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		int** arr1 = MatrixTranspose(arr, rows, columns);//function is called

		cout << "The transpose is: " << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << arr1[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		arr = NULL;
		delete[]arr;
	}

	if (choice == 5)
	{
		//rows and columns are input by the user 
		int rows, columns;
		cout << "Enter rows of the matrix: ";
		cin >> rows;
		cout << "Enter columns of the matrix: ";
		cin >> columns;
		while (columns != rows)
		{
			cout << "columns must be equal to rows" << endl;
			cout << "Enter rows  for first matrix: ";
			cin >> rows;
			cout << "Enter columns for the first matrix: ";
			cin >> columns;

		}
		cout << endl;
		int** arr = new int* [rows];
		for (int i = 0; i < rows; i++)//dynamic 2D array is created 
		{
			arr[i] = new int[columns];
		}

		cout << endl;
		cout << "Enter the 2D array:" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr[i][j];
			}
		}
		cout << "The original array is" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		int** arr1 = MatrixRotate(arr, rows, columns);//function is called
		cout << "Matrix after rotation is: " << endl;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << arr1[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		arr = NULL;
		delete[]arr;
	}

	if (choice == 6)
	{
		//rows and columns are input by the user 
		int rows, columns;
		cout << "Enter rows of the matrix: ";
		cin >> rows;
		cout << "Enter columns of the matrix: ";
		cin >> columns;
		while (columns != rows)
		{
			cout << "columns must be equal to rows" << endl;
			cout << "Enter rows  for first matrix: ";
			cin >> rows;
			cout << "Enter columns for the first matrix: ";
			cin >> columns;

		}
		cout << endl;
		int** arr = new int* [rows];
		for (int i = 0; i < rows; i++)//dynamic 2D array is created 
		{
			arr[i] = new int[columns];
		}

		cout << endl;
		cout << "Enter the 2D array:" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << "Enter the element of " << i + 1 << " row and " << j + 1 << " column: ";
				cin >> arr[i][j];
			}
		}
		cout << "The original array is" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << "The determinant is: " << MatrixDet(arr, rows, columns);//function is called

		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		arr = NULL;
		delete[]arr;
	}


		
	system("pause");
	return 0;
}