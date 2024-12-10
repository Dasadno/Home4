#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>
void findMinMax(const int arr[], int size, int& min, int& max) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}


void findMaxMin(const int arr[], int size, int startMonth, int endMonth, int& minMonth, int& maxMonth) {
    if (startMonth < 0 || endMonth >= size || startMonth > endMonth) {
        std::cout << "������������ ��������!" << std::endl;
        return;
    }

    minMonth = startMonth;
    maxMonth = startMonth;

    for (int i = startMonth; i <= endMonth; i++) {
        if (arr[i] < arr[minMonth]) {
            minMonth = i;
        }
        if (arr[i] > arr[maxMonth]) {
            maxMonth = i;
        }
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int months = 12;
    int profits[months];
    for (int i = 0; i < months; i++) {
        std::cout << "������� ������� �� ����� #" << (i + 1) << ": ";
        std::cin >> profits[i];
    }

    int startMonth, endMonth;
    std::cout << "������� �������� (��������, 3 6 ��� ������� 3-6)\n\n";
    std::cout << "����: ";
    std::cin >> startMonth;
    std::cout << "����: ";
    std::cin >> endMonth;
    


    int minMonth, maxMonth;
    findMaxMin(profits, months, startMonth - 1, endMonth - 1, minMonth, maxMonth);

    std::cout << "������������ ������� � ������: " << (maxMonth + 1) << ", ����������� ������� � ������: " << (minMonth + 1) << std::endl;

    return 0;
}