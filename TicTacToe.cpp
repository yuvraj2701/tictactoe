#include <iostream>

using namespace std;

void display(char board[3][3]){		//show current board state

	cout << "\ncurrent state of board:\n";
	for (int i=0;i<3;i++){
		cout << " ";
		for (int j=0;j<3;j++){
			cout << board[i][j];
			if(j != 2) 
				cout << " | ";
			else
				cout << " ";
		}
		cout << endl;
		if(i != 2)
			cout << "-----------";
		
		cout << endl;
	}
}

int input(int n,int a,char board[3][3]){	//take user input

	if (n>=1 && n<= 9){

		//row - column of board
		int row = (n-1)/3;	
		int col = (n-1)%3;

		if(board[row][col] == 'X' || board[row][col] == 'O'){
			cout << "It is already filled"<< endl;
			return 0;
		} else{
			if(a==1)
				board[row][col] = 'X';
			else
				board[row][col] = 'O';
		}	

	} else{
		cout << "please enter in the range 1-9"<<endl;
	}
	return 1;
}

int check(char board[3][3]){	//check if someone has won

	for(int i=0;i<3;i++)
    {
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])  //checking for horizontal match
        {
			if(board[i][0]=='X')return 1;	//player 1 wins
			else if(board[i][0]=='O')return 2;	//player 2 wins
		}
        else if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]) //checking for vertical match
        {
			if(board[0][i]=='X')return 1;	//player 1 wins
			else if(board[0][i]=='O')return 2;	//player 2 wins
		}
	}
    
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])  //check match in main diagonal
    {
		if(board[0][0]=='X')return 1;	//player 1 wins
		else if(board[0][0]=='O')return 2;	//player 2 wins
	}
    else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])  //check match in second main diagonal
    {
		if(board[0][2]=='X')return 1;	//player 1 wins
		else if(board[0][2]=='O')return 2;	//player 2 wins
	}
    
    return 0;   //no win yet
}

int check_draw(char board[3][3]){	
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(!(board[i][j]=='X' || board[i][j]=='O'))return 0;

		}
	}
	return 1;
}

int case1,case2,case3;

//function decides computer's moves if it is player 1
void computer1(int n,char board[3][3]){

	int entries=0;
	//check number of moves uptil now
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j]=='X' || board[i][j]=='O')
				entries++;
		}
	}
	
	//first move of computer
	if(entries==0){
		input(7,1,board);
		cout << "computer played at 7"<<endl;
	}

	//if player plays at center
	if(n==5 && entries==2)	
	{
		case1 = 1;input(3,1,board);	//computer's input
		cout << "computer played at 3"<<endl;
	}
	if(n==1 && entries==4 && case1==1){
		case1 = 6;input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if(n==9 && entries==4 && case1==1){
		case1 = 7;input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n==6 && entries==6 && case1==6){
		input(8,1,board);
		cout << "computer played at 8"<<endl;
	}
	if(n!=6 && entries==6 && case1==6){
		input(6,1,board);
		cout << "computer played at 6"<<endl;
	}
	if(n==2 && entries==6 && case1==7){
		input(4,1,board);
		cout << "computer played at 4"<<endl;
	}
	if(n!=2 && entries==6 && case1==7){
		input(2,1,board);
		cout << "computer played at 2"<<endl;
	}
	if(n==2 && entries==4 && case1==1){
		input(8,1,board);
		cout << "computer played at 8"<<endl;
		case1 = 8;
	}
	if(n==4 && entries==4 && case1==1){
		input(6,1,board);
		cout << "computer played at 6"<<endl;
		case1 = 9;
	}
	if(n==6 && entries==4 && case1==1){
		input(4,1,board);
		cout << "computer played at 4"<<endl;
		case1 = 10;
	}
	if(n==8 && entries==4 && case1==1){
		input(2,1,board);
		cout << "computer played at 2"<<endl;
		case1 = 11;
	}
	if(n!=9 && entries==6 && case1==8){
		input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if(n==9 && entries==6 && case1==8){
		input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n!=9 && entries==6 && case1==9){
		input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if(n==9 && entries==6 && case1==9){
		input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n!=1 && entries==6 && case1==10){
		input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n==1 && entries==6 && case1==10){
		input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if(n!=1 && entries==6 && case1==11){
		input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n==1 && entries==6 && case1==11){
		input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if(n!=4 && entries==8 && case1==8){
		input(4,1,board);
		cout << "computer played at 4"<<endl;
	}
	if(n==4 && entries==8 && case1==8){
		input(6,1,board);
		cout << "computer played at 6"<<endl;
	}
	if(n!=2 && entries==8 && case1==9){
		input(8,1,board);
		cout << "computer played at 8"<<endl;
	}
	if(n==2 && entries==8 && case1==9){
		input(8,1,board);
		cout << "computer played at 8"<<endl;
	}
	if(n!=8 && entries==8 && case1==10){
		input(8,1,board);
		cout << "computer played at 8"<<endl;
	}
	if(n==8 && entries==8 && case1==10){
		input(2,1,board);
		cout << "computer played at 2"<<endl;
	}
	if(n!=6 && entries==8 && case1==11){
		input(6,1,board);
		cout << "computer played at 6"<<endl;
	}
	if(n==6 && entries==8 && case1==11){
		input(2,1,board);
		cout << "computer played at 2"<<endl;
	}
	
	//if player has played 2nd move at corner or at edge 
	if((n==1 || n==4) && entries==2){
		case1 = 2;input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if((n==3 || n==6) && entries==2){
		case1 = 3;input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if((n==8 || n==9) && entries==2){
		case1 = 4;input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n==2 && entries==2){
		case1 = 5;input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n==8 && entries==4 && case1==2){
		input(3,1,board);
		cout << "computer played at 3"<<endl;
	}
	if(n==8 && entries==4 && case1==3){
		input(1,1,board);
		cout << "computer played at 1"<<endl;
	}
	if(n!=8 && entries==4 && (case1==2 || case1==3)){
		input(8,1,board);
		cout << "computer played at 8"<<endl;
	}

	if(n==4 && entries==4 && case1==4){
		input(3,1,board);
		cout << "computer played at 3"<<endl;
	}
	if(n==4 && entries==4 && case1==5){
		input(9,1,board);
		cout << "computer played at 9"<<endl;
	}
	if(n!=4 && entries==4 && (case1==4 || case1==5)){
		input(4,1,board);
		cout << "computer played at 4"<<endl;
	}
	if(n==5 && entries==6 && case1==2){
		input(6,1,board);
		cout << "computer played at 6"<<endl;
	}
	if(n!=5 && entries==6 && case1==2){
		input(5,1,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==5 && entries==6 && case1==3){
		input(4,1,board);
		cout << "computer played at 4"<<endl;
	}
	if(n!=5 && entries==6 && case1==3){
		input(5,1,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==5 && entries==6 && case1==4){
		input(2,1,board);
		cout << "computer played at 2"<<endl;
	}
	if(n!=5 && entries==6 && case1==4){
		input(5,1,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==5 && entries==6 && case1==5){
		input(8,1,board);
		cout << "computer played at 8"<<endl;
	}
	if(n!=5 && entries==6 && case1==5){
		input(5,1,board);
		cout << "computer played at 5"<<endl;
	}

	display(board);	//display after computer's move
}

//computer's move when it is player 2
void computer2(int n,char board[3][3]){
	int entries=0;

	//count number of moves uptill now
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j]=='X' || board[i][j]=='O')
				entries++;
		}
	}

	//when player plays first
	if(n==1 && entries==1){
		case1 = 1;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==2 && entries==1){
		case1 = 2;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==3 && entries==1){
		case1 = 3;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==4 && entries==1){
		case1 = 4;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==6 && entries==1){
		case1 = 6;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==7 && entries==1){		
		case1 = 7;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==8 && entries==1){
		case1 = 8;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==9 && entries==1){
		case1 = 9;input(5,2,board);
		cout << "computer played at 5"<<endl;
	}
	if(n==5 && entries==1){
		case1 = 5;input(7,2,board);
		cout << "computer played at 7"<<endl;
	}

	//if player selects cell 1 at first move
	if(case1==1){
		if(n==2 && entries==3){
			input(3,2,board);
			case2 = 2;cout << "computer played at 3"<<endl;
		}
		if(case2==2){
			if(n!=7 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n!=6 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==3 && entries==3){
			case2 =  3;input(2,2,board);
			cout << "computer played at 2"<<endl;
		}
		if(case2==3){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n!=6 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}		
		}
		if(n==4 && entries==3){
			input(7,2,board);
			cout << "computer played at 7"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n!=3 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==6 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=2 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=7 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==7 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 = 7;
		}
		if(case2==7){
			if(n!=6 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
		}
		if(n==8 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=3 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==9 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 = 9;
		}
		if(case2==9){
			if(n!=6 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=7 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
	}

	//if player plays at 2
	if(case1==2){
		if(n==1 && entries==3){
			input(3,2,board);
			cout << "computer played at 3"<<endl;
			case2 = 1;
		}
		if(case2==1){
			if(n!=7 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n!=6 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==3 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 3;
		}
		if(case2==3){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==4 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=3 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==6 && entries==3){
			input(3,2,board);
			cout << "computer played at 3"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=7 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=1 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==7 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 = 7;
		}
		if(case2==7){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=9 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==9 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 = 9;
		}
		if(case2==9){
			if(n!=6 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=7 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==8 && entries==3){
			input(7,2,board);
			cout << "computer played at 7"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n!=3 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
		}
	}

	//if player plays at 3
	if(case1==3){
		if(n==6 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==9 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 =  9;
		}
		if(case2==9){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}		
		}
		if(n==2 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 2;
		}
		if(case2==2){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==8 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n!=6 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=1 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==1 && entries==3){
			input(2,2,board);
			cout << "computer played at 2"<<endl;
			case2 = 1;
		}
		if(case2==1){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
		}
		if(n==4 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n!=2 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=9 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==7 && entries==3){
			input(2,2,board);
			cout << "computer played at 2"<<endl;
			case2 = 7;
		}
		if(case2==7){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=1 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
	}
	//if player plays at 4
	if(case1==4){
		if(n==7 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 7;
		}
		if(case2==7){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==1 && entries==3){
			input(7,2,board);
			cout << "computer played at 7"<<endl;
			case2 = 1;
		}
		if(case2==1){
			if(n!=3 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==8 && entries==3){
			input(7,2,board);
			cout << "computer played at 7"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n!=3 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=1 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==2 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 2;
		}
		if(case2==2){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=7 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==9 && entries==3){
			input(2,2,board);
			cout << "computer played at 2"<<endl;
			case2 = 9;
		}
		if(case2==9){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=3 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==3 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 3;
		}
		if(case2==3){
			if(n!=2 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=9 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==6 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
		}
	}
	//if player plays at 5
	if(case1==5){
		if(n==1 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 1;
		}
		if(case2==1){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==2 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 2;
		}
		if(case2==2){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==3 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 3;
		}
		if(case2==3){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==4 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n==1 && entries==5){
				input(9,2,board);
				case3 = 1;
				cout << "computer played at 9"<<endl;
			}
			if(case3==1){
				if(n!=8 && entries==7){
					input(8,2,board);
					cout << "computer played at 8"<<endl;
				}
				if(n==8 && entries==7){
					input(3,2,board);
					cout << "computer played at 3"<<endl;
				}
			}
			if((n==2 || n==3)&& entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
				case3 = 2;
			}
			if(case3==2){
				if(n!=9 && entries==7){
					input(9,2,board);
					cout << "computer played at 9"<<endl;
				}
				if(n==9 && entries==7){
					input(1,2,board);
					cout << "computer played at 1"<<endl;
				}
			}
			if(n==8 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
				case3 = 3;
			}
			if(case3==3){
				if((n==1 || n==3)&& entries==7){
					input(9,2,board);
					cout << "computer played at 9"<<endl;
				}
				if(n==9 && entries==7){
					input(1,2,board);
					cout << "computer played at 1"<<endl;
				}
			}
			if(n==9 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
				case3 = 4;
			}
			if(case3==4){
				if(n!=8 && entries==7){
					input(8,2,board);
					cout << "computer played at 8"<<endl;
				}
				if(n==8 && entries==7){
					input(2,2,board);
					cout << "computer played at 2"<<endl;
				}
			}
		}
		if(n==6 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==8 && entries==3){
			input(2,2,board);
			cout << "computer played at 2"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n==9 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
				case3 = 1;
			}
			if(case3==1){
				if(n!=4 && entries==7){
					input(4,2,board);
					cout << "computer played at 4"<<endl;
				}
				if(n==4 && entries==7){
					input(3,2,board);
					cout << "computer played at 3"<<endl;
				}
			}
			if((n==3 || n==6) && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
				case3 = 2;
			}
			if(case3==2){
				if(n!=1 && entries==7){
					input(1,2,board);
					cout << "computer played at 1"<<endl;
				}
				if(n==1 && entries==7){
					input(9,2,board);
					cout << "computer played at 9"<<endl;
				}
			}
			if(n==1 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
				case3 = 3;
			}
			if(case3==3){
				if(n!=4 && entries==7){
					input(4,2,board);
					cout << "computer played at 4"<<endl;
				}
				if(n==4 && entries==7){
					input(6,2,board);
					cout << "computer played at 6"<<endl;
				}
			}
			if(n==4 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
				case3 = 4;
			}
			if(case3==4){
				if((n==1 || n==3) && entries==7){
					input(9,2,board);
					cout << "computer played at 9"<<endl;
				}
				if(n==9 && entries==7){
					input(1,2,board);
					cout << "computer played at 1"<<endl;
				}
			}
		}
		if(n==9 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2==9;
		}
		if(case2==9){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
	}
	//if player plays at 6
	if(case1==6){
		if(n==3 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 3;
		}
		if(case2==3){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n!=8 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==9 && entries==3){
			input(3,2,board);
			cout << "computer played at 3"<<endl;
			case2 = 9;
		}
		if(case2==9){
			if(n!=7 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==2 && entries==3){
			input(3,2,board);
			cout << "computer played at 3"<<endl;
			case2 = 2;
		}
		if(case2==2){
			if(n!=7 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=9 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==8 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=3 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==1 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 1;
		}
		if(case2==1){
			if(n!=2 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=7 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==7 && entries==3){
			input(2,2,board);
			cout << "computer played at 2"<<endl;
			case2 = 7;
		}
		if(case2==7){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=1 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==4 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
		}
	}
	//if player plays at 7
	if(case1==7){
		if(n==4 && entries==3){
			input(1,2,board);
			cout << "computer played at 1"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n!=9 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==1 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 =  1;
		}
		if(case2==1){
			if(n!=6 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}		
		}
		if(n==8 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n!=6 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==2 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 = 2;
		}
		if(case2==2){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=9 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==9 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 9;
		}
		if(case2==9){
			if(n!=2 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n!=6 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
		}
		if(n==6 && entries==3){
			input(2,2,board);
			cout << "computer played at 2"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=1 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==3 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 3;
		}
		if(case2==3){
			if(n!=2 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=9 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
	}
	//if player plays at 8
	if(case1==8){
		if(n==9 && entries==3){
			input(7,2,board);
			cout << "computer played at 7"<<endl;
			case2 = 9;
		}
		if(case2==9){
			if(n!=3 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==7 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 7;
		}
		if(case2==7){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n!=6 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==6 && entries==3){
			input(9,2,board);
			cout << "computer played at 9"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=1 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=7 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==4 && entries==3){
			input(7,2,board);
			cout << "computer played at 7"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n!=3 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==5){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n!=9 && entries==7){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n==9 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==3 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 = 3;
		}
		if(case2==3){
			if(n!=6 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=1 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
			if(n==1 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==1 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 = 1;
		}
		if(case2==1){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=3 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==2 && entries==3){
			input(3,2,board);
			cout << "computer played at 3"<<endl;
			case2 = 2;
		}
		if(case2==2){
			if(n!=7 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==5){
				input(9,2,board);
				cout << "computer played at 9"<<endl;
			}
			if(n!=6 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
		}
	}
	//if player plays at 9
	if(case1==9){
		if(n==8 && entries==3){
			input(7,2,board);
			cout << "computer played at 7"<<endl;
			case2 = 8;
		}
		if(case2==8){
			if(n!=3 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
		if(n==7 && entries==3){
			input(8,2,board);
			cout << "computer played at 8"<<endl;
			case2 = 7;
		}
		if(case2==7){
			if(n!=2 && entries==5){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n!=4 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}		
		}
		if(n==6 && entries==3){
			input(3,2,board);
			cout << "computer played at 3"<<endl;
			case2 = 6;
		}
		if(case2==6){
			if(n!=7 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
		}
		if(n==4 && entries==3){
			input(2,2,board);
			cout << "computer played at 2"<<endl;
			case2 = 4;
		}
		if(case2==4){
			if(n!=8 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n==8 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=3 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==7){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
		}
		if(n==3 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 = 3;
		}
		if(case2==3){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
			if(n!=2 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
			if(n==2 && entries==7){
				input(1,2,board);
				cout << "computer played at 1"<<endl;
			}
		}
		if(n==2 && entries==3){
			input(4,2,board);
			cout << "computer played at 4"<<endl;
			case2 = 2;
		}
		if(case2==2){
			if(n!=6 && entries==5){
				input(6,2,board);
				cout << "computer played at 6"<<endl;
			}
			if(n==6 && entries==5){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n!=7 && entries==7){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n==7 && entries==7){
				input(8,2,board);
				cout << "computer played at 8"<<endl;
			}
		}
		if(n==1 && entries==3){
			input(6,2,board);
			cout << "computer played at 6"<<endl;
			case2 = 1;
		}
		if(case2==1){
			if(n!=4 && entries==5){
				input(4,2,board);
				cout << "computer played at 4"<<endl;
			}
			if(n==4 && entries==5){
				input(7,2,board);
				cout << "computer played at 7"<<endl;
			}
			if(n!=3 && entries==7){
				input(3,2,board);
				cout << "computer played at 3"<<endl;
			}
			if(n==3 && entries==7){
				input(2,2,board);
				cout << "computer played at 2"<<endl;
			}
		}
	}
	
	display(board);	// finally display the board
}

int main(){

	cout<<"Welcome!\n";

	//loop until game is not over
	while(1){

		cout<<"\nBoard-\n";
		for (int i=0;i<3;i++)
		{
			cout << " ";
			for (int j=0;j<3;j++){
				cout << i*3 + j + 1;
				if(j != 2) 
					cout << " | ";
				else
					cout << " ";
			}
			cout << endl;
			if(i != 2)
				cout << "-----------";

			cout << endl;
		}

		char board[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' ',},b;
		int n=0,a,c,w,d,flag;
		
		//decide if human wants to go first or second
		while(1){
			cout << "\nWant to go 1st or 2nd (enter 1 or 2):";
			cin >> a;
			if(a != 1 && a != 2)
				cout << "You must enter only 1 or 2" << endl;
			else
				break;
		}

		if (a == 1)
			cout << "Computer is assigned player 2\n" << endl;
		else 
			cout << "Computer is assigned player 1\n" << endl;


		//loop until board is filled completely with X and O
		while(1){

			if(a ==  2)	//computer making move when human is 2nd player
				computer1(n,board);

			w = check(board);	//check if anyone won
			if(w == 1){
				if(a==1)
					cout << "Player 1 won the game\n";
				else
					cout << "Computer won the game\n"; 
				break;
			}
			else{
				if(w == 2){
					if(a==2)
						cout << "Player 2 won the game\n";
					else
						cout << "Computer won the game\n";
					break;
				}
			}

			//human's turn
			cout << "Enter cell number (1 to 9):";
			cin >> n;
			c = input(n,a,board);
			display(board);
			w = check(board);	//check win
			if(w == 1){
				if(a==1)
					cout << "Player 1 won the game\n";
				else
					cout << "Computer won the game\n"; 
				break;
			}
			else{
				if(w == 2){
					if(a==2)
						cout << "Player 2 won the game\n";
					else
						cout << "Computer won the game\n";
					break;
				}
			}

			if(a == 1 && c==1)	//computer's move when it is 2nd player
				computer2(n,board);

			w = check(board);
			if(w == 1){		//check win
				if(a==1)
					cout << "Player 1 won the game\n";
				else
					cout << "Computer won the game\n"; 
				break;
			}
			else{
				if(w == 2){
					if(a==2)
						cout << "Player 2 won the game\n";
					else
						cout << "Computer won the game\n";
					break;
				}
			}

			d = check_draw(board);
			if(d==1){
				cout << "Game ended in a Draw\n";
				break;
			}
		}
		
		while(1){
			cout << "\nDo you wish to play another game(enter 'y' or 'n' for yes or no respectively):";
			cin >> b;

			if(b=='Y' || b=='y'){
				flag = 1;
				break;
			}
			else{
				if(b=='n' || b=='N'){
					flag = 0;
					break;
				}
				else
					cout << "pls enter 'y' or 'n' only" << endl;
			} 
		}
		if(flag==0)
			break;
	}
	return 0;
}