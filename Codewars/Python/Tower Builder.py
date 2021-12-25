'''
Source : Codewars

Build Tower by the following given argument:
number of floors (integer and always greater than 0).

for example, a tower of 3 floors looks like below
[
  '  *  ', 
  ' *** ', 
  '*****'
]
'''

def tower_builder(n_floors):
    floors = []
    floor = ''
    space = n_floors - 1
    # building the floor
    for i in range(n_floors):
        # right space
        block = 1 + 2*i
        for j in range(space):
            floor += ' '
        # putting blocks
        for k in range(block):
            floor += '*'
        # left space
        for j in range(space):
            floor += ' '
        space -= 1;
        # assembly
        floors.append(floor)
        floor = ''
    return floors

test = 3
print(tower_builder(test))

# better solution
# much more readable 
'''
def tower_builder(n_floors):
    if n_floors == 0:
        return []
        
    count = 1
    result = []

    for i in range(1, n_floors + 1):
        stars = '*' * (2 * i - 1)
        space = ' ' * (n_floors - i)
        result.append(space + stars + space)
    
    return result
'''