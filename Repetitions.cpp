#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> // Include this header for std::accumulate
#include <stdexcept> // Include this header for std::out_of_range

template<typename T>
std::vector<T> take_vector(size_t size, std::istream& in) {
    std::vector<T> vec;
    std::copy_n(std::istream_iterator<T>(in), size, std::back_inserter(vec));
    return vec;
}

template<typename T>
void print_vector(const std::vector<T>& vec, const std::string& delimiter = " ") {
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<T>(std::cout, delimiter.c_str()));
        std::cout << vec.back(); // Print last element without delimiter
    }
    std::cout << std::endl;
}

template<typename T>
T sum_vector_element(const std::vector<T>& vec, int start = 0, int end = -1) {
    // Set end to the size of the vector if not provided
    if (end == -1) {
        end = vec.size(); // Set end to the size of the vector
    }

    // Ensure that the start and end indices are within bounds
    if (start < 0 || end > vec.size() || start >= end) {
        throw std::out_of_range("Invalid start or end index");
    }

    // Use std::accumulate to sum the elements in the specified range
    return std::accumulate(vec.begin() + start, vec.begin() + end, T(0));
}

template<typename T>
T read_input() {
    T input;
    std::getline(std::cin, input); // Read the entire line of input
    return input; // Return the read input
}


int main() {
    std::string dna_sequence = read_input<std::string>(); // Read input string
    int max_length = 1; // To keep track of the maximum repetition length
    int current_length = 1; // To count the current repetition length

    // Iterate through the string starting from the second character
    for (size_t i = 1; i < dna_sequence.size(); i++) {
        // If the current character is the same as the previous one
        if (dna_sequence[i] == dna_sequence[i - 1]) {
            current_length++; // Increment the current length
        } else {
            // Update max_length if current_length is greater
            max_length = std::max(max_length, current_length);
            current_length = 1; // Reset current length for the new character
        }
    }
    
    // Final check to update max_length for the last repetition
    max_length = std::max(max_length, current_length);
    
    std::cout << max_length << std::endl; // Output the result

    return 0; // Return 0 for successful execution
}