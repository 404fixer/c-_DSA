# A Python program to show that there are two types in
# Python 2.7 : int and long int
# And in Python 3 there is only one type : int

def fast_exp(b, e, m): # Calculate b^e mod m
    init = 2
    powers = [b]
    # Calculate b powers until e
    while init <= e:
        powers.append((powers[-1]**2) % m)
        init *= 2
    binary = bin(e)[2:][::-1]
    product = 1
    # We can now multiply the correct powers
    for i in range(len(binary)):
        if binary[i] == '1':
            product *= powers[i]
            product %= m
    return product
 
 
 
n = int(input())
# n,k=map(int,input().split())
k = int(input())
m = int(input())
modc = int(998244353)
 
num = pow(k, n)
# ans = expo(m, num, modc);
# ans = pow(m, num)%modc
ans = fast_exp(m, num, modc)
print(ans)