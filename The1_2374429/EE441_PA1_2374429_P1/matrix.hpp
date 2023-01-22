#include <iostream>

using namespace std;

template <int N> class Matrix {
    private:
        double data[N][N];
    public:
        Matrix();
        //Matrix (const Matrix<N> &obj);
        Matrix<N>& operator = (const Matrix <N> &rhs){
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)data[i][j]=rhs.getelement(i,j);
        }

        int const SIZE = N;
        double getelement(int row, int col)const;
        void setelement(int setrow, int setcol,double value);
        void Info()const;

};


