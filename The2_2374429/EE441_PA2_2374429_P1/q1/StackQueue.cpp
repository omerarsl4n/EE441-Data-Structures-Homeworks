#include "StackQueue.hpp"

template <class T>
StackQueue<T>::StackQueue(){    //Initialize rear and front values according to implementation
    myfront = 0;
    myrear = -1;
    mycount = 0;
}
/*
 //friend StackQueue<T>& operator << (ostream& out, const StackQueue<T> &data);
template <class T>
ostream& operator<<(ostream& out, const StackQueue<T> &data){
    for(int i=data.myrear;i<data.mycount;){
        out << data.stqlist[i] << " ";
        i = (i -1 + MaxQuStSize) % MaxQuStSize ;
    }
    out << "\n";
    return out;
}
*/


template <class T>
void StackQueue<T>::print_info()const{
    int i = (myrear+ MaxQuStSize) % MaxQuStSize;    //CIRCULAR STACKQUEUE
    for(int a=mycount;a>0;a--){
        cout << stqlist[i] << " ";
        i = (i -1 + MaxQuStSize) % MaxQuStSize ;
    }
    cout << endl;
}


template <class T>
void StackQueue<T>::push_front(const T& item){
    if(mycount == MaxQuStSize) {cerr<<"StackQueue overflow!" <<endl;  exit(1);}
    mycount++;
    myfront=(myfront - 1 + MaxQuStSize)% MaxQuStSize;//CIRCULAR STACKQUEUE
    stqlist[myfront] = item;

}


template <class T>
void StackQueue<T>::push_rear(const T& item){
    if(mycount == MaxQuStSize) {cerr<<"StackQueue overflow!" <<endl;  exit(1);}
    mycount++;
    myrear=(myrear+1)% MaxQuStSize;
    stqlist[myrear] = item;

}

template <class T>
T StackQueue<T>::pop_front(void){
    T temp;
    if (mycount==0){cerr<<"Deleting from an empty stackqueue from front!"<<endl;}
    temp = stqlist[myfront];
    mycount--;
    myfront=(myfront+1) % MaxQuStSize;
    return temp;
}

template <class T>
T StackQueue<T>::pop_rear(void){
    T temp;
    if (mycount==0){cerr<<"Deleting from an empty stackqueue from rear!"<<endl;}
    temp = stqlist[(myrear+ MaxQuStSize) % MaxQuStSize];
    mycount--;
    myrear=(myrear -1 + MaxQuStSize) % MaxQuStSize ; //because of circular operation
    return temp;
}

template <class T>
T StackQueue<T>::peek_front(void)const{
    T temp;
    if (mycount==0){cerr<<"Empty stackqueue"<<endl;}
    temp = stqlist[myfront];
    return temp;
}

/*  SOME TESTS FOR STACKQUEUE IMPLEMENTATION
int main(){
    StackQueue<char> A;
    int x;
    A.push_front('A');
    A.push_front('B');
    A.push_front('C');
    A.push_front('D');
    A.push_front('E');
    A.print_info();
    cout << A.pop_front() << endl;
    A.print_info();
    cout << A.pop_front() << endl;
    A.print_info();
    cout << A.pop_front() << endl;
    A.print_info();
    cout << A.pop_front() << endl;
    A.print_info();

    return 0;
}
*/
