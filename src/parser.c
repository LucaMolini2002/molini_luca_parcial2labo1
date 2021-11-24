#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "Editorial.h"
#include "parser.h"
#include "controller.h"

/** \brief Parsea los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param listLibros LinkedList*
 *
 * \return int retorna la cant de libros que se cargaron
 */
int parser_LibroFromText(FILE *pFile, LinkedList *listLibros)
{
	int retorno=-1;
	eLibro* pAuxLibro;
	char idStr[128],titulo[128],autor[128],precioStr[128],editorialIdStr[128];
	int id;
	int precio;
	int editorialId;
	int idMax=0;

	if(pFile !=NULL)
	{
		do
		{

			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", idStr, titulo, autor, precioStr, editorialIdStr)==5){
				id=atoi(idStr);
				precio=atoi(precioStr);
				if(id>idMax)
				{
					idMax=id;
				}
			}
			else
			{
				break;
			}
			editorial_insertarIdByEditorial(editorialIdStr);
			editorialId = atoi(editorialIdStr);
			pAuxLibro=libro_newParametros(id,titulo,autor,precio,editorialId);
			if(pAuxLibro!=NULL)
			{
				ll_add(listLibros, pAuxLibro);
			}
		}while(!feof(pFile));
			retorno = idMax;
	}
	return retorno;
}

