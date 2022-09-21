#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>
#include <graphics.h>
#define KEY_LEFT       75
#define KEY_RIGHT      77
#define KEY_UP         72
#define KEY_DOWN       80
#define KEY_SPACE      32

using namespace std; 

class Spaceship{
  protected:
  int rx1,rx2,ry1,ry2,lx1,lx2,ly1,ly2,ly3,ly4;

  public:
  Spaceship(int rex1=0,int rex2=0,int rey1=0,int rey2=0,int lix1=0,
  int lix2=0,int liy1=0,int liy2=0,int liy3=0,int liy4=0){
    rx1=rex1;
    rx2=rex2;
    ry1=rey1;
    ry2=rey2;
    lx1=lix1;
    lx2=lix2;
    ly1=liy1;
    ly2=liy2;
    ly3=liy3;
    ly4=liy4;
  }

  virtual void destroyspaceship(){
  setcolor(BLACK);
  rectangle(rx1,ry1,rx2,ry2);
  circle((rx1+rx2)/2,(ry1+ry2)/2,10);
  line(rx1,(ry1+ry2)/2,(rx1+rx2)/2-10,(ry1+ry2)/2);
  line((rx1+rx2)/2+10,(ry1+ry2)/2,rx2,(ry1+ry2)/2);
  line(lx1,ly1,lx1,ly2);
  line(lx1,ly1,lx2,ly3);
  line(lx1,ly2,lx2,ly4);
  }

  virtual void createspaceship(){
  setcolor(WHITE);
  rectangle(rx1,ry1,rx2,ry2);
  line(lx1,ly1,lx1,ly2);
  line(lx1,ly1,lx2,ly3);
  line(lx1,ly2,lx2,ly4);
  setcolor(COLOR(252,252,197));
  circle((rx1+rx2)/2,(ry1+ry2)/2,10);
  line(rx1,(ry1+ry2)/2,(rx1+rx2)/2-10,(ry1+ry2)/2);
  line((rx1+rx2)/2+10,(ry1+ry2)/2,rx2,(ry1+ry2)/2);
  }

  virtual void resetSpaceship(){}
  virtual void movement(){}
  virtual void reSpaceship(){}
  virtual int hy(){return 0;}
  virtual int hx(){return 0;}
  virtual int ly(){return 0;}

};

class EnemySpaceShip:public Spaceship{
  public:
  EnemySpaceShip(int rex1=0,int rex2=0,int rey1=0,int rey2=0,int lix1=0,
  int lix2=0,int liy1=0,int liy2=0,int liy3=0,int liy4=0):
  Spaceship(rex1,rex2,rey1,rey2,lix1,lix2,liy1,liy2,liy3,liy4){}

  void movement(){
    rx1-=1;rx2-=1;lx1-=1;lx2-=1;
  }

  void createspaceship(){
  setcolor(WHITE);
  rectangle(rx1,ry1,rx2,ry2);
  line(lx1,ly1,lx1,ly2);
  line(lx1,ly1,lx2,ly3);
  line(lx1,ly2,lx2,ly4);
  setcolor(COLOR(199,220,255));
  line(rx1+5,ry1,rx1+5,ry2);
  line(rx2-10,ry1,rx2-10,ry2);
  line(rx1+5,ry1+15,rx2-10,ry1+15);
  }
  
  void destroyspaceship(){
  setcolor(BLACK);
  rectangle(rx1,ry1,rx2,ry2);
  line(lx1,ly1,lx1,ly2);
  line(lx1,ly1,lx2,ly3);
  line(lx1,ly2,lx2,ly4);
  line(rx1+5,ry1,rx1+5,ry2);
  line(rx1+5,ry1+15,rx2-10,ry1+15);
  line(rx2-10,ry1,rx2-10,ry2);
  }

  void resetSpaceship(){
    if(rx2<=0){
    int h = 30+rand()%299;
    rx1=550;rx2=600;ry1=h;ry2=h+30;lx1=600;lx2=590;ly1=h-10;ly2=h+40;ly3=h;ly4=h+30;
    }
  }

  void reSpaceship(){
    int h = 30+rand()%299;
    rx1=550;rx2=600;ry1=h;ry2=h+30;lx1=600;lx2=590;ly1=h-10;ly2=h+40;ly3=h;ly4=h+30;
  }

  int hx(){return rx1;}
  int hy(){return ly2;}
  int ly(){return ly1;}

};


class Score{
  int scores;
  public:
  Score(int s=0){scores=s;}

  void inc(){
    scores++;
  }

  void show(int life){
    system("cls");
    cout<< "Spaceshooter" << endl << endl;
    cout<< "Your lives: " << life << endl;
    cout<< "Your Score: " << scores << endl;
  }

  void backmenu(){
        cout << endl << "Type a number to back to menu: ";
        char a;
        cin >> a;
  }

  void resco(){
    scores=0;
  }
};

class Myspaceship:public Spaceship
{ private:
  int bullets[20];
  int bullety[20];
  int count,lifespans;
  Score* score;

  public:
  Myspaceship(int rex1=0,int rex2=0,int rey1=0,int rey2=0,int lix1=0,
  int lix2=0,int liy1=0,int liy2=0,int liy3=0,int liy4=0,int z=0):
  Spaceship(rex1,rex2,rey1,rey2,lix1,lix2,liy1,liy2,liy3,liy4)
  { count=0;lifespans=3;}

  void control(char c){
  if(c==KEY_DOWN){
    if(ly2<=400){
    destroyspaceship();ry1+=10;ry2+=10;ly1+=10;ly2+=10;ly3+=10;ly4+=10;createspaceship();}}
  else if(c==KEY_UP){
    if(ly1>=20){
    destroyspaceship();ry1-=10;ry2-=10;ly1-=10;ly2-=10;ly3-=10;ly4-=10;createspaceship();}}
  else if(c==KEY_LEFT){
    if(lx1>=10){
    destroyspaceship();rx1-=10;rx2-=10;lx1-=10;lx2-=10;createspaceship();}}
  else if(c==KEY_RIGHT){
    if(rx2<=598){
    destroyspaceship();rx1+=10;rx2+=10;lx1+=10;lx2+=10;createspaceship();}}
  else if(c==32){
    setbullet();
    bullet();}    
  }

  void setbullet(){
    bullets[count] = rx2;
    bullety[count]=(ry1+ry2)/2;
  }
  
  void bullet(){
    setcolor(COLOR(252,201,197));
    rectangle(bullets[count]+1,bullety[count]-1,bullets[count]+1,bullety[count]+1);
    count++;
    if(count>=20){count=0;}
  }

  void destroybullet(){
    for (int s=0;s<20;s++){
    if(bullets[s]<=600){
    setcolor(BLACK);
    rectangle(bullets[s]+1,bullety[s]-1,bullets[s]+2,bullety[s]+1);}}
  }

  void redrawbullet(){
    for (int z=0;z<20;z++){
      if(bullets[z]!=0&&bullety[z]!=0){
    if(bullets[z]<=600){
    setcolor(COLOR(252,201,197));
    rectangle(bullets[z]+1,bullety[z]-1,bullets[z]+2,bullety[z]+1);}}}
  }

  void movebullet(){
    for (int k=0;k<20;k++){
      if (bullets[k]!=0&&bullety[k]!=0){
    if(bullets[k]<=600){
    bullets[k]+=1;}}
  }}

  int bulletposition(int hx,int hy,int ly,int life){
    for(int o=0;o<20;o++){
      if(bullets[o]!=0&&bullety[o]!=0){
        if(bullets[o]>=hx&&bullets[o]<=(hx+235)){
          if(((bullety[o]-2)<=hy)&&((bullety[o]-2)>=ly)){
            bullets[o]=0;
            bullety[o]=0;
            score->inc();
            score->show(life);
            return 1;
          }
          if(((bullety[o]+2)<=hy)&&((bullety[o]+2)>=ly)){
            bullets[o]=0;
            bullety[o]=0;
            score->inc();
            score->show(life);
            return 1;
          }
        }
      }
    } 
  return 0;}

  int lifespaneneres(int hx,int hy,int ly,int life){
    if(rx2>=hx && rx2<=hx+50){
      if(ly2<=hy&&ly2>=ly){
        lifespans--;
        score->show(life);
        return 1;}
      if(ly1<=hy&&ly1>=ly){
        lifespans--;
        score->show(life);
        return 1;}
    }
    return 0;}

  int lifespanbreak(){
      return lifespans;
    }

  void relife(){
    lifespans=3;
  }

  void scoreback(int s){
    score->show(s);
    score->backmenu();
  }
  
  void scoreshows(int s){
    score->show(s);
  }

  void rescore(){
    score->resco();
  }

  void setscore(Score* s){
    score=s;
  }
};

class Game{
  private:
  Spaceship* s2[2];

  public:
  Myspaceship s1;
  Game(int rex1=0,int rex2=0,int rey1=0,int rey2=0,int lix1=0,
  int lix2=0,int liy1=0,int liy2=0,int liy3=0,int liy4=0,int s=0):s1(rex1,rex2,rey1,rey2,lix1,lix2,liy1,liy2,liy3,liy4)
  {}

  void sets1(Myspaceship z){
    s1 = z;
  }

  void sete(EnemySpaceShip* z1,EnemySpaceShip* z2){
    s2[0]=z1;
    s2[1]=z2;
  }

  void instru(){
    rectangle(660,25,710,75);
    line(685,35,685,65);
    line(670,50,685,35);
    line(685,35,700,50);
    
    rectangle(660,125,710,175);
    line(685,135,685,165);
    line(670,150,685,165);
    line(685,165,700,150);

    rectangle(660,225,710,275);
    line(670,250,700,250);
    line(685,235,700,250);
    line(700,250,685,265);

    rectangle(660,325,710,375);
    line(670,350,700,350);
    line(685,335,670,350);
    line(670,350,685,365);    

    bgiout<<"Up";
    outstreamxy(730,40);
    bgiout<<"Down";
    outstreamxy(730,140);
    bgiout<<"Right";
    outstreamxy(730,240);
    bgiout<<"Left";
    outstreamxy(730,340);
    system("cls");
    cout<<"Press any key to start the game";
  }
  
  void resetlife(){
    s1.relife();
  }

  void play(){
    instru();
    char z = getch();
    s1.rescore();
    s1.scoreshows(s1.lifespanbreak());
    while(1)
    {
      if(kbhit()){
        char c = getch();
        if(c==27) {
        s1.scoreback(s1.lifespanbreak());
        break;}
        s1.control(c);
      }
      s1.createspaceship();
      s2[0]->createspaceship();
      s2[1]->createspaceship();
      s1.redrawbullet();
      Sleep(1);
      s1.destroyspaceship();
      s2[0]->destroyspaceship();
      s2[1]->destroyspaceship();
      s1.createspaceship();
      s1.destroybullet();
      if(s1.bulletposition(s2[0]->hx(),s2[0]->hy(),s2[0]->ly(),s1.lifespanbreak())==1){
        s2[0]->reSpaceship();}
      if(s1.bulletposition(s2[1]->hx(),s2[1]->hy(),s2[1]->ly(),s1.lifespanbreak())==1){
        s2[1]->reSpaceship();}
      s1.movebullet();
      s2[0]->movement();
      s2[1]->movement();
      s2[0]->resetSpaceship();
      s2[1]->resetSpaceship();
      if(s1.lifespaneneres(s2[0]->hx(),s2[0]->hy(),s2[0]->ly(),s1.lifespanbreak())==1){
        s1.scoreshows(s1.lifespanbreak());
        s2[0]->reSpaceship();
      if(s1.lifespanbreak()==0){
        s1.scoreback(s1.lifespanbreak());
        break;}}
      if(s1.lifespaneneres(s2[1]->hx(),s2[1]->hy(),s2[1]->ly(),s1.lifespanbreak())==1){
        s1.scoreshows(s1.lifespanbreak());
        s2[1]->reSpaceship();
      if(s1.lifespanbreak()==0){
        s1.scoreback(s1.lifespanbreak());
        break;}}
  }
  }
};

void menu()
{ 
  system("cls");
  cout << "Welcome to space shooter" << endl << endl;
  cout << "1. Play" << endl;
  cout << "2. Instruction" << endl;
  cout << "3. Exit" << endl << endl;
  cout << "Type a number to proceed: ";
}

void instruction()
{
  system("cls");
  cout << "Instructions:\n\nHow to play" << endl;
  cout << "Try your best to survive by destroying your enermy (spaceships) and avoid clashing with them." << endl;
  cout << "You only have 3 lives and each lives will be reduced once your spaceship clashing with the enemy " << endl;
  cout << "\n\nMovement" << endl;
  cout << "Use your keyboard (left right up down) to control the movement of spaceship" << endl;
  cout << "Use the space key to shoot the enemy" << endl << endl;
  cout << "Type a word to back to the menu: ";
  char z;
  cin >> z;
}

int main()
{ 
  //window
	srand( (unsigned)time(NULL)); 
  int h = 30+rand()%134;
  int k = 204+rand()%125;
  Score s(0);
  Myspaceship r(50,100,285,315,50,60,275,325,285,315);
  r.setscore(&s);
  EnemySpaceShip e1(550,600,h,h+30,600,590,h-10,h+40,h,h+30);
  EnemySpaceShip e2(550,600,k,k+30,600,590,k-10,k+40,k,k+30);
  Game game(50,100,285,315,50,60,275,325,285,315);
  int graphic_window_width = 850;
  int graphic_window_height = 550;
  int c,z=0;
  game.sets1(r);
  game.sete(&e1,&e2);
  do{
    menu();
    cin >> c;
    switch(c){
      case 1:
      initwindow(graphic_window_width,graphic_window_height,"Space Shooter");
      for (int y=1;y<=404;y++){
      if(y==1||y==403){
      for (int x=1;x<=600;x++){
      bgiout << "-";
      outstreamxy(x,y);
      }}}
      line(603,10,603,410);
      bgiout << "Press the key (left,right,up,down) to control the spaceship and SPACE to shoot a bullet\nScore will be display in the command prompt";
      outstreamxy(0,470);
      game.play();
      game.resetlife();
      break;

    case 2:
    instruction();
    break;

    case 3:
    z=1;
    break;
    }
  }while(z==0);
  
  //update

  //render

  //draw your game
  system("pause");
}

