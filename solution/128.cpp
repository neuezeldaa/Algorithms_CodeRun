#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// dfs-функция для вычисления количества наследников для каждого узла в дереве	
int dfs(const string& name, map<string, vector<string>>& childrens, map<string, int>& result) {
	int count = 0;

	// Рекурсией проходимся по всем детям текущего узла и прибавляем к количеству наследников результат рекурсивного вызова
	for (const string& child : childrens[name]) {
		count += (1 + dfs(child, childrens, result));
	}
	result[name] = count;
	return count;
}

int main()
{
	// Число элементов в генеалогическом дереве
	int N;
	cin >> N;

	// Словари для имен родителей и детей
	map<string, string> parents;
	map<string, vector<string>> childrens;
	unordered_set<string> dict;

	// Чтение пар "Ребенок Родитель"
	for (int i = 0; i < N - 1; i++) {
		string child, father;
		cin >> child >> father;
		parents[child] = father;
		childrens[father].push_back(child);
		dict.insert(father);
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

	// С помощью dfs находим всех наследников для всех узлов
	map<string, int> result;
	dfs(father, childrens, result);

	// Сортируем результат
	vector<string> sorted(dict.begin(), dict.end());
	sort(sorted.begin(), sorted.end());

	// Вывод результата в формате "Имя Количество_Наследников"
	for (const auto& name : sorted) {
		cout << name << " " << result[name] << endl;
	}

	return 0;
}

