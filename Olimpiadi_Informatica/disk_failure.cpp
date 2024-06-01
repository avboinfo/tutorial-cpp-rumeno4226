// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() 
{
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    long long A, B, T;
    cin >> A >> B >> T;

    long long g_interi = T / 24;

    long long tempo_online = B - A;

    long long left_over = tempo_online * g_interi;

    T = T - g_interi * 24;

    T = T - ( 24 - tempo_online );

    if ( T < 0 )
        T = 0;

    cout << T + left_over << endl;    

    return 0;
}