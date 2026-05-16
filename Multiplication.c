// Multiplication Function

#include "Functions.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    *headR = NULL;
    *tailR = NULL;
    
    node *temp2 = tail2;
    int count = 0;          // how many zeros to add
    while(temp2 != NULL)
    {
        node *headtemp = NULL;
        node *tailtemp = NULL;
        node *temp1 = tail1;
        int carry = 0;

        // if 0 is input , then result will be zero
        if((tail1->data == 0 && tail1->prev == NULL) || 
            (tail2->data == 0 && tail2->prev == NULL))
        {
            insert_last(headR, tailR, 0);
            return;
        }

        while(temp1 != NULL)
        {
            // Multiplication Operation
            int product = temp1->data * temp2->data + carry;
            int digit = product % 10;
            carry = product / 10;

            // Storing Digit value in linked list
            insert_first(&headtemp, &tailtemp, digit);

            temp1 = temp1 -> prev;
        }
        // carry > 0 , storing carry value in linked list
        if(carry > 0)
        {
            insert_first(&headtemp, &tailtemp, carry);
        }

        // adds zeros at the end of the partial result.
        for(int i = 0; i < count; i++)
        {
            insert_last(&headtemp, &tailtemp, 0);
        }

        // storing result linked list
        if(*headR == NULL)
        {
            *headR = headtemp;
            *tailR = tailtemp;
        }
        else
        {
           node *newhead = NULL;
           node *newtail = NULL; 

            addition(*tailR, tailtemp, &newhead, &newtail);

            delete_list(headR,tailR);
            delete_list(&headtemp,&tailtemp);

            *headR = newhead;
            *tailR = newtail;
        }
        // increments zero count
        count++;

        temp2 = temp2->prev;
    }

    // remove pre zeros in result linked list
    remove_pre_zeros(headR,tailR);
}
