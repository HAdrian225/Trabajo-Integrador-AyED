#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profesionales{
        char apenom[60];
        int id;
        int dni;
        char phone[25];
};

void registrar(FILE *p){
        profesionales reg;

        printf("\nCREAR CUENTA DE PROFESIONAL\n-----------------------------------\n");
        printf("Apellido y nombre: ");
        _flushall();
        gets(reg.apenom);
        printf("ID: ");
        scanf("%d",&reg.id);
        printf("DNI: ");
        scanf("%d",&reg.dni);
        printf("Numero de telefono: ");
        _flushall();
        gets(reg.phone);
        fwrite(&reg,sizeof(profesionales),1,p);
        
}



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
