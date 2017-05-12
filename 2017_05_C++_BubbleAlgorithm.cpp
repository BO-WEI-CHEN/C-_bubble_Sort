//
//  2017_05_C++_BubbleAlgorithm.cpp
//  2017_05_C++_BubbleAlgorithm
//
//  Created by martinchen on 2017/5/12.
//  Copyright © 2017年 martinchen. All rights reserved.
//

// Selection sort with pass-by-reference. This program puts values into an
// array, sorts them into ascending order ans prints the resulting array.
// Function selectionSort (lines 50-63) sorts the array. Line 51 declares the variable
// smallest, which will store the index of the smallest element in the remaining array. Lines
// 54–62 loop size - 1 times. Line 55 sets the smallest element’s index to the current index.
// Lines 57-59 loop over the remaining array elements. For each element, line 58 compares
// its value to the value of the smallest element. If the current element is smaller than the
// smallest element, line 59 assigns the current element’s index to smallest. When this loop
// finishes, smallest will contain the index of the smallest element in the remaining array.
// Line 61 calls function swap (lines 67-71) to place the smallest remaining element in the
// next spot in the array (i.e., exchange the array elements array[i] and array[smallest]).



#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(int * const, const int);  // prototype: sort
void swap(int * const, int * const);  // prototype: change each other

int main(){
    const int arraySize = 10;
    int a[arraySize] = {2,6,4,8,10,12,89,68,45,37};  // declare one dimension aray: array_name[number_of_elements]
    
    cout<<"Data item in original order:\n";
    
    for (int i = 0; i < arraySize; i++)
        cout<<setw(4)<<a[i];
    
    selectionSort(a, arraySize);  // sort the array
    
    cout<<"\nData items in ascending order:\n";
    
    for (int j = 0; j < arraySize; j++)
        cout<<setw(4)<<a[j];
    
    cout<<endl;
}  // end main

// function to sort an array
void selectionSort(int * const array, const int size){
    int smallest;  // index of smallest element
    
    // loop over size-1 elements(最多只要檢查交換size-1次即可)
    for (int i = 0; i < size-1; i++){
        smallest = i;
        // loop to find index of smallest element
        for (int index = i+1; index < size; index++)
            if (array[index] < array[smallest])  // if the next element is smaller than the first element, then change. if you want to in a decending order, just array[smallest] < array[index]
                smallest = index;
        
        swap(&array[i], &array[smallest]);
    }  // end if
}  // end function selectionSort

// swap values at memory location to which
// element1Ptr and element2Ptr2 point
void swap(int * const element1Ptr, int * const element2Ptr){
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}  // end function swap

