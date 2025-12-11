import sys
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1] * n

    def find(self, x):
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return self.sz[a]
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return self.sz[a]


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(lambda x: int(x) - 1, input().split()))
    b = list(map(lambda x: int(x) - 1, input().split()))
    c = list(map(int, input().split()))

    edges = sorted(zip(c, a, b))  

    ans = [-1] * (n + 1)
    ans[1] = 0  
    dsu = DSU(n)
    M = 1  
    prev_M = 1

    for w, u, v in edges:
        new_size = dsu.union(u, v)
        if new_size > M:
            M = new_size
            for k in range(prev_M + 1, M + 1):
                ans[k] = w
            prev_M = M

            if M == n:
                break

    print(*ans[1:])
