#include<stdio.h>
#include<math.h>
#define H 0.1
#define N 10

double derivada(double x, double y) {
	return(1+pow(x-y,2));
}

double k_1(double x, double y) {
	return(derivada(x,y));
}

double k_2(double x, double y, double k1) {
	return(derivada(x+0.5*H,y+0.5*H*k1));
}

double k_3(double x, double y, double k2) {
	return(derivada(x+0.5*H,y+0.5*H*k2));
}

double k_4(double x, double y, double k3) {
	return(derivada(x+H,y+H*k3));
}

double y_prox(double y, double k1, double k2, double k3, double k4) {
	return(y+H/6.0*(k1+2*k2+2*k3+k4));
}

double x_prox(double x) {
	return(x+H);
}

int main() {
	int i = 0;
	double y = 1, x = 2, k1, k2, k3, k4;	
	FILE *fp = fopen("fc.txt", "w");
	
	while(i <= N) {
		fprintf(fp,"%lf %lf\n", x, y);

		k1 = k_1(x,y);
		k2 = k_2(x,y,k1);
		k3 = k_3(x,y,k2);
		k4 = k_4(x,y,k3);
		
		x = x_prox(x);
		y = y_prox(y,k1,k2,k3,k4);

		i++;
	}

	return(0);
}			
	
	
	
