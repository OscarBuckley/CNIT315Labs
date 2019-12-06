#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sequentialarray(int** array, int* size);
void shufflearray(int** array, int* size);
void evaluation(int** array, int* size);
void bubblesort (int* array, int length);
void insertionsort (int* array, int length);
void selectionsort(int* array, int length);
int LinearSearch (int* array, int length, int query);
int BinarySearch (int* array, int start, int end, int query);

//main
int main (){

int ten[10];
int fifty[50];
int hundred[100];
int fivehundred[500];
int thousand[1000];
int fivethousand[5000];
int tenthousand[10000];
int twentyfivethousand[25000];
int fiftythousand[50000];

int *pointers[9] = {ten, fifty, hundred, fivehundred, thousand, fivethousand, tenthousand, twentyfivethousand, fiftythousand};
int size[9] = {10, 50, 100, 500, 1000, 5000, 10000, 25000, 50000};

//generating sequential array
sequentialarray(pointers, size);


//evaluation function
evaluation(pointers, size);


}











//outside of main function

//seqential array
void sequentialarray(int** pointers, int* size){

for (int j = 0; j < 9; j++){

int length = size[j];

for (int i = 0; i < length; i++){

pointers[j][i] = i;

}

}

}








//evaluation function
void evaluation(int** pointers, int* size){

//shuffling array
shufflearray(pointers, size);

//bubble sort
for (int i = 0;i < 9; i ++){

clock_t start = clock();
bubblesort(pointers[i], size[i]);
clock_t end = clock();

double time = (double)(end - start)/CLOCKS_PER_SEC;

printf("Array Size of %d using Bubble Sort took %lf seconds.\n", size[i], time);

}

//shuffling array
shufflearray(pointers, size);

//selection sort
for (int i = 0;i < 9; i ++){

clock_t start = clock();
selectionsort(pointers[i], size[i]);
clock_t end = clock();

double time = (double)(end - start)/CLOCKS_PER_SEC;

printf("Array Size of %d using Selection Sort took %lf seconds.\n", size[i], time);

}

//shuffling array
shufflearray(pointers, size);

//insertion sort
for (int i = 0;i < 9; i ++){

clock_t start = clock();
insertionsort(pointers[i], size[i]);
clock_t end = clock();

double time = (double)(end - start)/CLOCKS_PER_SEC;

printf("Array Size of %d using Insertion Sort took %lf seconds.\n", size[i], time);

}

//binary search
for (int i = 0;i < 9; i ++){

int key = rand()%size[i];
clock_t start = clock();
int index = BinarySearch (pointers[i], 0, size[i], key);
clock_t end = clock();

double time = (double)(end - start)/CLOCKS_PER_SEC;

printf("Binary Search Array Size of %d took %lf seconds finding %d at %d index.\n", size[i], time, key, index);

}

//linear search
for (int i = 0;i < 9; i ++){

int key = rand()%size[i];
clock_t start = clock();
int index = LinearSearch (pointers[i], size[i], key);
clock_t end = clock();

double time = (double)(end - start)/CLOCKS_PER_SEC;

printf("Linear Search Array Size of %d took %lf seconds finding %d at %d index.\n", size[i], time, key, index);

}

}











//shuffling array
//code referenced from https://www.youtube.com/watch?v=LP7YQdT5eps
void shufflearray(int** pointers, int* size){

for (int k = 0; k < 9; k++){

srand(time(NULL));

int length = size[k] - 1;

while (length > 0){

int j = rand()%(length+1);

int temp = pointers[k][length];
pointers[k][length] = pointers[k][j];
pointers[k][j] = temp;


length--;
}

}
}

//bubble sort
//code referenced from slide on Blackboard
void bubblesort (int* array, int length){

int i, j;
int temp;

for (i = 0; i < length - 1; i++ ){

for(j = 0; j < length - i - 1; j++){

if(array[j] > array[j + 1]){

temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;

}

}

}

}

//insertion sort
//code from geeksforgeeks.org at https://www.geeksforgeeks.org/c-program-for-insertion-sort/
void insertionsort(int arr[], int n) 
{ 
int i, key, j; 
for (i = 1; i < n; i++) { 
key = arr[i]; 
j = i - 1; 
  
while (j >= 0 && arr[j] > key) { 
arr[j + 1] = arr[j]; 
j = j - 1; 

} 

arr[j + 1] = key; 
} 

} 

//selection sort
//code from TA
void selectionsort(int* array, int length){

	int i, j, least;

	for(i = 0; i < length - 1; i++){
	 
		least = i;

		for(j = i + 1; j < length; j++){

			if (array[least] > array[j]){
				least = j;

			}

		}
				int tmp = array[least];
				array[least] = array[i];
				array[i] = tmp;

}

}

//Linear Search
//Code from Blackboard
int LinearSearch (int* array, int length, int query){

int index = -1;
for(int i = 0 ; i < length ; i++) {	

if(query == array[i]) {
index = i;
break;
}

}   
return index;
}

//Binary Search
//Code from TA
int BinarySearch (int* array, int start, int end, int query){

int middle = (start + end)/2;

if(array[middle] == query){

return middle;

}else if (array[middle] > query){

BinarySearch(array, start, middle - 1, query);

}else if(array[middle] < query){

BinarySearch(array, middle + 1, end, query);

}else return -1;
}

