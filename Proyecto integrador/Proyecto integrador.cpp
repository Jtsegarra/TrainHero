
// Chupapi munano

#include <iostream>
#include <string>

using namespace std;

// variables globales
const double Cuota_Membresia = 10.0;
const double Precio_Por_Sesion = 15.0;
const double Precio_Por_Clase[] = { 15.99, 20.99, 25.99 };
double MesesMembresia = 0, Totalidad_1 = 0, Totalidad_2 = 0, Sesiones = 0;

double Calcular_Total(double Totalidad_1, double Totalidad_2, double Totalidad_3) {
    return Totalidad_1 + Totalidad_2 + Totalidad_3;
}

double Precio_Total(int Meses_Membresia, int Sesiones, int Cantidad_Clases) {
    double Costo_Membresia = Meses_Membresia * Cuota_Membresia;
    double Costo_Entrenamiento = Sesiones * Precio_Por_Sesion;
    double Costo_Clases = Precio_Por_Clase[0] * Cantidad_Clases;

    return Costo_Membresia + Costo_Entrenamiento + Costo_Clases;
}

void Opciones() {
    cout << "Bienvenido a ONLY FOR ALPHAS GYM\n" << endl;
    cout << "1. Membresia Mensual\n";
    cout << "2. Entrenamiento Personal\n";
    cout << "3. Clases Grupales\n";
}

void Manejar_Opcion(int opcion) {
    switch (opcion) {
    case 1: {
        cout << "Ingrese la cantidad de meses que desea utilizar las instalaciones: ";
        cin >> MesesMembresia;

        Totalidad_1 = Precio_Total(MesesMembresia, 0, 0);

        cout << "Total de la cuota de membresia: $" << Totalidad_1 << " por " << MesesMembresia << " meses\n";

        cout << "Ingrese la cantidad de sesiones que desea en su entrenamiento: ";
        cin >> Sesiones;

        Totalidad_2 = Sesiones * Precio_Por_Sesion;

        cout << "Total a pagar por el entrenamiento personal: $" << Totalidad_2 << " por " << Sesiones << " sesiones.\n";
        break;
    }

    case 2: {
        int Cantidad_Clases;
        cout << "Ingrese la cantidad de clases en las que desea inscribirse: ";
        cin >> Cantidad_Clases;

        double Totalidad_3 = Precio_Por_Clase[0] * Cantidad_Clases;

        cout << "Precio total a pagar por las clases grupales: $" << Totalidad_3 << " por " << Cantidad_Clases << " clases de Culturismo.\n";
        break;
    }

    default:
    {
        cout << "Opcion invalida. Por favor seleccione una opcion del 1 al 3.\n";
        break;
    }
    }
}

int main() {
    cout << "  GGGGG   Y    Y    MMM   MMM\n";
    cout << " GG   GG   Y  Y     MM M M MM\n";
    cout << "GG         YYY      MM  M  MM\n";
    cout << "GG   GGG    Y       MM     MM\n";
    cout << " GG   GG    Y       MM     MM\n";
    cout << "  GGGGG     Y       MM     MM\n\n";

    cout << "  OOOOO   N     N    L      YY  YY   FFFFF   OOOOO    RRRRRR       AAA       L       PPPPPPP   H    H    A A   SSSSS\n";
    cout << " OO   OO  NN    N    L       Y  Y    F      OO   OO   R     R     A   A      L       P      P  H    H   A A A  S\n";
    cout << "OO     OO N N   N    L        YY     F     OO      O  R     R    A     A     L       P     P   HHHHHH  A     A  S\n";
    cout << "OO     OO N  N  N    L        Y      FFF   OO      O  RRRRRR     AAAAAAA     L       PPPPPP    H    H  AAAAAAA   SSS\n";
    cout << "OO     OO N   N N    L        Y      F     OO      O  R   R      A     A     L       P         H    H  A     A     S\n";
    cout << " OO   OO  N    NN    L        Y      F      OO   OO   R    R     A     A     L       P         H    H  A     A     S\n";
    cout << "  OOOOO   N     N    LLLLLLL  Y      F       OOOOO    R     R    A     A     LLLLLLL P         H    H  A     A SSSSS\n\n";

    Opciones();

    int opcion;
    cout << "Por favor seleccione una opcion: ";
    cin >> opcion;

    Manejar_Opcion(opcion);

    int Cantidad_Clases;
    char quiere_Entrenamiento, quiere_Clases;

    cout << "\nDesea entrenamiento personal? (s/n): ";
    cin >> quiere_Entrenamiento;

    if (quiere_Entrenamiento == 's' || quiere_Entrenamiento == 'S') {
        cout << "Ingrese la cantidad de sesiones para el entrenamiento personal: ";
        cin >> Sesiones;
    }
    else {
        Sesiones = 0;
    }

    cout << "Desea inscribirse en clases grupales? (s/n): ";
    cin >> quiere_Clases;

    if (quiere_Clases == 's' || quiere_Clases == 'S') {
        cout << "Ingrese la cantidad de clases en las que desea inscribirse: ";
        cin >> Cantidad_Clases;
    }
    else {
        Cantidad_Clases = 0;
    }

    double Costo_Total = Precio_Total(0, Sesiones, Cantidad_Clases);

    cout << "Costo total a pagar: $" << Costo_Total << endl;
    string quiere_Servicios, nombre, apellido;
    int codigo;

    cout << "Desea crear un perfil para futuras visitas? (S/N)";
    cin >> quiere_Servicios;
    if (quiere_Servicios == "s" || quiere_Servicios == "S") {
        system("CLS");

        cout << "Cree un perfil para guardar sus datos";
        cout << "Ingrese su nombre: ";
        cin >> nombre;
        cout << "Ingrese su apellido: ";
        cin >> apellido;
        cout << "Cree un codigo para acceder a su perfil: ";
        cin >> codigo;

        int codigo_Perfil;
        cout << "Ingrese su codigo:";
        cin >> codigo_Perfil;
        if (codigo_Perfil == codigo) {
            cout << "Bienvenid@ a su perfil\n";
            cout << "Su membresia incluye: " << MesesMembresia << "de uso en nuestras instalaciones por un costo de: " << Totalidad_1 << endl;
            cout << "Usted selecciono: " << Sesiones << "de clases por un precio de: " << Totalidad_2 << endl;



        }
    }
    return 0;
}
