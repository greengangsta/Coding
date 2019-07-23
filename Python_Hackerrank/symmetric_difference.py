# Enter your code here. Read input from STDIN. Print output to STDOUT

m = input()
l1 = input().split(' ')
l1 = list(map(int ,l1))
n = input()
l2 = input().split(' ')
l2 = list(map(int,l2))
l1 = set(l1)
l2 = set(l2)
l3 = list(l1.difference(l2))
l4 = list(l2.difference(l1))
l = l3 + l4
l.sort()
for e in l:
    print(e)