

/*
                    	--- Arbitrary Precision Calculator (APC) ---

     Name : Bhuvaneshwaran P
       ID : 25036B_092
Start date: 25/03/2026
 End date : 09/04/2026

DESCRIPTION:
            	This project implements an Arbitrary Precision Calculator in C using linked lists
 to perform arithmetic operations on very large numbers that cannot be handled by standard
 data types. The calculator supports operations such as addition, subtraction, multiplication,
 division, modulus, and power. Each digit of the number is stored in a node of a linked list,
 allowing efficient handling of large inputs. The project focuses on dynamic memory management, 
 pointer manipulation, and implementation of fundamental data structure concepts.It demonstrates 
 problem-solving skills in handling big numbers and designing modular, structured programs using 
 Data Structures and Algorithms.

*/



#include "Functions.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL;
	node *head2 = NULL, *tail2 = NULL;
	node *headR = NULL, *tailR = NULL;

    // Validation of arguments
	if(cla_validation(argc, argv) == FAILURE)
		return 1;

	// Sign Validation
	int flag1 = 1, flag2 = 1;
	char *arg = argv[1];
	if(*arg == '-')
	{
		flag1 = -1;
		arg++;
	}
	char *arg1 = argv[3];
	if(*arg1 == '-')
	{
		flag2 = -1;
		arg1++;
	}	

    // Create 2 lists of operands
	create_list(arg,&head1,&tail1);
	create_list(arg1,&head2,&tail2);

    // Remove pre zeros
	remove_pre_zeros(&head1,&tail1);
	remove_pre_zeros(&head2,&tail2);

	// getting operator from CLA
    char operation = argv[2][0];

	// performing operations
    switch(operation)
    {
	// Addition Operation
	case '+':
		{
			if(flag1 == flag2)
			{
				addition(tail1,tail2,&headR,&tailR);
				if(flag1 == -1)
					printf("-");
			}
			else 
			{
				int compare = compare_list(head1,head2);

				if(compare == OPERAND1 || compare == SAME)
				{
					subtraction(tail1, tail2, &headR, &tailR);
					if(flag1 == -1)
						printf("-");
				}
				else
				{
					subtraction(tail2, tail1, &headR, &tailR);
					if(flag2 == -1)
						printf("-");
				}
			}
	    	break;
		}
	// Subtraction Operation
	case '-':
		{
			flag2 = -flag2;
			if(flag1 == flag2)
			{
				addition(tail1,tail2,&headR,&tailR);
				if(flag1 == -1)
					printf("-");
			}
			else
			{
				int compare = compare_list(head1,head2);
				if(compare == OPERAND1 || compare == SAME)
				{
					subtraction(tail1,tail2,&headR,&tailR);
					if(flag1 == -1)
						printf("-");
				}
				else
				{
					subtraction(tail2, tail1, &headR, &tailR);
                    if(flag2 == -1) 
						printf("-");
				}
			}
	    	break;
		}
	// Multiplication Operation
	case 'x':
	case 'X':
			{
				multiplication(tail1,tail2,&headR,&tailR);
					if(flag1 != flag2 && !(headR->data == 0 && headR->next == NULL))
    					printf("-");
	    	break;
			}
	// Division Operation
	case '/':
			{
				division(head1,head2,&headR,&tailR);
					if(flag1 != flag2 && !(headR->data == 0 && headR->next == NULL))
    					printf("-");
	    	break;
			}
	default:
	    printf("Invalid operator\n");
		return 1;
    }
	// removing pre zeros in result linked list
	remove_pre_zeros(&headR,&tailR);
	// printing result linked list
	print_list(headR);

	// clearing memory of all linked list
	delete_list(&head1, &tail1);
	delete_list(&head2, &tail2);
	delete_list(&headR, &tailR);

	return 0;
}

