#include "Time.h"
#include <limits>

Time::Time() : hours(0), minutes(0) {}

// ����������� � �����������
Time::Time(short int h, short int m) {
    if (h < 0 || h > 23 || m < 0 || m > 59) {
        throw std::invalid_argument("�������� �������� �������! ���� ������ ���� �� 0 �� 23, � ������ �� 0 �� 59.");
    }
    hours = h;
    minutes = m;
}

// ����������� �����������
Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// ����� ��������� �������
Time Time::subtract(const Time& other) const {
    int totalMinutes1 = hours * 60 + minutes;
    int totalMinutes2 = other.hours * 60 + other.minutes;

    int diffMinutes = totalMinutes1 - totalMinutes2;
    if (diffMinutes < 0) {
        diffMinutes += 24 * 60;
    }

    return Time(diffMinutes / 60, diffMinutes % 60);
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes;
    return os;
}

// ����� ����� ������� � ����������
void Time::input() {
    std::cout << "������� ���� (0-23): ";
    std::cin >> hours;
    while (std::cin.fail() || hours < 0 || hours > 23) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������! ������� ���������� �������� ����� (0-23): ";
        std::cin >> hours;
    }

    std::cout << "������� ������ (0-59): ";
    std::cin >> minutes;
    while (std::cin.fail() || minutes < 0 || minutes > 59) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������! ������� ���������� �������� ����� (0-59): ";
        std::cin >> minutes;
    }
}

// ������� ��������

// ���������� ��������� (���������� ������)
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

// ����������� ��������� (���������� ������)
Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

// ���������� ��������� (��������� ������)
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

// ����������� ��������� (��������� ������)
Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

// �������� ���������� ����

// ������� �������������� � int (���������� �����)
Time::operator int() const {
    return hours * 60 + minutes;
}

// ����� �������������� � bool
Time::operator bool() const {
    return hours != 0 || minutes != 0;
}

// �������� �������� ���������

// ������ (<)
bool Time::operator<(const Time& other) const {
    return static_cast<int>(*this) < static_cast<int>(other);
}

// ������ (>)
bool Time::operator>(const Time& other) const {
    return static_cast<int>(*this) > static_cast<int>(other);
}
