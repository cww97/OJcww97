from math import gcd

if __name__ == '__main__':
    x,n = input().split(' ')
    x = int(x)
    n = int(n)

    for i in range(2,n+1):
        print(int(i/gcd(i,x)))
