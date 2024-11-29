#include <iostream>

long long countTrailingZeros(long long n) {
    long long count = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << countTrailingZeros(n) << std::endl;
    return 0;
}
