#include <iostream>
#include <fstream>
#include <ctime> // Вместо <time.h>
using namespace std;

bool finder(long long int a, long long int b, long long int c, long long int d)
{
    bool result = false;
    while (a * b != 0 && !(result) && (a >= c) && (b >= d))
        if (a > b) {
            a = a % b;
            if (b == d)
                if ((c - a % b) % b == 0) result = true;
        }
        else {
            b = b % a;
            if (a == c)
                if ((d - b % a) % a == 0) result = true;
        }
    return result;
}

int main()
{
    double time_spent = 0.0;
    clock_t begin, end;

    long long int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    begin = clock();
    if (finder(a, b, c, d))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    end = clock(); 
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime is %f seconds", time_spent);
    return 0;
}
