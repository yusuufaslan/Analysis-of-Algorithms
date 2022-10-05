/*
author:     @yusuufaslan
date:       5 October 2022
         
Insertion Sort Algorithm: 

To sort an array of size N in ascending order: 

Iterate from arr[1] to arr[N] over the array. 
Compare the current element (key) to its predecessor. 
If the key element is smaller than its predecessor, 
compare it to the elements before. Move the greater elements 
one position up to make space for the swapped element.

Time Complexity: O(N^2) 
Auxiliary Space: O(1)

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

void insertionSort(vector<int>& arr) {
    int i, j, key;

    for (int i = 1; i < arr.size(); i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(vector<int>& arr) {
    for (auto i: arr)
        cout << i << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> arr= {12, 11, 13, 5, 6};
    
    printArray(arr);
    insertionSort(arr);
    printArray(arr);

    return 0;
}
