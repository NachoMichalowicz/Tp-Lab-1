#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int getIndex(LinkedList* pArrayListEmployee, int id);

int compare_EmployeesName(void* pEmployee1, void* pEmployee2);
int compare_EmployeesID(void* pEmployee1, void* pEmployee2);
int compare_EmployeesSalario(void* pEmployee1, void* pEmployee2);
int compare_EmployeesHoras(void* pEmployee1, void* pEmployee2);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    f = fopen(path, "r");

    int cant;
    char buffer[3][10];
    Employee* auxEmpleado;

    if (f == NULL)
    {

        return -1;
    }
    else
    {
        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            printf("\n-----------------------");
            if (cant == 4)
            {
                auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(pArrayListEmployee, auxEmpleado);

                printf("\nNombre: %s", auxEmpleado->nombre);
                printf("\nId: %d", auxEmpleado->id);
                printf("\nHoras trabajadas: %d", auxEmpleado->horasTrabajadas);
                printf("\nSueldo: %d", auxEmpleado->sueldo);

            }
            else
            {
                fclose(f);
            }
        }
    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    f = fopen(path, "rb");

    int cant;
    char buffer[3][10];
    Employee* auxEmpleado;

    if (f == NULL)
    {

        return -1;
    }
    else
    {
        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            printf("\n-----------------------");
            if (cant == 4)
            {
                auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(pArrayListEmployee, auxEmpleado);

                printf("\nNombre: %s", auxEmpleado->nombre);
                printf("\nId: %d", auxEmpleado->id);
                printf("\nHoras trabajadas: %d", auxEmpleado->horasTrabajadas);
                printf("\nSueldo: %d", auxEmpleado->sueldo);

            }
            else
            {
                fclose(f);
            }
        }
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{

    Employee* nuevoEmpleado;
    char buffer[3][10];

    int errorControl;

    itoa(id, buffer[3], 10);

    system("cls");
    printf("\n----------Dando de alta a un empleado----------");
    printf("\nIngrese un nombre: ");
    scanf("%s", buffer[0]);

    printf("\nIngrese la cantidad de horas trabajadas: ");
    scanf("%s", buffer[1]);

    printf("\nIngrese el sueldo: ");
    scanf("%s", buffer[2]);

    nuevoEmpleado = employee_newParametros(buffer[3], buffer[0], buffer[1], buffer[2]);
    errorControl = ll_add(pArrayListEmployee, nuevoEmpleado);

    if (errorControl == -1)
    {
        printf("\nERROR. No se pudo agregar dicho empleado.");
    }

    return 0;

}

/** \brief Modificar datos de empleado
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    char buffer[3][10];

    Employee* empleadoActual;

    system("cls");
    printf("\n---------Modificando a un empleado---------");
    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngrese el id del empleado a modificar: ");
    scanf("%s", buffer[0]);
    fflush(stdin);

    id = atoi(buffer[0]);

    index = getIndex(pArrayListEmployee, id);

    empleadoActual = ll_get(pArrayListEmployee, index);

    if (index == -1)
    {
        printf("\nERROR. No existe empleado con dicha id.");

        return -1;
    }
    else
    {
        int errorControl;

        printf("\nIngrese un nuevo nombre (%s): ", empleadoActual->nombre);
        scanf("%s", buffer[1]);
        fflush(stdin);

        printf("\nIngrese la cantidad de horas trabajadas (%d): ", empleadoActual->horasTrabajadas);
        scanf("%s", buffer[2]);
        fflush(stdin);

        printf("\nIngrese el sueldo (%d): ", empleadoActual->sueldo);
        scanf("%s", buffer[3]);
        fflush(stdin);

        Employee* nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
        errorControl = ll_set(pArrayListEmployee, index, nuevoEmpleado);

        if (errorControl == -1)
        {
            return -1;
        }
    }

    return 0;
}

/** \brief Baja de empleado
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    char buffer[3][10];

    Employee* empleadoActual;

    system("cls");
    printf("\n---------Dando de baja a un empleado---------");
    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngrese el id del empleado a eliminar: ");
    scanf("%s", buffer[0]);
    fflush(stdin);

    id = atoi(buffer[0]);

    index = getIndex(pArrayListEmployee, id);

    if (index != -1)
    {
        empleadoActual = ll_get(pArrayListEmployee, index);

        int errorControl;
        errorControl = ll_remove(pArrayListEmployee, index);

        if (errorControl == -1)
        {
            return -1;
        }

        return 0;
    }
    else
    {
        printf("\nERROR. No existe empleado con dicha id.");
        return -1;
    }

}

/** \brief Listar empleados
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int lenList = ll_len(pArrayListEmployee);

    system("cls");
    printf("\n--------Listado de empleados--------");

    for (int i = 0; i < lenList; i++)
    {
        Employee* employeeActual;
        employeeActual = ll_get(pArrayListEmployee, i);

        if (employeeActual->id != 0)
        {
            printf("\nNombre: %s", employeeActual->nombre);
            printf("\nId: %d", employeeActual->id);
            printf("\nHoras trabajadas: %d", employeeActual->horasTrabajadas);
            printf("\nSueldo: %d", employeeActual->sueldo);
            printf("\n--------------------------------------");
        }
    }

    printf("\n");
    return 1;
}


/** \brief Ordenar empleados
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;

    system("cls");
    printf("  |----------------Ordenamiento de empleados----------------|");
    printf("\n|Para ordenar por ID ingrese 1                            |");
    printf("\n|Para ordenar por sueldo ingrese 2                        |");
    printf("\n|Para ordenar por nombre ingrese 3                        |");
    printf("\n|Para ordenar por cantidad de horas trabajadas ingrese 4  |");
    printf("\n|Para volver al menu principal ingrese cualquier caracter |");
    printf("\n|---------------------------------------------------------|");

    printf("\n\nIngrese una opcion: ");
    scanf("%d", &opcion);
    fflush(stdin);

    if (opcion < 1 || opcion > 4)
    {
        return 1;
    }
    else
    {
        int orden;
        printf("\nPara ordenarlos de manera ascendente ingrese 0");
        printf("\nPara ordenarlos de manera descendente ingrese 1");
        printf("\nIngrese una opcion: ");

        scanf("%d", &orden);
        fflush(stdin);

        while (orden > 1 || orden < 0)
        {
            printf("\nERROR. Ingrese una opcion valida");
            printf("\nIngrese una opcion: ");

            scanf("%d", &orden);
            fflush(stdin);
        }

        printf("\n----------------------------------------------------------");
        printf("\nRealizando el ordenamiento... (esto puede tomar un tiempo)");
        switch(opcion)
        {
            case 1:
                ll_sort(pArrayListEmployee, compare_EmployeesID, orden);
                break;

            case 2:
                ll_sort(pArrayListEmployee, compare_EmployeesSalario, orden);
                break;

            case 3:
                ll_sort(pArrayListEmployee, compare_EmployeesName, orden);
                break;

            case 4:
                ll_sort(pArrayListEmployee, compare_EmployeesHoras, orden);
                break;
        }
    }

    return 1;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path, "w");
    Employee* empleadoActual;
    int lenList = ll_len(pArrayListEmployee);

    if (f == NULL)
    {
        printf("\nERROR. No se pudo escribir el archivo.");
        return -1;
    }
    else
    {
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");

        for (int i = 0; i < lenList; i++)
        {
            empleadoActual = ll_get(pArrayListEmployee, i);
            fprintf(f,"%d,%s,%d,%d\n", empleadoActual->id, empleadoActual->nombre, empleadoActual->horasTrabajadas, empleadoActual->sueldo);
        }
        fclose(f);

    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path, "wb");
    Employee* empleadoActual;
    int lenList = ll_len(pArrayListEmployee);

    if (f == NULL)
    {
        printf("\nERROR. No se pudo escribir el archivo.");
        return -1;
    }
    else
    {
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
        for (int i = 0; i < lenList; i++)
        {
            empleadoActual = ll_get(pArrayListEmployee, i);
            fprintf(f,"%d,%s,%d,%d\n", empleadoActual->id, empleadoActual->nombre, empleadoActual->horasTrabajadas, empleadoActual->sueldo);
        }
        fclose(f);

    }

    return 1;
}


int getIndex(LinkedList* pArrayListEmployee, int id)
{
    int listLen = ll_len(pArrayListEmployee);

    for (int i = 0; i < listLen; i++)
    {
        Employee* empleadoActual = ll_get(pArrayListEmployee, i);

        if (empleadoActual->id == id)
        {
            if (empleadoActual == NULL)
            {
                return -1;
            }
            else
            {
                return i;
            }

        }
    }
    return -1;
}

int compare_EmployeesName(void* pEmployee1, void* pEmployee2)
{
    char primerCaracterEmp1 = ((Employee*) pEmployee1)->nombre[0];
    char primerCaracterEmp2 = ((Employee*) pEmployee2)->nombre[0];

    if (primerCaracterEmp1 > primerCaracterEmp2)
    {
        return 1;
    }
    else
    {
        if (primerCaracterEmp1 < primerCaracterEmp2)
        {
             return -1;
        }
        else
        {
            char segundoCaracterEmp1 = ((Employee*) pEmployee1)->nombre[1];
            char segundoCaracterEmp2 = ((Employee*) pEmployee2)->nombre[1];

            if (segundoCaracterEmp1 > segundoCaracterEmp2)
            {
                return 1;
            }
            else
            {
                if (segundoCaracterEmp1 < segundoCaracterEmp2)
                {
                    return -1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}

int compare_EmployeesID(void* pEmployee1, void* pEmployee2)
{
    int id1 = ((Employee*) pEmployee1)->id;
    int id2 = ((Employee*) pEmployee2)->id;

    if (id1 > id2)
    {
        return 1;
    }
    else
    {
        if (id1 < id2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int compare_EmployeesSalario(void* pEmployee1, void* pEmployee2)
{
    int salario1 = ((Employee*) pEmployee1)->sueldo;
    int salario2 = ((Employee*) pEmployee2)->sueldo;

    if (salario1 > salario2)
    {
        return 1;
    }
    else
    {
        if (salario1 < salario2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int compare_EmployeesHoras(void* pEmployee1, void* pEmployee2)
{
    int horas1 = ((Employee*) pEmployee1)->horasTrabajadas;
    int horas2 = ((Employee*) pEmployee2)->horasTrabajadas;

    if (horas1 > horas2)
    {
        return 1;
    }
    else
    {
        if (horas1 < horas2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}
