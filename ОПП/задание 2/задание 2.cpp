#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

// ��������� ��� �������� ����������� ��������� ��������
struct ExamResult {
    std::string lastName;     // �������
    std::string firstName;    // ���
    std::string groupNumber;  // ����� ������
    std::string subjects[5];  // �������� ���������
    int scores[5];          // ������ �� ���������
};

// ��������� ������� (���������� ����� ��������������)
void addStudent(std::vector<ExamResult> &students); // ���������� ��������
void printAverageScoreByGroup(const std::vector<ExamResult> &students); // ����� �������� ����� �� ������
void printUnsatisfactoryStudents(const std::vector<ExamResult> &students); // ����� ������������ ���������
void printExcellentStudents(const std::vector<ExamResult> &students); // ����� ����������
double calculateAverageScore(const int scores[5]); // ������ �������� �����
bool isValidScore(int score); // �������� ���������� ������


int main() {
setlocale(LC_ALL, "Russian");
    std::vector<ExamResult> students; // ������������ ������ (������) ��������

    while(true) {
        std::cout << "\n����:\n";
        std::cout << "1. �������� ���������� ��������\n";
        std::cout << "2. ������� ������� ���� �� ������\n";
        std::cout << "3. ������� ������ ������������ ���������\n";
        std::cout << "4. ������� ������ ����������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� ��������: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // ������� ������ �����

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
               std::cout << "����� �� ���������.\n";
               return 0;

            default:
                std::cout << "�������� �����, ���������� ��� ���.\n";
        }
    }

    return 0;
}



// ������� ��� ���������� ����������� ������ ��������
void addStudent(std::vector<ExamResult> &students) {
    ExamResult newStudent;

    std::cout << "������� �������: ";
    std::getline(std::cin, newStudent.lastName);

    std::cout << "������� ���: ";
    std::getline(std::cin, newStudent.firstName);

    std::cout << "������� ����� ������: ";
    std::getline(std::cin, newStudent.groupNumber);

    for(int i=0; i<5; i++) {
        std::cout << "������� �������� �������� " << i+1 << ": ";
        std::getline(std::cin, newStudent.subjects[i]);

        bool valid_score = false;
        while(!valid_score){
            std::cout << "������� ������ �� " << newStudent.subjects[i] << ": ";
            std::string score_str;
            std::getline(std::cin, score_str);
            std::stringstream ss(score_str);
            if(ss >> newStudent.scores[i] && ss.eof() && isValidScore(newStudent.scores[i]) ){
                valid_score = true;
            } else {
                 std::cout << "�������� ������. ������ ������ ���� ����� ������ (2-5)" << std::endl;
             }
        }
    }
    students.push_back(newStudent); // ���������� ��������� � ������
}

// ������� ��� ������� �������� �����
double calculateAverageScore(const int scores[5]) {
     double sum = 0.0;
     for (int i = 0; i < 5; i++) {
       sum += scores[i];
    }
    return sum / 5.0;
}

// ������� ��� �������� ���������� ������ (�� 2 �� 5)
bool isValidScore(int score){
  return score >= 2 && score <= 5;
}


// ������� ��� ������ �������� ����� �� ������
void printAverageScoreByGroup(const std::vector<ExamResult> &students) {
    if (students.empty()) {
        std::cout << "��� ������ � ���������.\n";
        return;
    }

   std::string targetGroup;
    std::cout << "������� ����� ������ ��� ������� �������� �����: ";
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
         std::cout << std::fixed << std::setprecision(2) << "������� ���� ��� ������ " << targetGroup << ": " << average << std::endl;
     } else {
          std::cout << "�������� �� ������ " << targetGroup << " �� �������.\n" << std::endl;
      }
}


// ������� ��� ������ ������ ������������ ���������
void printUnsatisfactoryStudents(const std::vector<ExamResult> &students) {
    if (students.empty()) {
        std::cout << "��� ������ � ���������.\n";
        return;
    }
      std::cout << "������������ ��������:\n";
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
            std::cout << student.lastName << " " << student.firstName << " (������: " << student.groupNumber << ") - ";
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
        std::cout << "������������ �������� �� �������.\n";
    }
}


// ������� ��� ������ ������ ����������
void printExcellentStudents(const std::vector<ExamResult> &students) {
    if (students.empty()) {
        std::cout << "��� ������ � ���������.\n";
        return;
    }


    std::cout << "���������:\n";
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
             std::cout << student.lastName << " " << student.firstName << " (������: " << student.groupNumber << ")\n";
          }
     }

    if (students.size() > 0) {
      double percentage = static_cast<double>(excellentCount) / students.size() * 100;
     std::cout << std::fixed << std::setprecision(2) << "������� ����������: " << percentage << "%\n";

    } else{
          std::cout << "������� ����������: 0%\n";
     }
    if(excellentCount == 0) {
      std::cout << "��������� �� �������.\n";
   }

}

