#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int validarOperandos(char operando1[LEN], char operando2[LEN]);
/** brief Valida si se han ingresado ambos operandos
*
*\param char operando1[]: Operando 1 representado en cadenas de caracteres.
*\param char operando2[]: Operando 2 representado en cadenas de caracteres.
*\return int: Devuelve 1 en caso de que est�n ingresados o 0 en caso contrario.
*
*/

int pedirNumero(char mensaje[26]);
/** brief Pide un n�mero al usuario.
*
*\param char[] : Mensaje que se mostrar� en pantalla al pedir el n�mero.
*\return int: Devuelve el n�mero ingresado por el usuario mediante formato entero.
*
*/

void mostrarMenu(char a[LEN], char b[LEN], char resultadosMensaje[TAM][LEN]);
/** brief Muestra y actualiza el men� general.
*
*\param char[]: Primer operando representado en una cadena de caracteres.
*\param char[]: Segundo operando representado en una cadena de caracteres.
*\param char[][]: Resultados de los c�lculos representados en una cadena de caracteres multidimensional.
*/

void pausar();
/** brief Pausa el programa y espera confirmaci�n del usuario para continuar.
*
*/

#endif // MENU_H_INCLUDED
