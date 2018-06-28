#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleado.h"


int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno =0;
    char id[4000];
    char nombre[4000];
    char horasTrabajadas[4000];
    Empleado* auxEmpleado;
    FILE* pFile;
    pFile = fopen(fileName, "r");
    if(pFile != NULL)
    {
        retorno =1;
        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas);
            auxEmpleado = empleado_newParametros(id, nombre, horasTrabajadas);
            al_add(listaEmpleados, auxEmpleado);
        }
        fclose(pFile);
    }

    return retorno; //[1] OK
}

int parser_guardarEmpleado(char* fileName , ArrayList* listaEmpleados)
{
    int retorno =0;
    int id, horasTrabajadas;
    char nombre[4000];

    Empleado* this;
    int i;
    FILE* pFile;
    pFile = fopen(fileName, "w");
    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,horas_trabajadas\n");
        for(i=0; i<al_len(listaEmpleados);i++)
        {
            retorno = 1;
            this = al_get(listaEmpleados, i);
            empleado_getId(this,&id);
            empleado_getNombre(this,nombre);
            empleado_getHorasTrabajadas(this, &horasTrabajadas);
            fprintf(pFile, "%d,%s,%d\n", id, nombre, horasTrabajadas);
        }
        fclose(pFile);
    }
    return retorno;
}


