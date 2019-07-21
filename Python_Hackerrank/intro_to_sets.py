def average(array):
    # your code goes 
    h_distinct = set(array)
    s = 0
    c = 0
    for h in h_distinct:
        s += h
        c += 1
    avg = s / float(c)
    return avg


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)