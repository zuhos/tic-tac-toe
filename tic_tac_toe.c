
#include <stdio.h>
#include <string.h>

char *table[3][3] = {
        {"| |", "| |", "| |"},
        {"| |", "| |", "| |"},
        {"| |", "| |", "| |"}
 };

void game_loop();
void print_table();
void check_winner();
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
void check_winner(){


    if(table[0][0] == "|O|" && table[0][1] == "|O|" && table[0][2] == "|O|"){
        printf("Winner is O");
    }

    else if(table[1][0] == "|O|" && table[1][1] == "|O|" && table[1][2] == "|O|"){
        printf("Winner is O");
    }

    else if(table[2][0] == "|O|" && table[2][1] == "|O|" && table[2][2] == "|O|"){
        printf("Winner is O");
    }

    else if(table[0][0] == "|X|" && table[0][1] == "|X|" && table[0][2] == "|X|"){
        printf("Winner is X");
    }

    else if(table[1][0] == "|X|" && table[1][1] == "|X|" && table[1][2] == "|X|"){
        printf("Winner is X");
    }

    else if(table[2][0] == "|X|" && table[2][1] == "|X|" && table[2][2] == "|X|"){
        printf("Winner is X");
    }

    //
    else if(table[0][0] == "|O|" && table[1][1] == "|O|" && table[2][2] == "|O|"){
        printf("Winner is O");
    }

    else if(table[0][0] == "|X|" && table[1][1] == "|X|" && table[2][2] == "|X|"){
        printf("Winner is X");
    }

    //
    else if(table[0][2] == "|O|" && table[1][1] == "|O|" && table[2][0] == "|O|"){
        printf("Winner is O");
    }

     else if(table[0][2] == "|X|" && table[1][1] == "|X|" && table[2][0] == "|X|"){
        printf("Winner is X");
    } 

}


void game_loop(){

    /*
    player_x = 0,
    player_o = 1
    */
    int choice;
    int turn = player_x;
    int is_empty;

    while(true){


        print_table();
        check_winner();
      
        if(turn == player_x){
            printf("\n(x) > ");

        } else if (turn == player_o){
            printf("\n(O) > ");
        }

        scanf("%d", &choice);

        if(choice < 0 || choice > 9){
            printf("Wrong choice");
            scanf("%d", &choice);
        } 
    
        if(check_table(choice) == 0){
            fill_table(choice, turn);

                if(turn == player_x)
                {
                    turn = player_o;
                }
                else if (turn == player_o)
                {
                    turn = player_x;
                }

        } else {
            printf("Err > ");
            scanf("%d", &choice);
        }

    
    }

 
}