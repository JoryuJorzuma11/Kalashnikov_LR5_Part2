// Kalashnikov_LR5_part2/Kalashnikov_MathOperations.cpp
#include <iostream>
#include "Kalashnikov_MathOperations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << "Программа для математических операций\n";
    std::cout << "===================================\n";
    
    int A, B, C;
    
    // Ввод данных
    Kalashnikov::inputNumbers(A, B, C);
    
    try {
        // Вычисление остатка
        int remainder = Kalashnikov::calculateRemainder(A, B, C);
        std::cout << "\nОстаток от деления (A-B) на C: " << remainder << std::endl;
        
        // Вычисление целой части
        int intDivision = Kalashnikov::calculateIntegerDivision(A, B, C);
        std::cout << "Целая часть от деления A на (B+C): " << intDivision << std::endl;
    } 
    catch (const std::runtime_error& e) {
        std::cerr << "\nОшибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}