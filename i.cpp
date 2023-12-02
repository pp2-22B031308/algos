#include <iostream>
#include <string>
using namespace std;

class EmptyListException : public std::exception {
public:
    const char* what() const throw() {
        return "List is empty";
    }
};

struct Node{
    string val;
    Node* next;
    Node* prev;

    Node( string data ) {
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{
    public:
    int size;
    Node* head;
    Node* tail;

    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool is_empty(){
        if (head == nullptr)
            return true;
        else
            return false;
    }

    void push_back( string n ){
        size++;
        if (tail != nullptr) {
            tail->next = new Node( n );
            tail->next->prev = tail;
            tail = tail->next;
        }
        else
            head = tail = new Node( n );
    }

    void push_front( string n ){
        size++;
        if ( head != nullptr){
            head->prev = new Node( n );
            head->prev->next = head;
            head = head->prev;
        }
        else
            head = tail = new Node( n );
    }

//     int pop_back(){
//         if ( !is_empty() ){
//             int data = tail->val;
//             tail = tail->prev;
//             if (tail != nullptr){
//                 tail->next->prev = nullptr;
//                 Node *free = tail->next;
//                 tail->next = nullptr;
//                 delete free;
//             }
//             return data;
//     }
// }

//     int pop_front(){
//         if ( !is_empty() ){
//             int data = head->val;
//             head = head->next;
//             if (head != nullptr){
//                 head->prev->next = nullptr;
//                 Node *free = head->prev;
//                 head->prev = nullptr;
//                 delete free;
//             }
//             return data;
//         }
//     }
string pop_back() {
    if (!is_empty()) {
        size--;
        string data = tail->val;
        Node *free = tail;
        if (tail->prev != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = tail = nullptr;
        }
        delete free;
        return data; 
    } else {
        return "error";
    //     throw EmptyListException();
    }
}

string pop_front() {
    if (!is_empty()) {
        size--;
        string data = head->val;
        Node *free = head;
        if (head->next != nullptr) {
            head = head->next;
            head->prev = nullptr;
        } else {
            head = tail = nullptr;
        }
        delete free;
        return data; 
    } else {
        return "error";
        // throw EmptyListException();
    }
}
    void view(){
        Node* curr = head;
        while ( curr != nullptr){
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << '\n';
    }

    // int size(){
    //     return size;
    // }

    void insert( string data, int pos){
        if (pos > size - 1)
            throw -1;
        int ind = 0;
        Node* test = new Node( data );
        if (ind == pos){
            test->next = head;
            head->prev = test;
            head = test;
        }
        else if ( pos == size ){
            test->prev = tail;
            tail->next = test;
            tail = test;
        }
        else{ 
            Node* curr = head;
            while ( ind != pos ){
                ind++;
                curr = curr->next;
            }
            test->prev = curr->prev;
            test->next = curr;
            curr->prev = test;
            test->prev->next = test;
        }


    }
    string front(){
        if (head != nullptr) {
            return head->val;
        }
        else {
            return "error";
        }
    }
    string back(){
        if (tail != nullptr) {
            return tail->val;
        }
        else{
            return "error";
        }
    }

    void clear(){
        head = tail = nullptr;
    }
    
};

int main() {
    string s;
    LinkedList mylist;
    while (s != "exit"){
        cin >> s;
        if ( s == "add_front"){
            cin >> s;
            mylist.push_front( s );
            cout << "ok" << endl;
        }
        if ( s == "add_back"){
            cin >> s;
            mylist.push_back( s );
            cout << "ok" << endl;
        }
        if ( s == "erase_front"){
            cout << mylist.pop_front() << endl;
        }
        if ( s == "erase_back"){
            cout << mylist.pop_back() << endl;
        }
        if ( s == "front"){
            cout << mylist.front() << endl;
        }
        if ( s == "back"){
            cout << mylist.back() << endl;
        }
        if ( s == "clear"){
            mylist.clear();
            cout << "ok" << endl;
        }
    }
    cout << "goodbye";
}