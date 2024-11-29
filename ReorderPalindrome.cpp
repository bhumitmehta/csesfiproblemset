#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> // Include this header for std::accumulate
#include <stdexcept> // Include this header for std::out_of_range
#include <cmath>

using str = std::string;
using lli = long long int;
#define RESULT_MODULO = 1000000007;


template<typename T=int>
std::vector<T> take_vector(size_t size, std::istream& in = std::cin) {
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
template <typename T=int>
T input(std::istream& in = std::cin) {
    T value;
    in >> value;
    return value;
}


template <typename T=int>
void print(T val,const std::string& delimiter = "\n") {
    std::cout<< val << delimiter;
   
}

template <typename T=int>
T max(T a, T b) {
    return (a > b) ? a : b; // Return the greater of the two values
}
template <typename T=int>
T min(T a, T b) {
    return (a < b) ? a : b; // Return the greater of the two values
}
template <typename T=int>
bool isOdd(T val){
    return val%2==0 ? false : true;
}

template <typename T = int >
T mod_exp(T base,T exp,T mod){
    T result= 1;
    while(exp >= 1){
        if(exp%2==1){
            result =(result*base)%mod;         
        }
        base = (base*base)%mod;
        exp /=2;
    }
    return result;
}


int main() {
   str s = input<str>();
    std::vector<int> c(26, 0);

    // Count the frequency of each character
    for (char ch : s) {
        c[ch - 'A']++;
    }

    int oddCount = 0;
    int oddIndex = -1;

    // Check for characters with odd frequencies
    for (int i = 0; i < 26; i++) {
        if (c[i] % 2 != 0) {
            oddCount++;
            oddIndex = i;
        }
    }

    if (oddCount > 1) {
        print("NO SOLUTION");
        return 0;
    }

    // Construct the palindrome
   str result(s.size(), ' ');
    int left = 0;
    int right = s.size() - 1;

    for (int i = 0; i < 26; i++) {
        while (c[i] > 1) {
            result[left++] = (char)(i + 'A');
            result[right--] = (char)(i + 'A');
            c[i] -= 2;
        }
    }

    // Place the middle character if needed
    if (oddIndex != -1) {
        result[s.size() / 2] = (char)(oddIndex + 'A');
    }

    print(result);
    return 0;
}