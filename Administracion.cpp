#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ModuloAdministracion.h"

typedef char cadena[11];


main(){
    FILE *p,*q;
    int x,i;
    cadena nomuser[50];

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

				case 2: p=fopen("Usuarios.dat","rb");
						if(p==NULL){
							printf("Es el primer usuario a registrar\n");
							fclose(p);
						}else{
							transferir(p,nomuser,i);
                        	fclose(p);
                        	printf("Cantidad de usuarios registrados: %d\n",i);
                        	
                        }
                        
                        p=fopen("Usuarios.dat","a+b");
                        transferir(p,nomuser,i);
						registrar2(p,nomuser,i);
						fclose(p);
						system("pause");
                        system("cls");
                        break;
                case 3: p=fopen("Turnos.dat","rb");
                		q=fopen("Profesionales.dat","rb");
                		if(p==NULL){
                			printf("\nNo se han registrado turnos\n");
                		}else{
                		mostrarAtenciones(p,q);
                			
                		}
                		fclose(p);
                		fclose(q);
						system("pause");
                        system("cls");
                        break;
            	
            	case 4:	p=fopen("Turnos.dat","rb");
                		q=fopen("Profesionales.dat","rb");
                		if(p==NULL){
                			printf("\nNo se han registrado turnos\n");
                		}else{
                			rankingProf(p,q);
                		}
            			fclose(p);
                		fclose(q);
            			system("pause");
                        system("cls");
                        break;
            	
                case 5: break;
            	
            	default: printf("\n\tEl valor ingresado es invalido\n");
            			system("pause");
            			system("cls");
            			break;
        }  

    }while(x!=5);



    system("pause");
    return 0;
}
