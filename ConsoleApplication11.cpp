#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
// INSTRUCCION PARA IGNORAR EL ERROR 
#pragma warning(disable : 4996)
using namespace std;

const float Cuota_Membresia = 25.00;
const float Precio_Por_Sesion = 15.00;
const float Precio_Por_Clase = 11.00;


double MesesMembresia = 0, Totalidad_1 = 0, Totalidad_2 = 0, Totalidad_3 = 0, Sesiones = 0;


float Calcular_Total(float Totalidad_1, float Totalidad_2, float Totalidad_3) {
    return Totalidad_1 + Totalidad_2 + Totalidad_3;
}


void Manejar_Opcion(int opcion) {
    switch (opcion) {
    case 1: {
        cout << "Ingrese la cantidad de meses que desea utilizar las instalaciones: \n";
        cin >> MesesMembresia;
        if (MesesMembresia == 0) {
            cout << "Hasta luego\n";

        }
        Totalidad_1 = MesesMembresia * Cuota_Membresia;
        cout << "Total de la cuota de membresia: $" << Totalidad_1 << " por " << MesesMembresia << " meses\n";
        break;
    }

    default: {
        cout << "Opcion invalida. Por favor seleccione una opcion del 1 al 3.\n";
        break;
    }
    }
}

string Seleccionar_Entrenador() {
    string horarios[3] = { "5a.m-12p.m", "12p.m-9p.m", "9p.m-5a.m" };
    string entrenadores[3] = { "Luis", "July", "Cbum" };

    cout << "Los Horarios Disponibles son:\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << horarios[i] << endl;
    }
    cout << "Elija un horario (1-3): ";
    int opcion;
    cin >> opcion;
    if (opcion >= 1 && opcion <= 3) {
        //opcion-1 para que reste uno y comienze en la posicion 0 
        cout << "El horario de " << entrenadores[opcion - 1] << " es de " << horarios[opcion] << endl;
    }
    else {
        cout << "Opci�n inv�lida.\n";
    }
    return entrenadores[opcion - 1];
}

int main() {
    int opcion, year, mes, dia, edad;

    // of stream para crear archivo 
    ofstream Myfile("Bienvenida.txt");
    Myfile << " Bienvenid@ al sistema de aplicacion de membresia para:  ONLY FOR ALPHAS GYM ";
    Myfile.close();

    //if stream para llamar y mostrar el archivo
    ifstream ReadFile("Bienvenida.txt");
    string line;
    // get line para mostrar cada linea de texto en el archivo creado 
    while (getline(ReadFile, line))
    {
        cout << line << endl;
    }


    //Para saber la fecha del dispositivo
    time_t now = time(0);
    tm* localTime = localtime(&now);
    //LLevarlo al year actual 
    int currentYear = 1900 + localTime->tm_year;
    do {
        cout << "Recuerde que para entara a nuestras instalaciones debe ser mayor de edad\n";
        cout << "Entre su fecha de naciento para comenzar (year, mes y dia)";
        cin >> year >> mes >> dia;
        edad = currentYear - year;
        // ajuste si el usuario todavia no ha cumplido
        if (mes > localTime->tm_mon + 1 || (mes == localTime->tm_mon + 1 && dia > localTime->tm_mday)) {
            edad--;
        }
        cout << "Su edad actual es " << edad << " de edad \n";
    } while (edad <= 17);


    //Manejar_Opcion(1);
    cout << "Ingrese la cantidad de meses que desea utilizar las instalaciones: \n";
    cin >> MesesMembresia;
    if (MesesMembresia == 0) {
        cout << "Hasta luego\n";
        // return -1 dentro del main para terminar el programa 
        return -1;
    }
    Totalidad_1 = MesesMembresia * Cuota_Membresia;
    cout << "Total de la cuota de membresia: $" << Totalidad_1 << " por " << MesesMembresia << " meses\n";

    char quiere_Entrenamiento, quiere_Clases;

    cout << "Desea entrenamiento personal? (s/n):  \n";
    cin >> quiere_Entrenamiento;
    // declaro la variable sin llamr la funcion 
    string trainer = "";

    if (quiere_Entrenamiento == 's' || quiere_Entrenamiento == 'S') {
        // utilizo la variable para llamar la funcion 
        trainer = Seleccionar_Entrenador();;
    }

    cout << "Desea inscribirse en clases grupales? (s/n):  \n";
    cin >> quiere_Clases;

    if (quiere_Clases == 's' || quiere_Clases == 'S') {
        int Cantidad_Clases;
        cout << "Ingrese la cantidad de clases en las que desea inscribirse:  \n";
        cin >> Cantidad_Clases;
        Totalidad_3 = Precio_Por_Clase * Cantidad_Clases;
    }

    double total_general = Calcular_Total(Totalidad_1, Totalidad_2, Totalidad_3); // Calculando el total general

    cout << "Costo total a pagar: $" << total_general << endl;

    string quiere_Servicios, nombre, apellido;
    int codigo;

    cout << "Desea crear un perfil para futuras visitas? (s/n)  \n";
    cin >> quiere_Servicios;
    system("cls");
    if (quiere_Servicios == "s" || quiere_Servicios == "S") {
        cout << "Cree un perfil para guardar sus datos  \n";
        cout << "Ingrese su nombre:  \n";
        cin >> nombre;
        cout << "Ingrese su apellido:  \n";
        cin >> apellido;
        cout << "Cree un codigo para acceder a su perfil:  \n";
        cin >> codigo;


        int codigo_Perfil;

        //Loop #2
        do {
            cout << "Ingrese su codigo para acceder al perfil:  \n";
            cin >> codigo_Perfil;

            if (codigo_Perfil != codigo) {
                cout << "Codigo incorrecto. Intente nuevamente." << endl;
            }
        } while (codigo_Perfil != codigo);


        cout << "Bienvenid@ a su perfil: " << nombre << " " << apellido << endl;
        cout << "Su membresia incluye: " << MesesMembresia << " meses de uso en nuestras instalaciones por un costo de: $" << Totalidad_1 << endl;
        cout << " Usted escogio " << trainer << " como su entrenador personal " << endl;
    }
    else {
        cout << "GRACIAS POR SU VISITA \n";
    }
    return 0;
}