#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int countFreedomNodes(Node* root, int target){
    if(root == NULL)
        return 0;

    if(!root->left && !root->right && root->data == target)
        return 1;

    int count = 0;

    count += countFreedomNodes(root->left, target - root->data);
    count += countFreedomNodes(root->right, target - root->data);

    return count;
}

int main()
{
    int n, x;
    cin>>n>>x;

    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;

        nodes[i] = new Node(val);
    }

    for(int i = 0; i < n/2; i++){
        if(nodes[i]->data != -1){
            nodes[i]->left = nodes[2*i + 1];
            nodes[i]->right = nodes[2*i + 2];
        }
    }

    int ans = countFreedomNodes(nodes[0], x);

    cout << ans << endl;
    return 0;
}