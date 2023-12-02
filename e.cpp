#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v, v2;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size(); i++) {
        if (i == 0 || v[i] != v[i - 1]) {
            v2.push_back(v[i]);
        }
    }

    cout << "All in all: " << v2.size() << endl;
    cout << "Students:" << endl;

    reverse(v2.begin(), v2.end());

    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << endl;
    }

    return 0;
}
