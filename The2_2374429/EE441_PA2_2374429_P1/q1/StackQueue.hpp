#include <iostream>

using namespace std;

const int MaxQuStSize=1024;

template <class T>
class StackQueue{
    private:
        T stqlist[MaxQuStSize];
        int myfront, myrear;

    public:
        int mycount;
        StackQueue();

        void push_front(const T& item);
        void push_rear(const T& item);
        T pop_front(void);
        T pop_rear(void);
        T peek_front(void)const;
        void print_info(void)const;
};
