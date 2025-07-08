import bisect

def main():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))
    
    idx = 0
    N = data[idx]
    idx += 1
    answers = data[idx:idx+N]
    idx += N
    
    M = data[idx]
    idx += 1
    b_j_list = data[idx:idx+M]
    
    sorted_answers = sorted(answers)
    results = []
    
    for b_j in b_j_list:
        pos = bisect.bisect_left(sorted_answers, b_j)
        
        candidates = []
        if pos > 0:
            candidates.append(sorted_answers[pos-1])
        if pos < len(sorted_answers):
            candidates.append(sorted_answers[pos])

        if len(candidates) == 1:
            results.append(str(candidates[0]))
        else:
            if abs(candidates[0] - b_j) <= abs(candidates[1] - b_j):
                results.append(str(candidates[0]))
            else:
                results.append(str(candidates[1]))
    
    print('\n'.join(results))

if __name__ == "__main__":
    main()
