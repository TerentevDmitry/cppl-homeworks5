// Домашнее задание к занятию «Шаблоны и функторы»
// Задача 1. Возведение в квадрат

#include <iostream>
#include <vector>
#include <cmath>

//template <class T>
//T degree(T xxx)
//{
//	return xxx * xxx;
//};

void degree(std::vector <int>* v1, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		v1->at(i) *= v1->at(i);
	};
};

/*template <class T1, class T2>
T1 degree(T1 vec1, T2 size)
{
	for (size_t i = 0; i < vec1.size(); i++)
	{
		vec1[i] = std::pow(vec1[i]);
	};

	return vec1;
};*/


int main()
{
	setlocale(LC_ALL, "ru");

	std::vector <int> v1 {-1, 2, 4, 7};

	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << "\t";
	};
	std::cout << std::endl << std::endl;

	//std::cout << degree <int>(2) << std::endl;
	//std::cout << degree <double>(3.5) << std::endl;

	degree(&v1, v1.size());

	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << "\t";
	};
	std::cout << std::endl << std::endl;


	//degree(v1);






};