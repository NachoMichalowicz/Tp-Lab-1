#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

void printMenu();


int main()
{
    int option = 0;
    int cantidadEmpleados;
    int controlError;
    int idActual = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

        printMenu();
        printf("\nIngrese una opcion: ");
        scanf("%d", &option);
        fflush(stdin);

        cantidadEmpleados = ll_len(listaEmpleados);
        switch(option)
        {
            case 1:
                if (cantidadEmpleados == 0)
                {
                    controller_loadFromText("data.csv", listaEmpleados);
                    idActual = ll_len(listaEmpleados) + 1;
                }
                else
                {
                    printf("\nERROR. Ya hay empleados cargados!");
                }
                break;

            case 2:
                if (cantidadEmpleados == 0)
                {
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    idActual = ll_len(listaEmpleados) + 1;
                }
                else
                {
                    printf("\nERROR. Ya hay empleados cargados!");
                }
                break;

            case 3:
                if (cantidadEmpleados > 0)
                {
                   controller_addEmployee(listaEmpleados, idActual);
                   idActual++;
                }
                else
                {
                    printf("\nERROR. Primero se deben cargar los empleados!");
                }

                break;

            case 4:
                if (cantidadEmpleados > 0)
                {
                    controlError = controller_editEmployee(listaEmpleados);

                    if (controlError == -1)
                    {
                        printf("\n\nERROR. No se pudo modificar al empleado.");
                    }
                    else
                    {
                        printf("\n\nEmpleado modificado exitosamente!");
                    }
                }
                else
                {
                    printf("\nERROR. Primero se deben cargar los empleados!");
                }
                break;

            case 5:
                if (cantidadEmpleados > 0)
                {
                    controlError = controller_removeEmployee(listaEmpleados);

                    if (controlError == -1)
                    {
                        printf("\n\nERROR. No se pudo dar de baja al empleado.");
                    }
                    else
                    {
                        printf("\n\nEmpleado dado de baja exitosamente!");
                    }
                }
                else
                {
                    printf("\nERROR. Primero se deben cargar los empleados!");
                }
                break;

            case 6:
                controller_ListEmployee(listaEmpleados);
                break;

            case 7:
                if (cantidadEmpleados >  0)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nERROR. Primero se deben cargar los empleados!");
                }
                break;

            case 8:
                controlError = controller_saveAsText("data.csv", listaEmpleados);

                if (controlError == -1)
                {
                    printf("\nERROR. No se pudo guardar el archivo.");
                }
                else
                {
                    printf("\nArchivo guardado exitosamente.");
                }
                break;

            case 9:
                controlError = controller_saveAsBinary("data.bin", listaEmpleados);

                if (controlError == -1)
                {
                    printf("\nERROR. No se pudo guardar el archivo.");
                }
                else
                {
                    printf("\nArchivo guardado exitosamente.");
                }
                break;

            case 10:
                printf("\nSaliendo del programa...");
                break;

            default:
                printf("\nIngrese una opcion valida");
                break;

        }
        printf("\n\n");
        system("pause");

    }while(option != 10);
    return 0;
}

void printMenu()
{
    system("cls");
    printf("  |-----------------------------------Menu-----------------------------------------|");
    printf("\n|1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).    |");
    printf("\n|2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).  |");
    printf("\n|3. Alta de empleado                                                             |");
    printf("\n|4. Modificar datos de empleado                                                  |");
    printf("\n|5. Baja de empleado                                                             |");
    printf("\n|6. Listar empleados                                                             |");
    printf("\n|7. Ordenar empleados                                                            |");
    printf("\n|8. Guardar los datos de los empleados en el archivo data.csv (modo texto).      |");
    printf("\n|9. Guardar los datos de los empleados en el archivo data.bin (modo binario).    |");
    printf("\n|10. Salir                                                                       |");
    printf("\n|--------------------------------------------------------------------------------|");
    printf("\n");
}
