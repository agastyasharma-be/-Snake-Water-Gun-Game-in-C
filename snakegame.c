#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int player, computer;
    int playerscore = 0, computerscore = 0;
    printf("=========================\n");
    printf("  SNAKE WATER GUN GAME\n");
    printf("=========================\n");
    int round = 0;
    for (int i = 0; i < 10; i++)
    {
        // RANDOM INPUT
        srand(time(0));
        computer = rand() % 3;
        printf("         ROUND %d\n", i + 1);
        printf("=========================\n");
        printf("CHOOSE \n");
        printf("0 --> SNAKE, 1 --> GUN ,2 --> WATER\n");
        scanf("%d", &player);
        char *choice[3] = {"Snake", "Gun", "Water"};
        printf("COMPUTER CHOSE: ");
        printf("%s\n", choice[computer]);
        if (player == 0 && computer == 0)
        {
            printf("ITS A DRAW!\n");
            printf("=========================\n");
        }
        else if (player == 0 && computer == 1)
        {
            printf("YOU LOSE!\n");
            printf("=========================\n");
            computerscore++;
        }
        else if (player == 0 && computer == 2)
        {
            printf("YOU WIN!\n");
            printf("=========================\n");
            playerscore++;
        }
        else if (player == 1 && computer == 0)
        {
            printf("YOU WIN!\n");
            printf("=========================\n");
            playerscore++;
        }
        else if (player == 1 && computer == 1)
        {
            printf("ITS A DRAW!\n");
            printf("=========================\n");
        }
        else if (player == 1 && computer == 2)
        {
            printf("YOU LOSE!\n");
            computerscore++;
            printf("=========================\n");
        }
        else if (player == 2 && computer == 0)
        {
            printf("YOU LOSE!\n");
            computerscore++;
            printf("=========================\n");
        }
        else if (player == 2 && computer == 1)
        {
            printf("YOU WIN!\n");
            playerscore++;
            printf("=========================\n");
        }
        else if (player == 2 && computer == 2)
        {
            printf("ITS A DRAW!\n");
            printf("=========================\n");
        }
        else
        {
            printf("WRONG INPUT!\n");
            printf("=========================\n");
        }
    }
    printf("YOUR SCORE IS: %d\n", playerscore);
    printf("COMPUTER'S SCORE IS: %d\n", computerscore);
    if (computerscore == playerscore)
    {
        printf("ITS A DRAW!\n");
    }
    else if (computerscore > playerscore)
    {
        printf("YOU LOSE!\n");
    }
    else if (computerscore < playerscore)
    {
        printf("CONGRATULATIONS\n");
        printf("YOU WIN!\n");
    }
    printf("=========================\n");

    // FILE HANDLING WORK
    FILE *ptr;
    ptr = fopen("results.txt", "a");
    fprintf(ptr, "YOUR SCORE IS: %d\n", playerscore);
    fprintf(ptr, "COMPUTER'S SCORE IS: %d\n", computerscore);
    if (computerscore == playerscore)
    {
        fprintf(ptr, "%s", "ITS A DRAW!\n");
    }
    else if (computerscore > playerscore)
    {
        fprintf(ptr, "%s", "YOU LOSE!\n");
    }
    else if (computerscore < playerscore)
    {
        fprintf(ptr, "%s", "CONGRATULATIONS\n");
        fprintf(ptr, "%s", "YOU WIN!\n");
    }

    return 0;
}