#!/usr/bin/env python
tel = {'jack': 4098, 'sape': 4139}
tel['guido'] = 4127
print tel
print tel['jack']
del tel['sape']
tel['irv'] = 4127
print tel.keys()
print tel.has_key('guido')

