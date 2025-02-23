#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Time {
private:
    short int hours;   // Часы (0-23)
    short int minutes; // Минуты (0-59)

public:
    Time();                            // Конструктор по умолчанию
    Time(short int h, short int m);    // Конструктор с параметрами
    Time(const Time& other);           // Конструктор копирования

    Time subtract(const Time& other) const; // Метод вычитания времени

    friend ostream& operator<<(ostream& os, const Time& t); // Перегрузка оператора вывода

    void input(); // Метод для ввода времени с клавиатуры

    // Унарные операции
    Time& operator++();   // Префиксный инкремент
    Time operator++(int); // Постфиксный инкремент
    Time& operator--();   // Префиксный декремент
    Time operator--(int); // Постфиксный декремент

    // Операции приведения типа
    operator int() const;       // Неявное преобразование в int (количество минут)
    explicit operator bool() const; // Явное преобразование в bool

    // Бинарные операции сравнения
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
};

#endif // TIME_H
