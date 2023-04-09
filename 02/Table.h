#pragma once
#include <iostream>
#include <array>




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
		return arr1_[i][j];
	};

	class Proxy
	{
	public:
		Proxy(T* _array) : _array(_array) { }

		T operator[](int index) {
			return _array[index];
		}
	private:
		T* _array;

	};

	Proxy operator[](int index) 
	{
		
		
		return Proxy(arr1_[index]);
	};

	void getSize() 
	{
		std::cout << "Size: " << arrSizeRow_ << " x " << arrSizeCol_ << std::endl << std::endl;
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