#include <iostream>
#include <vector>
#include <algorithm>

using lli = long long int;

int binarySearch(int start, int end, const std::vector<std::vector<int>>& arr, int t) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid][0] < t) {
            start = mid + 1;
        } else if (arr[mid][0] > t) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    lli t;
    std::cin >> t;
    std::vector<std::vector<int>> arr(n, std::vector<int>(2));
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i][0];
        arr[i][1] = i + 1;
    }

    // Sort the array based on the first element of the inner vectors
    std::sort(arr.begin(), arr.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int remaining = t - arr[i][0] - arr[j][0];
            int idx = binarySearch(j + 1, n - 1, arr, remaining);
            if (idx != -1) {
                std::cout << arr[i][1] << " " << arr[j][1] << " " << arr[idx][1] << std::endl;
                return 0;
            }
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}