#include <stdio.h>
#include <math.h>

const double Pi = 3.14;
int main(void){
    int mode;
    scanf("%d" , &mode);

    switch( mode ){
        case 1:{
            double l;
            scanf("%lf" ,&l );
            printf("%.2lf\n" , l*l*l );
            break;
        }
        case 2:{
            double l,h,w;
            scanf("%lf%lf%lf" ,&l , &h, &w );
            printf("%.2lf\n" , l*h*w );
            break;
        }
        case 3:{
            double r,h;
            scanf("%lf%lf" ,&r , &h );
            printf("%.2lf\n" , Pi*r*r*h );
            break;
        }
        case 4:{
            double l;
            scanf("%lf" ,&l );
            printf("%.2lf\n" , (sqrt(2)/12.0)*l*l*l);
            break;
        }
    }
    return 0;
}

