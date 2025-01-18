#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

// Структура для хранения результатов экзаменов студента
struct ExamResult {
    std::string lastName;     // Фамилия
    std::string firstName;    // Имя
    std::string groupNumber;  // Номер группы
    std::string subjects[5];  // Названия предметов
    int scores[5];          // Оценки по предметам
};

// Прототипы функций (объявления перед использованием)
void addStudent(std::vector<ExamResult> &students); // Добавление студента
void printAverageScoreByGroup(const std::vector<ExamResult> &students); // Вывод среднего балла по группе
void printUnsatisfactoryStudents(const std::vector<ExamResult> &students); // Вывод неуспевающих студентов
void printExcellentStudents(const std::vector<ExamResult> &students); // Вывод отличников
double calculateAverageScore(const int scores[5]); // Расчет среднего балла
bool isValidScore(int score); // Проверка валидности оценки


int main() {
setlocale(LC_ALL, "Russian");
    std::vector<ExamResult> students; // Динамический массив (вектор) структур

    while(true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить результаты студента\n";
        std::cout << "2. Вывести средний балл по группе\n";
        std::cout << "3. Вывести список неуспевающих студентов\n";
        std::cout << "4. Вывести список отличников\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера ввода

         switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                printAverageScoreByGroup(students);
                break;
            case 3:
                printUnsatisfactoryStudents(students);
                break;
            case 4:
                printExcellentStudents(students);
                break;
            case 0:
               std::cout << "Выход из программы.\n";
               return 0;

            default:
                std::cout << "Неверный выбор, попробуйте еще раз.\n";
        }
    }

    return 0;
}



// Функция для добавления результатов нового студента
void addStudent(std::vector<ExamResult> &students) {
    ExamResult newStudent;

    std::cout << "Введите фамилию: ";
    std::getline(std::cin, newStudent.lastName);

    std::cout << "Введите имя: ";
    std::getline(std::cin, newStudent.firstName);

    std::cout << "Введите номер группы: ";
    std::getline(std::cin, newStudent.groupNumber);

    for(int i=0; i<5; i++) {
        std::cout << "Введите название предмета " << i+1 << ": ";
        std::getline(std::cin, newStudent.subjects[i]);

        bool valid_score = false;
        while(!valid_score){
            std::cout << "Введите оценку по " << newStudent.subjects[i] << ": ";
            std::string score_str;
            std::getline(std::cin, score_str);
            std::stringstream ss(score_str);
            if(ss >> newStudent.scores[i] && ss.eof() && isValidScore(newStudent.scores[i]) ){
                valid_score = true;
            } else {
                 std::cout << "Неверная оценка. Оценка должна быть целым числом (2-5)" << std::endl;
             }
        }
    }
    students.push_back(newStudent); // Добавление структуры в массив
}

// Функция для расчета среднего балла
double calculateAverageScore(const int scores[5]) {
     double sum = 0.0;
     for (int i = 0; i < 5; i++) {
       sum += scores[i];
    }
    return sum / 5.0;
}

// Функция для проверки валидности оценки (от 2 до 5)
bool isValidScore(int score){
  return score >= 2 && score <= 5;
}


// Функция для вывода среднего балла по группе
void printAverageScoreByGroup(const std::vector<ExamResult> &students) {
    if (students.empty()) {
        std::cout << "Нет данных о студентах.\n";
        return;
    }

   std::string targetGroup;
    std::cout << "Введите номер группы для расчета среднего балла: ";
    std::getline(std::cin, targetGroup);

   double totalScore = 0.0;
    int studentCount = 0;

    for (const auto& student : students) {
         if (student.groupNumber == targetGroup) {
           totalScore += calculateAverageScore(student.scores);
            studentCount++;
        }
    }

    if (studentCount > 0) {
        double average = totalScore / studentCount;
         std::cout << std::fixed << std::setprecision(2) << "Средний балл для группы " << targetGroup << ": " << average << std::endl;
     } else {
          std::cout << "Студенты из группы " << targetGroup << " не найдены.\n" << std::endl;
      }
}


// Функция для вывода списка неуспевающих студентов
void printUnsatisfactoryStudents(const std::vector<ExamResult> &students) {
    if (students.empty()) {
        std::cout << "Нет данных о студентах.\n";
        return;
    }
      std::cout << "Неуспевающие студенты:\n";
      bool foundUnsatisfactory = false;

   std::vector<ExamResult> unsatStudents = students;

    std::sort(unsatStudents.begin(), unsatStudents.end(), [](const ExamResult& a, const ExamResult& b) {
        return a.lastName < b.lastName;
    });

   for (const auto& student : unsatStudents) {
        bool hasUnsatScore = false;
         std::vector<std::string> unsatSubjects;

        for (int i=0; i < 5; ++i){
          if(student.scores[i] < 3){
             hasUnsatScore = true;
             unsatSubjects.push_back(student.subjects[i]);
            }
        }

        if (hasUnsatScore) {
           foundUnsatisfactory = true;
            std::cout << student.lastName << " " << student.firstName << " (Группа: " << student.groupNumber << ") - ";
            for(size_t i = 0; i < unsatSubjects.size(); ++i) {
             std::cout << unsatSubjects[i];
             if(i < unsatSubjects.size()-1){
                  std::cout << ", ";
               }
            }
            std::cout << std::endl;
         }
    }
      if (!foundUnsatisfactory) {
        std::cout << "Неуспевающие студенты не найдены.\n";
    }
}


// Функция для вывода списка отличников
void printExcellentStudents(const std::vector<ExamResult> &students) {
    if (students.empty()) {
        std::cout << "Нет данных о студентах.\n";
        return;
    }


    std::cout << "Отличники:\n";
    int excellentCount = 0;
     for (const auto& student : students) {
        bool isExcellent = true;
        for(int score : student.scores) {
           if(score != 5){
             isExcellent = false;
             break;
          }
        }
          if (isExcellent) {
            excellentCount++;
             std::cout << student.lastName << " " << student.firstName << " (Группа: " << student.groupNumber << ")\n";
          }
     }

    if (students.size() > 0) {
      double percentage = static_cast<double>(excellentCount) / students.size() * 100;
     std::cout << std::fixed << std::setprecision(2) << "Процент отличников: " << percentage << "%\n";

    } else{
          std::cout << "Процент отличников: 0%\n";
     }
    if(excellentCount == 0) {
      std::cout << "Отличники не найдены.\n";
   }

}

