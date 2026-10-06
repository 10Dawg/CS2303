#include "clean_word.h"
void cleanWord(char* i1){
    for(int i = 0; i1[i]; i++){

        // if this character is not a letter
        if(isalpha(i1[i]) == 0){  
            // shift everything to the left in the array
            for(int j = i; j < 50; j++)  
            {  
                i1[j] = i1[j + 1];  
            }  
            i = i - 1;
        }

        i1[i] = tolower(i1[i]);
    }
}