'''
Source : Codewars

Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, 
which is the number of times you must multiply the digits in num until you reach a single digit.

Example:
persistence(39) # returns 3, because 3*9=27, 2*7=14, 1*4=4
                # and 4 has only one digit
                  
persistence(999) # returns 4, because 9*9*9=729, 7*2*9=126,
                 # 1*2*6=12, and finally 1*2=2

persistence(4) # returns 0, because 4 is already a one-digit number
'''


def persistence(n):
    counter = 0
    # using str() so we can use len() and iterate with for loop
    while len(str(n)) > 1:
        counter += 1
        digits = list(str(n))
        number = 1
        # multiply all digit in digits
        for digit in digits:
            number *= int(digit)
        n = number
    # return counter after n is only single digit
    return counter

test = 39
print(persistence(test))

# lebih rapih, cuman nama variabelnya bisa dibagusin lagi
'''
def persistence(n):
    n = str(n)
    count = 0
    while len(n) > 1:
        p = 1
        for i in n:
            p *= int(i)
        n = str(p)
        count += 1
    return count
    # your code
'''