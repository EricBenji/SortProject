#include "time.h"

using namespace std::chrono;

high_resolution_clock::time_point begin;

void start_timer(){
    begin = high_resolution_clock::now();
}

int ms_passed(){
    return 0;
}

double end_timer(){
    auto curr = high_resolution_clock::now();
    duration<double, std::micro> n = curr - begin;
    return n.count();
}

