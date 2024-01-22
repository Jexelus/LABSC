#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    string input, copy;
    int M;

    // Шаг 1: Считать входные данные
    cout << "Введите натуральное число: ";
    cin >> input;
    copy = input;

    cout << "Введите количество цифр для удаления (M): ";
    cin >> M;

    int index = 0;
    while (index < input.size() - 1 && M > 0) {
        if (input[index] > input[index + 1]) {
            copy.erase(index, 1);
            M--;
            index = 0;
        }
        else {
            index++;
        }
    }

    int k = 0;
    for (int i = 0; i < input.size(); i++) {
        if (copy[k] != input[i]) {
            cout << i + 1 << " ";
        }
        else {
            k++;
        }
    }

    if (copy.size() > input.size() - M) {
        auto count = copy.size() - (input.size() - M);
        auto ind = (input.size()) - count;
        //auto так как размер файла может превышать макс значения инта, не в нашем случае, но так правильно
        for (auto i = ind; i < input.size(); i++) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}