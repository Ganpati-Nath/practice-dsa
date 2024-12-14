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

Node* buildTree(){
    int data;
    cout << "Enter data : " ;
    cin >> data;
    if(data == -1) return NULL;
    Node* root = new Node(data);
    cout << "Enter the left node of " << data << " is..." << endl;
    root->left = buildTree();
    cout << "Enter the right node of " << data << " is..." << endl;
    root->right = buildTree();
    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << "   ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << "   ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if(root == NULL) return;
    cout << root->data << "   ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "   ";
}

int height(Node* root) {
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = 1 + max(leftHeight, rightHeight);
    return ans;
}

int diameter(Node* root) {
    if(root == NULL) return 0;
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = height(root->left) + 1 + height(root->right);
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
    inOrder(root);
    cout << endl;
    cout << "PRE-ORDER-TRAVERSAL..." << endl;
    preOrder(root);
    cout << endl;
    cout << "POST-ORDER-TRAVERSAL..." << endl;
    postOrder(root);
    cout << endl;
    cout << "Height : " << height(root) << endl;
    cout << endl;
    cout << "Diameter : " << diameter(root) << endl;
    return 0;
}