#!/usr/bin/env python

def ask_ok (prompt, retries = 4, complaint = 'Yes or no, please!'):
    while True :
        ok = raw_input (prompt)
        if ok in ('y', 'ye', 'yes'):return 1 
        if ok in ('n', 'no', 'nop', 'nope'):return 0
        retries = retries - 1 
        if retries <0:raise IOError, 'refusenik user' 
        print complaint

ask_ok("Do you like me?",10)
