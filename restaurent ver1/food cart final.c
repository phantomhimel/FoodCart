#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
void addfood();
void admin();
void gotoxy(short x, short y);
void worker();
void viewfood();
void animation();
void ascii_line(int);
void workersell();
void banner();
void viewsellfood();
void foodsave();
void resetdata();
void foodread();
void sellsave();
void sellread();

int f=0,g=0;

struct food
{
    char name[20];
    int tk;
}fd[100];

struct sell
{
    char name[20];
    int tk;
    int amnt;
    char tim[25];
    int sum;
}bill[100];

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ascii_line(int k){

	int j;
	for(j=0;j<30;j++)
	printf("%c",k);
}
void animation()
{
    int i;
    printf("\n\n");
    for(i=1; i<=100; i++)
    {
        printf("\r\t\t\t\t\t\t\t\tL o a d i n g . . . %d%%",i);
        Sleep(12);
    }
}
void banner()
{
    char ch[]="WELCOME TO KHAI KHAI FOODCART";
    int i;
    printf("\n\t\t\t");
    for(i=0; i<10; i++)
    {
        Sleep(20);
        printf("%c", 178);
    }
    for(i=0; i<ch[i]; i++)
    {
        Sleep(20);
        printf(" %c", ch[i]);
    }
    printf(" ");
    for(i=0; i<10; i++)
    {
        Sleep(20);
        printf("%c", 178);
    }
}
int main()
{
    foodread();
    sellread();
    int b;
    system("mode 200");gotoxy(50,2);printf("SELECT THEME");gotoxy(41,3);ascii_line(196);
    gotoxy(10,5);printf("1. Light"); gotoxy(10,6);printf("2. Dark");gotoxy(7,8);printf("Enter choice: ");gotoxy(21,8);scanf("%d", & b);
    if (b==1)
    {
        system("cls");
        system("color 3F");
        goto D;
    }
    else if (b==2)
    {
        system("cls");system("color 0A");goto D;
    }
D:  banner();
    int m;
    gotoxy(50,6);
    printf("Press--");gotoxy(55,7); printf("-> 1. Admin"); gotoxy(55,8); printf("-> 2. Worker");gotoxy(55,9);printf("-> 3. Exit"); gotoxy(39,12);printf("Enter choice::: ");
    gotoxy(55,12);
    scanf("%d", &m);
    if (m==1)
    {
        animation();
        system("cls");
        admin();
    }
    else if (m==2)
    {
        animation();
        system("cls");
        worker();
    }
    else if (m==3)
    {
        gotoxy(50,5);printf("THANX FOR USING THE SYSTEM");
        gotoxy(2,10);exit(0);
    }
    else
    {
        printf("\awrong choice");
        getch();
        system("cls");
        main();
    }
}

void admin()
    {
    int pass=123456,ch;
    gotoxy(45,10);
    printf("Enter password: ");
    scanf("%d", &ch);
    if (ch==pass)
    {
    system("cls");
    int n,m;
    A:  gotoxy(60,0);
    ascii_line(219);
    gotoxy(67,2);
    printf("ADMIN OPTION");
    gotoxy(60,4);
    ascii_line(219);
    gotoxy(35,8); printf("Choose option from below--"); gotoxy(60,9);printf("-> 1. Add todays menu and price");gotoxy(60,10);printf("-> 2. View food");
    gotoxy(60,11);printf("-> 3. View sell");gotoxy(60,12); printf("-> 4. Reset data");gotoxy(60,13); printf("-> 5. Exit");gotoxy(47,15); printf("Enter choice::: ");
    gotoxy(62,15);
    scanf("%d", &n);
    if (n==1)
    {
        addfood();
        goto A;
    }
    else if (n==2)
    {
        viewfood();
        goto A;
    }
    else if (n==3)
    {
        viewsellfood();
        goto A;
    }
    else if (n==4)
    {
        resetdata();
    }
    else if (n==5)
    {
        exit(0);
    }
    else
    {
        gotoxy(62,18);
        system("cls");
        printf("\a!! wrong choice !!");
        goto A;
    }
    }
    else{
            gotoxy(45,15);
        printf("\a !! Access denied !! Try again\n\n\n\n");
        system("pause");
        system("cls");
        admin();
    }

}
void addfood()
{
    system("cls");
D:  gotoxy(60,0);
    ascii_line(219);
    gotoxy(63,2);
    printf("INPUT FOOD NAME AND PRICE");
    gotoxy(60,4);
    ascii_line(219);
    int m,k;
    do{
            printf("\n\nEnter food name         : ") ;
            scanf("%s", fd[f].name);
            printf("\nEnter price of the food : ");
            scanf("%d", &fd[f].tk);
            foodsave();
            f++;
            foodsave();
            printf("\nPress 1 to continue and press 0 to exit: ");
            scanf("%d", &m);
            ascii_line(45);
        }while(m!=0);
        printf("\n\n\n\t\t\t\t\t\t\t");
        ascii_line(254);
        printf("\n\t\t\t\t\t\t\t     Name and price uploaded\n\t\t\t\t\t\t\t");
        ascii_line(254);
        getch();
        system("cls");
}
void viewfood()
{
    system("cls");
    foodread();
    gotoxy(50,1);
    ascii_line(219);
    gotoxy(58,3);
    printf("VIEW FOOD");
    gotoxy(50,5);
    ascii_line(219);
    gotoxy(50,8);printf("Food name");gotoxy(50,9); printf("---------");gotoxy(70,8); printf("Price");gotoxy(70,9);printf("-----");
    int k;
    for(k=0; k<f; k++)
    {
        gotoxy(50,k+11);
        printf("%s", fd[k].name);
        gotoxy(70, k+11);
        printf("%d", fd[k].tk);
    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}
void viewsellfood()
{
    sellread();
    system("cls");
    gotoxy(60,1);
    ascii_line(219);
    gotoxy(68, 3);
    printf("VIEW ALL SELL");
    gotoxy(60, 5);
    ascii_line(219);
    gotoxy(40,8); printf("Food name");gotoxy(40,9); printf("_________");gotoxy(60,8);printf("Price");gotoxy(60,9);printf("_____");
    gotoxy(80,8);printf("Amount");gotoxy(80,9);printf("______");gotoxy(100,8);printf("Total price");gotoxy(100,9);printf("___________");
    int j,total=0;
    for(j=0; j<g; j++)
    {
        gotoxy(40,j+11);
        printf("%s", bill[j].name);
        gotoxy(60, j+11);
        printf("%d", bill[j].tk);
        gotoxy(80,j+11);
        printf("%d", bill[j].amnt);
        gotoxy(100,j+11);
        printf("%d\n", bill[j].sum);
        total= total+bill[j].sum;
    }
    printf("\n\n\n\n");
    printf("\t\tTotal sell is::: %d BDT\n\n", total);
    system("pause");
    system("cls");
}
void resetdata()
{
    system("cls");
    char ch;
    int i;
    gotoxy(50,1);
    ascii_line(178);
    gotoxy(60,3);
    printf("RESET DATA");
    gotoxy(50,5);
    ascii_line(178);
    printf("\n\n\tOnce you delete your data you'll be never able use them. Do you still want to cotinue? (Press 'y' for yes and 'n' for no)");
    printf("\n\tEnter choice:: "); ch=getch();printf("\n\n\n");
    if (ch=='y')
    {
          remove("test.txt");remove("test1.txt");remove("test2.txt");remove("test3.txt");
        for(i=10; i>=0; i--)
        {
              printf("\r\t\t\t\t\t\tDeleting data. Your program will be closed after %d seconds..", i);
              Sleep(1000);
        }
        system("cls");
        exit(0);
    }
    else if (ch=='n')
    {
        system("cls");
    }
    else{
        printf("\a!! Wrong choice!!\n");
        getch();  system("cls"); resetdata();
    }
}

void worker()
{
    int m;
    gotoxy(50,1);
    ascii_line(219);
    gotoxy(59,3);
    printf("Worker Option");
    gotoxy(50,5);
    ascii_line(219);
    gotoxy(45,8);printf("Press--");gotoxy(50,9);printf(" -> 1. Sell food");gotoxy(50,10);printf(" -> 2. View available food name");gotoxy(50,11);printf(" -> 3. Exit");gotoxy(39,13);printf("Enter chioce: ");
    gotoxy(52,13);scanf("%d", &m);
    if (m==1)
    {
        workersell();
    }
    else if (m==2)
    {
        viewfood();
        system("cls");
        worker();
    }
    else if(m==3)
    {
        exit(0);
    }
    else
    {gotoxy(52,15);
        printf("!! Wrong choice !!");
        Sleep(30);
        system("cls");
        worker();
    }
}
void workersell()
{
    system("cls");
C:  gotoxy(50,1);
    ascii_line(219);
    gotoxy(60,3);
    printf("WELCOME");
    gotoxy(50,5);
    ascii_line(219);
    char name[20];
    time_t t;
    time(&t);
    int amt=0,m,count=0, total=0,i, flag=0;
    do
    {
        printf("\n\nEnter food name (case sensetive)       : ");
        scanf("%s", bill[g].name);
        for(i=0; i<f; i++)
        {
        if (strcmp(fd[i].name,bill[g].name)==0)
        {
            printf("\nPrice of %s is                     : %d", bill[g].name, fd[i].tk);
            bill[g].tk=fd[i].tk;
            printf("\n\nEnter amount                           : ");
            scanf("%d", & bill[g].amnt);
            bill[g].sum= bill[g].amnt*bill[g].tk;
            printf("\nBill for %d %s is                   : %d",bill[g].amnt, bill[g].name, bill[g].sum);
            total=total+bill[g].sum;
            count++;
            flag=1;
        }
        }
         if(flag==0)
        {
            printf("\n\n\t\a!! Wrong name !!");
            getch();
            system("cls");
            goto C;
        }
        sellsave();
        g++;
        sellsave();
        printf("\n\nPress 1 to add another food or press 0 to calculate total bill ");
        scanf("%d", &m);
        ascii_line(45);
    }while(m!=0);
    int money=0,totalsum=0;
    printf("\n\nYour total bill for %d food is : %d\n\n", count,total);
    printf("Money recieved                : ");
    scanf("%d", &money);
    totalsum= money-total;
    printf("\nChange                        : %d", totalsum);
    printf("\n\nBuying date and time          : %s", ctime(&t));
    printf("\n\n\n\t\t\t\t\t");
    ascii_line(254);
    printf("\n\t\t\t\t\t\tThank You\n\t\t\t\t\t");
    ascii_line(254);
B:  printf("\n\n\nPress 1 to continue and 0 to go back to main menu: ");
    scanf("%d", & m);
    if (m==1)
    {
        system("cls");
        workersell();
    }
    else if(m==0)
    {
        system("cls");
        worker();
    }
    else
    {
        printf("\a !! Wrong choice !!");
        goto B;
    }
}

void foodsave()
{
    FILE *fp;
    fp= fopen("test.txt", "w");
    fwrite(&fd, sizeof (fd), 1, fp);
    fclose(fp);
    FILE *fp1;
    fp1= fopen("test1.txt", "w");
    fwrite(&f, sizeof (f), 1, fp1);
    fclose(fp1);
}
void foodread()
{
    FILE *fp;
    fp= fopen("test.txt", "r");
    fread(&fd, sizeof (fd), 1, fp);
    fclose(fp);
    FILE *fp1;
    fp1= fopen("test1.txt", "r");
    fread(&f, sizeof (f), 1, fp1);
    fclose(fp1);
}
void sellsave()
{
    FILE *fp2;
    fp2= fopen("test2.txt", "w");
    fwrite(&bill, sizeof (bill), 1, fp2);
    fclose(fp2);
    FILE *fp3;
    fp3= fopen("test3.txt", "w");
    fwrite(&g, sizeof (g), 1, fp3);
    fclose(fp3);
}
void sellread()
{
    FILE *fp2;
    fp2= fopen("test2.txt", "r");
    fread(&bill, sizeof (bill), 1, fp2);
    fclose(fp2);
    FILE *fp3;
    fp3= fopen("test3.txt", "r");
    fread(&g, sizeof (g), 1, fp3);
    fclose(fp3);
}
