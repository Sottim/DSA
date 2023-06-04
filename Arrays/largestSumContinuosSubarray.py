#Approach : Using Kandane's Alogrithm : TC O(n)

# The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum contiguous 
# subarray ending at current index and a variable max_so_far stores the maximum sum of contiguous subarray found so 
# far, Everytime there is a positive-sum value in max_ending_here compare it with max_so_far and update max_so_far if
#  it is greater than max_so_far.


from sys import maxsize #Largest possible +ve integer value from python i.e MSD in two's com, 0 
                        #indicates +ve num, 1 indicate negative num

def largestSumContinuousSubarray(list):
    max_Sum_TillNow = -maxsize # - convets it into largest possible -ve integer.
    maximumSum = 0

    for i in range(len(list)):
        maximumSum += list[i] #First time anyway we have to add the first ele to check 

        if(max_Sum_TillNow < maximumSum): #First time it gets false 
            max_Sum_TillNow = maximumSum
        if(maximumSum < 0):
            maximumSum = 0

    return max_Sum_TillNow


list = [-2, -3, 4, -1, -2, 1, 5, -3]
print(largestSumContinuousSubarray(list))