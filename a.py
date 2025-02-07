def getNumSubarrays(arr):
    n = len(arr)
    validRight = [False] * (n + 2)
    validLeft = [False] * (n + 2)

    validLeft[0] = True
    validRight[n + 1] = True

    for i in range(n):
        validLeft[i + 1] = validLeft[i] and (i == 0 or arr[i - 1] <= arr[i])

    for i in range(n - 1, -1, -1):
        validRight[i + 1] = validRight[i + 2] and (i == n - 1 or arr[i] <= arr[i + 1])

    res = 0
    j = 1
    for i in range(1, n + 1):
        while j <= n and (not validRight[j] or j <= i or (i != 1 and arr[i - 2] > arr[j - 1])):
            j += 1
        
        if validLeft[i - 1]:
            res += (n + 2) - j

    return res - 1


def main():
    a = [1,2,2,6,1,3]
    print(getNumSubarrays(a))

if __name__ == "__main__":
    main()