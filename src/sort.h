/* sort.h - The header file for sort.cpp. Sort contains a variety
 *     of sorting algorithms to sort a vector of integers.
 * Author: Eric Benjamin
 * URL: www.github.com/EricBenji
 * Date: 5/23/ 2018
 */
#ifndef SORT_H
#define SORT_H
#include <vector>
#include <queue>
#include <cmath> 
#include <cstdlib>
#include <iostream>

// The smallest array for which the quicksort algorithm will 
// resort to an O(n^2) algorithm - selection sort by default
#define MIN_QUICK_SORT_SIZE 2 

// Set the amount of time given to each algorithm 
// TODO
//int set_time_out(int ms);

// Mergesort algorithm -- O(nlogn)
void merge(std::vector<int> * data);

// Quicksort algorithm -- O(nlogn)
void quick(std::vector<int> * data);

// Least Significant Digit Radixsort algorithm - O(kn)
void radix(std::vector<int> * data);

// Bubblesort algorithm -- O(n^2)
void bubble(std::vector<int> * data);

// Cocktail Shaker sort algorithm -- O(n^2)
void shaker(std::vector<int> * data);

// Selection sort algorithm -- O(n^2)
void selection(std::vector<int> * data);

// Heapsort algorithm -- O(nlogn)
void heap(std::vector<int> * data);

#endif // SORT_H
