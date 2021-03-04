#include <iostream>
#include <vector>

using namespace std;

void Init(int matirx[][5], int col, int row);
void ZeroMatrix(int matrix[][5], int col, int row);
void ShowMatrix(int matrix[][5], int col, int row);

struct Position
{
    int i, j;
};

int main()
{
    int matrix[4][5];

    Init(matrix, sizeof(matrix[0]) / sizeof(int), sizeof(matrix) / sizeof(matrix[0]));
    ZeroMatrix(matrix, sizeof(matrix[0]) / sizeof(int), sizeof(matrix) / sizeof(matrix[0]));
    ShowMatrix(matrix, sizeof(matrix[0]) / sizeof(int), sizeof(matrix) / sizeof(matrix[0]));

    return 0;
}

void Init(int matirx[][5], int col, int row)
{
    int initValue = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 2 && j == 3 || i == 1 && j == 1)
            {
                matirx[i][j] = 0;
            }
            else
            {
                matirx[i][j] = initValue;
            }

            initValue++;
        }
    }

}

void ZeroMatrix(int matrix[][5], int col, int row)
{    
    std::vector<Position> pos;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                Position position;
                position.i = i;
                position.j = j;

                pos.push_back(position);
            }
        }
    }

    while (!pos.empty())
    {
        Position currentPos = pos[pos.size() - 1];
        pos.pop_back();

        for (int i = 0; i < row; i++)
        {
            matrix[i][currentPos.j] = 0;
        }
        for (int j = 0; j < col; j++)
        {
            matrix[currentPos.i][j] = 0;
        }
    }
}

void ShowMatrix(int matrix[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << ",  ";
        }

        cout << endl;
    }
}

