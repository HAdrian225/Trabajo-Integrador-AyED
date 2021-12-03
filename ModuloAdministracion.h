
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
