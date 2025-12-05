import sys

input = sys.stdin.readline

n = int(input())
points = []
for i in range(n):
    x, y, z = map(int, input().split())
    points.append((x, y, z, i))

edges = []

points.sort(key=lambda p: p[0])
for i in range(n - 1):
    x1, y1, z1, idx1 = points[i]
    x2, y2, z2, idx2 = points[i + 1]
    w = min(abs(x1 - x2), abs(y1 - y2), abs(z1 - z2))
    edges.append((w, idx1, idx2))

points.sort(key=lambda p: p[1])
for i in range(n - 1):
    x1, y1, z1, idx1 = points[i]
    x2, y2, z2, idx2 = points[i + 1]
    w = min(abs(x1 - x2), abs(y1 - y2), abs(z1 - z2))
    edges.append((w, idx1, idx2))

points.sort(key=lambda p: p[2])
for i in range(n - 1):
    x1, y1, z1, idx1 = points[i]
    x2, y2, z2, idx2 = points[i + 1]
    w = min(abs(x1 - x2), abs(y1 - y2), abs(z1 - z2))
    edges.append((w, idx1, idx2))

edges.sort(key=lambda e: e[0])

parent = list(range(n))
rank = [0] * n


def find(x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x


def union(a, b):
    ra = find(a)
    rb = find(b)
    if ra == rb:
        return False
    if rank[ra] < rank[rb]:
        ra, rb = rb, ra
    parent[rb] = ra
    if rank[ra] == rank[rb]:
        rank[ra] += 1
    return True


mst_cost = 0
edges_used = 0

for w, u, v in edges:
    if union(u, v):
        mst_cost += w
        edges_used += 1
        if edges_used == n - 1:
            break

print(mst_cost)
