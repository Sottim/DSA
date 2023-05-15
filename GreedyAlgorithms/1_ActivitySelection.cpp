#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Activity{
    int start, finish;
};

bool sortActivity_FinishTime(Activity a1, Activity a2){
    return (a1.finish < a2.finish) ; // if a1.finish is less than a2 finish, it returns true and placed before a2 in the sorting order  
}


void print_Activity(Activity array[], int size){
    sort(array, array + size, sortActivity_FinishTime);
    int i = 0; 
    int j;   
    cout<< array[i].start << "," << array[i].finish << "\n";

    for(j = 1; j < size; j++){
        if(array[j].start > array[i].finish){
            cout<< array[j].start <<","<< array[j].finish << "\n";
        }
        i++;
    }
}

int main(){
    Activity arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },{ 0, 6 }, { 5, 7 }, { 8, 9 } };
    int size = sizeof(arr) / sizeof(arr[0]);
    print_Activity(arr, size);

}