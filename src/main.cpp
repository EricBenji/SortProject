#include "sort.h"
#include "misc.h"

#define EXPECTED_NUM_ARGS 2

typedef void (*sort_function_ptr) (std::vector<int> *);
typedef std::pair<sort_function_ptr, std::string> sort_name;

int main(int argc, char * argv[]){

    // Check for correct usage
    if( argc < EXPECTED_NUM_ARGS + 1){
        std::cout << "Correct usage: ./sort range num_tests time_out_ms(optional)" << std::endl;
        return -1;
    }

    for(int i = 1; i <= EXPECTED_NUM_ARGS; i++){
        if( toInteger(argv[i]) == -1 ){
            std::cout << "Arguments must be integers" << std::endl;
            std::cout << "Correct usage: ./sort range num_tests" << std::endl;
            return -2;
        } 
    }

    int range = toInteger(argv[1]);
    int num_tests = toInteger(argv[2]); 
    int time_out = argc >= EXPECTED_NUM_ARGS + 1 ? toInteger(argv[3]):10000;
    generateFiles(num_tests, range);

    sort_name sf [] = {
        std::make_pair(&heap,"HEAP"),
        std::make_pair(&merge, "MERGE"),
        std::make_pair(&quick, "QUICK"),
        std::make_pair(&radix, "RADIX"),
        std::make_pair(&shaker, "SHAKER"),
        std::make_pair(&selection, "SELECTION"),
        std::make_pair(&bubble, "BUBBLE")
    };

    for(int i = 0; i < sizeof(sf) / sizeof(sort_name); i++){
        std::cout << sf[i].second << ": ";
        long total = 0;
        for(int test = 0; test < num_tests; test++){
            total += (long) runTest(sf[i].first,test);
        }
        total = (long) total / num_tests;
        double d_total = (double) total * ((double) std::micro::num / std::micro::den);
        std::cout << d_total << std::endl;
    }

    return 0;
}
