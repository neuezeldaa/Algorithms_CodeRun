#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, const std::vector<int>& a, int m, const std::vector<int>& b) {
    auto preprocess = [](const vector<int>& v) {
        vector<int> zero_positions;
        vector<int> one_positions;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 0) {
                zero_positions.push_back(i);
            } else {
                one_positions.push_back(i);
            }
        }
        return make_pair(zero_positions, one_positions);
    };

    auto [zeros_a, ones_a] = preprocess(a);
    auto [zeros_b, ones_b] = preprocess(b);

    int count0_a = zeros_a.size();
    int count1_a = ones_a.size();
    int count0_b = zeros_b.size();
    int count1_b = ones_b.size();

    int max_len = max(min(count0_a, count0_b), min(count1_a, count1_b));

    auto count_ones_after_k_zeros = [](const vector<int>& zeros, const vector<int>& ones, int k) {
        if (k == 0) return (int)ones.size();
        if (k > zeros.size()) return 0;
        int last_zero_pos = zeros[k - 1];
        auto it = upper_bound(ones.begin(), ones.end(), last_zero_pos);
        return (int)(ones.end() - it);
    };

    int min_zeros = min(count0_a, count0_b);
    for (int k = min_zeros; k >= 0 && k + count1_b > max_len; --k) {
        int l_a = count_ones_after_k_zeros(zeros_a, ones_a, k);
        int l_b = count_ones_after_k_zeros(zeros_b, ones_b, k);
        int current_len = k + min(l_a, l_b);
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    return max_len;
}
