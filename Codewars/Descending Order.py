'''
Source : Codewars

Your task is to make a function that can take any non-negative integer as an argument and return it 
with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

example :
Input: 42145 Output: 54421
Input: 145263 Output: 654321
Input: 123456789 Output: 987654321
'''

def descending_order(num):
    # typecast num to str so num is iterable
    num = str(num)
    numlist = []
    result = ''
    
    # iterate through digit and append to list
    for digit in num:
        numlist.append(digit)
    
    # sort the list in descending order
    numlist.sort(reverse=True)
    # combine the list and ship it
    result = result.join(numlist)
    return int(result)

test = 42145
print(descending_order(test))