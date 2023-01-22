#include <iostream>
#include <math.h>

#ifndef PRIME_HPP_INCLUDED
#define PRIME_HPP_INCLUDED

#define  max_prime_size 100000
using namespace std;

int prime_array[max_prime_size];
int index=1;

int check_prime(int n){
    if(n==2 || n==3)return 1;
    else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)return 0;     //normal check_prime implementation
        }
      return 1;
    }
}

void sieve_of_eratosthenes(){
        for(int i=2;i<sqrt(max_prime_size);i++){
            if(check_prime(i))prime_array[index++]=i; // if it is prime, write to prime_array
        }
}
int nth_prime(int n){
    return prime_array[n];
}


#endif // PRIME_HPP_INCLUDED
