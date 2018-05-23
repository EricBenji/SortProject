#ifndef MISC_H
#define MISC_H

#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "time.h"

int toInteger(char * input);

std::string toFileName(int input);

void generateFiles(int num_files, int range);

int runTest(void (*sortFun)(std::vector<int> *), int x);

#endif // MISC_H
