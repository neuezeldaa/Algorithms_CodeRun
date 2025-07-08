def search(a, t):
    l = 0
    r = len(a)
    while r - l > 1:
        m = (l + r) // 2
        if a[m] > t:
            r = m
        else:
            l = m
    if r < len(a) and a[r] - t < t - a[l]:
        return a[r]
    return a[l]


def main():
    n = int(input())
    a = sorted(map(int, input().split()))
    m = int(input())
    for _ in range(m):
        t = int(input())
        print(search(a, t))

if __name__ == '__main__':
    main()
