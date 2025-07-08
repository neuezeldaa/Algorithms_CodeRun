#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Функция для вычисления факториала
double factorial(int n) {
    double res = 1.0;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

// Функция для вычисления полиномиального коэффициента
double multinomial_coeff(int k, int a, int b) {
    return factorial(k) / (factorial(a) * factorial(b) * factorial(k - a - b));
}

void solve() {
    int t;
    cin >> t;
    cout << fixed << setprecision(12);
    
    while (t--) {
        int k, x, y, v, u, a, b;
        cin >> k >> x >> y >> v >> u >> a >> b;
        
        // Проверка на невозможный случай
        if (a + b > k) {
            cout << "0.000000000000" << endl;
            continue;
        }
        
        // Вычисляем размеры интервалов и их пересечения
        int len_P = y - x + 1;
        int len_V = u - v + 1;
        
        // Находим пересечение интервалов Пети и Васи
        int overlap_start = max(x, v);
        int overlap_end = min(y, u);
        int len_overlap = (overlap_start <= overlap_end) ? (overlap_end - overlap_start + 1) : 0;
        
        // Вычисляем вероятности
        double p_P = (len_P - len_overlap) / 37.0;
        double p_V = (len_V - len_overlap) / 37.0;
        double p_both = len_overlap / 37.0;
        double p_none = 1.0 - (len_P + len_V - len_overlap) / 37.0;
        
        // Проверка на невозможный случай (a и b не могут быть положительными, если нет общего интервала)
        if (len_overlap == 0 && a > 0 && b > 0) {
            cout << "0.000000000000" << endl;
            continue;
        }
        
        double total_prob = 0.0;
        
        // Перебираем все возможные значения s - сколько раз выпало пересечение
        int max_s = min({a, b, len_overlap > 0 ? k : 0});
        for (int s = 0; s <= max_s; ++s) {
            if (a - s < 0 || b - s < 0 || (k - (a + b - s)) < 0) continue;
            
            double coeff = multinomial_coeff(k, s, a - s, b - s, k - (a + b - s));
            double prob = coeff * pow(p_both, s) * pow(p_P, a - s) * pow(p_V, b - s) * pow(p_none, k - (a + b - s));
            total_prob += prob;
        }
        
        cout << total_prob << endl;
    }
}

// Перегруженная версия multinomial_coeff для 4 переменных
double multinomial_coeff(int k, int s, int a_minus_s, int b_minus_s, int none) {
    return factorial(k) / (factorial(s) * factorial(a_minus_s) * factorial(b_minus_s) * factorial(none));
}

int main() {
    solve();
    return 0;
}
