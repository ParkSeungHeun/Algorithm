n = int(input())

lst_a = list(map(int, input().split()))
lst_b = list(map(int, input().split()))

lst_a.sort()
lst_b.sort(reverse=True)

ans = 0
for elem1, elem2 in zip(lst_a, lst_b):
    ans += elem1 * elem2

print(ans)