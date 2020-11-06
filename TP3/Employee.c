#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();

    if (nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = atoi(idStr);
        nuevoEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);
        nuevoEmpleado->sueldo = atoi(sueldoStr);
        strcpy(nuevoEmpleado->nombre, nombreStr);
    }
    else
    {
        nuevoEmpleado->id = 0;
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}
