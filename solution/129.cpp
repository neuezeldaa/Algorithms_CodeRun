#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

void dfs(const string& name, map<string, vector<string>>& childrens, map<string, int>& result, int cur_height) {
	result[name] = cur_height;
	for (const string& child : childrens[name]) {
		dfs(child, childrens, result, cur_height + 1);
	}
}


int main()
{
	//¬ходные данные
	int N;
	cin >> N;

	map<string, string> parents;
	map<string, vector<string>> childrens;
	unordered_set<string> dict;
	vector<string> names;

	for (int i = 0; i < N - 1; i++) {
		string child, father;
		cin >> child >> father;
		parents[child] = father;
		childrens[father].push_back(child);
		dict.insert(father);
		dict.insert(child);
	}

	string father;
	for (const auto& n : dict) {
		if (parents.find(n) == parents.end()) {
			father = n;
			break;
		}
	}

	map<string, int> result;
	dfs(father, childrens, result, 0);

	//dict не поддерживает сортировки
	names.assign(dict.begin(), dict.end());
	sort(names.begin(), names.end());

	for (const auto& name : names) {
		cout << name << " " << result[name] << endl;
	}

	return 0;
}

