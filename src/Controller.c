/*
 * Controller.c
 *
 *  Created on: 26 jun. 2021
 *      Author: Luk
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "libros.h"
#include "Editorial.h"
#include "controller.h"

/**
 * \brief carga datos de libros en modo texto
 *
 * \param path char*, nombre del archivo
 * \param listLibros LinkedList* puntero a la lista enlazada de libros
 * \return int, 0 si salio bien, -1 si hubo un error
 *
 */
int controller_LoadFromText(char *path, LinkedList *listLibros)
{
	int ret=-1;
	FILE *pFile;

	pFile = fopen(path, "r");
	if(pFile != NULL && listLibros != NULL)
		ret = parser_LibroFromText(pFile, listLibros);

	fclose(pFile);

	return ret;
}

/**
 * \brief ordena la lista de libros
 *
 * \param listLibros LinkedList* puntero a la lista enlazada de libros
 * \return int, 0 si salio bien, -1 si hubo un error
 *
 */
int controller_SortBook(LinkedList *listLibros)
{
	int ret=-1;
	LinkedList *auxListLibros;

	if(listLibros != NULL)
	{
		auxListLibros = ll_clone(listLibros);
		if(ll_sort(auxListLibros, libro_SortByAuthor, 0) == 0)
			ret = controller_ListBook(auxListLibros);

		ll_deleteLinkedList(auxListLibros);
	}
	return ret;
}

/**
 * \brief muestra la lista de libros
 *
 * \param listLibros LinkedList* puntero a la lista enlazada de libros
 * \return int, 0 si salio bien, -1 si hubo un error
 *
 */
int controller_ListBook(LinkedList *listLibros)
{
	int ret;
	ret = -1;
	if(listLibros != NULL)
		ret = editorial_mostrarLibro(listLibros);
	return ret;
}

/**
 * \brief aplica descuentos en la lista de libros
 *
 * \param listLibros LinkedList* puntero a la lista enlazada de libros
 * \return int, 0 si salio bien, -1 si hubo un error
 *
 */
int controller_Discounts(LinkedList *listLibros)
{
	int ret;

	ret = -1;
	if(listLibros != NULL)
	{
		if(ll_map(listLibros, libro_DiscountsPlaneta) == 0 &&
		   ll_map(listLibros, libro_DiscountsSigloXXIE) == 0)
		{
			ret = 0;
		}
	}
	return ret;
}

/**
 * \brief guarda la informacion de los libros en mapeado.csv en modo texto
 *
 * \param path char*, nombre del archivo
 * \param listLibros LinkedList* puntero a la lista enlazada de libros
 * \return int, 0 si salio bien, -1 si hubo un error
 */
int controller_SaveAsText(LinkedList *listLibros)
{
	int ret=-1;
	FILE *pFile;

	pFile = fopen("mapeado.csv", "w");

	if(listLibros != NULL && pFile != NULL)
		ret = editorial_SaveAsText(pFile, listLibros);

	fclose(pFile);
	return ret;
}
