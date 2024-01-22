//
// Created by danil on 22.01.2024.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int number)
{
    if (number <= 1)
        return false;

    if (number == 2)
        return true;

    if (number % 2 == 0)
        return false;

    for (int i = 3; i * i <= number; i += 2)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin)
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        return 1;
    }

    int kol_chis;
    fin >> kol_chis;

    vector<int> numbers(kol_chis);
    for (int i = 0; i < kol_chis; i++)
    {
        fin >> numbers[i];
    }

    vector<int> prime_factors(1000, 0);

    for (int i = 0; i < kol_chis; i++)
    {
        int chis = numbers[i];

        for (int j = 2; j <= chis; j++)
        {
            while (chis % j == 0)
            {
                if (isPrime(j))
                {
                    prime_factors[j]++;
                }
                chis = chis / j;
            }
        }
    }

    int proiz = 1;
    for (int i = 0; i < prime_factors.size(); i++)
    {
        if (prime_factors[i] > 0)
        {
            cout << i << " --> " << prime_factors[i] << endl;
            proiz = (prime_factors[i] % 10) * (proiz % 10);
        }
    }

    cout << "Произведение последних цифр степеней делителей: " << proiz % 10 << endl;

    return 0;
}
