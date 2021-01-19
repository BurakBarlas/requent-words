//
// Created by Barlas on 1/11/2021.
//

#ifndef REQUENT_WORDS_CHECKWORD_H
#define REQUENT_WORDS_CHECKWORD_H


bool whenStart = false;

std::string START_WORD = "<BODY>";
std::string END_WORD = "</BODY>";

bool isStart(std::string word){

    if(word.find(START_WORD) != std::string::npos) {
        return true;
    }
    return false;
}

bool isEnd(std::string word){

    if(word.find(END_WORD) != std::string::npos) {
        return true;
    }

    return false;
}

std::string checkWord(std::string test){
    std::string tempWord;
    if(isEnd(test)){
        whenStart = false;
    }

    if(whenStart && ((test[0] >= 'a' && test[0]<= 'z')||(test[0] >= 'A' && test[0]<= 'Z'))){
        char *token = strtok( &test[0] , "\",.]:'>()");
//        cout << token << endl;
//        wordNum++;
        return token;

    }
    if(isStart(test)){
        whenStart = true;
        int startPos = test.find(START_WORD) + START_WORD.length();
        for (int i = startPos; i < test.size(); ++i) {
            tempWord += test[i];
        }
        test = tempWord;
//        cout<< test <<endl;
//        wordNum++;
        return  test;

    }
    else{
        return "";
    }
}

#endif //REQUENT_WORDS_CHECKWORD_H
