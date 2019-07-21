# Enter your code here. Read input from STDIN. Print output to STDOUT

n, m  = input().split(" ")
n = int(n)
m = int(m)
arr  = input().split(' ')
arr = list(map(int ,arr))
a = input().split(' ')
b = input().split(' ')
happiness = 0
a = list(map(int,a))
b = list(map(int,b))
a = set(a)
b = set(b)
for e in arr:
    if e in a:
        happiness += 1
    elif e in b:
        happiness -= 1
print(happiness)