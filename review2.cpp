This document provides a comprehensive overview of **Data Structures and Algorithms** as part of the CDS 1101 Prelims course. It covers basic Python data types, the classification of data structures, and their practical applications.

---

## **Introduction to Data Structures**

A **Data Structure** is a specialized format used for organizing, processing, retrieving, and storing data. By arranging data for specific purposes, these structures ensure information can be accessed and worked with efficiently.

### **Basic Data Types in Python**

To declare variables in Python, an assignment operator is used to link a name to a value (e.g., `name = "mabel"`). Using correct data types is crucial for accurate operations; for instance, adding two integers results in a sum, while adding two strings results in concatenation.

* 
**Integer**: Positive or negative whole numbers without fractional parts.


* 
**Float**: Real numbers with a floating-point representation (decimals or scientific notation).


* 
**Boolean**: Represents one of two values: True or False ( or ).


* **Sequence Types**:
* 
**String**: A collection of characters enclosed in single, double, or triple quotes.


* 
**List**: An ordered collection of items (not necessarily the same type) in square brackets `[]`.


* 
**Tuple**: An ordered collection of items in parentheses `()`.





---

## **Classification of Data Structures**

### **1. Built-in Data Structures**

These are predefined structures available directly within Python:

* 
**List**: A mutable (changeable), ordered sequence of elements.


* 
**Dictionary**: An unordered collection that stores data in unique **key-value pairs**. They are mutable.


* 
**Tuple**: An ordered, **immutable** collection; once created, items cannot be changed, added, or removed.


* 
**Set**: An unordered collection of unique elements, supporting mathematical operations like union and intersection.



### **2. User-Defined Data Structures**

These structures are often implemented using classes or other built-in types to meet specific needs:

* 
**Stack**: A linear structure following the **Last-In, First-Out (LIFO)** principle.


* 
**Queue**: A linear structure following the **First-In, First-Out (FIFO)** principle.


* 
**Tree**: A non-linear, hierarchical structure with parent-child relationships (root, branches, and leaves).


* 
**Linked List**: A linear collection of nodes where each node contains data and a pointer to the next node. Unlike arrays, they do not use contiguous memory.


* 
**Graph**: A non-linear structure consisting of vertices (nodes) and edges that connect them.


* 
**HashMap**: Often implemented via the built-in dictionary, it can be customized for specific hash-table mechanics.



---

## **Importance and Operations**

Programs consist of **data** and **algorithms**. Data structures are vital because they:

* Simplify algorithms and make them faster and easier to maintain.


* Enhance software performance by speeding up data storage and retrieval.


* Allow management of large datasets like internet indexing or databases.



### **Common Operations**

* 
**Search**: Finding an item within the structure.


* 
**Sort**: Arranging items in a specific order.


* 
**Insert**: Adding a new item.


* 
**Update**: Modifying an existing item.



### **Real-World Examples**

* 
**Web Browsers**: Use **Linked Lists** to track visited pages for the "back" button.


* 
**Text Editors**: Use **Stacks** to manage "undo" mechanisms.


* 
**Operating Systems**: Use **Queues** for CPU task scheduling.


* 
**Compilers**: Use **Trees** to determine the order of precedence in arithmetic expressions.



---

Would you like me to create a summary table comparing the differences between **Lists**, **Tuples**, and **Sets** based on this data?