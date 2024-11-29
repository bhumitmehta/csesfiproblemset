#include <windows.h>
#include <iostream>

using namespace std;

#define OCR_NORMAL 32512 // ID for the normal arrow cursor

int main() {
    // Load a custom cursor from a file using a wide string literal
    HCURSOR hCursor = LoadCursorFromFileW(L"C:/Users/20092/OneDrive/Documents/Bhumit/coding/cursor.cur");

    if (!hCursor) {
        DWORD error = GetLastError(); // Get the last error code
        std::cerr << "Failed to load cursor. Make sure the file path is correct. Error code: " << error << std::endl;
        return 1;
    } else {
        std::cout << "Cursor loaded successfully." << std::endl;
    }

    // Set the system cursor for the standard arrow cursor
    if (!SetSystemCursor(hCursor, OCR_NORMAL)) {
        DWORD error = GetLastError(); // Get the last error code
        std::cerr << "Failed to set the system cursor. Error code: " << error << std::endl;
        return 1;
    }

    std::cout << "Cursor style changed successfully!" << std::endl;

    // Keep the console open
    std::cin.get();

    return 0;
}
