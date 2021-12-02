#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Usuarios{
    char Usuario [10], Contrasenia [10], ApellidoyNombre[60];
};

struct Profesionales{
    char ApellidoyNombre[60],Telefono[25];
    int IDProfesional,DNI;
};

struct UsuariosYProfesionales{
    Usuarios Base1;
    Profesionales Base2;
};


void IniciarSesion(){
    UsuariosYProfesionales Base;
    char UsuarioBase[10], ContraseniaBase[10];
    printf("Ingrese el usuario:\n");
    gets(UsuarioBase);
    _flushall();
    printf("Ingrese la contrasenia:\n");
    gets(ContraseniaBase);
    _flushall();
    fflush(stdin);
    FILE *Puntero = fopen ("Recepcionistas.dat","rb");
    if (Puntero == NULL){
        printf("No existe el archivo base, por favor creelo antes de entrar\n");
        goto Salida;
    }
    
    while (!feof(Puntero)){
        fread (&Base,sizeof(UsuariosYProfesionales),1,Puntero);
        if (strcmp(UsuarioBase,Base.Base1.Usuario)== 0){
            if (strcmp(ContraseniaBase,Base.Base1.Contrasenia)== 0){
                printf ("Contrasenia valida\nIngreso completado\nBienvenido %s",Base.Base1.ApellidoyNombre);
                system("pause");
                break;
            }
        }
    }
    Salida:
    fclose(Puntero);
    system("pause");
    system("cls");
}