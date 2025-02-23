#include <iostream>
#include "Time.h"
#include "Tests.h"

using namespace std;

int main() {
    int option;

    setlocale(LC_ALL, "RU");

    cout << "Выберите опцию:\n";
    cout << "1. Ввод данных с клавиатуры\n";
    cout << "2. Запуск тестов\n";
    cin >> option;

    if (option == 1) {
        try {
            Time t1, t2;

            // ввод времени
            cout << "Введите первое время:\n";
            t1.input();
            cout << "Введите второе время:\n";
            t2.input();
            cout << "\nДемонстрация работы перегруженных операторов:\n";

            // унарные операции
            ++t1;
            cout << "После префиксного ++: " << t1 << "\n";

            t1--;
            cout << "После постфиксного --: " << t1 << "\n";

            // пперации приведения типа
            int t1_new = t1;
            cout << "\nВремя в минутах (неявное преобразование): "
                << t1_new << "\n";

            cout << "Булево значение времени (явное преобразование): "
                << (static_cast<bool>(t1) ? "true" : "false") << "\n";

            // бинарные операции сравнения
            cout << "\nСравнение времени:\n";
            cout << t1 << " < " << t2 << ": "
                << (t1 < t2 ? "true" : "false") << "\n";
            cout << t1 << " > " << t2 << ": "
                << (t1 > t2 ? "true" : "false") << "\n";

        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << "\n";
        }
    }
    else if (option == 2) {
        runTests();
    }
    else {
        cerr << "Неверный выбор!\n";
    }

    return 0;
}
