#include <iostream>
#include "Time.h"
#include "Tests.h"

using namespace std;

int main() {
    int option;

    setlocale(LC_ALL, "RU");

    cout << "�������� �����:\n";
    cout << "1. ���� ������ � ����������\n";
    cout << "2. ������ ������\n";
    cin >> option;

    if (option == 1) {
        try {
            Time t1, t2;

            // ���� �������
            cout << "������� ������ �����:\n";
            t1.input();
            cout << "������� ������ �����:\n";
            t2.input();
            cout << "\n������������ ������ ������������� ����������:\n";

            // ������� ��������
            ++t1;
            cout << "����� ����������� ++: " << t1 << "\n";

            t1--;
            cout << "����� ������������ --: " << t1 << "\n";

            // �������� ���������� ����
            int t1_new = t1;
            cout << "\n����� � ������� (������� ��������������): "
                << t1_new << "\n";

            cout << "������ �������� ������� (����� ��������������): "
                << (static_cast<bool>(t1) ? "true" : "false") << "\n";

            // �������� �������� ���������
            cout << "\n��������� �������:\n";
            cout << t1 << " < " << t2 << ": "
                << (t1 < t2 ? "true" : "false") << "\n";
            cout << t1 << " > " << t2 << ": "
                << (t1 > t2 ? "true" : "false") << "\n";

        }
        catch (const exception& e) {
            cerr << "������: " << e.what() << "\n";
        }
    }
    else if (option == 2) {
        runTests();
    }
    else {
        cerr << "�������� �����!\n";
    }

    return 0;
}
