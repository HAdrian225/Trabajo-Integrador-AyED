#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profesionales{
        char apenom[60];
        int id;
        int dni;
        char phone[25];
}

main(){

    int x;

    do{ 
        printf("Módulo Administración\n==========================\n1.- Registrar Profesional\n2.- Registrar Usuario Recepcionista\n3.- Atenciones por Profesional\n5.- Ranking de Profesionales por Atenciones\n6.- Cerrar la aplicación.\nIngrese una opción: ");
        scanf("%d",&x);
        switch(x){




                case 6: default;
                        break;
        }  

    }while(x!=6);



    system("pause");
    return 0;
}