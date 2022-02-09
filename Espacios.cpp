#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct Fecha
{
  int anio;
  int mes;
  int dia;	
};

struct Profesionales
{
	char ApellidoNombre[60];
	int IdProfesional;
	int DNI;
	char phone[25];
};

struct Cliente
{
	char NombreCliente [60];
	char Domicilio [60];
	char localidad[60];
	char Telefono[25];
	int DNI_Cliente;
	Fecha fechanacimiento;
	float Peso;
};

struct Turnos
{
	int IdProfesional,dniCliente,fueatendido;//-1) si -2) no
	Fecha fecha;
	char DetalleAtencion[380]; 
};

struct CuentasDeUsuarios
{
	char user[11];
	char password [32];
	char ApellidoNombre[60];
};

void RegistroEvolucionCliente(int bandera,int &ID);
void Listadeespera(int bandera,int &ID);
void InicioDeSesion(int &bandera,int &ID);
int menu();

main()
{	int ID;
	int x, bandera=0;
	do{
		x=menu();
		switch(x)
		{
			case 1: InicioDeSesion(bandera,ID);
			break;
			
			case 2: Listadeespera(bandera,ID);
			break;
			
			case 3: RegistroEvolucionCliente(bandera,ID);
			break;
			
			case 4: printf("***FIN DEL PROGRAMA***\n\n");
			break;
			
			default: printf("***LA OPCION NO ES VALIDA***\n\n");
			break;
		}
   }while(x!=4);
	
}

int menu()
{      
    system("cls");
	int n;
	printf("------------------------------------");
	 printf("\n\n\tModulo Espacios \n\n");
	 printf("------------------------------------");
	 printf("\n\n1)Iniciar Sesion");
	 printf("\n\n2)Visualizar lista de espera de turnos [informe]");
	 printf("\n\n3)Registrar evolucion del Cliente");
	 printf("\n\n4)Cerrar la aplicacion");
	 printf("\n\nIngrese Opcion: ");
	scanf("%d",&n);
	return(n);
}

void InicioDeSesion(int &bandera,int &ID)
{
	system("cls");
	
	char apenom[60];
	int id; 
	FILE *arch2;int clavecorrecta, usuariocorrecto;
	Profesionales usu;
	
	arch2=fopen("Profesionales.dat","rb");
	
	if(arch2==NULL)
	{
		printf("\nError en el programa");
	}
	else
	{
		printf("\nIngrese nombre y apellido: ");
		_flushall();
		gets(apenom);
		printf("\nIngrese la ID: ");
		scanf("%d",&id);
		bandera=0;
		fread(&usu,sizeof(Profesionales),1,arch2);
		
		while(!feof(arch2))
		{
			usuariocorrecto=strcmp(apenom, usu.ApellidoNombre);
			clavecorrecta=id-usu.IdProfesional;
			
			if(clavecorrecta==0 && usuariocorrecto==0)
			{	
				ID=id;
				bandera=1;
				goto salida;
			}
			
			fread(&usu,sizeof(Profesionales),1,arch2);	
		}
		
		salida:
		if(bandera==1)
		{
			strcat(apenom," !");
			printf("\n                                                    ");
			printf("\n                                                    ");
			printf("\nBienvenido/a: %s\n",apenom);
			printf("\n");
			printf("\n");
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
	fclose(arch2);
	system("pause");
	
}

void Listadeespera(int bandera,int &ID)
{
	system("cls");
	 
	//----------------Declaracion de las variables--------------------------------------///	
	FILE *arch; 
	Turnos reg; 
	int IdProfesional, IdProfesionalcorrecta, Dia, Mes, Anio, hayturnos=0;
	
	///--------------------------------Apertura de Archivos -----------------------------------///	
	arch=fopen("Turnos.dat","rb");
	
	//--------------------------------Verificacion de Archivos--------------------------------------///	
	if(arch==NULL)
	{
		printf("\nError en el programa, Archivos no cargados\n\n");
		goto salida;
	}
	//--------------------------------Control de inicio de sesion--------------------------------------///	
	if(bandera==0)
	{
	 printf("\nNo ha iniciado sesion\n\n");
	                                                             
	}else{
///--------------------------------Impresion de lista de espera--------------------------------------///	
		fread(&reg,sizeof(Turnos),1,arch);
	
		while(!feof(arch)){
		  
	        if( reg.IdProfesional==ID)
            {  
            	hayturnos=1;
            	if(reg.fueatendido==2){
            		
					printf("\nEn espera:\nDNI: %d\nFecha: %d / %d / %d \nHistorial: %s\n\n",reg.dniCliente,reg.fecha.dia,reg.fecha.mes,reg.fecha.anio,reg.DetalleAtencion);
					
				}else{
            		printf("\nYa atendido:\nDNI: %d\nFecha: %d / %d / %d \nHistorial: %s\n\n",reg.dniCliente,reg.fecha.dia,reg.fecha.mes,reg.fecha.anio,reg.DetalleAtencion);
            		
            	}     
		 	          
		    }
		    fread(&reg,sizeof(Turnos),1,arch);
	   }
		
		if(hayturnos==0)
		{
		printf("\nNo hay turnos en la fecha");
		system("pause");
		}
  	     
		fclose(arch);
		
    }
    
    salida:
	system("pause");
}

void RegistroEvolucionCliente(int bandera,int &ID)
{
	system("cls");
	FILE *archCLI, *archTUR;
	Cliente regcli; 
	Turnos regtur;
	int cont;
	int Clienteencontrada=0, tamanoevolucion, evolucionregistrada,dniCliente, evolucionguardada=0;
	char  DetalleEvolucion[380]; bool atencion;
	
	archCLI=fopen("Clientes.dat","r+b");
	archTUR=fopen("Turnos.dat","r+b");
	
	//Verificar archivos correctos-----
	if(archCLI==NULL or archTUR==NULL)
	{
	printf("\nError en el sistema-Archivos no cargados");
	}	

	//Verificar Inicio de Sesion-----
	if(bandera==0)
	{
		printf("\nNo ha iniciado sesion");
		system("pause");
	}
	else
	{
	
		printf("\nIngrese el DNI del Cliente: "); 
		scanf("%d",&dniCliente);
		
		//Registrar evolucion----		
		evolucionregistrada=0;
		
		fread(&regtur,sizeof(Turnos),1,archTUR);
		
		while(!feof(archTUR) and evolucionregistrada==0)
		{
			if(dniCliente==regtur.dniCliente and regtur.fueatendido==2)
			{
				fread(&regcli,sizeof(Cliente),1,archCLI);
				while(!feof(archCLI) and evolucionregistrada==0)
				{
				 	if(dniCliente==regcli.DNI_Cliente)
					{
						Clienteencontrada=1;
						printf("\n----------------------------------------------------------------------");
						printf("\nCliente: ");
						puts(regcli.NombreCliente);
						printf("\nPeso: %.2f Kg",regcli.Peso);
						printf("\nEdad: %d anios",2022-(regcli.fechanacimiento.anio));
						printf("\nDNI Cliente: %d",regcli.DNI_Cliente);
						do 
						{
							printf("\n\nIngrese la evolucion de la Cliente en no mas de 380 letras:");
							_flushall();
							gets(DetalleEvolucion);   // (reg3.DetalleAtencion); 
							tamanoevolucion=strlen(DetalleEvolucion);//(reg3.DetalleAtencion);
							if(tamanoevolucion>380 or tamanoevolucion<5) //(tamanoevolucion>380)
							{
								printf("Debe escribir su evolucion de manera adecuada\n");
							}
						}while(tamanoevolucion>380||tamanoevolucion<5);
						
		
						evolucionregistrada=1;	
					}
			      fread(&regcli,sizeof(Cliente),1,archCLI);
				}
			
		    }
			fread(&regtur,sizeof(Turnos),1,archTUR);		  
	    }
    	fclose(archCLI);
    	rewind(archTUR);
    	
    	//Guardar evolucion-----	
    	
		if(Clienteencontrada==1){
			cont=0;
			do{	
				fread(&regtur,sizeof(Turnos),1,archCLI);
				if(regtur.IdProfesional==ID){
				regtur.fueatendido=1;
				strcat(regtur.DetalleAtencion," / ");
				strcat(regtur.DetalleAtencion,DetalleEvolucion);
				fseek(archTUR,cont*sizeof(Turnos),SEEK_SET);
				fwrite(&regtur,sizeof(Turnos),1,archTUR);
				
				evolucionguardada=1;
				
				}
				cont++;
			}while(regtur.IdProfesional!=ID);
			
		}else{
		
			printf("\nEl dni ingresado no esta registrado en sistema");
		}
		
		if(evolucionguardada=1){
			printf("\n---datos cargados correctamente---\n");
		}
		fclose(archTUR);
		
    }
	system("pause");
    system("cls");
}


