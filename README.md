#Binary Search Tree
Binary Search Tree is a node-based binary tree data structure which has the following properties: 

1.The left subtree of a node contains only nodes with values lesser than the node value.
2.The right subtree of a node contains only nodes with values greater than the node value.
3.The left and right subtree each must also be a binary search tree. 
4.There must be no duplicate nodes.

![Screenshot from 2022-06-24 13-50-24](https://user-images.githubusercontent.com/104670251/175511507-48ad9686-6ac9-4c95-87fa-5597c9d37744.png)

Advantages of Binary Search Tree:
1.BST is fast in insertion and deletion when balanced.
2.BST is efficient.
3.BST code is simple as compared to other data structures.

Disadvantages of Binary Search Tree:
1.The main disadvantage is that we should always implement a balanced binary search tree.Otherwise the cost of operations may not be logarithmic and degenerate into a linear search on an array.
2.Accessing the element in BST is slightly slower than array.
3.A BST can be imbalanced which can increase the complexity.

![Screenshot from 2022-06-24 14-11-56](https://user-images.githubusercontent.com/104670251/175514722-dbed9e89-3654-4f09-9168-2cd5bc50b782.png)

Execution times:
1.Search	O(log n):
2.Minimum	O(log n):
3.Maximum	O(log n):
4.Insert	O(log n):
5.Delete	O(log n):
//this function returns two trees connected to each other
BST functions:
1.insert() //enters a value.
2.clear() //enters a value.
3.get_height() // returns the height of the tree.
4.erase() //removes a specific item.
5.get_number_of_nodes() // returns the number of roots.
6.preorder()
7.inorder()
8.postorder()
9.levelorder()
10.get_root_data() // returns root.
11.merge() //this function returns two trees connected to each other.
12.contains() // checks if there is such a value.
13.find() // this function returns a pointer to the root of a given value.
