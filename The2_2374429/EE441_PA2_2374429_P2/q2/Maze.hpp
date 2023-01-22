#include <iostream>

using namespace std;

class Maze{
    protected:
        char arr[20][20];
        int nrow,ncol,curr_row,curr_col,frow,fcol;
    public:
        Maze();
        Maze(const Maze &obj);
        bool can_move_left()const;
        bool can_move_forward()const;
        bool can_move_right()const;
        bool can_move_back()const;
        void move_left();
        void move_forward();
        void move_right();
        void move_back();
        void print_state()const;
        bool is_solved()const;
};



