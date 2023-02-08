def coin_change(S, m, n):
    table = [0 for x in range(n+1)]

    table[0] = 1

    for i in range(0, m):
        for j in range(S[i], n+1):
            table[j] += table[j-S[i]]

    return table[n]


S = []
n = int((input('Enter the target : ')))
size = int((input("Enter the no of denominations : ")))
print("Enter the denominations : ")
for i in range(0, size):
    element = int(input())

    S.append(element)
m = len(S)

print(coin_change(S, m, n))
