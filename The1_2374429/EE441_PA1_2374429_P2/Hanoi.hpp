#include <iostream>
using namespace std;

class Disc{
    public:
        int mdim;
        Disc(int diameter=0);
};


class Hanoi{
    private:
        int rod0[20]={0};
        int rod1[20]={0};
        int rod2[20]={0};
    public:
        Hanoi(int x);
        int top_in0=0,top_in1=0,top_in2=0;
        int find_num_disc()const;
        void move_h(int from, int to);
        void print_info()const;
};

void solve_hanoi(Hanoi &game);
