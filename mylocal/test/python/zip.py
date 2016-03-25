#!/usr/bin/env python

questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print 'What is your %s?  It is %s.' % (q, a)

