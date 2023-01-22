#include "StackQueue.cpp"
#include "Maze.hpp"


void two_pass_maze_solver(Maze &x){ //SOLN OF MAZE IS IMPLEMENTED HERE
    StackQueue<char> data;
    Maze y(x); //COPY CONSTRUCTOR FOR SECOND PASS
    bool flag;
    cout << "First Pass:" << endl;
    while(!x.is_solved()){
    flag = true;
    cout << "SQ: ";
    data.print_info();
    x.print_state();
        if(x.can_move_left()){
            //cout << "L" << endl;
            if(data.mycount >1 && data.peek_front() == 'B'){
                char temp = data.pop_front();       //FRONT SIDE USED AS STACK REAR IN MY IMPLEMENTATION, SO FIRST STACK THE DATAS FROM FRONT, AND POP FROM FRONT FOR STACK IMP
                if(data.peek_front() == 'L'){
                    data.pop_front();
                    data.push_front('F');
                    flag = false;
                }
                else if(data.peek_front() == 'F'){
                    data.pop_front();
                    data.push_front('R');
                    flag = false;
                }
                else if(data.peek_front() == 'R'){
                    data.pop_front();
                    data.push_front('B');
                    flag = false;
                }
                else data.push_front(temp);
            }

            if(flag)data.push_front('L');
            x.move_left();
        }

        else if(x.can_move_forward()){
            // cout << "F" << endl;
            if(data.mycount > 1 && data.peek_front() == 'B'){
                char temp = data.pop_front();
                if(data.peek_front() == 'L'){
                    data.pop_front();
                    data.push_front('R');
                    flag = false;
                }

                else if(data.peek_front() == 'F'){
                    data.pop_front();
                    data.push_front('B');
                    flag = false;
                }

                else data.push_front(temp);
            }
            if(flag)data.push_front('F');
            x.move_forward();
        }

        else if (x.can_move_right()){
              //  cout << "R" << endl;
            if(data.mycount > 1 && data.peek_front() == 'B'){
                char temp = data.pop_front();
                if(data.peek_front() == 'L'){
                    data.pop_front();
                    data.push_front('B');
                    flag = false;
                }
                else data.push_front(temp);
            }
           if(flag) data.push_front('R');
            x.move_right();
        }

        else if(x.can_move_back()){
           // cout << "B" << endl;
            data.push_front('B');
            x.move_back();
        }

    }
    cout << "Maze is solved." << endl;

    cout << "Second pass:" << endl;

    while(!y.is_solved()){
        cout << "SQ: ";
        data.print_info();
        y.print_state();
        char temp = data.pop_rear();     //REAR SIDE USED AS QUEUE FRONT IN MY IMPLEMENTATION, FIRST I STACKED THE DATAS FROM THE FRONT AS A STACK THEN, I TAKE THEM IN REVERSE DIRECTION i.e from rear
        if (temp == 'L') y.move_left();
        else if(temp == 'F') y.move_forward();
        else if(temp == 'R') y.move_right();
        else if(temp == 'B') y.move_back();
    }
    cout << "SQ: " << endl;
    y.print_state();

}

int main(){
    Maze x;
    two_pass_maze_solver(x);
    return 0;
}




