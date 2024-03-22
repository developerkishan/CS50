#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node* next;
}node;

node * list = NULL;


int main (int argc , char *argv[])
{



    for(int i =1; i < argc; i++)
    {
        node * n = malloc(sizeof(node));
            if(n ==NULL)
    {
        return 1;
    }
        printf("This is executed \n");
        int number = atoi(argv[i]);
            n -> number = number;
            n->next = NULL;
        if(list==NULL){
            list=n;
        }
        else{
            for(node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                printf("The value we have added is %i \n" , n -> number);
                printf("The value we have LIST has got is %i \n" , list -> number);

                if(ptr->next == NULL){
                    ptr->next = n;
                    break;
                }



            }
        }
    }


node * ptr = list;
printf("The value we have got it %i \n" , ptr -> number);
    while(ptr != NULL){
        printf("%i\n" , ptr->number);
        ptr= ptr->next;
    }


}
