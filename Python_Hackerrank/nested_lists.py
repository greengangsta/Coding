scores  = []
for _ in range(int(raw_input())):
    name = raw_input()
    score = float(raw_input())
    info = []
    info.append(name)
    info.append(score)
    scores.append(info)

min1 = 100.0
min2 = 100.0
for score in scores:
    if  score[1] < min1:
        min1 = score[1]
for score in scores:
    if  score[1] < min2 and score[1] > min1:
        min2 = score[1]

names = []
for score in scores:
    if score[1] == min2:
        names.append(score[0])

names.sort()
for name in names:
    print(name)



