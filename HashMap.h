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
    //HashNode<K,V> **arr;

    HashNode<K,V> **HMap;
    int *indexStatusList;

    int capacity; // Max size
    int size;

    //HashMap<K,V> *dummy;
    void insert(int hashIndex, HashNode<K,V> *node) {
        //find next free space
        while(HMap[hashIndex] != NULL && HMap[hashIndex]->key != node->key)
        {
            hashIndex++;
            hashIndex %= capacity;
        }
        
        //if new node to be inserted increase the current size
        if(HMap[hashIndex] == NULL) {
            size++;
            HMap[hashIndex] = node;
            node->value++;
        }

        else if(HMap[hashIndex]->key == node->key){
            HMap[hashIndex]->value++;
        }
    }

        void insert1(int hashIndex, HashNode<K,V> node){

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

    int calculateHashValue(K word){

        unsigned int hashedWord = hash<K>{}(word);
        int address = hashedWord % capacity;

        return address;
    }

public:
    HashMap(int capacity){
        this->capacity = capacity;
        size = 0;

        HMap = new HashNode<K,V>*[capacity];

        for(int i=0; i < capacity;i++){
            HMap[i] = NULL;
        }
    }
    // Put
    void put(K key, V value) {
        // hashing
        HashNode<K, V> *newNode = new HashNode<K,V>(key, value);

        int hashIndex = calculateHashValue(key);
        // Chech if index empty
        insert(hashIndex, newNode);
    }

    V get(K key){
        int hashIndex = calculateHashValue(key);

        while (HMap[hashIndex] != NULL) {
            if (HMap[hashIndex] == calculateHashValue(key)) {
                return key;
            }
        }
    }

    void printStopWordsArray(){
        for (int i = 0; i < capacity; ++i) {
            cout << i << " ) " << HMap[i] << endl;
        }
    }

    void display()
    {
        for(int i=0 ; i<capacity ; i++)
        {
            if(HMap[i] != NULL)
                cout << i << "key = " << HMap[i]->key
                <<"  value = "<< HMap[i]->value << endl;
        }
    }


    // Checks whether key exists in hashmap
    bool isExist(K key);

//    List<V> getKeys();

    //void search(int &hashIndex, const HashMap<K,V>& node) const;


    bool isItemAtEqual(int hashIndex, const HashNode<K,V>& node) const;

    //get
};

#endif //REQUENT_WORDS_HASHMAP_H
