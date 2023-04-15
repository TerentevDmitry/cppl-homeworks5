#pragma once
#include <iostream>
#include <array>
#include <exception>

template<class T>
class Table
{
private:
	T** arr1_;
	int arrSizeRow_ = 0;
	int arrSizeCol_ = 0;
	int size_ = 0;

public:
	Table(int arrSizeRow, int arrSizeCol) : arrSizeRow_{arrSizeRow}, arrSizeCol_(arrSizeCol)
	{
		arr1_ = new T* [arrSizeRow_] {};
		for (int i = 0; i < arrSizeRow_; i++)
		{
			arr1_[i] = new T[arrSizeCol_] {};
		}
		std::cout << "Конструктор " << this << std::endl;
	};
	
	T& operator()(int i,int j)
	{
		if (i >= arrSizeRow_ || i < 0) throw std::out_of_range("out_of_range index i(one)");
		if(j >= arrSizeCol_ || j < 0) throw std::out_of_range("out_of_range index j(one)");

		return arr1_[i][j];
	};

	class ArrayRow
	{
	public:
		ArrayRow(T* arrayRow_, const int arrSizeCol) : arrayRow_(arrayRow_), arrSizeCol_(arrSizeCol) { }

		T& operator[](int i)
		{
			if (i >= arrSizeCol_ || i < 0) throw std::out_of_range("out_of_range index j(two)");
			return arrayRow_[i];
		}
	private:
		T* arrayRow_;
		int arrSizeCol_ = 0;
	};

	ArrayRow operator[](const int i) const
	{
		if (i >= arrSizeRow_ || i < 0) throw std::out_of_range("out_of_range index i(one)");

		return ArrayRow(arr1_[i], arrSizeCol_);
	};

	//Удаление функции копирования одного объекта в другой
	//Table& operator=(const Table& other) = delete;

	Table& operator=(Table& other)
	{
		if (this != &other)
		{
			arrSizeCol_ = other.arrSizeCol_;
			arrSizeRow_ = other.arrSizeRow_;

			delete[] arr1_;

			//создаем новый массив
			
			arr1_ = new T * [arrSizeRow_] {};
			for (int i = 0; i < arrSizeRow_; i++)
			{
				arr1_[i] = new T[arrSizeCol_]{};
			}
			std::cout << "Конструктор " << this << std::endl;

			//копируем элементы из старого массива в новый
			for (size_t i = 0; i < arrSizeRow_; i++)
			{
				for (size_t j = 0; j < arrSizeCol_; j++)
				{
					arr1_[i][j] = other.arr1_[i][j];
				}
			}
			std::cout << this << " - Оператор копирования SmartArray::operator=()\n\n";

			return *this;
		};
		std::cout << "Вы пытаетесь скопировать объект сам в себя\n";
		return *this;
	};

	void getSize()
	{
		std::cout << "Size Of Array: " << arrSizeRow_ << " x " << arrSizeCol_ << std::endl << std::endl;
	};

	void printArr() 
	{
		for (size_t i = 0; i < arrSizeRow_; i++)
		{
			for (size_t j = 0; j < arrSizeCol_; j++)
			{
				std::cout << arr1_[i][j] << '\t';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	};

	~Table()
	{
		delete[] arr1_;
		arr1_ = nullptr;
		std::cout << "Деструктор " << this << std::endl;
	}
};