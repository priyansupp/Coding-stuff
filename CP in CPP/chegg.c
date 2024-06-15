#include<stdio.h>
#include<math.h>
#include <stdlib.h>

float min(float a, float b){            // minimum function for finding minimum of the two values
    if(a > b) return b;
    return a;
}
float max(float a, float b){            // maximum function for finding maximum of the two values
    if(a < b) return b;
    return a;
}
int main()
{
    int count;
    float mini, maxi;
    FILE * fpointer = fopen("chegginput.txt", "r");     // pointer to the data file. I have used the name "chegginput.txt", use your own file name
    fscanf(fpointer, "%d %f %f", &count, &mini, &maxi); // scanning through file
    float x[count], xlow, xhigh;                        // declaring array to store input of numbers. xmin amd xmax store minimum and maxinum values from the list.
    for(int i = 0; i < count; i++){
        fscanf(fpointer, "%f", &x[i]);
        if(i == 0){                                     // initializing xmin, xmax when i == 0
            xlow = x[i];
            xhigh = x[i];
        }
        xlow = min(xlow, x[i]);                         // comparing and updating xmin, xmax each time a new value is scanned.
        xhigh = max(xhigh, x[i]);
    }
    float normx[count];                                 // array of normalized values
    for(int i = 0; i < count; i++){
        normx[i] = mini + (x[i] - xlow) * (maxi - mini) / (xhigh - xlow);   // applying the normalization formula on each element.
    }
    printf("Original values         Normalized values\n");      // column names
    for(int i = 0; i < count; i++){
        printf("%.1f                    %.1f\n", x[i], normx[i]);   // printing values alongside the column name one by one. %.1f denotes 1 decimal digit in floating number.
    }
    return 0;
}