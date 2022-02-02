#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>


struct Fecha
{
  int dia;
  int mes;
  int anio;	
};

struct Profesionales
{
	char ApellidoNombre[60];
	int IdProfesional;
	int DNI;
	int Telefono;
};

struct Cliente
{
	char NombreCliente [60];
	char Domicilio [60];
	int DNI_Cliente;
	char localidad[60];
	Fecha fechanacimiento;
	float Peso;
	int Telefono;
};

struct Turnos
{
	int IdProfesional;
	Fecha fecha;
	int dniCliente;
	int edadCliente;
	char DetalleAtencion[380];
	int fueatendido; //-1) si -2) no
};

struct CuentasDeUsuarios
{
	char user[10];
	char password [32];
	char ApellidoNombre[60];
};

void RegistroEvolucionCliente(int bandera);
void Listadeespera(int bandera);
void InicioDeSesion(int &bandera);
int menu();

main()
{	
	int opcionmenu, bandera=0;
	do{
		opcionmenu=menu();
		switch(opcionmenu)
		{
			case 1: InicioDeSesion(bandera);
			break;
			
			case 2: Listadeespera(bandera);
			break;
			
			case 3: RegistroEvolucionCliente(bandera);
			break;
			
			case 4: printf("***FIN DEL PROGRAMA***\n\n");
			break;
			
			default: printf("***LA OPCION NO ES VALIDA***\n\n");
			break;
		}
   }while(opcionmenu!=4);
	
}
/*void gotoxy(int x, int y){
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X= x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon, dwPos);
}*/

int menu()
{      
    system("cls");
	int opc;
	printf("------------------------------------");
	 printf("\n\n\tModulo Espacios \n\n");
	 printf("------------------------------------");
	 printf("\n\n1)Iniciar Sesion");
	 printf("\n\n2)Visualizar lista de espera de turnos [informe]");
	 printf("\n\n3)Registrar evolucion del Cliente");
	 printf("\n\n4)Cerrar la aplicacion");
	 printf("\n\nIngrese Opcion: ");
	scanf("%d",&opc);
	return(opc);
}

void InicioDeSesion(int &bandera)
{
	system("cls");
	
	char nameuser[10], passuser[32], usuario[30]; 
	FILE *arch2;int clavecorrecta, usuariocorrecto;
	CuentasDeUsuarios usu;
	
	arch2=fopen("Recepcionistas.dat","a+b");
	
	if(arch2==NULL)
	{
		printf("\nError en el programa");
	}
	else
	{
		printf("\nIngrese nombre de usuario: ");
		_flushall();
		gets(nameuser);
		printf("\nClave de usuario: ");
		_flushall();
		gets(passuser);
		bandera=0;
		fread(&usu,sizeof(CuentasDeUsuarios),1,arch2);
		
		while(!feof(arch2))
		{
			usuariocorrecto=strcmp(nameuser, usu.user);
			clavecorrecta=strcmp(passuser, usu.password);
			
			if(clavecorrecta==0&&usuariocorrecto==0)
			{
				strcpy(usuario,usu.ApellidoNombre);
				bandera=1;
			}
			
			fread(&usu,sizeof(CuentasDeUsuarios),1,arch2);	
		}
		
		if(bandera==1)
		{
			strcat(usuario," !");
			printf("\n                                                    ");
			printf("\n                                                    ");
			printf("\nBienvenido/a: ");
			puts(usuario);
			system("pause");
			printf("\n                                                     ");
			printf("\n                                                     ");
		}
		
		if(bandera==0)
		{
			printf("\n                                                    ");
			printf("\n                                                    ");
			printf("\nClave o usuario incorrecto");
			system("pause");
			printf("                                                    ");
			printf("                                                    ");
			
		}
		
	}
	system("pause");
	
}

void Listadeespera(int bandera)
{
	system("cls");
	 
	//----------------Declaracion de las variables--------------------------------------///	
	FILE *arch4, *arch3; Cliente reg4; Turnos reg3; int IdProfesional, IdProfesionalcorrecta, Dia, Mes, Anio, hayturnos;
	
	///--------------------------------Apertura de Archivos -----------------------------------///	
	arch4=fopen("Clientes.dat","rb");
	arch3=fopen("Turnos.dat","rb");
	
	//--------------------------------Verificacion de Archivos--------------------------------------///	
	if(arch3==NULL|| arch4==NULL)
	{
		printf("\nError en el programa, Archivos no cargados");
	}
	//--------------------------------Control de inicio de sesion--------------------------------------///	
	if(bandera==0)
	{
	 printf("\nNo ha iniciado sesion");
	 system("pause");
	printf("  \n                                                                    ");
	printf("\n                                                                   ");
	}
	else
	{//--------------------------------Solicitud de los datos--------------------------------------	
	
		printf("\nIngrese su ID por favor: ") ;scanf("%d",&IdProfesional);
		printf("  \n                                                         ");
		printf("\nFecha: ");	
		printf("\nDia: ");
			scanf("%d",&Dia);
		printf("\nMes: ");
			scanf("%d",&Mes);
		printf("\nAnio: ");
			scanf("%d",&Anio);
		 
		//--------------------------------Verificacion de los datos en los archivos--------------------------------------///	
		hayturnos=0;
		IdProfesionalcorrecta=0;
		fread(&reg3,sizeof(Turnos),1,arch3);
		
		while(!feof(arch3))
		{
			if(IdProfesional==reg3.IdProfesional)	
			{
			  	IdProfesionalcorrecta=1;
			}
			fread(&reg3,sizeof(Turnos),1,arch3);
		}
		  
		if(IdProfesionalcorrecta==1)
		{
	  		rewind(arch3);
			fread(&reg3,sizeof(Turnos),1,arch3);
	        while(!feof(arch3))
	        {  
	            if(reg3.fueatendido==2 && reg3.IdProfesional==IdProfesional && Dia==reg3.fecha.dia && Mes==reg3.fecha.mes && Anio==reg3.fecha.anio)
	            {
			        rewind(arch4);
			        fread(&reg4,sizeof(Cliente),1,arch4);
			        
			        while(!feof(arch4))
			        {    ///--------------------------------Impresion de lista de espera--------------------------------------///	
			            printf("\nEn espera: ");
				        if(reg4.DNI_Cliente=reg3.dniCliente)
		    		    {
			    		   	hayturnos=1;
						    printf("\nCliente: ");
						    puts(reg4.NombreCliente);
						    printf("\nFecha de turno: ");
						    printf("\nDia: %d",reg3.fecha.dia);
						    printf("\nMes: %d", reg3.fecha.mes);
						    printf("\nAnio: %d",reg3.fecha.anio);
						    printf("\nDNI: %d",reg3.dniCliente);
						    system("pause");
						    printf("                                      ");
				        }
		 	          fread(&reg4,sizeof(Cliente),1,arch4);	
			        }
	            }
		        fread(&reg3,sizeof(Turnos),1,arch3);	
	        }
		}
		else{
		printf("\nID incorrecta, Vuelva a intentarlo");}
		
		if(hayturnos==0)
		{
		printf("\nNo hay turnos en la fecha");
		system("pause");
		}
  	     
		fclose(arch3); fclose(arch4);
		
    }
	system("pause");
}

void RegistroEvolucionCliente(int bandera)
{
	system("cls");
	FILE *arch4, *arch3;Cliente reg4; Turnos reg3;
	int Clienteencontrada=0, tamanoevolucion, evolucionregistrada,dniCliente,IdProfesional, IdProfesionalcorrecta, evolucionguardada, no=2, si=1;
	char nombreCliente[32], DetalleEvolucion[380]; bool atencion;
	
	arch4=fopen("Clientes.dat","r+b");
	arch3=fopen("Turnos.dat","r+b");
	
	//Verificar archivos correctos-----
	if(arch4==NULL|| arch3==NULL)
	{
	printf("\nError en el sistema-Archivos no cargados");
	}	

	//Verificar Inicio de Sesion-----
	if(bandera==0)
	{
		printf("\nNo ha iniciado sesion");
		system("pause");
	}
	//Verificar IdProfesional----
	else
	{
	printf("\nIngrese su ID: "); 
	scanf("%d",&IdProfesional);
		do
		{
			IdProfesionalcorrecta=0;
			fread(&reg3,sizeof(Turnos),1,arch3);
			rewind(arch3);
			
			while(!feof(arch3))
			{
				if(reg3.IdProfesional==IdProfesional)
				{
					IdProfesionalcorrecta=1;
				}
				fread(&reg3,sizeof(Turnos),1,arch3);
			}
			
			if(IdProfesionalcorrecta==0)
			{
				printf("\nEl numero de la ID no esta en el sistema- Vuelva a intentarlo");
				printf(" \n                                                                   ");
			}
			
	    }while(IdProfesionalcorrecta==0);
	    
		 printf("\nIngrese el DNI del Cliente: "); scanf("%d",&dniCliente);
		
		//Registrar evolucion----		
		evolucionregistrada=0;
		rewind(arch3);
		
		fread(&reg3,sizeof(Turnos),1,arch3);
		
		while(!feof(arch3)&&evolucionregistrada==0)
		{
			if(dniCliente==reg3.dniCliente && reg3.fueatendido==2&&reg3.IdProfesional==IdProfesional)
			{
				fread(&reg4,sizeof(Cliente),1,arch4);
				while(!feof(arch4)&&evolucionregistrada==0)
				{
				 	if(reg4.DNI_Cliente==dniCliente)
					{
						Clienteencontrada=1;
						printf("                                                                                ");
						printf("                                                                                ");
						printf("\nCliente: ");
						puts(reg4.NombreCliente);
						printf("\nPeso: %.2f Kg",reg4.Peso);
						printf("\nEdad: %d anios",reg3.edadCliente);
						printf("\nDNI Cliente: %d",reg4.DNI_Cliente);
						do 
						{
							printf("\nIngrese la evolucion de la Cliente en no mas de 380 letras:");
							_flushall(); gets(DetalleEvolucion);   // (reg3.DetalleAtencion); 
							tamanoevolucion=strlen(DetalleEvolucion);//(reg3.DetalleAtencion);
							if(tamanoevolucion>380) //(tamanoevolucion>380)
							{
								printf("                                                                     ");
							}
						}while(tamanoevolucion>380||tamanoevolucion<5);
						printf("\nIngrese su ID para finalizar: ");
						 printf("\nID: "); scanf("%d",&IdProfesional);//("%d",reg3.IdProfesional);
						
						evolucionregistrada=1;
						break;	
					 }
			      fread(&reg4,sizeof(Cliente),1,arch4);
				}
			
		    }
			fread(&reg3,sizeof(Turnos),1,arch3);		  
	    }
    
		if(evolucionregistrada==1)
		{
		system("pause");
			//Guardar evolucion-----	 
			evolucionguardada=0;
			rewind(arch3); rewind(arch4);	
			fread(&reg3,sizeof(Turnos),1,arch3);
			while(!feof(arch3)&&evolucionguardada==0)
			{
				if(reg3.fueatendido==2 && reg3.dniCliente==dniCliente&&reg3.IdProfesional==IdProfesional)
				{   
					fread(&reg4,sizeof(Cliente),1,arch4);
					while(!feof(arch4)&&evolucionguardada==0)
					{   
						if(reg4.DNI_Cliente==dniCliente && reg3.fueatendido==2 && evolucionguardada==0);
						{
							reg3.edadCliente=reg3.fecha.anio-reg4.fechanacimiento.anio;
							reg3.fueatendido=1;
							strcpy(reg3.DetalleAtencion,DetalleEvolucion);
							int pos=ftell(arch3)-sizeof(Turnos);
							fseek(arch3,pos,SEEK_SET);
							fwrite(&reg3,sizeof(Turnos),1,arch3);
							printf("\nSe ha guardado la evolucion correctamente ");
							evolucionguardada=1;
							break;
						}
						fread(&reg4,sizeof(Cliente),1,arch4);
					}
				}
				if(evolucionguardada==1)
				{
					break;
				}
				else
				{
					fread(&reg3,sizeof(Turnos),1,arch3);  
				}
			}
		}
		
		fclose(arch4); fclose(arch3);
		
		if(evolucionregistrada==0)
		{
		printf("\nEl dni ingresado no esta registrado en sistema");
		}
    }
	system("pause");
}


