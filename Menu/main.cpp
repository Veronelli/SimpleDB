#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <direct.h>

#define BACKGROUND_White 0xfff//Color blanco de fondo
#define FOREGROUND_White 0x000f//Color Blanco TEXT
#define BACKGROUND_BLACK 0x0043//Color negro fondo
#define BACKGROUND_Red 0x0020
#define FOREGROUND_gren 0x000a

using namespace std;

void programa_part2(string str_usu, string str_con);
void crear(string str_usu);



void QuitarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void MostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void login(string str_usu,string str_con);

void Bienvenida(){
int x=219;
int o=0;
cout<<"\n";
for(o;o<80;o++){
    cout<<char(x);
}
cout<<"\n\n\n";
cout<<"\n\n\t\t\t\t Cargando.";

for(o=0;o<10;o++){
        cout<<".";
        Sleep(100);
}
cout<<"\n\n\n\n\t\t\tPresione una tecla para continuar.\n\n\n\n\n\t\t\t\tBy:Facundo Veronelli\n\n\n\n\n\n\n";
for(o;o<90;o++){
    cout<<char(x);
}

getch();

}

void Crear(){

ifstream leer;
ofstream escribir;
cout<<"\nCreando User.txt\n";
escribir.open("User.txt",ios::out);

}

void registro(string str_usu, string str_con){

ofstream esc;
esc.open("User.txt",ios::app);
if(esc.is_open()){
	
	esc<<str_usu<<"\n"<<str_con<<"\n";
	
}else{
	cout<<"ERROR";
}

}

void pusqueda(string str_usu,string str_con,string &estado){
	
	ifstream leer;
	ofstream esc;
	string linea="";
	bool encon=true;
	
	leer.open("User.txt",ios::in);
	if(leer.is_open()){
		while(!leer.eof()||linea.length()!=0){
			
			getline(leer,linea);
			
			if(str_usu==linea)
			{
				estado="USUARIO EXISTENTE";
				encon=false;
			}
			linea="";
			getline(leer, linea);
			
		}
	if(encon==true){
		
		estado="USUARIO CREADO";
		registro(str_usu, str_con);
		system("cls");
		mkdir("C:/Users/Facundo-PC/Documents/Trabajos/C++/Menu/Base");
		str_usu="C:/Users/Facundo-PC/Documents/Trabajos/C++/Menu/Base/"+str_usu+".txt";
		cout<<"Creando directorio\n";
		esc.open(str_usu.c_str(),ios::out);
		esc.close();
		cout<<"Directorio creado\n";
		
	}
	}
	else{
		estado="Falta User";
	}
	leer.close();
	
}

void busqueda(string str_usu,string str_con,string &estado,bool &op){

    string linea="";
    string usu="";
    string con="";
    ifstream leer;
    leer.open("User.txt",ios::in);
    if(leer.is_open()){

            while(!leer.eof()||linea.length()!=0){
                linea="";
                getline(leer,linea);

                if(str_usu==linea){

                    linea="";
                    getline(leer,linea);
                    if(str_con==linea){
                        op=true;
                        cout<<"Correcto"<<endl<<" \n\n\t   ";
                        system("pause");
                        login(str_usu,str_con);
                    }
                }
                linea="";
                getline(leer,linea);

    }
    }
    else{
    estado="Error de archivo:falta User.txt";
    }
    if(op==false){
        estado="No se pudo ingresar";
    }
    op=false;
}

void Registrarse(string str_usu,string str_con,int Enter,int Arriba,int abajo,string tipo);

void Programa(){

int  Enter = 13;
int Arriba= 72;//Arriba
int abajo= 80;//Abajo
char key;
int apuntador=0;
string str_usu="_________";
string str_con="_________";
int indice1 =0;
string tipo="";
bool alta=false;
string estado="";
bool op=false;

while(1){
QuitarCursor();
cout<<"\n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_INTENSITY);
cout<<"\t\t\t\tMi Fichero\t\t\t\t\t\n\n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);


 if(key==char(Arriba)){
    apuntador=apuntador-1;
 }
 if(key==char(abajo)){

    apuntador=apuntador+1;
 }

 if(apuntador==-1){
    apuntador=3;
 }
 if(apuntador==4){
    apuntador=0;
 }
cout<<"\t\t\t";

//Usuario
if(apuntador==0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Input";

}
cout<<" User:    ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
cout<<str_usu<<"\n";
cout<<"\t\t\t";

//Contraseña
if(apuntador==1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
        tipo="Input";

}
cout<<" Password: ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
cout<<str_con<<"\n";
cout<<"\t\t\t";

//Aceptar
if(apuntador==2){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Botton";
}
cout<<" Log       \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);

cout<<"\t\t\t";
if(apuntador==3){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
    cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Botton";
}

cout<<" Register  \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);


cout<<"\n\n\n________________________________________________________________________________\n\tTipo: "<<tipo<<"  Opcion: "<<apuntador+1<<"  "<<estado;
  key=getch();

  if(key==char(Enter)){

    switch(apuntador){

    case 0:
        system("cls");
    MostrarCursor();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
            cout<<"Ingrese su Usuario: \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
            cin>>str_usu;

    break;

    case 1:
        system("cls");
        MostrarCursor();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
                    cout<<" ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
                    cout<<"Ingrese su Clave: \n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
                    cin>>str_con;

system("cls");
    break;

    case 2:

        busqueda(str_usu,str_con,estado,op);


    break;

    case 3:
        system("cls");

            Registrarse(str_usu,str_con,Enter,Arriba,abajo,tipo);

        system("cls");

        break;
    }

  }
system("cls");
}
}

void Registrarse(string str_usu,string str_con,int Enter,int Arriba,int abajo,string tipo){

char key;
int apuntador=0;
string estado="";
bool op=true;
ofstream leer;
leer.open("User.txt",ios::in);
if(leer.is_open()){

system("cls");



while(op==true){
        QuitarCursor();

cout<<"\n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_INTENSITY);
cout<<"\t\t\t\tRegister\t\t\t\t\t\n\n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);

 if(key==char(Arriba)){
    apuntador=apuntador-1;
 }
 if(key==char(abajo)){

    apuntador=apuntador+1;
 }

 if(apuntador==-1){
    apuntador=3;
 }
 if(apuntador==4){
    apuntador=0;
 }


//Usuario
cout<<"\t\t\t";
if(apuntador==0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Input";

}
cout<<" User:    ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
cout<<str_usu<<"\n";
cout<<"\t\t\t";

//Contraseña
if(apuntador==1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
        tipo="Input";

}
cout<<" Password: ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
cout<<str_con<<"\n";
cout<<"\t\t\t";

//Aceptar
if(apuntador==2){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Botton";
}
cout<<" Register     \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);

cout<<"\t\t\t";
if(apuntador==3){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Botton";
}
cout<<" Atras     \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);

cout<<"\n\n";
cout<<"\n\n\n________________________________________________________________________________\n\tTipo: "<<tipo<<"  Opcion: "<<apuntador+1<<"  "<<estado;


 key=getch();
system("cls");
if(key==char(Enter)){
    switch(apuntador){

case 0:

        MostrarCursor();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
            cout<<"Ingrese su Usuario: \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
            cin>>str_usu;
system("cls");

break;
case 1:
            system("cls");
        MostrarCursor();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
                    cout<<" ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
                    cout<<"Ingrese su Clave: \n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
                    cin>>str_con;

system("cls");

break;

case 2:
		if((str_usu==""||str_con=="")||(str_usu=="_________"||str_con=="_________")){
			cout<<"Error 002";
			Registrarse(str_usu,str_con,Enter,Arriba,abajo,tipo);
		}else{
		pusqueda(str_usu,str_con,estado);
		system("cls");
		}

	break;
	
case 3:

	Programa();

break;			
    }
    }

 }

}else{
cout<<"ERROR falta de archivo User\n";
}

}

int main()
{

QuitarCursor();

    ifstream leer;
    leer.open("User.txt",ios::in);

    Bienvenida();
    cout<<"Iniciando...\n";
    Sleep(200);

    if(leer.is_open()){
        cout<<"Carganedo User.txt";
        Sleep(200);
    }

    else{
        Crear();
    }

    leer.close();
    system("cls");
    Programa();


}




void login(string str_usu, string str_con){
	
	string txt;
	ifstream leer;
	
	txt= "Base/" + str_usu + ".txt";
	
	leer.open(txt.c_str(),ios::in);
	
	system("cls");
	cout<<"Iniciando..\n";
	cout<<"Buscarndo carpeta base..\n";
	if(leer.is_open()){
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_gren);
		cout<<"Usuario encontrado\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_White);
		system("pause");
		system("cls");
		
		programa_part2(str_usu,str_con);
	
	}
	else{
		
		cout<<"Error 002\n";
		system("pause");
		
	}
	
}

void programa_part2(string str_usu, string str_con){
	char car;
	string tipo ="Button";
	int op=0;
	string base;

	
	while(car!=char(13)){
		

	
		if(car==char(80)){
			
			op=op+1;
			
		}
		if(car==char(72)){
			
			op=op-1;
			
		}
		if(op==-1){
			
			op=1;
			
		}
		if(op==2){
			op=0;
		}

			cout<<"\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_INTENSITY);
	cout<<"\t\t\t\tBase++\t\t\t\t\t\t\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
	
		
	cout<<"\t\tUser: "<< str_usu<<" Tipe: "<<tipo<<"  Opcion: "<<op+1<<"\n\t\t\t\t";
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_INTENSITY);
	cout<<"   Menu   \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
		
	cout<<"\n\n\n\t\t";
	if(op==0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Botton";
    
}
cout<<"Crear     \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);

	cout<<"\t\t";

	if(op==1){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
    tipo="Botton";
    
}
cout<<"Abrir     \n";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
	
		cout<<"\n\n\n________________________________________________________________________________";
		
	car =getch();
	system("cls");
	

	
	}
	switch(op){
	
	case 0:
		
		        system("cls");
    MostrarCursor();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_White);
        cout<<" ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White|BACKGROUND_Red);
            cout<<"Ingrese nombre de la base de datos: \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_White);
            cin>>base;		
	QuitarCursor();
	crear(str_usu);
		
		break;
	case 1:
		
		
		
		break;
	
	}
	
	system ("pause");	
	
}

//Crear menu Crear tabla,Ver tablas,atras

void crear(string str_usu){
	
	
	
		char car;
	string tipo ="Button";
	int op=0;
	string base;

	
	while(car!=char(13)){
		

	
		if(car==char(80)){
			
			op=op+1;
			
		}
		if(car==char(72)){
			
			op=op-1;
			
		}
		if(op==-1){
			
			op=1;
			
		}
		if(op==2){
			op=0;
		}
 cout<<op;
	car =getch();
	system("cls");



}
}

