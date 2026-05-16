#include "Functions.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    *headR = NULL;
    *tailR = NULL;
    
    int carry = 0, sum;
    node *temp1 = tail1;
    node *temp2 = tail2;

    while(temp1 != NULL || temp2 != NULL || carry)
    {
        // checking data in temp 
        int digit1 = temp1 ? temp1->data : 0;
        int digit2 = temp2 ? temp2->data : 0;

        // sum operation
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        // Storing sum in linked list
        insert_first(headR,tailR,sum);
        
        if(temp1 != NULL)
                temp1 = temp1->prev;

        if(temp2 != NULL)
            temp2 = temp2->prev;
    }
}
