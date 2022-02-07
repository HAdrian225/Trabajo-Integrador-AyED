struct fecha{
	int dia;
	int mes;
	int anio;
};

struct turno{
    int IdProfesional,DNICliente,Atendido;
    fecha fec;
    char DetalledeAtencion [380];
};

struct profesionales{
        char apenom[60];
        int id;
        int dni;
        char phone[25];
};

struct usuarios{
	char user[11];
	char passw[32];
	char apenom[60];
};

struct rank{
	int id;
	char name[60];
	int cant;
};

typedef char cadena[11];


void transferir(FILE *p,cadena nomuser[50],int &i){
        i=0;
        usuarios reg[50];
        fread(&reg[i],sizeof(usuarios),1,p);
        strcpy(nomuser[i],reg[i].user);
        while(!feof(p)){
            i++;
            fread(&reg[i],sizeof(usuarios),1,p);
            strcpy(nomuser[i],reg[i].user);
        }

}

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




void registrar2(FILE *p,cadena nomuser[50],int r){
	int cDigit=0,cMayus=0,cMin,user=0;
	usuarios reg;
	int cPunt=0,cConsAlpha=0,cConsDigit=0;
	char contraux[32];

	printf("\nCREACION DE USUARIO PARA RECEPCION\n------------------------------\n");
	printf("Nombre de usuario\nDebera cumplir los siguientes requisitos\n1. Ser unico para cada usuario registrado.\n2. Comenzar con una letra minuscula.\n3. Tener al menos 2 letras mayusculas.\n4. Tener como maximo 3 digitos.\n");
	do{
		cDigit=0;
		cMayus=0;
		cMin=0;
		user=0;
		printf("Ingrese el nombre de usuario: ");
		_flushall();
		gets(reg.user);
		
		for(int m=0;m<=r;m++){
			if(strcmp(nomuser[m],reg.user)==0){
				user++;
				printf("El nombre de usuario no debe ser igual a uno anteriormente registrado\n");
			}

		}


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
		
	}while(strlen(reg.user)<6 or strlen(reg.user)>10 or cMin==0 or cDigit>3 or cMayus<2 or user!=0);
	
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


void mostrarAtenciones(FILE *p,FILE *q){
	
	int id,cant=0;
	profesionales prof;
	turno turn;
	
	fread(prof,sizeof(profesionales),1,q);
	id=prof.id;
	
	while(!feof(q)){
	
	
		fread(turn,sizeof(turno),1,p);
		if(turn.IdProfesional==id){
			cant++;
		
		}
	
		while(!feof(p)){
		
			fread(turn,sizeof(turno),1,p);
			if(turn.IdProfesional==id){
				cant++;
			
			}
		}
	
		printf("\nProfesional %d: %d pacientes atendidos\n",id,cant);
		
		rewind(p);
		cant=0;
		
		fread(prof,sizeof(profesionales),1,q);
		id=prof.id;
	
	}
}

void rankingProf(FILE *p,FILE *q){
	
	rank profeNum[100],aux_reg;
	int cant=0,i=0;
	int n,b=1;
	profesionales prof;	
	turno turn;
	
	fread(prof,sizeof(profesionales),1,q);

	while(!feof(q)){
		
		profeNum[i].id=prof.id;
		strcpy(profeNum[i].name,prof.apenom);
		
		fread(turn,sizeof(turno),1,p);
		if(turn.IdProfesional==prof.id){
			cant++;
		}
		
		while(!feof(p)){
			
			fread(turn,sizeof(turno),1,p);
			if(turn.IdProfesional==prof.id){
				cant++;
			}	
		}
		
		profeNum[i].cant=cant;
		
		i++;
		cant=0;
		rewind(p);
		
		fread(prof,sizeof(profesionales),1,q);
		
	}
	
	n=i;
	
	//ordenar el array de registro
	
	while(b!=0){
		b=0;
		
		for(int i=0;i<n-1;i++){
			if(profeNum[i].cant<profeNum[i+1]){
				aux_reg=profeNum[i];
				profeNum[i]=profeNum[i+1];
				profeNum[i+1]=profeNum[i];
				b=1;
			}	
		}	
	}
	
	//imprime array en pantalla
	printf("\nRanking:\n\t");
	for(int j=0;j<n;j++){
		printf("%d.Nombre y apellido: %s\n\tID: %d\n\tCantidad de pacientes atendidos: %d\n",j,profeNum[j].name,profeNum[j].id,profeNum[j].cant);
		
	}
	
}

