#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int k;
    cin >> k;

    int minDistance = abs(numbers[0] - k);
    int result = 0;

    for (int i = 1; i < n; ++i) {
        int distance = abs(numbers[i] - k);
        if (distance < minDistance) {
            minDistance = distance;
            result = i;
        }
    }

    cout << result;

    return 0;
}
