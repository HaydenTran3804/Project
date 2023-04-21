#include "Dino_General.h"
int main(){
 dinosaur a;
    grd b;
    cactus c;
    bird d;
      b.draw_ground();
       a.draw_dino(a.y);
     //  c.draw_cactus(c.x);
    d.draw_bird(d.x);
       	while(true){
            Sleep(10);
            b.move();
	if(kbhit()){
	    switch(getch()){
			case 'w' : {
                up = 25;
                sig_dino = 2;
            sig_ground = 0;
            break;
            }
            case 's':{ 
                up = 0;
                break; 
            }
		}	
	} else {
        up++;
	}
    if(up >= 25){
        int h = a.y+3;
        for(int i=0;i<3;i++){
            gotoxy(a.x+17,h++);
            cout << del_down;
        } 
        a.jump();
    } else {
        int h = a.y;
            for(int i=0;i<3;i++){
                gotoxy(a.x,h++);
                cout << space_dino;
            }
                for(int i = 0;i<6;i++){
                    gotoxy(a.x,h++);
                    cout << dino_down[i];
                }
                  sig_ground = 1;
    }   
    if(obs == 1){
      c.move_cactus();
    } else{
      d.move();
    }
        if((sig_dino==0) && c.x >= a.x && c.x < a.x + 17 ){
          cout << endl << endl << system("PAUSE");
            cout << endl << endl << setw(45) << "YOU LOSE";
        }
        if(up >= 25 && d.x < a.x + 17 && d.x >= a.x && d.y <= a.y ){
             cout << endl << endl << system("PAUSE");
            cout << endl << endl << setw(45) << "YOU LOSE";
        }
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,15});
}
    cout << endl << endl << system("PAUSE");
}

