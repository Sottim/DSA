// ABCDE
// ABCDE
// ABCDE
// ABCDE
// ABCDE

#include <iostream>
using namespace std;

int main(){
    int n;
    printf("Enter the number of rows:");
    cin >> n;
    int row = 1;
    while(row <= n){
        int col = 1; 
        while(col <= n){
            char c = 'A' + col - 1;
            
            cout << c;
            col = col + 1;
        }
        cout<< endl;
        row = row + 1;  
    }
}