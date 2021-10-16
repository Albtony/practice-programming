'''
Source : Codewars

The main idea is to count all the occurring characters in a string. If you have a string like aba, 
then the result should be {'a': 2, 'b': 1}.

What if the string is empty? Then the result should be empty object literal, {}.
'''


def count(string):
    # we use dict as return type
    dict = {}
    # for every unique char in string
    for char in sorted(set(string)):
        # that char is that many char
        dict[char] = string.count(char)
    return dict

test = "aba"
print(count(test))