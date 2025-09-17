# Trees Implementation

### what is my approach here?
- Create a structure for the <b>nodes of the tree</b>
    - one variable to <i>hold the data</i> of the node - `int data`.
    - the other is an array `vector<Node*> children`, which will hold the all the childrens of that Node.

    ```cpp
    struct Node{
        int data;
        vector<Node*> children;
    };
    