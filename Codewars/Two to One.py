'''
Source : Codewars

Take 2 strings s1 and s2 including only letters from ato z. Return a new sorted string, the longest possible,
 containing distinct letters - each taken only once - coming from s1 or s2.

examples :
a = "xyaabbbccccdefww"
b = "xxxxyyyyabklmopq"
longest(a, b) -> "abcdefklmopqwxy"
'''


def longest(a1, a2):
    # we will eliminate multiple char so adding our string will make the job simpler
    result = a1 + a2
    for char in result:
        # delete all char except 1
        charOcc = result.count(char)
        result = result.replace(char, '', charOcc-1)
    # transform string to list so we can sort
    result = list(result)
    result.sort()
    # pack it and ship it
    result = ''.join(result)
    return(result)

test1 = "xyaabbbccccdefww"
test2 = "xxxxyyyyabklmopq"
print(longest(test1, test2))


# best solution
# same concept but rather than manually deleting char we use set here
'''
def longest(a1, a2):
    return "".join(sorted(set(a1 + a2)))
'''