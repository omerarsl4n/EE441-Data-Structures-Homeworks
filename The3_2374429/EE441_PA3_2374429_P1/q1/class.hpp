#include <iostream>

using namespace std;

class Matrix {
    private:
        int data[20][20];
    public:
        Matrix(int n=0);
        //Matrix (const Matrix<N> &obj);
        Matrix& operator = (const Matrix &rhs);
        bool operator == (const Matrix &rhs);
        bool operator < (const Matrix &rhs);
        int SIZE;
        int getelement(int row, int col)const;
        void setelement(int setrow, int setcol,int value);
        void Info()const;
};

class BST_Node
{
    public :
        BST_Node(const Matrix& item, BST_Node *lptr = NULL, BST_Node *rptr = NULL, long det=0);
        BST_Node* left;
        BST_Node* right;
        // Determinant of key matrix is value
        Matrix key;
        long value;
};

bool key_exists(Matrix A, BST_Node *root);
BST_Node* GetNode(Matrix item, BST_Node *lptr, BST_Node *rptr, long det);
void printTree(BST_Node *root);
void insert(Matrix A, long detA, BST_Node *root);
long search(Matrix A, BST_Node *root);
void find_cofactor(Matrix &arr,Matrix &store,int n, int curr_row,int curr_col);
long find_det(Matrix &A,int n, BST_Node* root);



