#include <iostream>
#include "algos_header.h"
using namespace std;


//������ 1: �������� ��� ��������, ������� �������, "�����������" �������
int SredniyElement(int a, int b, int c) {
    
	int arg[3] = { a,b,c };
    int temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (arg[j] > arg[j + 1]) {
                temp = arg[j];
                arg[j] = arg[j + 1];
                arg[j + 1] = temp;
            }
        }
    }
	return arg[1];
}
//������ 5321: �������� � ����� ������� ����, �� ������ ������ 2^(i-1) �������, ���������� ������� ������� ��������� ��� k �������
int NaryajElka(int k) {
    int summa = 0;
    for (int i = 1; i <= k; i++) {
        summa += int(pow(2, i - 1));
    }
    return summa;
}


//������ 55: ������ �������� �� ������� �� �����. � ������ ���� ����������
//���� �������� � ������ ������, �� ��� ������ �� ���� ������ ��� ���.
//��������� ����� ����������� ���������� ��������� ��� ����� ���� ������ ���������� N
int AngryPigs(int N)
{
    int x, y;
    cin >> N;
    set<int> counts;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        counts.insert(x);
    }

    return counts.size();
}

//������ 83: �� ���������� ���� N ������ � ����������� ��������� ������� �� ������ �������,
// �������� ������������������ �� K �������. ����������, �������� �� ������� ����� ���� ������������������?
int Keybord()
{
    int N, K;
    cin >> N;
    vector<int> pressing;
    vector<int> sequence;
    int cur;

    for (int i = 0; i < N; i++) {
        cin >> cur;
        pressing.push_back(cur);
    }

    cin >> K;
    for (int j = 0; j < K; j++) {
        cin >> cur;
        sequence.push_back(cur);
    }

    for (int i = 0; i < N; i++) {
        if (pressing[i] >= K) {
            cout << "NO" << endl;
            continue;
        }
        if (pressing[i] < count(sequence.begin(), sequence.end(), i + 1)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

//������ 62: ���������� ��������� ����� � ������
int Different_numbers()
{
    set<int> massive;
    int num;
    while (cin >> num) {
        massive.insert(num);
        if (cin.peek() == '\n') {
            break;
        }
    }
    return massive.size();
}

int poliglott()
{
    int N, M;
    int cou = 0;
    string languages;
    vector<string> all_lang;
    vector<string> result_lang;
    set<string> poliglot;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> languages;
            poliglot.insert(languages);
            all_lang.push_back(languages);
        }
    }

    for (string n : poliglot) {
        if (count(all_lang.begin(), all_lang.end(), n) == N) {
            cou++;
            result_lang.push_back(n);
        }
    }
    cout << cou << endl;
    for (string n : result_lang)
        cout << n << endl;

    cout << poliglot.size() << endl;

    for (string n : poliglot)
        cout << n << endl;

    return 0;
}
