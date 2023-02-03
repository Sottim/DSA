// D
// CD
// BCD
// ABCD

#include <iostream>
using namespace std;

int main(){
    int n;
    printf("Enter the value of n: ");
    cin >> n;

    int i = 1;
    
    while(i<=n){
        int j = 0;
        char start = 'A' + n - i;
        while(j<i){
            cout << char(start + j);
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }

}

