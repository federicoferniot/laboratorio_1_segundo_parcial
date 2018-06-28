#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidNombre(char* str);
static int isValidHoras(int horas);

Empleado* empleado_new(void)
{
    Empleado* auxEmpleado = (Empleado*) malloc(sizeof(Empleado));
    return auxEmpleado;
}

Empleado* empleado_newParametros(char* strId, char* nombre, char* strHorasTrabajadas)
{
    int id, horasTrabajadas;
    Empleado* this;
    id = atoi(strId);
    horasTrabajadas = atoi(strHorasTrabajadas);
    this = empleado_new();
    if(!empleado_setId(this, id) &&
       !empleado_setNombre(this, nombre) &&
       !empleado_setHorasTrabajadas(this, horasTrabajadas))
    {
        return this;
    }
    empleado_delete(this);
    return NULL;
}

int empleado_setId(Empleado* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
    if(this != NULL && id == -1)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    else if(this != NULL && id > ultimoId)
    {
        retorno = 0;
        ultimoId = id;
        this->id = ultimoId;
    }
    return retorno;
}

void empleado_delete(Empleado* this)
{
    if(this != NULL)
        free(this);
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int empleado_setHorasTrabajadas(Empleado* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && isValidHoras(horasTrabajadas))
    {
        retorno = 0;
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}

int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}

int empleado_getId(Empleado* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int empleado_getHorasTrabajadas(Empleado* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        retorno = 0;
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}

static int isValidNombre(char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

static int isValidHoras(int horas)
{
    if(horas>=0)
        return 1;
    return 0;
}

int em_trabajaMasDe120Horas(void* item)
{
    int retorno = 0;
    int horas;
    empleado_getHorasTrabajadas(item, &horas);
    if(horas > 120)
        retorno = 1;
    return retorno;
}
