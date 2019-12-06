#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int function1(int f);
int function2(int f);
void function3(int n, char x, char y, char z);
void function4(char *s, int b, int e);
void function5(char *s, int b, int e);
void binaryconversion(char ch, int i);
int function6(char *string, int start, int end, int sum);
int decimalconversion (int sum, int i);

int count = 0;
char binary [8] = "";
int cont = 0;
//main function
int main(){

while (cont != 7){
int option = 0;
int factoral = 0;
int factoral_ans = 0;
int fibonacci = 0;
int fibonacci_ans = 0;
int hanoi = 0;
char string[50] = "";
int asciisum = 0;
int sum = 0;

printf("Please Choose a Function:\n\n");
printf("Function 1 (Factorals)\n");
printf("Function 2 (Fibonacci Numbers)\n");
printf("Function 3 (Towers of Hanoi)\n");
printf("Function 4 (Reversing String)\n");
printf("Function 5 (ASCII Conversion)\n");
printf("Function 6 (Conversion Add ASCII to a Number)\n");
printf("Press any other key to go to exit screen.\n");

scanf(" %d", &option);

switch (option){

//function 1
case 1:
printf("What number factoral do you want to know?\n");
scanf("%d", &factoral);
factoral_ans = function1(factoral);

printf("= %d\n", factoral_ans);

count++;
break;

//function 2
case 2:
printf("Please enter the number of fibonacci sequence that you want to know.\n");
scanf("%d", &fibonacci);

for (int i = 1; i <= fibonacci; i++){
fibonacci_ans = function2(i);
printf("%d ",fibonacci_ans);
}
count++;
break;

//function 3
case 3:
printf("Please enter the solution with n amount of disks.\n");
scanf("%d", &hanoi);
function3(hanoi, 'A', 'C', 'B');
//A is source
//B is destination
//C is temporary
count++;
break;

//function 4
case 4:
printf("Please enter the string you want to reverse.\n");
scanf(" %[^\n]", string);

printf("The input is: %s\n", string);
function4(string, 0, strlen(string) - 1);
printf("The output is: %s\n", string);
count++;
break;

//function 5

case 5:
printf("Please enter the string you want to convert into binary.\n");
scanf(" %[^\n]", string);

function5(string, 0, strlen(string) - 1);
count++;
break;

//function 6
case 6:
printf("Please enter a string that will be summed together.\n");
scanf(" %[^\n]", string);

asciisum = function6(string, 0, strlen(string) - 1, 0);
printf("The sum of the ascii values are: %d\n", asciisum);
count++;
break;

default:
printf("Function not selected.\n");
}

printf("\nDo you want to continue the program?\n");
printf("Press 7 to quit. Press any number to continue.\n");
scanf("%d", &cont);
}
printf("Number of Functions ran: %d\n", count);
return count;

}

//funciton 1
int function1(int factoral){
int answer = 0;

//original code from lab manual
if (factoral == 1){

printf("1 ");	
return 1;
		
}else{

printf("%d * ", factoral);
return factoral = factoral*function1(factoral-1);

}
}

//function 2
int function2 (int fibonacci){

int answer = 0;

if (fibonacci <= 2){

return 1;

}else{

return function2(fibonacci - 1) + function2 (fibonacci - 2);

}
}

//function 3
void function3(int n, char x, char y, char z){
if (n == 1){

printf("Top Disk move from %c to %c\n", x, z );

}else{
//following code from lab manual
function3(n-1,x,z,y);
function3(1,x,y,z);
function3(n-1,y,x,z);
}
}

//function 4 
void function4(char *string, int start, int end){

char temp = 0;
if (end <= start){
return;
}

//help from TA
temp = string[start];
string[start] = string[end];
string[end] = temp;

function4(string, start + 1, end - 1);

}

//function 5
void function5(char *string, int start, int end){

if (end < start){
return;
}

binaryconversion(string[start], 7);
printf("%s", binary);

function5(string, ++start, end);

}

//binary conversion to string
void binaryconversion (char target, int i){

if (target == 0 && i == 0){
binary[i] = '0';
return;
}
else{
 
if (target%2 == 1){
binary[i] = '1';
}else{
binary[i] = '0';
}

binaryconversion (target/2,  i - 1);

}
}


//function 6
int function6(char *string, int start, int end, int sum){

if (end < start){
return sum;
}

binaryconversion(string[start], 7);
sum = sum + decimalconversion(0, 7);

function6(string, ++start, end, sum);

}

//decimal conversion
int decimalconversion (int sum, int i){

if (i < 0){
return sum;
}

if (binary[i] == '1'){
sum = sum + pow(2, 7 - i);
}else{
sum = sum + 0;
}

decimalconversion (sum, i - 1);

}
