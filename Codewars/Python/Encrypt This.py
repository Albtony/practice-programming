'''
Source : Codewars

Encrypt this!

You want to create secret messages which can be deciphered by the Decipher this! kata. Here are the conditions:

Your message is a string containing space separated words.
You need to encrypt each word in the message using the following rules:
1. The first letter needs to be converted to its ASCII code.
2. The second letter needs to be switched with the last letter
3. Keepin' it simple: There are no special characters in input.

Example:
encrypt_this("hello world") == "104olle 119drlo"
'''

def encrypt_this(text):
    # split to iterate word
    text = text.split()
    result = ''
    for word in text:
        # transform to list so swapping is easy
        word  = list(word)
        if len(word) > 1:
            word[1], word[len(word)-1] = word[len(word)-1], word[1]
        word[0] = str((ord(word[0])))
        # combine and combine
        word = ''.join(word)
        result += word + ' '
    # remove excess whitespace
    result = result[:len(result)-1]
    return result

test = "hello world"
print(encrypt_this(test))