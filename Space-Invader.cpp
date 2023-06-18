#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
char enermies[25][50];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int score = 5;
class Enemies{
public:
char enermies[25][50];
vector<pair<int,int>> pos_ene;
vector<pair<int,int>> ene_bullet;
bool appearene(int n,int m){
	for(int i=0;i<pos_ene.size();i++){
		if(pos_ene[i].first==n && pos_ene[i].second==m){
		return true;
		}
	}
	return false;
}
void checkene(){
	for(int i=0;i<25;i++){
		for(int j=0;j<50;j++){
			if(enermies[i][j]=='*'){
				if(!appearene(i,j)) enermies[i][j]=' ';
			}
		}
	}
	}
void delenepos(int n,int m){
	for(int i=0;i<pos_ene.size();i++){
		if(pos_ene[i].first==n && pos_ene[i].second==m){
			pos_ene.erase(pos_ene.begin()+i,pos_ene.begin()+i+1);
		}
	}
}
bool check_ene_bullet(int n,int m){
	for(int i=0;i<ene_bullet.size();i++){
		if(ene_bullet[i].first==n && ene_bullet[i].second==m){
			return true;
		} if(ene_bullet[i].first>=24) 	ene_bullet.erase(ene_bullet.begin()+i,ene_bullet.begin()+i+1);
	}
	return false;
}
void set_ene_bullet(){
int i=rand()%pos_ene.size() + 0;
if(enermies[pos_ene[i].first+1][pos_ene[i].second]!='*' && enermies[pos_ene[i].first][pos_ene[i].second]=='*'){
			ene_bullet.push_back({pos_ene[i].first+1,pos_ene[i].second});
		}
}
void ene_bullet_fly(){
	for(int i=0;i<ene_bullet.size();i++){
		ene_bullet[i].first+=1;
	}
}
bool check_ene_move(int i){
	for(int k=0;k<pos_ene.size();k++){
 if(enermies[pos_ene[k].first+dx[i]][pos_ene[k].second+dy[i]]=='#' || pos_ene[k].first + dx[i]>=8 ) return true;
	}
	return false;
}
};
Enemies enemies;
class Craft{
public:
map<int,vector<int>> spacecraft;
vector<pair<int,int>> bullet;
void create(){
	for(int i=22;i<24;i++){
		 if(i==22){
		spacecraft[i].push_back(25);
		} else{
			for(int j=24;j<27;j++){
				spacecraft[i].push_back(j);
			}
		}
	}
}
bool checkbullet(int n,int m){
	for(int i=0;i<bullet.size();i++){
		if(bullet[i].first==n && bullet[i].second==m){
			if(enermies[n][m]=='*'){
				enemies.enermies[n][m]=' ';
				score++;
			    enemies.delenepos(n,m);
				bullet.erase(bullet.begin()+i,bullet.begin()+i+1);
				return false;
			}
			return true;
		}
		if(bullet[i].first<=0){
				bullet.erase(bullet.begin()+i,bullet.begin()+i+1);
		}
	}
	return false;
}
bool checkcraft(int n,int m){
	for(auto x:spacecraft){
		if(x.first==n){
		for(int j=0;j<x.second.size();j++){
			if(x.second[j]==m){
				for(int k=0;k<enemies.ene_bullet.size();k++){
					if(enemies.ene_bullet[k].first==n && enemies.ene_bullet[k].second==m){
					score-=1;
					enemies.ene_bullet.erase(enemies.ene_bullet.begin()+k,enemies.ene_bullet.begin()+k+1);
					break;
				}
				}
				return true;
			}
		}
	}
}
	return false;
}
void bulletfly(){
	for(int i=0;i<bullet.size();i++){
		bullet[i].first-=1;
	}
}
void move(int dir){
	for(int i=22;i<24;i++){
		for(int j=0;j<spacecraft[i].size();j++){
			spacecraft[i][j]=spacecraft[i][j]+dir;
		}
	}
}
};
Craft craft;
void board(){
	for(int i=0;i<25;i++){
		cout << setw(40);
		for(int j=0;j<50;j++){
			if(i==0 || i==24 || j==0 || j==49){
			 cout <<"#";
		} else if(craft.checkcraft(i,j)) {
		cout <<'o';
		} else if(craft.checkbullet(i,j)){
		cout <<'^';
		} else if(enemies.check_ene_bullet(i,j)){
			cout <<"v";
		}
		  else{
   cout << enemies.enermies[i][j];
}
		
	} 
	cout << endl;
	}
	cout << "Score: " <<score << endl;
	if(score>=10) cout <<setw(50) << "You Win";
else cout <<setw(50) <<"You Lose";
}
void ene_move(){
	int i;
	do{
 i=rand()%4+0;
} while(enemies.check_ene_move(i));
	int n=enemies.pos_ene.size();
	vector<pair<int,int>> tmp;
	for(int h=0;h<n;h++){
		enemies.enermies[enemies.pos_ene[h].first][enemies.pos_ene[h].second]=' ';
		tmp.push_back({enemies.pos_ene[h].first+dx[i],enemies.pos_ene[h].second+dy[i]});
	}
	enemies.pos_ene.clear();
	enemies.pos_ene=tmp;
		for(int h=0;h<n;h++){
			craft.checkbullet(enemies.pos_ene[h].first,enemies.pos_ene[h].second);
			enemies.enermies[enemies.pos_ene[h].first][enemies.pos_ene[h].second]='*';
	}
	
}


int main(){
craft.create();
for(int i=0;i<25;i++){
	for(int j=0;j<50;j+=1){
		if(i==0 || i==24 || j==0 || j==49){
			enemies.enermies[i][j]='#';
		} else if(i>3 && i<8 && j%12==0 && j!= 48){
		enemies.pos_ene.push_back({i,j});
		enemies.enermies[i][j]='*';
	} else enemies.enermies[i][j]=' ';
}
}
int dir;
int time=0;
while(score<12 && score>0){
		board();
	if(kbhit()){
		switch(getch()){
            case 'd': dir=1;break;
			case 'a': dir=-1;break;
		}

		craft.move(dir);
} else {
	craft.move(dir);
}
  if(time==4){
craft.bullet.push_back({21,craft.spacecraft[22][0]+dir});
enemies.set_ene_bullet();
}
ene_move();
	if(time==4) time=0;
	time++;
	craft.bulletfly(); 
    enemies.ene_bullet_fly();

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
}

}

