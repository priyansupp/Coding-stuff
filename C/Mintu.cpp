#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition1 (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int quickSort1(int arr[], int low, int high)
{
    int comparisons1 = 0;
	if (low < high)
	{
	    comparisons1 =high-low;
		int pi = partition1(arr, low, high);
		comparisons1+=quickSort1(arr, low, pi - 1);
		comparisons1+=quickSort1(arr, pi + 1, high);
	}
	return comparisons1;
}

int partition2 (int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = (low + 1);

	for (int j = low + 1; j <= high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i - 1], &arr[low]);
	return (i - 1);
}

int quickSort2(int arr[], int low, int high)
{
    int comparisons2 = 0;
	if (low < high)
	{
        comparisons2 = high - low;
        int pi = partition2(arr, low, high);
        comparisons2 += quickSort2 (arr, low, pi -1);
        comparisons2 += quickSort2 (arr, pi +1, high);
	}
	return comparisons2;
}

int main()
{
  int A1[10];
  unsigned long int i = 0;
  ifstream ifl2("a3test1.txt");
  while (!ifl2.eof()) {
    int s;
    ifl2 >> s;
    A1[i] = s;
    i++;
  }
  ifl2.close();

  int A2[100];
  unsigned long int m = 0;
  ifstream ifl3("a3test1.txt");
  while (!ifl3.eof()) {
    int l;
    ifl3 >> l;
    A2[m] = l;
    m++;
  }
  ifl3.close();
  //cout<<A2[2];
  //quickSort1(A1, 0, 9);

  cout <<quickSort2(A1, 0, 9)<<endl;

	return 0;
}

// This code is contributed by rathbhupendra
