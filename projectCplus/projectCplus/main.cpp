//
//  main.cpp
//  projectCplus
//
//  Created by Exo-terminal on 7/18/14.
//  Copyright (c) 2014 Evgenia. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <algorithm>


#define MAXSTACK 100000

#define ARR_SIZE 700000
//#define ARR_SIZE 2097152
//#define ARR_SIZE 4194304
//#define ARR_SIZE 8388608
//#define ARR_SIZE 16777216
//#define ARR_SIZE 33554432
//#define ARR_SIZE 67108864
//#define ARR_SIZE 110000000

#define RANGE 100000
//O(N2)
template<class T> void InsertionSort(T *A, int N);
template<class T> void selectSort(T a[], long size);
template<class T> void bubbleSort(T a[], long size);

//O(NlogN)
template<class T> void qSortI(T a[], long size);
template<class T> void MergeSort_recursion (T *array, size_t len, T* tmp);

int twoInPower (int minThreshold, int maxThreshold);

int comp( const void* a, const void* b )
{
   return ( *( int* )a - *( int* )b );

}

int main(int argc, const char * argv[])
{
    clock_t t;
    
//    int* arr = new int[ARR_SIZE];
//    float* arr = new float[ARR_SIZE];
    short* arr = new short[ARR_SIZE];
//      char* arr = new char[ARR_SIZE];
    
    
    srand((unsigned)time(NULL));
    
//    for (int i = 0; i < ARR_SIZE; i++) arr[i] = rand()%RANGE;//int
//    for (int i = 0; i < ARR_SIZE; i++) arr[i] = (float)(rand()%RANGE)/100;//float
    for (int i = 0; i < ARR_SIZE; i++) arr[i] = (short)(rand()%SHRT_MAX*2) - SHRT_MIN;//short
//      for (int i = 0; i < ARR_SIZE; i++) arr[i] = (char)(rand()%25 + 65);//char

//    for (int i = 0; i < ARR_SIZE; i++) printf("%d element = %c\n",i,arr[i]);
    
//    printf("%d, %d",SHRT_MAX ,SHRT_MIN);

    
    /*t = clock();
    std:qsort( arr, ARR_SIZE, sizeof( int ), comp);
    t = clock() - t;
    printf("time = %f",(float)t/CLOCKS_PER_SEC);
    printf("\n\n\n");
    for (int i = 0; i < ARR_SIZE; i++) printf("%d element = %d\n",i,arr[i]);*/

    
    /*t = clock();
    InsertionSort(arr, ARR_SIZE);
    t = clock() - t;
    printf("insertion sort time = %f",(float)t/CLOCKS_PER_SEC);*/
    
    
    /*t = clock();
    selectSort(arr, ARR_SIZE);
    t = clock() - t;
    printf("selection sort time = %f",(float)t/CLOCKS_PER_SEC);*/
    
    t = clock();
    bubbleSort(arr, ARR_SIZE);
    t = clock() - t;
    printf("bubble sort time = %f",(float)t/CLOCKS_PER_SEC);
    
    /*t = clock();
    qSortI(arr, ARR_SIZE);
    t = clock() - t;
    printf("quick sort time = %f",(float)t/CLOCKS_PER_SEC);
//   for (int i = 0; i < ARR_SIZE; i++) printf("%i element = %c\n",i,arr[i]);*/
    
//    float* arr1 = new float[ARR_SIZE];
//    float* arr1 = new float[ARR_SIZE];
//    short* arr1 = new short[ARR_SIZE];
//    char* arr1 = new char[ARR_SIZE];
    
   /* t = clock();
    MergeSort_recursion(arr, ARR_SIZE, arr1);
    t = clock() - t;
    
    printf("merge sort time = %f",(float)t/CLOCKS_PER_SEC);
//    for (int i = 0; i < ARR_SIZE; i++) printf("%i element = %i\n",i,arr[i]);*/

    
    
//    twoInPower(700000, 110000000);
    getchar();
    return (0);
}


//insertion sort
template<class T>
void InsertionSort(T *A, int N)
{
    if (N < 2) return;
    
    for (int i = 1; i < N; i++)
        for (int j = i; j && A[j] < A[j-1]; j--)
            std::swap(A[j], A[j-1]);
}

//selection sort
template<class T>
void selectSort(T a[], long size) {
    long i, j, k;
    T x;
    
    for( i=0; i < size; i++) {
        k=i; x=a[i];
        
        for( j=i+1; j < size; j++)
            if (  a[j] < x ) {
                k=j; x=a[j];
            }
        
        a[k] = a[i]; a[i] = x;
    }
}

//bubble sort
template<class T>
void bubbleSort(T a[], long size) {
    long i, j;
    T x;
    
    for( i=0; i < size; i++) {
        for( j = size-1; j > i; j-- ) {
            if ( a[j-1] > a[j] ) {
                x=a[j-1]; a[j-1]=a[j]; a[j]=x;
            }
        }
    }
}




//quick sort
template<class T>
void qSortI(T a[], long size) {
    
    long i, j;
    long lb, ub;
    
    long lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
    // каждый запрос задается парой значений,
    // а именно: левой(lbstack) и правой(ubstack)
    // границами промежутка
    long stackpos = 1;
    long ppos;
    T pivot;
    T temp;
    
    lbstack[1] = 0;
    ubstack[1] = size-1;
    
    do {
        
        lb = lbstack[ stackpos ];
        ub = ubstack[ stackpos ];
        stackpos--;
        
        do {
            
            ppos = ( lb + ub ) >> 1;
            i = lb; j = ub; pivot = a[ppos];
            do {
                while ( a[i] < pivot ) i++;
                while ( pivot < a[j] ) j--;
                if ( i <= j ) {
                    temp = a[i]; a[i] = a[j]; a[j] = temp;
                    i++; j--;
                }
            } while ( i <= j );
            
           
            if ( i < ppos ) {
                if ( i < ub ) {
                    stackpos++;
                    lbstack[ stackpos ] = i;
                    ubstack[ stackpos ] = ub;
                }
                ub = j;
            } else {
                if ( j > lb ) {
                    stackpos++;
                    lbstack[ stackpos ] = lb;
                    ubstack[ stackpos ] = j;
                }
                lb = i;
            }
        } while ( lb < ub );
    } while ( stackpos != 0 ); 
}


//merge sort
template<class T>
void MergeSort_recursion (T *array, size_t len, T* tmp) {
     if (len < 2) return;

     size_t middle = len / 2;
     MergeSort_recursion(array, middle, tmp);
     MergeSort_recursion(array + middle, len - middle, tmp);
     memcpy(tmp, array, middle * sizeof(array[0]));

     size_t i = 0, j = middle, k = 0;
     while (i < middle && j < len)
     array[k++] = (array[j] < tmp[i])?array[j++]:tmp[i++];
     while (i < middle)
     array[k++] = tmp [i++];
     }

template<class T>
void MergeSort(float *array, size_t len) {
     const size_t half_len = (len + 1) / 2;
     T *tmp = new T[half_len];
     MergeSort_recursion(array, len, tmp);
     delete[] tmp;
 }



 //search size of array
int twoInPower (int minThreshold, int maxThreshold)
{
    long int currentPowerValue = 2;
    long int currentPower = 2;
    
    while (true)
    {
        if (currentPowerValue >= maxThreshold)
        {
            break;
        }
        currentPowerValue = pow(2, currentPower);
        if (currentPowerValue >= minThreshold && currentPowerValue <maxThreshold)
        {
            printf("2^%li = %li\n", currentPower, currentPowerValue);
        }
        
        currentPower++;
    }
    
    return 0;
}