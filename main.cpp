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

User buscarUsuario(string nombreusuario, vector<User> usuarios)
{
    //Buscar en la lista general de usuarios para ver si existe y lo retorna
    Usuario u;
    for(int i=0; i < usuarios.size(); i++){
        if(usuarios[i].getUsername() == nombreusuario){
            u = usuarios[i];
        }
    }
    return u;
}

bool usuarioCorrecto(string nombreusuario, string contrasena, vector<User> usuarios)
{
    //Verifica si la contraseña es la adecuada para el usuario
    for(int i=0; i < usuarios.size(); i++){
        if(usuarios[i].getUsername() == nombreusuario){
            if(usuarios[i].getPassword() == contrasena){
                cout << "Acceso exitoso" << endl;
                return true;
            }
        }
    }
    cout << "Usuario o contrasena incorrectas" << endl;
    return false;
}

void verMisSoftwares(User usuario)
{
    //Muestra todos los softwares en la biblioteca del  usuario
    cout << "Mis Software: " << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < usuario.getSoftwares()[i].size(); j++){
            cout << usuario.getSoftwares()[i][j].toString() << endl;
        }
    }
}

void agregarSoftware(User usuario, vector<vector<Software>> biblioteca)
{
    //Muestra todos los softwares de la biblioteca general de softwares
    cout << "Todos los softwares: " << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < biblioteca[i].size(); j++){
            cout << biblioteca[i][j].toString() << endl;
        }
    }

    //El usuario ingresa el nombre dle software que desea agregar, se busca en la biblioteca general y si lo encuentra lo agrega a la biblioteca de softwares del usuario
    string softwareAgregar;
    cout << "Ingrese el nombre del software que desea agregar" << endl;
    cin >> softwareAgregar;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < biblioteca[i].size(); j++){
            if(biblioteca[i][j].getName() == softwareAgregar){
                usuario.getSoftwares()[i].push_back(biblioteca[i][j]);
                cout << "Software agregado con exito" << endl;
                break;
            }
        }
    }
    cout << "No se pudo encontrar el software" << endl;

}

void eliminarMiSoftware(User usuario)
{   
    //Pregunta al usuario por el software que desea eliminar de su biblioteca, y si lo encuentra lo elimina
    string softwareEliminar;
    cout << "Ingrese el nombre del software que desea eliminar de su cuenta" << endl;
    cin >> softwareEliminar;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < usuario.getSoftwares()[i].size(); j++){
            if(usuario.getSoftwares()[i][j].getName() == softwareEliminar){
                erase(usuario.getSoftwares()[i].begin(),usuario.getSoftwares()[i].begin()+i);
                cout << "Software eliminado con exito" << endl;
                break;
            }
        }
    }
    cout << "No se pudo eliminar el software" << endl;
}
/*
void verHistorial(User usuario)
{
    //Se pide el nombre del navegador del usuario al cual le desea ver el historial, si se encuentra se hace una especie de casteo
    //para acceder al metodo que muestra el historial
    if(usuario.getSoftwares()[2].size() != 0){
        
        string nav;
        cout << "Ingrese el nombre del navegador del cual desea ver el historial" << endl;
        cin >> nav;
        for(int i = 0; i < usuario.getSoftwares()[2].size(); i++){
            if(usuario.getSoftwares()[2][i].getName() == nav){
                //Navegation n = usuario.getSoftwares()[2][i];
                Software* s = dynamic_cast<Software*>(usuario.getSoftwares())[2][i].seeHistorial());
                break;
            }
        }
    }
}

void agregarHistorial(User usuario)
{
    //Se pide el nombre del navegador del usuario al cual le desea agregar una url al historial, si se encuentra se hace una especie de casteo
    //para acceder al metodo que muestra el historial
    string navSoftware;
    string newUrl;
    cout << "Ingrese el nombre del software que desea agregar" << endl;
    cin >> navSoftware;
    cout << "Ingrese el url a agregar" << endl;
    cin >> newUrl;

    for(int i = 0; i < usuario.getSoftwares()[2].size(); i++){
            if(usuario.getSoftwares()[2][i].getName() == navSoftware){
                Navegation n = usuario.getSoftwares()[2][i];
                n.addPage(url);
                break;
            }
        }

    cout << "No se pudo encontrar el software" << endl;
}

void crearArchivo(User usuario)
{
    // se le pide al usuario el software en donde desea agregar un archivo, si lo encuentra se agrega uno mas a este exitosamente
    string softwareOffice;
    cout << "Ingrese el nombre del software en el cual desea agregar un archivo" << endl;
    cin >> softwareOffice;

    for(int i = 0; i < usuario.getSoftwares()[1].size(); i++){
            if(usuario.getSoftwares()[1][i].getName() == navSoftware){
                OfficeAutomation a = usuario.getSoftwares()[1][i];
                a.createFile();
                return;
            }
        }
    cout << "No se pudo encontrar el software" << endl;
}

void borrarArchivo(User usuario)
{
    //se le pide al usuario el nombre dle software en donde quiere borrar un archivo, si se encuentyra el software entonces se bora un archivo
    string softwareOffice;
    cout << "Ingrese el nombre del software en el cual desea eliminar un archivo" << endl;
    cin >> softwareOffice;

    for(int i = 0; i < usuario.getSoftwares()[1].size(); i++){
            if(usuario.getSoftwares()[1][i].getName() == softwareOffice){
                OfficeAutomation a = usuario.getSoftwares()[1][i];
                a.deleteFile();
                break;
            }
        }
    cout << "No se pudo encontrar el software" << endl;
}

void agregarAmigo(User usuario,  vector<User> usuarios)
{
    string nombreSocial;
    cout << "Ingrese el nombre del software social en donde desee agregar el usuario: " << endl;
    cin >> nombreSocial;
    Social s(NULL, NULL, 0, false);
    for(int i = 0; i < usuario.getSoftwares()[1].size(); i++){
            if(usuario.getSoftwares()[5][i].getName() == nombreSocial){
                s = usuario.getSoftwares()[5][i];
                break;
            }  
    }
    if(s.getName() == NULL){
        cout << "No se encontro el software" << endl;
        return;
    }

    string newFriend;
    cout << "Ingrese el nombre del usuario que desea agregar: " << endl;
    cin >> newFriend;
    
    if(friend.getAge() >= 18 || friend.getAge() == -1){
        if(this->getAge() >= 18 || this->getAge() == -1){
            this->friends.push_back(friend);
            cout << "Se agrego el nuevo amigo" << endl;
        }
        else{
            cout << "Un niño no puede tener como amigo a un adulto o a un administrador" << endl;
        }
    }
    else if(friend.getAge() < 18 || friend.getAge() >= 0){
        if(this->getAge() < 18 || this->getAge() >= 0){
            this->friends.push_back(friend);
            cout << "Se agrego el nuevo amigo" << endl;
        }
        else{
            cout << "Un niño no puede tener como amigo a un adulto o a un administrador" << endl;
        }
    }

    User friend = buscarUsuario(newFriend, usuarios);
    if(friend.getName() != NULL){
        s.addFriend(friend);
        return;
    }

}
*/
void sesionUsuario(User usuario, vector<User> usuarios, vector<vector<Software>> biblioteca, bool sesion)
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
    cout << "9. Agregar un amigo" << endl;;
    cout << "10. Cerrar sesión" << endl;

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
        //eliminar un software de la biblioteca general de softwares
            cout << "Aun no contamos con esta opcion :(" << endl;
            break;
        case 5:
        //ver historial de navegacion del usuario
            verHistorial(usuario);
            break;
        case 6:
        //agregar historial de navegacion al usuario
            agregarHistorial(usuario);
            break;
        case 7:
        //crear un archivo en un software de ofimatica
            crearArchivo(usuario);
            break;
        case 8:
        //borrar un archivo de un software de ofimatica
            borrarArchivo(usuario);
            break;
        case 9:
        //agregar amigo en software social al usuario
            agregarAmigo(usuario, usuarios);
            break;
        case 10:
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

    //Verificar si existe el usuario y la contraseña del usuario
    if(usuarioCorrecto(nombreusuario, contrasena, usuarios))
    {   
        //Buscar usuario en lista de usuarios generales
        User usuario = buscarUsuario(nombreusuario, usuarios);

        //acceder menu principal
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

//creacion de usuarios: (username,password,age,mail,bool log)
    User adm1("adminav1", "123abc", -1, "123@gmail.com", true);
    User child1("nino1", "123abc", 10, NULL, false);
    User child2("nino2", "hsakw", 5, NULL, false);
    User child3("nino3", "83ru2", 14, NULL, false);
    User child4("nino4", "iosh", 17, NULL, false);
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

    //Lista de softwares y usuarios del sistema interno
    vector<vector<Software>> biblioteca{{game1, game2}, {of1, of2, of3, of4, of5}, {nav1, nav2}, {prod1, prod2, prod3, prod4}, {sec1, sec2, sec3, sec4, sec5, sec6}, {soc1,soc2}};
    vector<User> usuarios{adm1, child1, child2, child3, child4, normal1, normal2, normal3, normal4, normal5, normal6, normal7, normal8, normal9, normal10};

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