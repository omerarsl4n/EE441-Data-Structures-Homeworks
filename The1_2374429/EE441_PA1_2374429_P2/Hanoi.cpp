#include <iostream>
#include "Hanoi.hpp"
using namespace std;


Disc::Disc(int dim):mdim(dim){}

Hanoi::Hanoi(int x){
    int temp=x;
    top_in0=x;
    for(int i=0;i<x;i++){
        Disc A(temp--);
        rod0[i]=A.mdim;
    }
}

void Hanoi::print_info()const{
    for(int i=0;i<20;i++)cout <<rod0[i]<<" ";
    cout << endl;
    for(int i=0;i<20;i++)cout <<rod1[i]<<" ";
    cout << endl;
    for(int i=0;i<20;i++)cout <<rod2[i]<<" ";
    cout << endl;
}

int Hanoi::find_num_disc()const{
    int x=0;
    for(int i=0;i<20;i++){
        if(rod0[i]!=0)x++;
        else break;
    }
    return x;
}

void Hanoi::move_h(int from, int to){
    //cout << rod0[top_rod0] << " " << rod1[top_rod1] << " "<<rod2[top_rod2]<<endl;
    if( (from<0) || (from>2) || (to<0) || (to>2) || (from==to))cout<<"Indices are not valid."; //check undefined index

    if(from ==0){
        if(top_in0==0) cerr << "it is illegal." << endl; // if there is no disc you cant move aynthing

        else if(to==1 && top_in1==0){    // if receiver rod has no disc no need to check inputs
            rod1[top_in1]=rod0[top_in0-1];
            cout << "Disc "<<rod0[top_in0-1]<<" is moved from Rod 0 to Rod 1"<<endl;
            rod0[top_in0-1]=0;
            top_in1+=1; // it holds top index of rod1
            top_in0-=1; // it holds top index of rod0
        }
        else if(to==1 && rod0[top_in0-1]<rod1[top_in1-1]){  //now check that the input magnitude for proper hanoi algorithm
            rod1[top_in1]=rod0[top_in0-1];
            cout << "Disc "<<rod0[top_in0-1]<<" is moved from Rod 0 to Rod 1"<<endl;
            rod0[top_in0-1]=0;
            top_in1+=1;
            top_in0-=1;
        }
        else if(to==2 && top_in2==0){
            rod2[top_in2]=rod0[top_in0-1];
            cout << "Disc "<<rod0[top_in0-1]<<" is moved from Rod 0 to Rod 2"<<endl;
            rod0[top_in0-1]=0;
            top_in2+=1; // it holds top index of rod2
            top_in0-=1;
        }
        else if(to==2 && rod0[top_in0-1]<rod2[top_in2-1]){
            rod2[top_in2]=rod0[top_in0-1];
            cout << "Disc "<<rod0[top_in0-1]<<" is moved from Rod 0 to Rod 2"<<endl;
            rod0[top_in0-1]=0;
            top_in2+=1;
            top_in0-=1;
        }
        else cerr << "it is illegal." << endl;
    }

    if(from ==1){ // just same conditional block as the first one but this time it comes from 1
        if(top_in1==0)cout << "it is illegal." << endl; // if there is no disc you cant move aynthing

        else if(to==0 && top_in0==0){
            rod0[top_in0]=rod1[top_in1-1];
            cout << "Disc "<<rod1[top_in1-1]<<" is moved from Rod 1 to Rod 0"<<endl;
            rod1[top_in1-1]=0;
            top_in0+=1;
            top_in1-=1;
        }
        else if(to==0 && rod1[top_in1-1]<rod0[top_in0-1]){
            rod0[top_in0]=rod1[top_in1-1];
            cout << "Disc "<<rod1[top_in1-1]<<" is moved from Rod 1 to Rod 0"<<endl;
            rod1[top_in1-1]=0;
            top_in0+=1;
            top_in1-=1;
        }
        else if(to==2 && top_in2==0){
            rod2[top_in2]=rod1[top_in1-1];
            cout << "Disc "<<rod1[top_in1-1]<<" is moved from Rod 1 to Rod 2"<<endl;
            rod1[top_in1-1]=0;
            top_in2+=1;
            top_in1-=1;
        }
        else if(to==2 && rod1[top_in1-1]<rod2[top_in2-1]){
            rod2[top_in2]=rod1[top_in1-1];
            cout << "Disc "<<rod1[top_in1-1]<<" is moved from Rod 1 to Rod 2"<<endl;
            rod1[top_in1-1]=0;
            top_in2+=1;
            top_in1-=1;
        }
        else cerr << "it is illegal." << endl;
    }

    if(from ==2){ // just same conditional block as the first one but this time it comes from 2
        if(top_in2==0) cout << "it is illegal." << endl; // if there is no disc you cant move aynthing


        else if(to==1 && top_in1==0){
            rod1[top_in1]=rod2[top_in2-1];
            cout << "Disc "<<rod2[top_in2-1]<<" is moved from Rod 2 to Rod 1"<<endl;
            rod2[top_in2-1]=0;
            top_in1+=1;
            top_in2-=1;
        }

        else if(to==1 && rod2[top_in2-1]<rod1[top_in1-1]){
            rod1[top_in1]=rod2[top_in2-1];
            cout << "Disc "<<rod2[top_in2-1]<<" is moved from Rod 2 to Rod 1"<<endl;
            rod2[top_in2-1]=0;
            top_in1+=1;
            top_in2-=1;
        }
        else if(to==0 && top_in0==0){
            rod0[top_in0]=rod2[top_in2-1];
            cout << "Disc "<<rod2[top_in2-1]<<" is moved from Rod 2 to Rod 0"<<endl;
            rod2[top_in2-1]=0;
            top_in0+=1;
            top_in2-=1;
        }
        else if(to==0 && rod2[top_in2-1]<rod0[top_in0-1]){
            rod0[top_in0]=rod2[top_in2-1];
            cout << "Disc "<<rod2[top_in2-1]<<" is moved from Rod 2 to Rod 0"<<endl;
            rod2[top_in2-1]=0;
            top_in0+=1;
            top_in2-=1;
        }
        else cerr << "it is illegal." << endl;
    }


}

void real_soln_hanoi(int n, Hanoi &trial,int start_rod, int helper_rod,int end_rod){
    if (n==1){// stopping condition for recursion
            trial.move_h(start_rod,end_rod);
            return;
    }
    real_soln_hanoi(n - 1, trial,start_rod, end_rod, helper_rod); // in our case it corresponds to shift top n-1 disc from 1st rod to 2nd rob by utilizing third one
    //trial.print_info(); // just for debugging
    trial.move_h(start_rod,end_rod); // move biggest(nth one) disc to rod 3
    real_soln_hanoi(n - 1, trial,helper_rod, start_rod, end_rod);//then gather remaining n-1 discs to third rod by utilizing the first one
}

void solve_hanoi(Hanoi &game){
    int num = game.find_num_disc();
    real_soln_hanoi(num,game,0,1,2);// at first I wrote solution for general, then I just used for this special case start=0, helper=1,end=2
}


//int main()
//{
//    int n=5;
//    Hanoi trial_arr(n);
//    /*trial_arr.print_info();
//    trial_arr.move_h(0,1);
//    trial_arr.move_h(1,2);
//    trial_arr.move_h(0,1);
//    trial_arr.move_h(0,2);                    ////testign for move_h function
//    trial_arr.print_info();
//    trial_arr.move_h(2,1);
//    trial_arr.move_h(1,0);
//    trial_arr.move_h(1,2);
//    trial_arr.move_h(0,2);
//    trial_arr.print_info();*/
//    trial_arr.print_info();
//    solve_hanoi(trial_arr);
//    trial_arr.print_info();
//    return 0;
//}

