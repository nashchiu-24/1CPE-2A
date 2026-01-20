The sort() function is used to sort elements in a container or array. It provides a simple and efficient way to sort data in C++.

Works on random-access iterators (arrays, vectors, deques).
Default sort is ascending order.



#include <iostream>
using namespace std;
​
int main()
{
    vector<int> v = {5, 3, 2, 1, 4};
​
    // Sort vector (by default in ascending order)
    sort(v.begin(), v.end());
​
    for (int i : v)
        cout << i << " ";
    return 0;
}

Output
1 2 3 4 5 
Syntax of sort()
The std::sort() function is defined inside the <algorithm> header file.


sort(first, last);
Parameters:

first: Iterator to the beginning of the range to be sorted.
last: Iterator to the element just after the end of the range.
Variations and Usage of sort() in C++ STL
Sort the entire range (default ascending order)



#include <algorithm>
#include <iostream>
using namespace std;
​
int main()
{
    int arr[5] = {5, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
​
    // Sort array (by default in ascending order)
    sort(arr, arr + n);
​
    for (int i : arr)
        cout << i << " ";
    return 0;
}

Output
1 2 3 4 5 
Sort a specific range



#include <algorithm>
#include <iostream>
using namespace std;
​
int main()
{
    int arr[] = {10, 5, 8, 1, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
​
    // Sort only the elements from index 1 to 4 (i.e., 5, 8, 1, 7)
    sort(arr + 1, arr + 5);
​
    // Print the array after sorting the range
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
​
    return 0;
}

Output
10 1 5 7 8 3 
Sort Array in Descending Order



#include <algorithm>
#include <iostream>
using namespace std;
​
int main()
{
    int arr[5] = {5, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
​
    // Sort array in descending order
    sort(arr, arr + n, greater<int>());
​
    for (int i : arr)
        cout << i << " ";
​
    return 0;
}

Output
5 4 3 2 1 
Sort Vector of User Defined Type



#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
​
struct Point
{
    int x;
    int y;
};
​
int main()
{
    vector<Point> points = {{3, 5}, {1, 2}, {4, 1}};
​
    // Sort points by x value (ascending)
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) { return a.x < b.x; });
​
    // Print sorted points
    for (auto p : points)
        cout << "(" << p.x << "," << p.y << ") ";
​
    return 0;
}
Try it on GfG Practice
redirect icon

Output
(1,2) (3,5) (4,1) 
Working of sort() Function
The sort() function is implemented using the Intro Sort Algorithm. It is the combination of three standard sorting algorithms: insertion sort, quick sort and heap sort. It automatically chooses the best algorithm that fits the given case. Refer to this article to know more - Internal Working of STL sort() Function.

As it uses the above sorting algorithms, its average time complexity turns out to be O(n log n).

heap sort

Heap Sort is a comparison-based sorting algorithm based on the Binary Heap data structure.

It is an optimized version of selection sort.
The algorithm repeatedly finds the maximum (or minimum) element and swaps it with the last (or first) element.
Using a binary heap allows efficient access to the max (or min) element in O(log n) time instead of O(n).
The process is repeated for the remaining elements until the array is sorted.
Overall, Heap Sort achieves a time complexity of O(n log n).
Heap Sort Algorithm :
First convert the array into a max heap using heapify, Please note that this happens in-place. The array elements are re-arranged to follow heap properties. Then one by one delete the root node of the Max-heap and replace it with the last node and heapify. Repeat this process while size of heap is greater than 1.

Detailed Working of Heap Sort
Step 1: Treat the Array as a Complete Binary Tree
We first need to visualize the array as a complete binary tree. For an array of size n, the root is at index 0, the left child of an element at index i is at 2i + 1, and the right child is at 2i + 2.

Visualize-the-array-as-a-complete-binary-tree
Step 2: Build a Max Heap
Heapify-Binary-Tree-1.webpHeapify-Binary-Tree-1.webp
Step 3: Sort the array by placing largest element at end of unsorted array.
Remove-from-Max-Heap-1.webpRemove-from-Max-Heap-1.webp
In the illustration above, we have shown some steps to sort the array. We need to keep repeating these steps until there’s only one element left in the heap.

Try it on GfG Practice
redirect icon



#include <iostream>
#include<vector>
using namespace std;
​
// To heapify a subtree rooted with node i
void heapify(vector<int>& arr, int n, int i){
​
    // Initialize largest as root
    int largest = i;
​
    // left index = 2*i + 1
    int l = 2 * i + 1;
​
    // right index = 2*i + 2
    int r = 2 * i + 2;
​
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
​
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
​
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
​
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
​
// Main function to do heap sort
void heapSort(vector<int>& arr){
    int n = arr.size();
​
    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
​
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
​
        // Move current root to end
        swap(arr[0], arr[i]);
​
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
​
int main(){
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };
​
    heapSort(arr);
​
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
}

Output
Sorted array is 
2 3 4 5 8 9 10 
Time Complexity: O(n log n)
Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.

Important points about Heap Sort
An in-place algorithm.
Its typical implementation is not stable but can be made stable (See this)
Typically 2-3 times slower than well-implemented QuickSort. The reason for slowness is a lack of locality of reference.
Advantages of Heap Sort
Efficient Time Complexity: Heap Sort has a guaranteed time complexity of O(n log n) in all cases, making it suitable for large datasets. The log n factor comes from the height of the binary heap, ensuring consistent performance.
Minimal Memory Usage: Heap Sort can work in-place with minimal extra memory. Using an iterative heapify() avoids additional stack space, so apart from storing the array itself, no extra memory is required.
Simplicity: Heap Sort is relatively easy to understand and implement compared to other efficient sorting algorithms, as it relies on the straightforward binary heap structure without advanced concepts like recursion (if iterative heapify is used).
Disadvantages of Heap Sort
Costly: Heap sort is costly as the constants are higher compared to merge sort even if the time complexity is O(n log n) for both.
Unstable: Heap sort is unstable. It might rearrange the relative order.
Inefficient: Heap Sort is not very efficient because of the high constants in the time complexity.

quick sort

QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array. .

There are mainly three steps in the algorithm:

Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).
Partition the Array: Re arrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right.
Recursively Call: Recursively apply the same process to the two partitioned sub-arrays.
Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.
Heap-Sort-Recursive-Illustration
Choice of Pivot
There are many different choices for picking pivots.

Always pick the first (or last) element as a pivot. The below implementation picks the last element as pivot. The problem with this approach is it ends up in the worst case when array is already sorted.
Pick a random element as a pivot. This is a preferred approach because it does not have a pattern for which the worst case happens.
Pick the median element is pivot. This is an ideal approach in terms of time complexity as we can find median in linear time and the partition function will always divide the input array into two halves. But it takes more time on average as median finding has high constants.
Partition Algorithm
The key process in quickSort is a partition(). There are three common algorithms to partition. All these algorithms have O(n) time complexity.

Naive Partition: Here we create copy of the array. First put all smaller elements and then all greater. Finally we copy the temporary array back to original array. This requires O(n) extra space.
Lomuto Partition: We have used this partition in this article. This is a simple algorithm, we keep track of index of smaller elements and keep swapping. We have used it here in this article because of its simplicity.
Hoare's Partition: This is the fastest of all. Here we traverse array from both sides and keep swapping greater element on left with smaller on right while the array is not partitioned. Please refer Hoare’s vs Lomuto for details.
Working of Lomuto Partition Algorithm with Illustration
 The logic is simple, we start from the leftmost element and keep track of the index of smaller (or equal) elements as i . While traversing, if we find a smaller element, we swap the current element with arr[i]. Otherwise, we ignore the current element. 

Try it on GfG Practice
redirect icon
Let us understand the working of partition algorithm with the help of the following example:

quick-sort-1.webpquick-sort-1.webp
Illustration of QuickSort Algorithm
In the previous step, we looked at how the partitioning process rearranges the array based on the chosen pivot. Next, we apply the same method recursively to the smaller sub-arrays on the left and right of the pivot. Each time, we select new pivots and partition the arrays again. This process continues until only one element is left, which is always sorted. Once every element is in its correct position, the entire array is sorted.

Below image illustrates, how the recursive method calls for the smaller sub-arrays on the left and right of the pivot:

quick-sort--images



#include <iostream>
#include <vector>
using namespace std;
​
int partition(vector<int>& arr, int low, int high) {
  
    // choose the pivot
    int pivot = arr[high];
  
    // undex of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;
​
    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}
​
// the QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);
​
        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
​
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

Output
1 5 7 8 9 10 
Complexity Analysis of Quick Sort
Time Complexity:

Best Case: (Ω(n log n)), Occurs when the pivot element divides the array into two equal halves.
Average Case (θ(n log n)), On average, the pivot divides the array into two parts, but not necessarily equal.
Worst Case: (O(n²)), Occurs when the smallest or largest element is always chosen as the pivot (e.g., sorted arrays).
Auxiliary Space:

Worst-case scenario: O(n) due to unbalanced partitioning leading to a skewed recursion tree requiring a call stack of size O(n).
Best-case scenario: O(log n) as a result of balanced partitioning leading to a balanced recursion tree with a call stack of size O(log n).
Please refer Time and Space Complexity Analysis of Quick Sort for more details.

Advantages of Quick Sort
It is a divide-and-conquer algorithm that makes it easier to solve problems.
It is efficient on large data sets.
It has a low overhead, as it only requires a small amount of memory to function.
It is Cache Friendly as we work on the same array to sort and do not copy data to any auxiliary array.
Fastest general purpose algorithm for large data when stability is not required.
It is tail recursive and hence all the tail call optimization can be done.
Disadvantages of Quick Sort
It has a worst-case time complexity of O(n2), which occurs when the pivot is chosen poorly.
It is not a good choice for small data sets.
It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot's position (without considering their original positions).
Applications of Quick Sort
Sorting large datasets efficiently in memory.
Used in library sort functions (like C++ std::sort and Java Arrays.sort for primitives).
Arranging records in databases for faster searching.
Preprocessing step in algorithms requiring sorted input (e.g., binary search, two-pointer techniques).
Finding the kth smallest/largest element using Quickselect (a variant of quicksort).
Sorting arrays of objects based on multiple keys (custom comparators).
Data compression algorithms (like Huffman coding preprocessing).
Graphics and computational geometry (e.g., convex hull algorithms).

merge sort

Merge Sort
Last Updated : 3 Oct, 2025
Merge sort is a popular sorting algorithm known for its efficiency and stability. It follows the Divide and Conquer approach. It works by recursively dividing the input array into two halves, recursively sorting the two halves and finally merging them back together to obtain the sorted array.

arr_
Here's a step-by-step explanation of how merge sort works:

Divide: Divide the list or array recursively into two halves until it can no more be divided.
Conquer: Each subarray is sorted individually using the merge sort algorithm.
Merge: The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.
Let's sort the array or list [38, 27, 43, 10] using Merge Sort

420046649.webp420046649.webp
Let's look at the working of above example: 

Divide: 

[38, 27, 43, 10]  is divided into  [38, 27] and  [43, 10]  . 
[38, 27]  is divided into  [38]  and  [27]  . 
[43, 10]  is divided into  [43]  and  [10]  . 
Conquer: 

[38]  is already sorted. 
[27]  is already sorted. 
[43]  is already sorted. 
[10]  is already sorted. 
Merge: 

Merge  [38]  and  [27]  to get  [27, 38]  . 
Merge  [43]  and  [10]  to get  [10,43]  . 
Merge  [27, 38]  and  [10,43]  to get the final sorted list  [10, 27, 38, 43] 
Therefore, the sorted list is  [10, 27, 38, 43]  . 

Try it on GfG Practice
redirect icon



#include <iostream>
#include <vector>
using namespace std;
​
// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;
​
    // Create temp vectors
    vector<int> L(n1), R(n2);
​
    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
​
    int i = 0, j = 0;
    int k = left;
​
    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
​
    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
​
    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
​
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right){
    
    if (left >= right)
        return;
​
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
​
// Driver code
int main(){
    
    vector<int> arr = {38, 27, 43, 10};
    int n = arr.size();
​
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

Output
10 27 38 43 
Recurrence Relation of Merge Sort
The recurrence relation of merge sort is:
T
(
n
)
=
{
Θ
(
1
)
if 
n
=
1
2
T
(
n
2
)
+
Θ
(
n
)
if 
n
>
1
T(n)={ 
Θ(1)
2T( 
2
n
​
 )+Θ(n)
​
  
if n=1
if n>1
​
 

T(n) Represents the total time time taken by the algorithm to sort an array of size n.
2T(n/2) represents time taken by the algorithm to recursively sort the two halves of the array. Since each half has n/2 elements, we have two recursive calls with input size as (n/2).
O(n) represents the time taken to merge the two sorted halves
Complexity Analysis of Merge Sort
Time Complexity:

Best Case: O(n log n), When the array is already sorted or nearly sorted.
Average Case: O(n log n), When the array is randomly ordered.
Worst Case: O(n log n), When the array is sorted in reverse order.
Auxiliary Space: O(n), Additional space is required for the temporary array used during merging.

Applications of Merge Sort:
Sorting large datasets
External sorting (when the dataset is too large to fit in memory)
Used to solve problems like Inversion counting, Count Smaller on Right & Surpasser Count
Merge Sort and its variations are used in library methods of programming languages. Its variation TimSort is used in Python, Java Android and Swift. The main reason why it is preferred to sort non-primitive types is stability which is not there in QuickSort. Arrays.sort in Java uses QuickSort while Collections.sort uses MergeSort.
It is a preferred algorithm for sorting Linked lists.
It can be easily parallelized as we can independently sort subarrays and then merge.
The merge function of merge sort to efficiently solve the problems like union and intersection of two sorted arrays.
Advantages and Disadvantages of Merge Sort
Advantages

Stability : Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN) , which means it performs well even on large datasets.
Simple to implement: The divide-and-conquer approach is straightforward.
Naturally Parallel : We independently merge subarrays that makes it suitable for parallel processing.
Disadvantages

Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process.
Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
Merge Sort is Slower than QuickSort in general as QuickSort is more cache friendly because it works in-place.

intro to sorts 

Sorting refers to rearrangement of a given array or list of elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of elements in the respective data structure.

Sorted_unsorted-algorithm--112.webpSorted_unsorted-algorithm--112.webp
Why Sorting Algorithms are Important
Sorting algorithms are essential in Computer Science as they simplify complex problems and improve efficiency. They are widely used in searching, databases, divide and conquer strategies, and data structures.

Key Applications:

Organizing large datasets for easier handling and printing
Enabling quick access to the k-th smallest or largest elements
Making binary search possible for fast lookups in sorted data
Solving advanced problems in both software and algorithm design
Sorting Basics
In-place Sorting: An in-place sorting algorithm uses constant space for producing the output (modifies the given array only. Examples: Selection Sort, Bubble Sort, Insertion Sort and Heap Sort.
Internal Sorting: Internal Sorting is when all the data is placed in the main memory or internal memory. In internal sorting, the problem cannot take input beyond allocated memory size.
External Sorting : External Sorting is when all the data that needs to be sorted need not to be placed in memory at a time, the sorting is called external sorting. External Sorting is used for the massive amount of data. For example Merge sort can be used in external sorting as the whole array does not have to be present all the time in memory,
Stable sorting: When two same items appear in the same order in sorted data as in the original array called stable sort. Examples: Merge Sort, Insertion Sort, Bubble Sort.
Hybrid Sorting: A sorting algorithm is called Hybrid if it uses more than one standard sorting algorithms to sort the array. The idea is to take advantages of multiple sorting algorithms. For Example IntroSort uses Insertions sort and Quick Sort.
Types of Sorting Techniques
There are various sorting algorithms are used in data structures. The following two types of sorting algorithms can be broadly classified:

Comparison-based: We compare the elements in a comparison-based sorting algorithm)
Non-comparison-based: We do not compare the elements in a non-comparison-based sorting algorithm)
Sorting algorithm
Sorting algorithm
Basics Sorting Algorithms:
Bubble Sort - O(n^2) Time and O(1) Space
It is a simple sorting algorithm that repeatedly swaps adjacent elements if they are in the wrong order. It performs multiple passes through the array, and in each pass, the largest unsorted element moves to its correct position at the end.

After each pass, we ignore the last sorted elements and continue comparing and swapping remaining adjacent pairs. After k passes, the last k elements are sorted. For more details refer here.

bubble-sort-1.webpbubble-sort-1.webp



#include <iostream>
#include <vector>
using namespace std;
​
// An optimized version of Bubble Sort 
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}
​
int main() {
    vector<int> arr = { 5, 6, 1, 3 };
    bubbleSort(arr); 
    for (int num : arr)
        cout << num << " ";
}

Output
11 12 22 25 34 64 90 
Insertion Sort - O(n^2) Time and O(1) Space
It is a simple sorting algorithm that builds the sorted array one element at a time. It works like sorting playing cards in your hand, where each new card is inserted into its correct position among the already sorted cards.

We start with the second element, assuming the first is already sorted. If the second element is smaller, we shift the first element and insert the second in the correct position. Then we move to the third element and place it correctly among the first two. This process continues until the entire array is sorted. For more details refer here.

Insertion-Sort--1.webpInsertion-Sort--1.webp



#include <iostream>
#include <vector>
using namespace std;
​
void insertionsort(vector<int>& arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
​
        // move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
​
int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();
​
    insertionsort(arr, n);
​
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
​
    return 0;
}

Output
5 6 11 12 13 
Selection Sort - O(n^2) Time and O(1) Space
It is a comparison-based sorting algorithm that repeatedly selects the smallest (or largest) element from the unsorted part of the array and swaps it with the first unsorted element. This process continues until the array is fully sorted.

We start by finding the smallest element and swap it with the first element. Then we find the next smallest element among the remaining and swap it with the second element. This continues until all elements are placed in their correct positions. For more details refer here.

Selection-Sort-Algorithm-1.webpSelection-Sort-Algorithm-1.webp



#include <iostream>
#include <vector>
using namespace std;
​
void selectionSort(vector<int> &arr) {
    int n = arr.size();
​
    for (int i = 0; i < n - 1; ++i) {
​
        // Assume the current position holds
        // the minimum element
        int min_idx = i;
​
        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
​
                // Update min_idx if a smaller
                // element is found
                min_idx = j; 
            }
        }
​
        // Move minimum element to its
        // correct position
        swap(arr[i], arr[min_idx]);
    }
}
​
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
​
    for (int &val : arr) {
        cout << val << " ";
    }
​
    return 0;
}

Output
11 12 22 25 64 
Counting Sort
It is a non-comparison-based sorting algorithm that works efficiently when the range of input values is small relative to the number of elements. It counts the frequency of each distinct element and uses that count to place elements directly into their correct sorted positions.

However, if the maximum value is much larger than the array size (especially more than n log n), then standard comparison-based algorithms are usually more efficient. For more details refer here.

Counting-Sort--1.webpCounting-Sort--1.webp



#include <iostream>
#include <vector>
using namespace std;
​
vector<int> countsort(vector<int>& arr) {
    int n = arr.size();
​
    // find the maximum element
    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);
​
    // create and initialize count array
    vector<int> count(maxval + 1, 0);
​
    // count frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
​
    // compute prefix sum
    for (int i = 1; i <= maxval; i++)
        count[i] += count[i - 1];
​
    // build output array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
​
    return ans;
}
​
int main() {
    vector<int> arr = {2,5,3,0,2,3,0,3};
    vector<int> sorted = countsort(arr);
​
    for (int x : sorted)
        cout << x << " ";
​
    return 0;
}

Output
0 0 2 2 3 3 3 5 
Time Complexity: O(n + m), where n and m are the size of arr[] and count[] respectively
Auxiliary Space: O(n + m)

Some of the most common sorting algorithms are:
Selection sort, Bubble sort, Insertion Sort, Cycle Sort, Merge Sort, 3-way Merge Sort, Quick sort, Heap sort and Counting sort

Some other Sorting algorithms:
Radix sort, Bucket sort, Shell sort, Tim Sort, Comb Sort, Pigeonhole sorting, Cocktail Sort, Strand sort, Bitonic Sort, Stooge Sort, Tag Sort, Tree sort, Cartesian Sort, Odd-Even Sort / Brick Sort, Gnome sort, Cocktail shaker sort

Comparison of Complexity Analysis of Sorting Algorithms:
Name	Best Case  	Average Case  	Worst Case 	Memory	Stable   	Method Used
Quick Sort	
n
l
o
g
n
nlogn	
n
l
o
g
n
nlogn	
n
2
n 
2
 	
l
o
g
n
logn	No	Partitioning
Merge Sort	
n
l
o
g
n
nlogn	
n
l
o
g
n
nlogn	
n
l
o
g
n
nlogn	n	Yes	Merging
Heap Sort	
n
l
o
g
n
nlogn	
n
l
o
g
n
nlogn	
n
l
o
g
n
nlogn	1	No	Selection
Insertion Sort	n	
n
2
n 
2
 	
n
2
n 
2
 	1	Yes	Insertion
Tim Sort	n	
n
l
o
g
n
nlogn	
n
l
o
g
n
nlogn	n	Yes	Insertion & Merging
Selection Sort	
n
2
n 
2
 	
n
2
n 
2
 	
n
2
n 
2
 	1	No	Selection
Shell Sort	
n
l
o
g
n
nlogn	
n
4
/
3
n 
4/3
 	
n
3
/
2
n 
3/2
 	1	No	Insertion
Bubble Sort	n	
n
2
n 
2
 	
n
2
n 
2
 	1	Yes	Exchanging
Cycle Sort	
n
2
n 
2
 	
n
2
n 
2
 	
n
2
n 
2
 	1	No	Selection


    disadvantages of sorting algorithms

    Applications, Advantages and Disadvantages of Sorting Algorithm
Last Updated : 23 Jul, 2025
Sorting algorithms are used to arrange a list of elements in a specific order, such as ascending or descending or any other user specified order like sorting strings by lengths.

Click to enlarge
Sorting Algorithm


Applications of Sorting Algorithms:
Quickly Finding k-th Smallest or K-th Largest : Once we sort the array, we can find k-th smallest and k-th largest elements in O(1) time for different values of k.
Searching Algorithms: Sorting is often a crucial step in search algorithms like binary search, Ternary Search, where the data needs to be sorted before searching for a specific element.
Data management: Sorting data makes it easier to search, retrieve, and analyze.
Database optimization: Sorting data in databases improves query performance. We typically keep the data sorted by primary index so that we can do quick queries.
Machine learning: Sorting is used to prepare data for training machine learning models.
Data Analysis: Sorting helps in identifying patterns, trends, and outliers in datasets. It plays a vital role in statistical analysis, financial modeling, and other data-driven fields.
Operating Systems: Sorting algorithms are used in operating systems for tasks like task scheduling, memory management, and file system organization.
Advantages of Sorting Algorithms:
Efficiency: Sorting algorithms help in arranging data in a specific order, making it easier and faster to search, retrieve, and analyze information.
Improved Performance: By organizing data in a sorted manner, algorithms can perform operations more efficiently, leading to improved performance in various applications.
Simplified data analysis: Sorting makes it easier to identify patterns and trends in data.
Reduced memory consumption: Sorting can help reduce memory usage by eliminating duplicate elements.
Improved data visualization: Sorted data can be visualized more effectively in charts and graphs.
Disadvantages of Sorting Algorithms:
Insertion: If we wish to keep data sorted, then insertion operation becomes costly as we have to maintain sorted order. If we do not have to maintain sorted order, we can simply insert at the end.
Algorithm selection: Choosing the most appropriate sorting algorithm for a given dataset can be challenging.
For a lot of problems hashing works better than sorting, for example, finding distinct elements, finding a pair with given sum.
Comment
T