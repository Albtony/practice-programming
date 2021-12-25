'''
Source : Codewars

This time no story, no theory. The examples below show you how to write function accum:

example :
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
'''

def accum(s):
    times = 1
    result = ''
    # iterate every char on string
    for char in s:
        # skips whitespace
        if char == ' ':
            continue
        # prints a number of char according to its position
        for i in range(times):
            if i == 0:
                # first char is uppercase
                result += char.upper()
            else:
                # every next char is lowercase
                result += char.lower()
        # add - after every char
        result += '-'
        times += 1
    # remove excessive -
    result = result[:(len(result)-1)]
    return(result)

test = accum("Yo Wassup")
print(test)