#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// dfs-функция для вычисления высоты каждого узла в дереве
void dfs(const string& name, map<string, vector<string>>& childrens, map<string, int>& result, int cur_height) {
    result[name] = cur_height; // Сохраняем текущую высоту для узла
    // Рекурсией проходимся по всем "детям" текущего узла
    for (const string& child : childrens[name]) {
        dfs(child, childrens, result, cur_height + 1); 
    }
}

int main() {
    // Число элементов в генеалогическом дереве
    int N;
    cin >> N;

    // Словари для имен родителей и детей
    map<string, string> parents;
    map<string, vector<string>> childrens;
    unordered_set<string> dict; // Все уникальные имена
    vector<string> names;       // Для сортированного вывода 

    // Чтение пар "ребёнок-родитель"
    for (int i = 0; i < N - 1; i++) {
        string child, father;
        cin >> child >> father;
        parents[child] = father;          // Сохраняем родителя для ребёнка
        childrens[father].push_back(child); // Добавляем ребёнка в список "детей" родителя
        dict.insert(father);              // Добавляем имена в множество
        dict.insert(child);
    }

    // Поиск корневого узла (не имеющего родителя)
    string father;
    for (const auto& n : dict) {
        if (parents.find(n) == parents.end()) {
            father = n;
            break;
        }
    }

    // Вычисление высоты для всех узлов через DFS
    map<string, int> result;
    dfs(father, childrens, result, 0);

    // Преобразование множества в вектор для сортировки
	// unordered_set dict не имеет метода сортировки
    names.assign(dict.begin(), dict.end());
    sort(names.begin(), names.end()); // Сортировка имён

    // Вывод результатов в формате: имя высота
    for (const auto& name : names) {
        cout << name << " " << result[name] << endl;
    }

    return 0;
}
