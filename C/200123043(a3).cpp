#include<bits\stdc++.h>
using namespace std;
int median(int arr[], int start, int m, int stop){
    if(arr[start]>arr[m] && arr[start]>arr[stop]){
        if(arr[m]>arr[stop]) return m;
        else return stop;
    }
    else if(arr[m]>arr[start] && arr[m]>arr[stop]){
        if(arr[start]>arr[stop]) return start;
        else return stop;
    }
    else{
        if(arr[start]>arr[m]) return start;
        else return m;
    }
}
void insertionSort(int arr[], int start, int stop){
    int key,j;
    for(int i=1;i<=stop;i++){
        key=arr[i];
        j=i-1;
            while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
                }
            arr[j+1]=key;
    }
}
int partstart(int arr[], int start, int stop){
    int pivot=arr[start];
    int pIndex=start+1;
    for(int i=start+1;i<=stop;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex-1],arr[start]);
    return pIndex-1;
}
int partstop(int arr[], int start, int stop){
    int pivot=arr[stop];
    int pIndex=start;
    for(int i=start;i<stop;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex],arr[stop]);
    return pIndex;
}
int partmedian(int arr[], int start, int stop){
    int d=stop+start,k=stop-start;
    int pIndexx=start,j=stop,temp;
    int pivot=arr[median(arr,start,d/2,stop)];
    while(pIndexx<=j){
        while(arr[pIndexx] < pivot)
                  pIndexx++;
            while(arr[j] > pivot)
                  j--;
            if(pIndexx<= j){
                  temp=arr[pIndexx];
                  arr[pIndexx]=arr[j];
                  arr[j]=temp;
                  pIndexx++;
                  j--;
            }
    }
    return pIndexx;

}
int QuickSortstart(int arr[], int start, int stop){
    int compcount=0;
    if(start<stop){
        compcount=stop-start;
        int pIndex=partstart(arr, start, stop);
        compcount+=QuickSortstart(arr,start,pIndex-1);
        compcount+=QuickSortstart(arr,pIndex+1,stop);
    }
    return compcount;
}
int QuickSortstop(int arr[], int start, int stop){
    int compcount=0;
    if(start<stop){
        compcount=stop-start;
        int pIndex=partstop(arr, start, stop);
        compcount+=QuickSortstop(arr,start,pIndex-1);
        compcount+=QuickSortstop(arr,pIndex+1,stop);
    }
    return compcount;
}
int QuickSortmedian(int arr[], int start, int stop){
    int compcount_m=0;
    if(stop-start>5){
        compcount_m=stop-start;
        int pIndexx=partmedian(arr, start, stop);
        compcount_m+=QuickSortmedian(arr,start,pIndexx-1);
        compcount_m+=QuickSortmedian(arr,pIndexx+1,stop);
    }
    else insertionSort(arr,start,stop);
    return compcount_m;
}
int main()
{
    string line;
    ifstream File1, File2;
    File1.open("a3test1.txt");
        int n=0;
        while(getline(File1, line))
            n++;
    File1.close();
        int arr[n];
    File2.open("a3test1.txt");
        int i=0;
        while(getline(File2, line)){
            arr[i] = (int)stoi(line);
            i++;
        }
        //cout<<"NUMBER OF COMPARISONS WITH FIRST ELEMENT AS PIVOT "<<QuickSortstart(arr,0,n-1);
        //cout<<"NUMBER OF COMPARISONS WITH LAST ELEMENT AS PIVOT "<<QuickSortstop(arr,0,n-1);
        //cout<<"NUMBER OF COMPARISONS WITH MEDIAN ELEMENT AS PIVOT "<<QuickSortmedian(arr,0,n-1);

        File2.close();
}
