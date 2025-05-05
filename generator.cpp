#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
string randString(int len) { 
    string s;
    for (int i = 0; i < len; i++) 
        s += (char)randInt('a', 'z');
    return s;
}

vector<pair<int, int>> generateTree(int N) {
    vector<pair<int, int>> edges;
    vector<int> nodes(N);
    iota(nodes.begin(), nodes.end(), 1);
    shuffle(nodes.begin(), nodes.end(), rng);

    for (int i = 1; i < N; i++) {
        int u = nodes[i];
        int v = nodes[randInt(0, i - 1)];
        edges.emplace_back(u, v);
    }
    return edges;
}

vector<pair<int, int>> generateGraph(int N, int M) {
    set<pair<int, int>> edges;
    while ((int)edges.size() < M) {
        int u = randInt(1, N), v = randInt(1, N);
        if (u != v) edges.insert({min(u, v), max(u, v)});
    }
    return vector<pair<int, int>>(edges.begin(), edges.end());
}

void generateTestCases() {
    freopen("C:/Users/aksha/Onedrive/Coding/Codeforces/inp/input.txt", "w", stdout); // Redirect output to input.txt

    int T = randInt(3, 10); // Number of test cases
    cout << T << "\n";

    while (T--) {
        int type = 1;

        if (type == 1) { // Array Test Case
            int n = 100000;
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << randInt(1, 1e9) << " ";
            }
            cout << "\n";

        } else if (type == 2) { // String Test Case
            int len = randInt(1, 10);
            cout << len << "\n" << randString(len) << "\n";

        } else if (type == 3) { // Tree Test Case
            int n = randInt(2, 10);
            cout << n << "\n";
            vector<pair<int, int>> tree = generateTree(n);
            for (auto it : tree) {
                cout << it.first << " " << it.second << "\n";
            }

        } else if (type == 4) { // Graph Test Case
            int n = randInt(2, 10), m = randInt(n - 1, min(n * (n - 1) / 2, 10));
            cout << n << " " << m << "\n";
            vector<pair<int, int>> graph = generateGraph(n, m);
            for (auto it : graph) {
                cout << it.first << " " << it.second << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    generateTestCases();
    return 0;
}
