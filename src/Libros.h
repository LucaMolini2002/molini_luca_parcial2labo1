/*
 * Libros.h
 *
 *  Created on: 22 nov. 2021
 *      Author: Luk
 */

#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct{
	int id;
	char titulo[128];
	char autor[50];
	int precio;
	int editorialId;
}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(int id,char* titulo,char* autor,int precio,int editorialId);
int libro_delete(eLibro* this);
void libro_mostrar(eLibro *this);

int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char* titulo);

int libro_setAutor(eLibro* this,char* autor);
int libro_getAutor(eLibro* this,char* autor);

int libro_setPrecio(eLibro* this,int precio);
int libro_getPrecio(eLibro* this,int* precio);

int libro_setEditorialId(eLibro* this,int editorialId);
int libro_getEditorialId(eLibro* this,int* editorialId);

int libro_SortByAuthor(void *libro1, void *libro2);
int libro_DiscountsPlaneta(void *libro);
int libro_DiscountsSigloXXIE(void *libro);
#endif /* LIBROS_H_ */
