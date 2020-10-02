#include <stdio.h>
#include <stdlib.h>
#include "maths.c"
#include "menu.c"

#define TAM 6
#define LEN 4

int main()
{
    char resultados[TAM][LEN] = {"r", "r" ,"r", "r" ,"r1", "r2"};
    char strValor1[LEN] = "A";
    char strValor2[LEN] = "B";

    int opcion = 0;

    int valor1;
    int valor2;

    int suma;
    int resta;
    int multiplicacion;
    long int factorial1;
    long int factorial2;
    float division;

    int flagCalculos = 0;

    while (opcion != 5)
    {
        mostrarMenu(strValor1, strValor2, resultados);
        opcion = pedirNumero("Ingrese una opcion: ");

        switch(opcion)
        {
            case 1:
                valor1 = pedirNumero("\nIngrese el primer valor: ");
                sprintf(strValor1, "%d", valor1);
                break;

            case 2:
                valor2 = pedirNumero("\nIngrese el segundo valor: ");
                sprintf(strValor2, "%d", valor2);
                break;

            case 3:
                if (validarOperandos(strValor1, strValor2) == 0)
                {
                    printf("Antes de calcular ingrese dos valores!\n");
                }
                else
                {
                    suma = sumar(valor1, valor2);
                    resta = restar(valor1, valor2);
                    division = dividir(valor1, valor2);
                    multiplicacion = multiplicar(valor1, valor2);

                    factorial1 = factorizar(valor1);
                    factorial2 = factorizar(valor2);

                    printf("\nCalculos realizados\n");
                    flagCalculos = 1;
                }

                break;

            case 4:
                if (flagCalculos == 1)
                {
                    sprintf(resultados[0], "%d", suma);
                    sprintf(resultados[1], "%d", resta);

                    if (valor2 == 0){
                        resultados[2][0] = 'n';
                    }
                    else
                    {
                        sprintf(resultados[2], "%.1f", division);
                    }

                    sprintf(resultados[3], "%d", multiplicacion);

                    if (valor1 < 0)
                    {
                        resultados[4][0] = 'n';
                    }
                    else
                    {
                        sprintf(resultados[4], "%ld", factorial1);
                    }

                    if (valor2 < 0)
                    {
                        resultados[5][0] = 'n';
                    }
                    else
                    {
                        sprintf(resultados[5], "%ld", factorial2);
                    }
                    printf("\nActualice y apareceran los resultados en pantalla\n");
                }
                else
                {
                    printf("\nPrimero se deben calcular las operaciones!\n");
                }
                break;

            case 5:
                return 0;
                break;

            default:
                printf("\nIngrese una opcion valida\n");
        }
        pausar();
    }
}
