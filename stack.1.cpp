#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> actions;
    string arr[] = {"Open File", "Edit File", "Save File"};
    
    for (int i = 0; i < 3; i++) {
        actions.push(arr[i]);
    }

    cout << "Last action: " << actions.top() << endl;
                        actions.pop();
                            cout << "After undo, current action: " << actions.top() << endl;

                                return 0;
                                }
                                
