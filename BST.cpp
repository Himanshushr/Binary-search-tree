#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
       int value;
       Node *left, *right;
       Node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
       }
};
class BinarySearchTree{
    private:
        Node *root;
    public:
        BinarySearchTree(){
            root = nullptr;
        }
        //root getter
        Node *getRoot(){
            return root;
        }
        //recursive insert
        void rInsert(int value){
            if(root == nullptr){
                root = new Node(value);
            }
            rInsert(root, value);
        }
        Node *rInsert(Node *currentNode, int value){
            if(currentNode == nullptr) return new Node(value);

            if(currentNode->value > value){
                currentNode->left = rInsert(currentNode->left, value);
            }else if(currentNode->value < value){
                currentNode->right = rInsert(currentNode->right, value);
            }
            return currentNode;
        }
        //normal insert
        bool insert(int value){
            Node *newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
                return true;
            }
            Node *temp = root;
            while(true){
                if(temp->value == newNode->value)return false;
                if(newNode->value < temp->value){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
        //return minimum value
        int minValue(Node *currentNode){
            while(currentNode->left){
                currentNode = currentNode->left;
            }
            return currentNode->value;
        }
        //BFS TRAVERSAL
        void bfs(){
            if(!root){
                cout << "Tree empty" << endl;
                return;
            }
            queue<Node*> myQueue;
            myQueue.push(root);
            while(myQueue.size() > 0){
                Node *currentNode = myQueue.front();
                myQueue.pop();
                cout << currentNode->value << " ";
                if(currentNode->left){
                    myQueue.push(currentNode->left);
                }
                if(currentNode->right){
                    myQueue.push(currentNode->right);
                }
            }
        }
        //preorder is not as same as bfs
        //pre-order
        void preOrder(Node *currentNode){
            if(!currentNode){
                cout << "tree is Empty" << endl;
                return;
            }
            cout << currentNode->value << " ";
            if(currentNode->left){
                preOrder(currentNode->left);
            }
            if(currentNode->right){
                preOrder(currentNode->right);
            }
        }
};
int main(){
    BinarySearchTree *bst = new BinarySearchTree();
    int choice = 1;
    while(choice != 0){
        cout << "1. To Insert values into BST\n" << "2. To insert a values using rBST\n" <<
                "3. To find the min value of tree\n" << "4. To print bfs\n" << "5. To print preorder" << endl;
        cin >> choice; 
        switch(choice){
            case 1: int val, limit;
                    cout << "Enter count of values: ";
                    cin >> limit; 
                    cout << "Enter values: " << endl;
                    for(int i = 0; i < limit; i++){
                        cin >> val;
                        bst->insert(val);
                    }
                    break;
            case 2: cout << "Enter a value(rBST): " << endl;
                    cin >> val;
                    bst->rInsert(val);
                    break;
            case 3: cout << bst->minValue(bst->getRoot()) << endl;
                    break;        
            case 4: cout << "BFS: ";
                    bst->bfs();
                    cout << endl;
                    break;
            case 5: cout << "Pre-Order: ";
                    bst->preOrder(bst->getRoot());
                    cout << endl;
                    break;
            case 0: break;
        }
    }
}