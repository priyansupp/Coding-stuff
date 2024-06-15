def findValue(nums,value):
    index=0
    length=len(nums)

    for index in range(length):
        if nums[index]==value:
            return index
    return -1
            

nums=[3,2,1,5,3,6,8]
value=5
print(findValue(nums,value))