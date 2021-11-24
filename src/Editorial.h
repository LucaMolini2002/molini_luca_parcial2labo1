/*
 * Editorial.h
 *
 *  Created on: 22 nov. 2021
 *      Author: Luk
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Libros.h"

int editorial_SaveAsText(FILE *pFile, LinkedList *listBooks);
int editorial_editorialById(eLibro *book, char *nameEditorial);
int editorial_mostrarLibro(LinkedList *listBooks);
int editorial_insertarIdByEditorial(char *name);
void editorial_mostrarMenu(void);

#endif /* EDITORIAL_H_ */
