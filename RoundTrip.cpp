#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int node, int parent, vector<vector<int>>& a, vector<int>& path, set<int>& visited, bool& found) {
    if (found) return; // Stop further recursion if cycle is already found

    visited.insert(node);
    path.push_back(node);

    for (int neighbor : a[node]) {
        if (neighbor == parent) continue; // Ignore the immediate parent

        if (visited.find(neighbor) != visited.end()) {
            // Cycle detected
            cout << path.size() + 1 << endl;  // Cycle length
            for (int k : path) cout << k + 1 << " ";
            cout<<path[0]+1<<" "; // Convert back to 1-based index
            cout << endl;
            found = true;
            return;
        } else {
            dfs(neighbor, node, a, path, visited, found);
            if (found) return; // Stop further recursion if cycle is found
        }
    }

    path.pop_back(); // Backtrack
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> a(n);
    for (int i = 0; i < q; i++) {
        int s, k;
        cin >> s >> k;
        s--; k--; // Convert to 0-based indexing
        a[s].push_back(k);
        a[k].push_back(s);
    }

    bool found = false;
    set<int> visited;
    vector<int> path;

    for (int i = 0; i < n; i++) {
        if (!visited.count(i)) {
            dfs(i, -1, a, path, visited, found);
            if (found) break;
        }else{
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }  
    }

    return 0;
}
