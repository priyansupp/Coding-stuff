#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void swap(int16_t *x, int16_t *y){
    int t=*x;
    *x=*y;
    *y=t;
}
void insertionSort(int16_t arr[], int n){
    int key,j;             //insertionSort
        for(int i=1;i<n;i++){
            key=arr[i];
            j=i-1;
            while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
                }
            arr[j+1]=key;
            }
}
void bubbleSort(int16_t arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void selectionSort(int16_t arr[], int n){
    for(int i=0;i<n-1;i++){
           int min_ind=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min_ind]){
            min_ind=j;
        }
        }
        swap(&arr[i],&arr[min_ind]);
}
}
int main()
{
        for(int n=10;n<=100000; n=n*10){
            int16_t arr[n];
            srand(time(0));
            for(int i=0;i<n;i++){
                arr[i]=rand();
            }
            auto start = high_resolution_clock::now();
            insertionSort(arr, n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout <<"Time for insertion sort for RANDOM ARRAY for n= "<<n<<" is "<< duration.count() << endl;
            auto start1 = high_resolution_clock::now();
            insertionSort(arr, n);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
            cout <<"Time for insertion sort for SORTED ARRAY for n= "<<n<<" is "<< duration1.count() << endl;
            reverse(arr, arr + n);
            auto startr = high_resolution_clock::now();
            insertionSort(arr, n);
            auto stopr = high_resolution_clock::now();
            auto durationr = duration_cast<nanoseconds>(stopr - startr);
            cout <<"Time for insertion sort for REVERSE SORTED ARRAY for n= "<<n<<" is "<< durationr.count() <<"\n"<< endl;

            srand(time(0));
            for(int i=0;i<n;i++){
                arr[i]=rand();
            }
            auto start2 = high_resolution_clock::now();
            bubbleSort(arr, n);
            auto stop2 = high_resolution_clock::now();
            auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
            cout <<"Time for bubble sort for RANDOM ARRAY for n= "<<n<<" is "<< duration2.count() << endl;
            auto start3 = high_resolution_clock::now();
            bubbleSort(arr, n);
            auto stop3 = high_resolution_clock::now();
            auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
            cout <<"Time for bubble sort for SORTED ARRAY for n= "<<n<<" is "<< duration3.count() << endl;
            reverse(arr, arr + n);
            auto startrr = high_resolution_clock::now();
            bubbleSort(arr, n);
            auto stoprr = high_resolution_clock::now();
            auto durationrr = duration_cast<nanoseconds>(stoprr - startrr);
            cout <<"Time for bubble sort for REVERSE SORTED ARRAY for n= "<<n<<" is "<< durationrr.count() <<"\n"<< endl;

            srand(time(0));
            for(int i=0;i<n;i++){
                arr[i]=rand();
            }
            auto start4 = high_resolution_clock::now();
            selectionSort(arr, n);
            auto stop4 = high_resolution_clock::now();
            auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
            cout <<"Time for selection sort for RANDOM ARRAY for n= "<<n<<" is "<< duration4.count() << endl;
            auto start5 = high_resolution_clock::now();
            selectionSort(arr, n);
            auto stop5 = high_resolution_clock::now();
            auto duration5 = duration_cast<nanoseconds>(stop5 - start5);
            cout <<"Time for selection sort for SORTED ARRAY for n= "<<n<<" is "<< duration5.count() << endl;
            reverse(arr, arr + n);
            auto startrrr = high_resolution_clock::now();
            selectionSort(arr, n);
            auto stoprrr = high_resolution_clock::now();
            auto durationrrr = duration_cast<nanoseconds>(stop5 - start5);
            cout <<"Time for selection sort for REVERSE SORTED ARRAY for n= "<<n<<" is "<< durationrrr.count() <<"\n"<< endl;
            cout<<"\n";

        }
}
