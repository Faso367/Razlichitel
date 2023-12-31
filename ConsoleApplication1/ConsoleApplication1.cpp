﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "RO.h"

// #pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <vector>
#include "RO.h"

// using namespace std;
using uint = uint32_t;




//uint PRF::work(uint x) {
unsigned int PRF(unsigned int x) {
	unsigned int y;

	uint A = 0x1234b123;
	uint B = 0x712a7b96;
	uint C = 0x7518ad81;
	uint key = 0x7518abc8;

	for (int i = 0; i < 4; i++) {
		//y = (key * (x + A) >> i) + (((key ^ C) + B >> 20) + x + 91750) * (i * C + A >> 16);

		y = (key * (x + 0x1234b123) >> i) + (((key ^ 0x7518ad81) + 0x712a7b96 >> 20) + x + 91750) * (i * 0x7518ad81 + 0x1234b123 >> 16);
	}

	return y;
};


int main() {

	setlocale(LC_ALL, "Russian");

	//uint max = 0;
	//uint min = 4000000000;
	double summa = 0;
	uint kol_vizovov = 1000;
	uint kol_checks = 1000;

	std::cout << "Пусть Вероятность это вероятность того," <<
    "что длина выхода из RO отличается от длины выхода из PRF : \n---------------------" << std::endl;

	srand(time(0));
	for (int j = 0; j < kol_checks; j++) {

		uint count = 0;
		uint min_i = 0;

		
		for (uint i = 0; i < kol_vizovov; i ++) {

			
			uint randomNumber = rand()%1024;
			uint result = PRF(randomNumber);

			//if (max < result)
			//	max = result;

			//if (min > result)
			//	min = result;

			RO* d = new RO();
			uint z = GRU();


			if (std::size(std::to_string(z)) < std::size(std::to_string(result)))
				count++;

		}

		double ratio = static_cast<double>(static_cast<double>(count) / static_cast<double>(kol_vizovov));
		summa += ratio;

		std::cout << "Вероятность: " << ratio << std::endl;
		
	}

	std::cout << "Средняя вероятность того, что длина выхода" <<
		"из RO отличается от длины выхода из PRF : \n" << static_cast<double>(static_cast<double>(summa) / static_cast<double>(kol_checks));
}