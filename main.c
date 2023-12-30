#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define Left 75
#define Right 77
#define Esc 27
#define Enter 13
#define End 79
#define Home 71
#define Del 83
#define Backspace 8
#define Tab 9
#define Ins 82

void printchars(char *arr, int size){
    int i=0;
    for(int i=0; i<size; i++){
        if(arr[i]!='\0'){
            printf("%c", arr[i]);
        }else{
            break;
        }
    }
}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
struct Employee{
    int id;
    char name[10];
    int age;
    float salary;
    float commission;
    float deduction;
};
char* LineEditor(int size,int col,int row,int startKey,int endKey)
{
    char *arr;
    arr=malloc(size * sizeof(char));
    int f=0;
    int l=0;
    int c = 0;
    char *Fp = arr;
    char *Lp = arr;
    char *C = arr;
    int flag = 1;
    char ch;
    do{
        gotoxy(col+c,row);
        ch=getch();
        if(ch==-32){
            ch=getche();
            switch(ch){
                case Left:
                    if(c > 0){
                     c--;
                     C--;
                    }
                break;
                case Right:
                    if(c < l){
                     c++;
                     C++;
                    }
                break;
                case Home:
                    c = 0;
                break;
                case End:
                    c = l-1;
                break;
                case Del:
                    if(c < l) {
                        for(int i=0; i<l; i++) {
                            arr[c+i]=arr[c+1+i];
                        }
                        arr[l-1]='\0';
                        l--;
                        Lp--;
                        gotoxy(col, row);
                        printf("%s",arr);
                        arr[l-1]='\0';
                    }
                break;
                case Ins:
                    if(l!=size){
                        ch=getch();
                        Lp++;
                        l++;
                        for(int i=l; i>c; i--) {
                            arr[i]=arr[i-1];
                        }
                        arr[c]=ch;
                        arr[l]='\0';
                        gotoxy(col, row);
                        printf("%s",arr);
                    }
                break;
            }
        }else{
            switch(ch){
                case Enter:
                    flag=0;
                break;
                case Backspace:
                        Lp--;
                        l--;
                        C--;
                    if(c>0) {
                        for(int i=0; i<l; i++) {
                            arr[c-1+i]=arr[c+i];
                        }
                        c--;
                        //arr[l]='\0';
                        gotoxy(col, row);
                        printchars(arr,size);
                    }
                break;
                default:
                   if(c<size && isprint(ch)!=0 &&ch>=startKey&&ch<=endKey){
                    if(c==l){
                     Lp++;
                     l++;
                    }
                     arr[c]=ch;
                     arr[l]='\0';
                     //printf("%c", ch);
                     c++;
                    }
                break;
            }
            }
            gotoxy(col,row);
            printf("                 ");
            gotoxy(col,row);
            printf("%s",arr);

    }while(flag==1);
    return arr;
}
struct Employee empArr[10];
int main()
{
    char data[6][20]={"id", "name", "age", "salary", "commission", "deduction"};
    for(int i=0;i<1;i++){
        for(int i=0; i<6; i++){
            if(i%2==0){
                gotoxy(10,10+i+3);
            }else{
                gotoxy(70,10+i+3);
            }
            printf("%s:",data[i]);
        }

        empArr[i].id=atoi(LineEditor(10,15,13,48,57));

        _flushall();
        strcpy(empArr[i].name,LineEditor(10,75,14,97,122));

        _flushall();

        empArr[i].age=atoi(LineEditor(3,15,15,48,57));

        empArr[i].age=atof(LineEditor(10,78,16,48,57));

        empArr[i].commission=atof(LineEditor(10,22,17,48,57));

        empArr[i].commission=atof(LineEditor(10,81,18,48,57));

        system("cls");
    }

        printf("id %i \n", (empArr[0].id));
        printf("Name ");
        puts(empArr[0].name);

        printf("net salary %f \n", (empArr[0].salary+empArr[0].commission-empArr[0].deduction));

    return 0;
}
