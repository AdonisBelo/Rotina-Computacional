#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define f(x) (3*x*x*x + 2*x*x - 4*x - 2)
int main(){
	clock_t Ticks[2];
	Ticks[0] = clock();
	printf("Metodo Regula Falsi\n\n");
	printf("A funcao analisada eh: 3x^3 - 2x^2 + 4x + 1\n");
	int i=0;
	float x0, x1, x2, f0, f1, f2, e;

	printf("Digite o intervalo:\n");
	scanf("%f %f",&x0,&x1);
	printf("Digite o erro estimado:\n");
	scanf("%f",&e);
	
	if((f(x0)*f(x1))>0){
	    printf("Intervalo invalido!");      
	    exit(1);                                                 
	}
	else if(f(x0)==0 || f(x1)==0){
	    printf("A raiz eh um dos intervalos. A raiz eh %f\n",f(x0)==0?x0:x1);
	    exit(0);
	}
	
	do{
	    f0=f(x0);
	    f1=f(x1);
	    f2=f(x2);
	    x2= ((x0*f1)-(x1*f0))/(f1-f0);
	    if(f0*f2<0){
	    	x1=x2;
	    	f1=f2;
		} else{
			x0=x2;
			f0=f2;
		}
		i++;
		printf("iteracao: %d\t", i);
		printf("raiz: %.11f\t", x2);
		printf("valor da funcao: %.11f\n", f2);
	    
	}while(fabs(f2)>e);
		
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms\n\n", Tempo);
		return 0;
	}
