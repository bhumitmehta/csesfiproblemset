#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void deleteExeAndNoExtensionFiles(const fs::path& folderPath) {
    if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
        std::cerr << "Error: The specified path is not a directory or does not exist." << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (fs::is_regular_file(entry)) {
            fs::path filePath = entry.path();
            std::string extension = filePath.extension().string();

            // Check for .exe files or files without extensions
            if (extension == ".exe" || extension.empty()) {
                try {
                    fs::remove(filePath);
                    std::cout << "Deleted: " << filePath << std::endl;
                } catch (const fs::filesystem_error& e) {
                    std::cerr << "Error deleting file: " << filePath << " - " << e.what() << std::endl;
                }
            }
        }
    }
}

int main() {
    // Specify the folder path
    std::string folderPath = "../coding";
   

    deleteExeAndNoExtensionFiles(folderPath);

    return 0;
}
