#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

int sum = 0;

void greaterSumTree(Node* root){
    if(!root)
        return;
    
    greaterSumTree(root->right);
    root->data += sum;
    sum = root->data;
    greaterSumTree(root->left);
}

vector<int> treeToArray(Node* root){
    vector<int> arr;
    
    if(!root)
        return arr;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr){
            arr.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        }else{
            arr.push_back(-1);
        }
    }

    while(!arr.empty() && arr.back() == -1){
        arr.pop_back();
    }
    return arr;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    Node* root = NULL;

    for(int i = 0; i < n; i++){
        if(arr[i] == -1)
            continue;
        
        Node* newNode = new Node(arr[i]);

        if(!root)
            root = newNode;
        
        else{
            Node* parent = root;

            while(true){
                if(arr[i] < parent->data){
                    if(!parent->left){
                        parent->left = newNode;
                        break;
                    }
                    parent = parent->left;
                }
                else{
                    if(!parent->right){
                        parent->right = newNode;
                        break;
                    }
                    parent = parent->right;
                }
            }
        }
    }

    greaterSumTree(root);
    vector<int> ans = treeToArray(root);

    for(int x = 0; x < ans.size(); x++){
        cout << ans[x] << " ";
    }
    cout<<endl;
    return 0;
}