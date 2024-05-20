// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector< int > H, V;

int main() 
{
    //uncomment the following lines if you want to read/write from files
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> N;

    H.resize( N );

    for ( int i = 0; i < N; i++ )
        cin >> H[ i ];

    V.resize( N );

    for ( int i = 0; i < N; i++ )
        cin >> V[ i ];

    int somma0 = 0;

    int somma1 = 0;

    int vel0 = INT32_MAX;

    int vel1 = INT32_MAX;

    for ( int i = 0; i < N; i++)
    {
        somma0 += H[ i ];
    }

    for ( int i = 0; i < N; i++)
    {
        somma1 += V[ i ];
    }

    if ( somma0 > somma1 )
        cout << "Verstappen" << endl;

    else 
        cout << "Hamilton" << endl;

    //vel0 = H[ 0 ];

    for ( int i = 0; i < N; i++)
    {
        if ( vel0 >= H[ i ] )
        {
            vel0 = H[ i ];
        }
    }

    //vel1 = V[ 0 ];

    for ( int i = 0; i < N; i++ )
    {
        if ( vel1 >= V[ i ] )
        {
            vel1 = V[ i ];
        }
    }

    if ( vel0 < vel1 )
        cout << "Hamilton" << endl;

    else 
        cout << "Verstappen" << endl;    
    
    return 0;
}