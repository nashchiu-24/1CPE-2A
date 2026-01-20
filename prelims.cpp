#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort 
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10] = {23,45,23,60,55,32,22,53,29,25};
    
    stack<int> s;
    queue<int> q;
    
   // task 1
    cout << "Array: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // task 2
    for (int i = 0; i < 10; i++) {
        s.push(arr[i]);
        q.push(arr[i]);
    }
    
    // Output Stack
    for (int i = 0; i < 3; i++) {
        s.pop();
    }
    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    // Output Queue
    for (int i = 0; i < 3; i++) {
        q.pop();
    }
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    

    // task 3 
    for (int i = 0; i < 10; i++) {
        s.push(arr[i]);
        q.push(arr[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        s.pop();
        q.pop();
    }
    
    int DataMerging[20];
    int index = 0;
    
    // Add stack elements to array
    while (!s.empty()) {
        DataMerging[index++] = s.top();
        s.pop();
    }
    
   
    while (!q.empty()) {
        DataMerging[index++] = q.front();
        q.pop();
    }
    
    cout << " DataMerging: ";
    for (int i = 0; i < index; i++) {
        cout << DataMerging[i] << " ";
    }
    cout << endl << endl;
    
    // task 4: chrono time
    vector<pair<string, long long>> sortTimes;
    
    // Bubble Sort
    int bubbleArr[20];
    copy(DataMerging, DataMerging + index, bubbleArr);
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(bubbleArr, index);
    auto end = chrono::high_resolution_clock::now();
    long long bubbleTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    
    cout << "Bubble Sort Result: ";
    for (int i = 0; i < index; i++) {
        cout << bubbleArr[i] << " ";
    }
    cout << "\nTime: " << bubbleTime << " us" << endl << endl;
    sortTimes.push_back({"Bubble Sort", bubbleTime});
    
    // Insertion Sort
    int insertionArr[20];
    copy(DataMerging, DataMerging + index, insertionArr);
    start = chrono::high_resolution_clock::now();
    insertionSort(insertionArr, index);
    end = chrono::high_resolution_clock::now();
    long long insertionTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    
    cout << "Insertion Sort Result: ";
    for (int i = 0; i < index; i++) {
        cout << insertionArr[i] << " ";
    }
    cout << "\nTime: " << insertionTime << " us" << endl << endl;
    sortTimes.push_back({"Insertion Sort", insertionTime});
    
    // Merge Sort
    int mergeArr[20];
    copy(DataMerging, DataMerging + index, mergeArr);
    start = chrono::high_resolution_clock::now();
    mergeSort(mergeArr, 0, index - 1);
    end = chrono::high_resolution_clock::now();
    long long mergeTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    
    cout << "Merge Sort Result: ";
    for (int i = 0; i < index; i++) {
        cout << mergeArr[i] << " ";
    }
    cout << "\nTime: " << mergeTime << " us" << endl << endl;
    sortTimes.push_back({"Merge Sort", mergeTime});
    
    // Quick Sort
    int quickArr[20];
    copy(DataMerging, DataMerging + index, quickArr);
    start = chrono::high_resolution_clock::now();
    quickSort(quickArr, 0, index - 1);
    end = chrono::high_resolution_clock::now();
    long long quickTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    
    cout << "Quick Sort Result: ";
    for (int i = 0; i < index; i++) {
        cout << quickArr[i] << " ";
    }
    cout << "\nTime: " << quickTime << " us" << endl << endl;
    sortTimes.push_back({"Quick Sort", quickTime});
    
    // Sort by time (fastest to slowest)
    sort(sortTimes.begin(), sortTimes.end(), [](const pair<string, long long>& a, const pair<string, long long>& b) {
        return a.second < b.second;
    });
    
    cout << "=== Sorting Performance Ranking (Fastest to Slowest) ===" << endl;
    for (int i = 0; i < sortTimes.size(); i++) {
        cout << i + 1 << ". " << sortTimes[i].first << ": " << sortTimes[i].second << " us" << endl;
    }
    cout << endl;    
    return 0;
}