
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//-g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
//valgrind -s

void free_board(char **board, int board_size)
{
    int i;

    i = 0;
    while (i < board_size)
    {
        free(board[i]);
        ++i;
    }
    free (board);
    return;
}

char **make_board(int board_size)
{
    int i;
    int j;
    char **board;

    i = 0;
    board = malloc (sizeof (char *)  * (board_size ));
    if (!board)
        return (0);
    while (i < board_size)
    {
        j = 0;
        board[i] = malloc (sizeof(char) * (board_size + 1));
        board[i][board_size] = '\0';
        while (j < board_size)
        {
            ++j;
        }
        ++i;
    }
    return (board);
}

void print_solution(char **board, char board_size)
{
    int i;
    int j;
    i = 0;
    j = 0;

    while (j < board_size)
    {
        i = 0;
        while (i < board_size)
        {
            if (board[i][j] == 'Q')
                printf("%d ", i);
            ++i;
        }
        ++j;
    }
    printf("\n");
    return;
}


char **print_board(char **board, int board_size)
{
    int i;
    int j;

    i = 0;
    printf ("\n");
    while (i < board_size)
    {
        j = 0;
        while (j < board_size)
        {
            printf("%c ", board[i][j]);
            ++j;
        }
        printf ("\n");
        ++i;
    }
     printf ("\n");
    return (board);
}


char **clear_board(char **board, int board_size)
{
    int i;
    int j;

    i = 0;
    while (i < board_size)
    {
        j = 0;
        while (j < board_size)
        {
            board [i][j] = '.';
            ++j;
        }
        ++i;
    }
    return (board);
}

int is_safe (char **board, int board_size, int a, int b)
{
    int i;
    int j;

    i = a - 1;
    j = b;
    ///is safe col ?
    while (i >= 0)
    {
        if (board[i][j] == 'Q')
            return (0);
        --i;
    }
    ///  is safe row?
    i = a;
    j = b - 1;
    while (j > 0)
    {
        if (board[i][j] == 'Q')
            return (0);
        --j;
    }
    //is safe diagonal ?
    i = a - 1;
    j = b - 1;
    while(i >= 0 && j >= 0)
    {
       if (board[i][j] == 'Q')
            return (0);
        --i;
        --j;
    }
    i = a - 1;
    j = b + 1;
    while(i >= 0 && j < board_size)
    {
       if (board[i][j] == 'Q')
            return (0);
        --i;
        ++j;
    }
    return (1);
}

int queen_to_row(char **board, int board_size, int i, int queen)
{
    int j;

    // first you have to try if you reach the en of board !!!! 


    if (i == board_size)                        // if you reach the size of board, you stop here !!!!!
    {
         if (queen == board_size)                // only if you have solution, you will print something
         {
            print_solution(board, board_size);
           // print_board(board, board_size);   //u can use this function for see result
            return (1);
         }
         return(0);
    }

    // if you are not at the end of board, you can continue 

    j = 0;
    while (j < board_size)
    {
        if (is_safe(board, board_size, i, j))
        {
            board[i][j] = 'Q';                                 // put queen to [i][j] for try queen_to_row for rest of board 
            queen_to_row(board, board_size, i+1, queen+1);     // function lives it's own life 
            board[i][j] = '.';                                 // clear [i][j] for put queen to next [j]
        }
        j++;
    }
    return (0);
}

int main (int argc, char *argv[])
{
    int i;
    int j;
    int queen;
    int board_size;
    char **board;

    if (argc !=2)
        return (0); 

    board_size = atoi(argv[1]);
    i = 0;
    j = 0;
    queen = 0;
    
    board = make_board(board_size);     // allocate board
    clear_board (board, board_size);    // need to fill all board with '.'
    queen_to_row(board, board_size, i, queen);
    free_board(board, board_size);
    return(0);
}