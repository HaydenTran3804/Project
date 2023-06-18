#include<bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <random>
using namespace std;
char wall_check[25][50];
map<char,pair<int,int>> len;
int speed = 1;
class pos{
    public:
	int x,y;
};
class Food : public pos{
    public:
    void pos(){
	srand(time(NULL));
	do{
		x=rand()%48+1;
		y=rand()%23+1;
	}while(wall_check[y][x]!=' ');
	wall_check[y][x]='*';
}
};
Food food;
class Snake : public pos{
    public:
    deque<pair<int,int>> body;
    void pos(){
	srand(time(NULL));
	do{
	x=rand()%48+1;
	y=rand()%23+1;
	}while(wall_check[y][x]!=' ');
	body.push_back({y,x});
	wall_check[y][x]='o';
}
  void move(char ctr){
    if(body.front().first==food.y && body.front().second==food.x){
		food.pos();
        char tmp = grow();
		body.push_back({body.back().first+len[tmp].first,body.back().second+len[tmp].second});
		wall_check[body.back().first+len[tmp].first][body.back().second+len[tmp].second]='o';
	}
    if(body.front().second <49 && body.front().second>0 && body.front().first<24 && body.front().first>0){
        body.push_front({body.front().first+len[ctr].first,body.front().second+len[ctr].second});
		wall_check[body.back().first][body.back().second]=' ';
		body.pop_back();
    } else cout << endl << system("PAUSE");
}
char grow(){
	for(auto k:len){
	if(wall_check[body.front().first+k.second.first][body.front().second+k.second.second]==' ') return k.first;
	}
	return 'N';
}
    bool check_pos(int i,int j){
    pair<int,int> tmp={i,j};
    auto it=find(body.begin(),body.end(),tmp);
	if(it != body.end()) return true;
	return false;
}
};
Snake snake;
void board(){
	for(int i=0;i<25;i++){
		cout <<setw(30);
		for(int j=0;j<50;j++){
			if(i==0 || i==24 || j==49 || j==0){
				cout << '#' ;
			} else if(snake.check_pos(i,j)){
					 cout <<"o";
					} else if(food.y==i && food.x==j){
					cout << "*";
				} else cout << " ";
		}
        cout << endl;
	}
}
void setup(){
    len['w'] = {-speed,0};
    len['s'] = {speed,0};
    len['d'] = {0,speed};
    len['a'] = {0,-speed};
    for(int i=0;i<25;i++){
		for(int j=0;j<50;j++){
			if(i==0 || i==24 || j==0 || j==49){
				wall_check[i][j]='#';
			}
		else	wall_check[i][j]=' ';
		}
	}
    food.pos();
    snake.pos();
    board;
}
int main()
{
    setup();
char dir;
	while(true){
		board();
	if(kbhit()){
		switch(getch()){
			case 'w': dir='w';break;
			case 's': dir='s';break;
			case 'd': dir='d';break;
			case 'a': dir='a';break;
		
		}	
		snake.move(dir);
	
	} else {
		snake.move(dir);
	}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
}
    return 0;
}