#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayEmployees.h"

#define TAM 51

void ingresoDatos();
void printMenu();
void alta(Employee* employeeList, int* size, int* idUltima);
void modificar(Employee* empleados, int size);
void baja(Employee* employeeList, int* size);
int pedirInt();
float pedirFloat();
void pedirTexto(char *texto [], int length);
int corregirTexto(char *texto[]);

int main()
{
    ingresoDatos();
}


//ingreso de datos genérico
void ingresoDatos()
{
    Employee empleados[1000];
    int opcion = 0;
    int size = -1;
    int idActual = 1000;

    initEmployees(empleados, 1000);

    while (opcion != 5)
    {
        printMenu();

        printf("\n\nIngrese una opcion: ");
        opcion = pedirInt();

        while (opcion > 5 || opcion < 1)
        {
            printf("\n\nERROR. Ingrese una opcion valida: ");
            opcion = pedirInt();
        }

        printf("\n\n");
        switch (opcion)
        {
            case 1:
                alta(empleados, &size, &idActual);
                break;

            case 2:
                modificar(&empleados, size);
                break;

            case 3:
                baja(&empleados, &size);
                break;

            case 4:
                printf("Imprimiendo empleados...");
                int controlError = printEmployees(&empleados, size);

                if (controlError == -1)
                {
                    printf("\nERROR. No hay empleados a mostrar");
                }
                break;

            case 5:
                //por si el usuario ingresó el 5 sin querer, le damos la posiblidad de cambiar su opción
                printf("Seguro que quiere salir? (ingrese '5' de nuevo para confirmar salida, o cualquier otro caracter para continuar)\n");
                opcion = pedirInt();
        }

        printf("\n\n");
        system("pause");
    }
}

//limpia la pantalla e imprime el menú
void printMenu()
{
    system("cls");
    printf("---------------- Opciones ----------------\n\n");
    printf("1: Para dar de alta un nuevo empleado.\n");
    printf("2: Para modificar un empleado existente.\n");
    printf("3: Para dar de baja un empleado.\n");
    printf("4: Para informar el listado actual de los empleados.\n");
    printf("5: Para salir del programa.\n");

}

//da de alta a un empleado y actualiza tanto tamaño del array como id
void alta(Employee* employeeList, int* size, int* idUltima)
{
    char nombre[TAM];
    char apellido[TAM];
    float salario;
    int sector;
    int newSize = *size +1;
    int newId = *idUltima +1;


    //pedimos los datos
    printf("------- Dando de alta a un empleado -------\n\n");
    printf("Nombre del empleado: ");
    pedirTexto(&nombre, TAM);

    printf("\nApellido del empleado: ");
    pedirTexto(&apellido, TAM);

    printf("\nSalario: ");
    salario = pedirFloat();

    printf("\nSector: ");
    sector = pedirInt();

    int controlError = addEmployees(employeeList, newSize, newId, nombre, apellido, salario, sector);

    if (controlError == -1){
        printf("\nERROR. No se ha podido dar de alta al empleado.");
    }
    else
    {
        //se actualiza tanto el tamaño del array como la posición de id
        *size = newSize;
        *idUltima = newId;
    }
}

//para modificar un empleado existente, accediendo mediante un ID
void modificar(Employee* empleados, int size)
{
    int id;
    printf("\n------- MODIFICAR -------\n");
    printf("\nIngrese el id del empleado a modificar: ");
    id = pedirInt();
    int index = findEmployeeById(empleados, size, id);

    if (index == -1)
    {
        printf("\nERROR. No existe un empleado con dicha id");
    }
    else
    {
        Employee empleadoActual;

        int opcion = 0;
        empleadoActual = empleados[index];

        //preguntamos qué quiere modificar
        printf("\n\nUsted esta por modificar la ficha de %s %s\n", empleadoActual.name, empleadoActual.lastName);
        printf ("\n\n Opciones:\n");
        printf("\n1: Modificar nombre (%s)", empleadoActual.name);
        printf("\n2: Modificar apellido (%s)", empleadoActual.lastName);
        printf("\n3: Modificar salario (%.2f)", empleadoActual.salary);
        printf("\n4: Modificar sector (%d)", empleadoActual.sector);
        printf("\n5: Volver al menu principal\n");
        printf("\nIngrese una opcion: ");

        opcion = pedirInt();

        //si la opción es inválida, le preguntará de nuevo en bucle
        while (opcion < 1 || opcion > 5)
        {
            printf("\nERROR. Ingrese una opcion valida: ");
            opcion = pedirInt();
        }

        switch (opcion)
        {
            case 1:
                printf("\nIngrese un nuevo nombre: ");
                char nuevoNombre[TAM];
                pedirTexto(&nuevoNombre, TAM);

                strcpy(empleadoActual.name, nuevoNombre);
                break;

            case 2:
                printf("\nIngrese un nuevo apellido: ");
                char nuevoApellido[TAM];
                pedirTexto(&nuevoApellido, TAM);

                strcpy(empleadoActual.lastName, nuevoApellido);
                break;

            case 3:
                printf("\nIngrese un nuevo salario: ");
                float nuevoSalario;
                nuevoSalario = pedirFloat();

                empleadoActual.salary = nuevoSalario;
                break;

            case 4:
                printf("\nIngrese un nuevo sector: ");
                int nuevoSector;
                nuevoSector = pedirInt();
                empleadoActual.sector = nuevoSector;
                break;
        }
        empleados[index] = empleadoActual;
    }
}

//para dar de baja a un empleado
void baja(Employee* employeeList, int* size)
{
    int newSize = *size -1;

    printf("Ingrese el id del empleado a dar de baja: ");
    int id = pedirInt();

    int controlErrores = removeEmployee(employeeList, *size, id);

    //se reajusta el tamaño si la operación fue efectiva
    if (controlErrores == -1)
    {
        printf("\nERROR. No existe un empleado con dicho id");
    }
    else
    {
        printf("\nEmpleado removido exitosamente!");
        *size = newSize;
    }
}

//pide un número de tipo entero y limpia el buffer. En caso de recibir un número menor a 0 o una cadena de textos, vuelve a pedir el número.
int pedirInt()
{
    int num;
    char input[TAM];

    scanf("%s", &input);
    fflush(stdin);
    num = atoi(input);

    while (num < 1)
    {
        printf("\nERROR. Ingrese unicamente un numero distinto a 0.");
        printf("\nNumero: ");
        scanf("%s", &input);
        fflush(stdin);
        num = atoi(input);
    }

    return num;
}

//pide un número de tipo float positivo y limpia el buffer. En caso de recibir un número menor a 0 o una cadena de textos, vuelve a pedir el número.
float pedirFloat()
{
    float num;
    char input[TAM];

    scanf("%s", &input);
    fflush(stdin);
    num = atof(input);

    while(num < 0.1)
    {
        printf("\nERROR. No puede ser un numero negativo ni una cadena de texto.");
        printf("\nIngrese otro valor: ");
        scanf("%f", &num);
        fflush(stdin);
    }

    return num;
}

//pide un texto, corrige en caso de errores, limpia el buffer y lo asigna a un puntero
void pedirTexto(char *texto [], int length)
{
    scanf("%s", texto);
    fflush(stdin);
    int controlError = corregirTexto(texto);

    while (controlError == -1)
    {
        printf("\nERROR. No puede contener numeros.");
        printf("\nIngrese otro texto: ");
        scanf("%s", texto);
        fflush(stdin);
        controlError = corregirTexto(texto);
    }
}

//Corrige las mayúsculas y minúsculas de un texto . Ej:
//Input: rOdRiGo
//Output: Rodrigo
//return devuelve -1 si hay un número en la cadena de caracteres y 0 en caso de que esté limpia

int corregirTexto(char *texto[])
{
    char textoCorregido[TAM];

    strcpy(textoCorregido, texto);

    for (int i = 0; textoCorregido[i] != '\0'; i++){

        textoCorregido[i] = tolower(textoCorregido[i]);

        if (!isalpha(textoCorregido[i]))
        {
            return -1;
        }
    }
    textoCorregido[0] = toupper(textoCorregido[0]);
    strcpy(texto, textoCorregido);
    return 0;
}
