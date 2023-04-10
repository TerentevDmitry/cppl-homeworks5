// Домашнее задание к занятию «Шаблоны и функторы»
// Задача 2. Таблица

#include <iostream>
#include "Table.h"

int main()
{
    setlocale(LC_ALL, "ru");

    Table <double> T1(7, 7);
    
    T1.printArr();
    
    T1.getSize();
    
    
    try
    {
        T1(0, 0) = 3.3;
        T1(1, 1) = 7.4;
        T1(2, 2) = 9.5;
        T1(5, 4) = 10.6;
        T1[5][5] = 99;
        T1[5][6] = 88;

        T1.printArr();

        std::cout << T1(1, 1) << "\n";
        std::cout << T1[5][5] << "\n";

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    };



    std::cout << "\n\nHello World!\n\n";
};