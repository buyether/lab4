#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Time {
private:
    short int hours;   // ���� (0-23)
    short int minutes; // ������ (0-59)

public:
    Time();                            // ����������� �� ���������
    Time(short int h, short int m);    // ����������� � �����������
    Time(const Time& other);           // ����������� �����������

    Time subtract(const Time& other) const; // ����� ��������� �������

    friend ostream& operator<<(ostream& os, const Time& t); // ���������� ��������� ������

    void input(); // ����� ��� ����� ������� � ����������

    // ������� ��������
    Time& operator++();   // ���������� ���������
    Time operator++(int); // ����������� ���������
    Time& operator--();   // ���������� ���������
    Time operator--(int); // ����������� ���������

    // �������� ���������� ����
    operator int() const;       // ������� �������������� � int (���������� �����)
    explicit operator bool() const; // ����� �������������� � bool

    // �������� �������� ���������
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
};

#endif // TIME_H
