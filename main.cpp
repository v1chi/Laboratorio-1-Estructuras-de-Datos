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
    //Si el usuario no tiene ningun software en su biblioteca se avisa por pantalla
    if(usuario->getSoftwares().empty()){
        cout << "No tiene softwares" << endl;
    }
    //Si tiene 1 o mas softwares en su biblioteca se muestran
    else{
        for(int i = 0; i < usuario->getSoftwares().size(); i++){
            cout << usuario->getSoftwares()[i]->toString() << endl;
        }
    }   
}

void agregarSoftware(User* usuario)
{
    //Se muestran los softwares que puede agregar
    cout << "Softwares que puede agregar a su biblioteca: " << endl;
    
    for(int i = 0; i < biblioteca.size(); i++){
        //Si es un software de seguridad hay que revisar si el usuario es administrador
        if(typeid(*biblioteca[i]) == typeid(Security)){
            //Si el usuario es administrador(es decir, tiene acceso al log) entonces se muestra el software de tipo Seguridad
            if(usuario->getLog()){
                cout << "ID del software: " << i << ": " << biblioteca[i]->toString() << endl;
            }
        }
        //Si el software es de otro tipo distinto de Seguridad
        else{
            //Si el usuario es niño/menor de edad, se muestr el software solo si es apto para menores de edad
            if(usuario->getAge() < 18 && usuario->getAge() > -1){
                if(biblioteca[i]->isForUnderage()){
                    cout << "ID del software: " << i << ": " << biblioteca[i]->toString() << endl;
                }
            //Si el usuario es de tipo normal, se muestra el software
            }else{
                cout << "ID del software: " << i << ": " << biblioteca[i]->toString() << endl;
            }
        }
    }

    //Preguntar por el ID del software que desea agregar
    int posicionSoftware;
    cout << "Ingrese el ID del software que desea agregar a su biblioteca" << endl;
    cin >> posicionSoftware;

    //Se crea la variable "agregar" para corroborar de que el software que desea agregar el usuario a su biblioteca existe
    Software* agregar = nullptr;
    agregar = biblioteca[posicionSoftware];
    if(agregar != nullptr){
        //Se agrega el software a la lista de softwares del usario, ademas se agrega el usuario a la lista de usuarios que usan el software
        usuario->addSoftware(biblioteca[posicionSoftware]);
        biblioteca[posicionSoftware]->addUser(usuario->getUsername());
        cout << "Software agregado con exito" << endl;
    }else{
        cout << "No se pudo agregar el software" << endl;
    }
}

void eliminarSoftware(Software* eliminar)
{
    //Si el software a eliminar no tiene ningun usuario que lo use entonces se elimina
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
    //Si hay 1 o mas personas que este/n usando el software entonces no se puede eliminar
    else{
        cout << "No se puede eliminar, se necesita el permiso de los demas usuarios" << endl;
    }
}

void eliminarMiSoftware(User* usuario)
{   
    //Si el usuario no tiene ningun software, se le notifica
    if(usuario->getSoftwares().size()==0){
        cout << "No hay softwares para eliminar" << endl;
        return;
    }

    //Si el usuario tiene 1 o mas softwares, se muestran
    int softwareEliminar;
    cout << "Mis Softwares" << endl;
    for(int i = 0; i < usuario->getSoftwares().size(); i++){
        cout << "ID del software: " << i << ": "<< usuario->getSoftwares()[i]->toString() << endl;
    }
    
    //Se pregunta por el ID del software que desea eliminar
    cout << "Ingrese el ID del software que desea eliminar" << endl;
    cin >> softwareEliminar;
    Software* eliminar = usuario->getSoftwares()[softwareEliminar];
    //Se elimina el software de la biblioteca del usuario
    usuario->deleteSoftware(softwareEliminar);
    //Se elimina el usuario de la lista de usuarios que usan el software
    eliminar->deleteUser(usuario->getUsername());


    //Se pregunta si se desea eliminar el software de la biblioteca general
    cout << "Desea eliminar el software de la biblioteca?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int deseaEliminar;
    cin >> deseaEliminar;
    switch(deseaEliminar)
    {
        case 1:
            //Se intenta eliminar el software de la biblioteca general
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
    
//Creacion de usuarios y agregarlos a la lista de usuarios general
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


//Creacion de softwares y agregarlos a la biblioteca
    //Juegos
    Game game1("CSGO","Valve", 145, false, "FPS");
    Game game2("COD: Warzone","Infinity Ward", 379, false, "FPS");
    Game game3("WOW","BLIZZARD",386, true, "MMO");
    Game game4("Final Fantasy XIV","SQUARE ENIX",7439, true, "MMO");
    Game game5("Portal","Valve",74829, true, "PUZZLE");
    Game game6("Candy Crush","King",74390, true, "PUZZLE");
    Game game7("Minecraft","Mojang Studios",5672, true, "Sandbox");
    Game game8("Terraria","ReLogic",3478, true, "Sandbox");
    Game game9("The Witcher 3","CD",289, false, "RPG");
    Game game10("Skyrim","Bethesda",30, true, "RPG");
    Game game11("FIFA 22","EA",62, true, "Deportes");
    Game game12("Rocket League","Psyonix",4278, true, "Deportes");
    Game game13("Civilization VI","Firaxis",23, true, "Estrategia");
    Game game14("AOE II","Forgotten",432, true, "Estrategia");
    Game game15("Hollow Knight","Team Cherry",635, true, "Plataformas");
    Game game16("Celeste","Maddy Makes Games",432, true, "Plataformas");
    Game game17("Stardew Valley","ConcernedAge",677, true, "Simulacion");
    Game game18("The Sims 4","Maxis",345, true, "Simulacion");
    Game game19("GTA V","Rockstar",3444, false, "Accion");
    Game game20("Dark Souls III","FromSoftware",754, false, "Accion");
    biblioteca.push_back(&game1);
    biblioteca.push_back(&game2);
    biblioteca.push_back(&game3);
    biblioteca.push_back(&game4);
    biblioteca.push_back(&game5);
    biblioteca.push_back(&game6);
    biblioteca.push_back(&game7);
    biblioteca.push_back(&game8);
    biblioteca.push_back(&game9);
    biblioteca.push_back(&game10);
    biblioteca.push_back(&game11);
    biblioteca.push_back(&game12);
    biblioteca.push_back(&game13);
    biblioteca.push_back(&game14);
    biblioteca.push_back(&game15);
    biblioteca.push_back(&game16);
    biblioteca.push_back(&game17);
    biblioteca.push_back(&game18);
    biblioteca.push_back(&game19);
    biblioteca.push_back(&game20);
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