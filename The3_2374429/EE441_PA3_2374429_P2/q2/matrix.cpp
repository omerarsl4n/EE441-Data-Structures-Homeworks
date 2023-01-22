#include "Class.hpp"

Matrix::Matrix(int n){ // identity matrix constructor
    SIZE = n;
    if(SIZE!=0){
        for(int i=0;i<SIZE;i++){
           for(int j=0;j<SIZE;j++){
            if(i!=j)data[i][j]=0;
            else data[i][j]=1;
         }
       }
    }
}

int Matrix::getelement(int row, int col)const{
    if(row<SIZE && row>=0 && col<SIZE && col>=0){
        return data[row][col];
    }
    else cerr << "Invalid index input, check it again";
}
void Matrix::setelement(int setrow, int setcol,int value){
    if(setrow<SIZE && setrow>=0 && setcol<SIZE && setcol>=0){
            data[setrow][setcol] = value;
        }
    else cerr << "Invalid index input, check it again";
}

Matrix& Matrix::operator = (const Matrix &rhs){
    SIZE = rhs.SIZE;
    for(int i=0;i<SIZE;i++)for(int j=0;j<SIZE;j++)data[i][j]=rhs.getelement(i,j);
    return *this;
}

bool Matrix::operator == (const Matrix &rhs){
   if(SIZE != rhs.SIZE)return false;
   else{
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)if(data[i][j]!=rhs.data[i][j])return false;
    }
   }
   return true;
}

bool Matrix::operator < (const Matrix &rhs){
   if(SIZE < rhs.SIZE)return true;
   else{
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(data[i][j]!=rhs.data[i][j]){
                if(data[i][j]<rhs.data[i][j])return true;
                else return false;
            }
        }
    }
   }
   return false;
}

void Matrix::Info()const{
     for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++) cout << data[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

