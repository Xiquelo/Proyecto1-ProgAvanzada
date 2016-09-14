#include <stdio.h>
#include <stlib.h>
#include <conio.h>
#include <string.h>

typedef struct contacto
{
	char nombre[30]
	int telefono[10]
} CONTACTO;

void NewContact()
{
	CONTACTO new;
	char select s, n;

	printf("\n\t Introduzca los datos del nuevo contacto: \n");
	scanf("%s,%d", &new.nombre, &new.telefono);

	printf("\n Se ha ingresado el contacto con el nombre: %s", new.nombre);
	printf("\n Con el no. de teléfono: %d", new.telefono);
	printf("\n ¿Desea guardar este nuevo contacto? S/N");

	if(select = s)
		FILE *agenda;
		agenda=fopen ("agenda.txt", "r+");
		fseek (pf, 0, SEEK_END);
		fprintf(agenda, "\n%s\t\t%d", new.nombre, new.telefono);
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
	int 1, linea, NUMlineas=0;
	char LINEA[MAX], c, ch;
	FILE *destino, *agenda;
	
	printf("\n Lista actual de contactos: \n");
	LoadContacts();
	printf("Introduzca el no. de contacto a eliminar: ");
	scanf("%d", &1);

	linea=1+3;

	agenda=fopen("agenda.txt", "r+");
	destino=fopen("age")
}