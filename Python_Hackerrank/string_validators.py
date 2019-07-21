if __name__ == '__main__':
    s = input()
    alpha = False
    num = False
    digi = False
    lower = False
    upper = False
    for i in range(len(s)):
        if s[i].isalnum():
            num = True
        if s[i].isalpha():
            alpha = True
        if s[i].isdigit():
            digi = True
        if s[i].islower():
            lower = True
        if s[i].isupper():
            upper = True
    print(num)
    print(alpha)
    print(digi)
    print(lower)
    print(upper)


       

