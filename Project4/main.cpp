#include <iostream>
#include <Windows.h>

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

int sumOfElementsLessThan(const int arr[], int size, int threshold) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < threshold) {
            sum += arr[i];
        }
    }
    return sum;
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

    srand(time(NULL));

    const int size1 = 10;
    int arr1[size1] = { 15, 22, 3, 42, 7, 56, 12, 8, 2, 30 };
    int min, max;
    findMinMax(arr1, size1, min, max);
    std::cout << "������������ �������: " << max << ", ����������� �������: " << min << std::endl;

    const int size = 10;
    int arr[size];

    int randomMin, randomMax;
    
    std::cout << "������� �������� ��� ���������� ���������� ������� (min max)\n";
    std::cout << "����: ";
    std::cin >> randomMin;
    std::cout << "����: ";
    std::cin >> randomMax;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (randomMax - randomMin + 1) + randomMin;
    }

    std::cout << "��������������� ������: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    std::cout << "������� �����: ";
    int threshold;
    std::cin >> threshold;

    int sum = sumOfElementsLessThan(arr, size, threshold);
    std::cout << "����� ���������, ������ ��������� �����: " << sum << '\n';

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