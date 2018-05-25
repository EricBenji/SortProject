#/* time.cpp - functions for timing with high resolution using <chrono>
 *    from the C++11 standard library. 
 * Author: Eric Benjamin
 * URL: www.github.com/EricBenji
 * Date: 5/23/ 2018
 */

#include "time.h"

using namespace std::chrono;

high_resolution_clock::time_point begin;
bool isRunning = false;

// Begins a timer
void start_timer(){
    isRunning = true;
    begin = high_resolution_clock::now();
}

// Returns the number of ms passed since timer started
int ms_passed(){
    if(!isRunning) return -1;
    auto curr = high_resolution_clock::now();
    duration<double, std::milli> n = curr - begin;
    return (int) n.count();
}

// Returns the number of seconds since timer started
double end_timer(){
    if(!isRunning) return 0.0;
    auto curr = high_resolution_clock::now();
    duration<double, std::micro> n = curr - begin;
    return n.count();
}

