#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number ;
    struct node* next;
}node;

int main(int argc, char * argv[])
{
    node* list = NULL;

    for(int i =1; i < argc;i++)
    {
        node* n = malloc(sizeof(node));
        if(n==NULL)
        {
            //steps to free the memory .
            return 1;
        }
        int number = atoi(argv[i]);
        n ->number = number;
        n ->next = NULL;
        if (list == NULL)
        {

            list = n;
        }
        else if (n->number < list->number)
        {
            n->next = list;
            list =n;

        }
        else
        {
            for(node* ptr = list ; ptr!=NULL;ptr = ptr->next)
            {
                //If at the end of the list .
                if (ptr->next==NULL){
                        ptr->next=n;
                        break;

                }
                //If at the beginning of the list
                if(n->number <ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }

    }
    node* ptr = list;
     while(ptr != NULL){
        printf("%i\n" , ptr->number);
        ptr= ptr->next;

 }

}
