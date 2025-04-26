// Kalashnikov_LR5_part2/Kalashnikov_MathOperations.h
#ifndef KALASHNIKOV_MATHOPERATIONS_H
#define KALASHNIKOV_MATHOPERATIONS_H

#include <iostream>
#include <limits>

namespace Kalashnikov {
    // Функция контроля ввода целых чисел
    int inputControl(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                break;
            } else {
                std::cout << "Ошибка ввода! Пожалуйста, введите целое число.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return value;
    }

    // Метод ввода трех чисел
    void inputNumbers(int& A, int& B, int& C) {
        std::cout << "Введите три целых числа:\n";
        A = inputControl("Число A: ");
        B = inputControl("Число B: ");
        C = inputControl("Число C: ");
    }

    // Вычисление остатка от деления разности A-B на C
    int calculateRemainder(int A, int B, int C) {
        if (C == 0) {
            throw std::runtime_error("Ошибка: деление на ноль!");
        }
        return (A - B) % C;
    }

    // Вычисление целой части от деления A на (B+C)
    int calculateIntegerDivision(int A, int B, int C) {
        int sum = B + C;
        if (sum == 0) {
            throw std::runtime_error("Ошибка: деление на ноль!");
        }
        return A / sum;
    }
}

#endif // KALASHNIKOV_MATHOPERATIONS_H