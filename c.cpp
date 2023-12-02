#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        
        ListNode* newNode = new ListNode(num);

        
        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            
            current->next = newNode;
            current = newNode;
        }
    }

    
    bool deleteNode = false;

    current = head;
    while (current != nullptr) {
        if (deleteNode) {
            
            ListNode* temp = current;
            current = current->next;
            delete temp;
        } else {
            
            cout << current->val << " ";
            current = current->next;
        }

        
        deleteNode = !deleteNode;
    }

    
    current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
