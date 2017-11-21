#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int j = 0;

void print_board(int board[64]){
	cout << "  a b c d e f g h  " << endl;
    for(int i=0; i<8; i++){
        cout << i + 1;
        cout << " ";
	    for(int j=0; j<8; j++){
		    if(board[(8*i)+j]==0)
		    	cout << ". ";
		    else if(board[(8*i)+j]==1)	//Le joueur noir est caractérisé par l'entier 1 et les "X"
		    	cout << "X ";
		    else if(board[(8*i)+j]==2)	//Le joueur blanc est caractérisé par l'entier 2 et les "O"
		    	cout << "O ";
	    }
        cout << i+1 << endl;
    }
	cout << "  a b c d e f g h  " << endl;
}

void init_board(int* board){
    
	for(int i = 0; i<64; i++){
		if( i == 27 || i == 36)
			*(board + i) = 2;
		else if (i == 28 || i == 35)
			*(board + i) = 1;
		else
			*(board + i) = 0;
	}
}

bool check_input(int* board, int x, int y){
    if(x>8 || x<0 || y>8 || y < 0){
        cout << "invalid position" <<endl;
        return false;
    }
    
    else if(*(board + ((8*(x))+(y))) != 0){
        cout << "invalid position" <<endl;
        return false;
    }
    else
        return true;

}

bool check_direction(int position, int* board, int direction, int turn,int* pos_eat){

    if(position + direction >= 0 && position + direction < 63){
        if(*(board + position + direction) == turn){
            *(pos_eat + j) = position;
            for(int i =0; i<=j;i++)
                *(board + *(pos_eat + i)) = turn;
            return true;
        }
        else if (*(board + position + direction) == 0)
            return false;
        else{ 
            *(pos_eat + j) = position;
            j++;
            return check_direction(position + direction, board, direction,turn, pos_eat);  
        }
    }
}

bool check_eat(int position, int* board, int turn){
    int direction[8] = {1,-1,7,-7,8,-8,9,-9};
    bool eat = false;
    for(int i = 0; i<8; i++){
        int pos_eat[6] = {0};
        j = 0;
        if(position + direction[i] >= 0 && position + direction[i] < 63){
            if(*(board + position + direction[i]) != turn && *(board + position + direction[i]) != 0){
                if(check_direction(position + direction[i], board, direction[i],turn, &pos_eat[0]))
                    eat = true;     
             }
        }
    }
    return eat;
}

//bool check_pass(

void player_turn(int* turn, int* board){
    
    string input = "";
    int x =0;
    int y =0;
    if(*turn == 2){
        cout << "White player turn" << endl;
        *turn = 1;        
    }    
    else{
	    cout << "Black player turn" << endl;
        *turn = 2;        
    }
    while(true){
		cout << "enter a position :";
		getline(cin, input);
		if(input.length() == 2){               
                y = input[0] - 'a';
                x = input[1] - '1';
                if(check_input(board,x,y))
                    if(check_eat(((8*(x))+(y)),board, *turn))
                        break;
                    else
                        cout << "mouvement impossible" << endl;
		}          
        else
            cout << "invalid position" << endl;
	}
    *(board + ((8*(x))+(y))) = *turn;
}


int main(int argc, char *argv[]){	

    int board[64] = {0};

    int turn = 2;
    init_board(&board[0]);
	print_board(board);
    while(true){
        player_turn(&turn, &board[0]);
        print_board(board);
    }
	return 0;

}


