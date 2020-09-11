#define TAM 6
#define LEN 4

int validarOperandos(char operando1[LEN], char operando2[LEN])
{
    if (operando1[0] == 'A' || operando2[0] == 'B')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int pedirNumero(char mensaje[26])
{
    int num;

    printf("%s", mensaje);
    scanf("%d", &num);
    fflush(stdin);

    return num;
}

void mostrarMenu(char a[LEN], char b[LEN], char resultadosMensaje[TAM][LEN])
{
    system("cls");

    printf("1. Ingresar 1er operando (A=%s)\n", a);
    printf("2. Ingresar 2do operando (B=%s)\n", b);
    printf("3. Calcular todas las operaciones\n\n");

    printf("    a) Calcular la suma (%s+%s)\n", a, b);
    printf("    b) Calcular la resta (%s-%s)\n", a, b);
    printf("    c) Calcular la division (%s/%s)\n", a, b);
    printf("    d) Calcular la multiplicacion (%s*%s)\n", a, b);
    printf("    e) Calcular el factorial (%s!)\n\n", a);

    printf("4. Informar resultados\n");
    printf("    a) El resultado de %s+%s es: %s\n", a, b, resultadosMensaje[0]);
    printf("    b) El resultado de %s-%s es: %s\n", a, b, resultadosMensaje[1]);


    if (resultadosMensaje[2][0] == 'n')
    {
        printf("    c) No es posible dividir por cero\n");
    }
    else
    {
        printf("    c) El resultado de %s/%s es: %s\n", a, b , resultadosMensaje[2]);
    }

    printf("    d) El resultado de %s*%s es: %s\n", a, b, resultadosMensaje[3]);

    if (resultadosMensaje[4][0] == 'n')
    {
        printf("    e) No es posible factorizar con un valor negativo.\n");
    }
    else
    {
        printf("    e) El factorial de %s es: %s\n", a, resultadosMensaje[4]);
    }

    if (resultadosMensaje[5][0] == 'n')
    {
        printf("       No es posible factorizar con un valor negativo.\n");
    }
    else
    {
        printf("       El factorial de %s es: %s\n", b, resultadosMensaje[5]);
    }

    printf("5. Salir\n");

}

void pausar()
{
    printf("\nPresione 'intro' para continuar");
    getchar();
}
