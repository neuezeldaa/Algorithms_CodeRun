import sys
from bisect import bisect_left, bisect_right

LIMIT = 10 ** 18
PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]

sys.setrecursionlimit(10000)


def build_artifacts():
    cand = []

    def dfs(pos, last_exp, n, d):
        cand.append((n, d))
        if pos == len(PRIMES):
            return
        p = PRIMES[pos]
        cur = n
        for e in range(1, last_exp + 1):
            if cur > LIMIT // p:
                break
            cur *= p
            dfs(pos + 1, e, cur, d * (e + 1))

    dfs(0, 60, 1, 1)
    cand.sort(key=lambda x: x[0])
    artifacts = []
    best = 0
    for n, divs in cand:
        if divs > best:
            best = divs
            artifacts.append(n)
    return artifacts


def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    q = int(data[0])
    artifacts = build_artifacts()
    ans = []
    i = 1
    for _ in range(q):
        l = int(data[i])
        r = int(data[i + 1])
        i += 2
        left = bisect_left(artifacts, l)
        right = bisect_right(artifacts, r)
        ans.append(str(right - left))
    sys.stdout.write("\n".join(ans))


if __name__ == "__main__":
    main()
