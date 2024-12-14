#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree() {
    int data;
    cout << "Enter data : ";
    cin >> data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    cout << "Enter the data for left node of " << data << " is..." << endl;
    root->left = buildTree();
    cout << "Enter the data for right node of  " << data << " is..." << endl;
    root->right = buildTree();
    return root;
}

void inOrderTraversal(Node* root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << "   ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if(root == NULL) return;
    cout << root->data << "   ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "    ";
}

void levelOrderTraversal(Node* root) {
    queue<Node*> que;
    que.push(root);
    que.push(NULL);
    while(!que.empty()) {
        Node* temp = que.front();
        que.pop();
        if(temp == NULL) {
            cout << endl;
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else {
            cout << temp->data << "   ";
            if(temp->left) {
                que.push(temp->left);
            }
            if(temp->right) {
                que.push(temp->right);
            }
        }
    }
    
}

int heightOfTree(Node* root) {
    if(root == NULL) return 0;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

int diameterOfTree(Node* root){
    if(root == NULL) return 0;
    int option1 = diameterOfTree(root->left);
    int option2 = diameterOfTree(root->right);
    int option3 = heightOfTree(root->left) + 1 + heightOfTree(root->right);
    int ans = max(option1, max(option2, option3));
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree();
    cout << "LEVEL-ORDER-TRAVERSAL..." << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "IN-ORDER-TRAVERSAL..." << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "PRE-ORDER-TRAVERSAL..." << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "POST-ORDER-TRAVERSAL..." << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "Height : " << heightOfTree(root) << endl;
    cout << "Diameter : " << diameterOfTree(root) << endl;
    return 0;
}