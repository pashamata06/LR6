#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

// Функция для поиска групп с четным количеством символов
void findEvenGroups(const char* input) {
    std::vector<std::string> evenGroups;
    std::string currentGroup;

    for (size_t i = 0; input[i] != '\0'; ++i) {
        if (input[i] == '0' || input[i] == '1') {
            currentGroup += input[i];
        } else if (input[i] == ' ' || input[i + 1] == '\0') {
            // Если конец группы, проверяем длину
            if (currentGroup.length() % 2 == 0 && !currentGroup.empty()) {
                evenGroups.push_back(currentGroup);
            }
            currentGroup.clear();
        }
    }

    // Вывод результата
    std::cout << "Группы с четным количеством символов:" << std::endl;
    if (evenGroups.empty()) {
        std::cout << "Нет групп с четным количеством символов." << std::endl;
    } else {
        // Используем обычный цикл for вместо range-based
        for (size_t i = 0; i < evenGroups.size(); ++i) {
            std::cout << evenGroups[i] << std::endl;
        }
    }
}

// Функция для ввода строки с проверкой на корректность
void inputString(char* input, size_t size) {
    std::cout << "Введите строку (группы нулей и единиц, разделенные пробелами): " << std::endl;

    while (true) {
        size_t i = 0;
        char ch;
        bool isValid = true;

        // Считываем строку с помощью getchar()
        while ((ch = getchar()) != '\n' && i < size - 1) {
            if (ch != ' ' && ch != '0' && ch != '1') {
                std::cout << "Ошибка: введены недопустимые символы. Введите только 0, 1 и пробел." << std::endl;
                isValid = false;
                break;
            }
            input[i++] = ch;
        }

        if (isValid) {
            input[i] = '\0'; // Завершаем строку
            break;
        }
    }
}

// Функция для вывода статистики о строках
void printStatistics(const char* input) {
    size_t length = 0;
    size_t zeroCount = 0;
    size_t oneCount = 0;

    for (size_t i = 0; input[i] != '\0'; ++i) {
        length++;
        if (input[i] == '0') {
            zeroCount++;
        } else if (input[i] == '1') {
            oneCount++;
        }
    }

    std::cout << "\nСтатистика по введенной строке:" << std::endl;
    std::cout << "Общая длина строки: " << length << std::endl;
    std::cout << "Количество нулей: " << zeroCount << std::endl;
    std::cout << "Количество единиц: " << oneCount << std::endl;
}

// Функция для очистки и освобождения памяти
void clearMemory(char* input) {
    delete[] input; // Освобождаем память
}

int main() {
    char* input = new char[161]; // Увеличиваем размер массива (160 символов + '\0')

    // Ввод строки
    inputString(input, 161);

    // Вывод статистики по строке
    printStatistics(input);

    // Обработка строки
    findEvenGroups(input);

    // Освобождение памяти
    clearMemory(input);

    return 0;
}

