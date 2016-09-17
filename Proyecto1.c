#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct contacto
{
	char nombre[30];
	int telefono;
} CONTACTO;

void NewContact()
{
	CONTACTO new;

	printf("\nIntroduzca los datos del nuevo contacto: \n\t");
	scanf("%s %d", new.nombre, &new.telefono);

	printf("\n\tNuevo contacto: %s %d", new.nombre, new.telefono);
	printf("\n\n\tContacto guardado con éxito\n\n");

	FILE *agenda;

	agenda=fopen("agenda.txt","r+");

	fseek(agenda, 0, SEEK_END);

	fprintf(agenda, "\n%s\t\t\t%d", new.nombre, new.telefono);

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
	printf("\n\n");
}

void DelContact()
{
	int l, linea, NUMlineas=0;
	char LINEA[MAX], c, ch;
	FILE *destino, *agenda;
	
	printf("\n Lista actual de contactos: \n");
	LoadContacts();
	
	printf("Introduzca el no. de contacto a eliminar: ");
	scanf("%d", &l);

	linea=l+3;

	agenda=fopen("agenda.txt", "r+");
	destino=fopen("tmp.txt", "w+"); //se crea archivo temporal

	//se leen todas las lineas de agenda.tx
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

	printf("\n\n Contacto eliminado con éxito\n\n");
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
		fprintf(agenda, "\nNOMBRE\t\t\tTELÉFONO");
		fclose(agenda);
	}

	printf("\n\n\nBIENVENIDO A TU AGENDA PERSONAL\n");
	printf("\t1.Nuevo Contacto\n\t2.Ver Contactos\n\t3.Borrar Contacto\n\t4.Salir\n\nOpción: ");
	scanf("%d", &op);

		switch(op)
		{
			case 1:
				NewContact();
				break;

			case 2:
				LoadContacts();
				break;

			case 3:
				DelContact();
				break;

			case 4:
				break;

			default:
				printf("Opción no válida\n\n");
		}

	return 0;
}