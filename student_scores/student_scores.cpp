// You need to create a C++ program that:
    // Stores student names and scores using a vector of pairs
    // Sorts students by score in descending order
    // Finds students with a specific score
    // Counts how many students scored above a threshold

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {

    // Declaring vector
    std::vector<std::pair<std::string, int>> students;

    // Declaring variable to store user input
    int n;

    // Ask user
    std::cout << "Enter the number of students: ";
    std::cin >> n;

    // Loop n times and populate the vector
    for (int i = 0; i < n; i+=1) {
        std::string student_name;
        int student_score;
        std::cout << "\nEnter name of the student: ";
        std::cin >> student_name;
        std::cout << "\nEnter score of the student: ";
        std::cin >> student_score;
        students.emplace_back(student_name, student_score);
    }

    // Sorting students by score (descending order)
    std::sort(students.begin(), students.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    // Display sorted list of students
    std::cout << "\n*** Sorted list of students ***" << std::endl;
    for (const auto& i : students) {
        std::cout << "Student name: " << i.first << "-> Score: " << i.second << std::endl;
    }

    // Search for a student with specific score
    std::cout << "\nEnter score to search: ";
    int score_to_search;
    std::cin >> score_to_search;
    // Usamos el algoritmo std::find_if -> scans the vector and returns the first element that matches
    auto it = std::find_if(students.begin(), students.end(),
        [score_to_search](const auto& x) {
            return x.second == score_to_search;
        });

    // Display results
    if (it != students.end()) {
        std::cout << "Student found: " << it->first << ", with a score of: " << it->second << std::endl;
    }
    else {
        std::cout << "No student found with a score of: " << score_to_search << std::endl;
    }

    // Count students above a threshold
    std::cout << "Type a threshold to show students above that threshold: ";
    int threshold;
    std::cin >> threshold;
    // Usamos el algoritmo count_if -> retorna el numero de estudiantes por encima del threshold
    auto number = std::count_if(students.begin(), students.end(),
        [threshold](const auto& s)
        {return s.second > threshold;});
    // Display
    std::cout << "Number of students with grade above " << threshold << ": " << number << std::endl;

    return 0;
}
