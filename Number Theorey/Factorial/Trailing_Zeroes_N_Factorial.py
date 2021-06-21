# Trailing zeroes in n!

# naiveMethod
# find the factorial and store it
# Then divide it by 10 to count the zeroes

def trailingZeroes(n):
    res = 1
    for i in range(1,n+1):
        res *= i
    zeroes = 0
    while (res % 10) == 0:
        zeroes += 1
        res //= 10
    return zeroes

def trailingZeroes_Efficient(n):
    zeroes = 0
    i = 5
    while i <= n:
        zeroes += (n // i)
        i *= 5
    return zeroes

if __name__ == '__main__':
    print(trailingZeroes(8))
    print(trailingZeroes(10))
    print(trailingZeroes(15))
    print(trailingZeroes(20))
    print(trailingZeroes(25))
    print(trailingZeroes(30))
    print(trailingZeroes(125))
    print(trailingZeroes(553))
    print(trailingZeroes(625))
    print(trailingZeroes(10000))
    # print(trailingZeroes(553007)) Dont Do it TLS
    
    print(trailingZeroes_Efficient(8))
    print(trailingZeroes_Efficient(10))
    print(trailingZeroes_Efficient(15))
    print(trailingZeroes_Efficient(20))
    print(trailingZeroes_Efficient(25))
    print(trailingZeroes_Efficient(30))
    print(trailingZeroes_Efficient(125))
    print(trailingZeroes_Efficient(553))
    print(trailingZeroes_Efficient(625))
    print(trailingZeroes_Efficient(10000))
    print(trailingZeroes_Efficient(533007))