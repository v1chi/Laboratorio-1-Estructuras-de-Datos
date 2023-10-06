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

User* buscarUsuario(string nombreusuario, vector<User> usuarios)
{
    for(int i=0; i < usuarios.size(); i++){
        if(usuarios[i]->getUsername() == nombreusuario){
            return usuarios[i];
        }
    }
    cout << "No se encontro el usuario" << endl;
    return NULL;
}

bool usuarioCorrecto(User* usuario, string contrasena, vector<User> usuarios)
{
    if(usuario!=NULL){
        if(usuario->getPassword() == contrasena){
            return true;
        }
    }
    return false;
}

void verMisSoftwares(User* usuario)
{
    cout << "Mis Software: " << endl;
    for(int i = 0; i < usuario->getSoftwares().size(); i++){
        cout << usuario->getSoftwares()[i].toString() << endl;
    }
}

void agregarSoftware(User* usuario, vector<Software> biblioteca)
{

}

void sesionAdmin(User* usuario, vector<User> usuarios, vector<Software> biblioteca, bool sesion)
{
    cout << "------------------------------MENU------------------------------" << endl;
    cout << "Ingrese una opcion" << endl;
    cout << "1. Ver mis softwares" << endl;
    cout << "2. Agregar un software a mi biblioteca" << endl;
    cout << "3. Eliminar un software de mi biblioteca" << endl;
    cout << "4. Eliminar un software de la biblioteca general" << endl;
    cout << "5. Ver mi historial" << endl;
    cout << "6. Crear un archivo" << endl;
    cout << "7. Eliminar un archivo" << endl;
    cout << "8. Agregar un amigo" << endl;
    cout << "9. Eliminar un amigo" << endl;
    cout << "10. Acceder al log de los software" << endl;
    cout << "11. Cerrar sesión" << endl;

    int opcionAdmin;
    cin >> opcionAdmin;

    switch(opcionAdmin)
    {
        case 1:
            verMisSoftwares(usuario);
            break;
        case 2:
            agregarSoftware(usuario, biblioteca);
            break;
        case 3:
            eliminarMiSoftware(usuario, biblioteca);
            break;
        case 4:

            break;
        case 5:
            verHistorial(usuario);
            break;
        case 6:
            crearArchivo(usuario);
            break;
        case 7:
            borrarArchivo(usuario);
            break;
        case 8:
            agregarAmigo(usuario, usuarios);
            break;
        case 9:
            eliminarAmigo(usuario, usuarios);
            break;
        case 10:
            log(biblioteca, usuarios);
            break;
        case 11:
            sesion = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

void sesionNormal(User* usuario, vector<User> usuarios, vector<Software> biblioteca, bool sesion)
{
    cout << "MENU" << endl;
    cout << "Ingrese una opcion" << endl;
    cout << "2. Ver mis software" << endl;
    cout << "2. Agregar un software a mi biblioteca" << endl;
    cout << "3. Eliminar un software de mi biblioteca" << endl;
    cout << "4. Eliminar un software de la biblioteca general" << endl;
    cout << "5. Ver mi historial" << endl;
    cout << "6. Crear un archivo" << endl;
    cout << "7. Eliminar un archivo" << endl;
    cout << "8. Agregar un amigo" << endl;
    cout << "9. Eliminar un amigo" << endl;
    cout << "10. Cerrar sesión" << endl;

    int opcionUser;
    cin >> opcionUser;

    switch(opcionUser)
    {
        case 1:
            verMisSoftwares(usuario);
            break;
        case 2:
            agregarSoftware(usuario, biblioteca);
            break;
        case 3:
            eliminarMiSoftware(usuario, biblioteca);
            break;
        case 4:

            break;
        case 5:
            verHistorial(usuario);
            break;
        case 6:
            crearArchivo(usuario);
            break;
        case 7:
            borrarArchivo(usuario);
            break;
        case 8:
            agregarAmigo(usuario, usuarios);
            break;
        case 9:
            eliminarAmigo(usuario, usuarios);
            break;
        case 10:
            sesion = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}
void menuUsuario(vector<User> usuarios, vector<Software> biblioteca)
{
    string nombreusuario;
    string contrasena;

    //Preguntar por el nombre de usuario y la contraseña     
    cout << "Ingrese su nombre de usuario: " << endl;
    cin >> nombreusuario;
    cout << "Ingrese su contrasena: " << endl;
    cin >> contrasena;

    //Verificar si existe el usuario
    User* usuario = buscarUsuario(nombreusuario, usuarios);

    //Verificar contraseña del usuario
    if(usuarioCorrecto(usuario, contrasena, usuarios))
    {
        bool sesion = true;
        while(sesion)
        {
            if(usuario->getLog()){sesionAdmin(usuario, usuarios, biblioteca, sesion);}
            else{sesionNormal(usuario, usuarios, biblioteca, sesion);}

        }
    }
    else{
        cout << "Contrasena o usuario incorrecto" << endl; 
    }
}

int main(){

//Usuarios: (username,password,age,mail,bool log)
    User adm1("adminav1", "123abc", -1, "123@gmail.com", true);
    User child1("nino1", "123abc", 10, NULL, false);
    User normal1("normal1", "456def", 20 , "456@gmail.com", true);

//Softwares
    //Juegos
    Game game1("CSGO","VALVE", 145, false, "FPS");
    Game game2("WOW","BLIZZARD",386, true, "MMO");
    //Ofimatica
    OfficeAutomation of1("ofimatica1","dev1",87, true);
    OfficeAutomation of2("ofimatica2","devof2",1497, false);
    //Navegacion
    Navegation nav1("nav1","devnav1",376, true);
    Navegation nav2("nav2","devnav2",500, false);
    //Produccion
    Production prod1("pro1", "devprod1", 4382, true, "musica");
    Production prod2("prod2","devprod2",237, false, "video");
    //Seguridad
    Security sec1("sec1","devsec1",7843, false, "malware");
    Security sec2("sec2","deevsec2",3672, false, "spyware");
    //Social
    Social soc1("soc1","devsoc1",496, true);
    Social soc2("soc2","devsoc2",9034, false);

    //Lista de softwares y usuarios del sistema interno
    vector<Software> biblioteca{game1, game2, of1, of2, nav1, nav2, prod1, prod2, sec1, sec2, soc1, soc2};
    vector<User> usuarios{adm1, child1, normal1};

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
                menuUsuario(usuarios, biblioteca);
                break;       
            case 2:
                menu = false;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    }while(menu);

    return 0;
}