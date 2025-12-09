import bisect


def precompute_k_interesting(max_n, max_k):
    k_interesting = [[] for _ in range(max_k + 1)]

    k_interesting[1] = list(range(2, max_n + 1))

    def generate(product, k_needed, min_factor, result_set):
        if k_needed == 0:
            result_set.add(product)
            return

        min_remaining_product = 1
        for i in range(k_needed):
            min_remaining_product *= (min_factor + i)
            if product * min_remaining_product > max_n:
                return

        max_factor = max_n // product

        for factor in range(min_factor, max_factor + 1):
            new_product = product * factor
            if new_product > max_n:
                break
            generate(new_product, k_needed - 1, factor + 1, result_set)

    for k in range(2, max_k + 1):
        min_val = 1
        for i in range(k):
            min_val *= (2 + i)

        if min_val > max_n:
            break

        result_set = set()
        generate(1, k, 2, result_set)
        k_interesting[k] = sorted(result_set)

    return k_interesting


MAX_N = 700000
MAX_K = 100

k_interesting = precompute_k_interesting(MAX_N, MAX_K)

q = int(input())
for _ in range(q):
    k, l, r = map(int, input().split())

    if k >= len(k_interesting) or not k_interesting[k]:
        print(0)
    else:
        numbers = k_interesting[k]
        left_idx = bisect.bisect_left(numbers, l)
        right_idx = bisect.bisect_right(numbers, r)
        print(right_idx - left_idx)
