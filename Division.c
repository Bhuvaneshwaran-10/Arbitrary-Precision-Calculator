// Division Function

#include "Functions.h"

void division(node *head1, node *head2, node **headR, node **tailR)
{
    *headR = NULL;
    *tailR = NULL;

    if(head1 == NULL || head2 == NULL)
        return;

    // If divisor is 1 ,result will be dividend
    if(head2->data == 1 && head2->next == NULL)
    {
        node *temp = head1;
        while(temp != NULL)
        {
            insert_last(headR, tailR, temp->data);
            temp = temp->next;
        }
        return;
    }

    // If divisor is 0 , the result will be ERROR (undefined)
    if(head2->next == NULL && head2->data == 0)
    {
        printf("Error: Division by zero\n");
        return;
    }

    // Handle edge cases: dividend < divisor → 0, equal → 1
    int cmp = compare_list(head1, head2);

    if(cmp == OPERAND2)
    {
        insert_last(headR, tailR, 0);
        return;
    }
    else if(cmp == SAME)
    {
        insert_last(headR, tailR, 1);
        return;
    }

    // Initialize pointers for dividend traversal and partial division handling
    node *temp1 = head1;
    node *temp_head = NULL, *temp_tail = NULL;

    node *tail2 = head2;
    while(tail2->next)
        tail2 = tail2->next;

    while(temp1 != NULL)
    {

        insert_last(&temp_head, &temp_tail, temp1->data);
        remove_pre_zeros(&temp_head,&temp_tail);

        // count represents the quotient digit for each division step
        int count = 0;

        // Repeated subtraction to compute quotient digit
        while(compare_list(temp_head, head2) == OPERAND1 || 
              compare_list(temp_head, head2) == SAME)
        {
            node *res_head = NULL, *res_tail = NULL;

            subtraction(temp_tail, tail2, &res_head, &res_tail);

            delete_list(&temp_head, &temp_tail);

            temp_head = res_head;
            temp_tail = res_tail;

            remove_pre_zeros(&temp_head,&temp_tail);

            count++;
        }

        // Storing result in linked list
        insert_last(headR, tailR, count);

        temp1 = temp1->next;
    }

    remove_pre_zeros(headR,tailR);
    delete_list(&temp_head, &temp_tail);
    
}