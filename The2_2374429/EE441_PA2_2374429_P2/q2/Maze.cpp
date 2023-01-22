#include "Maze.hpp"
#include <fstream>

Maze::Maze(){
 /* reading the maze from file */
 ifstream input_file; /* input file stream */
 input_file.open ("input_maze.txt");
 input_file >> nrow >> ncol; /* read the size from file */

 for(int i=0; i<nrow; ++i){
    for(int j=0; j<ncol; ++j){
        input_file >> arr[i][j];
        if(arr[i][j] == 'W' || arr[i][j] == 'N' || arr[i][j] == 'E' || arr[i][j] == 'S'){
            curr_row = i;
            curr_col = j;
        }
        if(arr[i][j] == 'T'){
            frow = i;
            fcol = j;
        }
    }
 }
 input_file.close();
}

Maze::Maze(const Maze &obj){
    nrow = obj.nrow;
    ncol = obj.ncol;
    curr_row = obj.curr_row;
    curr_col = obj.curr_col;
    frow = obj.frow;
    fcol = obj.fcol;
    for(int i=0; i<nrow; ++i){
        for(int j=0; j<ncol; ++j){
            arr[i][j] = obj.arr[i][j];
        }
    }
}

bool Maze::can_move_left()const{
    if(arr[curr_row][curr_col] == 'W'){
        if(curr_row + 1 <= nrow && arr[curr_row+1][curr_col] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'N'){
        if(curr_col - 1 >= 0 && arr[curr_row][curr_col-1] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        if(curr_row - 1 >= 0 && arr[curr_row-1][curr_col] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        if(curr_col + 1 <= ncol && arr[curr_row][curr_col+1] != '#')return true;
        else return false;
    }

}

bool Maze::can_move_right()const{
    if(arr[curr_row][curr_col] == 'W'){
        if(curr_row -1 >= 0 && arr[curr_row-1][curr_col] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'N'){
        if(curr_col + 1 <= ncol && arr[curr_row][curr_col+1] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        if(curr_row + 1 <= nrow && arr[curr_row+1][curr_col] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        if(curr_col - 1 >= 0 && arr[curr_row][curr_col-1] != '#')return true;
        else return false;
    }

}

bool Maze::can_move_back()const{
    if(arr[curr_row][curr_col] == 'W'){
        if(curr_col + 1 <= ncol && arr[curr_row][curr_col+1] != '#')return true;
        else return false;
    }

     else if(arr[curr_row][curr_col] == 'N'){
        if(curr_row +1 <= nrow && arr[curr_row+1][curr_col] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        if(curr_col - 1 >= 0 && arr[curr_row][curr_col-1] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        if(curr_row - 1 >= 0 && arr[curr_row-1][curr_col] != '#')return true;
        else return false;
    }

}

bool Maze::can_move_forward()const{
    if(arr[curr_row][curr_col] == 'W'){
        if(curr_col - 1 >= 0 && arr[curr_row][curr_col-1] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'N'){
        if(curr_row -1 >= 0 && arr[curr_row-1][curr_col] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        if(curr_col + 1 <= ncol && arr[curr_row][curr_col+1] != '#')return true;
        else return false;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        if(curr_row + 1 <= nrow && arr[curr_row+1][curr_col] != '#')return true;
        else return false;
    }

}

void Maze::move_back(){
    if(!can_move_back())return;

    if(arr[curr_row][curr_col] == 'W'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col+1] = 'E';
        curr_col = curr_col+1;
    }

    else if(arr[curr_row][curr_col] == 'N'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row+1][curr_col] = 'S';
        curr_row = curr_row +1;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col-1] = 'W';
        curr_col = curr_col - 1;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row-1][curr_col] = 'N';
        curr_row = curr_row - 1;
    }
}

void Maze::move_forward(){
    if(!can_move_forward())return;

    if(arr[curr_row][curr_col] == 'W'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col-1] = 'W';
        curr_col = curr_col - 1;
    }

    else if(arr[curr_row][curr_col] == 'N'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row-1][curr_col] = 'N';
        curr_row = curr_row - 1;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col+1] = 'E';
        curr_col = curr_col+1;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row+1][curr_col] = 'S';
        curr_row = curr_row +1;
    }

}
void Maze::move_right(){
    if(!can_move_right())return;

    if(arr[curr_row][curr_col] == 'W'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row-1][curr_col] = 'N';
        curr_row = curr_row - 1;
    }

    else if(arr[curr_row][curr_col] == 'N'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col+1] = 'E';
        curr_col = curr_col+1;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row+1][curr_col] = 'S';
        curr_row = curr_row +1;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col-1] = 'W';
        curr_col = curr_col - 1;
    }
}

void Maze::move_left(){
    if(!can_move_left())return;

    if(arr[curr_row][curr_col] == 'W'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row+1][curr_col] = 'S';
        curr_row = curr_row +1;
    }

    else if(arr[curr_row][curr_col] == 'N'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col-1] = 'W';
        curr_col = curr_col - 1;
    }

    else if(arr[curr_row][curr_col] == 'E'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row-1][curr_col] = 'N';
        curr_row = curr_row - 1;
    }

    else if(arr[curr_row][curr_col] == 'S'){
        arr[curr_row][curr_col] = '.';
        arr[curr_row][curr_col+1] = 'E';
        curr_col = curr_col+1;
    }
}

void Maze::print_state()const{
   for(int i=0; i<nrow; ++i){
    for(int j=0; j<ncol; ++j){
        cout << arr[i][j];
    }
    cout << endl;
 }
    cout << endl;
}

bool Maze::is_solved()const{
    if( (curr_row == frow) && (curr_col == fcol) )return true;
    else return false;
}
