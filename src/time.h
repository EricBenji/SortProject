/* time.h - The header file for time.cpp. time.cpp contains 
 *    functions for timing with high resolution using <chrono>
 *    from the C++11 standard library. 
 * Author: Eric Benjamin
 * URL: www.github.com/EricBenji
 * Date: 5/23/ 2018
 */

#ifndef TIME_H
#define TIME_H
#include <chrono>
#include <ratio>

void start_timer();
int ms_passed();
double end_timer();

#endif // TIME_H
