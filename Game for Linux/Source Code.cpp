#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>

char getch() {//get char without press enter
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

bool isEqual_3(int a,int b,int c){//check equal
    if(a==b && b==c)
    return 1;
return 0;
}

using namespace std;

class XO{
private:

int Board[5][5]={ //0->Boundary | 1->Free | 2->X | 3->O | 4->Cursor
    {0,0,0,0,0},
    {0,4,1,1,0},
    {0,1,1,1,0},
    {0,1,1,1,0},
    {0,0,0,0,0}
    };

    bool turn=0; //0->X | 1->O

    char input; //input of user

    int CursorIndx[2]={1,1}; //Cursor coordinates

    int cursorTemp=1; // The value that the cursor is hiding

public:
    void printBoard(){ //Print Board
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
        if(Board[i][j]==1)
                cout<<"\033[1;46m   \033[0m";
            else if(Board[i][j]==2)
                cout<<"\033[1;46m X \033[0m";
            else if(Board[i][j]==3)
                cout<<"\033[1;46m O \033[0m";
        else{
        if(turn){
            if(cursorTemp==2)
                cout<<"\033[1;42m X \033[0m";
            else if(cursorTemp==3)
                cout<<"\033[1;42m O \033[0m";
            else if(cursorTemp==1)
                cout<<"\033[1;42m   \033[0m";
                }

        else{
            if(cursorTemp==2)
                cout<<"\033[1;41m X \033[0m";
            else if(cursorTemp==3)
                cout<<"\033[1;41m O \033[0m";
            else if(cursorTemp==1)
                cout<<"\033[1;41m   \033[0m";
                }
        }
        }
    cout<<"\n";
    }
    }

    void setInput(char x){ //Get input from the user
    input=x;
    }

    bool getTurn(){ // knowing X or O
    return turn;
    }

    void moveCursor(){ // To move cursor using 'w','s','a','d'
    if( (input=='s'||input=='S') && Board[CursorIndx[0]+1][CursorIndx[1]]){
    Board[CursorIndx[0]][CursorIndx[1]]=cursorTemp;
    CursorIndx[0]++;
    cursorTemp=Board[CursorIndx[0]][CursorIndx[1]];
    Board[CursorIndx[0]][CursorIndx[1]]=4;
    }
    else if( (input=='w'||input=='W') && Board[CursorIndx[0]-1][CursorIndx[1]]){
    Board[CursorIndx[0]][CursorIndx[1]]=cursorTemp;
    CursorIndx[0]--;
    cursorTemp=Board[CursorIndx[0]][CursorIndx[1]];
    Board[CursorIndx[0]][CursorIndx[1]]=4;
    }
    else if( (input=='d'||input=='D') && Board[CursorIndx[0]][CursorIndx[1]+1]){
    Board[CursorIndx[0]][CursorIndx[1]]=cursorTemp;
    CursorIndx[1]++;
    cursorTemp=Board[CursorIndx[0]][CursorIndx[1]];
    Board[CursorIndx[0]][CursorIndx[1]]=4;
    }
    else if( (input=='a'||input=='A') && Board[CursorIndx[0]][CursorIndx[1]-1]){
    Board[CursorIndx[0]][CursorIndx[1]]=cursorTemp;
    CursorIndx[1]--;
    cursorTemp=Board[CursorIndx[0]][CursorIndx[1]];
    Board[CursorIndx[0]][CursorIndx[1]]=4;
    }
    }

    void select(){ //To select by clicking 'c'
    if(turn && cursorTemp==1){//O
    Board[CursorIndx[0]][CursorIndx[1]]=3;
    cursorTemp=3;
    turn=0;
    }
    else if(!turn && cursorTemp==1){//X
    Board[CursorIndx[0]][CursorIndx[1]]=2;
    cursorTemp=2;
    turn=1;
    }
    }

    bool checkWin(){ // To check if there is a winner
    for(int i=1;i<4;i++){
    if(isEqual_3(Board[i][1],Board[i][2],Board[i][3]) && (Board[i][3]==2||Board[i][3]==3))
    return 1;
    else if(isEqual_3(Board[1][i],Board[2][i],Board[3][i]) && (Board[3][i]==2||Board[3][i]==3))
    return 1;
    }
    if(isEqual_3(Board[1][1],Board[2][2],Board[3][3]) && (Board[2][2]==2||Board[2][2]==3))
    return 1;
    else if(isEqual_3(Board[1][3],Board[2][2],Board[3][1]) && (Board[2][2]==2||Board[2][2]==3) )
    return 1;

    return 0;
    }

    void randomPlay(){
    while(cursorTemp!=1){
    srand(time(0));
    int downTimes=rand()%3,upTimes=rand()%3,leftTimes=rand()%3,rightTimes=rand()%3;
    while(downTimes--){
        this->setInput('s');
        this->moveCursor();
    }
    while(upTimes--){
        this->setInput('w');
        this->moveCursor();
    }
    while(leftTimes--){
        this->setInput('a');
        this->moveCursor();
    }
    while(rightTimes--){
        this->setInput('d');
        this->moveCursor();
    }
    }
    this->setInput('c');
    this->select();
    }

};

int main()
{
bool again=0;
int CorF=0;
char input;
cout<<"Welcome to my X-O game devoloped by Mohab Elshamy\n\n";
do{
cout<<"Do you want to play against computer or your friend?\n";
cout<<"1- with computer\n2- with my friend\nSelect: ";
cin>>CorF;

if(CorF==2){
system("clear");
cout<<"use \'w\' \'a\' \'s\' \'d\' to move and \'c\' to choose\n(remeber to change your keyboard to english if isn't)\n";
XO friendXO;
while(!friendXO.checkWin()){
    friendXO.printBoard();
    input=getch();
    friendXO.setInput(input);
    if(input==99||input==67)
    friendXO.select();
    else
    friendXO.moveCursor();
    system("clear");
}
friendXO.getTurn()?cout<<"-> \033[1;31mX player\033[0m is the winner <-\n":cout<<"-> \033[1;32mO player\033[0m is the winner <-\n";
}
//------------------------------------->computer
else{
system("clear");
cout<<"use \'w\' \'a\' \'s\' \'d\' to move and \'c\' to choose\n(remeber to change your keyboard to english if isn't)\n";
XO computerXO;
while(!computerXO.checkWin()){
    computerXO.printBoard();
    if(computerXO.getTurn())
    computerXO.randomPlay();

    else{
    input=getch();
    computerXO.setInput(input);
        if(input==99||input==67)
        computerXO.select();
        else
        computerXO.moveCursor();
    }
    system("clear");
}
computerXO.getTurn()?cout<<"-> \033[1;31mYou\033[0m are the winner <-\n":cout<<"-> \033[1;32mComputer\033[0m is the winner <-\n";

}
cout<<"\nDo you want to play again (y/n)\n";
char s;
s=getch();
if(s=='y')
again=1;
system("clear");
}while(again);

return 0;
}
