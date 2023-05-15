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

int main() {
    int size;
    cout << "Enter the number of activities: ";
    cin >> size;

    Activity* arr = new Activity[size];
    cout << "Enter the start and finish times for each activity:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> arr[i].start >> arr[i].finish;
    }
    print_Activity(arr, size);
    
    return 0;
}