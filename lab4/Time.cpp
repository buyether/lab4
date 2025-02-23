#include "Time.h"
#include <limits>

Time::Time() : hours(0), minutes(0) {}

// конструктор с параметрами
Time::Time(short int h, short int m) {
    if (h < 0 || h > 23 || m < 0 || m > 59) {
        throw std::invalid_argument("Неверное значение времени! Часы должны быть от 0 до 23, а минуты от 0 до 59.");
    }
    hours = h;
    minutes = m;
}

// конструктор копирования
Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// метод вычитания времени
Time Time::subtract(const Time& other) const {
    int totalMinutes1 = hours * 60 + minutes;
    int totalMinutes2 = other.hours * 60 + other.minutes;

    int diffMinutes = totalMinutes1 - totalMinutes2;
    if (diffMinutes < 0) {
        diffMinutes += 24 * 60;
    }

    return Time(diffMinutes / 60, diffMinutes % 60);
}

// перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes;
    return os;
}

// метод ввода времени с клавиатуры
void Time::input() {
    std::cout << "Введите часы (0-23): ";
    std::cin >> hours;
    while (std::cin.fail() || hours < 0 || hours > 23) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите корректное значение часов (0-23): ";
        std::cin >> hours;
    }

    std::cout << "Введите минуты (0-59): ";
    std::cin >> minutes;
    while (std::cin.fail() || minutes < 0 || minutes > 59) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите корректное значение минут (0-59): ";
        std::cin >> minutes;
    }
}

// унарные операции

// префиксный инкремент (добавление минуты)
Time& Time::operator++() {
    ++minutes;
    if (minutes == 60) {
        minutes = 0;
        ++hours;
        if (hours == 24) {
            hours = 0;
        }
    }
    return *this;
}

// постфиксный инкремент (добавление минуты)
Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

// Префиксный декремент (вычитание минуты)
Time& Time::operator--() {
    if (minutes == 0) {
        minutes = 59;
        if (hours == 0) {
            hours = 23;
        }
        else {
            --hours;
        }
    }
    else {
        --minutes;
    }
    return *this;
}

// постфиксный декремент (вычитание минуты)
Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

// операции приведения типа

// неявное преобразование в int (количество минут)
Time::operator int() const {
    return hours * 60 + minutes;
}

// явное преобразование в bool
Time::operator bool() const {
    return hours != 0 || minutes != 0;
}

// бинарные операции сравнения

// меньше (<)
bool Time::operator<(const Time& other) const {
    return static_cast<int>(*this) < static_cast<int>(other);
}

// больше (>)
bool Time::operator>(const Time& other) const {
    return static_cast<int>(*this) > static_cast<int>(other);
}
