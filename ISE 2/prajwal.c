/*1.Group Number: - 01

URN NO: -  21031010                                   21041010
Name : -     MANALI MANIKRAO THORAT           PRAJWAL GUNWANT SANDAGE.

                                PROJECT NAME  :  Rat in Maze               */

#include <stdio.h>
#define N 4
#define M 5
int input[N][M] = {
    {1, 0, 1, 1, 0},
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1}};

int fx = 2, fy = 3;

int sol[N][M];

int solve(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M) // check block is outside the boundary of matrix
    {
        return 0;
    }
    if (input[x][y] == 0) // the block is dead end
    {
        return 0;
    }
    if (x == fx && y == fy) // reach at destination
    {
        sol[x][y] = 1;
        return 1;
    }
    if (sol[x][y] == 1)
    {
        return 0;
    }

    sol[x][y] = 1;
    // recursively call sol function for all direction..
    if (solve(x + 1, y))
    {
        return 1;
    }
    if (solve(x - 1, y))
    {
        return 1;
    }
    if (solve(x, y + 1))
    {
        return 1;
    }
    if (solve(x, y - 1))
    {
        return 1;
    }
    sol[x][y] = 0; // if block is dead...
    return 0;
}

int main()
{

    if (solve(0, 0))
    {
        printf("Path Found!\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (sol[i][j] == 1)
                {
                    printf("{%d %d} ", i, j);
                }
            }
        }
    }
    else
    {
        printf("No Path Found!\n");
    }
    return 0;
}
/*
Structured programming is a programming paradigm that emphasizes the use of structured control flow constructs, such as loops, conditionals, and subroutines, to create well-organized and readable code. The goal of structured programming is to make code easier to understand, maintain, and modify, by breaking it down into smaller, more manageable pieces.

Coding standards, also known as programming standards or coding conventions, are a set of guidelines and rules that are used to ensure that code is written in a consistent, readable, and maintainable way. They define rules for naming conventions, formatting, commenting, and other aspects of code style, and are used by software engineering teams to promote good coding practices and ensure code quality.

Structured programming and coding standards are closely related, as the principles of structured programming are often used as the basis for coding standards. For example, coding standards may require that control structures (e.g. if-else statements, loops) be indented and formatted in a consistent way, to make the code more readable and structured.

Some common coding standards that are based on structured programming principles include:

The use of meaningful variable names and comments to help clarify the purpose of code.

The use of consistent formatting and indentation to make code more readable.

The use of functions or methods to break down complex tasks into smaller, more manageable parts.

The avoidance of global variables and the use of encapsulation to prevent unintended side effects.

The use of control structures (e.g. loops, conditionals) to control program flow in a clear and structured way.

By following structured programming principles and coding standards, software engineers can create code that is easier to understand, maintain, and modify, which can lead to improved software quality and efficiency.*/