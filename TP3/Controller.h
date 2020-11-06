

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Alta de empleados
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id);


/** \brief Modificar datos de empleado
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Listar empleados
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados
 * \return int Retorna 1 en caso de que la carga haya sido exitosa. Caso contrario, retorna -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Compara los nombres de dos empleados
 *
 * \param void* pEmployee1 Primer empleado
 * \param void* pEmployee2 Segundo empleado
 * \return int Retorna 1 en caso de que el primero sea mayor. -1 en caso de que el segundo sea mayor. 0 si ambos son iguales
 *
 */
int compare_EmployeesName(void* pEmployee1, void* pEmployee2);


/** \brief Compara los ID'S de dos empleados
 *
 * \param void* pEmployee1 Primer empleado
 * \param void* pEmployee2 Segundo empleado
 * \return int Retorna 1 en caso de que el primero sea mayor. -1 en caso de que el segundo sea mayor. 0 si ambos son iguales
 *
 */
int compare_EmployeesID(void* pEmployee1, void* pEmployee2);


/** \brief Compara los salarios de dos empleados
 *
 * \param void* pEmployee1 Primer empleado
 * \param void* pEmployee2 Segundo empleado
 * \return int Retorna 1 en caso de que el primero sea mayor. -1 en caso de que el segundo sea mayor. 0 si ambos son iguales
 *
 */
int compare_EmployeesSalario(void* pEmployee1, void* pEmployee2);


/** \brief Compara las horas de dos empleados
 *
 * \param void* pEmployee1 Primer empleado
 * \param void* pEmployee2 Segundo empleado
 * \return int Retorna 1 en caso de que el primero sea mayor. -1 en caso de que el segundo sea mayor. 0 si ambos son iguales
 *
 */
int compare_EmployeesHoras(void* pEmployee1, void* pEmployee2);

