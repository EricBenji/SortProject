#include "sort.h"

int time_out = ~(1 << 31);
bool over_time = false;

int set_time_out(int ms){
    time_out = ms;
}

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

void merge(std::vector<int> * data){
    over_time = false;
    merge(data,0,data->size());
}

void quick(std::vector<int> * data, int pivot){
    if(data->size() < MIN_QUICK_SORT_SIZE){
        selection(data);
        return;
    }
    std::vector<int> * small = new std::vector<int> ();
    std::vector<int> * large = new std::vector<int> ();
    for(int i = 0; i < data->size(); i++){
        if(data->at(i) < pivot) small->push_back(data->at(i));
        else large->push_back(data->at(i));
    }
    if(small->size() > 0)
        quick(small, small->at(rand() % small->size()));
    if(large->size() > 0)
        quick(large, large->at(rand() % large->size()));
    for(int i = 0; i < small->size(); i++)
        data->at(i) = small->at(i);
    for(int j = 0; j < large->size(); j++)
        data->at(small->size() + j) = large->at(j);
    delete small;
    delete large;
}

void quick(std::vector<int> * data){
    over_time = false;
    int p = rand() % data->size();
    quick(data,data->at(p));
}

int num_digits(int in){
    int toReturn = 0;
    while( in != 0){
        in = in / 10;
        toReturn++;
    }
    return toReturn;
}

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
}

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
}

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
}

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
}

void heap(std::vector<int> * data){
    std::priority_queue<int> * pq = new std::priority_queue<int> ();
    for(int i = 0; i < data->size(); i++) pq->push(data->at(i));
    for(int i = data->size() - 1; i >= 0; i--) {
        int curr = pq->top();
        pq->pop();
        data->at(i) = curr;
    }
}



