//
// Created by Barlas on 1/12/2021.
//

#ifndef REQUENT_WORDS_FILEOPENER_H
#define REQUENT_WORDS_FILEOPENER_H



std::string sgmStringTransporter(int index){
    std::string sgmFile = "reut2-000.sgm";
    if (index <= 9){
        sgmFile[8] = index + 48;
    }
    else{
        sgmFile[7] = ((index - (index % 10))/10) + 48;
        sgmFile[8] = (index % 10) + 48;
    }
    return sgmFile;
}


#endif //REQUENT_WORDS_FILEOPENER_H
