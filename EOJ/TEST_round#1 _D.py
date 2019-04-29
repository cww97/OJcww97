# -*-coding:utf-8-*-
from functools import reduce
import sys

fib = [0,1]
def getFib():
    #fib[1] = 1
    #fib[2] = 1
    for i in range(2,100):
        #print("i = ", i)
        #fib[i] = fib[i-1] + fib[i-2]
        fib.append(fib[i-1] + fib[i-2])

if __name__ == "__main__":
    #a, b = input(), input()
    getFib()
    for i in range(1,100):
        #print(fib[i],end = '')
        sys.stdout.write('%d' %fib[i])