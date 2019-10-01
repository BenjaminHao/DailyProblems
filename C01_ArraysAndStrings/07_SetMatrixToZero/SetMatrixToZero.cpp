#include <iostream>
#include <cstring>
#include <iomanip>

/* setToZero(int **matrix, int m, int n)
** matrix[m][n], a m * n two dimensional array
*/
void setToZero(int** matrix, int m, int n)
{
	bool* row = new bool[m];
	bool* col = new bool[n];

    // set to false for all elements
    // for automatically-allocated arrays, use:
    // memset(myarray, 0, sizeof(myarray)); 
    // for heap-allocated arrays, where N is the number of elements, use:
    // memset(myarray, 0, N * sizeof(*myarray));
	memset(row, false, m * sizeof(*row));
	memset(col, false, n * sizeof(*col));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (row[i] || col[j])
			{
				matrix[i][j] = 0;
			}
		}
	}
	delete[] row;
	delete[] col;
}

int main()
{
	// create a 5 * 6 array
	int** matrix = new int* [5];
	for (int i = 0; i < 5; ++i)
	{
		matrix[i] = new int[6];
	}

	// fill in numbers
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			matrix[i][j] = 1 + i * 6 + j;
		}
	}

	// set 15 to be 0
	matrix[2][2] = 0;

	// display original array
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			std::cout << std::setw(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Set to zero: " << std::endl;

	setToZero(matrix, 5, 6);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			std::cout << std::setw(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// free the memory. Notice how we free them correctly
	for (int i = 0; i < 5; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}