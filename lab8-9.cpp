#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

int brute_force(int L, int U, int R, int D, int** mas) {
    int sum = 0;
    for (int i = U - 1; i < D; i++) {
        for (int j = L - 1; j < R; j++) {
            sum += mas[i][j];
        }
    }
    return sum;
}

void input_matrix(int N, int M, int** mas) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mas[i][j];
        }
    }
}

void print_matrix(int N, int M, int** mass) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}

void free_memory(int** temp, int N) {
    for (int i = 0; i < N; i++)
        delete[] temp[i];
    delete[] temp;
}

void generate_dop(int N, int M, int** dop_mas, int** mas_date) {
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++) {
            if ((i == 0) || (j == 0)) dop_mas[i][j] = 0;
            else dop_mas[i][j] = dop_mas[i - 1][j] + dop_mas[i][j - 1] - dop_mas[i - 1][j - 1] + mas_date[i - 1][j - 1];
        }
}

int efficient_algorithm(int** dop_mas, int** mas_date, int L, int U, int R, int D) {
    int sum = dop_mas[D][R] - dop_mas[U - 1][R] - dop_mas[D][L - 1] + dop_mas[U - 1][L - 1];
    return sum;
}

int main() {
    system("if exist output* (del output*)");
    setlocale(LC_ALL, "rus");
    string name_in, name_out;
    int** mass;
    int** dop_mass;
    time_t t1, t2, t3, t4;
    int count_tests, N, M, K, L, U, R, D, number;
    cout << "Введите количество тестов, которые должны быть сгенерированы" << endl;
    cin >> count_tests;
    cout << "Введите номер алгоритма:" << endl
        << "1. Полный перебор" << endl
        << "2. Эффективный алгоритм" << endl;

    while (true) {
        cin >> number;
        switch (number) {
        case 1:
        {
            for (int i = 1; i <= count_tests; i++) {
                t1 = clock();
                cout << "Введите N и M:" << endl;
                cin >> N >> M;
                mass = new int* [N];
                for (int i = 0; i < N; ++i)
                    mass[i] = new int[M];

                cout << "Введите элементы матрицы:" << endl;
                input_matrix(N, M, mass);

                cout << "Введите K:" << endl;
                cin >> K;

                cout << "Введите запросы (L U R D):" << endl;
                for (int j = 0; j < K; j++) {
                    cin >> L >> U >> R >> D;
                    cout << brute_force(L, U, R, D, mass) << " ";
                }

                t2 = clock();
                cout << endl << "" << endl;
                cout << "ВРЕМЯ РАБОТЫ АЛГОРИТМА ПОЛНОГО ПЕРЕБОРА: " << fixed << (float)(t2 - t1) / CLOCKS_PER_SEC << endl << "" << endl;
                free_memory(mass, N);
            }
            break;
        }

        case 2:
        {
            for (int i = 1; i <= count_tests; i++) {
                t3 = clock();
                cout << "Введите N и M:" << endl;
                cin >> N >> M;
                mass = new int* [N];
                dop_mass = new int* [N];
                for (int i = 0; i < N; ++i) {
                    mass[i] = new int[M];
                    dop_mass[i] = new int[M];
                }

                cout << "Введите элементы матрицы:" << endl;
                input_matrix(N, M, mass);

                generate_dop(N, M, dop_mass, mass);

                cout << "Введите K:" << endl;
                cin >> K;

                cout << "Введите запросы (L U R D):" << endl;
                for (int i = 0; i < K; i++) {
                    cin >> L >> U >> R >> D;
                    cout << efficient_algorithm(dop_mass, mass, L, U, R, D) << " ";
                }

                t4 = clock();
                cout << "" << endl << "" << endl;
                cout << "ВРЕМЯ РАБОТЫ ЭФФЕКТИВНОГО АЛГОРИТМА: " << fixed << (float)(t4 - t3) / CLOCKS_PER_SEC << endl;
                free_memory(mass, N);
                free_memory(dop_mass, N);
            }
            break;
        }
        }
    }
    return 0;
}
