#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
int count_letter_words_sentences(string text);


int main (void){

    string text = get_string("Enter the text: ");
    float index = count_letter_words_sentences(text);
    printf("%f is the index \n ", index);

}

int count_letter_words_sentences(string text){

    int i = 0, letterCount =0,words=1, sentence=0 ;
    float index;
    while (text[i] != '\0'){
        if (isalpha(text[i])){
            letterCount++;
        }
        else if (text[i] == ' '){
            words++;
        }
        else if (text[i] == '.' || text[i]== '?'|| text[i]== '!'){
            sentence++;
        }
        i++;
    }
    float letterCountFloat =((float)letterCount/ (float)words) *100;
    float sentenceFloat = ((float)sentence/(float)words) *100;
    index =  0.0588 * letterCountFloat - 0.296 * sentenceFloat - 15.8;
    return index;
    }
