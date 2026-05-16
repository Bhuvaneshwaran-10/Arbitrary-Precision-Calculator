// Function definitions

#include "Functions.h"

// create linked list function
void create_list(char *opr, node **head, node **tail)
{
    int i = 0;

    if (opr[i] == '-' || opr[i] == '+') 
    {
        i++;
    }

    while(opr[i] != '\0')
    {
        node *new = (node *)malloc(sizeof(node));
        if(new == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        new->data = opr[i] - '0';
        new->next = NULL;
        new->prev = NULL;

        if(*head == NULL)
        {
            *head = new;
            *tail = new;
        }
        else
        {
            (*tail)->next = new;
            new->prev = *tail;
            *tail = new;
        }
        i++;
    }
}

// insert first function
int insert_first(node **head, node **tail, int data)
{
     node *new = malloc(sizeof(node));
     if(new == NULL)
     {
        return FAILURE;
     }   
     new->data = data;
     new->prev = NULL;
     new->next = *head;
     if(*head == NULL)
     {
        *tail = new;
     }
     else
     {
        (*head)->prev = new;
     }
    *head = new;
    return SUCCESS;
}

// insert last function 
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->next = NULL;
    new->prev = *tail;
    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        (*tail)->next = new;
    }
    *tail = new;
    return SUCCESS;
}

// delete list function
int delete_list(node **head, node **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    node *temp1 = (*head);
    node *temp2;
    while(temp1 != NULL)
    {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

// printing linked list function
void print_list(node *head)
{
    if(head == NULL)
    {
        printf("List is Empty..\n");
        return;
    }

    while(head != NULL)
    {
    printf("%d" ,head->data);
    head = head->next;
    }
    printf("\n");
}

// comparing two linked list
int compare_list(node *head1, node *head2)
{
    int list1_len = list_len(head1);
    int list2_len = list_len(head2);
    node *temp1 = head1;
    node *temp2 = head2;

    if(list1_len > list2_len)
    {
        return OPERAND1;
    }
    else if(list1_len < list2_len)
    {
        return OPERAND2;
    }
    else
    {
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data > temp2->data)
            {
                return OPERAND1;
            }
            else if(temp1->data < temp2->data)
            {
                return OPERAND2;
            }  
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            } 
        }
    }
    return SAME;
    
}

// finding length of linked list
int list_len(node *head)
{
    int i = 0;
    while(head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

// validation arguments
int cla_validation(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("\nERROR : Enter proper aruguments\n");
        printf("\nExample :  ./a.out <operand1> <operator> <operand2>\n");
        printf("or\nExample : ./Calculator <operand1> <operator> <operand2>\n");
        printf("\nValid Operators : '+' , '-' , 'x' or 'X , '/' \n");
        return FAILURE;
    }

    if((num_validation(argv[1])) == FAILURE)
    {
        printf("Enter valid number\n");
        return FAILURE;
    }

    if((is_operand(argv[2]))  == FAILURE)
    {
        printf("Enter valid operand\n");
        printf("Operands are    '+' , '-' , 'x' or 'X , '/'  \n");
        return FAILURE;
    }

    if((num_validation(argv[3])) == FAILURE)
    {
        printf("Enter valid number\n");
        return FAILURE;
    }
    return SUCCESS;
}

// validation for number
int num_validation(char *num)
{
    int i = 0;

    if(num[i] == '+' || num[i] == '-')
        i = 1;

    if(num[i] == '\0')
        return FAILURE;

    while(num[i] != '\0')
    {
    if((num[i] < '0' || num[i] > '9'))
        return FAILURE;
    i++;
    }
   
    return SUCCESS;
}

// validation for operand
int is_operand(char *opr)
{
    if(!((opr[0] == '+') || (opr[0] == '-') || (opr[0] == 'x') || (opr[0] == 'X') || (opr[0] == '/')))
        return FAILURE;
    return SUCCESS;
}

// removing pre zeros 
void remove_pre_zeros(node **head, node **tail) {
    while ((*head)->data == 0 && (*head)->next != NULL) 
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    if ((*head)->next == NULL)
        *tail = *head;
}