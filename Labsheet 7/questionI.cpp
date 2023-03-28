#include <iostream>
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

bool findPath(Node* root, int target, vector<int>& path){
    if(!root)
        return false;

    path.push_back(root->data);

    if(root->data == target)
        return true;

    if(findPath(root->left, target, path) || findPath(root->right, target, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int leastCommonAncestor(Node* root, int t1, int t2){
    vector<int> path1, path2;

    if(!findPath(root, t1, path1) || !findPath(root, t2, path2)){
        return -1;
    }
    int temp = 0;

    while(temp < path1.size() && temp < path2.size() && path1[temp] == path2[temp]){
        temp++;
    }

    return path1[temp - 1];
}

int main()
{
    int n, t1, t2;
    cin>>n>>t1>>t2;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++){
        if(arr[i] != -1){
            nodes[i] = new Node(arr[i]);
        }else{
            nodes[i] = NULL;
        }
    }

    for(int i = 0; i < n; i++){
        if(nodes[i]){
            if((2 * i + 1 < n) && nodes[2 * i + 1]){
                nodes[i]->left = nodes[2 * i + 1];
            }
            if((2 * i + 2 < n) && nodes[2 * i + 2]){
                nodes[i]->right = nodes[2 * i + 2];
            }
        }
    }

    Node* root = nodes[0];

    int ans = leastCommonAncestor(root, t1, t2);
    cout<<ans<<endl;
    return 0;
}