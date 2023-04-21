#include <bits/stdc++.h>
#include "Graphic.h"
char ground[3][75];
int sig_dino = 0;
int sig_ground;
int up = 50;
string space_dino ="                 ";
char space_cactus[2]={' ',' '};
int check = 25;
int obs = 1;
string bird_ = "_/__";
string del_down = "        ";
string dino[9]={
	"         oooooooo",
	"         oooooooo",
	"         oooooooo",
	"o      ooooooooo ",
	"ooo  oooooooooo  ",
	"oooooooooooo  o  ",
	"   ooooooooo     ",
	"   ooo oo        ",
    "   oo  oo        ",
};
string dino_down[6]={
	"o      ooooooooo oooooooo",
	"ooo  oooooooooo  oooooooo",
	"oooooooooooo  o  oooooooo",
	"   ooooooooo     ",
	"   ooo oo        ",
    "   oo  oo        ",
};
string ct[9]={
"  |  ",
"| |  ",
"| | |",
"| |_|",
"|_|  ",
"  |  ",
"  |  ",
"  |  ",
"__|  ",
};
class pos{
    public:
       int x,y;
};
class grd : public pos{
 public:
 grd(){
    x = 15;
    y = 25+9;
    for(int i=0;i<75;i++){
        ground[0][i]='_';
        set_ground(i);
    }
    ground[0][16] = 'o';
    ground[0][17] = 'o';
    ground[0][20] = 'o';
    ground[0][21] = 'o';
 }
 void set_ground(int i);
 void draw_ground(){
    int h = y;
    if(sig_ground){
    ground[0][16] = 'o';
    ground[0][17] = 'o';
    ground[0][20] = 'o';
    ground[0][21] = 'o';
    } else {
    ground[0][16] = '_';
    ground[0][17] = '_';
    ground[0][20] = '_';
    ground[0][21] = '_';
    }
    for(int j = 0;j<3;j++){
        gotoxy(x,h++);
    for(int i=0;i<75;i++){
             cout<<ground[j][i];
    }
    }
}
void move(){
gotoxy(x,y);
   for(int i=1;i<3;i++){
    for(int j=0;j<74;j++){
           ground[i][j] = ground[i][j+1];
    }
   }
    set_ground(74);
    draw_ground();
}
};
void grd :: set_ground(int i){
        int v = rand() % 15 + 1;
 switch(v){
            case 1: {
                ground[1][i] = '.';ground[2][i] = ' ';break;
            }
            case 2:{
                ground[1][i] = '-';ground[2][i] = ' ';break; 
            }
            case 3:{
                ground[1][i] = '.';ground[2][i] = ' ';break;
            }
             case 4:{
                ground[1][i] = 248;ground[2][i] = ' ';break;
            }
            case 5:{
                ground[1][i] = ' ';ground[2][i] = '.';break;
            }
            case 6:{
                ground[1][i] = ' ';ground[2][i] = '-';break;
            }
            case 7:{
                ground[1][i] = ' ';ground[2][i] = '*';break;
            }
            default:{
                ground[1][i] = ' ';ground[2][i] = ' ';break;
            }
        }
    
}
class cactus : public pos{
public:
cactus(){
    x = 85;
    y = 26;
}
void draw_cactus(int j){
    int h = y;
    for(int i=0;i<9;i++){
        int tmp = h++;
        gotoxy(j, tmp);
        cout << ct[i];
        }
        h = y+2;
        for(int i=0;i<2;i++){
            gotoxy(j+5,h++);
            cout << space_cactus[i];
        }
}
void move_cactus(){
        int l = y;
        if(x>16){
        draw_cactus(--x);
        } else{
            for(int i=0;i<9;i++){
                gotoxy(x,l++);
                for(int j=0;j<ct[i].size();j++){
                    cout<<" ";
                }
            }
            obs = rand()%2 + 1;
            x=84;
        }
}
};
class dinosaur : public pos{
    public:
    dinosaur(){
        x = 28;
        y = 25;
    }
    void draw_dino(int h){
        for(int i=0;i<9;i++){
        gotoxy(x,h++);
         cout << dino[i];
        }
    }
    void jump(){
    if(sig_dino == 2 && check >= 10){
        gotoxy(x,check+9);
        cout << space_dino;
        draw_dino(check--);
    }  
    if( check == 9){
        sig_dino = 1;
        check = 11;
    }
    if(sig_dino == 1 && check < 25){
            gotoxy(x,check-1);
        cout << space_dino;
           draw_dino(check++);
    }
    if(check == 25) 
    { 
        gotoxy(x,check-1);
        cout << space_dino;
        draw_dino(check);
        sig_dino = 0;
        check = 25;
        sig_ground = 1;
    }

    }
};
class bird : public pos{
public:
bird(){
    x = 84 ;
    y = 26;
}
void draw_bird(int j){
     gotoxy(j,y);
     cout << bird_;
}
void move(){
    gotoxy(x+4,y);
    cout << " ";
    if(x > 16){
        draw_bird(--x);
    } else {
        gotoxy(x,y);
        cout <<"    ";
        x = 84;
        y = rand() % 5 + 23;
         obs = rand()%2 + 1;
    }
}
};