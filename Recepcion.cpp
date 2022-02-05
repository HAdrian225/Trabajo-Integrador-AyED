#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ModuloRecepcion.h"

int main (){
    int Selector;
    FILE *Abredor;
    bool Salida = true;
    Abredor = fopen("Recepcionistas.dat","w+b");
    fclose(Abredor);
    while (Salida){
        printf("Ingrese 1:");
        scanf("%d",&Selector);
        fflush(stdin);
        switch (Selector){
        case 1:
            IniciarSesion();
            break;
        case 2:
            RegistrarCliente();
            break;
        case 3:
            RegistrarTurno();
            break;
        default:
            Salida = false;
            break;
        }

    }
    system ("pause");
    return 0;
}