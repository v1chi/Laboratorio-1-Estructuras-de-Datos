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
        if(usuarios[i].getUsername() == nombreusuario){
            return &usuarios[i];
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
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < usuario->getSoftwares()[i].size(); j++){
            cout << usuario->getSoftwares()[i][j]->toString() << endl;
        }
    }
}

void agregarSoftware(User* usuario, vector<vector<Software>> biblioteca)
{
    cout << "Todos los softwares: " << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < biblioteca[i].size(); j++){
            cout << biblioteca[i][j].toString() << endl;
        }
    }

    string softwareAgregar;
    cout << "Ingrese el nombre del software que desea agregar" << endl;
    cin >> softwareAgregar;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < biblioteca[i].size(); j++){
            if(biblioteca[i][j].getName() == softwareAgregar){
                usuario->getSoftwares()[i].push_back(biblioteca[i][j]);
                cout << "Software agregado con exito" << endl;
                break;
            }
        }
    }
    cout << "No se pudo encontrar el software" << endl;

}

void eliminarMiSoftware(User* usuario)
{
    string softwareEliminar;
    cout << "Ingrese el nombre del software que desea eliminar de su cuenta" << endl;
    cin >> softwareEliminar;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < usuario->getSoftwares()[i].size(); j++){
            if(usuario->getSoftwares()[i][j]->getName() == softwareEliminar){
                usuario->getSoftwares()[i].erase(usuario->getSoftwares()[i].begin(),usuario->getSoftwares()[i].begin()+i);
                cout << "Software eliminado con exito" << endl;
            break;
            }
        }
    }
    cout << "No se pudo eliminar el software" << endl;
}

void verHistorial(User* usuario)
{
    if(usuario->getSoftwares()[2].size() != 0){
        
        string nav;
        cout << "Ingrese el nombre del navegador del cual desea ver el historial" << endl;
        cin >> nav;
        for(int i = 0; i < usuario->getSoftwares()[2].size(); i++){
            if(usuario->getSoftwares()[2][i]->getName() == nav){
                Navegation n = usuario->getSoftwares()[2][i];
                n->seeHistorial();
                break;
            }
        }
    }
}

void agregarHistorial(User* usuario)
{

    string navSoftware;
    string newUrl;
    cout << "Ingrese el nombre del software que desea agregar" << endl;
    cin >> navSoftware;
    cout << "Ingrese el url a agregar" << endl;
    cin >> newUrl;

    for(int i = 0; i < usuario->getSoftwares()[2].size(); i++){
            if(usuario->getSoftwares()[2][i]->getName() == navSoftware){
                Navegation n = usuario->getSoftwares()[2][i];
                n->addPage(url);
                break;
            }
        }

    cout << "No se pudo encontrar el software" << endl;
}

void crearArchivo(User* usuario)
{
    string softwareOffice;
    cout << "Ingrese el nombre del software en el cual desea agregar un archivo" << endl;
    cin >> softwareOffice;

    for(int i = 0; i < usuario->getSoftwares()[1].size(); i++){
            if(usuario->getSoftwares()[1][i]->getName() == navSoftware){
                OfficeAutomation a = usuario->getSoftwares()[1][i];
                a->createFile();
                return;
            }
        }
    cout << "No se pudo encontrar el software" << endl;
}

void borrarArchivo(User* usuario)
{
    string softwareOffice;
    cout << "Ingrese el nombre del software en el cual desea eliminar un archivo" << endl;
    cin >> softwareOffice;

    for(int i = 0; i < usuario->getSoftwares()[1].size(); i++){
            if(usuario->getSoftwares()[1][i]->getName() == navSoftware){
                OfficeAutomation a = usuario->getSoftwares()[1][i];
                a->deleteFile();
                break;
            }
        }
    cout << "No se pudo encontrar el software" << endl;
}

void cantidadArchivos(User* usuario)
{
    string softwareOffice;
    cout << "Ingrese el nombre del software del cual desea saber la cantidad de archivos" << endl;
    cin >> softwareOffice;

    for(int i = 0; i < usuario->getSoftwares()[1].size(); i++){
            if(usuario->getSoftwares()[1][i]->getName() == navSoftware){
                OfficeAutomation a = usuario->getSoftwares()[1][i];
                a.getFileCount();
                break;
            }
        }
    cout << "No se pudo encontrar el software" << endl;
}

void agregarAmigo(User* usuario,  vector<User> usuarios)
{
    string nombreSocial;
    cout << "Ingrese el nombre del software social en donde desee agregar el usuario: " << endl;
    cin >> nombreSocial;
    Social s = NULL;
    for(int i = 0; i < usuario->getSoftwares()[1].size(); i++){
            if(usuario->getSoftwares()[5][i]->getName() == nombreSocial){
                s = usuario->getSoftwares()[5][i];
                break;
            }  
    }
    if(s == NULL){
        cout << "No se encontro el software" << endl;
        return;
    }

    string newFriend;
    cout << "Ingrese el nombre del usuario que desea agregar: " << endl;
    cin >> newFriend;
    User friend = NULL;

    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getUsername() ==  newFriend){
            cout << "Amigo encontrado" << endl;
            friend = usuarios[i];
            break;
        }
    }

    if(friend == NULL){
        cout << "Usuario no encontrado" << endl;
        return;
    }
    if(friend.getAge() >= 18 || friend.getAge() == -1){
        if(usuario->getAge() >= 18 || usuario->getAge() == -1){
            s.addFriend(newFriend);
            cout << "Se agrego el nuevo amigo" << endl;
        }
        else{
            cout << "Un niño no puede tener como amigo a un adulto o a un administrador" << endl;
        }
    }
    else if(friend.getAge() < 18 || friend.getAge() >= 0){
        if(usuario->getAge() < 18 || friend.getAge() >= 0){
            s.addFriend(newFriend);
            cout << "Se agrego el nuevo amigo" << endl;
        }
        else{
            cout << "Un niño no puede tener como amigo a un adulto o a un administrador" << endl;
        }
    }
}

void eliminarAmigo(User* usuario,  vector<User> usuarios)
{
    string nombreSocial;
    cout << "Ingrese el nombre del software social en donde desee eliminar el usuario: " << endl;
    cin >> nombreSocial;
    Social s = NULL;
    for(int i = 0; i < usuario->getSoftwares()[1].size(); i++){
            if(usuario->getSoftwares()[5][i]->getName() == nombreSocial){
                s = usuario->getSoftwares()[5][i];
                break;
            }  
    }
    if(s == NULL){
        cout << "No se encontro el software" << endl;
        return;
    }

    string newFriend;
    cout << "Ingrese el nombre del usuario que desea eliminar: " << endl;
    cin >> newFriend;
    User friend = NULL;
    int posicionFriend;

    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getUsername() ==  newFriend){
            cout << "Amigo encontrado" << endl;
            friend = usuarios[i];
            posicionFriend = i;
            break;
        }
    }

    erase(usuario->getSoftwares[5].begin(),usuario->getSoftwares[5].begin()+posicionFriend);
    cout << "Amigo eliminado" << endl;
}

void sesionUsuario(User* usuario, vector<User> usuarios, vector<vector<Software>> biblioteca, bool sesion)
{
    cout << "------------------------------MENU------------------------------" << endl;
    cout << "Ingrese una opcion" << endl;
    cout << "1. Ver mis softwares" << endl;
    cout << "2. Agregar un software a mi biblioteca" << endl;
    cout << "3. Eliminar un software de mi biblioteca" << endl;
    cout << "4. Eliminar un software de la biblioteca general" << endl;
    cout << "5. Ver mi historial" << endl;
    cout << "6. Agregar pagina a historial" << endl;
    cout << "7. Crear un archivo" << endl;
    cout << "8. Eliminar un archivo" << endl;
    cout << "9. Ver cantidad de archivos" << endl;
    cout << "10. Agregar un amigo" << endl;
    cout << "11. Eliminar un amigo" << endl;
    cout << "12. Cerrar sesión" << endl;

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
            eliminarMiSoftware(usuario);
            break;
        case 4:
            cout << "Aun no contamos con esta opcion :(" << endl;
            break;
        case 5:
            verHistorial(usuario);
            break;
        case 6:
            agregarHistorial(usuario);
            break;
        case 7:
            crearArchivo(usuario);
            break;
        case 8:
            borrarArchivo(usuario);
            break;
        case 9:
            cantidadArchivos(usuario);
            break;
        case 10:
            agregarAmigo(usuario, usuarios);
            break;
        case 11:
            eliminarAmigo(usuario, usuarios);
            break;
        case 12:
            sesion = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

void menuUsuario(vector<User> usuarios, vector<vector<Software>> biblioteca)
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
            sesionUsuario(usuario, usuarios, biblioteca, sesion);
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
    vector<vector<Software>> biblioteca{{game1, game2}, {of1, of2}, {nav1, nav2}, {prod1, prod2}, {sec1, sec2}, {soc1,soc2}};
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