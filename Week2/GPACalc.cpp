#include <iostream>
#include <string>
#include <iomanip>

int main() {
    double total_points = 0;
    int total_credits = 0;

    std::string input;
    char repeat = 'Y';

    while (repeat == 'Y' || repeat == 'y') {
        std::cout << "Enter your credits and grade: ";
        std::cin >> input;

        int credits = input[0] - '0';
        std::string grade = input.substr(1);

        double credit_points = 0;

        if (grade == "A+" || grade == "A") {
            credit_points = 4.0;
        } else if (grade == "A-") {
            credit_points = 3.7;
        } else if (grade == "B+") {
            credit_points = 3.3;
        } else if (grade == "B") {
            credit_points = 3.0;
        } else if (grade == "B-") {
            credit_points = 2.7;
        } else if (grade == "C+") {
            credit_points = 2.3;
        } else if (grade == "C") {
            credit_points = 2.0;
        } else if (grade == "D") {
            credit_points = 1.0;
        } else if (grade == "F" || grade == "WU" || grade == "FIN" || grade == "FAB") {
            credit_points = 0.0;
        } else {
            std::cout << "Invalid grade entered." << std::endl;// Skip to the next iteration
        }

        total_credits += credits;
        total_points += credits * credit_points;

        if (credits > 0 && credits < 10) {
            double gpa = total_points / total_credits;

            std::cout << "Semester GPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
        }

        std::cout << "Do you want to enter another course? (Y/N): ";
        std::cin >> repeat;
    }
}


