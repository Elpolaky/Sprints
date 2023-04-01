#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t ;
// -------------------------------------------- Functions prototypes ----------------------------------------------------------
void drawBoard(uint8_t *board); // This function will take a board as an input and prints it on the console

void updateBoard (uint8_t *board, uint8_t position, uint8_t value); //- This function will take the board, position to update and value to set in this position

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);  /*- This function will take the player's number and asks the player to choose between X and O (case insensitive)
                                                                    - This function will return 0 when the input symbol is not wrong and/or was not chosen before
                                                                    - This function will return 1 when the input symbol is wrong and/or was chosen before*/


void setPlayerConfig(uint8_t *configArray); //- This function will prompt and asks each user about their preferred symbols and saves it in the configArray

void loadAndUpdate(uint8_t playerNumber); //- This function will take the player's number then load his config, ask him for the position then updates the board

void getGameState(uint8_t *board, uint8_t *gameState); /* - This function will check after each move if there is a win, draw or continue playing.
                                                          - Returns 0 for winning
                                                          - Returns 1 for a draw
                                                          - Returns 2 to continue */
//-----------------------------------------------------------------------------------------------------------------------------
//----------------------------- Global variables , arrays , Flags -------------------------------------------------------------
uint8_t start, flag_config, flag_player1, flag_player2, flag_position, state =2;
uint8_t player1_config[2];
uint8_t player2_config[2];
uint8_t player_num =1;
//----------------------------------------------------------------------------------------------------------------------------

uint8_t board[]= { '-','-','-','-','-',
                   '1','|','2','|','3',
                   '-','|','-','|','-',
                   '4','|','5','|','6',
                   '-','|','-','|','-',
                   '7','|','8','|','9',
                   '-','-','-','-','-',
                 };

enum game_state  { _WIN,_DRAW,_CONTINUE};


//---------------------------------------------------- Main --------------------------------------------------------------------
int main()
{
//-- instructions --
    printf("---- Hello players in X-O Game ---- \n\n To start playing we need you to follow these steps\n");
    printf("   1- player 1 and player 2 will choose their symbols ---> ( note : choose symbol between X / O ) \n");
    printf("   2- Each player will choose the position to put the symbol in it ---> (note : choose position between (1-9) as shown)\n");
    drawBoard(board);
    printf("   3- The first one to collect 3 of his symbol in row or in column or in diagonal he will win \n");

    printf("\n\n----> To start please enter number 1 <---- \n");
// ----------------

        scanf("%d",&start);
        fflush(stdin);
        printf("\n");
        while(start == 1)
        {
            if(state == _WIN)
            {
                printf("\n------> YOU WON <------\n\n");
                break;
            }
            else if ( state == _DRAW)
            {
                printf("\n------>  DRAW  <------\n\n");
                break;
            }
            else
            {
                state = 2 ;
                loadAndUpdate(player_num);

            }



    }
    return 0;
}
//------------------------------------------------------- End of Main ----------------------------------------------------------------



void drawBoard(uint8_t *board)
{
    uint8_t i = 0 ;
    for(i=0; i<=35; i++)
    {
        printf("%c",board[i]);
        if((i!=0)&&((i+1)%5==0))
        {
            printf("\n");
        }
    }
}


void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{
    switch(value)
    {
    case'x':
        value ='X';
        break;
    case'o':
        value = 'O';
        break;
    case 'X':
        break;
    case 'O':
        break;
    default :
        break;

    }

    switch(position)  // this switch case to check position
    {
    case '1' :
        board[5]= value;
        break;
    case '2' :
        board[7]= value;
        break;

    case '3':
        board[9]= value;
        break;

    case '4' :
        board[15]= value;
        break;

    case '5' :
        board[17]= value;
        break;

    case '6' :
        board[19]= value;
        break;
    case '7' :
        board[25]= value;
        break;
    case '8' :
        board[27]= value;
        break;
    case '9':
        board[29]= value;
        break;

    default:
        flag_position = 1;

        break;

    }
    drawBoard(board);


}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)
{
    uint8_t return_value = 0;
    printf("Please Player %d choose X/O : ", playerNumber);

    scanf("%c",symbol);

    if((*symbol=='x'|| *symbol=='X')||(*symbol=='O'||*symbol=='o'))
    {
        return_value = 0 ;

    }

    else
    {
        return_value = 1 ;

    }
    if(player2_config[1]== player1_config[1] )
    {
        return_value = 1 ;

    }

    return return_value ;
}


void setPlayerConfig(uint8_t *configArray)
{

    flag_config = getPlayerSymbol(configArray[0],&configArray[1]);

}

void loadAndUpdate(uint8_t playerNumber)
{
    uint8_t position;

    while(playerNumber == 1 && !flag_player1)
    {
        player1_config[0]=1;
        setPlayerConfig(player1_config);
        fflush(stdin);
        if(flag_config)
        {
            printf("\n----> Wrong symbol please player 1 try again <----\n\n");
            playerNumber = 1 ;

        }
        else
        {
            flag_player1 = 1 ;
            playerNumber = 2 ;
            break ;
        }
    }

    while(playerNumber == 2 && !flag_player2)
    {
        player2_config[0]=2;
        setPlayerConfig(player2_config);
        fflush(stdin);

        if(flag_config)
        {
            printf("\n----> Wrong symbol please player 2 try again <----\n\n");
            playerNumber = 2 ;

        }
        else
        {
            flag_player2 = 1 ;
            playerNumber = 1 ;

            break;
        }
    }

    if(flag_player1 && flag_player2 )
    {

        getGameState(board,&state); // check the game state

        while(!flag_position && playerNumber==1 && state == 2)
        {
            printf("\nplease player 1 Enter the position you want from 1-9 : ");
            scanf("%c",&position);
            fflush(stdin);
            updateBoard(board,position,player1_config[1]);
            if(flag_position)
            {
                printf (" \n----> position not found please player 1 try again <----\n\n");
                flag_position =0 ;
            }
            else
            {
                playerNumber=2;

            }
        }

        getGameState(board,&state); // check the game state

        while(!flag_position && playerNumber==2 && state==2)
        {
            printf("please player 2 Enter the position you want from 1-9 : ");
            scanf("%c",&position);
            fflush(stdin);
            updateBoard(board,position,player2_config[1]);
            if(flag_position)
            {
                printf ("\n----> position not found please player 2 try again <----\n\n");
                flag_position =0 ;
            }
            else
            {
                playerNumber=1;
            }
        }


    }




}


void getGameState(uint8_t *board, uint8_t *gameState)
{
    if(

        // Winning case
        // Same row
        (board[5]  ==  board[7]  && board[7]   ==  board[9]  )  ||
        (board[15] ==  board[17] && board[17]  ==  board[19] )  ||
        (board[25] ==  board[27] && board[27]  ==  board[29] )  ||

        // Same cloumn
        (board[5]  ==  board[15] && board[15]  ==  board[25] )  ||
        (board[7]  ==  board[17] && board[17]  ==  board[27] )  ||
        (board[9]  ==  board[19] && board[19]  ==  board[29] )  ||

        // Same diagonal
        (board[5]  ==  board[17] && board[17]  ==  board[29] )  ||
        (board[9]  ==  board[17] && board[17]  ==  board[25] )
    )
    {

        *gameState = 0;

    }
    else if(
        // Draw case

        (board[5] == board[17] && board[17] == board[19] && board[19]== board[27] && board[27] == board[25]) ||
        (board[5] == board[7] && board[7] == board[19] && board[19] == board[29] && board[29] == board[25]) ||
        (board[5] == board[7] && board[7] == board[19] && board[19] == board[27] && board[27] == board[25])
    )
    {

        *gameState = 1;
    }

    else
    {

        *gameState = 2 ;
    }

}

