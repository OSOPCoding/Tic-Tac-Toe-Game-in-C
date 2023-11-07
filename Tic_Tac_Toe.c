/*
  This is a simple implementation of the classic Tic-Tac-Toe game in C.
  Two players take turns to mark 'X' and 'O' on a 3x3 grid. The program
  checks for win conditions and displays the winner when the game is won.
  Players enter their moves by specifying the position number according to
  the rules. The game continues until there is a winner or a draw.

  Author: OSOPCoding
*/


#include<stdio.h>
#include<conio.h>
#include<windows.h>

char arr[3][3];// 3x3 array to represent the tic-tac-toe board
int pos; // Variable to store the position entered by the player
char ch = 'O';// Variable to represent the current player ('O' starts first)
int row, col; // Variables to store the current row and column for the player's move
int f = 0;

void setup()
{
    // Initialize the game board with empty spaces
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            arr[i][j] =  ' ';
        }
    }
}

void setpos()
{
    // Convert the position entered by the player into row and column
    switch (pos)
   {
    case 1: row = 0, col = 0; break;
    case 2: row = 0, col = 1; break;
    case 3: row = 0, col = 2; break;
    case 4: row = 1, col = 0; break;
    case 5: row = 1, col = 1; break;
    case 6: row = 1, col = 2; break;
    case 7: row = 2, col = 0; break;
    case 8: row = 2, col = 1; break;
    case 9: row = 2, col = 2; break;
   }
}

void display()
{
    // Display the current state of the game board
    printf(" %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("------------\n");
    printf(" %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("------------\n");
    printf(" %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);
}

int checkwin()
{
    // Check if the current player has won the game
    if (arr[0][0] == ch && arr[0][1] == ch && arr[0][2] == ch)
      return 1;
    if (arr[1][0] == ch && arr[1][1] == ch && arr[1][2] == ch)
      return 1;
    if (arr[2][0] == ch && arr[2][1] == ch && arr[2][2] == ch)
      return 1;
    if (arr[0][0] == ch && arr[1][0] == ch && arr[2][0] == ch)
      return 1;
    if (arr[0][1] == ch && arr[1][1] == ch && arr[2][1] == ch)
      return 1;
    if (arr[0][2] == ch && arr[1][2] == ch && arr[2][2] == ch)
      return 1;
    if (arr[2][0] == ch && arr[1][1] == ch && arr[0][2] == ch)
      return 1;
    if (arr[0][0] == ch && arr[1][1] == ch && arr[2][2] == ch)
      return 1;

    return 0;
}

int main()
{
   setup();
   int i = 0;

   while (i != 9)
   {
   checkpos:
   system("cls"); // Clear the console screen
   display(); // Display the current state of the game board
   printf("Current player = %c\n", ch); // Display the current player
   printf("Enter position\n");
   scanf("%d", &pos);

   if (pos < 1 || pos > 9)
   {
      printf("Wrong position \n");
      Sleep(1000); // Pause for 1 second
      goto checkpos; // Ask the player to re-enter the position
   }

   setpos();

   if (arr[row][col] == ' ')
   {
       arr[row][col] = ch; // Update the board with the player's move
       i++; // Increment the move counter
       int c;
       c = checkwin(); // Check if the current player has won

       if (c == 1)
       {
          system("cls"); // Clear the console screen
          display(); // Display the final state of the board
          printf("Player %c wins the game\n", ch);
          Sleep(2000); // Pause for 2 seconds
          printf("Thanks for playing");
          return 1;
       }

       if (f == 0)
       {
          ch = 'X'; // Switch to the other player
          f = 1; // Toggle the player flag
       }
       else
       {
         ch = 'O'; // Switch to the other player
         f = 0; // Toggle the player flag
       }

   }
   else
   {
       printf("Element already occupied \n");
       Sleep(1000); // Pause for 1 second
       goto checkpos; // Ask the player to re-enter the position
   }

   }
   system("cls"); // Clear the console screen
   display(); // Display the final state of the board
   printf("Game draw\n");
   printf("Thanks for playing");
   Sleep(2000); // Pause for 2 seconds
   return 0;
}
