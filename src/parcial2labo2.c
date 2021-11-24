/*
 ============================================================================
 Name        : parcial2labo2.c
 Author      : Luca
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Editorial.h"
#include "utn.h"
#include "Libros.h"

int main(void)
{
	setbuf(stdout, NULL);
	LinkedList *listLibros;
	int opcion;

	listLibros = ll_newLinkedList();
	do
	{
		editorial_mostrarMenu();
		utn_getNumero(&opcion, "\nIngrese una opcion", "Error,ingrese una opcion valida", 1, 6, 3);
		switch(opcion)
		{
			case 1:
				if(controller_LoadFromText("Datos.csv", listLibros) > 0)
				{
					printf("Se cargaron los datos con exito");
				}
				else
				{
					printf("Se produjo un error cargando los datos");

				}
				break;

			case 2:
				if(!ll_isEmpty(listLibros))
				{
					if(controller_SortBook(listLibros) == -1)
					{
						printf("Error, la lista esta vacia");
					}
				}
				else
				{
					printf("Error, no hay libros en el sistema");
				}
				break;

			case 3:
				if(!ll_isEmpty(listLibros))
				{
					if(controller_ListBook(listLibros) == -1)
					{
						printf("Error, la lista esta vacia");
					}
				}
				else
				{
					printf("Error, no hay libros en el sistema");
				}
				break;

			case 4:
				if(!ll_isEmpty(listLibros))
				{
					if(controller_Discounts(listLibros) == 0)
					{
						printf("Descuento aplicado con exito");

					}
					else
					{
						printf("Error, la lista esta vacia");
					}
				}
				else
				{
					printf("Error, no hay libros en el sistema");
				}
				break;

			case 5:
				if(!ll_isEmpty(listLibros))
				{
					if(controller_SaveAsText(listLibros) == 0)
					{
						printf("\nGuardado exitosamente!");

					}
					else
					{
						printf("\nError guardando el archivo");
					}
				}
				else
				{
					printf("\nError, no hay libros en el sistema");
				}
				break;

			case 6:
				ll_deleteLinkedList(listLibros);
				break;
		}
	}while(opcion != 6);
}
