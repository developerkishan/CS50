#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
string rotate(string plain_text,int key);

int main(int argc, string argv[]){
    if (argc != 2){
            printf("Usage: ./caesar key\n");
            return 1;
        }
    else {
        for(int i = 0; i < strlen(argv[1]);i++){
            if (!isdigit(argv[1][i])){
                printf("Usage: ./caesar key\n");
            return 1;
            }

        }
    }
    //return 0;
    int key = atoi(argv[1]);
    string plain_text = get_string("Please enter the plain text: ");
     printf("The cipher text is %s ", rotate(plain_text, key));
}


string rotate(string plain_text,int key){
    char capitalLetters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char smallLetters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int i =0;
    char c;
    int position=0;
    while(plain_text[i] != '\0'){
        if(isupper(plain_text[i])){
             position  = ((plain_text[i] - 'A') + key )%26;
             printf("%i\n",position);
            c = capitalLetters[position];
            plain_text[i] = c;

        }
        else if (islower(plain_text[i])){
             position  = ((plain_text[i] - 'a')  + key )%26;
            c = smallLetters[position];
            printf("%i\n",position);
            plain_text[i] = c;

        }
        else {
            plain_text[i] = plain_text[i];
        }
        i++;
    }
    return plain_text;
}
