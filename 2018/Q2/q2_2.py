f = open("q2.in", "r")
r = f.read().split()
f.close()

##r = """abcde
##fghij
##klmno
##pqrst
##aghij
##axcye
##fguij
##wvxyz""".split()

arr = [[ch for ch in box] for box in r]
LEN = len(arr)
LEN2 = len(arr[0])

def main():
    ans1 = ''
    ans2 = ''
    # IF first letter is same
    # Compare first letters
    for a in range(0,LEN):
        for b in range(a+1,LEN):
            
            # If same first letter
            if arr[a][0] == arr[b][0]:
                diff = 0

                # Find no of differences
                for c in range(1,LEN2):
                    if arr[a][c] != arr[b][c]:
                        diff += 1
                    if diff > 1:
                        break

                if diff == 1:
                    ans1 = ''.join([str(x) for x in arr[a]])
                    ans2 = ''.join([str(x) for x in arr[b]])
                    print(ans1)
                    print(ans2)
                    return

    # ELSE first letter is the one that's different
    # Compare remaining letters
    for a in range(0,LEN):
        for b in range(a+1,LEN):
            if arr[a][1:] == arr[b][1:]:
                ans1 = ''.join([str(x) for x in arr[a]])
                ans2 = ''.join([str(x) for x in arr[b]])
                print(ans1)
                print(ans2)
                return

    print("No correct boxes")

main()
