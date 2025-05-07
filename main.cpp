//Programa esencial, siete palabras (Ahora, con manejo de error)


#include <iostream>
#include <fstream>
#include <bitset>
#include <string> //yo creo que esto sobra, pero a algunos bobis le daba error
#define MAXCAD 2147483647 //MAX_INT
using namespace std;


int main (){

    //char cadea [MAXCAD];
    string linea;
    string siete_palabras = "ESENCIA";
    int longitud = siete_palabras.length();
    int esencia, no_jodas_pibe, te_vas_a_cagar; //unsigned int todo esto y te ahorras comprobar luego si no son negativos, digo, vamos, no sé...
    bool mostrar = true, mensaje_mostrado = false;

    // Escritura no arquivo
    ofstream fsaida("E_S_E_S_E_N_C_I_A.txt"); //fluxo de saída e apertura do arquivo
    if (!fsaida) {
        cout << "Se lio con el archivo, jefe " << endl;
    return 1;
    }

    else {

        while (true){

            cout << "Cuanta ESENCIA PUEDES SOPORTAR? " << endl;
            cin >> esencia;

            if (cin.fail()){

                cin.clear();
                cin.ignore(10000, '\n');
                cout << endl << "\033[31mQue jefe, andamos graciosos. Pon un numero\033[0m"<< endl << endl;
                no_jodas_pibe++;

                if(no_jodas_pibe == 3){

                    goto BUCLE; //No hace falta el horror este si se usase alguna función en todo esto, es más no harían falta dos bucles si se usase unsigned int
                }
            }

            else if (esencia <0){

                cout << endl << "\033[31mNo sabemos leer, que sea positivo mi amor\033[0m" << endl << endl;
                te_vas_a_cagar ++;

                if(te_vas_a_cagar == 3){

                BUCLE:

                cout << "Lo siento pibe" <<endl <<endl;
                cout << "Bulma... Trunks... No se si algun dia entenderas por que hice lo que hice, pero... Adios.Kakarotto! No me llames por mi nombre, no lo hare. Pero si por alguna razon llegamos a encontrarnos, te lo dire.Este es el final para mi, Kakarotto.Adios, Bulma. Adios, Trunks. Adios, mundo! Adios a todos!";
                cout << endl << endl;

                    while (true){

                        fsaida << "E S E N C I A" << endl;

                    }
                }

            }

            else{

                break;

            }

        }



        cout << endl << endl; // no lo voy a cambiar pero fuere mejor usar el \n aquí que tanto endl de Dios que no es necesario para simplemente meter espacios


        fsaida << "VAS A SENTIR LA VERDADERA ESENCIA: " << esencia << " palabras" <<  endl;
        fsaida << "(Ahora tambien en Hexadecimal) "<< hex << esencia << " palabras" << endl;
        fsaida << "(Ahora incluso tambien, demasiado tiempo libre, en binario) "<< bitset<sizeof(int) * 8> binario(esencia);//Lo voy a hacer bien pero sencillito igual  || (código): bitset<32>(esencia)<< " palabras" << endl << endl; // Sí, no está bien hecho. Esto no me lo hace C++ así que va cutrón y ya

        fsaida << "⠀                 ⣾⣦⡀⠀⠀⠀⠀⣿⣿⢧⡄⢸⣇⣼⣿⣿⣧⣾⠏⡟⢟⣆⣿⣎⣠⣴⠞⢁⣾⢸⡇⠀⠀⠀⢀⣠⣶⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣧⠙⣶⣄⡀⠀⣿⣿⡄⢙⣾⣿⠃⡟⣿⣿⣿⣾⡇⢸⢸⣿⣯⡟⠁⣠⢿⣿⣼⣀⣤⣴⣾⠿⢛⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣮⢇⢸⡙⠻⢶⣿⢸⢿⣾⣿⡏⠀⠁⣿⣿⢸⣿⡁⠘⠈⣿⢿⡇⠀⣡⢾⣿⡿⣛⠽⠋⠁⣰⣻⠇⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⢰⣄⠀⠀⠀⠀⠀⠀⢻⣧⠸⣿⣦⣠⣹⠎⢏⣿⣸⢱⠀⠀⢿⡏⣘⡏⠃⠀⡰⡏⣸⠧⠞⢡⣫⠏⢚⣥⣾⠀⢘⣿⠏⠀⠀⣀⣴⣿⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣷⣤⣀⡀⠀⠀⠀⠹⣇⢻⢧⠉⢿⣼⠈⠈⢿⢿⡀⠀⢸⣿⣿⠀⠀⣠⠿⣛⠁⠀⢀⣿⣏⣴⢟⣿⠇⣠⣾⣃⣠⡴⠚⣻⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢳⡝⢷⣯⠩⠷⠶⢖⣪⣿⣶⡓⠀⢳⣧⠀⠈⠢⡙⢷⣄⣿⡇⣠⣾⠟⠋⠁⢀⣴⣿⡿⢛⡰⢫⣿⣴⠿⠟⢋⣩⣤⣞⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣆⠙⠻⢷⣮⣵⢦⣩⣽⣿⣄⠙⣯⣧⣠⣤⡼⡟⠻⣿⣿⡿⠓⠲⣤⣠⣼⠟⠉⢀⡺⣠⣾⣟⡥⣴⡾⠟⢁⣽⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⢶⣄⠀⠀⠀⠀⠈⠑⢦⣀⣹⣿⣯⣅⣀⠀⠈⠉⠉⠉⢉⣵⡿⠺⢷⣿⣿⣫⠾⢿⢽⡛⠽⠛⠒⠛⠚⣉⣭⣶⣿⣿⢀⣴⡿⠋⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠹⣿⣶⡦⣤⠤⠤⢤⠼⠛⠛⢆⢁⡉⠙⠛⠫⢭⣽⡿⠋⢠⣲⣧⢹⣿⣻⣤⡀⢧⠙⢦⣤⣤⡤⠼⠚⢉⣾⣿⣿⠽⠯⠤⠤⢤⣤⣴⣶⣾⠟⠁⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣍⣙⢒⡤⠀⠀⠀⠀⢀⣝⣯⣗⣢⢴⠿⠋⢀⡴⠋⠛⠿⢿⣿⠟⠋⠙⢿⡦⡠⠘⠽⣖⣶⢶⣿⣿⣯⣟⣉⣥⣤⣶⡶⢽⣺⠟⠁⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠳⠿⣯⡛⠋⠉⢋⣭⣿⣿⣷⣯⣤⣴⡋⠀⠀⣀⠀⠀⠅⠀⢀⡠⠖⣉⠛⢗⣲⣾⣻⣻⠋⠙⠋⠭⠿⣶⣶⣶⠾⠋⣠⡄⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡽⠗⠦⣤⣉⣻⣧⠘⢹⣿⢿⣯⣓⢤⡈⠳⡄⠀⡴⠋⣠⣞⣭⡿⠴⣿⢽⢹⣧⣤⣶⠶⠽⠛⠋⠋⠉⣹⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠐⠶⣶⡶⣯⠡⡤⠤⠀⣈⡭⠞⠋⠛⣣⣪⣧⠀⠹⣍⣛⣿⣶⣷⣿⣦⣾⣛⣡⠏⠀⢠⣏⣣⠿⢿⣯⣍⡁⠀⠀⢀⣴⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⣚⣓⣶⡞⠁⢀⣠⣴⣾⣿⣿⣼⡄⠈⣉⠉⠉⠙⠻⠻⠛⠛⠉⠉⡉⠀⣾⣾⣿⣅⣘⠻⠭⠙⠲⣯⣭⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢉⣩⠭⠏⣫⢽⡿⢛⣿⡿⠙⣆⠈⢳⠀⠀⣼⣇⠀⠀⢀⠎⠀⡴⢻⢻⡞⢿⡯                      \n";
        fsaida << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⠶⣾⣛⣉⣀⣠⠽⠒⠋⠉⠉⣽⡇⢰⠈⢦⡀⠀⠊⠉⠍⠉⠃⠘⣠⠞⢡⢻⣎⡉⠉⠛⠛⠻⠶⣄⣐⣺⠿⠟⠋⠁⠀⠀⢀⣀⣀⠀\n";
        fsaida << "⠀⠀⠀⣠⠤⠖⠒⠚⠉⠉⠙⠒⠒⠒⢄⡴⠋⠀⠀⡠⠖⢋⡿⠋⡇⠘⡆⠘⡵⣄⠀⠀⠀⠀⢀⣾⠏⢀⠏⢸⠘⢿⣍⠑⠲⢤⡀⠀⠙⠲⣄⡀⣠⠴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⣠⠔⠋⠀⠀⠀⣀⣀⠤⢤⣀⡀⠀⣠⢎⣀⣀⣰⣋⢀⣴⠟⠀⠀⠇⠀⠸⡄⠙⡌⠓⡒⠶⠚⢁⠞⢀⠎⠀⠸⡄⠀⣙⣷⣤⠤⠬⠦⠤⠤⣄⣙⣆⠀⠀⠀⣀⡤⠤⠄⠀⠀⠀⠀\n";
        fsaida << "⠁⠀⣠⠴⠚⠉⠉⠀⠀⣀⠤⠟⠋⠉⠉⠉⢁⣨⣸⡿⠋⠉⠙⠒⠢⢤⣀⠘⣄⠐⠀⢧⠀⢠⠏⢠⠋⣀⡤⠔⠓⠋⠉⣉⣿⠗⢶⣄⠀⠀⠀⠈⠉⠛⠲⢭⡁⠀⠀⠀⠀⠀⠀⠀\n";
        fsaida << "⢠⠞⠁⠀⠀⠀⠀⣠⠞⣁⣀⣀⠤⠤⠀⣰⣿⣿⡏⠓⢤⣀⠀⠀⠀⠀⠀⠉⠚⢦⣀⠈⠁⢀⡴⠟⠋⠁⠀⢀⣠⠔⠊⠁⠀⠀⢿⣿⣦⠀⠐⠒⠒⠒⠲⠤⢌⣳⣄⠀⠀⠀⠀⠀\n";
        fsaida << "⠋⠀⠀⠀⠀⢀⠴⠛⠉⠁⠀⠀⠀⠀⠀⠳⣌⠟⠁⠀⠀⣨⠉⢓⡲⠤⣄⣀⠀⠀⠈⠳⡴⠋⠀⣀⡤⠶⢋⠁⠈⢦⠀⠀⠀⠀⠈⣡⠞⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠦⣀⠀⠀⠀\n";
        fsaida << "⠀⠀⠀⠀⠴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠦⣀⢰⠃⠀⣄⡔⠀⡞⠈⠉⠙⠒⠲⡷⠒⠋⠁⢦⠈⢎⢳⡀⠈⠳⡄⠀⣠⣞⣁⠤⠤⠤⠤⠤⠄⠀⠀⠀⠀⠀⠀⠈⠳⡀⠀\n";
        fsaida << "⠀⠀⢀⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠈⠓⢤⡀⡙⠀⡼⠁⠀⠀⠀⠀⣠⣤⣤⠀⠀⠈⢧⠈⢆⢱⡄⢀⡽⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡀\n" << endl << endl << endl;



        for (int i = 0; i < esencia; i ++){

            fsaida << "JA ";

        }

        fsaida << endl << endl;

        for (int i = 0; i < esencia; i ++){

            fsaida << siete_palabras [i % longitud] << ' ';

            if ((i + 1) % longitud == 0){
                fsaida << endl;
            }

        }
        fsaida.close();
    }

    // Lectura do arquivo
    ifstream fentrada ("E_S_E_S_E_N_C_I_A.txt"); //fluxo de entrada e apertura do arquivo
    if (!fentrada) {
        cout << "Se lio con el archivo, jefe" << endl;
        return 1;
    }

    else {

        cout << "Contido del fichero mi rey, para que no tengas que ir a verlo manualmente (confia si esta creado y ademas te meti un virus): "<< endl << endl;

        while (getline(fentrada, linea)) { //fentrada.getline(cadea, MAXCAD) con cadenas

            //string linea (cadea);

            if (linea.find("⣾⣦") != string::npos) {
                mostrar = false;
            }

            else if (linea.find("JA") != string::npos) {
                mostrar = true;
            }

            // Mostrar el contenido del archivo según la variable de control
            if (mostrar) {
                cout << linea << endl;
            }
            else if (!mensaje_mostrado){
                cout << "**DIBUJO CUTRÓN DEL BROLY DE Z que no se muestra por caracteres ilegales y tal**" << endl << endl;
                mensaje_mostrado = true;
            }
        }
        fentrada.close();
    }

    cout << endl;
    system("pause");
    return 0;
}
