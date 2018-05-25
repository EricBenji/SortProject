/* misc.h - Header file for misc.cpp which holds I/O helper functions 
 *     for main.cpp which serves as a driver for the Sort project. 
 *     The Sort project sorts a series of test files with various sorting
 *     algorithms and outputs the times.
 *
 * Author: Eric Benjamin
 * URL: www.github.com/EricBenji
 * Date: 5/23/ 2018
 */

#ifndef MISC_H
#define MISC_H

#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "time.h"

// FILE_PATH is the location of the test files
#define FILE_PATH "testfiles/"

// Prints the correct command line usage
void printUsage();

// Converts a string literal into an integer
int toInteger(char * input);

// Converts an index into its corresponding testfile name
std::string toFileName(int input);

// Creates the randomized testfiles to be sorted
// The test files contain all integers between 0 and range
void generateFiles(int num_files, int range);

// Tests the function sortFun on testfile x
int runTest(void (*sortFun)(std::vector<int> *), int x);

#endif // MISC_H
