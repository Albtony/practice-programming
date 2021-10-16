'''
Source : Codewars

Write a function that when given a URL as a string, parses out just the domain name and returns it as a string. For example:

domain_name("http://github.com/carbonfive/raygun") == "github" 
domain_name("http://www.zombie-bites.com") == "zombie-bites"
domain_name("https://www.cnet.com") == "cnet"
'''

def domain_name(url):
    # remove the usual extension you find in front of url
    # check HTP
    if url[0:7] == "http://" or url[0:8] == "https://":
        # splits url with HTP so we can remove htp
        url = url.split('/')
        url.pop(0)
        # removes '' not necessary but maybe somewhat more readable
        while '' in url:
            url.remove('')
        url = ''.join(url)
    url = url.split('.')
    # check www. and remove
    if url[0] == "www":
        url.remove("www")
    return url[0]

test1 = "https://www.codewars.com/kata/514a024011ea4fb54200004b/train/python"
test2 = "http://github.com/carbonfive/raygun"
test3 = "www.wikipedia.com"

print(domain_name(test1))
print(domain_name(test2))
print(domain_name(test3))

# better solution
'''
def domain_name(url):
    url = url.replace('www.','')
    url = url.replace('https://','')
    url = url.replace('http://','')
    
    return url[0:url.find('.')]
'''