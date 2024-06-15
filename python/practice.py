def inversions(arr, x):
    j = 0                   # gets the index of the element which is equal to x
    for i in range(len(arr)):
        if arr[i] == x:
            j = i           # got it
            break

    count = 0
    for i in range(j + 1, len(arr)):           # starting ahead of the index of x i.e from j + 1 because we only have to check for values in array that are ahead of x(come after x).
        if arr[i] <= x - 1 and arr[i] >= 1:    # inverted  
            count = count + 1                  # increase the count

    return count                               # finally returning the count

arr = [0,1,2,3,4,5,6,7,8,9]             # n = 10. Array contains values from 0 to 9
x = 6                                   # x = 6
print(inversions(arr, x))               # prints 2. The inverted pairs for x = 6 are (6, 2) and (6, 4). As per question, we don't have to count (6, 0) but only those whose values range from 1 to (x-1) i.e 1 to 5 in this case.
