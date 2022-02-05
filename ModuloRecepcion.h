#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

struct Usuarios{
    char Usuario [11], Contrasenia [32], ApellidoyNombre[60];
};

struct Cliente{
    char ApellidoyNombre[60],Domicilio[60],Localidad[60],Telefono[25];
    int DNICliente,AnioFecha,MesFecha,DiaFecha;
    float Peso;
};

struct Turno{
    int IdProfesional,DNICliente,AnioFecha,MesFecha,DiaFecha;
    char DetalledeAtencion [380];
};


void IniciarSesion(){
    Usuarios Base;
    bool Validador = true;
    int ContadorDeFallos = 0,Segundos, Veces = 1, Exit;
    char UsuarioBase[10], ContraseniaBase[10];

//------------------------------------------Ingreso de Datos------------------------------------------------//
    Ingreso:

    printf("Ingrese el usuario:\n");
    gets(UsuarioBase);
    _flushall();
    printf("Ingrese la contrasenia:\n");
    gets(ContraseniaBase);
    _flushall();
    fflush(stdin);

//----------------------------------------Verificacion de existencia de Archivo  -------------------//
    FILE *Puntero = fopen ("Usuarios.dat","rb");
    if (Puntero == NULL){
        printf("No existe el archivo base, por favor creelo antes de entrar\n");
        goto Salida;
        system("pause");
        system("cls");
    }

//--------------------------------Verificacion de Datos--------------------------------------//
    do{
        fread (&Base,sizeof(Usuarios),1,Puntero);
        if (strcmp(UsuarioBase, Base.Usuario)== 0){
            if (strcmp(ContraseniaBase,Base.Contrasenia)== 0){
                printf ("Contrasenia valida\nIngreso completado\nBienvenido %s\n",Base.ApellidoyNombre);
                Validador = false;
                system("pause");
                goto Salida;
            }else {
                ContadorDeFallos++;
                goto Fallo;
            }
        }else {
            ContadorDeFallos++;
            goto Fallo;
        }
    }while (!feof(Puntero));
    
//--------En caso de fallar se le dara otros intentos, en caso de ser 3 intentos o mas habra un tiempo de penalizacion------------//
    Fallo :
    if ( (ContadorDeFallos % 3) == 0){
        Segundos = 30 * Veces;
        while (Segundos != 0){
            printf("Usted a fallado %d veces, por lo tanto tiene que esperar %d segundos",ContadorDeFallos,Segundos);
            Sleep(1000);
            system("cls");
            Segundos --;
        }
        Veces++;
    }

    if (Validador){
        printf("El usuario o la contrasenia no son correctas, por favor intente de nuevo\nEn caso de que quiera salir ingrese 1: ");
        scanf("%d",&Exit);
        fflush(stdin);
        if (Exit == 1) goto Salida;
        goto Ingreso;
    }
    Salida:
    fclose(Puntero);
}

void RegistrarCliente(){
    Cliente Base;
    FILE *Puntero = fopen ("Clientes.dat","a+b");
    if (Puntero == NULL){
        printf("No existe el archivo base, por favor creelo antes de entrar\n");
        system("pause");
        system("cls");
        goto Salida;
    }
    printf("Ingerese el apellido y nombre del nuevo cliente: ");
    gets(Base.ApellidoyNombre);
    _flushall();
    printf("Ingerese el domicilio del nuevo cliente: ");
    gets(Base.Domicilio);
    fflush(stdin);
    printf("Ingerese el DNI del nuevo cliente: ");
    scanf("%d",&Base.DNICliente);
    fflush(stdin);
    printf("Ingerese la localidad del nuevo cliente: ");
    gets(Base.Localidad);
    fflush(stdin);
    printf("Ingerese el anio de nacimiento del nuevo cliente: ");
    scanf("%d",&Base.AnioFecha);
    fflush(stdin);
    printf("Ingerese el mes de nacimiento del nuevo cliente: ");
    scanf("%d",&Base.MesFecha);
    fflush(stdin);
    printf("Ingerese el dia de nacimiento del nuevo cliente: ");
    scanf("%d",&Base.DiaFecha);
    fflush(stdin);
    printf("Ingerese el peso del nuevo cliente: ");
    scanf("%f",&Base.Peso);
    fflush(stdin);
    printf("Ingerese el telefono del nuevo cliente: ");
    gets(Base.Telefono);
    fflush(stdin);

    fwrite(&Base,sizeof(Cliente),1,Puntero);
    Salida:
    fclose(Puntero);
}

void RegistrarTurno(){
    Turno Base;
    FILE *Puntero = fopen ("Turnos.dat","a+b");
    if (Puntero == NULL){
        printf("No existe el archivo base, por favor creelo antes de entrar\n");
        system("pause");
        system("cls");
        goto Salida;
    }
    printf("Ingerese el ID del profesional: ");
    scanf("%d",&Base.IdProfesional);
    fflush(stdin);
    printf("Ingerese el anio de nacimiento del cliente: ");
    scanf("%d",&Base.AnioFecha);
    fflush(stdin);
    printf("Ingerese el mes de nacimiento del cliente: ");
    scanf("%d",&Base.MesFecha);
    fflush(stdin);
    printf("Ingerese el dia de nacimiento del cliente: ");
    scanf("%d",&Base.DiaFecha);
    fflush(stdin);
    printf("Ingerese el DNI del cliente: ");
    scanf("%d",&Base.DNICliente);
    fflush(stdin);
    printf("Ingerese los detalles de atencion que tiene con el cliente,tiene espacio para poder especificar lo que quiera, max 380 caracteres: ");
    gets(Base.DetalledeAtencion);
    fflush(stdin);

    fwrite(&Base,sizeof(Turno),1,Puntero);
    Salida:
    fclose(Puntero);
}