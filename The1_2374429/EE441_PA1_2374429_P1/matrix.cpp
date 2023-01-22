#include "matrix.hpp"

template <int N>
Matrix <N>::Matrix(){ // identity matrix constructor
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j)data[i][j]=0;
            else data[i][j]=1;
        }
    }
}

/*
template <int N>
Matrix <N>::Matrix(const Matrix <N> &obj){ // copy constructor
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            data[i][j]=obj.getelement(i,j);
        }
    }
}
*/
template <int N>
double Matrix<N>::getelement(int row, int col)const{ // getter
    if(row<N && row>=0 && col<N && col>=0){
        return data[row][col];
    }
    else cerr << "Invalid index input, check it again";
}

template <int N>
void Matrix<N>::setelement(int setrow, int setcol,double value){ //setter
    if(setrow<N && setrow>=0 && setcol<N && setcol>=0){
            data[setrow][setcol] = value;
        }
    else cerr << "Invalid index input, check it again";

}


template <int N>
void Matrix<N>::Info()const{   // for debugging purposes and printing the data
   for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout << data[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

