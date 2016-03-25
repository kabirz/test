def sum(seq):
    def add(x,y): return x+y
    return reduce(add, seq, 0)

print sum(range(1, 11))
print sum([])


