#include <iostream>
#include "class.hpp"

using namespace std;

int count_BST_items = 0;

BST_Node::BST_Node(const Matrix& item, BST_Node *lptr, BST_Node *rptr, long det){
    key   = item;
    left  = lptr;
    right = rptr;
    value = det;
}

bool key_exists(Matrix A, BST_Node *root){  //search for key exist in the tree
    bool x;
    if(root == NULL)return false;
    if(root->key == A) return true;//
    else{
        if((root->key)< A)x = key_exists(A, root->right);
        else x = key_exists(A, root->left);
        return x;
    }
}

BST_Node* GetNode(Matrix item, BST_Node *lptr=NULL, BST_Node *rptr=NULL, long det=0){
    BST_Node *p;
    p = new BST_Node(item,lptr,rptr,det);
    return p;
}

void printTree(BST_Node *root){
    if(root!=NULL){
        printTree(root->left);
        cout << root->value <<" " ;
        printTree(root->right);
    }
}


void insert(Matrix A, long detA, BST_Node *root){   //It should be called with root!!

    if(root == NULL){   //no root case, you must initialize root beforehand
        return;
    }

    if(root->key == A){
        root->value = detA;
        return;
    }

    if(root->right == NULL && (root->key)< A)      {root->right = GetNode(A,NULL,NULL,detA); count_BST_items++; return;} //insert right
    else if(root->left==NULL && !((root->key)< A) ){root->left = GetNode(A,NULL,NULL,detA);  count_BST_items++; return;} //insert left
    else{
        if((root->key)< A){insert(A, detA, root->right);}
        else              {insert(A, detA, root->left);}
    }
}

long search(Matrix A, BST_Node *root){  //after knowing the matrix A is exist in the tree, search for det value of the matrix
    long x;
    if(root == NULL)return -1;
    if(root->key == A) return root->value;
    else{
        if((root->key)< A)x = search(A, root->right);
        else x = search(A, root->left);
    }
    return x;
}

void find_cofactor(Matrix &arr,Matrix &store,int n, int curr_row,int curr_col){
    int store_array_row_index = 0;
    int store_array_col_index = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            //Classical way of finding cofactor, close the row and column belongs to i and j and send it others to n-1 matrix
            if(curr_row == i || curr_col ==j)continue;
            store.setelement(store_array_row_index,store_array_col_index,arr.getelement(i,j));
            store_array_col_index +=1;
            if(store_array_col_index == n-1){
                store_array_row_index +=1;
                store_array_col_index =0;
            }

        }
    }
}

long find_det(Matrix &A,int n, BST_Node* root){

    if(key_exists(A,root))return search(A,root);
    else{
        long result = 0; // initilization of result
        long sign = 1;
        long temp;

        if (n==1) return A.getelement(0,0); //stopping condition

        for(int i=0;i<n;i++){
            Matrix cofactor_arr(A.SIZE-1);
            find_cofactor(A,cofactor_arr,n,0,i); // since we only need the first row cofactors to calculate determinant
            temp = find_det(cofactor_arr,n-1,root);
            result += A.getelement(0,i) * temp * sign; //find and add the [n-1][n-1] matrix determinant, it is indeed recursive step.
            sign = sign * -1;
        }
       // count_BST_items++;
        insert(A,result,root);
        return result;
    }
}
