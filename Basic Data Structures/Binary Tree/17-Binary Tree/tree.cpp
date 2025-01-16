/*
### **In-Depth Explanation of Trees**

A **tree** is a widely used data structure in computer science that simulates a hierarchical tree structure with a set of connected nodes. Trees are non-linear data structures, unlike arrays, stacks, queues, and linked lists, which are linear.

---

### **Key Concepts of Trees**
1. **Nodes**:
   - The individual elements of a tree.
   - Each node contains data and references (links) to its child nodes.

2. **Root**:
   - The topmost node in a tree.
   - There is only one root in a tree, and it does not have a parent.

3. **Parent and Child**:
   - A **parent** node is a node that has branches to other nodes.
   - The nodes connected by these branches are called **children**.

4. **Leaf**:
   - A node that has no children (i.e., no outgoing branches).

5. **Subtree**:
   - A tree consisting of a node and its descendants.

6. **Edge**:
   - The connection between one node and another.
   - If there are \(n\) nodes in a tree, there will be \(n-1\) edges.

7. **Depth**:
   - The number of edges from the root to a specific node.

8. **Height**:
   - The number of edges on the longest path from the node to a leaf.
   - For the tree itself, the height of the root is the height of the tree.

9. **Level**:
   - The depth of a node plus 1 (root is at level 1, its children at level 2, etc.).

10. **Degree**:
    - The number of children a node has.

11. **Path**:
    - A sequence of nodes and edges connecting a node to another.

12. **Ancestor and Descendant**:
    - A node is an ancestor of another node if it lies on the path from the root to that node.
    - A descendant is any node that is a child or lies below a node.

---

### **Types of Trees**

1. **Binary Tree**:
   - Each node can have at most two children: left and right.
   - Commonly used for hierarchical data like expressions, decision processes, etc.

2. **Binary Search Tree (BST)**:
   - A binary tree with the additional property that:
     - The left subtree of a node contains only nodes with values less than the node’s value.
     - The right subtree contains only nodes with values greater than the node’s value.
   - Efficient for search operations.

3. **Balanced Trees**:
   - Trees that ensure the height difference between left and right subtrees for every node is minimal. Examples:
     - **AVL Tree**: Self-balancing binary search tree.
     - **Red-Black Tree**: A balanced binary search tree used in many libraries.

4. **Full Binary Tree**:
   - Every node has 0 or 2 children.

5. **Complete Binary Tree**:
   - All levels except possibly the last are fully filled, and all nodes are as far left as possible.

6. **Perfect Binary Tree**:
   - A binary tree in which all interior nodes have two children, and all leaves are at the same level.

7. **N-ary Tree**:
   - Each node can have up to \(N\) children.

8. **Trie (Prefix Tree)**:
   - A tree used to store strings where edges represent characters.

9. **Heap**:
   - A special tree-based data structure satisfying the **heap property**:
     - Max-Heap: Parent nodes are greater than or equal to their children.
     - Min-Heap: Parent nodes are less than or equal to their children.

10. **Segment Tree**:
    - Used for range queries and updates.

11. **Fenwick Tree (Binary Indexed Tree)**:
    - Used for cumulative frequency tables.

---

### **Tree Traversal**

Traversing a tree means visiting all the nodes in a specific order. Common tree traversal techniques:

1. **Depth-First Traversal (DFS)**:
   - Explore as far down a branch as possible before backtracking.
   - Types:
     - **Inorder**: Left → Root → Right
     - **Preorder**: Root → Left → Right
     - **Postorder**: Left → Right → Root

2. **Breadth-First Traversal (BFS)**:
   - Explore all nodes at one level before moving to the next.

---

### **Applications of Trees**

1. **Hierarchical Data Representation**:
   - File systems, organizational structures, XML/HTML data.

2. **Searching and Sorting**:
   - Binary Search Trees for fast searches.
   - Heaps for priority queues.

3. **Network Routing**:
   - Trees are used in decision-making for routing algorithms.

4. **Expression Parsing**:
   - Abstract syntax trees for compilers.

5. **Data Compression**:
   - Huffman trees for encoding.

6. **AI and Game Development**:
   - Decision trees and minimax algorithms.
*/