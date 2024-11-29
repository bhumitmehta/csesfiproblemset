#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> // Include this header for std::accumulate
#include <stdexcept> // Include this header for std::out_of_range
#include <cmath>


using lli = long long int;


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
bool isOdd(T val){
    return val%2==0 ? false : true;
}


void chess(int i){
     if(i<=1){
        print(0);
        return;
     }if (i==2){
        print(6);
        return;
     }if (i==3){
        print(28);
        return;
     }if (i==4){
        print(96);
        return;
     }
     else {
        lli total = i*i;
        lli comb = total*(total-1);
        lli tesa =max((i-4)*4,0), tc=(i-4)*(i-4);

        print((comb - 48 - tesa*4 - tc*8 -tesa*6)/2 );
     }

}

int main(){
    int n = input();
    for(int i=1;i<=n;i++){
        chess(i);
    }
    return 0;
}