def numSubseq(s, n, target):
    s.sort()
    left, right = 0, n - 1
    count = 0
    mod = 10 ** 9 + 7
    
    while left <= right:
        if s[left] + s[right] > target:
            right -= 1
        else:
            count += pow(2, right - left, mod)
            left += 1
    
    return count % mod

def solution(s, n, x, y):
    target = y - x
    arr = []
    for i in range(n):
        if s[i] == 'l':
            arr.append(-1)
        else:
            arr.append(1)
    ans = numSubseq(arr, n, target)
    print(ans)

solution("rrlrlr", 6, 1 ,2)



