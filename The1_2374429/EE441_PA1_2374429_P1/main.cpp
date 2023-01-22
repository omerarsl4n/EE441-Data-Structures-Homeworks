#include "matrix.cpp"

template <int N>
Matrix<N> add_array(Matrix<N>  &arr1, Matrix<N> &arr2){
    Matrix<N> temp_mat;
    double temp=0;
    for(int i=0;i<arr1.SIZE;i++){
        for(int j=0;j<arr2.SIZE;j++){
            temp = arr1.getelement(i,j)+arr2.getelement(i,j); //it is direct addition with the index
            temp_mat.setelement(i,j,temp);
        }
    }
    return temp_mat;
}


template <int N>
Matrix<N>  sub_array(Matrix<N>  &arr1, Matrix<N> &arr2){
    Matrix<N> temp_mat;
    double temp=0;
    for(int i=0;i<arr1.SIZE;i++){
        for(int j=0;j<arr2.SIZE;j++){
            temp = arr1.getelement(i,j)-arr2.getelement(i,j); // it is direct subtraction with the index
            temp_mat.setelement(i,j,temp);
        }
    }
    return temp_mat;
}

template <int N>
Matrix<N> multiply_array(Matrix<N>  &arr1, Matrix<N> &arr2){
    double temp=0;
    Matrix<N> temp_mat;
    for(int i=0;i<arr1.SIZE;i++){
        for(int j=0;j<arr2.SIZE;j++){
            temp=0;
            for(int k=0;k<arr1.SIZE;k++)temp += arr1.getelement(i,k)*arr2.getelement(k,j);// simple matrix multiplication expansion for square matrix is worked on O(n^3)
            temp_mat.setelement(i,j,temp);
        }
    }
    return temp_mat;
}

template <int N>
void find_cofactor(Matrix<N> &arr,Matrix<N> &store,int n, int curr_row,int curr_col){
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

template <int N>
int find_det(Matrix<N> &arr1){
    int res = calc_det(arr1,arr1.SIZE); //sake of simplicity
    return res;
}

template <int N>
int calc_det(Matrix<N> &arr1,int n){
    int result = 0; // initilization of result
    int sign = 1;
    if (n==1) return arr1.getelement(0,0); //stopping condition
    Matrix<N> cofactor_arr;

    for(int i=0;i<n;i++){
        find_cofactor(arr1,cofactor_arr,n,0,i); // since we only need the first row cofactors to calculate determinant
        result += arr1.getelement(0,i) * calc_det(cofactor_arr,n-1)*sign; //find and add the [n-1][n-1] matrix determinant, it is indeed recursive step.
        sign = sign * -1;
    }
    return result;
}


int main(void){

Matrix<3> arr_try1;
Matrix<3> arr_try2;
Matrix<3> arr_try3;                 //TEST OF EACH FUNCTION FOR MY DEBUGGING
Matrix<3> arr_try4;
Matrix<3> arr_try5;
Matrix<4> arr_try6;
// ADD SUB MUL TEST
arr_try3 = add_array(arr_try1,arr_try2);
arr_try3.Info();
arr_try3.setelement(2,2,5);
arr_try3.setelement(1,2,5);
arr_try3.setelement(3,2,5);
arr_try3.Info();
arr_try2.Info();
arr_try4 = sub_array(arr_try3,arr_try2);
arr_try4.Info();
arr_try3.Info();
arr_try5 = multiply_array(arr_try3,arr_try4);
arr_try5.Info();

//DETEMINANT TEST
arr_try1.setelement(0,1,2.0);
arr_try1.setelement(0,2,3.0);
arr_try1.setelement(1,0,4.0);
arr_try1.setelement(1,1,5.0);
arr_try1.setelement(1,2,10.0);
arr_try1.setelement(2,0,12.0);
arr_try1.setelement(2,1,8.0);
arr_try1.setelement(2,2,9.0);
arr_try1.Info();

int x = find_det(arr_try1);
cout << x;

 return 0;
}


