#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Calculate the total sum of the series 1 + 2 + ... + n
    long long total_sum = n * (n + 1) / 2;

    // Check if the sum is even
    if (total_sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        long long target_sum = total_sum / 2;
        vector<int> set1, set2;
        long long current_sum = 0;

        // Greedily place numbers from n to 1 into set1 until target_sum is reached
        for (int i = n; i >= 1; --i) {
            if (current_sum + i <= target_sum) {
                set1.push_back(i);
                current_sum += i;
            } else {
                set2.push_back(i);
            }
        }

        // Print set1
        cout << set1.size() << endl;
        for (int num : set1) {
            cout << num << " ";
        }
        cout << endl;

        // Print set2
        cout << set2.size() << endl;
        for (int num : set2) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
