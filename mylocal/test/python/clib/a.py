#!/usr/bin/env python
from ctypes import cdll
lib = cdll.LoadLibrary("./liba.so")
print lib.add(4,5)
