#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


void removeLF( char playerChoice[] ) {
    while( *playerChoice++ )
        if( *playerChoice == '\n' )
            *playerChoice = '\0';
}

void convertChoice( char playerChoice[] ) {
    while( *playerChoice ) {
        *playerChoice = toupper( *playerChoice );
        playerChoice++;
    }
}

void printScore( int playerScore, int botScore ) {
    printf( "You %d x %d Bot\n", playerScore, botScore );
}

int matchOutcome( char playerChoice[], int botChoice, int * playerScore, int * botScore ) {
    if(     ( !(strcmp( playerChoice, "ROCK"     )) && botChoice == 2   )
        ||  ( !(strcmp( playerChoice, "PAPER"    )) && botChoice == 0   )
        ||  ( !(strcmp( playerChoice, "SCISSORS" )) && botChoice == 1   ) ) {
            printf( "You won!\n" );
            (*playerScore)++;
            printScore( *playerScore, *botScore );
            return 1;
        }
    if(     ( !(strcmp( playerChoice, "ROCK"     )) && botChoice == 0   )
        ||  ( !(strcmp( playerChoice, "PAPER"    )) && botChoice == 1   )
        ||  ( !(strcmp( playerChoice, "SCISSORS" )) && botChoice == 2   ) ) {
            printf( "It's a tie!\n" );
            printScore( *playerScore, *botScore );
            return 3;
        }
            printf( "You lost.\n" );
            (*botScore)++;
            printScore( *playerScore, *botScore );
            return 2;
}

int main( void ) {
    srand( time(NULL) );
    char * playerChoice = NULL;
    int botChoice, err;
    int playerScore = 0, botScore = 0;
    size_t bufferSize;
    while( 1 ) {
        printf( "Enter your choice: (scissors, paper, rock)\n" );
        while( (err = getline( &playerChoice, &bufferSize, stdin )) ) {
            removeLF( playerChoice );
            convertChoice( playerChoice );
            if( err == EOF )
                break;
            if( strcmp( playerChoice, "ROCK" ) && strcmp( playerChoice, "PAPER" ) && strcmp( playerChoice, "SCISSORS" ) ) {
                    printf( "Choose either ROCK or PAPER or SCISSORS!\n" );
                    printf( "\n" );
                    break;
            }
            
            botChoice = rand() % 3; //  0 - Rock    |   1 - Paper   |   2 - Scissors 
            if( botChoice == 0 ) printf( "Bot chose rock!\n" );
            if( botChoice == 1 ) printf( "Bot chose paper!\n" );
            if( botChoice == 2 ) printf( "Bot chose scissors!\n" );
            
            matchOutcome( playerChoice, botChoice, &playerScore, &botScore );
            printf( "\n" );
            break;
        }
        if( err == EOF )
            break;
    }
    free( playerChoice );
    return 0;
}