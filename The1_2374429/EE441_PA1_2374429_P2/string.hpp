#include <iostream>
#include <cstring>

using namespace std;

void print_backwards(char const *a){
    int n=strlen(a);
    for(int i=n-1;i>=0;i--)cout << *(a+i); //traverse the string in the reverse order
    cout << endl;
}
