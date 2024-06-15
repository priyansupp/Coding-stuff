#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//declaring the structure named PC with SerialNumber, Year and Price as its fields.

struct PC{
    int SerialNumber;
    int Year;
    int Price;
};


int main()
{
    //asking for number of PCs
    printf("Enter the total number of PCs \n");
    int n;
    scanf("%d",&n);     //storing number of PCs in variable n.

    //declaring array of size n of structure PCs using dynamic memory allocation (malloc).

    struct PC* arr=(struct PC*)malloc(n*sizeof(struct PC));

    //now the variable 'arr' points to array of structure PCs and each PC can be reached using
    // arr[0],arr[1],arr[2], etc.

    //asking user to fill detais of each of n PCs
    printf("Fill the details for each PC \n");
    for(int i=0;i<n;i++){
        int S,Y,P;
        printf("Enter SerialNumber, Year and Price of PC %d : \n",i+1);
        scanf("%d%d%d",&S,&Y,&P);
        arr[i].SerialNumber=S;      //storing SerialNumber of PC in SerialNumber field of structure PC.
        arr[i].Year=Y;              //storing Year of PC in Year field of structure PC.
        arr[i].Price=P;             //storing Price of PC in Price field of structure PC.
    }

    printf("For PCs with Price 700KD or less, the SerialNumber, Year and Price respectively is: \n");
    for(int j=0;j<n;j++){                       //a for loop to test for each PC
        if(arr[j].Price<=700){                  //comparing Price of each PC
            printf("%d %d %d ", arr[j].SerialNumber, arr[j].Year, arr[j].Price);  //printing PC details if it satisfies the condition
            printf("\n");
        }
    }

    int sum=0;
    for(int k=0;k<n;k++){
        sum+=arr[k].Year;   //calculating sum of year of all the PCs
    }

    int avg=sum/n;         // calculating average of year i.e sum/(total number of PCs)

    printf("Average Year of all the PCs is: %d", avg);   //printing the average value

    return 0;
}
