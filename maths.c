int sumar(int a, int b)
{
    int resultado = a + b;

    return resultado;
}

int restar(int a, int b)
{
    int resultado = a - b;

    return resultado;
}

float dividir(int a, int b)
{
    float resultado = (float)a / b;

    return resultado;
}

int multiplicar(int a, int b)
{
    int resultado = a * b;

    return resultado;
}


long int factorizar(int num)
{
    long int resultado = num;
    int i;

    for (i = num -1; i > 0; i--)
    {
        resultado = resultado * i;

    }
    return resultado;
}
