# Trees Implementation

## what has been my approach here?
- Create a structure for the <b>nodes of the tree</b>
    - one variable to <i>hold the data</i> of the node - `int data`.
    - the other is an array `vector<Node*> children`, which will hold the all the childrens of that Node.
        ```cpp
        struct Node { 
            int data;
            vector<Node*> children;
        };
- Then we are creating a class to manage the nodes of the tree we are calling this class `tree`
    - we will need a root node (this is the staring point of the our tree)
    - using `root` we can do all the operations (<i>Creation, Read, Update, and Deletion</i>)
        ```cpp
        class Tree {
            private : 
                Node* root;
        }

#### Traversal Method for the Tree

- used `for` loop to traverse through the tree
- while traversing the nodes, if there are children of that node that too would be displayed but kept this nested loop structure only till the 2nd level. (<i>This is for understanding the logic behind traversal of tree</i>)

    ``` cpp
    void display(){
        // root level
        cout<< root->data  
        for(int i = 0; i < root->children.size(); i++){
            //Level 1
            cout<< root->children[i]->data; 
            if(root->children[i]->children.size()){ 
                // Level 2
                for(int j = 0; j < root->children[i]->children.size(); j++){
                    cout<< root->children[i]->children[j]->data;
                }
                }
            }
        }

#### How are children added for an element?

- <b>Concept:</b>
    - Since there we are using a `vector` with no specfified size we can store `n` number of nodes as children for any node.

    - so we could have something like this 

        ``` cpp
        vector<Node*> children = {child1Address, child2Address, child3Address}
    
- <b>Code Implementation:</b>
    - here we have not implemented what one would called a "proper function" for creaitng this  parent-children relationship rather we have used a a basic functions where we pass the `parentNode` and `childNode` as argument.

        ``` cpp
        void pushChildren(Node* parentNode, Node* childNode) {

            parentNode->children.push(childNode)

        }
    - how we will utlize this function?
        ``` cpp
        Node* higherLevelNode = new Node(10);
        Node* lowerLevelNode = new Node(20);

        pushChildren(higherLevelNode, lowerLevelNode);

        // this will create a realtionship like this

                (other part of the tree)
                         |
                         10
                     /   |   \
                    x    20   y

        // a realation b/w 10 and 20 been established as parent and child respectively
                    

## Final Conculsion:

1. Learnt to implement tree data structure
2. understood the basic of traversing a tree
3. Get a intiutive feeling of why we need a bettr data strcture.

## What's Next?
 - use this learning to create a more comprehensive way of creating trees
 - create a more efficnet way to traverse the tree (BSF and DSF)



