
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

struct usuarios{
	char user[11];
	char passw[32];
	char apenom[60];
};


void registrar2(FILE *p){
	int cDigit=0,cMayus=0,cMin;
	usuarios reg;
	int cPunt=0,cConsAlpha=0,cConsDigit=0;
	char contraux[32];
	
	printf("\nCREACION DE USUARIO PARA RECEPCION\n------------------------------\n");
	printf("Nombre de usuario\nDebera cumplir los siguientes requisitos\n1. Ser unico para cada usuario registrado.\n2. Comenzar con una letra minuscula.\n3. Tener al menos 2 letras mayusculas.\n4. Tener como maximo 3 digitos.\n");
	do{
		cDigit=0;
		cMayus=0;
		cMin=0;
		printf("Ingrese el nombre de usuario: ");
		_flushall();
		gets(reg.user);
		
		if(strlen(reg.user)<6 or strlen(reg.user)>10){
			printf("El nombre debe ser entre 6 y 10 caracteres\n");
		}
		if(islower(reg.user[0])!=0){
				cMin=1;
		}else{
			printf("El nombre debe iniciar con una letra minuscula\n");
		}
		
		
		for(int i=0;i<strlen(reg.user);i++){
			
			if(isdigit(reg.user[i])!=0){
				cDigit++;
			}
			if(isupper(reg.user[i])!=0){
				cMayus++;
			}
		}
		
		if(cDigit>3){
			printf("Debe contener como maximo 3 digitos\n");
		}
		if(cMayus<2){
			printf("Debe contener al menos 2 mayusculas\n");
		}
		system("pause");
		system("cls");
		
	}while(strlen(reg.user)<6 or strlen(reg.user)>10 or cMin==0 or cDigit>3 or cMayus<2);
	
	printf("\nCREACION DE USUARIO PARA RECEPCION\n------------------------------\n");
	printf("Contrasena\nDenera respetar lo siguiente:\n1. Debera contener al menos una letra mayuscula, una letra minuscula y un numero.\n2. No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.\n3. Debera tener entre 6 y 32 caracteres.\n4. No debe tener mas de 3 caracteres numericos consecutivos.\n5. No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente). Este criterio es valido tanto para letras mayusculas, minusculas o combinaci�n de ambas\n");
	do{
		cDigit=0;
		cMayus=0;
		cMin=0;
		cPunt=0;
		cConsAlpha=0;
		cConsDigit=0;
		
		printf("Ingrese una contrasena: ");
		_flushall();
		gets(reg.passw);
		
		if(strlen(reg.passw)<6 or strlen(reg.passw)>32){
			printf("La contrase�a debe ser entre 6 y 32 caracteres\n");
		}
		
		for(int i=0;i<strlen(reg.passw);i++){
			
			if(islower(reg.passw[i])!=0){
				cMin++;
			}
			if(isupper(reg.passw[i])!=0){
				cMayus++;
			}
			if(isdigit(reg.passw[i])!=0){
				cDigit++;
			}
			if(ispunct(reg.passw[i])!=0 or isspace(reg.passw[i])!=0){
				cPunt++;
			}
		}
		
		strcpy(contraux,reg.passw);
		strlwr(contraux);
		
		for(int j=0;j<strlen(reg.passw)-1;j++){
				
			
			
			if(isalpha(contraux[j])!=0){
				if(contraux[j]-contraux[j+1]==-1){
				cConsAlpha++;
				}
			}
			
			if(isdigit(contraux[j])!=0){
				if(contraux[j]-contraux[j+1]==-1){
				cConsDigit++;
				}
			}
			
		}
		
		if(cConsDigit>2){
			printf("No deben haber mas de 3 digitos consecutivos\n");
		}
		if(cConsAlpha>1){
			printf("No deben haber mas de 2 caracteres alfabeticamente consecutivos\n");
		}
		if(cDigit==0 or cMayus==0 or cMin==0){
			printf("Debe contener al menos una letra mayuscula, una letra minuscula y un numero\n");
		}
		if(cPunt!=0){
			printf("No debe contener ningun signo de puntuacion ni espacios\n");
		}
		
		system("pause");
		system("cls");
	}while(strlen(reg.passw)<6 or strlen(reg.passw)>32 or cDigit==0 or cMayus==0 or cMin==0 or cPunt!=0 or cConsDigit>2 or cConsAlpha>1);

	printf("\nCREACION DE USUARIO PARA RECEPCION\n------------------------------\n");
	printf("Apellido y nombre: ");
	_flushall();
	gets(reg.apenom);
	
	fwrite(&reg,sizeof(usuarios),1,p);
}

