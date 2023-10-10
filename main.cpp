#include <bits/stdc++.h>
#include <string>
#include "User.h"
#include "Software.h"
#include "Game.h"
#include "OfficeAutomation.h"
#include "Navegation.h"
#include "Production.h"
#include "Security.h"
#include "Social.h"
using namespace std;



void verMisSoftwares(User* usuario)
{

}

void agregarSoftware(User* usuario, vector<Software*> biblioteca)
{

}

void eliminarMiSoftware(User* usuario)
{   

}

void sesionUsuario(User* usuario, vector<User*> usuarios, vector<Software*> biblioteca, bool sesion)
{
    cout << "------------------------------MENU------------------------------" << endl;
    cout << "Ingrese una opcion" << endl;
    cout << "1. Ver mis softwares" << endl;
    cout << "2. Agregar un software a mi biblioteca" << endl;
    cout << "3. Eliminar un software de mi biblioteca" << endl;
    cout << "4. Cerrar sesión" << endl;

    int opcionAdmin;
    cin >> opcionAdmin;

    switch(opcionAdmin)
    {
        case 1:
        //Acceder a biblioteca de softwares del usuario
            verMisSoftwares(usuario);
            break;
        case 2:
        //agregar un software a la biblioteca del usuario
            agregarSoftware(usuario, biblioteca);
            break;
        case 3:
        //eliminar un software de la biblioteca del usuario
            eliminarMiSoftware(usuario);
            break;
        case 4:
            sesion = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

void menuUsuario(vector<User*> usuarios, vector<Software*> biblioteca)
{
    User* usuarioActual = nullptr;
    string nombreusuario;
    string contrasena;

    //Preguntar por el nombre de usuario y la contraseña     
    cout << "Ingrese su nombre de usuario: " << endl;
    cin >> nombreusuario;
    cout << "Ingrese su contrasena: " << endl;
    cin >> contrasena;

    //Buscar en la lista de usuarios
    for(int i = 0; i < usuarios.size(); i++){
        //Si se encuentra el username
        if(usuarios[i]->getUsername() == nombreusuario){
            //Si la contraseña es la correcta para el username
            if(usuarios[i]->getPassword() == contrasena){
                usuarioActual = usuarios[i];
                break;
            }
        }
    }
    
    if(usuarioActual != nullptr){
        cout << "Sesion iniciada con exito" << endl;
        bool sesion = true;
        while(sesion){
            sesionUsuario(usuarioActual, usuarios, biblioteca, sesion);
        }
    }
    else{
        cout << "Usuario o contrasena incorrecta" << endl;
    }
}

int main(){

//Lista de softwares y usuarios del sistema interno
    vector<Software*> biblioteca;
    vector<User*> usuarios;

//Creacion de usuarios
    //Administrador
    User adm1("adminav1", "123abc", -1, "123@gmail.com", true);
    usuarios.push_back(&adm1);
    //Niño
    User child1("nino1", "123abc", 10, "", false);
    User child2("nino2", "hsakw", 5, "", false);
    User child3("nino3", "83ru2", 14, "", false);
    User child4("nino4", "iosh", 17, "", false);
    usuarios.push_back(&child1);
    usuarios.push_back(&child2);
    usuarios.push_back(&child3);
    usuarios.push_back(&child4);
    //Normal
    User normal1("normal1", "456def", 20 , "456@gmail.com", false);
    User normal2("normal2", "nrt", 40 , "asd@gmail.com", false);
    User normal3("normal3", "rtns", 19 , "qwe@gmail.com", false);
    User normal4("normal4", "thj", 57 , "ert@gmail.com", false);
    User normal5("normal5", "tr", 92 , "tgb@gmail.com", false);
    User normal6("normal6", "ytr", 50 , "hjn@gmail.com", false);
    User normal7("normal7", "fdf", 26 , "uio@gmail.com", false);
    User normal8("normal8", "wh45", 49 , "kjh@gmail.com", false);
    User normal9("normal9", "75u", 62 , "jnt@gmail.com", false);
    User normal10("normal10", "suj", 19 , "jko@gmail.com", false);
    usuarios.push_back(&normal1);
    usuarios.push_back(&normal2);
    usuarios.push_back(&normal3);
    usuarios.push_back(&normal4);
    usuarios.push_back(&normal5);
    usuarios.push_back(&normal6);
    usuarios.push_back(&normal7);
    usuarios.push_back(&normal8);
    usuarios.push_back(&normal9);
    usuarios.push_back(&normal10);


//Softwares
    //Juegos
    Game game1("CSGO","VALVE", 145, false, "FPS");
    Game game2("WOW","BLIZZARD",386, true, "MMO");
    //Ofimatica
    OfficeAutomation of1("ofimatica1","dev1",87, true);
    OfficeAutomation of2("ofimatica2","devof2",243, false);
    OfficeAutomation of3("ofimatica3","devof3",932, true);
    OfficeAutomation of4("ofimatica4","devof4",89230, false);
    OfficeAutomation of5("ofimatica5","devof5",823, true);
    //Navegacion
    Navegation nav1("nav1","devnav1",376, true);
    Navegation nav2("nav2","devnav2",500, false);
    //Produccion
    Production prod1("pro1", "devprod1", 4382, false, "musica");
    Production prod2("prod2","devprod2",237, false, "video");
    Production prod3("prod3","devprod3",3479, false, "streaming");
    Production prod4("prod4","devprod4",3412, false, "fotos");
    //Seguridad
    Security sec1("sec1","devsec1",7843, false, "troyanos");
    Security sec2("sec2","deevsec2",3672, false, "spyware");
    Security sec3("sec3","deevsec3",7834, false, "ransomware");
    Security sec4("sec4","deevsec4",4343, false, "botnets");
    Security sec5("sec5","deevsec5",89349, false, "rootkits");
    Security sec6("sec6","deevsec6",2784, false, "gusanos");
    //Social
    Social soc1("soc1","devsoc1",496, true);
    Social soc2("soc2","devsoc2",9034, false);

    //Comienzo del menú de usuario
    bool menu = true;
    do{

        int opcionMenu;
        cout << "Ingrese una opcion" << endl;
        cout << "1. Registrarse" << endl;
        cout << "2. Salir" << endl;
        cin >> opcionMenu;

        switch(opcionMenu)
        {
            case 1:
                //Acceder al menu
                menuUsuario(usuarios, biblioteca);
                break;       
            case 2:
                //Salir de la biblioteca
                cout << "Adios!" << endl;
                menu = false;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    }while(menu);

    return 0;
}