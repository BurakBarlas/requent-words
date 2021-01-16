//
// Created by Barlas on 1/12/2021.
//

#ifndef REQUENT_WORDS_HASHING_H
#define REQUENT_WORDS_HASHING_H

#include "HashMap.h"

using namespace std;

template<typename K>


int calculateHashValue(K word , int arraySize){

    unsigned int hashedWord = hash<K>{}(word);

    int address = hashedWord % arraySize;

    return address;
}

void openFileStopWords(){
    string word;
    int wordIndex;

    ifstream stopWords("stopwords.txt");

    while(stopWords >> word){
        wordIndex = calculateWordsValue(word, 10000);
    }
    stopWords.close();
}

#endif //REQUENT_WORDS_HASHING_H
