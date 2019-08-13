d1  = {'ram':1,'dam':1,'shyam':3}
d2 = {v:k for k,v in d1.items()}

d3 = {}
for k,v in d1.items():
    if v in d3.keys():
        d3[v].append(k)
    else :
        d3[v] = [k]

for k,v in d3.items():
    print('key is %s and values is %s'%(k,v))
    