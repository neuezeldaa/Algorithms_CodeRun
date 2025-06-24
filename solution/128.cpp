#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// dfs-������� ��� ���������� ���������� ����������� ��� ������� ���� � ������	
int dfs(const string& name, map<string, vector<string>>& childrens, map<string, int>& result) {
	int count = 0;

	// ��������� ���������� �� ���� ����� �������� ���� � ���������� � ���������� ����������� ��������� ������������ ������
	for (const string& child : childrens[name]) {
		count += (1 + dfs(child, childrens, result));
	}
	result[name] = count;
	return count;
}

int main()
{
	// ����� ��������� � ��������������� ������
	int N;
	cin >> N;

	// ������� ��� ���� ��������� � �����
	map<string, string> parents;
	map<string, vector<string>> childrens;
	unordered_set<string> dict;

	// ������ ��� "������� ��������"
	for (int i = 0; i < N - 1; i++) {
		string child, father;
		cin >> child >> father;
		parents[child] = father;
		childrens[father].push_back(child);
		dict.insert(father);
		dict.insert(child);
	}

	// ����� ��������� ���� (�� �������� ��������)
	string father;
	for (const auto& n : dict) {
		if (parents.find(n) == parents.end()) {
			father = n;
			break;
		}
	}

	// � ������� dfs ������� ���� ����������� ��� ���� �����
	map<string, int> result;
	dfs(father, childrens, result);

	// ��������� ���������
	vector<string> sorted(dict.begin(), dict.end());
	sort(sorted.begin(), sorted.end());

	// ����� ���������� � ������� "��� ����������_�����������"
	for (const auto& name : sorted) {
		cout << name << " " << result[name] << endl;
	}

	return 0;
}

