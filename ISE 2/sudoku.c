#include <stdio.h>
#include <stdbool.h>
bool find_empty_cell(int mat[9][9], int *row, int *col)
{
    for (*row = 0; *row < 9; (*row)++)
    {
        for (*col = 0; *col < 9; (*col)++)
        {
            if (mat[*row][*col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
bool check_row(int mat[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (mat[row][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool check_col(int mat[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (mat[row][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool check_box(int mat[9][9], int start_row, int start_col, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (mat[row + start_row][col + start_col] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool is_safe(int mat[9][9], int row, int col, int num)
{
    return check_row(mat, row, num) && check_col(mat, col, num) && check_box(mat, row - row % 3, col - col % 3, num);
}

bool solve_sudoku(int mat[9][9])
{
    int row, col;
    if (!(find_empty_cell(mat, &row, &col)))
    {
        return true;
    }
    for (int num = 1; num <= 9; num++)
    {
        if (is_safe(mat, row, col, num))
        {
            mat[row][col] = num;
            if (solve_sudoku(mat))
            {
                return true;
            }
            mat[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int mat[9][9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        if (solve_sudoku(mat))
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
