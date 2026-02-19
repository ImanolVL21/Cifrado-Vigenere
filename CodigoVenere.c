#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** args){
	if(argc < 3){
		printf("Se requieren mas argumentos\n");
		return -1;
		}
	// Conocer el tamaño de las palabras
	int Tpalabra, Tclave;	
	char *Tem;
	for(Tem = args[1];*Tem; Tem++); Tpalabra = Tem - args[1];
	for(Tem = args[2];*Tem; Tem++); Tclave = Tem - args[2];
	char *p = malloc(sizeof(char) * Tpalabra);
	// Cifrado de Venere
	for (int i = 0; i<Tpalabra; i++) 
		p[i] = (char)((args[1][i] + args[2][i%Tclave] - 130)%26) + 'A';
	for (int i = 0; i < Tpalabra; i++)
		printf("%c", p[i]);
	printf("\n");
	// Descifrado de Venere
	for (int i = 0; i<Tpalabra; i++) 
		printf("%c", (char)((p[i] - args[2][i%Tclave]) < 0 ? (((p[i] - args[2][i%Tclave] + 26)%26) + 'A') : (((p[i] - args[2][i%Tclave])%26) + 'A')));
	printf("\n");
	return 0;
}
