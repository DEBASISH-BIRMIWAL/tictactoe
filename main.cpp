#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;


char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

char current_marker;
char marker_p1;
char marker_p2;
string current_player;
string username1,username2,un1,un2;

//******************************************regestration************************************************************
int registe(int a){
    if(a>0&&a<3){
        for(int i=0;i<a;i++){
            string username,password,actress;
            cout<<"select a username :";
            cin>>username;
            cout<<"select a password :";
            cin>>password;
            cout<<"who's your fav actress??";
            cin>>actress;
            if(i==0) un1=username;
            else un2=username;
            ofstream file(username+".txt");
            file<<username<<endl<<password<<endl<<actress;
            file.close();
        }
    }
    else{
        cout<<"enter valid no. of players!!";
        return 0;
    }
    return 0   ;
}

int crdcheck(int a){
    int b;
    int c;
    if(a>0&&a<3){
        for(int i=0;i<a;i++){ 
            cout<<i<<endl;  
            string username,password,un,pw;
            cout<<"enter the username : "; 
            cin>>username;
            cout<<"enter password :  "; 
            cin>>password;
            if(i==0) un1=username;
            else un2=username;
            ifstream read(username+".txt");
            getline(read,un);
            getline(read,pw);
            if(un==username && pw==password){
                if(i==0)    b=1; 
                if(i==1)    c=1;
            }
            else if(un==username&&pw!=password){
                if(i==0)    b= 2;
                if(i==1)    c=2;
            }
            else{
                if(i==0)   b=3;
                if(i==1)    c=3;
            }
        }
    }
    else{
        cout<<"enter valid no. of players!!";
        return 0;
    }   
    if(b==1&&c==1){
        return 1;
    } 
    if(b==2&&c==2){
        return 2;
    }
    if(b==3&&c==3){
        return 3;
    }
    if(b==1&&c==2){
        return 4;
    }
    if(b==1&&c==3){
        return 5;
    }
    if(b==2&&c==3){
        return 6;
    }
    if(b==1){
        return 1;
    }
    if(b==2){
        return 2;
    }
    if(b==3){
        return 3;
    }
    return 0;
    
}
int pwchange(){
    string username,password,actress,un,pw,ac;
    cout<<"enter username : ";
    cin>>username;
    cout<<"who's your fav actress??";
    cin>>actress;
    ifstream read(username+".txt");
    getline(read,un);
    getline(read,pw);
    getline(read,ac);
    if(un==username && ac==actress){
        cout<<"enter new password:";
        cin>>password;
        ofstream file(username+".txt");
        file<<username<<endl<<password<<endl<<actress;
        file.close();
        cout<<"password changed sucessfully ;-)"<<endl;
        return 0;
    }
    else{
        cout<<"invalid!!!!!!";
        return 0;
    }
}
//******************************************tictactoe****************************************************************
void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "__________\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "__________\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot)
{
    int row = slot / 3;
    int col;

    if(slot % 3 == 0) {
        row = row - 1;
        col = 2;
    }
    else {
        col = slot % 3 - 1;
    }
    if(board[row][col] != marker_p1 && board[row][col] != marker_p2) {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

string winner()
{
    for(int i = 0; i < 3; i++)
    {
        //rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return current_player;
        }
        // columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_player;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return current_player;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return current_player;
    }
    string a="tie";
    return a;
}

void swap_player_and_marker()
{
    if(current_marker == marker_p1)
    {
        current_marker = marker_p2;
    }
    else {
        current_marker = marker_p1;
    }
    if(current_player == un1)
    {
        current_player = un2;
    } 
    else {
        current_player = un1;
    }
}

void game()
{
    cout << "It`s player " << current_player << "`s turn. Enter your slot: ";
    int slot;
    cin >> slot;
    srand(time(0));
    cout << un1<< ", choose your marker: ";
    cin >> marker_p1;
    cout<<un2<<", choose your marker: ";
    cin>> marker_p2;

    current_player = un1;
    current_marker = marker_p1;

    drawBoard();

    string player_won;

    for(int i = 0; i < 9; i++)
    {
        

        if(slot < 1 || slot > 9) {
            cout << "That slot is invalid! Try another slot!"; i--; continue;
        }

        if(!placeMarker(slot)) {
            cout << "That slot occupied! Try another slot!"; i--; continue;
        }
        drawBoard();

        player_won = winner();

        if(player_won == un1)
        {
            cout <<un1<< " won! Congratulations!"; break;
        }
        if(player_won == un2)
        {
            cout <<un2<< " won! Congratulations!"; break;
        }

        swap_player_and_marker();
    }
    if(player_won == "tie")
    {
        cout << "That is a Tie!";
    }
}
void comp(){
    cout<<un1<<" dont be sad i am here to play with you"<<endl;
    cout<<"I, choose marker:! "<<endl;
    marker_p2='!';
    cout << un1<< ", choose your marker: ";
    cin >> marker_p1;
    
    current_player = un1;
    current_marker = marker_p1;

    drawBoard();

    string player_won;

    for(int i = 0; i < 9; i++)
    {
        int slot;
        if(i%2!=0){
            slot=rand()%9+1;
            cout<<"I choose slot no."<<slot<<endl;
        }
        else{
            cout << "It`s player " << current_player << "`s turn. Enter your slot: ";
            cin >> slot;
            
        }
        

        if(slot < 1 || slot > 9) {
            cout << "That slot is invalid! Try another slot!"; i--; continue;
        }

        if(!placeMarker(slot)) {
            cout << "That slot occupied! Try another slot!"; i--; continue;
        }
        drawBoard();

        player_won = winner();

        if(player_won == un1)
        {
            cout <<un1<< " won! Congratulations!"; break;
        }
        if(player_won == un2)
        {
            cout <<un2<< " won! Congratulations!"; break;
        }

        swap_player_and_marker();
    }
    if(player_won == "tie")
    {
        cout << "That is a Tie!";
    }
}

int main(){
    int x;
    cout<<"1:register \n2:login \nEnter what you wanna do : ";
    cin>>x;
    cout<<"HOW MANY OF ARE YOU:\n1\n2\n";
    int k;
    cin>>k;
//registerion
    if(x==1){
        registe(k);
        main();
    }
//login    
    else if(x==2){
        int status=crdcheck(k);
        if(status==1){
            cout<<"login sucessfull"<<endl;
        }
//passwordchange    
        else if(status==2){
            cout<<"wrong password";
            cout<<"do you want to change password??\nif yes press 1 or press any other number";
            int a;
            cin>>a;
            if(a==1){
                pwchange();
            }
            else{
                main();
            }
        }
//doesnt have an account
        else if(status==3){
            cout<<"you should make an account first"<<endl;
            main();
        }
        else if(status==4){
            cout<<un1<<" your login details are correct"<<endl;
            cout<<un2<<" your password is in correct"<<endl;
            cout<<"it is advised to change the passowrd by selecting no. of players 1 and start again together"<<endl;
            main();
        }
        else if(status==5){
            cout<<un1<<" your login details are correct"<<endl;
            cout<<un2<<" your account doesnot exist"<<endl;
            cout<<"it is advised to register by selecting no. of players 1 and start again together"<<endl;
            main();
        }
        else if(status==6){
            cout<<un1<<" your password is incorrect"<<endl;
            cout<<un2<<" your account doesnot"<<endl;
            cout<<un1<<"it is advised to register by selecting no. of players 1 and "<<endl;
            cout<<un2<<" it is advised to change the passowrd by selecting no. of players 1 and start again together"<<endl;
            main();
        }
    }
    if(k==1){
        comp();
    }
    else{
    game();
    }
    
    return 0;
}