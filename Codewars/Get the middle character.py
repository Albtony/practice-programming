'''
Source : Codewars

You are going to be given a word. Your job is to return the middle character of the word.
If the word's length is odd, return the middle character. If the word's length is even, return the middle 2 characters.

Kata.getMiddle("test") should return "es"
Kata.getMiddle("testing") should return "t"
Kata.getMiddle("middle") should return "dd"
Kata.getMiddle("A") should return "A
'''

def get_middle(s):
    # search middle index
    middex = int(len(s)/2)
    # determine how many char to return based on modulo result
    if len(s) % 2 == 1:
        return s[middex]
    else:
        return s[middex-1] + s[middex]

test = "middle"
print(get_middle(test))

# better solution
'''
def get_middle(s):
   return s[(len(s)-1)/2:len(s)/2+1]
'''

