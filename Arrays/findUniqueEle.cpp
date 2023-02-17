#include<iostream>
using namespace std;

// We use the concept of XOR. It results in 0 if two numbers are same and here when one is some unique number, doing 
// XOR results with 0 results in that unique number.
int uniqueEle(int a[], int n){
    int ans= 0;
    for(int i=0; i<n; i++){
        ans = ans ^ a[i]; // Doing XOR on array elements.

    }
    return ans;

}
int main(){
    int arr[] = {2, 4, 7, 9, 7, 4, 2};
    int size = sizeof(arr);
    cout << uniqueEle(arr, size);

}