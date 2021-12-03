#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ModuloRecepcion.h"

int main (){
int Selector;
    FILE *Abredor;
    Abredor = fopen("Recepcionistas.dat","w+b");
    fclose(Abredor);
    printf("Ingrese 1:");
    scanf("%d",&Selector);
    fflush(stdin);
    if (Selector== 1){
        IniciarSesion();
    }
    if(Selector == 2){
        RegistrarCliente();
    }
    if(Selector == 3){
        RegistrarTurno();
    }
    
}