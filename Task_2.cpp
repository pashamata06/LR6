#include <iostream>
#include <cstring>

// Функция для вставки подстроки после указанного символа (однократная вставка)
void insertSubstringAfterCharOnce(char* text, char symbol, const char* substring) {
    size_t textLength = strlen(text);
    size_t subLength = strlen(substring);
    size_t newLength = textLength + subLength;

    // Создаем новый массив для результата
    char* result = new char[newLength + 1]; // +1 для '\0'
    size_t resIndex = 0;

    bool inserted = false; // Проверка, вставлена ли подстрока
    for (size_t i = 0; i < textLength; ++i) {
        result[resIndex++] = text[i];
        if (text[i] == symbol && !inserted) {
            // Вставляем подстроку после символа
            for (size_t j = 0; j < subLength; ++j) {
                result[resIndex++] = substring[j];
            }
            inserted = true;
        }
    }

    result[resIndex] = '\0'; // Завершаем строку

    // Вывод результата
    std::cout << "Результат (однократная вставка): " << result << std::endl;

    delete[] result; // Освобождаем память
}

// Функция для вставки подстроки после каждого указанного символа
void insertSubstringAfterCharMultiple(char* text, char symbol, const char* substring) {
    size_t textLength = strlen(text);
    size_t subLength = strlen(substring);
    size_t maxNewLength = textLength + subLength * textLength; // Максимальная возможная длина

    // Создаем новый массив для результата
    char* result = new char[maxNewLength + 1]; // +1 для '\0'
    size_t resIndex = 0;

    for (size_t i = 0; i < textLength; ++i) {
        result[resIndex++] = text[i];
        if (text[i] == symbol) {
            // Вставляем подстроку после символа
            for (size_t j = 0; j < subLength; ++j) {
                result[resIndex++] = substring[j];
            }
        }
    }

    result[resIndex] = '\0'; // Завершаем строку

    // Вывод результата
    std::cout << "Результат (многократная вставка): " << result << std::endl;

    delete[] result; // Освобождаем память
}

// Основная функция программы
int main() {
    char* text = new char[101]; // Динамический массив для текста (100 символов + '\0')
    char* substring = new char[101]; // Динамический массив для подстроки (100 символов + '\0')

    char symbol;

    // Ввод данных с проверкой
    std::cout << "Введите текст (не более 100 символов): ";
    std::cin.getline(text, 101);

    if (strlen(text) == 0) {
        std::cerr << "Ошибка: текст не должен быть пустым!" << std::endl;
        delete[] text;
        delete[] substring;
        return 1;
    }

    std::cout << "Введите символ, после которого вставить подстроку: ";
    std::cin >> symbol;

    std::cin.ignore(); // Очистка буфера после ввода символа

    std::cout << "Введите подстроку (не более 100 символов): ";
    std::cin.getline(substring, 101);

    if (strlen(substring) == 0) {
        std::cerr << "Ошибка: подстрока не должна быть пустой!" << std::endl;
        delete[] text;
        delete[] substring;
        return 1;
    }

    // Вывод исходных данных
    std::cout << "Исходный текст: " << text << std::endl;
    std::cout << "Символ для вставки: " << symbol << std::endl;
    std::cout << "Подстрока для вставки: " << substring << std::endl;

    // Обработка текста (однократная и многократная вставка)
    insertSubstringAfterCharOnce(text, symbol, substring);
    insertSubstringAfterCharMultiple(text, symbol, substring);

    // Освобождение памяти
    delete[] text;
    delete[] substring;

    return 0;
}

