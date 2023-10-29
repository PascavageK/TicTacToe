#include <stdio.h>

//Draws the tic tac toe board to the consol
void drawBoard(char boardState[]) {
    printf("\n\n%c | %c | %c\n---------", boardState[0], boardState[1], boardState[2]);
    printf("\n%c | %c | %c\n---------", boardState[3], boardState[4], boardState[5]);
    printf("\n%c | %c | %c", boardState[6], boardState[7], boardState[8]);
}

//Checks for a winner; returns: 0 if no winner, 1 if O won, 2 if X won
int checkWin(char boardState[]) {
    int checkO = 0;
    int checkX = 0;

    //Loop for verticle and horizantle win check
    for (int i = 0; i < 3; i++) {
        checkO = 0, checkX = 0;

        //Loop for verticle win
        for (int x = i; x < 8; x += 3) {
            if (boardState[x] == 79) checkO += 1;
            if (boardState[x] == 88) checkX += 1;
        }
        if (checkO == 3) {printf("vert 1"); return 1;}
        else if (checkX == 3) return 2;
        
        checkO = 0, checkX = 0;

        //Loop for horizantle win
        if (i == 0) for (int x = 0; x < 3; x++) {
            if (boardState[x] == 79) checkO += 1;    
            if (boardState[x] == 88) checkX += 1;
        }
        else if (i == 1) for (int x = 3; x < 6; x++) {
            if (boardState[x] == 79) checkO += 1;
            if (boardState[x] == 88) checkX += 1;
        }
        else for (int x = 6; x < 9; x++) {
            if (boardState[x] == 79) checkO += 1;
            if (boardState[x] == 88) checkX += 1;
        }
        if (checkO == 3) return 1;
        else if (checkX == 3) return 2;
    }
    
    checkO = 0, checkX = 0;

    //Cross checks
    if ((boardState[0]+boardState[4]+boardState[8])%79 == 0 ||
        (boardState[2]+boardState[4]+boardState[6])%79 == 0) return 1;
    else if ((boardState[0]+boardState[4]+boardState[8])%88 == 0 ||         
             (boardState[2]+boardState[4]+boardState[6])%88 == 0) return 2;

    //If no winner
    return 0;
}

//Move select
int playerMove(char player) {
    int space;

    printf("\n\nPlayer %c:", player);
    scanf("%d", &space);

    return space;
}

//Opening sequence
int mainMenu() {
    int play = 65;

    printf("\nWould you like to play? (1/0): ");
    scanf("%d", &play);

    if (play == 1) return 1;
    return 0;
}

//Adds all ascii values in a char array
int evalCharArray(char charArray[]) {
    int total = 0;
    //int arrayLength = sizeof(charArray)/sizeof(charArray[0]); 

    for (int i = 0; i < 9/*arrayLength*/; i++) {
        total += charArray[i];
    }
    return total;
}

//main!
int main() {
    //Board
    char boardState[] = {48, 49, 50, 51, 52, 53, 54, 55, 56};

    //Game loop
    if (mainMenu()) {
        while (evalCharArray(boardState) < 756 && checkWin(boardState) == 0) {
            drawBoard(boardState);
            boardState[playerMove(88)] = 88;
            drawBoard(boardState);
            if (evalCharArray(boardState) == 756 || checkWin(boardState) != 0) break;
            boardState[playerMove(79)] = 79;
            drawBoard(boardState);
        }
        
        switch (checkWin(boardState)) {
            case 1:
                printf("\n\nPlayer O wins!");
            case 2:
                printf("\n\nPlayer X wins!");
            default:
                printf("\n\nIt is a tie!");
        }
        main();
    }
    return 0;
}

