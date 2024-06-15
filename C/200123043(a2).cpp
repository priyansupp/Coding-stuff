#include<bits/stdc++.h>
using namespace std;
long long mergeSort(long long arr[], long long subarr[], long long lt, long long r);
long long merging(long long arr[],long long subarr[], long long lt, long long mid, long long r);

long long mergeSortans(long long arr[], long long arrsize)
{
    long long subarr[arrsize];
    return mergeSort(arr, subarr, 0, arrsize-1);
}


long long mergeSort(long long arr[], long long subarr[], long long lt, long long r){
    long long mid, icount=0;
    if(r>lt){
        mid=(r+lt)/2;
        icount=icount+mergeSort(arr, subarr, lt, mid);
        icount=icount+mergeSort(arr, subarr, mid+1, r);
        icount=icount+merging(arr, subarr, lt,mid+1,r);
    }
    return icount;
}
long long merging(long long arr[],long long subarr[], long long lt, long long mid, long long r){
    long long i,j,k;
    long long icount=0;
    i=lt; j=mid; k=lt;
    while((i<=mid-1)&&(j<=r)){
        if(arr[i]<=arr[j]){
            subarr[k++]=arr[i++];
        }
        else{
            subarr[k++]=arr[j++];
            icount=icount+(mid-i);
        }
    }
    while (i <= mid - 1)
        subarr[k++] = arr[i++];
    while (j <= r)
        subarr[k++] = arr[j++];
    for (i=lt; i<=r; i++)
        arr[i] = subarr[i];

    return icount;
}


int main()
{
    string line;
    ifstream File1, File2;
    File1.open("tstcase1.txt");
        long long n=0;
        while(getline(File1, line))
            n++;
    File1.close();
        long long arr[n];
    File2.open("tstcase1.txt");
        long long i=0;
        while(getline(File2, line)){
            arr[i] = (long long)stoi(line);
            i++;
        }


        long long inversions = mergeSortans(arr, n);
        cout << "Number of inversions in test case 1 are "<<inversions<<endl;;

    File2.close();
    return 0;
}
