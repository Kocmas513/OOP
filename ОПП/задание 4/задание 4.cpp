#include <iostream>
#include <fstream>  
#include <vector>   
#include <random>   
#include <iomanip>  

// Функция для создания бинарного файла
void createBinaryFile() {
    std::ofstream outfile("numbers.bin", std::ios::binary); // Открываем файл для записи в бинарном режиме
    if (!outfile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть выходной файл." << std::endl;
        return; // Выходим, если файл не открыт
    }

    std::random_device rd;  // Для генерации случайных чисел
    std::mt19937 gen(rd());  // Генератор случайных чисел
    std::uniform_int_distribution<> distrib(5, 20); // Распределение для случайного числа элементов (от 5 до 20)
    int numCount = distrib(gen); // Генерируем случайное количество чисел

    std::uniform_int_distribution<> valDistrib(-100, 100);  // Распределение для значений чисел (от -100 до 100)
    std::vector<int> numbers; // Вектор для хранения чисел

     // Предлагаем пользователю выбор способа ввода данных:
    std::cout << "Выберите способ ввода данных:\n";
    std::cout << "1. Ввести числа вручную\n";
    std::cout << "2. Сгенерировать случайные числа\n";
    std::cout << "Ваш выбор: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {  // Если выбран ручной ввод
        for (int i = 0; i < numCount; ++i) {
            int number;
            std::cout << "Введите число " << i + 1 << ": ";
            std::cin >> number;
            numbers.push_back(number);
        }
    } else if (choice == 2) {  // Если выбрана случайная генерация
        for (int i = 0; i < numCount; ++i) {
             numbers.push_back(valDistrib(gen)); // Добавляем сгенерированное число в вектор
        }
    } else {
        std::cerr << "Ошибка: Неверный выбор.\n";
        outfile.close();
        return;
    }

    // Записываем количество элементов в начало файла
    outfile.write(reinterpret_cast<const char*>(&numCount), sizeof(numCount));
    // Записываем сами числа в файл
    outfile.write(reinterpret_cast<const char*>(numbers.data()), numCount * sizeof(int));

    std::cout << "Исходные числа, записанные в файл: ";
    for(int num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    outfile.close();
}

// Функция для обработки бинарного файла и вывода матрицы
void processBinaryFile() {
    std::ifstream infile("numbers.bin", std::ios::binary);  // Открываем бинарный файл для чтения
    if (!infile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть входной файл." << std::endl;
        return; // Выходим, если файл не открыт
    }

    int numCount;
    // Читаем количество чисел из бинарного файла
    infile.read(reinterpret_cast<char*>(&numCount), sizeof(numCount));
     if(infile.fail()){
          std::cerr << "Ошибка чтения количества элементов из бинарного файла" << std::endl;
           return;
      }

    std::vector<int> numbers(numCount); // Создаем вектор для хранения чисел

     // Читаем сами числа из бинарного файла
    infile.read(reinterpret_cast<char*>(numbers.data()), numCount * sizeof(int));
      if(infile.fail()){
          std::cerr << "Ошибка чтения чисел из бинарного файла" << std::endl;
           return;
      }

    infile.close(); // Закрываем файл

    int numCols = 4;  // Количество столбцов в матрице
    int numRows = (numCount + numCols - 1) / numCols;  // Вычисляем количество строк с округлением в большую сторону
    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols, 0));  // Создаем матрицу и заполняем нулями

    int index = 0;
    // Заполняем матрицу
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (index < numCount) {
                 matrix[i][j] = numbers[index++]; // Заполняем матрицу числами из файла
            } else {
                 matrix[i][j] = 0; // Заполняем оставшиеся элементы нулями
            }
        }
    }

    // Выводим матрицу на экран
     std::cout << "Матрица:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(5) << val; // Выводим число с форматированием ширины в 5 символов
        }
        std::cout << std::endl;
    }

    // Выводим размерность матрицы
    std::cout << "Размерность матрицы: " << numRows << " x " << numCols << std::endl;

    int mainDiagonalSum = 0;  // Сумма главной диагонали
    int secondaryDiagonalSum = 0;  // Сумма побочной диагонали
    int minSize = std::min(numRows, numCols); // Чтобы не выйти за границы прямоугольной матрицы
    // Вычисляем суммы диагоналей
    for (int i = 0; i < minSize; ++i) {
        mainDiagonalSum += matrix[i][i];  // Суммируем элементы главной диагонали
        secondaryDiagonalSum += matrix[i][numCols - 1 - i];  // Суммируем элементы побочной диагонали
    }

    // Выводим суммы диагоналей
    std::cout << "Сумма элементов главной диагонали: " << mainDiagonalSum << std::endl;
    std::cout << "Сумма элементов побочной диагонали: " << secondaryDiagonalSum << std::endl;
}

int main() {
setlocale(LC_ALL, "Russian");
    createBinaryFile(); // Вызываем функцию создания файла
    processBinaryFile(); // Вызываем функцию обработки файла
    return 0;
}

