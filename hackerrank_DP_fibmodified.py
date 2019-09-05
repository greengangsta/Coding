t1,t2,n = input().split()
t1 = int(t1)
t2 = int(t2)
n  = int(n)
fib = []
fib.append(t1)
fib.append(t2)
for j in range(2,n):
    fib.append(fib[j-2]+ fib[j-1]**2)
print(fib[n-1])