#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

struct Usuarios{
    char Usuario [10], Contrasenia [10], ApellidoyNombre[60];
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
    int ContadorDeFallos = 0,Segundos, Veces = 1;
    char UsuarioBase[10], ContraseniaBase[10];
    printf("Ingrese el usuario:\n");
    gets(UsuarioBase);
    _flushall();
    printf("Ingrese la contrasenia:\n");
    gets(ContraseniaBase);
    _flushall();
    fflush(stdin);
    FILE *Puntero = fopen ("Usuarios.dat","rb");
    if (Puntero == NULL){
        printf("No existe el archivo base, por favor creelo antes de entrar\n");
        goto Salida;
        system("pause");
        system("cls");
    }
    
    while (!feof(Puntero)){
        fread (&Base,sizeof(Usuarios),1,Puntero);
        if (strcmp(UsuarioBase, Base.Usuario)== 0){
            if (strcmp(ContraseniaBase,Base.Contrasenia)== 0){
                printf ("Contrasenia valida\nIngreso completado\nBienvenido %s",Base.ApellidoyNombre);
                Validador = false;
                system("pause");
                break;
            }
        }
    }
    if ( (ContadorDeFallos % 3) == 0){
        Segundos = 30 * Veces;
        while (Segundos != 0){
            Segundos --;
            Sleep(1000);
        }
        
    }

    if (Validador){
        printf("El usuario o la contraseña no son correctas, por favor intente de nuevo\n");
        ContadorDeFallos ++;
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