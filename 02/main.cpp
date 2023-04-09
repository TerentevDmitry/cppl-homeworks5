// Домашнее задание к занятию «Шаблоны и функторы»
// Задача 2. Таблица

#include <iostream>
#include "Table.h"

int main()
{
    setlocale(LC_ALL, "ru");

    Table <double> T1(4, 4);
    T1.printArr();
    T1.getSize();

    T1(0, 0) = 3.3;
    T1(1, 1) = 7.4;
    T1(2, 2) = 9.5;
    T1(3, 3) = 10.6;

    T1[3][4] = 99;

    T1.printArr();

    std::cout << T1(1, 1) << "\n";

    std::cout << T1[3][3] << "\n";

    std::cout << "\n\nHello World!\n\n";
};