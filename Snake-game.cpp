#include<bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <random>
using namespace std;
char a[25][50];
int n=0;
int score=0;
deque<pair<int,int>> pixel;
map<char,pair<int,int>> len;
struct pos{
	int x,y;
};
pos food;
pos snake;
//Check if the place of the snake
bool check(int i,int j){
pair<int,int> tmp={i,j};
auto it=find(pixel.begin(),pixel.end(),tmp);
	if(it != pixel.end()) return true;
	return false;
}
//Creating the board
void board(pos snake,pos food){
score=pixel.size();
	for(int i=0;i<25;i++){
		cout <<setw(30);
		for(int j=0;j<50;j++){
			if(i==0 || i==24 || j==49 || j==0){
				cout << '#' ;
			} else if(check(i,j)){
					 cout <<"o";
					} else if(food.y==i && food.x==j){
					cout << "*";
				} else cout << " ";
			  
			
		}

		cout << endl;
	}
	cout << "SCORE: "<<score;
}
//the firstpos of food
void foodpos(){
	srand(time(NULL));
	do{
		food.x=rand()%48+1;
		food.y=rand()%23+1;
	}while(a[food.y][food.x]!=' ');
	a[food.y][food.x]='*';
}
// the fistpos of snake
void snakepos(){
	srand(time(NULL));
	do{
	snake.x=rand()%48+1;
	snake.y=rand()%23+1;
	}while(a[snake.y][snake.x]!=' ');
	pixel.push_back({snake.y,snake.x});
	a[snake.y][snake.x]='o';
}
//the place to add the new dot to the snake when it eats the food
char put(char a[][50]){
	for(auto k:len){
		if(a[pixel.front().first+k.second.first][pixel.front().second+k.second.second]==' ') return k.first;
	}
	return 'N';
}
void process(char a[][50]){
	//Checking for going through the up and down wall
	if(pixel.front().first==24 || pixel.front().first==0){
		int tmp=pixel.front().second;
		pixel.push_front({abs(pixel.front().first-23),tmp});
		a[abs(pixel.front().first-23)][tmp]='o';
		a[pixel.back().first][pixel.back().second]=' ';
		pixel.pop_back();
	}
	//Checking for going through the left and right wall
	if(pixel.front().second==49 || pixel.front().second==0){
		int tmp=pixel.front().first;
		pixel.push_front({tmp,abs(pixel.front().second-48)});
		a[tmp][abs(pixel.front().second-48)]='o';
		a[pixel.back().first][pixel.back().second]=' ';
		pixel.pop_back();
	}
}
void move(char a[][50],char ctr){
      //Snake eat the food and its size changes
	if(pixel.front().first==food.y && pixel.front().second==food.x){
		foodpos();
		char tmp=put(a);
		if(tmp=='N'){
			cout << setw(55) << "LOSE";
			system("PAUSE");
		}
		pixel.push_back({pixel.back().first+len[tmp].first,pixel.back().second+len[tmp].second});
		a[pixel.back().first+len[tmp].first][pixel.back().second+len[tmp].second]='o';
	}
	//Snake go through the wall 
	if(pixel.front().first==24 || pixel.front().first==0 || pixel.front().second==49 || pixel.front().second==0){
		process(a);
	}
	//Snake moves and not eat food as well as meet the wall
	if(pixel.front().second <49 && pixel.front().second>0 && pixel.front().first<24 && pixel.front().first>0){
       pixel.push_front({pixel.front().first+len[ctr].first,pixel.front().second+len[ctr].second});
		a[pixel.back().first][pixel.back().second]=' ';
		pixel.pop_back();
	}
}


int main()
{
	for(int i=0;i<25;i++){
		for(int j=0;j<50;j++){
			if(i==0 || i==24 || j==0 || j==49){
				a[i][j]='#';
			}
		else	a[i][j]=' ';
		}
	}
	len['w']={-1,0};
	len['s']={1,0};
	len['a']={0,-1};
	len['d']={0,1};
	foodpos();
	snakepos();
	char dir;
	while(true){
		board(snake,food);
	if(kbhit()){
		switch(getch()){
			case 'w': dir='w';break;
			case 's': dir='s';break;
			case 'd': dir='d';break;
			case 'a': dir='a';break;
		
		}	
		move(a,dir);
	
	} else {
		move(a,dir);
	}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
}
    return 0;
}