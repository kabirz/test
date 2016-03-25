#!/usr/bin/env python3.3
#for python 2.6 
#import os
#filename = os.environ.get('PYTHONSTARTUP')
#if filename and os.path.isfile(filename):
#    execfile(filename)


#for python 3.3
import os
filename = os.environ.get('PYTHONSTARTUP')
if filename and os.path.isfile(filename):
    exec(open(filename).read())
