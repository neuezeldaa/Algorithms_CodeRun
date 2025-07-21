import sys

def gaussian_elimination(A, b):
    n = len(b)
    # Прямой ход метода Гаусса
    for col in range(n):
        # Выбор ведущего элемента
        max_row = col
        for i in range(col+1, n):
            if abs(A[i][col]) > abs(A[max_row][col]):
                max_row = i
        
        # Перестановка строк
        A[col], A[max_row] = A[max_row], A[col]
        b[col], b[max_row] = b[max_row], b[col]
        
        # Исключение переменных
        for i in range(col+1, n):
            factor = A[i][col] / A[col][col]
            for j in range(col, n):
                A[i][j] -= factor * A[col][j]
            b[i] -= factor * b[col]
    
    # Обратный ход
    x = [0.0] * n
    for i in range(n-1, -1, -1):
        s = b[i]
        for j in range(i+1, n):
            s -= A[i][j] * x[j]
        x[i] = s / A[i][i]
    
    return x

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])  # Количество объектов
    m = int(data[1])  # Количество признаков
    
    X = []  # Матрица признаков
    y = []  # Вектор меток классов
    
    index = 2
    for i in range(n):
        features = list(map(float, data[index:index+m]))
        X.append(features)
        y.append(float(data[index+m]))
        index += m + 1
    
    # Вычисление X^T * X
    XT_X = [[0.0] * m for _ in range(m)]
    for i in range(m):
        for j in range(m):
            for k in range(n):
                XT_X[i][j] += X[k][i] * X[k][j]
    
    # Вычисление X^T * y
    XT_y = [0.0] * m
    for i in range(m):
        for k in range(n):
            XT_y[i] += X[k][i] * y[k]
    
    # Добавление регуляризации (лямбда = 1e-6)
    for i in range(m):
        XT_X[i][i] += 1e-6
    
    # Решение системы уравнений
    a = gaussian_elimination(XT_X, XT_y)
    
    # Форматирование результата
    result = " ".join(f"{x:.8f}" for x in a)
    print(result)

if __name__ == "__main__":
    main()
