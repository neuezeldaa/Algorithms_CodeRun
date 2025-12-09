import sys

MOD = 10**9 + 7
it = iter(map(int, sys.stdin.buffer.read().split()))

n = next(it)
k = next(it)
a = [next(it) for _ in range(k)]

M = min(n, 10**6)

if M <= 1:
    print(1)
    sys.exit(0)

spf = [0] * (M + 1)
primes = []

for i in range(2, M + 1):
    if spf[i] == 0:
        spf[i] = i
        primes.append(i)
    for p in primes:
        v = i * p
        if v > M or p > spf[i]:
            break
        spf[v] = p

exp = [0] * (M + 1)

for p in primes:
    t = n
    s = 0
    while t:
        t //= p
        s += t
    exp[p] = s

for x in a:
    while x > 1:
        p = spf[x]
        c = 0
        while x % p == 0:
            x //= p
            c += 1
        exp[p] -= c

ans = 1
for p in primes:
    e = exp[p]
    if e > 0:
        ans = (ans * (e + 1)) % MOD

print(ans % MOD)
