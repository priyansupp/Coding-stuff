#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    char rollNo[10];
    float CGPA;
    char name[20];
} data;

bool comp(char* ptr1, char* ptr2) {
    bool flag = false;
    int i = 0, j = 0;
    while(ptr1[i] != '\0' && ptr2[i] != '\0') {
        char temp1 = ((ptr1[i] >= 'a' && ptr1[i] <= 'z') || ptr1[i] == ' ') ? ptr1[i] : ptr1[i] + 32;
        char temp2 = ((ptr2[j] >= 'a' && ptr2[j] <= 'z') || ptr2[j] == ' ') ? ptr2[j] : ptr2[j] + 32;
        if(temp1 < temp2) {
            flag = true;
            break;
        }
        if(temp1 > temp2)
            break;
        i++;j++;
    }
    if(ptr1[i] == '\0')
        flag = true;
    return flag;
}

void merge(data arr[], int i, int mid, int j) {
    int p,q,r;
    int size1 = mid-i+1;
    int size2 = j-mid;
    data temp1[size1], temp2[size2];
    for(p = 0; p < size1; p++)
        temp1[p] = arr[i + p];
    for(p = 0; p < size2; p++)
        temp2[p] = arr[mid + 1 + p];
    p = 0; q = 0; r = i;
    while(p < size1 && q < size2) {
        arr[r++] = comp(temp1[p].name, temp2[q].name) ? temp1[p++] : temp2[q++];
    }
    while(p < size1)
        arr[r++] = temp1[p++];
    while(q < size2)
        arr[r++] = temp2[q++];
}

void mergeSort(data arr[], int i, int j) {
    if(i == j)
        return;
    else {
        int mid = (i+j)/2;
        mergeSort(arr, i, mid);
        mergeSort(arr, mid+1, j);
        merge(arr, i, mid, j);
    }
}
int main() {
    int n = 7;
    FILE *fp;
    int lines;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &lines);
    char c;
    fscanf(fp, "%c", &c);
    data arr[lines];
    for(int i = 0; i < lines; i++){
        fgets(arr[i].rollNo, 10, fp);
        // fscanf(fp, "%c", &c);

        fscanf(fp, "%f", &arr[i].CGPA);
        // fscanf(fp, "%c", &c);

        fgets(arr[i].name, 20, fp);
        // printf("NAME read: %s\n ", name);
        // fscanf(fp, "%c", &c);
    }
    fclose(fp);
    mergeSort(arr, 0, n-1);
    fp = fopen("output.txt", "w");
    for(int i = 0; i < n; i++) {
        fputs(arr[i].name, fp);
        fputs("\t", fp);
        fputs(arr[i].rollNo, fp);
        fputs("\t", fp);
        fprintf(fp, "%.2f", arr[i].CGPA);
        fputs("\n", fp);
        // printf("%-12s\t\t %-12s\t\t %8.2f\n",arr[i].name,arr[i].rollNo, arr[i].CGPA);
    }
    fclose(fp);
    
    return 0;
}