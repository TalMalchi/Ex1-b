#include "mat.hpp"
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

std::string ariel::mat(int col, int row, char symbol_1, char symbol_2)
{
    vector<vector<char>> matrix(row, vector<char>(col));
    // vector<vector<char>> ans1;
    // string matrix[row][col];
    int Start_row = 0;
    int Start_col = 0;
    int End_row = row;
    int End_col = col;
    char sym = symbol_2;
    int const ascii_symbol_min = 33;
    int const ascii_symbol_max = 126;

    // check odd values
    if (row % 2 == 0 || col % 2 == 0)
    {
        throw invalid_argument("number must odd ");
    }
    // check negative values
    if (row < 0 || col < 0)
    {
        throw invalid_argument("number must positive");
    }

    if (symbol_1 < ascii_symbol_min || symbol_2 < ascii_symbol_min || symbol_1 > ascii_symbol_max || symbol_2 > ascii_symbol_max)
    {
        throw invalid_argument("worng symbol! ");
    }

    while (Start_row < End_row && Start_col < End_col)
    {
        // change the symbol each time
        if (sym == symbol_1)
        {
            sym = symbol_2;
        }
        else
        {
            sym = symbol_1;
        }

        // fill first line- from left to right
        for (int i = Start_col; i < End_col; i++)
        {
            matrix[Start_row][i] = sym;
        }
        // fill last col - from up to down
        for (int k = Start_row + 1; k < End_row; k++)
        {
            matrix[k][End_col - 1] = sym;
        }

        if (Start_row < End_row && Start_col < End_col)
        {
            // fill last row
            for (int l = End_col - 1; l >= Start_col; l--)
            {
                matrix[End_row - 1][l] = sym;
            }
            // fill first col
            for (int t = End_row - 1; t >= Start_row; t--)
            {
                matrix[t][Start_col] = sym;
            }
        }

        Start_row++;
        End_row--;
        Start_col++;
        End_col--;
    }
    // print the final matrix
    std::string ans;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans += matrix[i][j];
        }
        ans+="\n";
    }
    
    return ans;
};

// int main(int argc, char const *argv[])
// {
// //     int row, col;
// //     char symbol_1, symbol_2;

//     // cout << "Please enter row's number " <<endl;
//     // scanf("%d", &row);

//     // cout << "Please enter col's number " <<endl;
//     // scanf("%d", &col);

//     // cout << "Please enter Symbol 1 " <<endl;
//     // scanf("%c", &symbol_1);

//     // cout << "Please enter Symbol 2 " <<endl;
//     // scanf("%c", &symbol_2);

//     cout << ariel::mat(13, 15, '@', '-') <<endl;

//     return 0;
// }