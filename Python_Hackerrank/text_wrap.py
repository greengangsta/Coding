import textwrap

def wrap(string, max_width):
    s = ""
    for i in  range(0,len(string),max_width):
        for j in range(min(max_width,len(string)-i)):
            s += string[i+j]
        s += "\n"
    return s

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)