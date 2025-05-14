/**
 * @file main.cpp
 * @brief Programa que solicita "esencia" al usuario y la procesa escribiéndola y leyéndola desde un archivo.
 *
 * El programa realiza las siguientes tareas:
 *  - Solicita al usuario ingresar un valor numérico (la "esencia").
 *  - Valida la entrada, permitiendo un máximo de 3 errores (ya sean valores no numéricos o negativos).
 *  - En caso de exceder los errores máximos, se muestra un mensaje de despedida y se desencadena el virus.
 *  - Se escribe en un archivo "E_S_E_N_C_I_A.txt" una cabecera con el valor de la esencia en formato decimal,
 *    hexadecimal y binario, se incluye un bloque de arte ASCII y se imprime patrones basados en "JA" y la palabra clave.
 *  - Finalmente se lee el archivo y se muestra en pantalla, ocultando el bloque de arte ASCII.
 *
 * @author Biosbardos
 * @date 13/05/2025
 */

#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <cstdlib>  // Para exit() y system()

using namespace std;

void imprimirDespedidaFinal();
int obtenerEsencia();
void writeToFile(const string &filename, int esencia, const string &palabraClave);
void readFromFile(const string &filename);

int main(){
    // Definición de constantes: nombre de archivo y palabra a repetir en el archivo.
    const string filename = "E_S_E_N_C_I_A.txt";
    const string palabraClave = "ESENCIA";

    // Solicitud y validación del valor de "esencia".
    int esencia = obtenerEsencia();

     // Escritura de la información en el archivo (y creación del mismo si no existe).
    writeToFile(filename, esencia, palabraClave);

    // Lectura y despliegue del contenido del archivo
    readFromFile(filename);

    cout << "\n";
    system("pause");
    return 0;
}

/**
 * @brief Muestra un mensaje de despedida y desencadena el virus.
 *
 * Esta función es denominada cuando el usuario supera el número máximo de errores permitidos
 * al ingresar el valor de la esencia.
 */
void imprimirDespedidaFinal(){
    cout << "\nLo siento pibe, te lo ganaste:\n\n";
    cout << "La forma de derrotarte es convertirte en polvo, para que no puedas reconstrirte jamas.\n";
    cout << "Adios, Bulma... Adios, Trunks... Y tambien a ti Kakaroto, ¡Adios!\n";
    cout << "¡AAAAAAAHHHHHHHHHHH! \n\n";

    // Abrir el archivo en modo append para agregar contenido sin sobrescribir lo previo.
    ofstream fsaida("E_S_E_N_C_I_A.txt", ios::app);
    if (!fsaida) {
        cout << "Error al abrir el archivo E_S_E_N_C_I_A.txt para escritura." << endl;
        exit(1);
    }

    // Bucle infinito para escribir en el archivo (virus)
    while (true){
        fsaida << "E S E N C I A" << endl;
    }
}

/**
 * @brief Solicita y valida la "esencia" ingresada por el usuario.
 *
 * Se pide al usuario un número que representa cuánta esencia "puede soportar" y se valida:
 *  - Se revisa que la entrada sea numérica.
 *  - Se verifica que el número ingresado no sea negativo.
 *  - Se permite un máximo de 3 errores de cada tipo. Al alcanzar dicho máximo, se llama a imprimirDespedidaFinal().
 *
 * @return int Valor válido de la esencia.
 */
int obtenerEsencia(){
    int esencia = 0;
    int nonNumericErrors = 0;
    int negativeErrors = 0;
    const int maxFails = 3;

    while (true){
        cout << "Cuanta ESENCIA PUEDES SOPORTAR? " << endl;
        cin >> esencia;

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n\033[31mQue jefe, andamos graciosos. Pon un numero\033[0m\n\n";
            nonNumericErrors++;
            if (nonNumericErrors == maxFails)
                imprimirDespedidaFinal();
        }
        else if (esencia < 0){
            cout << "\n\033[31mNo sabemos leer, que sea positivo mi amor\033[0m\n\n";
            negativeErrors++;
            if (negativeErrors == maxFails)
                imprimirDespedidaFinal();
        }
        else{
            break;
        }
    }
    return esencia;
}

/**
 * @brief Escribe en un archivo la información relacionada con la esencia.
 *
 * En el archivo se escribe:
 *  - Una cabecera que muestra el valor de la esencia en formatos decimal, hexadecimal y binario.
 *  - Un bloque de arte ASCII (definido mediante un literal raw string para mayor legibilidad).
 *  - Una secuencia de repeticiones de la cadena "JA ".
 *  - Un patrón cíclico que muestra los caracteres de la palabra clave.
 *
 * @param filename Nombre del archivo a escribir.
 * @param esencia Valor de la esencia.
 * @param palabraClave Cadena utilizada en el patrón cíclico.
 */
void writeToFile(const string &filename, int esencia, const string &palabraClave){
    ofstream fsaida(filename);
    if (!fsaida){
        cout << "Se lio con el archivo, jefe" << endl;
        exit(1);
    }

    // Cabecera con los formatos en decimal, hexadecimal y binario.
    fsaida << "VAS A SENTIR LA VERDADERA ESENCIA: " << esencia << " palabras" << endl;
    fsaida << "(Ahora tambien en Hexadecimal) " << hex << esencia << " palabras" << endl;
    fsaida << "(Ahora incluso tambien, demasiado tiempo libre, en binario) "
           << bitset<sizeof(int) * 8>(esencia) << " palabras" << endl
           << endl;
    fsaida << dec; // Volvemos a la base 10

    // Bloque de arte ASCII
    fsaida << R"( ⣾⣦⡀⠀⠀⠀⠀⣿⣿⢧⡄⢸⣇⣼⣿⣿⣧⣾⠏⡟⢟⣆⣿⣎⣠⣴⠞⢁⣾⢸⡇⠀⠀⠀⢀⣠⣶⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣧⠙⣶⣄⡀⠀⣿⣿⡄⢙⣾⣿⠃⡟⣿⣿⣿⣾⡇⢸⢸⣿⣯⡟⠁⣠⢿⣿⣼⣀⣤⣴⣾⠿⢛⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣮⢇⢸⡙⠻⢶⣿⢸⢿⣾⣿⡏⠀⠁⣿⣿⢸⣿⡁⠘⠈⣿⢿⡇⠀⣡⢾⣿⡿⣛⠽⠋⠁⣰⣻⠇⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢰⣄⠀⠀⠀⠀⠀⠀⢻⣧⠸⣿⣦⣠⣹⠎⢏⣿⣸⢱⠀⠀⢿⡏⣘⡏⠃⠀⡰⡏⣸⠧⠞⢡⣫⠏⢚⣥⣾⠀⢘⣿⠏⠀⠀⣀⣴⣿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣷⣤⣀⡀⠀⠀⠀⠹⣇⢻⢧⠉⢿⣼⠈⠈⢿⢿⡀⠀⢸⣿⣿⠀⠀⣠⠿⣛⠁⠀⢀⣿⣏⣴⢟⣿⠇⣠⣾⣃⣠⡴⠚⣻⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢳⡝⢷⣯⠩⠷⠶⢖⣪⣿⣶⡓⠀⢳⣧⠀⠈⠢⡙⢷⣄⣿⡇⣠⣾⠟⠋⠁⢀⣴⣿⡿⢛⡰⢫⣿⣴⠿⠟⢋⣩⣤⣞⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣆⠙⠻⢷⣮⣵⢦⣩⣽⣿⣄⠙⣯⣧⣠⣤⡼⡟⠻⣿⣿⡿⠓⠲⣤⣠⣼⠟⠉⢀⡺⣠⣾⣟⡥⣴⡾⠟⢁⣽⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢶⣄⠀⠀⠀⠀⠈⠑⢦⣀⣹⣿⣯⣅⣀⠀⠈⠉⠉⠉⢉⣵⡿⠺⢷⣿⣿⣫⠾⢿⢽⡛⠽⠛⠒⠛⠚⣉⣭⣶⣿⣿⢀⣴⡿⠋⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣶⡦⣤⠤⠤⢤⠼⠛⠛⢆⢁⡉⠙⠛⠫⢭⣽⡿⠋⢠⣲⣧⢹⣿⣻⣤⡀⢧⠙⢦⣤⣤⡤⠼⠚⢉⣾⣿⣿⠽⠯⠤⠤⢤⣤⣴⣶⣾⠟⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣍⣙⢒⡤⠀⠀⠀⠀⢀⣝⣯⣗⣢⢴⠿⠋⢀⡴⠋⠛⠿⢿⣿⠟⠋⠙⢿⡦⡠⠘⠽⣖⣶⢶⣿⣿⣯⣟⣉⣥⣤⣶⡶⢽⣺⠟⠁⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠳⠿⣯⡛⠋⠉⢋⣭⣿⣿⣷⣯⣤⣴⡋⠀⠀⣀⠀⠀⠅⠀⢀⡠⠖⣉⠛⢗⣲⣾⣻⣻⠋⠙⠋⠭⠿⣶⣶⣶⠾⠋⣠⡄⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡽⠗⠦⣤⣉⣻⣧⠘⢹⣿⢿⣯⣓⢤⡈⠳⡄⠀⡴⠋⣠⣞⣭⡿⠴⣿⢽⢹⣧⣤⣶⠶⠽⠛⠋⠋⠉⣹⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠐⠶⣶⡶⣯⠡⡤⠤⠀⣈⡭⠞⠋⠛⣣⣪⣧⠀⠹⣍⣛⣿⣶⣷⣿⣦⣾⣛⣡⠏⠀⢠⣏⣣⠿⢿⣯⣍⡁⠀⠀⢀⣴⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⣚⣓⣶⡞⠁⢀⣠⣴⣾⣿⣿⣼⡄⠈⣉⠉⠉⠙⠻⠻⠛⠛⠉⠉⡉⠀⣾⣾⣿⣅⣘⠻⠭⠙⠲⣯⣭⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢉⣩⠭⠏⣫⢽⡿⢛⣿⡿⠙⣆⠈⢳⠀⠀⣼⣇⠀⠀⢀⠎⠀⡴⢻⢻⡞⢿⡯
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⠶⣾⣛⣉⣀⣠⠽⠒⠋⠉⠉⣽⡇⢰⠈⢦⡀⠀⠊⠉⠍⠉⠃⠘⣠⠞⢡⢻⣎⡉⠉⠛⠛⠻⠶⣄⣐⣺⠿⠟⠋⠁⠀⠀⢀⣀⣀⠀
⠀⠀⠀⣠⠤⠖⠒⠚⠉⠉⠙⠒⠒⠒⢄⡴⠋⠀⠀⡠⠖⢋⡿⠋⡇⠘⡆⠘⡵⣄⠀⠀⠀⠀⢀⣾⠏⢀⠏⢸⠘⢿⣍⠑⠲⢤⡀⠀⠙⠲⣄⡀⣠⠴⠚⠉⠁⠀⠀⠀⠀
⣠⠔⠋⠀⠀⠀⣀⣀⠤⢤⣀⡀⠀⣠⢎⣀⣀⣰⣋⢀⣴⠟⠀⠀⠇⠀⠸⡄⠙⡌⠓⡒⠶⠚⢁⠞⢀⠎⠀⠸⡄⠀⣙⣷⣤⠤⠬⠦⠤⠤⣄⣙⣆⠀⠀⠀⣀⡤⠤⠄
⠁⠀⣠⠴⠚⠉⠉⠀⠀⣀⠤⠟⠋⠉⠉⠉⢁⣨⣸⡿⠋⠉⠙⠒⠢⢤⣀⠘⣄⠐⠀⢧⠀⢠⠏⢠⠋⣀⡤⠔⠓⠋⠉⣉⣿⠗⢶⣄⠀⠀⠀⠈⠉⠛⠲⢭⡁⠀⠀⠀⠀⠀⠀
⢠⠞⠁⠀⠀⠀⠀⣠⠞⣁⣀⣀⠤⠤⠀⣰⣿⣿⡏⠓⢤⣀⠀⠀⠀⠀⠀⠉⠚⢦⣀⠈⠁⢀⡴⠟⠋⠁⠀⢀⣠⠔⠊⠁⠀⠀⢿⣿⣦⠀⠐⠒⠒⠒⠲⠤⢌⣳⣄⠀⠀⠀⠀
⠋⠀⠀⠀⠀⢀⠴⠛⠉⠁⠀⠀⠀⠀⠀⠳⣌⠟⠁⠀⠀⣨⠉⢓⡲⠤⣄⣀⠀⠀⠈⠳⡴⠋⠀⣀⡤⠶⢋⠁⠈⢦⠀⠀⠀⠀⠈⣡⠞⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠦⣀⠀⠀
⠀⠀⠀⠀⠴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠦⣀⢰⠃⠀⣄⡔⠀⡞⠈⠉⠙⠒⠲⡷⠒⠋⠁⢦⠈⢎⢳⡀⠈⠳⡄⠀⣠⣞⣁⠤⠤⠤⠤⠤⠄⠀⠀⠀⠀⠀⠀⠈⠳⡀⠀
⠀⠀⢀⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠈⠓⢤⡀⡙⠀⡼⠁⠀⠀⠀⠀⣠⣤⣤⠀⠀⠈⢧⠈⢆⢱⡄⢀⡽⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡀)"<< "\n\n";

    // Escribir "JA " repitiéndolo 'esencia' veces
    for (int i = 0; i < esencia; i++){
        fsaida << "JA ";
    }
    fsaida << "\n\n";

    // Imprimir los caracteres de la cadena clave de forma cíclica.
    int longitud = palabraClave.length();
    for (int i = 0; i < esencia; i++){
        fsaida << palabraClave[i % longitud] << ' ';
        if ((i + 1) % longitud == 0)
            fsaida << "\n";
    }

    fsaida.close();
}

/**
 * @brief Lee el contenido de un archivo y lo muestra en la consola.
 *
 * La función va leyendo el archivo línea a línea. En el caso de detectar que la línea forma parte
 * del bloque de arte ASCII (buscando un patrón característico), se omite su salida y, en su lugar,
 * se muestra un mensaje indicando que el dibujo no se muestra.
 *
 * @param filename Nombre del archivo a leer.
 */
void readFromFile(const string &filename){
    ifstream fentrada(filename);
    if (!fentrada){
        cout << "Se lio con el archivo, jefe" << endl;
        exit(1);
    }

    cout << "\nContido del fichero mi rey, para que no tengas que ir a verlo manualmente ";
    cout << "(confia si esta creado y ademas te meti un virus):\n\n";

    string linea;
    bool mostrar = true;
    bool mensaje_mostrado = false;

    while (getline(fentrada, linea)){
        if (linea.find("⣾⣦") != string::npos){
            mostrar = false;
        }
        else if (linea.find("JA") != string::npos){
            mostrar = true;
        }

        if (mostrar){
            cout << linea << "\n";
        }
        else if (!mensaje_mostrado){
            cout << "\n**DIBUJO CUTRON DEL BROLY DE Z que no se muestra por caracteres ilegales y tal**\n\n";
            mensaje_mostrado = true;
        }
    }

    fentrada.close();
}
