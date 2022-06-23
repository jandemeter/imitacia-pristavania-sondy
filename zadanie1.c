#include <stdio.h>

void prvy_vypis(double m,double T,double H,double g,double vsoft,double dt){
    printf("m=%.3lf\n",m);
    printf("T=%.3lf\n",T);
    printf("H=%.3lf\n",H);
    printf("g=%.3lf\n",g);
    printf("vsoft=%.3lf\n",vsoft);
    printf("dt=%.3lf\n",dt);

}
double vypocet_de(double T,double m,double g,double H){
    double A = T/m;
    double df = ((A-g)*H)/A;
    double de = H-df;
    return de;

}
int stav_motora(double vsoft,double v,double h, double de){
    if(v<vsoft & h<=de){
        return 1;
    }
    else{
        return 0;
    }

}
double vypocet_h(double h,double v,double dt,double a){
    h = h + (v * dt) + ((a*(dt*dt))/2)  ;
    return h;

}
double vypocet_v(double v,double a,double dt){
    v = v + a*dt;
    return v;

}
void vypis_simulacie(double vsoft, double v, double H, double g, double dt,double T,double m,double de){


    double h = H;
    double t = 0;
    double a = 0;
    int total =0;
    int olds = 0;
    int max = 1;
    int actual = 0;


    while(h>0){

        int s = stav_motora(vsoft,v,h,de);
        printf("s=%d ",s);

        if(olds==1 & s==1){
            actual++;
        }
        if(olds==1 & s==0){
            actual =0;
        }
        if(actual>max){
            max=actual;
        }
        olds = s;

        if(s==1){
            a = (T/m)-g;
            total++;
        }
        else{
            a = -g;
        }
        printf("h=%08.3lf ",h);
        h = vypocet_h(h, v, dt, a);


        printf("t=%.3lf ",t);
        t += dt;

        printf("v=%.3lf\n",v);
        v = vypocet_v(v,a,dt);

    }
    max++;
    printf("---Landed---\n");
    printf("h    =%08.3lf\n" , h);
    printf("t    =%8.3lf\n",t);
    printf("v    =%8.3lf\n",v);
    printf("total=%4d\n",total);
    printf("max  =%4d",max);

}


int main()
{
    double m,T,H,g,vsoft,dt;
    double v = 0;

    scanf("%lf""%lf""%lf""%lf""%lf""%lf",&m,&T,&H,&g,&vsoft,&dt);

    prvy_vypis(m,T,H,g,vsoft,dt);

    double de = vypocet_de(T,m,g,H);
    printf("de=%.3lf\n",de);


    vypis_simulacie(vsoft,v,H,g,dt,T,m,de);





    return 0;
}





