#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	// Количество вершин
	int N;
	cin >> N;

	// Заполнение матрицы смежности
	vector<vector<int>> smej_matrix(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> smej_matrix[i][j];
		}
	}

	// Ввод начальной и конечной вершины
	int begin, end;
	cin >> begin >> end;

	//Если нулевая длина пути (Путь начинается с той же вершины, где и кончается), то выводится ТОЛЬКО длина пути
	if (begin == end) {
		cout << "0";
		return 0;
	}

	--begin;
	--end;

	// Вектор all_distance хранит расстояние между начальной и всеми вершинами
	vector<int> all_distance(N, -1);
	all_distance[begin] = 0;

	// Вектор parent хранит данные о пути (каждая вершина запоминает предыдущую)
	vector<int> parent(N, -1);

	// Очередь для реализации bfs
	queue<int> que;
	que.push(begin);

	// Реализация bfs. Пока очередь не закончилась, вершины продолжают обрабатываться
	while (!que.empty()) {
		// Текущая вершина хранится в cur
		int cur = que.front();
		que.pop();

		// Если текущая вершина совпала с конечной, то останавливаем цикл
		if (cur == end) { break; }

		// Перебираем соседей для текущей вершины
		for (int neighbor = 0; neighbor < N; neighbor++) {
			// Если вершины смежны (имеют ребро в матрице смежности) и вершина еще не посещалась ранее, то
			if ((smej_matrix[cur][neighbor] == 1) && (all_distance[neighbor] == -1)) {
				// Прибавляем расстояние до соседских вершин
				all_distance[neighbor] = all_distance[cur] + 1;
				// Для соседских вершин текущая является родительской
				parent[neighbor] = cur;
				// Добавляем в очередь соседские вершины
				que.push(neighbor);
			}
		}
	}

	// Если расстояния до конечной от начальной не нашлось, то:
	if (all_distance[end] == -1) {
		// Вывод -1
		cout << -1 << endl;
	}
	else { // Иначе
		//Вывод расстояния
		cout << all_distance[end] << endl;
	}

	return 0;
}