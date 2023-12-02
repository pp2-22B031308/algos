#include <iostream>

// Definition for a singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int findMaxSum(ListNode* head) {
        if (!head) {
            return 0;
        }

        int maxEndingHere = head->val;
        int maxSoFar = head->val;
        ListNode* current = head->next;

        while (current) {
            maxEndingHere = std::max(current->val, maxEndingHere + current->val);
            maxSoFar = std::max(maxSoFar, maxEndingHere);
            current = current->next;
        }

        return maxSoFar;
    }
};

int main() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    int val;
    std::cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    for (int i = 1; i < n; ++i) {
        std::cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    Solution solution;
    int result = solution.findMaxSum(head);
    std::cout << result << std::endl;

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
