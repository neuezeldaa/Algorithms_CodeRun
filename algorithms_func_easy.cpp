#include "algos_header.h"


//Задача 1: Подается три элемента, вывести средний, "центральный" элемент
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
//Задача 5321: Подается К число уровней елки, на каждом уровне 2^(i-1) шариков, определить сколько шариков требуется для k уровней
int NaryajElka(int k) {
    int summa = 0;
    for (int i = 1; i <= k; i++) {
        summa += int(pow(2, i - 1));
    }
    return summa;
}


//Задача 55: Свинки стреляют по птичкам из ружья. У птичек есть координаты
//Если попадают в птичку сверху, то она падает на всех птичек под ней.
//Требуется найти минимальное количество выстрелов для снова всех птичек количесвом N
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

//Задача 83: На клавиатуре есть N клавиш с количеством возможных нажатий на каждую клавишу,
// Задается последовательность из K нажатий. Определить, работает ли клавиша после этой последовательности?
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

//Задача 62: Количество различных чисел в списке
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


//Задача 54: Найти среди N участников, которые знают по M языков общие языки и языки, которые знает хотя бы 1 ученик. 
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


//Задача 60: У Ани N кубиков, у Бори M кубиков, у каждого кубика свой цвет. Определить сходства и различие цветов кубиков.
int kubiki(int N, int M)
{
    vector<int> kubanya;
    vector<int> kuborya;
    vector<int> inter;

    vector<int> intanya, intborya;

    int cur = 0;
    for (int i = 0; i < (N + M); i++) {
        cin >> cur;
        if (i < N) {
            kubanya.push_back(cur);
        }
        else {
            kuborya.push_back(cur);
        }
    }

    sort(kubanya.begin(), kubanya.end());
    sort(kuborya.begin(), kuborya.end());

    set_intersection(kubanya.begin(), kubanya.end(),
        kuborya.begin(), kuborya.end(),
        back_inserter(inter));

    set_difference(kubanya.begin(), kubanya.end(),
        inter.begin(), inter.end(),
        back_inserter(intanya));

    set_difference(kuborya.begin(), kuborya.end(),
        inter.begin(), inter.end(),
        back_inserter(intborya));


    cout << inter.size() << endl;
    for (int n : inter)
        cout << n << " ";
    cout << endl;
    cout << intanya.size() << endl;
    for (int n : intanya)
        cout << n << " ";
    cout << endl;
    cout << intborya.size() << endl;
    for (int n : intborya)
        cout << n << " ";

    return 0;
}


//Задача 58: На калькуляторе есть 3 цифры: x y z. Пользователь хочет ввести число N. Определить, 
//Сколько цифр нужно добавить калькулятору для того, чтоб вывести N.
int OpenCalculator(int x, int y, int z, int N)
{
    int c = 0;
    set<int> digits;
    string str_N = to_string(N);
    for (int i = 0; i < size(str_N); i++) {
        digits.insert(N % 10);
        N /= 10;
    }

    for (int n : digits) {
        if (n == x or n == y or n == z) {
            continue;
        }
        else {
            c++;
        }
    }
    return c;
}


//Задача 324: Много стульев. Мужик покупает стулья и продает их. 
//Нужно найти максимальную выгоду, учитывая, что в городе есть N продавцов, которые продают по 1 стулу по определенной цене
//И есть M покупателей, которые покупают по 1 стулу по определенной цене.
int AlotOfChairs(int N, int M)
{
    if (N == 0 or M == 0) {
        cout << "0";
        return 0;
    }
    vector<int> Sell;
    vector<int> Buy;
    int cur = 0;
    long long sum = 0;

    for (int i = 0; i < (N + M); i++) {
        if (i < N) {
            cin >> cur;
            Sell.push_back(cur);
        }
        else {
            cin >> cur;
            Buy.push_back(cur);
        }
    }

    sort(begin(Sell), end(Sell));
    sort(begin(Buy), end(Buy));

    int i = 0;
    int j = 0;
    while (i < N && j < M && Sell[i] < Buy[j]) {
        sum += Buy[j] - Sell[i];
        ++i;
        ++j;
    }

    return sum;
}


//Задача 204: Есть N серверов и вероятности попадания запроса на сервер и
//Возникновения ошибки на сервере. Найти вероятность того, что веряотность произошла на соответствующем сервере.
int Error(int N)
{
    vector<double> P_server;
    double total_error = 0.0;

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        double prob = (a / 100.0) * (b / 100.0);
        P_server.push_back(prob);
        total_error += prob;
    }

    for (double prob : P_server) {
        printf("%.12f\n", prob / total_error);
    }

    return 0;
}


//Задача 61: Дано два множества, найти пересечения их элементов.
int intersecc()
{
    vector<int> first;
    vector<int> second;
    vector<int> intersec;
    int fir, sec;

    while (cin >> fir) {
        first.push_back(fir);
        if (cin.peek() == '\n') {
            cin.ignore();
            break;
        }
    }
    while (cin >> sec) {
        second.push_back(sec);
        if (cin.peek() == '\n') {
            break;
        }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    set_intersection(
        first.begin(), first.end(),
        second.begin(), second.end(),
        std::back_inserter(intersec)
    );

    for (int n : intersec) {
        cout << n << " ";
    }
    return 0;
}



//Задача 99: Выяснить, есть ли i-элемент из второго множества в первом множестве с помощью бинарного поиска
int check_vectors()
{
    vector<int> N_vec;
    vector<int> K_vec;
    int N, K;
    cin >> N >> K;
    int num;
    for (int i = 0; i < (N + K); i++) {
        cin >> num;
        if (i < N) {
            N_vec.push_back(num);
        }
        else {
            K_vec.push_back(num);
        }
    }
    sort(N_vec.begin(), N_vec.end());



    for (int i : K_vec) {
        if (binary_search(N_vec, i) != 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}




//Задачка 100: Найти ближайший элемент в N векторе для j-элемента K вектора
//Функция binary_search переехала сюда с ll из-за того, что в задаче рассматриваются числа не превосходящие 2*10^9.
int binary_search_ll(const vector<long long>& vec, long long i)
{
    int low = 0;
    int high = vec.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = vec[mid];
        if (guess == i) {
            return 1;
        }
        if (guess > i) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return 0;
}
int lower_bound_custom(const vector<long long>& arr, long long x) {
    int low = 0;
    int high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}
long long closest(const vector<long long>& N_num, long long x) {
    int n = N_num.size();

    if (binary_search_ll(N_num, x)) {
        return x;
    }

    int pos = lower_bound_custom(N_num, x);

    if (pos == 0) {
        return N_num[0];
    }

    if (pos == n) {
        return N_num[n - 1];
    }

    long long left_val = N_num[pos - 1];
    long long right_val = N_num[pos];

    if (abs(x - left_val) <= abs(x - right_val)) {
        return left_val;
    }
    else {
        return right_val;
    }
}
int closer_to_the_item()
{
    int N, K;
    cin >> N >> K;
    vector<long long> N_num;
    vector<long long> K_num;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        N_num.push_back(num);
    }
    for (int k = 0; k < K; k++) {
        cin >> num;
        K_num.push_back(num);
    }

    for (int n : K_num) {
        cout << closest(N_num, n) << endl;
    }
    return 0;
}


//Задача 72: Проверить, является ли список возрастающим или нет
bool is_increase()
{
    vector<int> numbers;
    int num;
    while (cin >> num) {
        numbers.push_back(num);
    }

    bool flag = true;

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] <= numbers[i - 1]) {
            flag = false;
            break;
        }
    }

    bool is_inc = (flag ? "YES" : "NO");
    return is_inc;
}
