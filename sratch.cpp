#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    // Initialize Queue with 10 elements
    queue<int> q;
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }
    
    // Initialize Stack with 10 elements
    stack<int> s;
    for (int i = 1; i <= 10; i++) {
        s.push(i);
    }
    
    // Pop 3 elements from queue to leave 7
    for (int i = 0; i < 3; i++) {
        q.pop();
    }
    
    // Pop 3 elements from stack to leave 7
    for (int i = 0; i < 3; i++) {
        s.pop();
    }
    
    // Output Queue (7 elements)
    cout << "Queue (7 elements): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    // Output Stack (7 elements)
    cout << "Stack (7 elements): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}