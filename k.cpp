#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        unordered_map<char, int> frequency;  
        queue<char> charQueue;  

        for (int i = 0; i < N; ++i) {
            char x;
            cin >> x;

            
            frequency[x]++;

            charQueue.push(x);

            while (!charQueue.empty() && frequency[charQueue.front()] > 1) {
                charQueue.pop();
            }

            if (charQueue.empty()) {
                cout << "-1 ";
            } else {
                cout << charQueue.front() << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
