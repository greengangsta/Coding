def count_substring(string, sub_string):
    count2 = 0
    for i in range(len(string) - len(sub_string) + 1):
        count = 0
        for j in range(len(sub_string)):
            if string[j+i] == sub_string[j]:
                count += 1
            if count == len(sub_string):
                count2 += 1

    return count2

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)