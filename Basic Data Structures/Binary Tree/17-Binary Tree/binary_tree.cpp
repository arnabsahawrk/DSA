/*
### **In-Depth Explanation of Binary Tree**

A **binary tree** is a hierarchical data structure where each node has at most two children, referred to as the **left child** and the **right child**. It is a specific type of tree structure and serves as the foundation for many more advanced tree data structures like binary search trees, heaps, and AVL trees.

---

### **Key Features of Binary Tree**
1. **Node Structure**:
   Each node consists of:
   - **Data**: The value stored in the node.
   - **Left Pointer**: Points to the left child (if any).
   - **Right Pointer**: Points to the right child (if any).

2. **Root**:
   - The topmost node of the binary tree.
   - The root node does not have a parent.

3. **Children**:
   - A node can have up to two children: left and right.

4. **Parent**:
   - A node that has branches to other nodes.

5. **Leaf Nodes**:
   - Nodes with no children.

6. **Subtree**:
   - A binary tree formed by any node and its descendants.

7. **Height**:
   - The number of edges on the longest path from a node to a leaf.

8. **Depth**:
   - The number of edges from the root to a node.

---

### **Types of Binary Trees**

1. **Full Binary Tree**:
   - A tree where every node has either 0 or 2 children.
   - No node has only one child.

2. **Perfect Binary Tree**:
   - A full binary tree in which all leaves are at the same depth.
   - All internal nodes have exactly two children.

3. **Complete Binary Tree**:
   - All levels are completely filled except possibly the last level, which is filled from left to right.

4. **Degenerate (or Pathological) Binary Tree**:
   - A tree where each parent node has only one child, making it effectively a linked list.

5. **Balanced Binary Tree**:
   - A tree where the height of the left and right subtrees of any node differ by at most 1.

6. **Binary Search Tree (BST)**:
   - A binary tree with the property:
     - For each node, all values in its left subtree are smaller, and all values in its right subtree are larger.

---

### **Binary Tree Representation**

#### **1. Array Representation**
   - A binary tree can be represented in a sequential manner using an array.
   - For a node at index \(i\) in the array:
     - Left child is at index \(2i + 1\).
     - Right child is at index \(2i + 2\).
     - Parent is at index \((i-1)/2\).

#### **2. Linked Representation**
   - Each node is represented as an object or struct with pointers to its left and right children.

**Example C++ Implementation of a Node**:
```cpp
class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};
```

---

### **Traversals in Binary Tree**

Traversal refers to the process of visiting all nodes in a binary tree in a systematic way.

#### **1. Depth-First Search (DFS)**
   - Traverses the tree by going as deep as possible along each branch before backtracking.

   **Types of DFS Traversals**:
   - **Inorder Traversal** (Left → Root → Right):
     - Visit left subtree.
     - Visit the root node.
     - Visit right subtree.
     - Produces nodes in sorted order for BSTs.

     **Example Code (C++)**:
     ```cpp
     void inorderTraversal(Node* root) {
         if (root == nullptr) return;

         inorderTraversal(root->left);    // Left
         cout << root->value << " ";      // Root
         inorderTraversal(root->right);   // Right
     }
     ```

   - **Preorder Traversal** (Root → Left → Right):
     - Visit the root node.
     - Visit left subtree.
     - Visit right subtree.

     **Example Code (C++)**:
     ```cpp
     void preorderTraversal(Node* root) {
         if (root == nullptr) return;

         cout << root->value << " ";      // Root
         preorderTraversal(root->left);   // Left
         preorderTraversal(root->right);  // Right
     }
     ```

   - **Postorder Traversal** (Left → Right → Root):
     - Visit left subtree.
     - Visit right subtree.
     - Visit the root node.

     **Example Code (C++)**:
     ```cpp
     void postorderTraversal(Node* root) {
         if (root == nullptr) return;

         postorderTraversal(root->left);   // Left
         postorderTraversal(root->right);  // Right
         cout << root->value << " ";       // Root
     }
     ```

#### **2. Breadth-First Search (BFS)**
   - Traverses the tree level by level from top to bottom, left to right.

   **Example Code (C++)**:
   ```cpp
   void levelOrderTraversal(Node* root) {
       if (root == nullptr) return;

       queue<Node*> q;
       q.push(root);

       while (!q.empty()) {
           Node* current = q.front();
           q.pop();
           cout << current->value << " ";

           if (current->left != nullptr) q.push(current->left);
           if (current->right != nullptr) q.push(current->right);
       }
   }
   ```

---

### **Properties of Binary Trees**

1. **Maximum Nodes at Level \(l\)**:
   - Maximum nodes at level \(l = 2^l\).

2. **Maximum Nodes in a Tree of Height \(h\)**:
   - Maximum nodes \(= 2^h - 1\).

3. **Minimum Height of a Binary Tree with \(n\) Nodes**:
   - Minimum height \(= \lceil \log_2(n + 1) \rceil\).

4. **Number of Leaf Nodes**:
   - In a full binary tree, the number of leaf nodes is one more than the number of internal nodes.

---

### **Applications of Binary Trees**

1. **Expression Trees**:
   - Used in compilers to represent arithmetic expressions.

2. **Binary Search Trees**:
   - Efficient for searching, inserting, and deleting.

3. **Heaps**:
   - Used to implement priority queues.

4. **Huffman Encoding**:
   - A binary tree is used in data compression algorithms.

5. **Routing Tables**:
   - Binary trees help in representing routing decisions in networks.

---

### **Common Problems with Binary Trees**

1. **Check if a Binary Tree is Balanced**:
   - Ensure the height difference of left and right subtrees is no more than 1.

2. **Find the Lowest Common Ancestor**:
   - Identify the lowest node that is an ancestor to two given nodes.

3. **Convert a Binary Tree to its Mirror**:
   - Swap the left and right pointers for all nodes.

4. **Calculate the Diameter of the Tree**:
   - The longest path between any two nodes.

---
*/