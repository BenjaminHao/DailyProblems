#include <iostream>

void swap(int &a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void transpose(int matrix[4][4])
{
    // reflection
    // swap [0][1] and [1][0], [0][2] and [2][0], [0][3] and [3][0]
    // swap [1][2] and [2][1], [1][3] and [3][1]
    // swap [2][3] and [3][2]
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // swap i and n - 1 - i
    // swap [0][0] and [3][0], [0][1] and [3][1], [0][2] and [3][2], [0][3] and [3][3]
    // swap [1][0] and [2][0], [1][1] and [2][1], [1][2] and [2][2], [1][3] and [2][3]
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            swap(matrix[i][j], matrix[4 - 1 - i][j]);
        }
    }
}

int main()
{
    int matrix[4][4] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Rotate the image by 90 degrees: " << std::endl;

    transpose(matrix);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}