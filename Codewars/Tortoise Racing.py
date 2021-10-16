'''
Source : Codewars

Two tortoises named A and B must run a race. A starts with an average speed of 720 feet per hour. 
Young B knows she runs faster than A, and furthermore has not finished her cabbage. When she starts, 
at last, she can see that A has a 70 feet lead but B's speed is 850 feet per hour. How long will it 
take B to catch A?

More generally: given two speeds v1 (A's speed, integer > 0) and v2 (B's speed, integer > 0) and a 
lead g (integer > 0) how long will it take B to catch A?

The result will be an array [hour, min, sec] which is the time needed in hours, minutes and seconds 
(round down to the nearest second) or a string in some languages. If v1 >= v2 then return nil, nothing, 
null, None or {-1, -1, -1} for C++, C, Go, Nim, Pascal,[] for Kotlin or "-1 -1 -1".

Example :
race(720, 850, 70) => [0, 32, 18] or "0 32 18"
'''

# dist1 = dist2
# dist = v * t + dist0
# v1 * t + g = v2 * t 
# t = g/(v2-v1) in hours
def race(v1, v2, g):
    if v1 >= v2:
        return None
    else:
        rawtime = int(g/(v2-v1)*3600)
        hours = rawtime // 3600
        minutes = rawtime % 3600 // 60
        seconds = rawtime % 60
        return [hours, minutes, seconds]

va = 720
vb = 850
dist0 = 70
print(race(va, vb, dist0))

# cleaner solution
'''
def race(v1, v2, g):
    if v1 < v2:
        t = g * 3600 / (v2 - v1)
        return [t//3600, t//60%60, t%60]
'''