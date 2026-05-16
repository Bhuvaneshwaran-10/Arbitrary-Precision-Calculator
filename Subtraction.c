// Subtraction Function

#include "Functions.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    *headR = NULL;
    *tailR = NULL;
    
    node *temp1 = tail1;
    node *temp2 = tail2;
    int borrow_flag = 0;
    
    while(temp1 != NULL || temp2 != NULL)
    {
        int digit1 = temp1 ? temp1->data : 0;
        int digit2 = temp2 ? temp2->data : 0;

        if(borrow_flag == 1)
        {
            digit1 = digit1 - 1;
        }
        if(digit1 < digit2)
        {
            digit1 = digit1 + 10;
            borrow_flag = 1;
        }
        else
        {
            borrow_flag = 0;
        }

        int sub = digit1 - digit2;

        insert_first(headR, tailR, sub);

         if(temp1 != NULL)
            temp1 = temp1->prev;

        if(temp2 != NULL)
            temp2 = temp2->prev;
    }
}
   