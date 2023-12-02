#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> countMap;
    vector<int> numbers;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        countMap[num]++;
        numbers.push_back(num);
    }

    int maxCount = 0;
    for (const auto& pair : countMap) {
        maxCount = max(maxCount, pair.second);
    }

    vector<int> modes;
    for (const auto& pair : countMap) {
        if (pair.second == maxCount) {
            modes.push_back(pair.first);
        }
    }

    sort(modes.rbegin(), modes.rend());

    for (int mode : modes) {
        cout << mode << " ";
    }

    return 0;
}
