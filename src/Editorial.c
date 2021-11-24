#include "Editorial.h"
#include "Controller.h"
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Libros.h"

/**
 *\brief guarda la infor de la linkedList en un file
 *
 * \param *pFile puntero a file
 * \param *listLibros puntero a la lista
 * \return return 0 si funciona bien y -1 sin hay error
 */
int editorial_SaveAsText(FILE *pFile, LinkedList *listLibros)
{
	eLibro *libro;
	int ret;
	int i;
	int lenList;
	int id;
	char titulo[128];
	char autor[128];
	char editorialId[128];
	int precio;

	libro = NULL;
	ret = -1;
	if(pFile != NULL && listLibros != NULL)
	{
		lenList = ll_len(listLibros);
		fprintf(pFile, "id,titulo,autor,precio,editorialId\n");

		for(i = 0; i < lenList; i++)
		{
			libro = (eLibro*) ll_get(listLibros, i);

			libro_getId(libro, &id);
			libro_getTitulo(libro, titulo);
			libro_getAutor(libro, autor);
			libro_getPrecio(libro, &precio);
			editorial_editorialById(libro, editorialId);
			fprintf(pFile, "%d,%s,%s,%d,%s\n", id, titulo, autor, precio, editorialId);
			editorial_mostrarLibro(listLibros);
		}
		ret = 0;
	}
	return ret;
}

/**
 * \brief convierte el id de la editorial en el nombre de esta
 *
 * \param libro puntero a libro
 * \param nombreEditorial nombre de la editorial
 * \return return 0 si funciona bien y -1 sin hay error
 */
int editorial_editorialById(eLibro *libro, char *nombreEditorial)
{
	int ret;
	int editorialId;

	ret = -1;
	if(libro != NULL)
	{
		libro_getEditorialId(libro, &editorialId);
		switch(editorialId)
		{
			case 1:
				strcpy(nombreEditorial, "PLANETA");
				break;

			case 2:
				strcpy(nombreEditorial, "SIGLO XXI EDITORES");
				break;

			case 3:
				strcpy(nombreEditorial, "PEARSON");
				break;

			case 4:
				strcpy(nombreEditorial, "MINOTAURO");
				break;

			case 5:
				strcpy(nombreEditorial, "SALAMANDRA");
				break;

			case 6:
				strcpy(nombreEditorial, "PENGUIN BOOKS");
				break;

			default:
				strcpy(nombreEditorial, "...");
				break;
		}
	}
	ret = 0;

	return ret;
}

/**
 * \brief muestra la lista de libros
 *
 * \param listLibros, puntero a la lista
 * \return return 0 si funciona bien y -1 sin hay error
 */
int editorial_mostrarLibro(LinkedList *listLibros)
{
	int ret;
	int i;
	int sizeList;
	eLibro *libro;

	ret = -1;
	if (listLibros != NULL)
	{
		sizeList = ll_len(listLibros);
		printf("ID                             TITULO                               AUTOR       PRECIO          EDITORIAL");
		for (i = 0; i < sizeList; i++)
		{
			libro = ll_get(listLibros, i);
			libro_mostrar(libro);
		}
		ret = 0;
	}

	return ret;
}

/**
 * \brief convierte el nombre de la editorial a su id correspondiente
 *
 * \param editorial nombre
 * \return return 0 si funciona bien y -1 sin hay error
 */
int editorial_insertarIdByEditorial(char *nombre)
{
	int ret;

	ret = -1;
	if (nombre != NULL)
	{
		if (strcasecmp(nombre, "PLANETA") == 0)
		{
			strcpy(nombre, "1");
		}
		else
		{
			if (strcasecmp(nombre, "SIGLO XXI EDITORES") == 0)
			{
				strcpy(nombre, "2");
			}
			else
			{
				if (strcasecmp(nombre, "PEARSON") == 0)
				{
					strcpy(nombre, "3");
				}
				else
				{
					if (strcasecmp(nombre, "MINOTAURO") == 0)
					{
						strcpy(nombre, "4");
					}
					else
					{
						if (strcasecmp(nombre, "SALAMANDRA") == 0)
						{
							strcpy(nombre, "5");
						}
						else
						{
							if (strcasecmp(nombre, "PENGUIN BOOKS") == 0)
							{
								strcpy(nombre, "6");
							}
							else
							{
								strcpy(nombre, "0");
							}
						}
					}
				}
			}
		}
		ret = 0;
	}
	return ret;
}

/**
 * \brief muestra menu de opciones
 *
 */
void editorial_mostrarMenu(void)
{
	printf("\n------------------ MENU ------------------");
	printf("\n1. Cargar libros al sistema");
	printf("\n2. Ordenar libros");
	printf("\n3. Listar libros");
	printf("\n4. Aplicar descuentos");
	printf("\n5. Guardar libros en el sistema");
	printf("\n6. Salir");
}
