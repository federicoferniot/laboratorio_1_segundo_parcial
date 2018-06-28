#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "ArrayList.h"

/** \brief  Carga el array con elementos dentro del archivo
 * \param fileName nombre del archivo del cual va a ser leido
 * \param listaEmpleados Array donde van a ser cargados los elementos
 * \return int Return (0) if Error [pList is NULL pointer]
 *                  - (1) if Ok
 */
int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados);

/** \brief  Genera un archivo con los elementos dentro del array
 * \param fileName nombre del archivo del cual va a ser leido
 * \param listaEmpleados Array de donde sacar los elementos
 * \return int Return (0) if Error [pList is NULL pointer]
 *                  - (1) if Ok
 */
int parser_guardarEmpleado(char* fileName , ArrayList* listaEmpleados);


#endif // PARSER_H_INCLUDED
