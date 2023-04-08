// Домашнее задание к занятию «Шаблоны и функторы»
// Задача 1. Возведение в квадрат

#include <iostream>
#include <vector>
//#include <cmath>
#include <string>

//Шаблон для Возведение в квадрат числа
template <class T>
T degree(T num)
{
	return num * num;
};


//Шаблон для string
template <>
std::string degree(std::string num)
{
	return num;
};

//Шаблон для Возведение в квадрат вектора
template <class T>
void degree(T* v1)
{
	for (size_t i = 0; i < v1->size(); i++)
	{
		v1->at(i) *= v1->at(i);
	};
};

//Печать вектора
void printVector(std::vector<int>* v1)
{
	for (size_t i = 0; i < v1->size(); i++)
	{
		std::cout << v1->at(i) << "\t";
	};
};



int main()
{
	setlocale(LC_ALL, "ru");

	
	std::cout << "degree <string>(a) = " << degree <std::string>("Privet") << std::endl;
	std::cout << "degree <int>(a) = " << degree <int>(2) << std::endl;
	std::cout << "degree <double>(b) = " << degree <double>(3.5) << std::endl;

	std::vector <int> v1{ -1, 2, 4, 7 };

	printVector(&v1);
	degree(&v1);
	std::cout << std::endl << "Вектор в квадрате: " << std::endl;
	printVector(&v1);

	std::cout << std::endl;
	std::cout << std::endl;
};