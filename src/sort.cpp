/* sort.cpp - Contains implementations of a variety
 *     of sorting algorithms to sort a vector of integers.
 * Author: Eric Benjamin
 * URL: www.github.com/EricBenji
 * Date: 5/23/ 2018
 */

#include "sort.h"

// TODO
// int time_out = ~(1 << 31);
// bool over_time = false;

// Helper function to test a sorting algorithm when it's done running
bool isSorted(std::vector<int> * data){
    for(int i = 0; i < data->size() - 1; i++)
        if (data->at(i) > data->at(i+1)) {
            for(int j = 0; j < data->size(); j++)
                std::cout << data->at(j) << " " << std::endl;
            return false;
        }
    return true;
}

// TODO 
//int set_time_out(int ms){
//    time_out = ms;
//}

// Helper function for Mergesort algorithm - sorts a subarray of a vector
// data - vector to be sorted
// begin - first index of subarray to be sorted
// size - size of subarray to be sorted
void merge(std::vector<int> * data, int begin, int size){
    if (size == 1) return;
    int half = size / 2;
    int mid = begin + half;
    merge(data, begin,half);
    merge(data, mid, size - half);
    std::vector<int> * temp = new std::vector<int> ();
    int low = begin; 
    int high = mid;
    int curr = 0;
    while(curr != size){
        int next;
        if (low == mid)
            next = high++;
        else if (high == begin + size)
            next = low++;
        else if (data->at(low) <= data->at(high))
            next = low++;
        else
            next = high++;
        temp->push_back(data->at(next));
        curr++;
    }
    for(int i = begin; i < begin + size; i++)
        data->at(i) = temp->at(i - begin);
    delete temp;
}

// Mergesort algorithm -- O(nlogn)
// Split the vector in half, recursively sort the left and right side
void merge(std::vector<int> * data){
    merge(data,0,data->size());
    if (!isSorted(data)) std::cout << "FAIL MERGE" << std::endl;
}

// Helper function for quicksort algorithm - sorts a subarray of a vector
// data - vector to be sorted
// begin - first index of subarray to be sorted
// size - size of subarray to be sorted
void quick(std::vector<int> * data, int begin, int size){
    if(size == 0) return;
    if(size == 1) return;
    /*if(size < MIN_QUICK_SORT_SIZE){
        std::vector<int> * v = new std::vector<int> ();
        for(int i = begin; i < begin + size; i++)
            v->push_back(data->at(i));
        selection(v);
        for(int i = begin; i < begin + size; i++) 
            data->at(i) = v->at(i - begin);
        delete v;
        return;
    }*/
    int pivot = (begin + (rand() % size));
    pivot = data->at(pivot);
    int low = begin;
    int high = begin + size - 1;
    while (low < high) {
        while( low < high && data->at(low) < pivot)
            low++;
        while( low < high && data->at(high) >= pivot)
            high--;
        if (low < high){
            int temp = data->at(low);
            data->at(low) = data->at(high);
            data->at(high) = temp;
        }
    }
    quick(data, begin, low - begin);
    quick(data, low, begin + size - low);
}

// Quicksort algorithm - O(nlogn)
// Randomly choose a "pivot" from the vector and place all values
// smaller than the pivot to the left of all values larger than the pivot.
// Recursively sort the left and right sides until sorted.
void quick(std::vector<int> * data){
    quick(data,0,data->size());
    if (!isSorted(data)) std::cout << "FAIL QUICK" << std::endl;
}

// Helper function for Radixsort
// Returns number of decimal digits in integer in
int num_digits(int in){
    int toReturn = 0;
    while( in != 0){
        in = in / 10;
        toReturn++;
    }
    return toReturn;
}

// LSD Radix sort algorithm -- O(kn)
// This algorithm makes as many passes as there are digits in the smallest
// element. This is possible because the data type is discrete. The data 
// is put into ten groups based on their digits, beginning with the least 
// significant digit and increasing with each pass.
void radix(std::vector<int> * data){
    if(data->size() == 0) return;
    int upper_bound = data->at(0);
    for(int i = 0; i < data->size(); i++)
        if(data->at(i) > upper_bound) upper_bound = data->at(i);
    int passes = num_digits(upper_bound);
    for(int digit = 0; digit < passes; digit++){
        std::vector<int> * bucket  [ 10 ];
        for(int i = 0; i < 10; i++)
        bucket[i] = new std::vector<int> ();
        for(int i = 0; i < data->size(); i++){
            int entry = data->at(i);
            entry = entry / pow(10,digit);
            bucket[ entry % 10 ]->push_back(data->at(i));
        }
        int curr = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < bucket[i]->size(); j++)
                data->at(curr++) = bucket[i]->at(j);
            delete bucket[i];
        }
    }
    if (!isSorted(data)) std::cout << "FAIL RADIX" << std::endl;
}

// Bubble sort -- O(n^2)
// Ascend through the data, swapping each element with the element above it
// if it is larger than the one above it. Continue making passes this way 
// until the data is sorted. 
// Sidenote - Never use bubble sort on large data sets please
void bubble(std::vector<int> * data){
    bool sorted = false;
    int max = data->size();
    while( !sorted && max > 0){
        sorted = true;
        for(int i = 0; i < max - 1; i++){
            if(data->at(i) > data->at(i+1)){
                int temp = data->at(i);
                data->at(i) = data->at(i+1);
                data->at(i+1) = temp;  
                sorted = false;
            }
        }
        max--;
    }
    if (!isSorted(data)) std::cout << "FAIL BUBBLE" << std::endl;
}

// Cocktail Shaker sort -- O(n^2)
// Ascend through the data, making swaps as bubble sort would do. Then 
// descend back through the data, making swaps in a similar fashion. 
// Negilibly better than Bubble sort for large amounts of data
void shaker(std::vector<int> * data){
    bool sorted = false;
    int max = data->size();
    int min = 0;
    while( !sorted && max - min > 0){
        sorted = true;
        for(int i = min; i < max - 1; i++){
            if(data->at(i) > data->at(i+1)){
                int temp = data->at(i);
                data->at(i) = data->at(i+1);
                data->at(i+1) = temp;  
                sorted = false;
            }
        }
        max--;
        for(int i = max - 1; i >= min; i--){
            if(data->at(i) > data->at(i+1)){
                int temp = data->at(i);
                data->at(i) = data->at(i+1);
                data->at(i+1) = temp;  
                sorted = false;
            }
        }
        min++;
    }
    if (!isSorted(data)) std::cout << "FAIL SHAKER" << std::endl;
}

// Selection sort algorithm -- O(n^2)
// Linearly seach through the data to find the smallest element.
// Then search the data for the second smallest element, etc.
// Continually put the next smallest element on the front of the 
// unsorted elements until it is sorted.
void selection(std::vector<int> * data){
    int next = 0;
    while(next < data->size() - 1){
        int smallest = next;
        for(int i = next+1; i < data->size(); i++)
            if( data->at(i) < data->at(smallest)) smallest = i;
        int temp = data->at(smallest);
        data->at(smallest) = data->at(next);
        data->at(next) = temp;
        next++;
    }
    if (!isSorted(data)) std::cout << "FAIL SELECTION" << std::endl;
}

// Heapsort algorithm -- O(nlogn)
// Insert the elements into a heap one by one and then extract them
// one by one. Here a heap is implemented using std::priority_queue
void heap(std::vector<int> * data){
    std::priority_queue<int> * pq = new std::priority_queue<int> ();
    for(int i = 0; i < data->size(); i++) pq->push(data->at(i));
    for(int i = data->size() - 1; i >= 0; i--) {
        int curr = pq->top();
        pq->pop();
        data->at(i) = curr;
    }
    if (!isSorted(data)) std::cout << "FAIL HEAP" << std::endl;
}



