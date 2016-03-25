#!/usr/bin/env python3.3

#python 2.6
"""def cheeseshop(kind, *arguments, **keywords):
    print "-- Do you have any", kind, '?'
    print "-- I'm sorry, we're all out of", kind
    for arg in arguments: print arg
    print '-'*40
    keys = keywords.keys()
    keys.sort()
    for kw in keys: print kw, ':', keywords[kw]
        """
#python 3.3

def cheeseshop(kind, *arguments, **keywords):
    print("-- Do you have any", kind, "?")
    print("-- I'm sorry, we're all out of", kind)
    for arg in arguments:
        print(arg)
    print("-" * 40)
    keys = sorted(keywords.keys())
    for kw in keys:
        print(kw, ":", keywords[kw])


cheeseshop('Limburger', "It's very runny, sir.", "It's really very, VERY runny, sir.", client='John Cleese', shopkeeper='Michael Palin', sketch='Cheese Shop Sketch')


def make_incrementor(n):
     return lambda x: x + n

f = make_incrementor(42)
#print f(1)
