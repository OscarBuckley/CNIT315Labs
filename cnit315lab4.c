#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct student{

char firstname[20];
char lastname[20];
char PUID[10];
int age;

struct student* next;
}node;

void DisplayList(node * start);
void CreateListNoNodes();
void CreateListNode();
void InsertEnd(node * insert);
void InsertFront(node * insert);
void InsertMiddle(node * insert);
void DeleteFront();
void DeleteMiddle();
void DeleteEnd();
void Traverse(char * query);
void LookUpByIndex(int index);
node * CreateNode(char * firstname, char * lastname, char * PUID, int age);

int length = 0;
node * start;
int nodeIndex = -1;

int main(){

printf("Creating List with No Nodes\n");
CreateListNoNodes();

printf("Displaying List\n");
DisplayList(start);

printf("Creating List with 1 Node\n");
CreateListNode();

printf("Displaying List\n");
DisplayList(start);

printf("Inserting Node at Front of the List\n");
node * front = CreateNode("Pranav", "Bhusari", "0022222222", 19);
InsertFront(front);

printf("Displaying List\n");
DisplayList(start);

printf("Inserting Node at End of the List\n");
node * back = CreateNode("Brandon", "Brewer", "0033333333", 18);
InsertEnd(back);

printf("Displaying List\n");
DisplayList(start);

printf("Inserting Node at Middle of the List\n");

do{
printf("Please enter the index that the new node will be positioned.\n");
printf("Index starts at 1.\n");
printf("Index must be larger than 1 and smaller or equal than %d.\n", length);
scanf("%d", &nodeIndex);
}while (nodeIndex <= 1 || nodeIndex > length);

node * middle = CreateNode("Diego", "Puga", "0044444444", 17);
InsertMiddle(middle);

printf("Displaying List\n");
DisplayList(start);

printf("Looking up node by Index\n");

int index;
do{
printf("Please enter the index to search the node\n");
printf("Index starts at 1.\n");
printf("Index must be larger than 0 and smaller or equal to %d.\n", length);
scanf("%d", &index);
}while (index <= 0 || index > length);

LookUpByIndex(index);

printf("Traverse List\n");
printf("Please enter the first name you want to search\n");
char query[20];
scanf("%s", query);
Traverse(query);

printf("Deleting the middle node in the List\n");
do{
printf("Please enter the index that the node will be deleted:\n");
printf("Index starts at 1.\n");
printf("Index must be larger than 1 and smaller than %d.\n", length);
scanf("%d", &nodeIndex);
}while (nodeIndex <= 1 || nodeIndex >= length);
DeleteMiddle();

printf("Displaying List\n");
DisplayList(start);

printf("Deleting the first node in the List\n");
DeleteFront();

printf("Displaying List\n");
DisplayList(start);

printf("Deleting the last node in the List\n");
DeleteEnd();

printf("Displaying List\n");
DisplayList(start);

}

//Outside of main
//Display List
void DisplayList(node * start){

node * temp = start;

while (temp != NULL){

printf("\t%s\n",temp->firstname);
printf("\t%s\n",temp->lastname);
printf("\t%s\n",temp->PUID);
printf("\t%d\n",temp->age);
printf("\n");
temp = temp->next;
}

}

//create empty list
void CreateListNoNodes(){

start = NULL;

}

//create list with one node
void CreateListNode(){
start = CreateNode("Oscar", "Wong", "0011111111", 20);

length++;
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

//Insert Node at End
void InsertEnd(node * insert){

node * tmp = start;

while (tmp->next != NULL){

tmp = tmp->next;
}

tmp->next = insert;

length++;

}

//Insert Node at Front
void InsertFront(node * insert){

insert->next = start;
start = insert;

length++;

}

//Insert Node in Middle
void InsertMiddle(node * insert){

node * tmp = start;
int counter = 2;
while (counter < nodeIndex && tmp->next != NULL){

tmp = tmp->next;
++counter;
}

insert->next = tmp->next;
tmp->next = insert;

length++;

}

//Delete Front Node
void DeleteFront(){

node * tmp = start;

start = tmp->next;
free(tmp);

length--;
}

//Delete End Node
void DeleteEnd(){

node * tmp = start;

while (tmp->next != NULL){
tmp = tmp->next;
}

node * secondlast = start;
while (secondlast->next->next != NULL){
secondlast = secondlast->next;
}

secondlast->next = NULL;
free(tmp);

length--;

}

//Delete Middle Node
void DeleteMiddle(){

node * tmp = start;
int counter = 1;
while (counter < nodeIndex && tmp->next != NULL){

tmp = tmp->next;
++counter;
}

node * fronttmp = start;
int counter2 = 1;
while (counter2 < nodeIndex - 1 && fronttmp->next != NULL){

fronttmp = fronttmp->next;
++counter2;
}

fronttmp->next = tmp->next;
free(tmp);

length--;

}

//Look Node up by Index
void LookUpByIndex(int index){

node * tmp = start;
int counter = 1;
while (counter < index && tmp != NULL){

tmp = tmp->next;
++counter;
}
printf("Displaying Selected Node at index %d\n", index);
printf("\t%s\n",tmp->firstname);
printf("\t%s\n",tmp->lastname);
printf("\t%s\n",tmp->PUID);
printf("\t%d\n",tmp->age);
printf("\n");
}

//Traverse
void Traverse (char * query){

node * tmp = start;
int count = 1;
bool succ = false;
while (tmp != NULL){

if (strcmp(query, tmp->firstname) == 0){
printf("Displaying Selected Node at index %d with query %s as First Name.\n", count, query);
printf("\t%s\n",tmp->firstname);
printf("\t%s\n",tmp->lastname);
printf("\t%s\n",tmp->PUID);
printf("\t%d\n",tmp->age);
printf("\n");
succ = true;
}

tmp = tmp->next;
++count;
}

if (succ == false)
printf("No results Found\n");

}
