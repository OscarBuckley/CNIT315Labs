#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main () {

//loop

for (;;){

float HT_width = 0;
float HT_depth = 0;
float DP_length = 0;
float MI_length = 0;
float SH_length = 0;
float length = 0;
float width = 0;
float SH_depth = 0;
float DP_depth = 0;

float HT_volume = 0;
float PL_volume = 0;
float HT_gallons = 0;
float PL_gallons = 0;
float TTL_cost = 0;
float TTL_gallons = 0;

char cont;

//entering data

//shallow end depth

do{
printf("Please Enter the Depth of the Shallow end.\n");
scanf("%f", &SH_depth);

if(SH_depth <= 0 || SH_depth > 5){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 0 AND 5 FEET!!!!\n");
}

} while (SH_depth <= 0 || SH_depth > 5);

//deep end depth
do{
printf("Please Enter the Depth of the Deep end.\n");
scanf("%f", &DP_depth);

if(DP_depth < 6 || DP_depth > 15){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 6 AND 15 FEET!!!!\n");
}

} while (DP_depth < 6 || DP_depth > 15);

//width
do{
printf("Please Enter the Width of the pool.\n");
scanf("%f", &width);

if(width < 15 || width > 30){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 15 AND 30 FEET!!!!\n");
}

} while (width < 15 || width > 30);

//total length
do{
printf("Please Enter the Length of the pool.\n");
scanf("%f", &length);


if(length < 35 || length > 70){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 35 AND 30 FEET!!!!\n");
}

} while (length < 35 || length > 70);

//length middle walk in
do{
printf("Please Enter the Length of the Walk-in.\n");
scanf("%f", &MI_length);

if(MI_length < 5 || MI_length > length/3){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 5 FEET TO A THIRD OF THE POOL'S LENGTH!!!!\n");
}

} while (MI_length < 5 || MI_length > length/3);

//length shallow end
do{
printf("Please Enter the Length of the Shallow end.\n");
scanf("%f", &SH_length);

if(SH_length < 5 || SH_length > length/3){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 5 FEET TO HALF OF THE POOL'S LENGTH!!!!\n");
}

} while (SH_length < 5 || SH_length > length/3);

//length deep end
do{
printf("Please Enter the Length of the Deep end.\n");
scanf("%f", &DP_length);

if(DP_length < 10 || DP_length > length/2){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 10 FEET TO HALF OF THE POOL'S LENGTH!!!!\n");
}

} while (DP_length < 10 || DP_length > length/2);


//hot tub width
do{
printf("Please Enter the Width of the Hot Tub.\n");
scanf("%f", &HT_width);

if(HT_width < 8 || HT_width > 14){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 8 TO 14 FEET!!!!\n");
}

} while (HT_width < 8 || HT_width > 14);

//hot tub depth
do{
printf("Please Enter the Depth of the Hot Tub.\n");
scanf("%f", &HT_depth);

if(HT_depth < 3 || HT_depth > 5){
printf("THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 3 TO 5 FEET!!!!\n");
}

} while (HT_depth < 3 || HT_depth > 5);


//calculations

//hot tub volume
HT_volume = pow(HT_width/2, 2) * (HT_depth - 0.5) * M_PI;

//pool volume
PL_volume = (DP_length * DP_depth * width) + (SH_length * SH_depth * width) + ((MI_length * SH_depth* width)/2) + ((length - DP_length - SH_length - MI_length) * width * SH_depth) + (((length - DP_length - SH_length - MI_length) * (DP_depth - SH_depth) * width)/2) - (length *width *.5);

//hot tub gallons
HT_gallons = HT_volume*7.481;

//pool gallons
PL_gallons = PL_volume*7.481;

//total volume
TTL_gallons = HT_gallons + PL_gallons;

//total cost
TTL_cost = TTL_gallons*4*.07;

//output
printf("POOL VOLUME\n");
printf("Total Volume of pool: %f\n", PL_volume);
printf("Gallons of Water to fill: %f\n", PL_gallons);

printf("HOT TUB VOLUME\n");
printf("Total Volume of Hot Tub: %f\n", HT_volume);
printf("Gallons of Water to fill: %f\n", HT_gallons);

printf("Total gallons for both: %f\n", TTL_gallons);
printf("Total cost for both: %f Dollars.\n", TTL_cost);
fflush(stdin);

//continue
printf("Do you want to continue?\nPress Q to quit, press any other key to continue.\n");

scanf(" %c", &cont);

if (cont == 'q' || cont == 'Q'){
exit(0);
}else{
printf("Continuing Program.\n");
}

}

return 0;


}
