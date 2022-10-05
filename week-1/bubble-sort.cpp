/*
author:     @yusuufaslan
date:       5 October 2022
         
Bubble Sort Algorithm: 

To sort an array of size N in ascending order: 

Run a nested for loop to traverse the input array using two variables i and j, 
such that 0 ≤ i < n-1 and 0 ≤ j < n-i-1 or 
such as 1 ≤ i < n and 0 ≤ j < n-1 and with a swapped flag
If arr[j] is greater than arr[j+1] then swap these adjacent elements, else move on

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

void bubbleSort(vector<int>& array) {
    int i, j;
    bool swapped = false;

    for (int i = 1; i < array.size(); i++) {
        for (int j = 0; j < array.size() - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
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
    bubbleSort(arr);
    printArray(arr);

    return 0;
}
