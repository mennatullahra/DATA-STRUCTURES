#include <iostream>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
using namespace std;
using namespace std::chrono;

// This is for merge sorting
void merge(int *, int, int, int);

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

void merge(int *a, int low, int high, int mid)
{
    int i, j, k;
    int c[100000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
//this is for quick sorting
void RandomShuffle(int arr[])
{
    srand(time(NULL));
    int i, j, temp;
    for (i = MAX - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Partition(int a[], int beg, int end)
{

    int pivotIndex = beg + rand()%(end - beg + 1); //generates a random number as a pivot
    int pivot;
    int i = beg - 1;
    int j;
    pivot = a[pivotIndex];
    Swap(&a[pivotIndex], &a[end]);
    for (j = beg; j < end; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            Swap(&a[i], &a[j]);
        }

    }
    Swap(&a[i+1], &a[end]);
    return i + 1;
}


void QuickSort(int arr[], int start, int End)
{
    int j;
    if (start < End)
    {
        j = Partition(arr, start, End);
       QuickSort(arr,start, j-1);
       QuickSort(arr, j+1, End);
    }
}

int main() {

    int i;
    int j;
    int arr[MAX];
    for (i = 0; i < MAX; i++)
        arr[i] = i;
    RandomShuffle(arr); //To randomize the array
    QuickSort(arr, 0, MAX-1);//The quick sorting

    mergesort(arr, 0, MAX-1 ); // the merge sorting

    auto start = high_resolution_clock::now();
    QuickSort(arr, 0, 5000-1);
    auto finish = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(finish - start);
    cout << "QuickSort time of 5000 size array= "<< duration.count() << " msec" << endl;

    start = high_resolution_clock::now();
    mergesort(arr,0,5000-1);
    finish = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(finish - start);
    cout << "Merge sort time of 5000 size array= "<< duration.count() << " msec" << endl;

    start= high_resolution_clock::now();
    QuickSort(arr, 0, 10000-1);
    finish = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(finish - start);
    cout << "QuickSort time of 10000 size array= "<< duration.count() << " msec" << endl;

    start = high_resolution_clock::now();
    mergesort(arr,0,10000-1);
    finish = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(finish - start);
    cout << "Merge sort time of 10000 size array= "<< duration.count() << " msec" << endl;

    start= high_resolution_clock::now();
    QuickSort(arr, 0, MAX-1);
    finish = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(finish - start);
    cout << "QuickSort time of 100000 size array= "<< duration.count() << " msec" << endl;

    start = high_resolution_clock::now();
    mergesort(arr,0,MAX-1);
    finish = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(finish - start);
    cout << "Merge sort time of 100000 size array= "<< duration.count() << " msec" << endl;
    return 0;
}
