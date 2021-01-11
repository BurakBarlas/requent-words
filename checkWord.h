//
// Created by Barlas on 1/11/2021.
//

#ifndef REQUENT_WORDS_CHECKWORD_H
#define REQUENT_WORDS_CHECKWORD_H

using namespace std;

bool whenStart = false;
string START_WORD = "<BODY>";
string END_WORD = "</BODY>";

bool isStart(string word){
//    if(verb.size() >=17){
//        if(verb[12] == 'B' && verb[13] == 'O' && verb[14] == 'D' && verb[15] == 'Y' ){
//            return true;
//        }
//    }

    if(word.find(START_WORD) != string::npos) {
        return true;
    }
    return false;
}

bool isEnd(string word){
//    if(verb.size() >=18){
//        if(verb[6] == 'B' && verb[7] == 'O' && verb[8] == 'D' && verb[9] == 'Y' ){
//            return true;
//        }
//    }

    if(word.find(END_WORD) != string::npos) {
        return true;
    }

    return false;
}

void checkWord(string test){
    string tempWord = "";
    if(isEnd(test)){
        whenStart = false;
    }

    if(whenStart && ((test[0] >= 'a' && test[0]<= 'z')||(test[0] >= 'A' && test[0]<= 'Z'))){
        char *token = strtok( &test[0] , "\",.:')");
        cout << token << endl;
    }
    if(isStart(test)){
        whenStart = true;
        int startPos = test.find(START_WORD) + START_WORD.length();
        for (int i = startPos; i < test.size(); ++i) {
            tempWord += test[i];
        }
        test = tempWord;
        cout<< test <<endl;
    }
}

#endif //REQUENT_WORDS_CHECKWORD_H
