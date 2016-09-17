#include <stdio.h>
#define MAX 100

typedef struct contacto
{
	char nombre[30];
	long int telefono;
} CONTACTO;

void NewContact()
{
	CONTACTO new;

	printf("\nIntroduzca los datos del nuevo contacto: (Nombre,teléfono)\n\t");
	scanf("%s %ld", new.nombre, &new.telefono);

	printf("\n\tNuevo contacto: %s %ld", new.nombre, new.telefono);
	printf("\n\n\tContacto guardado con éxito\n");

	FILE *agenda;

	agenda=fopen("agenda.txt","r+");

	fseek(agenda, 0, SEEK_END);

	fprintf(agenda, "%s\t\t\t%ld\n", new.nombre, new.telefono);

	fclose(agenda);
}

void LoadContacts()
{
	FILE *agenda;
	char c;

	agenda=fopen ("agenda.txt", "r");
	printf("\n");

	while(feof(agenda)==0)
	{
		c=getc(agenda);
		putchar(c);
	}

	putchar('\n');
	fclose(agenda);
}

void DelContact()
{
	int l, linea, NUMlineas=0;
	char LINEA[MAX], c, ch;
	FILE *destino, *agenda;
	
	printf("\n Lista actual de contactos: \n");
	LoadContacts();
	
	printf("Introduzca el número de contacto a eliminar: ");
	scanf("%d", &l);

	linea=l+3;

	agenda=fopen("agenda.txt", "r+");
	destino=fopen("tmp.txt", "w+");

	while(fgets(LINEA, MAX, agenda)!=NULL)
	{
		if ((ch=getc(agenda))!=EOF)
			ungetc(ch, agenda);
			NUMlineas++;
		if (NUMlineas!=linea)
		{
			fputs(LINEA, destino);
		}
	}

	printf("\n\nContacto eliminado con éxito");
	fclose(agenda);
	fclose(destino);
	remove("agenda.txt");
	rename("tmp.txt", "agenda.txt");
}

int main()
{
	int op;
	FILE *agenda;

	agenda=fopen("agenda.txt", "r");

	if (agenda==NULL)
	{
		fclose(agenda);
		agenda=fopen("agenda.txt", "w+");

		fprintf(agenda, "\tAGENDA PERSONAL\n");
		fprintf(agenda, "\nNOMBRE\t\t\tTELÉFONO\n");
		fclose(agenda);
	}

	do
	{
		printf("\n\nBIENVENIDO A TU AGENDA PERSONAL\n");
		printf("\t1.Nuevo Contacto\n\t2.Ver Contactos\n\t3.Borrar Contacto\n\t4.Salir\n\nOpción: ");
		scanf("%d", &op);

			switch(op)
			{
				case 1:
					NewContact();
					getchar();
					getchar();
					break;

				case 2:
					LoadContacts();
					getchar();
					getchar();
					break;

				case 3:
					DelContact();
					getchar();
					getchar();
					break;

				case 4:
					break;

				default:
					printf("Opción no válida");
					getchar();
					getchar();
			}
	}
	while(op!=4);

	return 0;
}