'''
Source : Codewars

Your task in order to complete this Kata is to write a function which 
formats a duration, given as a number of seconds, in a human-friendly way.
The function must accept a non-negative integer. If it is zero, it just 
returns "now". Otherwise, the duration is expressed as a combination of 
years, days, hours, minutes and seconds.

It is much easier to understand with an example:
format_duration(62)    # returns "1 minute and 2 seconds"
format_duration(3662)  # returns "1 hour, 1 minute and 2 seconds"
For the purpose of this Kata, a year is 365 days and a day is 24 hours.
'''


def format_duration(seconds):
    # find value for each pocket
    time = [0, 0, 0, 0, 0]
    time[0] = seconds // (60 * 60 * 24 * 365)
    time[1] = seconds // (3600 * 24) % 365
    time[2] = seconds // 3600 % 24
    time[3] = seconds // 60 % 60
    time[4] = seconds % 60 
    string = ["year", "day", "hour", "minute", "second"]
    result = ''
    i = 1
    # strip excess 0
    while i < len(time)-2:
        if time[-i] == 0:
            del time[-i]
            i -= 1
        else:
            break
        i += 1
    # if we find 2 non-zero pocket, the last pocket changed to minus to tell us to use "and"
    if len(time) > 1:
        for elem in time[:-1:]:
            if elem > 0:
                time[-1] *= -1
                break
    for i in range(len(time)):
        # if we are on the last nonzero pocket, add to result accordingly and break loop
        if i == len(time)-1:
            if time[i] > 1:
                result += str(time[i]) + " " + string[i] + "s"
                break
            elif time[i] > 0:
                result += str(time[i]) + " " + string[i]
                break
            elif time[i] < -1:
                result += " and " + str(time[i] * -1) + " " + string[i] + "s"
                break
            elif time[i] < 0:
                result += " and " + str(time[i] * -1) + " " + string[i] 
                break
            elif time[i] == 0:
                result += "now"
                break
        # if we are not in the last non-zero pocket add to result accordingly
        else:
            if time[i] > 1:
                result += str(time[i]) + " " + string[i] + "s"
            elif time[i] > 0:
                result += str(time[i]) + " " + string[i]
        # if we are not on the second last non-zero pocket add ", " to result
        count = 0
        for elem in time[i+1:]:
            if elem != 0:
                count += 1
        if time[i] != 0 and count != 1:
            result += ", "
    return result

print(format_duration(62))
print(format_duration(3662))

# may not be the best code but im proud of my work :')

# better solution
'''
times = [("year", 365 * 24 * 60 * 60), 
         ("day", 24 * 60 * 60),
         ("hour", 60 * 60),
         ("minute", 60),
         ("second", 1)]

def format_duration(seconds):

    if not seconds:
        return "now"

    chunks = []
    for name, secs in times:
        qty = seconds // secs
        if qty:
            if qty > 1:
                name += "s"
            chunks.append(str(qty) + " " + name)

        seconds = seconds % secs

    return ', '.join(chunks[:-1]) + ' and ' + chunks[-1] if len(chunks) > 1 else chunks[0]
'''