Example 1 (Stack)
Code:
#include <iostream>
#include <stack>
using namespace std;
int main() {
stack<string> actions;
actions.push(`Open File`);
actions.push(`Edit File`);
actions.push(`Save File`);
cout << `Last action: ` << actions.top() << endl;
actions.pop();
cout << `After undo, current action: ` << actions.top() << endl;
return 0;
}
Output:
Observation:
Example 2 (Queue)
Code:
University of the East
College of Engineering
Prepared for:
Engr. Marjon Umbay
Faculty, CpE Department
Subject code: Section: Date:
Prepared by: [lastname, firstname] Activity No.:
#include <iostream>
#include <queue>
using namespace std;
int main() {
queue<string> printQueue;
printQueue.push(`Document_A.pdf`);
printQueue.push(`Report_B.docx`);
printQueue.push(`Image_C.png`);
cout << `Printing: ` << printQueue.front() << endl;
printQueue.pop();
cout << `Next in line: ` << printQueue.front() << endl;
return 0;
}
Output:
Observation:
Example 3 (Boundary Access)
Code:
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
stack<char> letterStack;
queue<string> nameQueue;
letterStack.push('A');
letterStack.push('B');
letterStack.push('C');
nameQueue.push(`Alice`);
nameQueue.push(`Bob`);
nameQueue.push(`Charlie`);
cout << `Stack Top Letter: ` << letterStack.top() << endl;
cout << `Queue Front Name: ` << nameQueue.front() << endl;
cout << `Queue Back Name: ` << nameQueue.back() << endl;
return 0;
}
Output:
Observation:
Example 4 (Pseudo-Traversal)
Code:
#include <iostream>
#include <stack>
using namespace std;
void showHistory(stack<string> history) {
while (!history.empty()) {
cout << history.top() << endl;
history.pop();
}
}
int main() {
stack<string> commandHistory;
commandHistory.push(`Login`);
commandHistory.push(`Upload File`);
commandHistory.push(`Logout`);
cout << `Command History (Latest First):\n`;
showHistory(commandHistory);
return 0;
}
Output:
Observation:
Example 5 (Max-Heap)
Code:
#include <iostream>
#include <queue>
using namespace std;
int main() {
priority_queue<int> grades;
grades.push(85);
grades.push(92);
grades.push(78);
cout << `Highest Grade: ` << grades.top() << endl;
return 0;
}
Output:
Observation:
Example 6 (Min-Heap)
Code:
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
priority_queue<int, vector<int>, greater<int>> deadlines;
deadlines.push(5); // days
deadlines.push(2);
deadlines.push(10);
cout << `Most Urgent Deadline (days): ` << deadlines.top() << endl;
return 0;
}
Output:
Observation:
Example 7 (Safety Checks)
Code:
#include <iostream>
#include <queue>
using namespace std;
int main() {
queue<string> students;
cout << `Queue empty? ` << students.empty() << endl;
students.push(`Juan`);
students.push(`Maria`);
cout << `Students waiting: ` << students.size() << endl;
if (!students.empty()) {
cout << `Serving: ` << students.front() << endl;
students.pop();
}
cout << `Remaining students: ` << students.size() << endl;
return 0;
}
Output:
Observation:
Example 8 (CPU Scheduler)
Code:
#include <iostream>
#include <queue>
using namespace std;
int main() {
priority_queue<pair<int, string>> cpuScheduler;
cpuScheduler.push({1, `Background Sync`});
cpuScheduler.push({10, `System Update`});
cpuScheduler.push({5, `User Application`});
while (!cpuScheduler.empty()) {
cout << `Executing: ` << cpuScheduler.top().second << endl;
cpuScheduler.pop();
}
return 0;
}
Output:
Observation:



Example 9 (Swapping Stacks)
Code:
#include <iostream>
#include <stack>
using namespace std;
int main() {
stack<string> courseA, courseB;
courseA.push(`DSA`);
courseA.push(`OOP`);
courseB.push(`DBMS`);
courseB.push(`OS`);
courseA.swap(courseB);
cout << `Course A Top: ` << courseA.top() << endl;
cout << `Course B Top: ` << courseB.top() << endl;
return 0;
}
Output:
Observation:


Example 10 (Time Complexity)
Code:
#include <iostream>
#include <queue>
#include <chrono>
using namespace std;
int main() {
priority_queue<string> pq;
auto start = chrono::high_resolution_clock::now();
for (int i = 0; i < 50000; i++) {
pq.push("Task_" + to_string(i));
}
auto end = chrono::high_resolution_clock::now();
cout << "Insertion time (ms): "
<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
<< endl;
return 0;
}
Output:
Observation:
