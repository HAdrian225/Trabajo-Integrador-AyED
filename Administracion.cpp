#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ModuloAdministracion.h"


main(){
    FILE *p;
    int x;

    do{ 
        printf("Modulo Administracion\n==========================\n1.- Registrar Profesional\n2.- Registrar Usuario Recepcionista\n3.- Atenciones por Profesional\n4.- Ranking de Profesionales por Atenciones\n5.- Cerrar la aplicacion.\nIngrese una opcion: ");
        scanf("%d",&x);
        switch(x){
                case 1: p=fopen("Profesionales.dat","ab");
                        registrar(p);
                        fclose(p);
                        system("pause");
                        system("cls");
                        break;



                case 5: break;
                        
        }  

    }while(x!=5);



    system("pause");
    return 0;
}
