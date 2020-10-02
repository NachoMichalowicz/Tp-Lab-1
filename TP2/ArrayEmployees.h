#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;

/** \brief Para indicar que todas las posiciones están efectivamente vacías
 * esta función pone la vandera vacía (isEmpty) como TRUE en todas las
 * posiciones del array.
 * \param list Employee* Pointer al array de employees.
 * \param len int Tamaño del array.
 * \return int Return (-1) Si hay un error [Tamaño inválido or puntero nulo] - (0) si está bien.
 *
 */

int initEmployees(Employee* list, int len);

/** \brief Agrega los valores recibidos a una lista existente de empleados en la última posición
 * \param list employee* Lista de empleados
 * \param len int Tamaño
 * \param id int Id
 * \param name[] char Nombre
 * \param lastName[] char Apellido
 * \param salary float Salario
 * \param sector int Sector
 * \return int Return (-1) si hubo un error - (0) si salió bien
 *
 */

int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/** \brief Encuentra a un empleado mediante una id y devuelve el index del mismo
 *
 * \param list Employee* Lista de empleados
 * \param len int Tamaño
 * \param id int Id a buscar
 * \return Retorna la posición en index del empleado o (-1) en caso de que no exista.
 *
 */

int findEmployeeById(Employee* list, int len, int id);


/** \brief Elimina a un empleado por ID. Cambia su isEmpty a 1.
 *
 * \param list Employee* Lista de empleados
 * \param len int Tamaño
 * \param id int Id de empleado a eliminar
 * \return int Retorna -1 si no pudo efectuarse la eliminación o 0 en caso de que se haya efecutado.
 *
 */

int removeEmployee(Employee* list, int len, int id);

/** \brief Ordena el array de empleados.
 *
 * \param list Employee* Lista de empleados
 * \param len int Tamaño
 * \param order int 1: Orden ascendente, 2: Orden descendente
 * \return int Retorna (-1) en caso de error y (0) en caso de no error.
 *
 */

int sortEmployee(Employee* list, int len, int order);


/** \brief Imprime el contenido del array "empleados"
 *
 * \param list Employee* Lista de empleados
 * \param length int Tamaño
 * \return int Si no hay empleados a mostrar retorna (-1) Caso contrario, retorna (0)
 *
 */

int printEmployees(Employee* list, int length);


#endif // ARRAYEMPLOYEES_H_INCLUDED
