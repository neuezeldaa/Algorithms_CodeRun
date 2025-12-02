def main():
    nums = []
    for i in range(10):
        a = int(input())
        nums.append(a)

    result = 0

    for mask in range(1 << 10):
        s = 0
        for i in range(10):
            if mask & (1 << i):
                s += nums[i]

        if abs(100 - s) < abs(100 - result):
            result = s
        elif abs(100 - s) == abs(100 - result) and s > result:
            result = s

    print(result)

if __name__ == '__main__':
    main()
