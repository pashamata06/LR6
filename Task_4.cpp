#include <iostream>
#include <vector>
#include <cstring> // Для работы с char
#include <stdexcept>

// Функция для разбиения строки на слова
std::vector<char*> splitWords(char* str) {
    std::vector<char*> words;
    char* word = std::strtok(str, " "); // Разделение по пробелам
    while (word != nullptr) {
        words.push_back(word);
        word = std::strtok(nullptr, " ");
    }
    return words;
}

// Функция для преобразования двумерного массива в одномерный массив слов
std::vector<char*> extractWords(char** strings, size_t rows) {
    std::vector<char*> words;
    for (size_t i = 0; i < rows; ++i) {
        std::vector<char*> lineWords = splitWords(strings[i]);
        words.insert(words.end(), lineWords.begin(), lineWords.end());
    }
    return words;
}

// Функция для записи слов обратно в массив строк
void fillStrings(char** strings, size_t rows, const std::vector<char*>& words) {
    size_t wordIndex = 0;
    for (size_t i = 0; i < rows; ++i) {
        size_t col = 0;
        while (wordIndex < words.size() && col < std::strlen(strings[i])) {
            std::strcpy(strings[i] + col, words[wordIndex]);
            col += std::strlen(words[wordIndex]) + 1;
            ++wordIndex;
        }
    }
}

// Основная функция реверса слов
void reverseWords(char** strings, size_t rows) {
    if (strings == nullptr || rows == 0) {
        throw std::invalid_argument("Input array is empty or null");
    }

    // Преобразовать массив строк в массив слов
    std::vector<char*> words = extractWords(strings, rows);

    // Реверсировать массив слов
    std::reverse(words.begin(), words.end());

    // Очистить строки
    for (size_t i = 0; i < rows; ++i) {
        std::memset(strings[i], 0, std::strlen(strings[i]));
    }

    // Записать слова обратно в массив строк
    fillStrings(strings, rows, words);
}

// Тестовая функция
void printStrings(char** strings, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        std::cout << strings[i] << std::endl;
    }
}

int main() {
    // Пример массива строк
    size_t rows = 3;
    char str1[] = "Hello world";
    char str2[] = "C++ programming language";
    char str3[] = "Reverse words task";

    char* strings[] = {str1, str2, str3};

    try {
        std::cout << "Before reversal:\n";
        printStrings(strings, rows);

        reverseWords(strings, rows);

        std::cout << "\nAfter reversal:\n";
        printStrings(strings, rows);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
