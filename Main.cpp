#include "mat.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int row, col;
    char symbol_1, symbol_2;

    cout << "Please enter col's number: " << endl;
    cin>> col;

    cout << "Please enter row's number: " << endl;
    cin>>row;

    cout << "Please enter Symbol 1: " << endl;
    cin>> symbol_1;

    cout << "Please enter Symbol 2: " << endl;
    cin>> symbol_2;
    cout << ariel::mat(col, row, symbol_1, symbol_2) << endl;

}



