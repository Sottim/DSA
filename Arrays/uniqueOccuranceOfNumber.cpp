#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool uniqueOccurance(vector<int>& arr, int size){
    vector<int> freq;
    sort(arr.begin(), arr.end());

    int i = 0; 
    while(i<size){
        int counter = 1;
        for(int j = i+1; j<size; j++){
            if(arr[i] == arr[j]){
                //once the array is sorted, we can increase the counter value 
                //till we find the same numbers.
                counter = counter+1; 
                
            }
            else{
                break;
            }
            freq.push_back(counter);
            i = i + counter; //This lets us to ignore the same number which have 
            // already been counted and jump to the new number.      
    }
    sort(freq.begin(), freq.end());
    int newSize = sizeof(freq);
    for(i=0; i<newSize; i++){
        if(freq[i] == freq[i+1]){
            return false;
        }
    }
    return true;

}
}

int main(){

    vector<int> array = {1, 2, 4, 3, 1, 3, 3, 4, 4, 4};
    uniqueOccurance(array, sizeof(array));
    
    return 0;
}
