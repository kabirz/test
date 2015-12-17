'''
@author: zhonghuiping
'''

pi = 3.141596
def mymax(arr):
    tmp = arr[0]
    for i in arr:
        if tmp<i:
            tmp = i
         
    return tmp   
def mymin(arr):
    tmp = arr[0]
    for i in arr:
        if tmp>i:
            tmp = i
         
    return tmp   