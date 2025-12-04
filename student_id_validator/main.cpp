// Build a program that stores and validate unique student ID

#include <iostream>
#include <set>

int main() {
    // Declaramos un set para guardar IDs
    std::set <int> student_IDs;

    // Variable para guardar los IDs
    int id;
    std::cout << "Enter 5 student IDs: " << std::endl;

    // Hacemos un loop para popular el set
    for (int i = 0; i<5; ++i) {
        std::cin >> id;

        // Chequeamos que lo inserta correctamente
        // .insert() retorna un pair -> .second es verdadero cuando insert funciona
        if (student_IDs.insert(id).second == false) {
            std::cout << "Duplicate ID! Ignored \n";
        }
        else {
            // Monstramos el id añadido correctamente
            std::cout << "Student ID: " << id << " added correctly!" << std::endl;
        }

    }

    // Fuera del bucle for, mostramos todos los IDs
    std::cout << "\n*** ALL STUDENTS ***" << std::endl;
    std::cout << "\t- Student set size: " << student_IDs.size() << std::endl;
    for (int i : student_IDs) {
        std::cout << i << " " << std::endl;
    }
    return 0;
}
