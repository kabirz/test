#!/usr/bin/env python
import ctypes
so = ctypes.CDLL("./a.so")
print so.fact(4)
