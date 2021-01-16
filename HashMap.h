//
// Created by Barlas on 1/13/2021.
//

#ifndef REQUENT_WORDS_HASHMAP_H
#define REQUENT_WORDS_HASHMAP_H

//#include<bits/stdc++.h>
#include "hashing.h"

template<typename K, typename V>

class HashNode{
public:
    V value; // kac kere kullanildigi
    K key; // string

    //constructor

    HashNode(K key, V value){
        this->value = value;
        this->key = key;
    }
};

//template for generic type
template<typename K, typename V>

class HashMap {
private:
    //HashMap<K, V> **arr;

    HashMap<K,V> *HMap;
    int *indexStatusList;

    int capacity; // Max size
    int size;

    HashMap<K,V> *dummy;

    void insert(int hashIndex, const HashMap<K,V>& node){

        int pCount;
        int inc;

        pCount = 0;
        inc = 1;

        while (indexStatusList[hashIndex] == 1 && HMap[hashIndex] != node && pCount < capacity / 2){
            pCount++;
            hashIndex = (hashIndex + inc) % capacity;
            inc = inc + 2;
        }

        if(indexStatusList[hashIndex] != 1){
            HMap[hashIndex] = node;
            indexStatusList[hashIndex] = 1;
            size++;
        }

        else if (HMap[hashIndex] == node)
            cerr << "Error: No duplicates are allowed" << endl;
        else
            cerr << "Error: The table is full. "
                 <<"Unable to resolve the collision" << endl;

    }

    int calculateHashValue(K word , int arraySize){

        unsigned int hashedWord = hash<K>{}(word);
        int address = hashedWord % arraySize;

        return address;
    }

public:
    // Put
    void put(K key, V value) {
        // hashing
        HashMap<K, V> newNode = new HashMap<K,V>(key, value);
        int index = calculateHashValue(key, size);
        // Chech if index empty
        insert(index, newNode);
    }

    V get(K key){
        int hashIndex = calculateHashValue(key);

        while (HMap[hashIndex] != NULL) {
            if (HMap[hashIndex] == calculateHashValue(key)) {
                return key;
            }
        }
    }

    // Checks whether key exists in hashmap
    bool isExist(K key);

//    List<V> getKeys();

    //void search(int &hashIndex, const HashMap<K,V>& node) const;


    bool isItemAtEqual(int hashIndex, const HashMap<K,V>& node) const;

    //get
};

#endif //REQUENT_WORDS_HASHMAP_H
