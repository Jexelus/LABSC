#include <iostream>
#include <cmath>
#include <ctime>

int sum_numb(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

long long brute_force(int k) {
    long long kol = 0, s1, s2, gran = pow(10, k / 2);
    for (long long i = 1; i < gran; i++) {
        s1 = sum_numb(i);
        for (long long j = 0; j < gran; j++) {
            s2 = sum_numb(j);
            if (s1 == s2) kol++;
        }
    }
    return kol;
}

long long greedy(int k) {
    int n = pow(10, k / 2) - 1;
    int max_sum = sum_numb(n);
    int* m = new int[max_sum + 1](); // Инициализация массива нулями

    for (int i = 0; i <= n; i++) {
        int ind = sum_numb(i);
        m[ind]++;
    }

    long long luck = 0;
    for (int i = 0; i <= max_sum; i++) {
        luck += static_cast<long long>(m[i]) * m[i];
    }

    delete[] m;
    return luck - 1;
}

long long upgrade1(int k) {
    int n = pow(10, k / 2) - 1;
    int max_sum = sum_numb(n);

    auto* m = new long long[max_sum + 1]();
    for (int i = 0; i <= n - 9; i += 10) {
        int start = sum_numb(i);
        for (int j = 0; j <= 9; j++) {
            m[start + j]++;
        }
    }

    long long luck = 0;
    for (int i = 0; i <= max_sum; i++) {
        luck += m[i] * m[i];
    }

    delete[] m;
    return luck - 1;
}

long long upgrade2(int k) {
    long long n = pow(10, k / 2) - 1;
    int max_sum = sum_numb(n);
    int middle = (max_sum + 1) / 2;

    auto* m = new long long[middle + 1]();
    for (int i = 0; i <= n - 9; i += 10) {
        int start = sum_numb(i);
        int j = 0;
        while (j <= 9 && (start + j) <= middle) {
            m[start + j]++;
            j++;
        }
    }

    long long luck = 0;
    if ((max_sum + 1) % 2 == 1) {
        for (int i = 0; i < middle; i++)
            luck += 2 * m[i] * m[i];

        luck += m[middle] * m[middle];
    }
    else {
        for (int i = 0; i < middle; i++)
            luck += 2 * m[i] * m[i];
    }

    delete[] m;
    return luck - 1;
}

int main() {
    setlocale(LC_ALL, "rus");
    time_t t1, t2, t3, t4, t5;
    int k;
    std::cin >> k;

    t1 = clock();
    std::cout << "k = " << k << std::endl;
    std::cout << "Алгоритм полного перебора. Ответ: " << brute_force(k);
    t2 = clock();
    std::cout << " Время: " << static_cast<float>(t2 - t1) / CLOCKS_PER_SEC << std::endl;

    std::cout << "Жадный алгоритм. Ответ: " << greedy(k);
    t3 = clock();
    std::cout << " Время: " << static_cast<float>(t3 - t2) / CLOCKS_PER_SEC << std::endl;

    std::cout << "Алгоритм с усилением №1. Ответ: " << upgrade1(k);
    t4 = clock();
    std::cout << " Время: " << static_cast<float>(t4 - t3) / CLOCKS_PER_SEC << std::endl;

    std::cout << "Алгоритм с усилением №2. Ответ: " << upgrade2(k);
    t5 = clock();
    std::cout << " Время: " << static_cast<float>(t5 - t4) / CLOCKS_PER_SEC << std::endl;

    return 0;
}
