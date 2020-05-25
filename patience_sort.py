from bisect import bisect
arr = [5,3,2,4,1]
patience = []
for i in arr:
    it = bisect(patience, i)
    if it >= len(patience):
        patience.append(i)
    else:
        patience[it] = i
    print(i, patience)
