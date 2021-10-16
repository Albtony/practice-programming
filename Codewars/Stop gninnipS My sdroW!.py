'''
Source : Codewars

Write a function that takes in a string of one or more words, and returns the same string, 
but with all five or more letter words reversed (like the name of this kata).
- Strings passed in will consist of only letters and spaces.
- Spaces will be included only when more than one word is present.

'''

def spin_words(sentence):
    #split string into substrings
    sentence = sentence.split()                 
    i = 0
    
    #check if substring length > 5, if yes, reverse
    for elem in sentence:
        if len(elem) > 4:
            #reverse method using slicing
            sentence[i] = sentence[i][::-1]
        i += 1
        
    #combine the substrings and ship it
    sentence = ' '.join(sentence)
    return sentence

    