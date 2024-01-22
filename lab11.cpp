#include <iostream>
using namespace std;

bool pal(int le, int ri, int* s) {
    int i = le;
    int j = ri;
    bool f = true;

    while ((i <= j) && (f)) {
        if (s[i] != s[j]) {
            f = false;
        }
        else {
            i++;
            j--;
        }
    }

    return f;
}

int main()
{
    int n, r = 1;
    bool fk = true;
    setlocale(LC_ALL, "Russian");

    cout << "Размер массива: ";
    cin >> n;

    int* m = new int[n];

    cout << "Enter " << n << " Числа для массива: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
    }

    if (pal(0, n - 1, m))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;

        while ((r <= n - 1) && (fk)) {
            if (!pal(r, n - 1, m)) {
                r++;
            }
            else
            {
                cout << r << endl;

                for (int j = r - 1; j >= 0; j--)
                {
                    cout << m[j] << " ";
                }

                fk = false;
            }
        }

        delete[] m;

        return 0;
    }
}
