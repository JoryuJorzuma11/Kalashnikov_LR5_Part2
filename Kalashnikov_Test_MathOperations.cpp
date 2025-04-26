// Kalashnikov_LR5_part2/Kalashnikov_Test_MathOperations.cpp
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Kalashnikov_MathOperations.h"
#include <sstream>
#include <stdexcept>

// 1. Тесты для функции контроля ввода данных
void testInputControl_NormalInput() {
    std::istringstream input("42\n");
    std::cin.rdbuf(input.rdbuf());
    int result = Kalashnikov::inputControl("Введите число: ");
    ASSERT_EQUAL(42, result);
}

void testInputControl_InvalidThenValidInput() {
    std::istringstream input("abc\n42\n");
    std::cin.rdbuf(input.rdbuf());
    
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    int result = Kalashnikov::inputControl("Введите число: ");
    
    std::cout.rdbuf(oldCout);
    
    ASSERT_EQUAL(42, result);
    ASSERT_NOT_EQUAL(std::string::npos, output.str().find("Ошибка ввода"));
}

void testInputControl_MultipleInvalidInputs() {
    std::istringstream input("x\ny\nz\n42\n");
    std::cin.rdbuf(input.rdbuf());
    
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    int result = Kalashnikov::inputControl("Введите число: ");
    
    std::cout.rdbuf(oldCout);
    
    ASSERT_EQUAL(42, result);
    ASSERT_NOT_EQUAL(std::string::npos, output.str().find("Ошибка ввода"));
}

// 2. Тесты для функции вычисления остатка
void testCalculateRemainder_PositiveNumbers() {
    ASSERT_EQUAL(1, Kalashnikov::calculateRemainder(5, 4, 2));
    ASSERT_EQUAL(0, Kalashnikov::calculateRemainder(10, 2, 4));
}

void testCalculateRemainder_NegativeNumbers() {
    ASSERT_EQUAL(-1, Kalashnikov::calculateRemainder(-5, -4, 2));
    ASSERT_EQUAL(0, Kalashnikov::calculateRemainder(-10, -2, -4));
}

void testCalculateRemainder_ZeroDivision() {
    ASSERT_THROWS(Kalashnikov::calculateRemainder(5, 3, 0), std::runtime_error);
}

// 3. Тесты для функции целочисленного деления
void testCalculateIntegerDivision_PositiveNumbers() {
    ASSERT_EQUAL(2, Kalashnikov::calculateIntegerDivision(10, 3, 2));
    ASSERT_EQUAL(1, Kalashnikov::calculateIntegerDivision(15, 5, 5));
}

void testCalculateIntegerDivision_NegativeNumbers() {
    ASSERT_EQUAL(-3, Kalashnikov::calculateIntegerDivision(-15, 2, 3));
    ASSERT_EQUAL(2, Kalashnikov::calculateIntegerDivision(-10, -3, -2));
}

void testCalculateIntegerDivision_ZeroDivision() {
    ASSERT_THROWS(Kalashnikov::calculateIntegerDivision(5, 2, -2), std::runtime_error);
}

// 4. Тест для функции ввода трех чисел
void testInputNumbers_FullCycle() {
    std::istringstream input("5\nabc\n10\n0\n3\n");
    std::cin.rdbuf(input.rdbuf());
    
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    
    int A, B, C;
    Kalashnikov::inputNumbers(A, B, C);
    
    std::cout.rdbuf(oldCout);
    
    ASSERT_EQUAL(5, A);
    ASSERT_EQUAL(10, B);
    ASSERT_EQUAL(3, C);
    ASSERT_NOT_EQUAL(std::string::npos, output.str().find("Ошибка ввода"));
}

cute::suite make_suite_MathOperationsTests() {
    cute::suite s;
    
    // Тесты контроля ввода
    s.push_back(CUTE(testInputControl_NormalInput));
    s.push_back(CUTE(testInputControl_InvalidThenValidInput));
    s.push_back(CUTE(testInputControl_MultipleInvalidInputs));
    
    // Тесты вычисления остатка
    s.push_back(CUTE(testCalculateRemainder_PositiveNumbers));
    s.push_back(CUTE(testCalculateRemainder_NegativeNumbers));
    s.push_back(CUTE(testCalculateRemainder_ZeroDivision));
    
    // Тесты целочисленного деления
    s.push_back(CUTE(testCalculateIntegerDivision_PositiveNumbers));
    s.push_back(CUTE(testCalculateIntegerDivision_NegativeNumbers));
    s.push_back(CUTE(testCalculateIntegerDivision_ZeroDivision));
    
    // Комплексный тест ввода
    s.push_back(CUTE(testInputNumbers_FullCycle));
    
    return s;
}

int main(int argc, char const *argv[]) {
    cute::ide_listener<> lis;
    cute::makeRunner(lis)(make_suite_MathOperationsTests(), "All MathOperations Tests");
    return 0;
}