'''
Source : Codewars

Make a program that filters a list of strings and returns a list with only your friends name in it.
If a name has exactly 4 letters in it, you can be sure that it has to be a friend of yours! Otherwise, you can be sure he's not...

Ex: Input = ["Ryan", "Kieran", "Jason", "Yous"], Output = ["Ryan", "Yous"]
'''

def friend(x):
    result = []
    # iterate through list and append answer to result
    for i in range(len(x)):
        if len(x[i]) == 4:
            result.append(x[i])
    return result

test = ["Ryan", "Kieran", "Jason", "Yous"]
print(friend(test))