#include <iostream> 
using namespace std; 
class Student { 
public: 
string name; 
int year; 
void display() { 
cout << "Name: " << name << ", Year: " << year << endl; 
} 

}; 
int main() { 
Student s1; 
s1.name = "Nash Patrick G Chiu"; 
s1.year = 2005; 
s1.display(); 
return 0; 
} 
