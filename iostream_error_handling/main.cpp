#include <iostream>
#include <fstream>
#include <stdexcept>

int main() {
    // Intentamos abrir un archivo
    try {
        std::ifstream file ("file.txt");
        if (!file) {      // Si el archivo no se encuentra
            throw std::runtime_error("File could not be opened!");   // Tira este error
        }
        std::cout << "File opened successfully!"; // Si toodo va bien muestra este mensaje
        return 0;
    } catch (const std::exception& e) {  // Si hay un error, muestra o "caza" cual de todos ha sido (en nuestro ejemplo solo hay uno)
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
