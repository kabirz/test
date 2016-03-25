#!/usr/bin/env python

def f(x): return x%2 != 0 and x%3 !=0
def s(x):return x*x*x
def square(x): return x*x
def add(x,y): return x+y

print filter(f, range(10, 90))

print map(s, range(2, 10))

seq = range(8)
print map(None, seq, map(square, seq))

print reduce(add, range(1, 101))
