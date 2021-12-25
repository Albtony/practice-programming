'''
Source : Codewars

Write a function that takes a string of parentheses, and determines if the order of the parentheses is valid. 
The function should return true if the string is valid, and false if it's invalid.

Example :
"()"              =>  true
")(()))"          =>  false
"("               =>  false
"(())((()())())"  =>  true
'''

def valid_parentheses(string):
    # monitor the number of open and close parentheses
    open = close = 0
    # to double check the correctnes of parentheses pair orders
    stats = []
    for char in string:
        # count open parentheses and add pair stat
        if char == '(':
            stats.append(0)
            open += 1
        # count close parentheses and edit pair stat
        elif char == ')':
            close += 1
            # fail condition 1
            if close > open:
                return False
            else:
                stats[close-1] = 1;
    # fail condition 2
    if open != close:
        return False
    # fail condition 3
    elif sum(stats) != len(stats):
        return False
    else: 
        return True
            
test1 = "()"
test2 = ")(()))"
test3 = "("
test4 = "(())((()())())"

print(valid_parentheses(test1))
print(valid_parentheses(test2))
print(valid_parentheses(test3))
print(valid_parentheses(test4))


# better solution
# if cnt < 0; return False ini udah ngekoreksi kesalahan di urutan ()
'''
def valid_parentheses(string):
    cnt = 0
    for char in string:
        if char == '(': cnt += 1
        if char == ')': cnt -= 1
        if cnt < 0: return False
    return True if cnt == 0 else False
'''