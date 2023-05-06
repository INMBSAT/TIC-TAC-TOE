#include <iostream>
using namespace std;

class Player {
    private:
        char player_mark;
    	int score = 0;
    	string player_name;
    public:
	    void set_name(string name) {	//to set a name of player
	        player_name = name;
	    }
	    
    	string get_name() {	//to get a name of player
            return player_name;
        }
	    
        char get_mark() {	//to get a mark of player
            return player_mark;
        }
        
	    void set_mark(char mark) {	//to set a mark of player
	        player_mark = mark;
	    }
	    
	    int get_score() {	//to get a score of player
	        return score;
	    }
	
	    int take_turn(int player_no) {	//taking input of box number 
	        int box_no;
	        
	        cout << "Player " << player_no<<"----> "<<player_name<<" place your mark("<<player_mark << ")" << endl;
	        cout << "Enter the Box no :";
	
	        do {
	            while (!(cin >> box_no)) {
	                cin.clear();
	                cin.ignore(900, '\n');
	                cout << "  Invalid!\n  Again Enter the box no :";
	            }
	            if (box_no < 1 || box_no > 9) {
	                cout << "  Invalid!\n  Again Enter the box no :";
	            }
	        } while (box_no < 1 || box_no > 9);
	        
	        return box_no;
	    }
	
	    void increase_score() {	//increasing score of player
	        ++score;
	    }
};

class Board {
    char boxes[3][3]; //two dimenstional  array
    public:
        void display() {//display a board
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << " " << boxes[i][j];
                    if (j <= 1)
                        cout << " |";
                    else
                        cout << endl;
                    if (j == 2 && i < 2)
                        cout << "-----------" << endl;
                }
            }
            cout<<"\n";
        }
        
	    bool place_mark(char c, int n) {//to store the mark in boxes if it is empty
	        switch (n) {
		        case 1:
		            if (boxes[0][0] == 'X' || boxes[0][0] == 'O') {
		                return false;
		            } else {
		                boxes[0][0] = c;
		                return true;
		            }
		            break;
		
		        case 2:
		            if (boxes[0][1] == 'X' || boxes[0][1] == 'O')
		                return false;
		            else {
		                boxes[0][1] = c;
		                return true;
		            }
		            break;
		
		        case 3:
		            if (boxes[0][2] == 'X' || boxes[0][2] == 'O')
		                return false;
		            else {
		                boxes[0][2] = c;
		                return true;
		            }
		            break;
		        case 4:
		            if (boxes[1][0] == 'X' || boxes[1][0] == 'O')
		                return false;
		            else {
		                boxes[1][0] = c;
		                return true;
		            }
		            break;
		
		        case 5:
		            if (boxes[1][1] == 'X' || boxes[1][1] == 'O')
		                return false;
		            else {
		                boxes[1][1] = c;
		                return true;
		            }
		            break;
		        case 6:
		            if (boxes[1][2] == 'X' || boxes[1][2] == 'O')
		                return false;
		            else {
		                boxes[1][2] = c;
		                return true;
		            }
		            break;
		        case 7:
		            if (boxes[2][0] == 'X' || boxes[2][0] == 'O')
		                return false;
		            else {
		                boxes[2][0] = c;
		                return true;
		            }
		            break;
		
		        case 8:
		            if (boxes[2][1] == 'X' || boxes[2][1] == 'O')
		                return false;
		            else {
		                boxes[2][1] = c;
		                return true;
		            }
		            break;
		        case 9:
		            if (boxes[2][2] == 'X' || boxes[2][2] == 'O')
		                return false;
		            else {
		                boxes[2][2] = c;
		                return true;
		            }
		            break;
		        }
	    }
	    
	    char checker() { //checks the winner
			if ((boxes[0][0] == 'X' && boxes[0][1] == 'X' && boxes[0][2] == 'X') ||
	            (boxes[1][0] == 'X' && boxes[1][1] == 'X' && boxes[1][2] == 'X') ||
	            (boxes[2][0] == 'X' && boxes[2][1] == 'X' && boxes[2][2] == 'X') ||
	            (boxes[0][0] == 'X' && boxes[1][0] == 'X' && boxes[2][0] == 'X') ||
	            (boxes[0][1] == 'X' && boxes[1][1] == 'X' && boxes[2][1] == 'X') ||
	            (boxes[0][1] == 'X' && boxes[1][1] == 'X' && boxes[2][1] == 'X') ||
	            (boxes[0][2] == 'X' && boxes[1][1] == 'X' && boxes[2][0] == 'X') ||
	            (boxes[0][0] == 'X' && boxes[1][1] == 'X' && boxes[2][2] == 'X')) {
	            cout << "Congrats!! Player 'X' WINS" << endl;
	            return 'X';
	        } else if ((boxes[0][0] == 'O' && boxes[0][1] == 'O' && boxes[0][2] == 'O') ||
	            (boxes[1][0] == 'O' && boxes[1][1] == 'O' && boxes[1][2] == 'O') ||
	            (boxes[2][0] == 'O' && boxes[2][1] == 'O' && boxes[2][2] == 'O') ||
	            (boxes[0][0] == 'O' && boxes[1][0] == 'O' && boxes[2][0] == 'O') ||
	            (boxes[0][1] == 'O' && boxes[1][1] == 'O' && boxes[2][1] == 'O') ||
	            (boxes[0][1] == 'O' && boxes[1][1] == 'O' && boxes[2][1] == 'O') ||
	            (boxes[0][2] == 'O' && boxes[1][1] == 'O' && boxes[2][0] == 'O') ||
	            (boxes[0][0] == 'O' && boxes[1][1] == 'O' && boxes[2][2] == 'O')) {
	            cout << "Congrats!! Player 'O' WINS" << endl;
	            return 'O';
	        } else {
	            return 'n';
	        }
	    }
	    
	    void clear() {//to intialize the 3by3 array to zero
	        int i, j;
	        for (i = 0; i < 3; i++) {
	            for (j = 0; j < 3; j++) {
	                boxes[i][j] = 0;
	            }
	        }
	    }
	    
	    void demo() {//to intialize the 3by3 array for demo
	    	int demo_board[3][3];
	    	demo_board[0][0] = 1;
			demo_board[0][1] = 2;
			demo_board[0][2] = 3;
			demo_board[1][0] = 4;
			demo_board[1][1] = 5;
			demo_board[1][2] = 6;
			demo_board[2][0] = 7;
			demo_board[2][1] = 8;
			demo_board[2][2] = 9;
		    for (int i = 0; i < 3; i++) {
	                for (int j = 0; j < 3; j++) {
	                    cout << " " << demo_board[i][j];
	                    if (j <= 1)
	                        cout << " |";
	                    else
	                        cout << endl;
	                    if (j == 2 && i < 2)
	                        cout << "-----------" << endl;
	                }
	            }
	            cout<<"\n";
	    }
};

class Tic_Tac_Toe {
    Player * player1;
    Player * player2;
    Board board;
    public:
        Tic_Tac_Toe(Player p1, Player p2) {//constructor 
            this -> player1 = & p1;
            this -> player2 = & p2;
            welcome();
        }
		void welcome(){//welcome display
				cout << "********************************************************************************************************************" << endl;
			    cout << "********************************************************************************************************************" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                              WELCOME TO                                                        **" << endl;
			    cout << "**                                                 THE                                                            **" << endl;
			    cout << "**                                           TIC TAC TOE GAME :)                                                  **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                           Programmed by:                                                       **" << endl;
			    cout << "**                                         FA21-BSSE-0077 \"INMBSAT\"                                               **" << endl;
			    cout << "**                                         FA21-BSSE-0055 \"AISHA KAMRAN\"                                          **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "**                                                                                                                **" << endl;
			    cout << "********************************************************************************************************************" << endl;
			    cout << "********************************************************************************************************************" << endl;
			}
			
	    void setup_Game() {//to set the mark of players
	        char m;
	        string name1,name2;
	        cout<<"Player 1---->Enter your name: ";
	        cin>>name1;
	        cout << "\nPlayer 1----> Which mark do you want to choose?\n\t'X' or 'O':" << endl;
			
	        do {	//asking again if input is other than X and O(only capital)
	            cin >> m;
	            if (m == 'X' || m == 'O') {
	            	cout<<"\nPlayer 2---->Enter your name: ";
	            	cin>>name2;

	            } else {
	                cout << "Invalid Input !!!\nEnter again please: ";
	            }
	        } while (m != 'X' && m != 'O');
	        
	        player1 -> set_name(name1);
	        player1 -> set_mark(m);
	
	        if (m == 'X') {
	        	player2 -> set_name(name2);
	            player2 -> set_mark('O');
	        } else if (m == 'O') {
	        	player2 -> set_name(name2);
	            player2 -> set_mark('X');
	        }
	        intro();
	    }
	    
		void intro(){
			cout<<"\nPlayer 1 --> "<<player1->get_name()<<" \nYour mark is: "<<player1->get_mark()<<endl;
	        cout<<"Player 2 --> "<<player2->get_name()<<" \nYour mark is: "<<player2->get_mark()<<endl;
	        cout << "OK! LET'S START THE GAME.\n" << endl;
		}
		
	    void play_Game() {
	        bool place_mark_result;
	        char check;
			
	        board.clear();
			board.demo();
	        for (int i = 1; i <=5; i++) //takes the game input from the user
	        {
	            do { // loop to take the box number AGAIN if player1 enters incorrect number
	
	                place_mark_result = board.place_mark(player1 -> get_mark(), player1 -> take_turn(1));
	
	                if (!place_mark_result) {
	                    cout << "Box already filled :("<<endl;
	                }
	
	            } while (!place_mark_result);
				board.display();
	
	            check = board.checker();
				if(check!='n'){//check fo the winner
					this->set_result(check);
					break;
				}
				
	            if (i == 5) {//checking for tie
	                cout << "It's a TIE!! NO one WiNS"<<endl;
	                break;
	            }
	            
	            do { // loop to take the box number AGAIN if player2 enters incorrect number
	
	                place_mark_result = board.place_mark(player2 -> get_mark(), player2 -> take_turn(2));
	
	                if (!place_mark_result) {
	                    cout << "Box already filled :("<<endl;
	                }
	
	            } while (!place_mark_result);
				board.display();
				
	            check = board.checker();
				if(check!='n'){//check fo the winner
					this->set_result(check);
					break;
				}
	        }
	    }
	    
	    void set_result(char win_mark){//set the scores of players
	    	
	    	char palyer1_marks = player1 -> get_mark();
	        char palyer2_marks = player2 -> get_mark();
	        
	    	if (win_mark == palyer1_marks) {
	                player1 -> increase_score();
	            }
	            if (win_mark == palyer2_marks) {
	                player2 -> increase_score();
	            }
		}
		
	    void end_Game() {
	        cout << "      ******Game Over******\n" << endl;
	        cout << "      ****** Score ****** \n"<<endl;
	        cout << "Player1 ----> "<<player1->get_name()<<"'s Score is : " << player1 -> get_score()<<endl;
	        cout << "Player2 ----> "<<player2->get_name()<<"'s Score is : " << player2 -> get_score()<<endl<<endl;
	        exit(0);
	    }
};

int main() {
	Player p1, p2;
	Tic_Tac_Toe t(p1, p2);
    t.setup_Game();
    char choice;
    
    do{
    	t.play_Game();
    	cout << "\nDo you want to play again?(Y/N): ";
        cin >> choice;
        
        do{
        	if (choice == 'Y' || choice == 'N') {
                break;
            } else {
                cout << "Invalid Input !!!\nEnter again please: ";
                cin >> choice;
            }
		}
		while(choice != 'Y' || choice != 'N');
    	if(choice=='N'){
    		t.end_Game();
		}
	}
	while( choice=='Y');
	return 0;
}
