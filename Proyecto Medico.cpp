/*

	Proyecto Medico

*/



// incluimos las variables
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>


// asingamos los nombres de espacios
using namespace std;


//Declararan las variables y inicalizando las con nombres

float codigo=0, auxcodigo=0;   //Inicializamos la varaible de tipo int

string nombre, auxnombre, sala, edad;  // Inicializamos la variable string



char telefono[30]; //Declaramanos cuantos caracteres maximos podes incluir

char nodo;

bool encontrado = false;  //Declaramos si no cumple la condicion nos retorna a falso



void registro_pacientes()
{
	
					//*******************************************************
					//				Registro de Pacientes				    *		
					//*******************************************************
	
    ofstream escritura;  // Estas son las Variables de la biblicoteca fstream para incluir los archivos a nuestra carpeta
    ifstream consulta;

    do{
    escritura.open("REGISTRO_PACIENTE.txt", ios::out | ios::app);  // Indicamos El Nombre nuestro archivo de texto
    consulta.open("REGISTRO_PACIENTE.txt", ios::in);

    if (escritura.is_open() && consulta.is_open()){


            bool repetido=false;

            
            cout<<endl<<"\tINGRESE UN CODIGO DEL PACIENTE : ";cin>>auxcodigo;
            
            // Declaramos el tipo de lectura que tendra nuestro archivo
            
            consulta>>codigo;
            while (!consulta.eof()){
                consulta>>nombre>>sala>>telefono>>edad;
                if (auxcodigo==codigo){
                    cout<<"\t\tCLAVE EXISTENTE...\n";
                    repetido=true;
                    break;
                }
                	consulta>>codigo;
            }

           	if (repetido==false){ // 
           		
               	 	cout<<"\tINGRESE EL NOMBRE EL PACIENTE  : ";
                	cin>>nombre;
                	
               	 	cout<<"\tINGRESE LA SALA DEL PACIENTE   : ";
               		cin>>sala;
               		
                	cout<<"\tINGRESE EL NUMERO DE TELEFONO  : ";
                	cin>>telefono;
                	
                	cout<<"\tINGRESE LA  DIRECCION          : "; cin>>edad;
                	
                
                //AGRENDANDO LOS DATOS DEL PACIENTE PARA GUARDAR EN EL ARCHIVO PACIENTES
                
                
                escritura<<auxcodigo<<" "<<nombre<<" "<<sala<<" "<<telefono<<" "<<edad<<endl;
                cout<<"\n\t AGREGANDO PACIENTE...\n";
            }

            cout<<"\n\tINGRESE SIGUIENTE PACIENTE? [S/N]: ";cin>>nodo;
            

    }
	else{
        cout<<" ARCHIVO CORRUPTO NO SE PUEDE ABRIR... \n";
    }

    escritura.close();
    consulta.close();

    }while (nodo=='S' or nodo=='s');

}


		//*******************************************************
		//				Eliminar   Pacientes				    *		
		//*******************************************************

void eliminar_pacientes()
{
    ofstream aux;  ifstream lectura;
    
    encontrado=false;

    aux.open("REGISTRO_PACIENTE", ios::out);
   			 lectura.open("REGISTRO_PACIENTE", ios::in);

    if (aux.is_open() && lectura.is_open()){

        
        cout<<endl<<"\tINGRESA EL CODIGO DEL PACIENTE QUE DESEAS ELILIMAR: ";
        cin>>auxcodigo;
            
            ///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
            ///hasta llegar al final del archivo gracias a la funciÃ³n .eof()
            lectura>>codigo;
            while (!lectura.eof()){
                lectura>>nombre>>sala>>telefono>>edad;
                
                if (auxcodigo==codigo){
                	
                        encontrado=true;
                        cout<<"\n";
                        cout<<"\tCODIGO   :    "<<codigo<<endl;
                        cout<<"\tNOMBRE   :    "<<nombre<<endl;
                        cout<<"\tSALA     :    "<<sala<<endl;
                        cout<<"\tTELEFONO :    "<<telefono<<endl;
                        cout<<"\tEDAD     :    "<<edad<<endl;
                        cout<<"\t________________________________\n\n";
                        cout<<"\tDEFINITAVAMENTE SE ELIMANRA EL REGISTRO DEL PACIENTE [S/N] ? ---> "; cin>>nodo;
                       
                        if (nodo=='S' or nodo=='s'){
                            cout<<"\n\n\t\t\t ELIMANDO REGISTRO...\n\n\t\t\a";
                        }else{
                            aux<<codigo<<" "<<nombre<<" "<<sala<<" "<<telefono<<" "<<edad<<endl;
                        }
                    }else{
                        aux<<codigo<<" "<<nombre<<" "<<sala<<" "<<telefono<<" "<<edad<<endl;
                    }
                lectura>>codigo;
            }
    }else{
        cout<<"\n\t ARCHIVO CORRUPTO NO SE PUEDE ABRIR \n";
    }

    if (encontrado==false){
                cout<<"\n\tNO SE ENCOTRO LA CODIGO DEL REGISTRO : "<<auxcodigo<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("REGISTRO_PACIENTE.txt");
    rename("REGISTRO_AUXILIAR.txt", "REGISTRO_PACIENTE.txt");
}

    
    //*******************************************************
	//				Consulta  de  Pacientes				    *		
	//*******************************************************

void consulta_paciente()
{
    //Lectura de archivos

    ifstream lectura;
    lectura.open("REGISTRO_PACIENTE.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       lectura>>codigo;
       while (!lectura.eof()){
            lectura>>nombre>>sala>>telefono>>edad;
            cout<<"\n";
            cout<<"\tCLAVE  :  "<<codigo<<endl;
            cout<<"\tNOMBRE :  "<<nombre<<endl;
            cout<<"\tSALA   :  "<<sala<<endl;
            cout<<"\tGrupo  :  "<<telefono<<endl;
            cout<<"\tEdad   :  "<<edad<<endl;
            lectura>>codigo;
            cout<<"\t________________________________\n";
       }

    }else{
        cout<<" ARCHIVO CORRUPTO NO SE PUEDE ABRIR  \n";
    }
    lectura.close();
}

		//*******************************************************
		//				Buscar   Pacientes				  	    *		
		//*******************************************************


void buscar()
{
    ifstream lectura;
    lectura.open("REGISTRO_PACIENTE.txt", ios::out | ios::in);

    encontrado=false;

    if (lectura.is_open()){
        cout<<"\n\tDIGITE LA CODIGO DEL PACIENTE A BUSCAR : ";
        cin>>auxcodigo;

        lectura>>codigo;
        while(!lectura.eof()){
            lectura>>nombre>>sala>>telefono>>edad;
       

        if(auxcodigo==codigo){
            cout<<"\n";
            cout<<"\tClave    :    "<<codigo<<endl;
            cout<<"\tNombre   :   "<<nombre<<endl;
            cout<<"\tSemestre : "<<sala<<endl;
            cout<<"\tGrupo    :    "<<telefono<<endl;
            cout<<"\tEdad     :     "<<edad<<endl;
            cout<<"\t________________________________\n";
            encontrado=true;
            break;
        }

        
        lectura>>codigo;
        }//fin del while
        if (encontrado==false){
            cout<<"\n\n\tNo hay registros con la clave : "<<auxcodigo<<"\n\n\t\t\t";
        }
    }else{
        cout<<"\n\t ARCHIVO CORRUPTO NO SE PUEDE ABRIR...";
    }

    lectura.close();
}

	//*******************************************************
	//				Modificar   Pacientes				    *		
	//*******************************************************

void modificar()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("REGISTRO_AUXILIAR.txt", ios::out);
    lectura.open("REGISTRO_PACIENTE.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tINGRE LA CODIGO DEL PACIENTE A MODIFICAR : ";
        cin>>auxcodigo;

            lectura>>codigo;
            while (!lectura.eof()){
                lectura>>nombre>>sala>>telefono>>edad;
                if (auxcodigo==codigo){
                    encontrado=true;
                    cout<<"\n";
                    cout<<"\tClave:    "<<codigo<<endl;
                    cout<<"\tNombre:   "<<nombre<<endl;
                    cout<<"\tSemestre: "<<sala<<endl;
                    cout<<"\tGrupo:    "<<telefono<<endl;
                    cout<<"\tEdad:     "<<edad<<endl;
                    cout<<"\t________________________________\n\n";
                    cout<<"\tINGRESE EL NUEVO NOMBRE DEL PACIENTE CON EL CODIGO : "<<auxcodigo<<"\n\n\t---> ";
                    cin>>auxnombre;

                    aux<<codigo<<" "<<auxnombre<<" "<<sala<<" "<<telefono<<" "<<edad<<endl;
                    cout<<"\n\n\t\t\t MODIFICANDO REGISTRO...\n\t\t\a";
                    }else{
                    aux<<codigo<<" "<<nombre<<" "<<sala<<" "<<telefono<<" "<<edad<<endl;
                    }
                lectura>>codigo;
            }
    }else{
        cout<<"\n\t ARCHIVO CORRUPTO NO SE PUEDE ABRIR... \n";
    }

    if (encontrado==false){
                cout<<"\n\tNO HAY PACIENTE REGISTRADO CON ESTE CODIGO: "<<auxcodigo<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("REGISTRO_PACIENTE.txt");
    rename("REGISTRO_AUXILIAR.txt", "REGISTRO_PACIENTE.txt");
}


	//*******************************************************
	//				Funcion Prinicpal del programa		    *		
	//*******************************************************
int main (){  //Ejecucion del programa principal
	

    system ("color E0");
    int opcion;

    do{
    system("cls");

    	cout<<"\n\t*******************************";
   	    cout<<"\n\t*    REGISTRO DE PACIENTES    *\n";
    	cout<<"\t*******************************\n\n";
    	cout<<" 1) AGREGAR PACIENTE                           "<<endl;
    	cout<<" 2) ELIMINAR DATOS DE PACIENTES                "<<endl;
    	cout<<" 3) ACTUALIZAR DATOS DE PACIENTES              "<<endl;
    	cout<<" 4) GUIA DE LISTA DE PACIENTES                 "<<endl;
    	cout<<" 5) TRASLADAR DATOS DE  PACIENTE               "<<endl;
    	cout<<" 6) DESEA SALIR?                               "<<endl;

    cout<<"\n INGRESE UNA OPCION : "; cin>>opcion;
    
    switch (opcion)
    {
		case 1:{
    		system("cls");
    		registro_pacientes();
    		cout<<"\n\t\t";
    		system ("PAUSE");
    						break;
     	}

		case 2:{
    		system("cls");
    		eliminar_pacientes();
    		cout<<"\n\t\t";
    		system ("PUASE");
    						break;
		}



		case 3:{
    		system("cls");
    		consulta_paciente();
    		cout<<"\n\t\t";
    		system ("PAUSE");
    					break;
		}


		case 4:{
    		system("cls");
    		buscar();
    		cout<<"\n\t\t";
    		system ("PAUSE");
    					break;
		}
		
		case 5:{
    		system("cls");
    		modificar();
    		cout<<"\n\t\t";
    		system ("PAUSE");
    					break;
		}
		
		case 6:{
    		cout<<"\n\n\t SALIENDO..\n\n\t\t"; system ("PAUSE");
    														break;
		}

		default:{
    		cout<<"\n\n\t OPCION INVALIDA...\n\n\t\t"; system ("PAUSE");
    																break;
		}
    }//fin switch

    	}while (opcion!=6);

    	system("cls");

 	
	
	system("pause>0");
	
	return 0;
}
