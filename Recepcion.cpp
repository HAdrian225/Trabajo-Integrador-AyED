#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ModuloRecepcion.h"

int main (){
    int Selector;
    bool Salida = true;
    while (Salida){
        printf("Ingrese 1 para iniciar sesion\n");
        printf("Ingrese 2 para registrar un nuevo cliente\n");
        printf("Ingrese 3 para registrar un nuevo turno\n");
        printf("Ingrese 4 para listar las evoluciones de los clientes\n");
        printf("---------------------------------------------\n");
        printf("Ingrese 5 para salir de la aplicacion\n");
        printf("---------------------------------------------\n");
        printf("Numero a ingresar: ");
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
        case 4:
            ListadoDeEvoluciones();
            break;
        case 5: 
            Salida = false;
            break;
        default:
            printf("Usted a ingresado un numero que no aparece en la lista por favor vuelta a ingresar un numero bien\n");
            system("pause");
            system("cls");
            break;
        }

    }
    system ("pause");
    return 0;
}