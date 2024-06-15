#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

// Name    :  Prem Kumar
// Roll No :  200123042

using namespace std;

int quickSort1(int testcases[], int lower, int higher);
int partition1(int testcases[], int lower, int higher);
int quickSort2(int testcases[], int lower, int higher);
int partition2(int testcases[], int lower, int higher);
int quickSort3(int testcases[], int lower, int higher);
int partition3(int testcases[], int lower, int higher);

int insertionSort(int testcases[], int lower, int higher);

int main()
{
    // To count the number of lines in a text file
    int counts = 0;
    string linecount;
    ifstream is("a3test1.txt");
    if(is.is_open())
    {
        while(!is.eof())
        {
            getline(is,linecount);
            //cout << linecount << endl;
            counts++;
        }
        counts--;
        is.close();
    }
    // To get the input from a text file
    ifstream file("a3test1.txt");
    //cout << counts;

    int testcases[counts];
    int a;
    int countable = 0;
    while (countable < testcases[counts] && file>>a)
        testcases[countable++] = a;

    int comparisons;
    int z;
    int testcases2[counts],testcases3[counts];
    for (z=0;z<counts;z++)
    {
        testcases2[z]=testcases[z];
        testcases3[z]=testcases[z];
    }
    // Pivot Element First Element
    cout << "The total number of comparisons for pivot as first element  : " << quickSort2(testcases,0,counts-1) << endl;
    // Pivot Element Last Element
//    comparisons = quickSort1(testcases2,0,counts-1) ;
//    cout << "The total number of comparisons for pivot as last element : " << comparisons << endl;
//    // Pivot Element Middle Element
//    comparisons = quickSort3(testcases3,0,counts-1) ;
//    cout << "The total number of comparisons for pivot as last element : " << comparisons << endl;
    file.close();
    return 0;
}
int partition1 (int testcases[], int lower, int higher)
{
    int pivotelement = testcases[higher]; // pivot
    int i = lower; // Index of smaller element and indicates the right position of pivot found so far
    int j ;

    for (j = lower; j < higher; j++)
    {
        // If current element is smaller than the pivot
        if (testcases[j] <= pivotelement)
        {
            swap(testcases[j],testcases[i]);
            i++;
        }
    }
    swap(testcases[i],testcases[higher]);
    return i;
}

int quickSort1(int testcases[], int lower, int higher)
{
    int compare=0;
    if (lower<higher)
    {
        int part = partition1(testcases, lower, higher);
        compare += higher - lower;
        quickSort1(testcases, lower, part - 1);
        quickSort1(testcases, part + 1, higher);
    }
        return compare;
    //else
        //insertionSort (testcases,lower,higher);
        //return compare;
}



int quickSort2(int testcases[], int lower, int higher)
{
    int compare=0;
    if (lower<higher)
    {
        int part = partition2(testcases, lower, higher);
        compare = higher - lower;
        compare+=quickSort2(testcases, lower, part - 1);
        compare+=quickSort2(testcases, part + 1, higher);
    }
        return compare;
    //else
        //insertionSort (testcases,lower,higher);
        //return compare;
}

int partition2 (int testcases[], int lower, int higher)
{
    int pivotelement = testcases[lower]; // pivot
    int i = (lower + 1); // Index of smaller element and indicates the right position of pivot found so far
    int j ;

    for (j = lower+1; j <= higher; j++)
    {
        // If current element is smaller than the pivot
        if (testcases[j] <= pivotelement)
        {
            swap(testcases[j],testcases[i]);
            i++; // increment index of smaller element
        }
    }
    swap(testcases[i-1],testcases[lower]);
    return (i -1);
}

int quickSort3(int testcases3[], int lower, int higher)
{
    int compare=0;
    if (lower<higher)
    {
        compare = higher - lower;
        int part = partition3(testcases3, lower, higher);
        compare+=quickSort3(testcases3, lower, part - 1);
        compare+=quickSort3(testcases3, part + 1, higher);
    }
        return compare;
    //else
        //insertionSort (testcases,lower,higher);
        //return compare;
}

int partition3 (int testcases3[], int lower, int higher)
{
    int pivotelement = testcases3[higher]; // pivot
    int i = (lower - 1); // Index of smaller element and indicates the right position of pivot found so far
    int j ;
    int swape;

    for (j = lower+1; j <= higher; j++)
    {
        // If current element is smaller than the pivot
        if (testcases3[j] <= pivotelement)
        {
            i++; // increment index of smaller element
            swape = testcases3[i+1];
            testcases3[i+1]=testcases3[j];
            testcases3[j]=swape;
        }
    }
    swape = testcases3[i];
    testcases3[i]=testcases3[lower];
    testcases3[lower]=swape;
    return (i + 1);
}


/*int insertionSort(int testcases[], int lower, int higher)
{
    int p;
    int q;
    int i;
    for (i=1;i<=higher;i++)
    {
        p = testcases[i];
        q=i-1;
        while (q>=0 && testcases[q]>p)
        {
            testcases[q+1]=testcases[q];
            q--;
        }
        testcases[q+1]=p;
    }
}*/






