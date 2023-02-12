// _ _ _ 1 _ _ _ 
// _ _ 1 2 1 _ _
// _ 1 2 3 1 2 _
// 1 2 3 4 1 2 3 

//Combination of 3 triangles

#include <iostream>
using namespace std;

int main(){
    int n;
    printf("Enter the value of n: ");
    cin >> n;

    int row = 1;
    // Outermost loop 
    while(row <= n){
        //1st traingle
        int space = n-row;
        while(space){
            cout<<" ";
            space = space-1;
        }
        //2nd triangle
        int j = 1;
        while(j<=row){
            cout<<j;
            j=j+1;
        }

        //3rd triangle
        int start = row-1;
        while(start){
            cout<<start;
            start=start-1;
        }

    cout<<endl;
    row= row + 1;

    }
}
