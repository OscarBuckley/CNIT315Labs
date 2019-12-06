#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int option = 0;

typedef struct student{

char firstname[20];
char lastname[20];
char PUID[10];
int age;

struct student* next;
}node;

node * stackstart = NULL;
node * queuestart = NULL;

void PrintStack(node * start);
void PrintQueue(node * start);
node * CreateNode(char * firstname, char * lastname, char * PUID, int age);
void push(char * firstname, char * lastname, char * PUID, int age);
node * pop();
int stacksize();
bool isstackempty();
void enqueue(char * firstname, char * lastname, char * PUID, int age);
node * dequeue();
int queuesize();
bool isqueueempty();
void emptystack();
void emptyqueue();

int main(){

while (option != 12){
char firstname[20];
char lastname[20];
char PUID[10];
int age = 0;
int count = 0;
bool empty = true;
node * deleted = NULL;


printf("MENU\n\n");
printf("Print Functions:\n");
printf("0. Print Stack\n");
printf("1. Print Queue\n\n");

printf("Stack Functions:\n");
printf("2. Push\\Enqueue\n");
printf("3. Pop\n");
printf("4. Size of stack\n");
printf("5. Is stack Empty?\n");
printf("6. Empty Stack\n\n");


printf("Queue Functions:\n");
printf("7. Enqueue\\Push\n");
printf("8. Dequeue\n");
printf("9. Size of queue\n");
printf("10. Is queue Empty?\n");
printf("11. Empty Queue\n\n");

printf("12. Quit\n");

scanf("%d", &option);

switch (option){

	case 0:
	PrintStack(stackstart);
	break;

	case 1:
	PrintQueue(queuestart);
	break;

	case 2:
	printf("Please Enter the First Name:");
	scanf(" %s", firstname);
	printf("Please Enter the Last Name:");
	scanf(" %s", lastname);
	printf("Please Enter the PUID:");
	scanf(" %s", PUID);
	printf("Please Enter the Age:");
	scanf(" %d", &age);
	push(firstname, lastname, PUID, age);
	enqueue(firstname, lastname, PUID, age);

	break;

	case 3:
	deleted = NULL;
	deleted = pop();

	if(deleted != NULL){
		printf("The node that is popped has the following data\n");
		printf("\t%s\n",deleted->firstname);
		printf("\t%s\n",deleted->lastname);
		printf("\t%s\n",deleted->PUID);
		printf("\t%d\n",deleted->age);
		printf("\n");
	}
	break;

	case 4:
	count = stacksize();
	printf("The stack currently has %d nodes\n", count);
	break;

	case 5:
	empty = isstackempty();
	printf("The stack is currently empty: %s\n", empty ? "true" : "false");
	break;

	case 6:
	emptystack();
	break;

	case 7:
	printf("Please Enter the First Name:");
	scanf(" %s", firstname);
	printf("Please Enter the Last Name:");
	scanf(" %s", lastname);
	printf("Please Enter the PUID:");
	scanf(" %s", PUID);
	printf("Please Enter the Age:");
	scanf(" %d", &age);
	push(firstname, lastname, PUID, age);
	enqueue(firstname, lastname, PUID, age);
	break;

	case 8:
	deleted = NULL;
	deleted = dequeue();
	if(deleted != NULL){
		printf("The node that is popped has the following data\n");
		printf("\t%s\n",deleted->firstname);
		printf("\t%s\n",deleted->lastname);
		printf("\t%s\n",deleted->PUID);
		printf("\t%d\n",deleted->age);
		printf("\n");
	}
	break;

	case 9:
	count = queuesize();
	printf("The queue currently has %d nodes\n", count);
	break;

	case 10:
	empty = isqueueempty();
	printf("The queue is currently empty: %s\n", empty ? "true" : "false");
	break;

	case 11:
	emptyqueue();
	break;

	default:
	printf("Command not chosen\n");
	printf("Function not run\n");
	break;

}

free(deleted);
}



}

//OUTSIDE OF MAIN

//Print Stack
void PrintStack(node * start){

	node * temp = start;

	printf("\nBeginning of Stack\n\n");

	while (temp != NULL){

		printf("\t%s\n",temp->firstname);
		printf("\t%s\n",temp->lastname);
		printf("\t%s\n",temp->PUID);
		printf("\t%d\n",temp->age);
		printf("\n");
		temp = temp->next;

	}

	printf("\nEnd of Stack\n\n");

}

//Print Queue
void PrintQueue(node * start){

	node * temp = start;

	printf("\nBeginning of Queue\n\n");

	while (temp != NULL){

		printf("\t%s\n",temp->firstname);
		printf("\t%s\n",temp->lastname);
		printf("\t%s\n",temp->PUID);
		printf("\t%d\n",temp->age);
		printf("\n");
		temp = temp->next;

	}

	printf("\nEnd of Queue\n\n");

}

//create a new node
node * CreateNode(char * firstname, char * lastname, char * PUID, int age){

	node * p = (node *)malloc(sizeof(node));
	strcpy(p->firstname, firstname);
	strcpy(p->lastname, lastname);
	strcpy(p->PUID, PUID);
	p->age = age;

	p->next = NULL;
	return p;

}

//Pushing a.k.a. adding a node to the stack
void push(char * firstname, char * lastname, char * PUID, int age){

	node * insert = CreateNode(firstname, lastname, PUID, age);

	if (stackstart == NULL){

		stackstart = insert;

	}else{


		node * temp = stackstart;
		while (temp->next != NULL){


			temp = temp->next;
		}
	
		temp->next = insert;
		insert->next = NULL;


	}
}

//Popping a.k.a. removing a node from the stack
node * pop(){

	if (stackstart == NULL){

		printf("This stack is already empty\n");
		printf("Function not ran.\n");

		return NULL;

	}else if (stackstart->next == NULL){

		node * temp = stackstart;
		stackstart = NULL;
		return temp;

	}else{

		node * temp = stackstart;

		while (temp->next != NULL){

			temp = temp->next;
		}

		node * secondlast = stackstart;

		while (secondlast->next->next != NULL){

			secondlast = secondlast->next;
		}

		secondlast->next = NULL;
		return temp;
	}
}

//Get Stack Size
int stacksize(){
	
	int count = 0;

	node * temp = stackstart;

	while (temp != NULL){

		temp = temp->next;
		count++;

	}

	return count;

}

//Is Stack Empty?
bool isstackempty(){

	bool empty;

	if (stackstart == NULL){

		empty = true;
	}else{

		empty = false;
	}

	return empty;

}

//Enqueue i.e. adding a node
void enqueue(char * firstname, char * lastname, char * PUID, int age){

	node * insert = CreateNode(firstname, lastname, PUID, age);

	if (queuestart == NULL){

		queuestart = insert;

	}else{

		insert->next = queuestart;
		queuestart = insert;

	}

}

//Dequeue i.e. removing a node
node * dequeue(){

	if (queuestart == NULL){

		printf("This queue is already empty\n");
		printf("Function not ran.\n");

		return NULL;

	}else if (queuestart->next == NULL){

		node * temp = queuestart;
		queuestart = NULL;
		return temp;

	}else{

		node * temp = queuestart;

		while (temp->next != NULL){

			temp = temp->next;
		}

		node * secondlast = queuestart;

		while (secondlast->next->next != NULL){

			secondlast = secondlast->next;
		}

		secondlast->next = NULL;
		return temp;
	}
}

//Get Queue Size
int queuesize(){
	
	int count = 0;

	node * temp = queuestart;

	while (temp != NULL){

		temp = temp->next;
		count++;

	}

	return count;

}

//Is Queue Empty?
bool isqueueempty(){

	bool empty;

	if (queuestart == NULL){

		empty = true;
	}else{

		empty = false;
	}

	return empty;

}

//Emptying Stack
void emptystack(){

int length = stacksize();

int i = 0;

	while (i < length){

		if (stackstart->next == NULL){

				node * temp = stackstart;
				free(temp);
				stackstart = NULL;

			}else{

				node * temp = stackstart;

				while (temp->next != NULL){

					temp = temp->next;
				}

				node * secondlast = stackstart;

				while (secondlast->next->next != NULL){

					secondlast = secondlast->next;
				}

				secondlast->next = NULL;
				free(temp);

			}

		i++;
	}

	if (stackstart == NULL){
		printf("Stack has been successfully emptied\n");
	}else{
		printf("Stack not successfully emptied\n");
	}
}

//Emptying Queue
void emptyqueue(){

int length = queuesize();

int i = 0;

while (i < length){

		if (queuestart->next == NULL){

				node * temp = queuestart;
				free(temp);
				queuestart = NULL;

			}else{

				node * temp = queuestart;

				while (temp->next != NULL){

					temp = temp->next;
				}

				node * secondlast = queuestart;

				while (secondlast->next->next != NULL){

					secondlast = secondlast->next;
				}

				secondlast->next = NULL;
				free(temp);

			}

		i++;
	}

	if (queuestart == NULL){
		printf("Queue has been successfully emptied\n");
	}else{
		printf("Queue not successfully emptied\n");
	}

}
