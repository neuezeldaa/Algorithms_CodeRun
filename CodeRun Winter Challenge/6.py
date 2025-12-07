import sys
import bisect

N, M = map(int, input().split())

xs = []
ys = []

for _ in range(N):
    x, y = map(int, input().split())
    xs.append(x)
    ys.append(y)

xs.sort()
ys.sort()

px = [0] * (N + 1)
py = [0] * (N + 1)

for i in range(N):
    px[i + 1] = px[i] + xs[i]
    py[i + 1] = py[i] + ys[i]

def sum_dist(sorted_arr, pref, cur):
    k = bisect.bisect_right(sorted_arr, cur)
    left = cur * k - pref[k]
    right = (pref[N] - pref[k]) - cur * (N - k)
    return left + right

X = 0
Y = 0

cmds = input().strip()

for c in cmds:
    if c == 'N':
        Y += 1
    elif c == 'S':
        Y -= 1
    elif c == 'E':
        X += 1
    elif c == 'W':
        X -= 1

    ans = sum_dist(xs, px, X) + sum_dist(ys, py, Y)
    print(ans)
