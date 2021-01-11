#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "checkWord.h"

using namespace std;

int main() {
    clock_t tStart = clock();
    string test;
    ifstream MyFile("./Reuters-21578/reut2-000.txt");

    while(MyFile >> test){
       checkWord(test);
    }

    MyFile.close();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}
