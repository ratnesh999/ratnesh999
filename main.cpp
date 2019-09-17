/*  c++ program. when your run this program and take appropriate action in command prompt  it will show you a preliminary clock and in command prompt
it will show angle between clock needle. Please put command prompt and window side by side*/



#include <iostream>
#include <graphics.h>
#include<math.h>
#include<ctime>
#include<string.h>
//#include <cstdlib>

using namespace std;
int i=0;
string status;
int hour1, minute1, second1;
int hour2, minute2, second2;
char close;
int sec_min_angle, sec_hour_angle, min_hour_angle;

void secondneedle(int sec);
void minuteneedle(int minute, int sec);
void hourneedle(int hour, int minute, int sec);
void get_time(int& h, int& m, int& s);

class myclock{
public:
    myclock(int hour, int minute, int second){
        circle(250,250,220);
        secondneedle(second);
        minuteneedle(minute, second);
        hourneedle(hour,minute,second);

    }

};

void anglecalculator(int hour, int minute, int second){
    int secangle,minangle, hourangle;
    secangle=second*6;
    minangle=minute*6+secangle/60;
    if(hour==12){
        hourangle=minangle/60+secangle/60/60;
    }else{
        hourangle=hour*30+minangle/60+secangle/60/60;
    }



    if(abs(secangle-minangle)<=180){
            sec_min_angle=abs(secangle-minangle);

    }else{
        sec_min_angle=360-abs(secangle-minangle);

    }
    if(abs(secangle-hourangle)<=180){
            sec_hour_angle=abs(secangle-hourangle);

    }else{
        sec_hour_angle=360-abs(secangle-hourangle);

    }
    if(abs(minangle-hourangle)<=180){
            min_hour_angle=abs(minangle-hourangle);


    }else{
        min_hour_angle=360-abs(minangle-hourangle);

    }

}


void generator(int &hour, int &minute, int &second){
    int numofseconds=hour*3600+minute*60+second;
    numofseconds++;
    hour=numofseconds/3600;
    hour=hour%12;
    if(hour==0){
        hour=12;
    }
    numofseconds=numofseconds%3600;
    minute=numofseconds/60;
    numofseconds=numofseconds%60;
    second=numofseconds;

}

void secondneedle(int sec){
        int linex,liney;
        linex=250;
        liney=250;
        line(250,250,linex,liney);
        linex=250+150*sin((sec*6)*M_PI/180);
        liney=250-150*cos((sec*6)*M_PI/180);
        setcolor(1);
        line(250,250,linex, liney);//18, 3sdsdf2


};

void minuteneedle(int minute, int sec){
    int linea, lineb;
    linea=250+140*sin((minute*6)*M_PI/180+(sec*6)*M_PI/180/60);
    lineb=250-140*cos((minute*6)*M_PI/180+(sec*6)*M_PI/180/60);
    setcolor(2);
    line(250,250, linea,lineb);

};

void hourneedle(int hour, int minute, int sec){
    int linea, lineb;
    linea=250+130*sin((hour*30)*M_PI/180+(minute*6)*M_PI/180/60+(sec*6)*M_PI/180/60/60);
    lineb=250-130*cos((hour*30)*M_PI/180+(minute*6)*M_PI/180/60+(sec*6)*M_PI/180/60/60);
    setcolor(3);
    line(250,250, linea,lineb);

}
;
void get_time(int &h,int &m,int &s)
{
time_t rawtime;
struct tm *t;
time(&rawtime);
t = localtime(&rawtime);
h=t->tm_hour;
m=t->tm_min;
s=t->tm_sec;
}


int main()
{

 int gdriver = DETECT, gmode;
initgraph(&gdriver,&gmode,"d:\\tc\\bgi");


   cout<<"press 'a' to see present time needle angle difference "<<endl;
   cout<<"press other 'a' to see default time needle angle difference"<<endl;
   cin>>status;
   if(status=="a"){
    while(!kbhit()){
    get_time(hour1,minute1,second1);
    class myclock first(hour1,minute1,second1);
    anglecalculator(hour1,minute1,second1);
    cout<<"angle between hour and min  "<<min_hour_angle<<endl;
    cout<<"angle between min and sec"  <<sec_min_angle<<endl;
    cout<<"angle between hour and sec  "<<sec_hour_angle<<endl;

    delay(1000);
    cleardevice();
        }



   }else{


       cout<<"enter hour needle"<<endl;
       cin>>hour2;
       cout<<"enter minute needle"<<endl;
       cin>>minute2;
       cout<<"enter second needle"<<endl;
       cin>>second2;

       while(!kbhit()){
        generator(hour2,minute2,second2);
        class myclock second(hour2,minute2,second2);
        anglecalculator(hour2,minute2,second2);
    cout<<"angle between hour and min  "<<min_hour_angle<<endl;
    cout<<"angle between min and sec   "  <<sec_min_angle<<endl;
    cout<<"angle between hour and sec  "<<sec_hour_angle<<endl;

        delay(1000);
        cleardevice();
        }

  }

getch();
  return 0;
}
