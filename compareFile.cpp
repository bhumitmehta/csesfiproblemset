#include <iostream>
#include <fstream>
#include <string>

void compareFiles(const std::string& file1Path, const std::string& file2Path) {
    std::ifstream file1(file1Path);
    std::ifstream file2(file2Path);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error: Could not open one or both files." << std::endl;
        return;
    }

    std::string line1, line2;
    int lineNumber = 1;
    bool differencesFound = false;

    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) {
            std::cout << "Difference found at line " << lineNumber << ":\n";
            std::cout << "File 1: " << line1 << "\n";
            std::cout << "File 2: " << line2 << "\n\n";
            differencesFound = true;
        }
        lineNumber++;
    }

    // Check if there are remaining lines in either file
    while (std::getline(file1, line1)) {
        std::cout << "Extra line in File 1 at line " << lineNumber << ": " << line1 << "\n\n";
        lineNumber++;
        differencesFound = true;
    }

    while (std::getline(file2, line2)) {
        std::cout << "Extra line in File 2 at line " << lineNumber << ": " << line2 << "\n\n";
        lineNumber++;
        differencesFound = true;
    }

    if (!differencesFound) {
        std::cout << "The files are identical." << std::endl;
    }

    file1.close();
    file2.close();
}

int main() {
    std::string file1Path = "user_output.txt";
    std::string file2Path = "test_output.txt";

    compareFiles(file1Path, file2Path);

    return 0;
}
