/*
author:     @yusuufaslan
date:       5 October 2022
         
Merge Sort Algorithm: 

To sort an array of size N in ascending order: 

MergeSort(A, p, r):
    if p > r 
        return
    q = (p+r)/2
    mergeSort(A, p, q)
    mergeSort(A, q+1, r)
    merge(A, p, q, r)

Time Complexity:
Best Case Complexity: O(n*log n)
Worst Case Complexity: O(n*log n)
Average Case Complexity: O(n*log n)

Space Complexity:
The space complexity of merge sort is O(n).

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

void merge(int* array, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    
    int leftSubArray[size1];
    int rightSubArray[size2];


    for (int i = 0; i < size1; i++)
        leftSubArray[i] = array[left + i];

    for (int j = 0; j < size2; j++)
        rightSubArray[j] = array[mid + 1 + j];
    
    // Maintain current index of sub-arrays and main array
    int i = 0, j = 0, k = left;
    
    while (i < size1 && j < size2) {
        if (leftSubArray[i] <= rightSubArray[j]) {
            array[k] = leftSubArray[i];
            i++;
        } 
        else {
            array[k] = rightSubArray[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either leftSubArray or rightSubArray,
    // pick up the remaining elements and put in A[left...right]
    while (i < size1) {
        array[k] = leftSubArray[i];
        i++;
        k++;
    }
    
    while (j < size2) {
        array[k] = rightSubArray[j];
        j++;
        k++;
    }
}

void mergeSort(int* array, int left, int right) {
    if (left >= right)
        return;
    
    int mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int array[] = {12, 11, 13, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    printArray(array, size);
    mergeSort(array, 0, size - 1);
    printArray(array, size);

    return 0;
}