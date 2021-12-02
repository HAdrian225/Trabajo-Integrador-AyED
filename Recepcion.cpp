#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ModuloRecepcion.h"

int main (){
int Selector;   
    printf("Ingrese 1:");
    scanf("%d",&Selector);
    fflush(stdin);
    if (Selector== 1){
        IniciarSesion();
    }
}