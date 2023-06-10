# Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that sorts the given array. 
# The functions should put all 0s first, then all 1s and all 2s in last.
# This problem is also the same as the famous “Dutch National Flag problem”.

def swap(a, b):
    return b, a

def sortArray(array, size):
    low, mid = 0, 0
    high = size - 1
    while(mid <= high):
        if(array[mid] == 0):
            array[low], array[mid] = swap(array[low], array[mid])
            low += 1
            mid += 1
        elif(array[mid] == 1):
            mid += 1
        else:
            array[mid], array[high] = swap(array[mid], array[high])
            high = high - 1
    return array

def printarray(array):
    for i in range(len(array)):
        print(array[i], end= " ")

arr = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
size = len(arr)
array = sortArray(arr, size)
printarray(sortArray(arr, size))
  