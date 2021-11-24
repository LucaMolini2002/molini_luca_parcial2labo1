#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libros.h"
#include "Editorial.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief Busca espacio en memoria para una estructura de e inicializa los valores de la misma
 *
 * \return eLibro* Retorna un puntero a eLibro
 *
 */
eLibro* libro_new()
{
	eLibro *nuevoLibro;
	return (eLibro*) malloc(sizeof(eLibro));
	if (nuevoLibro != NULL)
	{
		nuevoLibro->id = 0;
		strcmp(nuevoLibro->titulo, "\0");
		strcmp(nuevoLibro->autor, "\0");
		nuevoLibro->precio = 0;
		nuevoLibro->editorialId = 0;
	}
	return nuevoLibro;
}

/** \brief Carga los valores que se le pasan por parametro a una nueva estructura de libro
 *
 * \param id int Direccion de memoria del id
 * \param titulo char* Direccion de memoria del titulo
 * \param autor char* Direccion de memoria del autor
 * \param precio int Direccion de memoria del precio
 * \param editorialId int Direccion de memoria de editorialId
 * \return eLibro* Retorna un puntero a eLibro
 *
 */
eLibro* libro_newParametros(int id,char* titulo,char* autor,int precio,int editorialId)
{
	eLibro* auxLibro= libro_new();
	if(auxLibro!=NULL)
	{
		if( libro_setId(auxLibro, id)<0 ||
			libro_setTitulo(auxLibro, titulo) <0 ||
			libro_setAutor(auxLibro, autor) <0 ||
			libro_setPrecio(auxLibro, precio) <0 ||
			libro_setEditorialId(auxLibro, editorialId) <0)
		{
			libro_delete(auxLibro);
			auxLibro=NULL;
		}
	}
	return auxLibro;
}

/**
 * \brief elimina un libro
 *
 * \param this libro a eliminar
 * \return -1 si el puntero es NULL o 0 si se elimino con exito
 */
int libro_delete(eLibro* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief mustra un libro
 *
 * \param this libro a imprimir
 */
void libro_mostrar(eLibro *this)
{
	int id;
	char titulo[128];
	char autor[128];
	char editorialId[128];
	int precio;

	if(this != NULL)
	{
		libro_getId(this, &id);
		libro_getTitulo(this, titulo);
		libro_getAutor(this, autor);
		libro_getPrecio(this, &precio);
		editorial_editorialById(this, editorialId);
		printf("\n%2d %50s %20s %10d %20s", id, titulo, autor, precio, editorialId);
	}
}

/** \brief Carga en la estructura  de libro el id que se le pasa por parametro
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param id int valor del id
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_setId(eLibro* this,int id)
{
    int retorno = -1;
    if(this != NULL && id > 0 && id <= 2000)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param id int* Direccion de memoria del id
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_getId(eLibro* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


/** \brief Carga en la estructura  de empleado el nombre que se le pasa por parametro
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param titulo char* Direccion de memoria del titulo
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_setTitulo(eLibro* this,char* titulo)
{
    int todoOk = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo, titulo);
        todoOk = 0;
    }
    return todoOk;
}


/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param titulo char* Direccion de memoria del titulo
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_getTitulo(eLibro* this,char* titulo)
{
    int todoOk = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk = 0;
    }
    return todoOk;
}


/** \brief Carga en la estructura  de empleado las horas trabajadas que se le pasa por parametro
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param autor char* Valor del autor
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_setAutor(eLibro* this,char* autor)
{
    int retorno = -1;
    if(this != NULL && autor >= 0)
    {
    	strcpy(this->autor, autor);
        retorno = 0;
    }
    return retorno;
}


/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param autor char* Direccion de memoria del autor
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_getAutor(eLibro* this,char* autor)
{
    int retorno = -1;
    if(this != NULL && autor != NULL)
    {
    	strcpy(autor, this->autor);
        retorno = 0;
    }
    return retorno;
}


/** \brief Carga en la estructura  de empleado el sueldo que se le pasa por parametro
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param precio int Valor del precio
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_setPrecio(eLibro* this,int precio)
{
    int retorno = -1;
    if(this != NULL && precio >= 0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param precio int* Direccion de memoria del precio
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_getPrecio(eLibro* this,int* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}

/** \brief Carga en la estructura  de empleado el sueldo que se le pasa por parametro
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param editorialId int Valor del editorialId
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_setEditorialId(eLibro* this,int editorialId)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->editorialId = editorialId;
        retorno = 0;
    }
    return retorno;
}

/** \brief Carga en el lugar donde apunta la direccion de memoria que se le pasa el valor de la estructura
 *
 * \param this eLibro* Direccion de memoria de la estructura
 * \param editorialId int* Direccion de memoria del editorialId
 * \return int Retorna 0 si se cargo el valor y -1 si no
 *
 */
int libro_getEditorialId(eLibro* this,int* editorialId)
{
    int retorno = -1;
    if(this != NULL)
    {
        *editorialId = this->editorialId;
        retorno = 0;
    }
    return retorno;
}

/**
 * \brief Compara el autor de los elementos tipo eBook
 *
 * \param bookA Libro 1 | void*
 * \param bookB Libro 2 | void*
 * \return resp [0] si ambos son iguales, [1] si el primero es mayor al segundo y [-1] si el primero es menor al segundo
 */
int libro_SortByAuthor(void *libro1, void *libro2)
{
	int ret;
	char autor1[128];
	char autor2[128];
	eLibro *aux1;
	eLibro *aux2;

	aux1 = (eLibro*) libro1;
	aux2 = (eLibro*) libro2;

	ret = 0;
	if(aux1 != NULL && aux2 != NULL)
	{
		libro_getAutor(aux1, autor1);
		libro_getAutor(aux2, autor2);

		if(strcasecmp(autor1, autor2) < 0)
		{
			ret = 1;
		}
		else
		{
			if (strcasecmp(autor1, autor2) > 0)
			{
				ret = -1;
			}
		}
	}
	return ret;
}

/**
 * \brief aplica descuentos a libros con la editorial PLANETA
 *
 * \param libro, void*
 * \return -1 si el puntero es NULL o 0 si funciono correctamente
 */
int libro_DiscountsPlaneta(void *libro)
{
	int ret;
	char nombreEditorial[128];
	eLibro *auxLibro;
	int precio;

	auxLibro = (eLibro*) libro;
	ret = -1;
	if (auxLibro != NULL)
	{
		editorial_editorialById(auxLibro, nombreEditorial);
		if (strcasecmp(nombreEditorial, "PLANETA") == 0)
		{
			libro_getPrecio(auxLibro, &precio);
			if (precio >= 300)
			{
				libro_setPrecio(auxLibro, precio - (0.20 * precio));
				ret = 0;
			}
		}
	}
	return ret;
}

/**
 * @brief aplica descuentos a libros con la editorial Siglo XXIE
 *
 * @param libro, void*
 * @return -1 si el puntero es NULL o 0 si funciono correctamente
 */
int libro_DiscountsSigloXXIE(void *libro)
{
	int ret;
	char editorialName[128];
	eLibro *auxLibro;
	int precio;

	auxLibro = (eLibro*) libro;
	ret = -1;
	if(auxLibro != NULL)
	{
		editorial_editorialById(auxLibro, editorialName);

		if(strcasecmp(editorialName, "SIGLO XXI EDITORES") == 0)
		{
			libro_getPrecio(auxLibro, &precio);
			if(precio <= 200)
			{
				libro_setPrecio(auxLibro, precio - (0.10 * precio));
			}
		}
		ret = 0;
	}
	return ret;
}
