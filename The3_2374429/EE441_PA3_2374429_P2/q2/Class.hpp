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

class HT_Item
{
    public :
        HT_Item(const Matrix& item,long det=0);
        Matrix key;
        long value;
};

long prob_fill(long x);
long get_hash(Matrix A);
void hash_fill(HT_Item* obj);
bool key_exists_hash(Matrix A);
long search_hash(Matrix A);
void insert_hash(Matrix A, long detA);
void find_cofactor_hash(Matrix &arr,Matrix &store,int n, int curr_row,int curr_col);
long find_det_hash(Matrix &A,int n);
void reset_table();


