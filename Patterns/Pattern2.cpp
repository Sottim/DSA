#include <iostream>
using namespace std;

int main(){
    int n;
    printf("Enter the number of rows:");
    cin >> n;
    int i = 1; int count =0;
    while(i<=n){
        int j = 1;
        while(j<=n){
            count = count + 1;
            j = j+1;
            cout << count<<" " ;
        }
        cout << endl;
        i = i + 1;
    }
}