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

// Approach 2: Giving error though on dry running it works fine.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        int duplicate;
        while(low <= high){
            int count = 0; 
            int mid = low + high;
            //duplicate = mid;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= mid){
                    count = count + 1;
                }
                }
                // Any time the count comes out to be more than number, it means 
                // either it is itself the duplicate number or there is number 
                // lower than it which is smaller. This is coz [4, 3, 4, 5, 2, 4, 1]
                // here 5's count would be more than itself. But it is not the 
                // duplicate number as all the 4's repetation also gets counted. 
                // So a unique number is the lowest value among i.e 4 here.
                if(count > mid){
                    //first time 5 is assigned as duplicate but will get changed to 
                    // to 4 and 4 gets returned as below this number, no number 
                    // fulfils the main criteria explained above.
                    duplicate = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }    

            }
            return duplicate;
        }

};

// Approach 3:It is similar to approach 2 but uses two functions. Found this concept online.
// This code runs properly
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        // Lambda function to count how many numbers are less than or equal to 'cur'
        //The lambda function is useful in cases where we need to compute the   number of elements in a collection that satisfy a particular condition, such as finding the number of elements in an array that are less than or equal to a certain threshold value.
        auto small_or_equal_test = [&](int cur) {
            int counter = 0;
            for (auto &num: nums) {
                if (num <= cur)
                    counter = counter + 1;
            }
            return counter;
        };
        
        // 'low' and 'high' represent the range of values of the target
        int low = 1, high = nums.size();
        int duplicate = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            //Calling the small_or_equal_test function which finds the count of specific number.
            if (small_or_equal_test(mid) > mid) { 
                duplicate = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return duplicate;
    }
};