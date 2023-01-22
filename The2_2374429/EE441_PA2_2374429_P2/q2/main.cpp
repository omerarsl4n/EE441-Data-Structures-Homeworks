#include "Maze.hpp"
#include "Node.cpp"

template <class T>
class wrapper{  //WRAPPER FUNCTION TO PORTABILITY OF QUESTION 1 SOLN
    private :
        Node<T> *head = NULL, *rear = NULL;

    public :
        int mycount;
        wrapper(){
            mycount = 0;
        }
        void push_front(T data){
            push_frontn(head,rear,data);//With the postfix n means node class implementation
            mycount++;
        }
        void push_rear(T data){
            push_rearn(head,rear,data);//With the postfix n means node class implementation
            mycount++;
        }
        T pop_front(void){
            T a=pop_frontn(head,rear);//With the postfix n means node class implementation
            mycount--;
            return a;
        }

        T pop_rear(void){
            T a=pop_rearn(head,rear);//With the postfix n means node class implementation
            mycount--;
            return a;
        }

        T peek_front(void){
            T a=peek_frontn(head);//With the postfix n means node class implementation
            return a;
        }
        void print_info(){
            printList(rear);
        }
};

void two_pass_maze_solver(Maze &x){
    wrapper<char> data; //!FOR THE SECOND PART WRAPPER CLASS IS USED TO CONVERT Q1SOLNT TO THIS ONE.
    bool flag;          //!Remaining code is exactly similar to my part1 soln except data is an object to wrapper class, and this class utilizes xor doubly linked list implemented in the part2 Q1
    Maze y(x); //COPY CONSTRUCTOR FOR SECOND PASS
    cout << "First Pass:" << endl;
    while(!x.is_solved()){
    flag = true;
    cout << "SQ: ";
    data.print_info();
    x.print_state();
        if(x.can_move_left()){
            //cout << "L" << endl;
            if(data.mycount >1 && data.peek_front() == 'B'){
                char temp = data.pop_front();
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
        char temp = data.pop_rear();
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
