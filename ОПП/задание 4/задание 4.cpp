#include <iostream>
#include <fstream>  
#include <vector>   
#include <random>   
#include <iomanip>  

// ������� ��� �������� ��������� �����
void createBinaryFile() {
    std::ofstream outfile("numbers.bin", std::ios::binary); // ��������� ���� ��� ������ � �������� ������
    if (!outfile.is_open()) {
        std::cerr << "������: �� ������� ������� �������� ����." << std::endl;
        return; // �������, ���� ���� �� ������
    }

    std::random_device rd;  // ��� ��������� ��������� �����
    std::mt19937 gen(rd());  // ��������� ��������� �����
    std::uniform_int_distribution<> distrib(5, 20); // ������������� ��� ���������� ����� ��������� (�� 5 �� 20)
    int numCount = distrib(gen); // ���������� ��������� ���������� �����

    std::uniform_int_distribution<> valDistrib(-100, 100);  // ������������� ��� �������� ����� (�� -100 �� 100)
    std::vector<int> numbers; // ������ ��� �������� �����

     // ���������� ������������ ����� ������� ����� ������:
    std::cout << "�������� ������ ����� ������:\n";
    std::cout << "1. ������ ����� �������\n";
    std::cout << "2. ������������� ��������� �����\n";
    std::cout << "��� �����: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {  // ���� ������ ������ ����
        for (int i = 0; i < numCount; ++i) {
            int number;
            std::cout << "������� ����� " << i + 1 << ": ";
            std::cin >> number;
            numbers.push_back(number);
        }
    } else if (choice == 2) {  // ���� ������� ��������� ���������
        for (int i = 0; i < numCount; ++i) {
             numbers.push_back(valDistrib(gen)); // ��������� ��������������� ����� � ������
        }
    } else {
        std::cerr << "������: �������� �����.\n";
        outfile.close();
        return;
    }

    // ���������� ���������� ��������� � ������ �����
    outfile.write(reinterpret_cast<const char*>(&numCount), sizeof(numCount));
    // ���������� ���� ����� � ����
    outfile.write(reinterpret_cast<const char*>(numbers.data()), numCount * sizeof(int));

    std::cout << "�������� �����, ���������� � ����: ";
    for(int num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    outfile.close();
}

// ������� ��� ��������� ��������� ����� � ������ �������
void processBinaryFile() {
    std::ifstream infile("numbers.bin", std::ios::binary);  // ��������� �������� ���� ��� ������
    if (!infile.is_open()) {
        std::cerr << "������: �� ������� ������� ������� ����." << std::endl;
        return; // �������, ���� ���� �� ������
    }

    int numCount;
    // ������ ���������� ����� �� ��������� �����
    infile.read(reinterpret_cast<char*>(&numCount), sizeof(numCount));
     if(infile.fail()){
          std::cerr << "������ ������ ���������� ��������� �� ��������� �����" << std::endl;
           return;
      }

    std::vector<int> numbers(numCount); // ������� ������ ��� �������� �����

     // ������ ���� ����� �� ��������� �����
    infile.read(reinterpret_cast<char*>(numbers.data()), numCount * sizeof(int));
      if(infile.fail()){
          std::cerr << "������ ������ ����� �� ��������� �����" << std::endl;
           return;
      }

    infile.close(); // ��������� ����

    int numCols = 4;  // ���������� �������� � �������
    int numRows = (numCount + numCols - 1) / numCols;  // ��������� ���������� ����� � ����������� � ������� �������
    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols, 0));  // ������� ������� � ��������� ������

    int index = 0;
    // ��������� �������
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (index < numCount) {
                 matrix[i][j] = numbers[index++]; // ��������� ������� ������� �� �����
            } else {
                 matrix[i][j] = 0; // ��������� ���������� �������� ������
            }
        }
    }

    // ������� ������� �� �����
     std::cout << "�������:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << std::setw(5) << val; // ������� ����� � ��������������� ������ � 5 ��������
        }
        std::cout << std::endl;
    }

    // ������� ����������� �������
    std::cout << "����������� �������: " << numRows << " x " << numCols << std::endl;

    int mainDiagonalSum = 0;  // ����� ������� ���������
    int secondaryDiagonalSum = 0;  // ����� �������� ���������
    int minSize = std::min(numRows, numCols); // ����� �� ����� �� ������� ������������� �������
    // ��������� ����� ����������
    for (int i = 0; i < minSize; ++i) {
        mainDiagonalSum += matrix[i][i];  // ��������� �������� ������� ���������
        secondaryDiagonalSum += matrix[i][numCols - 1 - i];  // ��������� �������� �������� ���������
    }

    // ������� ����� ����������
    std::cout << "����� ��������� ������� ���������: " << mainDiagonalSum << std::endl;
    std::cout << "����� ��������� �������� ���������: " << secondaryDiagonalSum << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    createBinaryFile(); // �������� ������� �������� �����
    processBinaryFile(); // �������� ������� ��������� �����
    return 0;
}

