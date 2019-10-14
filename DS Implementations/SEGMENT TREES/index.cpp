#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treenode)
{
    //base case
    if(start == end)
    {
        tree[treenode] = arr[start];
        return;
    }

    int mid = start + (end-start)/2;

    buildTree(arr,tree,start,mid,2*treenode);
    buildTree(arr,tree,mid+1,end,2*treenode+1);

    tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int* tree = new int[18];

    buildTree(arr,tree,0,8,1);

    for(int i = 1; i <= 18; i++)
        cout << tree[i] << endl;
}