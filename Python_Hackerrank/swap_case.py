def swap_case(s):
    p = ""
    for i in range(len(s)):
        if s[i].isupper() == True:
            p += s[i].lower()
        else:
            p += s[i].upper()
    return p

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)