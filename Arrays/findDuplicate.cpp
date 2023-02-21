//Approach 1: Giving error in the test case [2,2,2,2,2]

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result = 0;
        //We are doing XOR on each element of vector nums.
        // 0 ^ 1 ^ 3 ^ 4 ^ 2 ^ 2 = 1 ^ 3 ^ 4 
        for(int i = 0; i< nums.size(); i++){
            result = result ^ nums[i];
        }
         // Now we do XOR on all the numbers [1, n] and that will help us get the 
         // number which is repeated
         // 1 ^ 3 ^ 4 XORing with 1 .... n will leave that element in an array 
         // which was there twice, which is our result.
        for(int i=1; i < nums.size(); i++){
            result = result ^ i;
        
        }
        return result; 
    }
};