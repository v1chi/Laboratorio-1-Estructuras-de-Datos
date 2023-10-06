#include <bits/stdc++.h>
#include <string>
#include "Software.h"
#include "User.h"
#include "Game.h"
#include "OfficeAutomation.h"
#include "Navegation.h"
#include "Production.h"
#include "Security.h"
#include "Social.h"
using namespace std;

User* buscarUsuario(string nombreusuario)
{

    return NULL;
}

bool usuarioCorrecto(User* usuario, string contrasena)
{

    return false;
}

void sesionAdmin(User* usuario)
{

}

void sesionNormal(User* usuario)
{

}

int main(){

//Usuarios: (username,password,age,mail,bool log)
    User adm1("adminav1", "123abc", NULL, "123@gmail.com", true);
    User child1("nino1", "123abc", 10, NULL, false);
    User normal1("normal1", "456def", 20 , "456@gmail.com", true);

//Softwares
    //Juegos
    Game game1("CSGO","VALVE", 145, "FPS");
    Game game2("WOW","BLIZZARD",386,"MMO");
    //Ofimatica
    OfficeAutomation of1("ofimatica1","dev1",87);
    OfficeAutomation of2("ofimatica2","devof2",1497);
    //Navegacion
    Navegation nav1("nav1","devnav1",376);
    Navegation nav2("nav2","devnav2",500);
    //Produccion
    Production prod1("pro1", "devprod1", 4382, "musica");
    Production prod2("prod2","devprod2",237,"video");
    //Seguridad
    Security sec1("sec1","devsec1",7843,"malware");
    Security sec2("sec2","deevsec2",3672,"spyware");
    //Social
    Social soc1("soc1","devsoc1",496);
    Social soc2("soc2","devsoc2",9034);

    //Lista de softwares y usuarios del sistema interno
    vector<Software> biblioteca{game1, game2, of1, of2, nav1, nav2, prod1, prod2, sec1, sec2, soc1, soc2};
    vector<User> usuarios{adm1, child1, normal1};

    //Comienzo del menú de usuario
    bool menu = true;
    do{

        cout << "Ingrese una opcion" << endl;
        cout << "1.Registrarse" << endl;
        cout << "2.Salir" << endl;
        int opcionMenu;
        cin >> opcionMenu;

        string nombreusuario;
        string contrasena;
        switch(opcionMenu)
        {
            case 1:
                //Preguntar por el nombre de usuario y la contraseña
                
                cout << "Ingrese su nombg++re de usuario: " << endl;
                cin >> nombreusuario;
                cout << "Ingrese su contrasena: " << endl;
                cin >> contrasena;

                //Verificar si existe el usuario
                User* usuario = buscarUsuario(nombreusuario);

                //Verificar contraseña del usuario
                if(usuarioCorrecto(usuario,contrasena))
                {
                    bool sesion = true;
                    while(sesion)
                    {
                        if(usuario->getLog()){sesionAdmin(usuario);}
                        else{sesionNormal(usuario);}

                    }
                }
                  
                break;
            
            case 2:
                menu = false;
                break;
        }


    }while(menu);



    return 0;
}