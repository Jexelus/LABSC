//
// Created by danil on 22.01.2024.
//
#include <iostream>

using namespace std;

int findMinimum(int X, int Y, int L) {
    if (X == Y) {
        cout << "NOT!" << endl;
        return -1;
    }
    int P1 = (2 * L + X - Y - 1) / (X - Y);  // Минимум шагов для нечетного количества
    int P2 = (2 * (L - X) + X - Y - 1) / (X - Y) + 1;  // Минимум шагов для четного количества

    int result = (P1 < P2) ? P1 : P2;

    return result;
}

int main() {
    int X, Y, L;
    cin >> X >> Y >> L;
    int minimumSteps = findMinimum(X, Y, L);
    if (minimumSteps != -1) {
        cout << minimumSteps << endl;
    }
    return 0;
}
