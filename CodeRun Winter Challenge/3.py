def main():
    M, N = map(int, input().split())
    W = list(map(int, input().split()))
    MOD = 10 ** 9 + 7
    total_need = sum(W)

    shortage = total_need - M
    W.sort()


    lo, hi = 0, max(W)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        s = 0
        for w in W:
            if w >= mid:
                s += mid
            else:
                s += w
            if s > shortage:
                break
        if s > shortage:
            hi = mid - 1
        else:
            lo = mid
    t = lo

    d = [min(w, t) for w in W]
    cur = sum(d)
    rem = shortage - cur

    i = N - 1
    while rem > 0 and i >= 0:
        if d[i] < W[i]:
            d[i] += 1   
            rem -= 1
        i -= 1


    ans = 0
    for x in d:
        ans = (ans + x * x) % MOD
    print(ans)

if __name__ == "__main__":
    main()
