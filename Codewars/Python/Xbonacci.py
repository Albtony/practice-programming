'''
Source : Codewars

If you have completed the Tribonacci sequence kata, you would know by now that mister Fibonacci
has at least a bigger brother. If not, give it a quick look to get how things work.

Well, time to expand the family a little more: think of a Quadribonacci starting with a signature
of 4 elements and each following element is the sum of the 4 previous, a Pentabonacci 
(well Cinquebonacci would probably sound a bit more italian, but it would also sound really awful) 

with a signature of 5 elements and each following element is the sum of the 5 previous, and so on.
Well, guess what? You have to build a Xbonacci function that takes a signature of X elements - and 
remember each next element is the sum of the last X elements - and returns the first n elements of 
the so seeded sequence.


Example :

xbonacci {1,1,1,1} 10 = {1,1,1,1,4,7,13,25,49,94}
xbonacci {0,0,0,0,1} 10 = {0,0,0,0,1,1,2,4,8,16}
xbonacci {1,0,0,0,0,0,1} 10 = {1,0,0,0,0,0,1,2,3,6}
xbonacci {1,1} produces the Fibonacci sequence
'''


def Xbonacci(signature,n):
    x = len(signature)
    elemCount = 0
    elem = 0
    # elemCount + x = num of elem + signature
    while elemCount+x < n:
        # append elem as sum of previous x element with elemCount as shifter
        for i in range(x):
            elem += signature[i+elemCount]
        signature.append(elem)
        elemCount += 1
        elem = 0
    # n can be lower than x
    return signature[:n]

sig1 = [1,1,1,1]; numElem1 = 10
sig2 = [0,0,0,0,1]; numElem2 = 10
sig3 = [1,0,0,0,0,0,1]; numElem3 = 10

print(Xbonacci(sig1, numElem1))
print(Xbonacci(sig2, numElem2))
print(Xbonacci(sig3, numElem3))

# better answer
'''
def Xbonacci(signature,n):
    length = len(signature)
    while len(signature) < n:
        signature.append(sum(signature[-length:]))
    return signature[:n]
'''