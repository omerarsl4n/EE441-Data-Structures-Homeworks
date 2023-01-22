#include <iostream>
#include "Class.hpp"
#define mod 65536


HT_Item *arr[mod]={0};
int count = 0;
int detmy=0,detcp=0;

HT_Item::HT_Item(const Matrix& item, long det){
    key = item;
    value = det;
}

long prob_fill(long x){
    long y=x;
    x=(x+1)%mod;
    while(arr[x]!=0 && y!=x){   //lineer probing until the current location
         x=(x+1)%mod;
    }
    return x;
}

long get_hash(Matrix A){        //calculate the hash value of A using the given formula
    int n = A.SIZE;
    long temp = n;

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp = ((61*temp) + A.getelement(i,j)) % mod ;
        }
    }
    return temp%mod;
}

void hash_fill(HT_Item* obj){
    int n = obj->key.SIZE;
    long temp = get_hash(obj->key);
    if(arr[temp%mod]!=0)temp = prob_fill(temp%mod);
    arr[temp%mod] = obj;    // fill the hash after the probing if it is needed.
}

bool key_exists_hash(Matrix A){
    bool x;
    long hash_value = get_hash(A);  //get the hash first

    if(arr[hash_value] == 0)return false;

    if(arr[hash_value]->key == A)return true;
    else{
        long temp= (hash_value+1)%mod;
        while(temp!=hash_value){        //lineer probing until empty location or finding the hash.
            if(arr[temp]==0)return false;
            if(arr[temp]->key == A)return true;
            else temp= (temp+1) % mod;
        }
        return false;
    }
}

long search_hash(Matrix A){         // in this time we know it is exist, just search for the det value of the matrix A in the table.
    long hash_value = get_hash(A);
    //if(arr[hash_value]==0)return -1;  // in case of not exist, but it should not called before checking of existence of any matrix.
    if(arr[hash_value]->key == A)return arr[hash_value]->value;
    else{
        long temp= (hash_value+1)%mod;
        while(temp!=hash_value){
            if(arr[temp]->key == A)return arr[temp]->value;
            else temp= (temp+1) % mod;
        }
    }

}

void insert_hash(Matrix A, long detA){//get new dynamic class from the memory and add to hash table
    if(key_exists_hash(A))return;
    HT_Item* p;
    p = new HT_Item(A,detA);
    hash_fill(p);
    count++;    //increase count
    if(count==mod)cout << "Table is FULL";
}

void reset_table(){ //Delete all items in the table
    for(int i=0;i<mod;i++)arr[i] = 0;
    count = 0;
}


void find_cofactor_hash(Matrix &arr,Matrix &store,int n, int curr_row,int curr_col){
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

long find_det_hash(Matrix &A,int n){

    long result = 0; // initilization of result
    long sign = 1;

    if(key_exists_hash(A))return search_hash(A);
    else{
        if (n==1) return A.getelement(0,0); //stopping condition
        for(int i=0;i<n;i++){
            Matrix cofactor_arr(A.SIZE-1);
            find_cofactor_hash(A,cofactor_arr,n,0,i); // since we only need the first row cofactors to calculate determinant
            long subdet = find_det_hash(cofactor_arr,n-1);
            result += A.getelement(0,i) * subdet * sign; //find and add the [n-1][n-1] matrix determinant, it is indeed recursive step.
            sign = sign * -1;
        }
    }
    insert_hash(A,result);

    return result;
}

