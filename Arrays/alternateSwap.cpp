#include<iostream>
using namespace std;

void printElements(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<< arr[i] << "";
    }
    cout<<endl;
}

void swapAlternate(int arr[], int n){
    for(int i= 0; i<n ; i=i+2){

        if(i+1 < n){
            swap(arr[i], arr[i+1]);
        }
    }
}
int main(){
    int a[] = {5, 10, 15, 20, 25, 30, 35, 40};
    int len = sizeof(a);

    swapAlternate(a, len);
    
}