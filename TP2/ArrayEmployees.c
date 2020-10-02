#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    if (len < 1 || list == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }


}

int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{

    Employee addedEmployee;

    addedEmployee.id = id;

    strcpy(addedEmployee.name, name);
    strcpy(addedEmployee.lastName, lastName);

    addedEmployee.salary = salary;
    addedEmployee.sector = sector;
    addedEmployee.isEmpty = 0;

    list[len] = addedEmployee;

    return 1;
}

int findEmployeeById(Employee* list, int len, int id)
{
    for (int i = 0; i < len+1; i++)
    {
        if (list[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int removeEmployee(Employee* list, int len, int id)
{
    Employee empleadoVacio;
    empleadoVacio.isEmpty = 1;
    int idActual = findEmployeeById(list, len, id);

    if (list[idActual].isEmpty)
    {
        return -1;
    }
    else
    {
        list[idActual] = empleadoVacio;
        for (int i = idActual+1; i < len+1; i++)
        {
            list[i-1] = list[i];
        }
        return 0;
    }

}

int sortEmployee(Employee* list, int len, int order)
{
    for (int i = 0; i < len+1; i++)
    {
        for (int j = i; j < len+1; j++)
        {
            int sectorMayor;
            int sectorMenor;
            char primerCaracterApellidoMayor = list[i].lastName[0];
            char primerCaracterApellidoMenor = list[j].lastName[0];

            if (order == 0)
            {
                sectorMayor = list[i].sector;
                sectorMenor = list[j].sector;
            }
            else
            {
                sectorMayor = list[j].sector;
                sectorMenor = list[i].sector;
            }


            if (sectorMayor > sectorMenor) {

                Employee empleadoAux;
                empleadoAux = list[j];
                list[j] = list[i];
                list[i] = empleadoAux;
            }
            else
            {
                if (sectorMayor == sectorMenor)
                {
                    if (primerCaracterApellidoMayor > primerCaracterApellidoMenor)
                    {
                        Employee empleadoAux;
                        empleadoAux = list[j];
                        list[j] = list[i];
                        list[i] = empleadoAux;
                    }
                }
            }
        }
    }

    return 0;
}

int printEmployees(Employee* list, int length)
{
    float sumaSalarios = 0;
    float promedioSalarios;

    int cantidadEmpleadosMayorPromedio = 0;

    if (length < 0)
    {
        return -1;
    }
    else
    {
        printf("\n\n----------- Empleados -----------");

        sortEmployee(list, length, 0);

        for (int i = 0; i < length+1; i++)
        {
            printf("\nNombre del empleado: %s %s", list[i].name, list[i].lastName);
            printf("\nSalario del empleado: %.2f", list[i].salary);
            printf("\nSector del empleado: %d", list[i].sector);
            printf("\nId del empleado: %d\n", list[i].id);

            sumaSalarios += list[i].salary;
        }
        promedioSalarios = sumaSalarios / (length+1);
        printf("\nSuma de salarios: %.2f", sumaSalarios);
        printf("\nPromedio de salarios: %.2f", promedioSalarios);

        for (int i = 0; i < length+1; i++)
        {
            if (list[i].salary > promedioSalarios)
            {
                cantidadEmpleadosMayorPromedio += 1;
            }
        }

        printf("\nCantidad de empleados que superan el salario promedio: %d\n", cantidadEmpleadosMayorPromedio);
        return 0;
    }

}
