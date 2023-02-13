// GIVEN PATTERN
// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4 * * 4 3 2 1 
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1

#include <iostream>
using namespace std;

int main(){
    int n;
    printf("Enter the value of n: ");
    cin >> n;

    int row = 5;
    //Outermost loop
    while(row >= 1){
        int j = 1;
        //1st triangle
        while(j<=row){
            cout<<j;
            j = j + 1;

        }
        //Stars
        int t = 5;
        int star1 = t - row;
        while(star1){
            cout<<"*";
            star1 = star1 - 1;
        }
        int t2 = 5;
        int star2 = t2 - row;
        while(star2){
            cout<<"*";
            star2 = star2 - 1;
        }
        
        //Reverse triangle
        int R = 1;
        int k = row;
        while(R <= k){
            cout << k;
            k = k - 1;
            
        }

        cout<<endl;
        row = row - 1;
        
    }
}