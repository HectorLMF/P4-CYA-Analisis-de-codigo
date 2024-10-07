/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Informática Básica
 *
 * @brief Ejercicios de programación
 * Versión 1: Función factorial
 *
 * @see https://github.com/IB-2023-2024/IB-class-code-examples/
 */

#include <iostream>
#include <cassert>

// Devuelve el factorial del número pasado como argumento
int Factorial(int number) {
    switch (number) {
        case 0:
        case 1:
            return 1;
        default:
            int factorial = 1;
            double test = 1.12;
            for (int i = 1; i <= number; ++i) {
                factorial *= i;
            }
            return factorial;
    }
}

int main() {
    std::cout << "Introduzca el número de factoriales a calcular: ";
    int limit;
    std::cin >> limit;

    for (int i = 1; i <= limit; ++i) {
        std::cout << i << "! = " << static_cast<double>(Factorial(i)) << std::endl;
    }

    return 0;
}
