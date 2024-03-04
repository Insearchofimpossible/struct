#include <iostream>
#include <string>
#include <fstream>
struct student {
    std::string familia; std::string name; std::string otchestvo; std::string phone_number; int group; int marks[3];
    void enter_info(std::string f1, std::string i1, std::string o1, std::string p1, int g1, double m1, double m2, double m3) {
        familia = f1; name = i1; otchestvo = o1; phone_number = p1; group = g1; marks[0] = m1; marks[1] = m2; marks[2] = m3;
    }
};
int main() {
    student stud[100]; student stud1[100];
    setlocale(LC_ALL, "Ru"); system("chcp 1251>null"); int number_of_students;
    std::cout << "¬ведите количество студентов: "; std::cin >> number_of_students;
    for (int j = 0; j < number_of_students; j++) {
        std::string f, i, o; std::string p1; int g1; double m1, m2, m3;
        std::cout << "¬ведите фамилию, им€, отчество, номер телефона, номер группы и оценки студента: " << '\n';
        std::cin >> f >> i >> o >> p1 >> g1 >> m1 >> m2 >> m3;
        stud[j].enter_info(f, i, o, p1, g1, m1, m2, m3);
    }
    double avr; std::cout << "¬ведите среднее арифметическое: "; std::cin >> avr;
    int num, k = 0; std::cout << "¬ведите номер группы: "; std::cin >> num;
    for (int i = 0; i < number_of_students; i++) {
        double avr1 = (stud[i].marks[0] + stud[i].marks[1] + stud[i].marks[2]) / 3.0;
        if (avr1 >= avr || stud[i].group != num) {
            stud1[k] = stud[i]; k++;
        }
    }
    for (int i = 0; i < k; i++) {
        std::cout << stud1[i].familia << " " << stud1[i].name << " " << stud1[i].otchestvo << " " << stud1[i].phone_number << " " << stud1[i].group << " " << stud1[i].marks[0] << " " << stud1[i].marks[1] << " " << stud1[i].marks[2] << '\n';
    }
    std::string fam; std::string f, i, o; std::string p1; int g1; double m1, m2, m3; int number = 0;
    std::cout << "¬ведите фамилию студента, перед которым нужно поставить другого: "; std::cin >> fam;
    std::cin >> f >> i >> o >> p1 >> g1 >> m1 >> m2 >> m3;
    for (int m = 0; m < k; m++) {
        if (stud1[m].familia == fam) {
            stud[100 - 1].enter_info(f, i, o, p1, g1, m1, m2, m3 ); number = m;
            for (int j = k; j > m + 1; j--) {
                stud1[j] = stud[j - 1];
            }
        }
    }
    stud1[number + 1] = stud[100 - 1];
    for (int i = 0; i < k + 1; i++) {
        std::cout << stud1[i].familia << " " << stud1[i].name << " " << stud1[i].otchestvo << " " << stud1[i].phone_number << " " << stud1[i].group << " " << stud1[i].marks[0] << " " << stud1[i].marks[1] << " " << stud1[i].marks[2] << '\n';
    }
    std::ofstream s1("s1.txt");
    for (int i = 0; i < k + 1; i++) {
        {s1 << stud1[i].familia << " " << stud1[i].name << " " << stud1[i].otchestvo << " " << stud1[i].phone_number << " " << stud1[i].group << " " << stud1[i].marks[0] << " " << stud1[i].marks[1] << " " << stud1[i].marks[2] << '\n'; }
    }
    s1.close();
}