#!/usr/bin/env python
from ctypes import cdll
somelibc=cdll.LoadLibrary("./some.so")  
somelibc.hello()  
