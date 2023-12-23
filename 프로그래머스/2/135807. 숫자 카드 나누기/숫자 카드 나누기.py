def GCDS(arr):
    gcd = arr[0]
    for i in range(len(arr) - 1):
        gcd = GCD(gcd, arr[i + 1])
    return gcd

def GCD(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def solution(arrayA, arrayB):
    gcd_A = GCDS(arrayA)
    gcd_B = GCDS(arrayB)
    result = 0
    for i in arrayA:
        if i % gcd_B == 0:
            break
    else:
        result = gcd_B    
    
    for i in arrayB:
        if i % gcd_A == 0:
            break
    else:
        result = max(result, gcd_A)
    return result