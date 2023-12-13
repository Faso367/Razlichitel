// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//#include "RO.h"

#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include<unordered_set>


using namespace std;
using uint = uint32_t;


class RO
{
public:
	vector<uint> requests;
	vector<uint> responces;
	RO() {
		requests.resize(0);
		responces.resize(0);
		/*GRU(x);*/
	};

	~RO() {
		requests.clear();
		responces.clear();
	};


	inline uint GRU() {
		uint r;
		r = (uint)(rand() % 2048);
		r = r * 2048;
		r += (uint)(rand() % 2048);
		r = r * 1024;
		r += (uint)(rand() % 1024);
		return r;
	};

	uint MyRand(uint min, uint max) {
		return min + (rand() % static_cast<int>(max - min + 1));
	};

	uint work(uint x);
};

uint RO::work(uint x) {
	uint y;
	for (int i = 0; i < requests.size(); i++) {
		if (x == requests[i]) {
			y = responces[i];
			return y;
		}
	}
	requests.push_back(x);
	y = GRU();
	responces.push_back(y);
	return y;
};

//uint PRF::work(uint x) {
unsigned int PRF(unsigned int x) {
	unsigned int y;

	const unsigned int A = 0x1234b123;
	const unsigned int B = 0x712a7b96;
	const unsigned int C = 0x7518ad81;
	const unsigned int key = 0x7518abc8;

	for (int i = 0; i < 4; i++) {
		//y = (key * (x + A) >> i) + (((key ^ C) + B >> 20) + x + 91750) * (i * C + A >> 16);

		y = (key * (x + 0x1234b123) >> i) + (((key ^ 0x7518ad81) + 0x712a7b96 >> 20) + x + 91750) * (i * 0x7518ad81 + 0x1234b123 >> 16);
	}

	return y;
};


int main() {

	unsigned int max = 0;
	unsigned int min = 4000000000;

	for (int j = 0; j < 20; j++) {

		uint count = 0;
		uint kol_vizovov = 0;
		uint min_i = 0;

		for (unsigned int i = 0; i < 300; i += 1) {

			unsigned int result = PRF(i);
			if (max < result)
				max = result;

			if (min > result)
				min = result;
			RO* d = new RO();
			uint z = d->GRU();


			if (size(to_string(z)) < size(to_string(result)))
				count++;

			kol_vizovov++;

			d->~RO();
		}
		std::cout << "Middle:" << static_cast<double>(static_cast<double>(count) / static_cast<double>(kol_vizovov)) << endl;
	}
}