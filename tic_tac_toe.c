
#include <stdio.h>
#include <string.h>

char *table[3][3] = {
        {"| |", "| |", "| |"},
        {"| |", "| |", "| |"},
        {"| |", "| |", "| |"}
 };




void game_loop();
void print_table();
int check_winner(char *table[3][3]);
void fill_table(int choice, int turn);
int check_table(int choice);


enum turn{
    player_x = 0,
    player_o = 1
};


int main(void){

    game_loop();
    return 0;

}

void print_table(){

    for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){

                printf("%s", table[i][j]);
            }
            printf("\n");
        }

}

int check_table(int choice){

    int index = choice - 1;
    int i = index / 3;
    int j = index % 3;

    if(strcmp(table[i][j], "| |") == 0){
        return 0;
    }

}

void fill_table(int choice, int turn){

    for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){

                if(choice == i * 3 + j + 1){
                    
                    table[i][j] = "|X|";

                    switch(turn){
                        case 0:
                            table[i][j] = "|X|";
                        break;
                        case 1:
                            table[i][j] = "|O|";
                        break;
                    }
                }

            }

        }
}

int check_winner(char *table[3][3]){

    if((table[0][0] == "|O|" && table[0][1] == "|O|" && table[0][2] == "|O|")) return 1;
    else if(table[1][0] == "|O|" && table[1][1] == "|O|" && table[1][2] == "|O|")return 1;
    else if(table[2][0] == "|O|" && table[2][1] == "|O|" && table[2][2] == "|O|") return 1;
    
    else if(table[0][1] == "|X|" && table[0][1] == "|X|" && table[0][2] == "|X|") return 0;
    else if(table[1][0] == "|X|" && table[1][1] == "|X|" && table[1][2] == "|X|") return 0;
    else if(table[2][0] == "|X|" && table[2][1] == "|X|" && table[2][2] == "|X|") return 0;
    
    else if(table[0][0] == "|O|" && table[1][1] == "|O|" && table[2][2] == "|O|") return 1;
    else if(table[0][0] == "|X|" && table[1][1] == "|X|" && table[2][2] == "|X|") return 0;
    else if(table[0][2] == "|O|" && table[1][1] == "|O|" && table[2][0] == "|O|") return 1;
 
    else if(table[0][2] == "|X|" && table[1][1] == "|X|" && table[2][0] == "|X|") return 0;
    else if(table[0][0] == "|X|" && table[1][0] == "|X|" && table[2][0] == "|X|") return 0;
    else if(table[0][1] == "|X|" && table[1][1] == "|X|" && table[2][1] == "|X|") return 0;

    else if(table[0][2] == "|X|" && table[1][2] == "|X|" && table[2][2] == "|X|") return 0;
    
    else if(table[0][0] == "|O|" && table[1][0] == "|O|" && table[2][0] == "|O|") return 1;
    else if(table[0][1] == "|O|" && table[1][1] == "|O|" && table[2][1] == "|O|") return 1;
    else if(table[0][2] == "|O|" && table[1][2] == "|O|" && table[2][2] == "|O|") return 1; 

}


void game_loop(){

    
    int choice;
    int turn = player_o;
    int turns = 9;    
    int is_empty;
    int winner;
    char *t;

    while(true){

        print_table();

        if(turns == 0){
            printf("DRAW!");
            break;
        }
        
        if(check_winner(table) == 1 || check_winner(table) == 0){
            break;
        }

        if(turn == player_x) t = "\nTurn: x > ";
        else if (turn == player_o)t = "\nTurn: o > ";
        
        printf("%s", t);
        scanf("%d", &choice);

        if(choice < 0 || choice > 9 || check_table(choice) == 1){
            printf("Err");
            scanf("%d", &choice);
        } 
    
        if(check_table(choice) == 0){
            turns -= 1;
            fill_table(choice, turn);
            winner = check_winner(table);

            if(winner == player_x) printf("x wins!\n");
            else if (winner == player_o) printf("o wins!\n");
                     
            if(turn == player_x) turn = player_o;
            else if (turn == player_o) turn = player_x;
         
        } else {
            printf("Err > ");
            scanf("%d", &choice);
        }

    }
    
}