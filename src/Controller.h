#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Editorial.h"
#include "Parser.h"
#include "Libros.h"

int controller_LoadFromText(char *path, LinkedList *listBooks);
int controller_SortBook(LinkedList *listBooks);
int controller_ListBook(LinkedList *listBooks);
int controller_Discounts(LinkedList *listBooks);
int controller_SaveAsText(LinkedList *listBooks);

#endif /* CONTROLLER_H_ */
