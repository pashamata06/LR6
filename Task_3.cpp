#include <iostream>
#include <cstring>

// Функция для реверса всех строк
void reverseLinesInPlace(char* text, int numLines, size_t lineLength) {
    for (int i = 0; i < numLines / 2; ++i) {
        char* topLine = text + i * lineLength;
        char* bottomLine = text + (numLines - 1 - i) * lineLength;
        for (size_t j = 0; j < lineLength; ++j) {
            std::swap(topLine[j], bottomLine[j]);
        }
    }
}

// Утилита для вывода всех строк с разделением
void printLines(char* text, int numLines, size_t lineLength) {
    std::cout << "----- Начало вывода -----\n";
    for (int i = 0; i < numLines; ++i) {
        char* lineStart = text + i * lineLength;
        std::cout << "Строка " << i + 1 << ": " << lineStart << std::endl;
    }
    std::cout << "----- Конец вывода -----\n";
}

int main() {
    // Ввод количества строк и строк
    int n;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cin.ignore(); // Очищаем буфер после ввода числа

    const size_t lineLength = 100;
    char* text = new char[lineLength * n];  // Выделяем память для всех строк
    std::cout << "Введите строки (по одной на каждой строке):\n";
    for (int i = 0; i < n; ++i) {
        std::cin.getline(text + i * lineLength, lineLength);
    }

    // Вывод оригинального текста
    std::cout << "Оригинальный текст:\n";
    printLines(text, n, lineLength);

    // Обрабатываем массив строк в обратном порядке
    reverseLinesInPlace(text, n, lineLength);

    // Выводим результат
    std::cout << "Результат (в обратном порядке):\n";
    printLines(text, n, lineLength);

    delete[] text;  // Освобождаем память
    return 0;
}

