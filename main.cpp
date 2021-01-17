#include <iostream>
#include <fstream>
//#include <stdio.h>
#include <string.h>
#include <time.h>

#include "checkWord.h"
#include "hashing.h"

#include "HashMap.h"

using namespace std;

int main() {
    HashMap<string,int> *wordList = new HashMap<string,int>(10000);


    wordList->put("tell", 0);
    wordList->put("deneme1", 12);

    string word;
    int wordIndex;

    ifstream stopWords("stopwords.txt");

    while(stopWords >> word){
        wordList->put(word, 0);
    }
    stopWords.close();

    wordList->display();

    clock_t tStart = clock();
    string test;
    ifstream MyFile("./Reuters-21578/reut2-000.txt");

//    while(MyFile >> test){
//       wordList->put(checkWord(test),0);
//    }

    MyFile.close();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0 ;
}


//#include <string_view>
//#include <functional>
//#include <memory_resource>

//using namespace std::literals;
//using namespace std;
//
//int main()
//{
//    string test="abc";
//    auto sv = "Stand back! I've got jimmies!"sv;
//    auto a = "bd";
//    auto b = test;
//    //string s(sv);
//    //string pmrs(sv); // use default allocator
////    //cout << std::hash<std::string_view>{}(sv) << '\n';
////    //cout << std::hash<std::string>{}(a) << '\n';
////    unsigned int d = hash<string>{}(a);
////    unsigned int f = hash<string>{}(a);
////    //long int f = hash<string_view>{}(sv);
////
////    cout << hash<std::string_view>{}(sv) << '\n';
////    cout << hash<std::string>{}(a) << '\n';
//cout<< calculateHashValue("abc",1000);
//    cout<< calculateHashValue("acb",1000);
//    cout<< calculateHashValue("bca",1000);
////    //cout << hash<string>{}(b) << '\n';
////    //cout << d << " " << f;
////    //cout << hash<string>{}(pmrs) << '\n';
//}


