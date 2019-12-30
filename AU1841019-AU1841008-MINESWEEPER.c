/*
PROJECT NAME: MINESWEEPER GAME
DONE BY: VIDISH JOSHI(AU1841019) and RUSHIL PATEL(AU1841008)
*/


/*Please read instructions in 'How to play?' section...
Please read the input syntax to play the game...
A player can use the default username and password which are:
    USERNAME: admin
    PASSWORD: admin
    One can sign in using above values.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <windows.h>


void gotoxy(int x, int y)
{
     HANDLE hConsoleOutput;
     COORD Cursor_Pos={x,y};

    hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

struct USER_DETAILS
{
	char USERNAME[30];
	char PASSWORD[30];
} user;



char USERNAME[30];
int SCORE;




int menuoptions()
{
	decor_line1();
	gotoxy(100,8);
	int a;
	printf("\n\n\n\t\t\t\t\t\t>>>>>>>>>LOG-IN OPTIONS<<<<<<<<<");
	gotoxy(100,11);
	printf("\n\n\t\t\t\t\t\t1)SIGN-IN\n");
	gotoxy(100,13);
	printf("\n\n\t\t\t\t\t\t2)SIGN-UP");
	gotoxy(100,15);
	printf("\n\n\t\t\t\t\t\tSelect an option...:");
	scanf("%d", &a);
	
	return a;
}

int login(char x[])
{
	system("color 70");
	
	int e=menuoptions(),flag=0;
	char USERNAME1[40],PASSWORD1[40];
	char ch='n';
	 FILE *fp;

	if(e==1)
	{
	
	    do
	    {
	    ch='n';
	   
	    fp=fopen("USER_DETAILS.txt","a+");
		 
		system("cls");
		decor_line1();
		gotoxy(57, 10);
		fflush(stdin);
		printf("USERNAME: ");
		gets(USERNAME1);
		gotoxy(57,12);
		fflush(stdin);
		printf("PASSWORD: ");
		gets(PASSWORD1);
	
		
		strcpy(x,USERNAME1);
					
			
			while(fread(&user,sizeof(struct USER_DETAILS),1,fp))
			{
			
				if(strcmp(user.USERNAME,USERNAME1)==0)
				{
					if(strcmp(user.PASSWORD,PASSWORD1)==0)
					{
						gotoxy(57,17);
						printf("\n\t\t\t\tAccess Granted");
						flag=1;
						break;
					}
					
				}
			}
			
			if(flag==0)
			{
				gotoxy(57,17);
				printf("\n\t\t\t\tAccess denied");
				gotoxy(57,18);
				printf("\n\t\t\t\tDo you want to retry(y/n)???");
				ch=getch();			
			}
		
	}while(ch=='y');
   }
	fclose(fp);
	if(e==2)
	{
		system("cls");
		
    	FILE *fp1;
	    fp1=fopen("USER_DETAILS.txt","a+");

        decor_line1();
        gotoxy(57,10);
		fflush(stdin);
		printf("USERNAME: ");
		gets(user.USERNAME);
		gotoxy(57,12);
		fflush(stdin);
		printf("Password:");
		gets(user.PASSWORD);
		
		fwrite(&user,sizeof(struct USER_DETAILS),1,fp1);
		
		gotoxy(54,17);
		printf("congratulations your ID has been created");
		Sleep(500);
		flag=1;
		fclose(fp1);
		strcpy(x,user.USERNAME); 
	}

    if(flag==1)
    {
	return 10;
    }
    else
    {
    	return 0;
	}
    
}

int val_gen(int y, int g, int f)
{
    int m;
    y=0;


    y=rand()%g;
    if(y<f)
    {
        y+=f;
    }

    return(y);
}

void decor_line1()
{
	int i;
    gotoxy(24, 4);
    for( i=0;i<=80;i++)
    {
        printf("%c", 178);
    }

   gotoxy(28, 5);
    for(i=0;i<=72;i++)
    {
        printf("%c", 177);
    }

    int y=5;
    for(i=0;i<=17;i++)
    {
    	gotoxy(24, y);
    	printf("%c", 178);
    	y++;
	}

	y=5;
	for(i=0;i<=17;i++)
	{
		gotoxy(25, y);
		printf("%c", 178);
		y++;
	}

	y=5;
	for(i=0;i<=17;i++)
	{
		gotoxy(26, y);
		printf("%c", 177);
		y++;
	}

	y=5;
	for(i=0;i<=17;i++)
	{
		gotoxy(27, y);
		printf("%c", 177);
		y++;
	}

    gotoxy(24, 23);
    for( i=0;i<=80;i++)
    {
        printf("%c", 178);
    }

   gotoxy(28, 22);
    for(i=0;i<=72;i++)
    {
        printf("%c", 177);
    }

    y=5;
	for(i=0;i<=17;i++)
	{
		gotoxy(101, y);
		printf("%c", 177);
		y++;
	}

	y=5;
	for(i=0;i<=17;i++)
	{
		gotoxy(102, y);
		printf("%c", 177);
		y++;
	}

	y=5;
	for(i=0;i<=17;i++)
	{
		gotoxy(103, y);
		printf("%c", 178);
		y++;
	}

	y=5;
	for(i=0;i<=17;i++)
	{
		gotoxy(104, y);
		printf("%c", 178);
		y++;
	}
}


void decor_line2()
{
    int i;
    
    
    gotoxy(10,1);
    for(i=0;i<=90;i++)
    {
    	printf("%c", 178);
	}
	
	int y=2;
	for(i=0;i<=23;i++)
	{
		gotoxy(10,y);
		printf("%c", 178);
		y++;
	}
	
	y=2;
	for(i=0;i<=23;i++)
	{
		gotoxy(11,y);
		printf("%c", 178);
		y++;
	}
	
	
	
	gotoxy(10,26);
	for(i=0;i<=90;i++)
	{
		printf("%c", 178);
	}
	
	y=2;
	for(i=0;i<=23;i++)
	{
		gotoxy(100,y);
		printf("%c", 178);
		y++;
	}
	
	y=2;
	for(i=0;i<=23;i++)
	{
		gotoxy(99,y);
		printf("%c", 178);
		y++;
	}
	
		
}



int main()
{
   
    srand(time(NULL));    //SEEDING WITH CURRENT TIME
    
    int o;
    char x[100];
    o=login(x);
    printf("%s", x);
    
    if(o!=10)
    {
    	system("cls");
    	printf("\n\n\n\t\t\t\tYOU HAVE NOT LOGGED-IN SUCCESSFULLY...\n\t\t\t\tYOU CAN'T PLAY");
    	exit (1);
	}
	
   
    system("cls");
    
    line:
    decor_line1();
    hidecursor();
    gotoxy(28,6);
    printf("Player:%s", x);
    gotoxy (57,8);
    system("color 47");
	printf("MINESWEEPER");
	Sleep(300);
	gotoxy(50, 10);
	system("color 57");
    printf("1) PLAY");
    Sleep(300);
    gotoxy(50, 11);
    system("color 47");
    printf("2) LEVEL");
    Sleep(300);
    gotoxy(50,12);
    system("color 57");
	printf("3) HOW TO PLAY?");
	Sleep(300);
	gotoxy(50,13);
	system("color 47");
    printf("4) LEADERBOARD");
    Sleep(300);
    gotoxy(50,14);
    system("color 57");
    printf("5) QUIT");
    gotoxy(45,15);
    printf("------------------------------------------\n");
    gotoxy(45,16);
    printf("------------------------------------------\n");
	gotoxy(47, 17);
    system("color 57");
    printf("Select any option from above..:");
    gotoxy(45,18);
    printf("------------------------------------------\n");
    gotoxy(45,19);
    printf("------------------------------------------\n");
    gotoxy(79,17);
    Sleep(300);
    system("color 70");
    
        
	int a;
    scanf("%d", &a);
    
    int n;


    if(a==1)
    {
        system("cls");
        decor_line1();
        gotoxy(28,6);
        printf("Player:%s", x);
        gotoxy(50, 5);
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\tDo you want to start playing in EASY level...");
        printf("\n\t\t\t\t\t1)YES\t\t\t2)NO\n\n\n\t\t\t\t\t\tPlease select an option..");
        
        int c;
        scanf("%d", &c);
        if(c==1)
        {
        	decor_line1();
           system("cls");
           n=5;
           goto line1;

        }
        else
        {
        	decor_line1();
            system("cls");
            printf("Please enter the difficulty level...");
            goto line2;

        }
        
    }

    if(a==2)
    {

        system("cls");
        goto line2;

    }

    if(a==3)
    {
        system("cls");
        FILE *fp;
        fp=fopen("rules.txt", "r");                              //USE OF FILE HANDLING......(FILE PRINTING)
        char s=0;
        do
        {
            s=getc(fp);
            printf("%c", s);
        }
        while(s!=EOF);

	    printf("\n\n\t\t\t\tPress 1 to go back to home page...:");
        int b;
        scanf("%d", &b);

        if(b==1)
        {
        	system("cls");
        	goto line;

        }
    }
    
    if(a==4)
    {
    	system("cls");                                                     //USE OF FILE HANDLING(fILE PRINTING)
    	FILE *fp2;
    	fp2=fopen("USER_SCORE.txt", "r");
    	char s=0;
    	do
    	{
    		s=getc(fp2);
    		printf("%c", s);
		}
		while(s!=EOF);
		
		printf("\n\n\t\t\t\tPress 1 to go back to home page...:");
		int b;
		scanf("%d", &b);
		
		if(b==1)
		{
			system("cls");
			goto line;
		}
	}
    
    
    if(a==5)
    {
    	gotoxy(0,50);
    	exit(0);
	}
    
    
    //CODE TO CHOOSE THE DIFFICULTY LEVEL OF THE GAME...
    
    line2:
        	
    decor_line1();
    gotoxy(28,6);
    printf("Player:%s", x);
    
    gotoxy(50, 5);
    printf("\n\n\n\n\t\t\t\t===========================================================\n");
	printf("\t\t\t\tPlease choose which difficulty level do you want to play..:\n");
	printf("\t\t\t\t===========================================================");
	printf("\n\n\n");
	printf("\t\t\t\t\t\tEASY Level - Press 1\n\t\t\t\t\t\tINTERMEDIATE LEVEL - Press 2\n\t\t\t\t\t\tHARD LEVEL - Press 3\n\n\n\t\t\t\t\t\tEnter the number now - ");
	  
    	
	int g=0;
	scanf("%d", &g);
	system("cls");

    
	if(g==1)
	   {
	   	line1:
	   	g=0;
	   	n=5;
	   }
	if(g==2)
	   {
	   	n=9;
	   }
	if(g==3)
	   {
	   	n=12;
	   }
	   
	   
   
    //CODE TO PRINT THE BOARD ACCORDING TO THE SIZE DETERMINED BY THE ABOVE CODE
	char board[n][n], i, j;
	int board1[n][n], board2[n][n];                //DECLARING AN EXTRA BOARD TO STORE THE POSITIONS OF MINE
	

	for(i=0;i<n;i++)
	  {

	  	for(j=0;j<n;j++)
	  	   {
	  	       board[i][j]='*';                //ASSIGNING ALL THE POSITIONS OF THE ORIGINAL BOARD VALUE * TO PRINT THE BOARD
	  	       board1[i][j]=0;                 //ASSIGNING ALL THE POSITIONS OF THE EXTRA BOARD THE VALUE 0 
			   board2[i][j]=0;
			 }	
		 }

  	
	
	//PRINTING THE ORIGINAL BOARD
	
	decor_line2();
	
	
	gotoxy(10,4);
	printf("\t\t\t");
	for(i=0;i<n;i++)
	  {
	  	for(j=0;j<n;j++)
	  	   {
	  	   	printf(" %c ", board[i][j]);
			 }
			 printf(" ");
		 printf("\n\t\t\t\t");
		 }
		 
	gotoxy(12,2);
    printf("Player:%s", x);
	
	gotoxy(10, 3);
	printf("\t\t\t");
	for(i=0;i<n;i++)
	{
		printf(" %d ", i);
	}
	
	int u=4;
	
	for(i=0;i<n;i++)
	{
		gotoxy(9, u);
		printf("\t\t\t");
		printf(" %d ", i);
		u++;
	}



   //CODE TO DECIDE THE NUMBER OF MINES TO BE KEPT FOR A GIVEN TYPE OF LEVEL OF MATRIX
    int m;
    
    if(n==5)
    {
        m=7;
    }
    if(n==9)
    {
        m=21;
    }
    if(n==12)
    {
        m=60;
    }
 
   
   
   //CODE TO GENERATE A RANDOM PLACE FOR MINES TO KEEP

    int k, upper=n-1, lower=0, minechecker=0;
    while(minechecker<m)
    {
       int x, y;
       
       l1:

       x=val_gen(i, upper, lower);
       y=val_gen(j, upper, lower);
       
       if(x==0&&y==0)
       {
       	goto l1;
	   }
	   if(board1[x][y]!=1)
	   {
	   	board1[x][y]=1;
	   	minechecker++;
	   }
	               
    }


   //CODE TO MAKE USER ENTER BOX NAME AND CHECK FOR MINES AT THAT BOX
    int p, q, r, number, flagcount=0, correctmines=0, score=0, scoredelete=0, flag=m;
    FILE *fptr;
    fptr=fopen("USER_SCORE.txt","a+");
    repeatentry:
    system("cls");
    decor_line2();
    gotoxy(88, 2);
    printf("SCORE::%d", score);
    gotoxy(88, 3);
    printf("FLAGS::%d", flag);
    gotoxy(84, 4);
    printf("TOTAL MINES::%d", m);


    
	
	gotoxy(10,4);
    printf("\t\t\t");
    
    for(i=0;i<n;i++)
    {
	   	for(j=0;j<n;j++)
	      {
	       	if(board[i][j]=='-')
	       	{
	       		printf(" %d ", board2[i][j]);
			}
	   	        	
	       	else
	       	{
	   	 	printf(" %c ", board[i][j]);
	        }
			
	       }
		 printf(" ");
		 printf("\n\t\t\t\t");
		   
	 }
  
	gotoxy(12,2);
    printf("Player:%s", x);
	
	gotoxy(10, 3);
    printf("\t\t\t");
	for(i=0;i<n;i++)
	{
		printf(" %d ", i);
	}
	
    u=4;
	
	for(i=0;i<n;i++)
	{
		gotoxy(7, u);
		printf("\t\t\t     ");
		printf(" %d ", i);
		u++;
	}


    gotoxy(6, 18);
    printf("\t\t\t\tDO YOU WANT TO EXPLORE A BOX?.....Press 1:");
    printf("\n\n\t\t\t\tDO YOU WANT TO FLAG A MINE?.....Press 2:");
    printf("\n\n\t\t\t\tENTER THE CO-ORDINATES HERE..:");
    scanf("%d %d %d", &p, &q, &r);
    

    
    if(r==1)
    {
     

        if(board1[p][q]==1)
        {
        	system("cls");
        	decor_line1();
        	gotoxy(50,12);
        	printf("SCORE=%d", score);
        	gotoxy(30,17);
        	printf("OOPS...\n\t\t\t\t\tGAME-OVER\n\t\t\t\t\tYOU STEPPED ON A MINE....");
        	
           	
            fprintf(fptr,"PLAYERNAME: %s ", x);
            fprintf(fptr,"PLAYERSORE: %d \n", score);
            fclose(fptr);
        	
		//	if(getch()==32)
		//		main();
        	goto end;
		}
		
        else
		{
        	number=0;
        	
        	if(p>0&&board1[p-1][q]==1)
        	{
        		number++;
			}
			if(p>0&&q>0&&board1[p-1][q-1]==1)
			{
				number++;
			}
			if(q>0&&board1[p][q-1]==1)
			{
				number++;
			}
			if(p<(n-1)&&q>0&&board1[p+1][q-1]==1)
			{
				number++;
			}
			if(p<(n-1)&&board1[p+1][q]==1)
			{
				number++;
			}
			if(p<(n-1)&&q<(n-1)&&board1[p+1][q+1]==1)
			{
				number++;
			}
			if(q<(n-1)&&board1[p][q+1]==1)
			{
				number++;
			}
			if(p>0&&q<(n-1)&&board1[p-1][q+1]==1)
			{
				number++;
			}
	
			board2[p][q]=number;
			board[p][q]='-';
			score=score+5;
			system("cls");
			
		
           // printf("Please enter next number...");
            
        }
        
    }
    
    else if(r==2)
    {
    	flag=flag-1;
    	if(board1[p][q]==1)
    	{
    		correctmines++;
		}
		else
		{
			scoredelete++;
		}
    	board[p][q]='M';
    	flagcount++;
    	score=score+5;
    	    	
	}
	
	if(flagcount==m)
	{
		if(correctmines==m)
		{
			system("cls");
			decor_line1();
			gotoxy(17,15);
			printf("Your Final SCORE is %d", score);		

			gotoxy(17, 17);
			printf("\t\t\tYOU WIN!!!!....\n\n\t\t\t\t\tYOU HAVE LOCATED ALL THE MINES");
			goto end;
		}
		
		else if(correctmines!=m)
		{
			system("cls");
			decor_line1();
			gotoxy(40,12);
			printf("Your Final Score is :: %d", score-(5*scoredelete));
			gotoxy(27, 17);
			printf("\t\t\t\tOOOH :(.....\n\t\t\t\t\tYOU LOSE..\n\t\t\t\t\tYOU DID NOT LOCATE ALL MINES AND HAVE EXHAUSTED ALL FLAGS.");
			
			if(getch()==32)
				main();
			goto end;
		}
	}
	
	goto repeatentry;
	end:
	
   gotoxy(0,30);    

return 0;

}


