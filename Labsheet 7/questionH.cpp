#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* beautifulBST(Node* root, int l, int r){
    if(!root)
        return NULL;

    if(root->data < l){
        Node* right = root->right;
        delete(root);
        return beautifulBST(right, l, r);
    }

    if(root->data > r){
        Node* left = root->left;
        delete(root);
        return beautifulBST(left, l, r);
    }

    root->left = beautifulBST(root->left, l, r);
    root->right = beautifulBST(root->right, l, r);

    return root;
}

void postOrder(Node* root){
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int n, l, r;
    cin>>n>>l>>r;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    // BUILDING BST
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        if(arr[i] != -1){
            if(!root){
                root = new Node(arr[i]);
            }
            else{
                Node* temp = root;
                while(temp){
                    if(arr[i] < temp->data){
                        if(!temp->left){
                            temp->left = new Node(arr[i]);
                            break;
                        }
                        temp = temp->left;
                    }
                    else{
                        if(!temp->right){
                            temp->right = new Node(arr[i]);
                            break;
                        }
                        temp = temp->right;
                    }
                }
            }
        }
    }

    Node* beautifulRoot = beautifulBST(root, l, r);
    postOrder(beautifulRoot);

    cout<<endl;
    return 0;
}