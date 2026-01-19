This is your complete, all-in-one DSA exam study guide. I have consolidated all the theory from **Modules 1 through 4** and combined them with **fully working, copy-paste ready C++ code**.

I have removed the complex LaTeX formatting from the prose as requested, making it easy to read and copy into your notes or compiler.

---

## M1: Introduction to DSA in C++

**Data Structures** are ways to organize data (like Arrays or Stacks), and **Algorithms** are the steps to solve a problem (like Sorting).

### Key Concepts

* **Time Complexity:** How fast the code runs as input size () grows.
* : Constant (Fastest)
* : Linear
* : Log-linear (Efficient Sorting)
* : Quadratic (Slow Sorting)


* **Memory Allocation:**
* **Static:** Done at compile time (e.g., `int arr[10];`).
* **Dynamic:** Done at runtime using `new` (e.g., `int* p = new int[n];`).



---

## M2: Functions, Arrays, and Overloading

### 1. Arrays

Arrays store elements of the same type in a single block of memory.

* **Access:** Very fast using an index.
* **Insertion:** Slow because you have to shift other elements.

### 2. Function Overloading

This allows you to have multiple functions with the **same name** but **different parameters**. The compiler picks the right one based on what you pass to it.

---

## M3: Stack, Queue, and STL

* **Stack:** LIFO (Last In, First Out). Think of a stack of books.
* **Queue:** FIFO (First In, First Out). Think of a line at a store.
* **Standard Template Library (STL):** A built-in C++ library that provides ready-to-use versions of these structures (e.g., `std::stack`, `std::vector`).

---

## M4: Sorting Algorithms

1. **Merge Sort:** Divides the array into two halves, sorts them, and merges them. It is very reliable.
2. **Quick Sort:** Picks a "pivot" element and moves smaller items to the left and larger to the right. Usually the fastest.
3. **Heap Sort:** Converts the array into a "Heap" (a tree-like structure) to find the largest elements.

---

## COMPLETE WORKING CODE

You can copy and paste this entire block into a single file (e.g., `main.cpp`) and run it. It demonstrates every module.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- M2: FUNCTION OVERLOADING ---
void printData(int i) {
    cout << "Overloaded Function (Int): " << i << endl;
}
void printData(string s) {
    cout << "Overloaded Function (String): " << s << endl;
}

// --- M3: MANUAL STACK IMPLEMENTATION ---
class SimpleStack {
private:
    int arr[5];
    int top;
public:
    SimpleStack() { top = -1; }
    void push(int val) {
        if (top < 4) arr[++top] = val;
    }
    int pop() {
        if (top >= 0) return arr[top--];
        return -1;
    }
};

// --- M4: SORTING ALGORITHMS ---

// Quick Sort Partition logic
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort Merge logic
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    cout << "--- M2: Function Overloading Test ---" << endl;
    printData(10);
    printData("Hello DSA");

    cout << "\n--- M3: Stack Test ---" << endl;
    SimpleStack s;
    s.push(50);
    s.push(100);
    cout << "Popped from stack: " << s.pop() << endl; // Should be 100

    cout << "\n--- M4: Sorting Test ---" << endl;
    int myArr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(myArr) / sizeof(myArr[0]);

    quickSort(myArr, 0, n - 1);

    cout << "Array Sorted using QuickSort: ";
    for (int i = 0; i < n; i++) cout << myArr[i] << " ";
    cout << endl;

    return 0;
}

```

---

### Final Summary Table for Exam Review

| Algorithm | Best Case | Worst Case | Memory (Extra Space) | Advantage |
| --- | --- | --- | --- | --- |
| **Quick Sort** | O(n log n) | O(n^2) | O(log n) | Very fast on average |
| **Merge Sort** | O(n log n) | O(n log n) | O(n) | Stable and predictable |
| **Heap Sort** | O(n log n) | O(n log n) | O(1) | Extremely memory efficient |

**Would you like me to explain the "Heapify" process specifically, or move on to a practice quiz?**

This is a comprehensive **Glossary of Terms** for your exam, organized by your specific modules. Each term is paired with a clear, concise definition tailored for a DSA student.

---

## M1: DSA in C++ Foundations

* **Data Structure:** A specialized format for organizing, storing, and managing data for efficient access and modification.
* **Algorithm:** A step-by-step procedure or set of rules to be followed in calculations or other problem-solving operations.
* **Time Complexity:** An estimation of the amount of time an algorithm takes to run as a function of the length of the input.
* **Space Complexity:** The amount of memory space required by an algorithm to complete its execution.
* **Big O Notation:** A mathematical notation used to describe the upper bound (worst-case scenario) of an algorithm's complexity.
* **Static Memory Allocation:** Memory that is allocated at compile time and remains fixed throughout the program execution.
* **Dynamic Memory Allocation:** Memory allocated during the execution of a program (runtime) using pointers and the `new` operator.
* **Pointer:** A variable that stores the memory address of another variable.

---

## M2: Functions, Arrays, and Overloading

* **Array:** A collection of elements of the same data type stored in contiguous memory locations.
* **Index:** A numerical value representing the position of an element in an array (starts at 0 in C++).
* **Function:** A self-contained block of code that performs a specific task and can be reused.
* **Pass by Value:** A method where a copy of the actual parameter's value is made in the formal parameter of the function.
* **Pass by Reference:** A method where the function accesses the actual variable's memory address, meaning changes inside the function affect the original variable.
* **Function Overloading:** A type of polymorphism that allows multiple functions to have the same name if their parameter lists (signatures) are different.
* **Signature:** The combination of a function's name and its parameter types.

---

## M3: Stack, Queue, and STL

* **Stack:** A linear data structure that follows the **LIFO** (Last-In, First-Out) principle.
* **Queue:** A linear data structure that follows the **FIFO** (First-In, First-Out) principle.
* **Push:** The operation used to insert an element into a stack.
* **Pop:** The operation used to remove the top element from a stack.
* **Enqueue:** The operation used to insert an element into the rear of a queue.
* **Dequeue:** The operation used to remove an element from the front of a queue.
* **Circular Queue:** A queue where the last position is connected back to the first position, forming a circle to optimize space.
* **Priority Queue:** A special type of queue where each element is associated with a priority, and elements with higher priority are served first.
* **STL (Standard Template Library):** A library of container classes, algorithms, and iterators provided in C++.
* **Vector:** A dynamic array provided by the STL that can resize itself automatically.

---

## M4: Sorting Algorithms

* **Sorting:** The process of arranging a collection of data into a specific order (ascending or descending).
* **Divide and Conquer:** An algorithmic paradigm that breaks a problem into smaller sub-problems, solves them, and combines the results.
* **Merge Sort:** A stable, divide-and-conquer sorting algorithm that splits an array in half and merges the sorted halves.
* **Quick Sort:** An efficient, divide-and-conquer algorithm that partitions an array around a chosen **Pivot** element.
* **Pivot:** An element chosen in Quick Sort to divide the array into elements smaller than it and elements larger than it.
* **Heap Sort:** A comparison-based sorting algorithm that uses a Binary Heap data structure to find the largest/smallest elements.
* **In-place Sort:** A sorting algorithm that requires only a constant amount  of additional memory space.
* **Stability (Sorting):** A property where the algorithm maintains the relative order of records with equal keys.
* **Recursion:** A process in which a function calls itself as a subroutine to solve smaller instances of the same problem.

---

### Comparison Chart for Sorting (Exam Cheat Sheet)

| Term | Merge Sort | Quick Sort | Heap Sort |
| --- | --- | --- | --- |
| **Logic** | Divide & Merge | Partitioning | Tree/Heap |
| **Worst Case** |  |  |  |
| **Stable?** | Yes | No | No |
| **In-place?** | No | Yes | Yes |

**Would you like me to create a "True or False" practice set using these terms to help you memorize them?**
