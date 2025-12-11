import sys

MOD = 10**9 + 7

def main():
    n = int(sys.stdin.readline())
    if n == 0:
        print(0)
        return

    inv = [0] * (n + 1)
    inv[1] = 1
    for i in range(2, n + 1):
        inv[i] = (MOD - (MOD // i)) * inv[MOD % i] % MOD

    p_prev = 0
    q_prev = 0
    p = 1
    q = 0

    for k in range(1, n):
        num_p = (n * p - k * p_prev) % MOD
        num_q = (n * q - n - k * q_prev) % MOD

        denom_inv = inv[n - k]
        p_next = num_p * denom_inv % MOD
        q_next = num_q * denom_inv % MOD

        p_prev, p = p, p_next
        q_prev, q = q, q_next

    lhs = (p - p_prev) % MOD
    rhs = (1 + q_prev - q) % MOD

    x = rhs * inv[lhs] % MOD 

    Hn = (p * x + q) % MOD
    print(Hn)

if __name__ == "__main__":
    main()
