#include<stdio.h>
#include<string.h>
#include "Tic-Tac-Toe_v2.c"
#include "Test_Tic-Tac-Toe.c"
char x,o;
char a[9]={'1','2','3','4','5','6','7','8','9'};
char u1[50],u2[50];
int main()
{
    FILE *p;
    p=fopen("score.txt","a+");
    fclose(p);
    system("color 09");
    int player=1;
    int choice,score=-1;
    char symbol,re;
    char start,dec;
    int s;
    rules();
    printf("\n\nType 1 to start the game:-\nType 2 to view leader board:-\n");
    scanf("%d",&s);
    if(s==1)
    {
    read:
        p=fopen("score.txt","a+");
    printf("\nEnter name of player1: ");
    scanf("%s",u1);
    fprintf(p,"\n%s",u1);
    printf("Enter name of player2: ");
    scanf("%s",u2);
    fprintf(p,"\t%s",u2);
    fclose(p);
    if(!strcmp(u1,u2))
    {
        printf("Enter names of different players!\n\n");
        goto read;
    }
    else
        decision();


    system("color fc");
    board();

    do
    {

        player=((player%2)?1:2);
        if(player==1)
        printf("%s Type any digit from 1-9 to fill your response:- ",u1);
        else
            printf("%s Type any digit from 1-9 to fill your response:- ",u2);
        scanf("%d",&choice);
        symbol=((player==1)?x:o);
        if(choice==1 && a[0]=='1')
            a[0]=symbol;
        else if(choice==2 && a[1]=='2')
            a[1]=symbol;
        else if(choice==3 && a[2]=='3')
            a[2]=symbol;
        else if(choice==4 && a[3]=='4')
            a[3]=symbol;
        else if(choice==5 && a[4]=='5')
            a[4]=symbol;
        else if(choice==6 && a[5]=='6')
            a[5]=symbol;
        else if(choice==7 && a[6]=='7')
            a[6]=symbol;
        else if(choice==8 && a[7]=='8')
            a[7]=symbol;
        else if(choice==9 && a[8]=='9')
            a[8]=symbol;
        else
            {printf("Wrong Selection\n");player--;}

        score=checkforwin();
        player++;
        board();
    }while(score == -1);


    p=fopen("score.txt","a+");
    if(score==1)
    {

        if(player==2)
        {printf("\n\nPlayer1 %s Wins!\n\n",u1);fprintf(p,"\t%s",u1);
        getch();}
        else
            {printf("\n\nPlayer2 %s Wins!\n\n",u2);fprintf(p,"\t%s",u2);
        getch();
            }
        fclose(p);
    }
    else
        printf("\n\nGame Draws!\n\n");fprintf(p,"\t%s","DRAW");
        getch();
    }
    if(s==2)
    {
        int cho;
        system("cls");
        printf("\n\n");
        printf("\tLEADERBOARD\n\n");
        char c;
        p=fopen("score.txt","r");
        while((c=getc(p))!=EOF)
        {
            printf("%c",c);
        }
        fclose(p);
        printf("\n\nPress 1 to start the game:- ");
        scanf("%d",&cho);
        if(cho==1)
            goto read;
        else
            getch();
    }
    else
    {
        printf("\n\nShould have typed 1 to play the game!\nHope to see you back soon!\n\n");
        getch();
    }
}