/* main.cpp - serves as a driver for the Sort project. 
 *     The Sort project sorts a series of test files with various sorting
 *     algorithms and outputs the times.
 *
 * Author: Eric Benjamin
 * URL: www.github.com/EricBenji
 * Date: 5/23/ 2018
 */
#include "sort.h"
#include "misc.h"

#define EXPECTED_NUM_ARGS 2 

// sort_function_ptr contains a pointer to one of the sort functions in sort.cpp
typedef void (*sort_function_ptr) (std::vector<int> *);
 
// sort_name is a pair containing a pointer to a sort function and its name
typedef std::pair<sort_function_ptr, std::string> sort_name;

int main(int argc, char * argv[]){

    // Check for correct usage
    if( argc < EXPECTED_NUM_ARGS + 1){
        printUsage();
        return -1;
    }

    for(int i = 1; i <= EXPECTED_NUM_ARGS; i++){
        if( toInteger(argv[i]) == -1 ){
            std::cout << "Arguments must be integers" << std::endl;
            printUsage();
            return -2;
        } 
    }

    // The test files will contain the integers 0,1,...,range-1
    int range = toInteger(argv[1]);
   
    // The number of files to be generated
    int num_tests = toInteger(argv[2]); 

    // TODO
    // int time_out = argc >= EXPECTED_NUM_ARGS + 1 ? toInteger(argv[3]):10000;

    generateFiles(num_tests, range);

    // This is the list of sort functions in sort.cpp to be tested
    sort_name sf [] = {
        std::make_pair(&heap,"HEAP"),
        std::make_pair(&merge, "MERGE"),
        std::make_pair(&quick, "QUICK"),
        std::make_pair(&radix, "RADIX"),
        std::make_pair(&shaker, "SHAKER"),
        std::make_pair(&selection, "SELECTION"),
        std::make_pair(&bubble, "BUBBLE")
    };

    // Run the tests and print the average time for each
    for(int i = 0; i < sizeof(sf) / sizeof(sort_name); i++){
        std::cout << sf[i].second << ": ";
        long total = 0;
        for(int test = 0; test < num_tests; test++){
            total += (long) runTest(sf[i].first,test);
        }
        total = (long) total / num_tests;
        double toSec = ((double) std::micro::num / std::micro::den);
        double d_total = (double) total * toSec;
        std::cout << d_total << "s" << std::endl;
    }

    return 0;
}
