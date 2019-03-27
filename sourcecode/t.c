#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int pos_played[9];
char mark_at_pos[9];

void gameboard();
int status();


int main()
{
    int player = 1;
	int i;
	int choice;
	FILE *file;
	
	
	int current_move = 0;
	int max_moves = 0;
	
		
	//get the current time and date
	
	time_t current_time;
	time(&current_time);

	
	
	file = fopen("game_history.txt","a");		//open the file with append, so I can keep adding the history of all games to this file.
	
	fprintf(file, "%s\n", ctime(&current_time));	//print the time and date to a file. 

    char mark; //nought or cross
    do
    {
		
        gameboard(); //initialize the gameboard
		
        if(player % 2){
			player = 1; // Odd
		}
		else{
			player = 2; // Even
		}			//if player is divisble by two - set player to 1, if it isn't - set player to 2
		
		printf("Total moves: %d\n", max_moves);
		printf("Current move: %d\n\n", current_move);
		printf("TO UNDO A MOVE, ENTER 0. TO REDO A MOVE, ENTER 11.\n\n");
		
        printf("Player %d, enter a position on a gameboard:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';	//if player is 1 - set mark to X, if it isn't - set mark to O
		
		if(current_move == 0){	//just to make sure that the game starts with player 1
			player = 1;
		}


        if (choice == 1 && square[1] == '1'){
            square[1] = mark;
			current_move++;
			pos_played[current_move] = 1;
			mark_at_pos[1] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 2 && square[2] == '2'){
            square[2] = mark;
			current_move++;
			pos_played[current_move] = 2;
			mark_at_pos[2] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 3 && square[3] == '3'){
            square[3] = mark;
			current_move++;
			pos_played[current_move] = 3;
			mark_at_pos[3] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 4 && square[4] == '4'){
            square[4] = mark;
			current_move++;
			pos_played[current_move] = 4;
			mark_at_pos[4] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 5 && square[5] == '5'){
            square[5] = mark;
			current_move++;
			pos_played[current_move] = 5;
			mark_at_pos[5] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 6 && square[6] == '6'){
            square[6] = mark;
			current_move++;
			pos_played[current_move] = 6;
			mark_at_pos[6] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 7 && square[7] == '7'){
            square[7] = mark;
			current_move++;
			pos_played[current_move] = 7;
			mark_at_pos[7] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 8 && square[8] == '8'){
            square[8] = mark;
			current_move++;
			pos_played[current_move] = 8;
			mark_at_pos[8] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
            
        else if (choice == 9 && square[9] == '9'){
            square[9] = mark;
			current_move++;
			pos_played[current_move] = 9;
			mark_at_pos[9] = mark;
			max_moves++;
			fprintf(file, "Player %d placed %c in position %d\n", player, mark, choice);
		}
		
		else if(choice == 0){		//undo the moves
			
			
			
			if(pos_played[current_move] == 1){
				square[1] = '1';
			}
			if(pos_played[current_move] == 2){
				square[2] = '2';
			}
			if(pos_played[current_move] == 3){
				square[3] = '3';
			}
			if(pos_played[current_move] == 4){
				square[4] = '4';
			}
			if(pos_played[current_move] == 5){
				square[5] = '5';
			}
			if(pos_played[current_move] == 6){
				square[6] = '6';
			}
			if(pos_played[current_move] == 7){
				square[7] = '7';
			}
			if(pos_played[current_move] == 8){
				square[8] = '8';
			}
			if(pos_played[current_move] == 9){
				square[9] = '9';
			}
			
			if(current_move != 0){
				current_move--;
				
			}
			
			
		}
		
		else if(choice == 11){		//redo the moves
			if(current_move == 0 && max_moves == 0){
			}
			else if(current_move < max_moves){	//so this only goes into effect if you undo something
				if(mark_at_pos[pos_played[current_move + 1]] != square[pos_played[current_move + 1]]){
					square[pos_played[current_move + 1]] = mark_at_pos[pos_played[current_move + 1]];	
				}
							
				current_move++;
			}
			
		}
		
		
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
		
        i = status();
		
		
		
		if(current_move != 0){
			player++;
		}
		
    }while (i == -1);
    
    gameboard();
    
    if (i == 1){	//check the status and output the result
        printf("==>\aPlayer %d has won\n ", --player);
		fprintf(file, "-------Player %d has won-------\n\n\n\n\n ", player);
		
	}
    else{
        printf("==>\aGame tied");
		fprintf(file, "-------Game tied-------\n\n\n\n\n");
	}

    getch();
	
	if(i == 1 || i == 0){	//1 is either player 1 or 2 won, 0 is a tie. -1 means it's in progress, so we don't want to close the file before it's all done
	fclose(file);
	}
	
	
    return 0;
}



int status()	//status of the game. I return the result based on the outcome. 1 is either player 1 or 2 won
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}




void gameboard()	//create a gameboard
{
    system("cls");		//clear screen

    printf("Player 1 is (X)  -  Player 2 is (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
