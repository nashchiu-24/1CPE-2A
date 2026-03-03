#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// C , B , assigned number 
// basic node used in the linked list
struct Node {
    char data;       // stored character
    Node* next;      // pointer to next node
    Node* prev;      // pointer to previous node (if doubly linked)
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

// simple linked list class. methods are named with two letters.
class JJ {
private:
    Node* head;      // first element
    Node* tail;      // last element
    bool isDoubly;   // track if list supports backward links

public:
    // constructor with optional doubly flag
    JJ(bool doubly = false) : head(nullptr), tail(nullptr), isDoubly(doubly) {}
    // destructor cleans up all nodes
    ~JJ() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // insert value; if atFront true, push at head, otherwise at tail
    void KK(char val, bool atFront = false) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
            return;
        }
        if (atFront) {
            newNode->next = head;
            if (isDoubly) head->prev = newNode;
            head = newNode;
        } else {
            tail->next = newNode;
            if (isDoubly) newNode->prev = tail;
            tail = newNode;
        }
    }

    // remove first node with matching value
    void NN(char val) {
        if (!head) return;
        // special case: head needs removal
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            if (isDoubly && head) head->prev = nullptr;
            if (!head) tail = nullptr;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != val) {
            current = current->next;
        }
        if (!current->next) return;
        Node* temp = current->next;
        current->next = temp->next;
        if (isDoubly && temp->next) temp->next->prev = current;
        if (!current->next) tail = current;
        delete temp;
    }

    // print list from head to tail
    void LL() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (isDoubly) cout << "<->";
            else cout << "->";
            temp = temp->next;
        }
        cout << "null\n";
    }

    // print list backward (only for doubly linked)
    void MM() const {
        if (!isDoubly) return;
        Node* temp = tail;
        while (temp) {
            cout << temp->data << "<->";
            temp = temp->prev;
        }
        cout << "null\n";
    }

    void OO() const { LL(); }
};

// node structure for binary tree
struct VV {
    char data;   // stored character
    VV* left;    // left child
    VV* right;   // right child
    VV(char val) : data(val), left(nullptr), right(nullptr) {}
};

// binary search tree class
class PP {
private:
    VV* root;    // root of the tree

    // helpers for recursive traversal order types
    enum class TraversalOrder { QQQ, RRR, SSS };

    // delete all nodes in subtree
    void clear(VV* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    // recursive BST insert helper
    VV* insertNode(VV* node, char val) {
        if (!node) return new VV(val);
        if (val < node->data)
            node->left = insertNode(node->left, val);
        else if (val > node->data)
            node->right = insertNode(node->right, val);
        return node;
    }

    // recursive BST delete helper
    VV* deleteNode(VV* node, char val) {
        if (!node) return nullptr;
        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            if (!node->left) {
                VV* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                VV* temp = node->left;
                delete node;
                return temp;
            } else {
                // two children: find inorder successor
                VV* temp = node->right;
                while (temp->left) temp = temp->left;
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    // generic traversal helper: preorder(QQQ), inorder(RRR), postorder(SSS)
    void ZZ(VV* node, TraversalOrder order) const {
        if (!node) return;
        if (order == TraversalOrder::QQQ) cout << node->data << " ";
        ZZ(node->left, order);
        if (order == TraversalOrder::RRR) cout << node->data << " ";
        ZZ(node->right, order);
        if (order == TraversalOrder::SSS) cout << node->data << " ";
    }

    void OO(TraversalOrder order) const {
        ZZ(root, order);
        cout << "\n";
    }

public:
    PP() : root(nullptr) {}
    ~PP() { clear(root); }

    void K(char val) { root = insertNode(root, val); }
    void NN(char val) { root = deleteNode(root, val); }
    void QQ() const { OO(TraversalOrder::QQQ); }
    void RR() const { OO(TraversalOrder::RRR); }
    void SS() const { OO(TraversalOrder::SSS); }

    // level-order traversal using a queue
    void TT() {
        if (!root) return;
        queue<VV*> q;
        q.push(root);
        while (!q.empty()) {
            VV* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n";
    }

    // iterative preorder traversal with stack
    void UU() {
        if (!root) return;
        stack<VV*> s;
        s.push(root);
        while (!s.empty()) {
            VV* node = s.top();
            s.pop();
            cout << node->data << " ";
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        cout << "\n";
    }
};

int main() {
    cout << "=== sing ===\n";
    JJ sing(false);
    for (char value : {'a', 'b','c'}) sing.KK(value);
    sing.OO();
    sing.NN('b');
    sing.OO();

    cout << "=== dance===\n";
    JJ dance(true);
    for (char value : {'d', 'e', 'f','g'}) dance.KK(value);
    cout << "LL: ";
    dance.LL();
    cout << "MM: ";
    dance.MM();

    dance.KK('c', true);
    cout << "after KK('c', true) - LL: ";
    dance.LL();
    cout << "after KK('c', true) - MM: ";
    dance.MM();

    dance.NN('e');
    cout << "after NN('e') - LL: ";
    dance.LL();
    cout << "after NN('e') - MM: ";
    dance.MM();

    cout << "=== travel  ; ===\n";
    PP travel;
    for (char value : {'d', 'b', 'f', 'a', 'c', 'e', 'g'}) travel.K(value);

    cout << "Preorder: ";
    travel.QQ();
    cout << "Inorder: ";
    travel.RR();
    cout << "Postorder: ";
    travel.SS();
    cout << "Level order: ";
    travel.TT();
    cout << "Iterative Preorder: ";
    travel.UU();

    return 0;
}
