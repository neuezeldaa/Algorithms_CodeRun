#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	// ���������� ������
	int N;
	cin >> N;

	// ���������� ������� ���������
	vector<vector<int>> smej_matrix(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> smej_matrix[i][j];
		}
	}

	// ���� ��������� � �������� �������
	int begin, end;
	cin >> begin >> end;

	//���� ������� ����� ���� (���� ���������� � ��� �� �������, ��� � ���������), �� ��������� ������ ����� ����
	if (begin == end) {
		cout << "0";
		return 0;
	}

	--begin;
	--end;

	// ������ all_distance ������ ���������� ����� ��������� � ����� ���������
	vector<int> all_distance(N, -1);
	all_distance[begin] = 0;

	// ������ parent ������ ������ � ���� (������ ������� ���������� ����������)
	vector<int> parent(N, -1);

	// ������� ��� ���������� bfs
	queue<int> que;
	que.push(begin);

	// ���������� bfs. ���� ������� �� �����������, ������� ���������� ��������������
	while (!que.empty()) {
		// ������� ������� �������� � cur
		int cur = que.front();
		que.pop();

		// ���� ������� ������� ������� � ��������, �� ������������� ����
		if (cur == end) { break; }

		// ���������� ������� ��� ������� �������
		for (int neighbor = 0; neighbor < N; neighbor++) {
			// ���� ������� ������ (����� ����� � ������� ���������) � ������� ��� �� ���������� �����, ��
			if ((smej_matrix[cur][neighbor] == 1) && (all_distance[neighbor] == -1)) {
				// ���������� ���������� �� ��������� ������
				all_distance[neighbor] = all_distance[cur] + 1;
				// ��� ��������� ������ ������� �������� ������������
				parent[neighbor] = cur;
				// ��������� � ������� ��������� �������
				que.push(neighbor);
			}
		}
	}

	// ���� ���������� �� �������� �� ��������� �� �������, ��:
	if (all_distance[end] == -1) {
		// ����� -1
		cout << -1 << endl;
	}
	else { // �����
		//����� ����������
		cout << all_distance[end] << endl;
	}

	return 0;
}