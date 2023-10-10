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

//Lista de softwares y usuarios del sistema interno
vector<Software*> biblioteca;
vector<User*> usuarios;

void verMisSoftwares(User* usuario)
{
    if(usuario->getSoftwares().empty()){
        cout << "No tiene softwares" << endl;
    }
    else{
        for(int i = 0; i < usuario->getSoftwares().size(); i++){
            cout << usuario->getSoftwares()[i]->toString() << endl;
        }
    }   
}

void agregarSoftware(User* usuario)
{
    cout << "Softwares que puede agregar a su biblioteca: " << endl;
    
    for(int i = 0; i < biblioteca.size(); i++){
        if(typeid(*biblioteca[i]) == typeid(Security)){
            if(usuario->getLog()){
                cout << "ID del software: " << i << ": " << biblioteca[i]->toString() << endl;
            }
        }
        else{
            if(usuario->getAge() < 18 && usuario->getAge() > -1){
                if(biblioteca[i]->isForUnderage()){
                    cout << "ID del software: " << i << ": " << biblioteca[i]->toString() << endl;
                }
            }else{
                cout << "ID del software: " << i << ": " << biblioteca[i]->toString() << endl;
            }
        }
    }

    //Preguntar por el software que desea agregar
    int posicionSoftware;
    cout << "Ingrese el ID del software que desea agregar a su biblioteca" << endl;
    cin >> posicionSoftware;

    //Se crea la variable "agregar" para corroborar de que el software que desea agregar el usuario a su biblioteca existe
    Software* agregar = nullptr;
    agregar = biblioteca[posicionSoftware];
    if(agregar != nullptr){
        usuario->addSoftware(biblioteca[posicionSoftware]);
        biblioteca[posicionSoftware]->addUser(usuario->getUsername());
        cout << "Software agregado con exito" << endl;
    }else{
        cout << "No se pudo agregar el software" << endl;
    }
}

void eliminarSoftware(Software* eliminar)
{
    if(eliminar->emptyUsers())
    {
        for(int i = 0; i < biblioteca.size(); i++){
            if(biblioteca[i]->getName() == eliminar->getName()){
                biblioteca.erase(biblioteca.begin()+i);
                cout << "Software eliminado" << endl;
                return;
            }
        }
    }
    else{
        cout << "No se puede eliminar, se necesita el permiso de los demas usuarios" << endl;
    }
}

void eliminarMiSoftware(User* usuario)
{   
    if(usuario->getSoftwares().size()==0){
        cout << "No hay softwares para eliminar" << endl;
        return;
    }

    int softwareEliminar;
    cout << "Mis Softwares" << endl;
    for(int i = 0; i < usuario->getSoftwares().size(); i++){
        cout << "ID del software: " << i << ": "<< usuario->getSoftwares()[i]->toString() << endl;
    }
    
    cout << "Ingrese el ID del software que desea eliminar" << endl;
    cin >> softwareEliminar;
    Software* eliminar = usuario->getSoftwares()[softwareEliminar];
    usuario->deleteSoftware(softwareEliminar);
    eliminar->deleteUser(usuario->getUsername());

    cout << "Desea eliminar el software de la biblioteca?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int deseaEliminar;
    cin >> deseaEliminar;
    switch(deseaEliminar)
    {
        case 1:
            eliminarSoftware(eliminar);
            break;
        case 2:
            break;
        default:
            break;
    }

}

void sesionUsuario(User* usuario, bool sesion, bool login)
{
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Ingrese una opcion" << endl;
    cout << "1. Ver mis softwares" << endl;
    cout << "2. Agregar un software a mi biblioteca" << endl;
    cout << "3. Eliminar un software de mi biblioteca" << endl;
    cout << "4. Cerrar sesion" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    int opcion;
    cin >> opcion;

    switch(opcion)
    {
        case 1:
            //Acceder a biblioteca de softwares del usuario
            verMisSoftwares(usuario);
            sesionUsuario(usuario, sesion, login);
            break;
        case 2:
            //Agregar un software a la biblioteca del usuario
            agregarSoftware(usuario);
            sesionUsuario(usuario, sesion, login);
            break;
        case 3:
            //Eliminar un software de la biblioteca del usuario o de la biblioteca general
            eliminarMiSoftware(usuario);
            sesionUsuario(usuario, sesion, login);
            break;
        case 4:
            sesion = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            sesion = false;
            break;
    }

}

User* iniciarSesion()
{
    //User* usuarioActual = nullptr;
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
            //Si la contraseña es la correcta para el username se retorna el usuario 
            if(usuarios[i]->getPassword() == contrasena){
                return usuarios[i];
            }
        }
    }
    //Si no se encuentra el usuario o la contraseña es incorrecta se retorna un puntero nulo
    cout << "Usuario o contrasena incorrecta" << endl;
    return nullptr;
    
}

int main(){
    
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


//Creacion de softwares
    //Juegos
    Game game1("CSGO","VALVE", 145, false, "FPS");
    Game game2("WOW","BLIZZARD",386, true, "MMO");
    biblioteca.push_back(&game1);
    biblioteca.push_back(&game2);
    //Ofimatica
    OfficeAutomation of1("ofimatica1","dev1",87, true);
    OfficeAutomation of2("ofimatica2","devof2",243, false);
    OfficeAutomation of3("ofimatica3","devof3",932, true);
    OfficeAutomation of4("ofimatica4","devof4",89230, false);
    OfficeAutomation of5("ofimatica5","devof5",823, true);
    biblioteca.push_back(&of1);
    biblioteca.push_back(&of2);
    biblioteca.push_back(&of3);
    biblioteca.push_back(&of4);
    biblioteca.push_back(&of5);
    //Navegacion
    Navegation nav1("nav1","devnav1",376, true);
    Navegation nav2("nav2","devnav2",500, false);
    biblioteca.push_back(&nav1);
    biblioteca.push_back(&nav2);
    //Produccion
    Production prod1("pro1", "devprod1", 4382, false, "musica");
    Production prod2("prod2","devprod2",237, false, "video");
    Production prod3("prod3","devprod3",3479, false, "streaming");
    Production prod4("prod4","devprod4",3412, false, "fotos");
    biblioteca.push_back(&prod1);
    biblioteca.push_back(&prod2);
    biblioteca.push_back(&prod3);
    biblioteca.push_back(&prod4);
    //Seguridad
    Security sec1("sec1","devsec1",7843, false, "troyanos");
    Security sec2("sec2","deevsec2",3672, false, "spyware");
    Security sec3("sec3","deevsec3",7834, false, "ransomware");
    Security sec4("sec4","deevsec4",4343, false, "botnets");
    Security sec5("sec5","deevsec5",89349, false, "rootkits");
    Security sec6("sec6","deevsec6",2784, false, "gusanos");
    biblioteca.push_back(&sec1);
    biblioteca.push_back(&sec2);
    biblioteca.push_back(&sec3);
    biblioteca.push_back(&sec4);
    biblioteca.push_back(&sec5);
    biblioteca.push_back(&sec6);
    //Social
    Social soc1("soc1","devsoc1",496, true);
    Social soc2("soc2","devsoc2",9034, false);
    biblioteca.push_back(&soc1);
    biblioteca.push_back(&soc2);

    //Boolenaos que van a permitirnos viajar entre el menu general y el menu de usuario
    bool login = true;
    bool sesion = true;

    //Comienzo del menú de usuario
    do{

        while(sesion){
            int opcionMenu;
            User* usuarioActual;
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Ingrese una opcion" << endl;
            cout << "1. Registrarse" << endl;
            cout << "2. Salir" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------" << endl;
            cin >> opcionMenu;

            switch(opcionMenu)
            {
                case 1:
                    //Se verifica que exista el nombre de usuario y que coincida su contraseña y luego de eso se accede al menu de usuario
                    usuarioActual = iniciarSesion();
                    if(usuarioActual != nullptr){
                        cout << "Sesion iniciada con exito" << endl;
                        sesionUsuario(usuarioActual, sesion, login);
                    }
                    break;       
                case 2:
                    //Salir de la sesion general
                    cout << "Adios!" << endl;
                    login = false;
                    sesion = false;
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
            }
        }

    }while(login);

    return 0;
}