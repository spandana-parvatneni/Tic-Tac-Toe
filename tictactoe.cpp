#include<iostream>
#include<array>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;


bool player; string player_name;
string p1, p2; char p1char, p2char;
char entry[3][3]; 
int p1score=0, p2score=0;
unordered_map <int, pair<int,int>> record;


void details(string &p1, string &p2, char &p1char, char &p2char);
void scoreboard(int rounds);
bool check(int &x, int &y);
void grid(pair<int ,int> coord,bool &player);
bool game_condition(char entry[3][3],int x, int y);
void game();
bool rematch(int round);


int main(){
    details(p1,p2,p1char,p2char);
    int round=1;
    while(round<=5){
        memset(entry,'\0',sizeof(entry));
        game();
        record[round]=make_pair(p1score,p2score);
        if(rematch(round)) round++;
        else break;
    }
    scoreboard(round);
    record.clear();
    return 0;
}


// takes names and feeds into scoreboard as the game restarts, assigns x's and o's to players and also give brief intro
void details(string &p1, string &p2, char &p1char, char &p2char){ 
    cout<<"Welcome to TIC-TAC-TOE: Cooler but Not Really\n\nThe stakes are HIGH!! Choose wisely! or else...\nnothing, you'll just embarrass yourself.LESSGOOOO\n\nEnter Player 1 name: ";cin>> p1; 
    cout<<"Enter Player 2 name: "; cin>>p2;
    if(rand()%2==0){p1char='O';p2char='X';}
    else{p1char='X';p2char='O';}
    cout<<"\n\n"<<p1<<" shall weild "<<p1char<<"\n"<<p2<<" shall weild "<<p2char<<"\nfor their battle of territory!!!\n\nHow to play(for dummies only):\nEach player must enter the coordinates of the block they want to occupy like a lil bitch. \n\nLET THE MADNESS BEGIN! \n\n";
}
   
//takes player names and arguments and maintains scoreboard(map) and displays it
void scoreboard(int rounds){ 
    int final1=0, final2=0;
    
    cout<<p1<<"|| ";
    for(auto& p: record){
        final1+=p.second.first;
        cout<<p.second.first<<"|  ";} 
    cout<<"FINAL SCORE: "<<final1<<"\n"<<endl;
    cout<<p2<<"|| ";
    for(auto& p: record){
        final2+=p.second.second;
        cout<<p.second.second<<"|  ";}
    cout<<"FINAL SCORE: "<<final2<<endl;
    
    string winner, loser;
    if(final1==final2) cout<<"\nY'all are useless.It's a tie."<<endl;

    else{ if (final1>final2){winner=p1; loser=p2;} else{winner=p2; loser=p1;}
    cout<<"\nThe Mighty "<<winner<<" has won the Battle of Tic-Tac-Toe."<<endl;
    cout<<loser<<" Has lost the Empire. you stupid bitch\n"<<endl;
    cout<<"GOODBYE WARRIORS\n"<<endl;}

}

//takes input of coordinate and player as arguments, updates the grid(array) and displays it.
void grid(pair<int ,int> coord,bool &player){
char sym;
if(player){sym=p2char; player=false;}
else {sym=p1char; player=true;}
entry[coord.first][coord.second]=sym;    //char array 'entry' updated

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        
        if(entry[i][j]!='\0'){
            if(i<2) {cout<<"_"<<entry[i][j]<<"_";}
            else {cout<<" "<<entry[i][j]<<" ";}}
        else{if(i<2)cout<<"___"; 
             else cout<<"   ";}
        if(j<2) cout<<"|";
    } cout<<endl;
} cout<<endl;
}

//checks input validity
bool check(int &x, int &y){
    while(true){
    if (x<0 || x>2 || y<0 || y>2) {
        cout << "Woah! Invalid coordinates. You trynna flee?.\n";
        return false;}
    else if (entry[x][y]!='\0') {
        return false;}
    else{ 
        return true;}
    cout<<"Careful now. You dont wanna step into there territory!"; 
    cout<<player_name<<": "; cin>>x>>y; x--;y--;
    }
}

//returns boolean value if winning condition is satisfied or not.(to continue the game or to ask for a rematch)
bool game_condition(char entry[3][3],int x, int y){
    if((entry[x][0]==entry[x][1] && entry[x][1]==entry[x][2] )|| entry[0][y]==entry[1][y] && entry[1][y]==entry[2][y]) {
        if(player) player=false; else player=true;
        return true;}
    else if((entry[0][0]==entry[1][1] && entry[1][1]==entry[2][2])||(entry[0][2]==entry[1][1] && entry[1][1]==entry[2][0]) ){
        if(player) player=false; else player=true;
        return true;}
    return false;
}

//Game: contains the loop for one complete round of tic-tac-toe game.
void game(){

    int played=1,x,y;
    cout<<"___|___|___\n___|___|___\n   |   |   \n";

    while(played<=9){
        if(played%2==0) player=true; else player=false;
        if(player) player_name=p2; else player_name=p1;  //player 1: false(0), player 2: true(1)

        cout<<player_name<<": "; cin>>x>>y; x--;y--;
        check(x,y);
        
        grid(make_pair(x,y),player);
        if(played>=5){
            if(game_condition(entry,x,y)){
                if(player) player_name=p2; else player_name=p1;
                cout<<"GAME OVER!!!\n"<<endl; 
                if(player) p2score++; else p1score++;
                break;}
        }
        played++; }
    if(!game_condition(entry, x,y)){
        cout<<"IT'S A TIE!"; 
        p1score++; p2score++;}
}

//question for rematch 
bool rematch(int round){
    if(round<5){
        char ans;
        cout<<"Do you wish to continue? (Y/N) "<<endl; cin>>ans;
        if(toupper(ans)=='Y') {
            return true;}
        else {cout<<"WUSS\n"<<endl;}
    }
    return false;
}

