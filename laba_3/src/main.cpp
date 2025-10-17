#include <iostream>
#include "Triangle.hpp"
#include "Hexagon.hpp"
#include "Octagon.hpp"
#include "FigureVector.hpp"

void printMenu() {
    std::cout << "\n=== Система управления фигурами ===" << std::endl;
    std::cout << "1. Добавить треугольник" << std::endl;
    std::cout << "2. Добавить шестиугольник" << std::endl;
    std::cout << "3. Добавить восьмиугольник" << std::endl;
    std::cout << "4. Показать все центры и площади" << std::endl;
    std::cout << "5. Вычислить общую площадь" << std::endl;
    std::cout << "6. Удалить фигуру по индексу" << std::endl;
    std::cout << "7. Очистить все фигуры" << std::endl;
    std::cout << "8. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

int main() {
    FigureVector figures;
    int choice;
    
    do {
        printMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                Triangle* triangle = new Triangle();
                std::cout << "Введите параметры треугольника (радиус x_центра y_центра): ";
                std::cin >> *triangle;
                figures.push(triangle);
                std::cout << "Треугольник добавлен!" << std::endl;
                break;
            }
            case 2: {
                Hexagon* hexagon = new Hexagon();
                std::cout << "Введите параметры шестиугольника (радиус x_центра y_центра): ";
                std::cin >> *hexagon;
                figures.push(hexagon);
                std::cout << "Шестиугольник добавлен!" << std::endl;
                break;
            }
            case 3: {
                Octagon* octagon = new Octagon();
                std::cout << "Введите параметры восьмиугольника (радиус x_центра y_центра): ";
                std::cin >> *octagon;
                figures.push(octagon);
                std::cout << "Восьмиугольник добавлен!" << std::endl;
                break;
            }
            case 4: {
                std::cout << "\n=== Все фигуры ===" << std::endl;
                if (figures.getSize() == 0) {
                    std::cout << "Фигур нет." << std::endl;
                } else {
                    figures.printAllCentersAndAreas();
                }
                break;
            }
            case 5: {
                double total = figures.calculateTotalArea();
                std::cout << "Общая площадь всех фигур: " << total << std::endl;
                break;
            }
            case 6: {
                size_t index;
                std::cout << "Введите индекс для удаления: ";
                std::cin >> index;
                if (index < figures.getSize()) {
                    figures.remove(index);
                    std::cout << "Фигура удалена!" << std::endl;
                } else {
                    std::cout << "Неверный индекс!" << std::endl;
                }
                break;
            }
            case 7: {
                figures.clear();
                std::cout << "Все фигуры очищены!" << std::endl;
                break;
            }
            case 8: {
                std::cout << "До свидания!" << std::endl;
                break;
            }
            default: {
                std::cout << "Неверный выбор!" << std::endl;
                break;
            }
        }
    } while (choice != 8);
    
    return 0;
}