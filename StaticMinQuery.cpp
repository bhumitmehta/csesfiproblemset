#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using lli = long long;

constexpr lli INF = std::numeric_limits<lli>::max();

// Node structure
struct node {
    lli data;
    node* left;
    node* right;
};

// Segment Tree class
template <typename T = lli>
class SegmentTree {
    node* root;
    int size;

public:
    SegmentTree(const std::vector<T>& arr) {
        size = arr.size();
        root = construct(arr, 0, size - 1);
    }

    ~SegmentTree() { clear(root); }

private:
    node* construct(const std::vector<T>& arr, int left, int right) {
        if (left == right) {
            node* n = new node();
            n->data = arr[left];
            n->left = nullptr;
            n->right = nullptr;
            return n;
        } else {
            int mid = (left + right) / 2;
            node* n = new node();
            n->left = construct(arr, left, mid);
            n->right = construct(arr, mid + 1, right);
            n->data = std::min(n->left->data, n->right->data);
            return n;
        }
    }

    void clear(node* root) {
        if (root) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }

    T solveQuery(int l, int r, int mi, int ma, node* root) {
        if (l > ma || r < mi) {
            // No overlap
            return INF;
        }
        if (l <= mi && r >= ma) {
            // Total overlap
            return root->data;
        }
        // Partial overlap
        int mid = (mi + ma) / 2;
        T leftRes = solveQuery(l, r, mi, mid, root->left);
        T rightRes = solveQuery(l, r, mid + 1, ma, root->right);
        return std::min(leftRes, rightRes);
    }

public:
    T query(int left, int right) {
        if (left < 0 || right >= size || left > right) {
            throw std::out_of_range("Invalid query range");
        }
        return solveQuery(left, right, 0, size - 1, root);
    }
};

// Input functions
int input() {
    int x;
    std::cin >> x;
    return x;
}

template <typename T>
std::vector<T> take_vector(int n) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    return v;
}

int main() {
    int n = input();
    int q = input();
    std::vector<lli> arr = take_vector<lli>(n);
    SegmentTree<lli> s(arr);

    while (q-- > 0) {
        int l = input();
        int r = input();
        try {
            std::cout << s.query(l - 1, r - 1) << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
