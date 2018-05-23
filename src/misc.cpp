#include "misc.h"

// toInteger converts a string literal to integer 
// while avoiding undefined behavior
int toInteger(char * input){
    if(input == nullptr) return -1;
    char * index = input;
    while( * index != '\0'){
        if( *index < '0' || *index > '9')
            return -1;
        index++;
    }
    return atoi(input);
}

// toFileName converts an integer to a string literal followed by ".txt"
std::string toFileName(int input){
    std::string toReturn = "";
    if (input == 0) toReturn = "0";
    while(input > 0)
    {
        toReturn = toReturn + (char) ('0' + (input % 10));
        input = input / 10;
    }
    return "../testfiles/" + toReturn + ".txt";
}

void generateFiles(int num_files, int range){
    std::ofstream out;

    std::srand(std::time(nullptr));

    std::cout << "Generating files..." << std::endl;

    for(int file = 0; file < num_files; file++)
    {
        out.open(toFileName(file).c_str());
        std::vector<int> * shuffle = new std::vector<int>();
        for(int i = 0; i < range; i++) 
            shuffle->push_back(i);
        for(int i = 0; i < shuffle->size(); i++){
            int swap = rand() % shuffle->size();
            int temp = (*shuffle)[swap];
            (*shuffle)[swap] = (*shuffle)[i];
            (*shuffle)[i] = temp;
        }
        for(int i = 0; i < shuffle->size(); i++)
            out << (*shuffle)[i] << std::endl;

        delete shuffle;
        out.close();
    }
}

int runTest(void (*sortFun)(std::vector<int> *), int x){
    std::ifstream in;
    std::string file = toFileName(x);
    in.open(file);
    std::vector<int> * data = new std::vector<int>();
    while(true){
        int n;
        in >> n;
        if( in.good() )
            data->push_back(n);
        else break;
    }
    start_timer();
    sortFun(data);
    int toReturn = end_timer();
    delete data;
    in.close();
    return toReturn;
}

