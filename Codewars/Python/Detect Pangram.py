'''
Source : Codewars

A pangram is a sentence that contains every single letter of the alphabet at least once. For example, the sentence 
"The quick brown fox jumps over the lazy dog" is a pangram, because it uses the letters A-Z at least once (case is irrelevant).
Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.
'''

def is_pangram(s):
    # lower all the case so sorting will be much simpler
    s = s.lower()
    # transform to a list so we can use set
    s = list(s)
    s = sorted(set(s))
    result = ''
    # for every aplhabet char transport it to result
    for char in s:
        if char.isalpha():
            result += char
    # check it and ship it
    if result == "abcdefghijklmnopqrstuvwxyz":
        return True
    else:
        return False

test = "The quick, brown fox jumps over the lazy dog!"
print(is_pangram(test))

# better solution
'''
import string

def is_pangram(s):
    s = s.lower()
    for char in 'abcdefghijklmnopqrstuvwxyz':
        if char not in s:
            return False
    return True
'''