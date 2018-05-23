#ifndef SORT_H
#define SORT_H
#include <vector>
#include <queue>
#include <cmath> 
#include <cstdlib>
#include <iostream>

#define MIN_QUICK_SORT_SIZE 8

int set_time_out(int ms);

void merge(std::vector<int> * data);

void quick(std::vector<int> * data);

void radix(std::vector<int> * data);

void bubble(std::vector<int> * data);

void shaker(std::vector<int> * data);

void selection(std::vector<int> * data);

void heap(std::vector<int> * data);

#endif // SORT_H
