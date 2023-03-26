class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){ //Till the time n exists and has comb of 0s and 1s
            int result = n & 1; // gives 1 if n has one at the point, 0 otherwise. The concept of AND operator 
            if(result == 1) count = count + 1; // Keeps track of the occurance of 1s
            n = n >> 1; //Right shift to discard value of n that has been checked
        }
        return count;
        
        }
};