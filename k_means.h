#pragma once
#ifndef K_MEANS_H_
#define K_MEANS_H_

#include <fstream> 
#include <iostream> 
#include "list.h"
#include <cmath>
#include <ctime>
using namespace std;
const int max_iterations = 100; //максимальное количество итераций

struct rgb  //пиксель
{ 
	double r; //красный
	double g; // зеленый
	double b; // синий
};

class K_means
{
public:
	List<rgb> pixcel;        //вектор пикселей соответствия
	int q_klaster;           //количество кластеров
	int k_pixcel;            //количество пикселей
	List<rgb> centr;         //центры кластеризации

	K_means(int n, rgb* mas, int n_klaster); //для инициализации пикселей из массива
	void identify_centers(); //метод случайного выбора начальных центров

	inline double compute(rgb k1, rgb k2); //встроенные методы для расчета расстояния между пикселями и пересчета центров соответственно
	inline double compute_s(double a, double b); // среднее 
	void clustering(ostream & os); //метод кластеризации	
	friend ostream & operator<<(ostream & os,  K_means & k); //перегружений оператор << 
	void fill(List<int> a,int sz, int num); // заполнеие векторов

	~K_means(); //деструктор
};

#endif // !K_MEANS_H_



