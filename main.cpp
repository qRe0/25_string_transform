#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("in.txt");   // Открытие файла для чтения
    ofstream output("out.txt"); // Открытие файла для записи

    // Считывание данных для решения задачи (штрафы за операции)
    int x, y, z;
    input >> x >> y >> z;

    // Считывание данных для решения задачи (строки)
    string a, b;
    input >> a >> b;

    // Размеры строк
    int m = a.size();
    int n = b.size();

    // Создание матрицы для динамического программирования
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Инициализация первой строки и первого столбца
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + x; // Удаление символа из a
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + y; // Вставка символа в a
    }

    // Заполнение матрицы dp с использованием динамического программирования
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Символы совпадают, нет дополнительных затрат
            } else {
                // Выбираем минимум из трех вариантов: удаление, вставка и замена
                dp[i][j] = min({dp[i - 1][j] + x, dp[i][j - 1] + y, dp[i - 1][j - 1] + z});
            }
        }
    }

    // Вывод результата (расстояния редактирования) в выходной файл
    output << dp[m][n] << endl;

    input.close();  // Закрытие файла для чтения
    output.close(); // Закрытие файла для записи

    return 0;
}