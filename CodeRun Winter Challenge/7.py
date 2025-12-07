MOD = 998244353

t = int(input())
tests = []
max_s = 0

for _ in range(t):
    n, s = map(int, input().split())
    tests.append((n, s))
    if s > max_s:
        max_s = s

fact = [1] * (max_s + 2)
invfact = [1] * (max_s + 2)

for i in range(1, max_s + 2):
    fact[i] = fact[i - 1] * i % MOD

invfact[max_s + 1] = pow(fact[max_s + 1], MOD - 2, MOD)
for i in range(max_s, -1, -1):
    invfact[i] = invfact[i + 1] * (i + 1) % MOD

def P(a, b):
    if b < 0 or b > a:
        return 0
    return fact[a] * invfact[a - b] % MOD

for n, s in tests:
    if n > s:
        print(0)
        continue
    print((P(s, n) + s * n % MOD * P(s - 1, n - 1)) % MOD)
