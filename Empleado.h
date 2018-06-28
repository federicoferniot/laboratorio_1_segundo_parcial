#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
};
typedef struct S_Empleado Empleado;

Empleado* empleado_new(void);
Empleado* empleado_newParametros(char* strId, char* nombre, char* strHorasTrabajadas);
int empleado_setId(Empleado* this, int id);
void empleado_delete(Empleado* this);
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_setHorasTrabajadas(Empleado* this, int horasTrabajadas);
int empleado_getNombre(Empleado* this, char* nombre);
int empleado_getId(Empleado* this, int* id);
int empleado_getHorasTrabajadas(Empleado* this, int* horasTrabajadas);

int em_trabajaMasDe120Horas(void* item);

#endif // EMPLEADO_H_INCLUDED
