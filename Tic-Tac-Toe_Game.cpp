#include<iostream>
#include<cstdlib>
using namespace std;
char board[9]= {'1','2','3','4','5','6','7','8','9'};

void show_board(){
    cout<<"\n";
    cout<<"\t"<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<endl;
    cout<<"\t--|---|---"<<endl;
    cout<<"\t"<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<endl;
    cout<<"\t--|---|---"<<endl;
    cout<<"\t"<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
    cout << endl;
}

bool check_win() {
    //for Row check
    if(board[0]== board[1] && board[1]== board[2])return true;
    if(board[3]== board[4] && board[4]== board[5])return true;
    if(board[6]== board[7] && board[7]== board[8])return true;
    //for Column check
    if(board[0]== board[3] && board[3]== board[6])return true;
    if(board[1]== board[4] && board[4]== board[7])return true;
    if(board[2]== board[5] && board[5]== board[8])return true;
    //for Diagonal check
    if(board[0]== board[4] && board[4]== board[8])return true;
    if(board[2]== board[4] && board[4]== board[6])return true;
    return false;
}

int main() {
    int move;
    char turn='X';
    for(int i=0; i<9; i++) {
        show_board();
        cout<<"  Player "<<turn<<" enter your move(1-9): ";
        cin>>move;
        if(move>9 || move<1 || board[move-1]=='X' || board[move-1]=='O') {
            cout << "  Invalid move! please try again move(1-9): ";
            cin>>move;
        }
        board[move-1]= turn;
        if(check_win()){
            show_board();
            cout << "  Player " <<turn<<" wins!"<< endl;
            return 0;
        }
        turn= (turn=='X') ?'O':'X';
    }
    show_board();
    cout << "  It's a Draw!\n" << endl;
    return 0;
}