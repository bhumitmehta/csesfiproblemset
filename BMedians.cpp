#include <iostream>
#include <vector>

using namespace std;

// Function to print the left boundaries of subarrays
void print_left_boundaries(const vector<int>& boundaries) {
    cout << boundaries.size() << endl;
    for (int boundary : boundaries) {
        cout << boundary << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // Ensure the array is [1, 2, ..., n], and it's already sorted
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }

        // Check if a valid partition is possible
        if (k > n || k < 1) {
            cout << -1 << endl;
            continue;
        }

        // Split the array into m subarrays of odd length such that k is the median of medians
        vector<int> boundaries;
        int m = (n / 2) + 1; // Initial choice to place k as the median
        int step = 2; // To keep subarrays of odd length (1, 3, 5, ...)

        if (a[m - 1] == k) { // Check if k is at the middle of chosen medians
            for (int i = 1; i <= n; i += step) {
                boundaries.push_back(i);
            }
            print_left_boundaries(boundaries);
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
