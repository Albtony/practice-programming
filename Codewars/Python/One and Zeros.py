'''
Source : Codewars

Given an array of ones and zeroes, convert the equivalent binary value to an integer.
Eg: [0, 0, 0, 1] is treated as 0001 which is the binary representation of 1.
'''

def binary_array_to_number(arr):
    currPow = len(arr)-1
    result = 0
    # we iterate digit from the head to tail and multiplies it according to currPow
    for digit in arr:
        # sum
        result += pow((digit*2), currPow) 
        currPow -= 1
    # 0 to the power of 0 is one in python, so we need to substract 1 to get the right answer
    if digit == 0:
        result -= 1
    return result

test = [1, 1, 1, 1]
print(binary_array_to_number(test))

# Better solution
'''
def binary_array_to_number(arr):
    s = 0
    for digit in arr:
        s = s * 2 + digit

    return s
'''