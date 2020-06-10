#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define DIM 1000
#define ESC 27


/** STRUCTURES  */

typedef struct
{
    int  id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[45];
    unsigned long movil;
    int baja; /// 0 si está activo - 1 si está eliminado

} stCliente;

typedef struct
{
    int id;  /// campo único y autoincremental
    int idCliente;
    int anio;
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos;  /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado

} stConsumo;

/** ***************************************************         */


/** UTILITIES PROTOTYPE*/
int validaEmail(char email[]);
int buscaUltimoId();
int buscaPosicion(int id);
int existeCliente(int dni);
int arch2Arr(stCliente clientesArr[], int dimension);
void ordenarArrDni(stCliente clientes[], int validos);
void ordenarArrApellido(stCliente clientes[], int validos);
void mostrarArr(stCliente clientesArr[],int validos);
void buscarClienteEspecif();
stCliente buscaCliente(int dni);


/** *********** **/

/** MENUS **/

void muestraMenu();
void muestraMenuCliente();
void menuModificar();
void muestraMenuConsumo();
void menuMostrar();

/** ********* **/



/** MODIFICADORES **/
void modifMovil();
void modifApellido();
void darDeBaja();
void modifDNI();
void modifDomicilio();
void modifEmail();
void modifNombre();
    /** MODIF UTILITIES **/
    void modifBaja(stCliente cliente);
    void cambiaApellido(stCliente cliente);
    void cambiaMovil(stCliente cliente);
    void cambiaDNI(stCliente cliente);
    void cambiaDomicilio(stCliente cliente);
    void cambiaEmail(stCliente cliente);
    void cambiaNombre(stCliente cliente);
    /** ************ **/


/** *********** **/


/** CLIENT FUNCTIONS PROTOTYPE */
stCliente cargarUnCliente();
void cargarClienteArchivo();
void guardarCliente(stCliente cliente);
void mostrarCliente(stCliente cliente);
void mostrarClientesArch();

/** ************* */


/** MAIN */
int main(){

char option;
do{
        system("cls");
    muestraMenu();
    printf("\n\nIngrese una opcion. 0 para salir: ");
    option = getch();

    switch(option){
    case 49:
        muestraMenuCliente();
    break;
    case 50:
        muestraMenuConsumo();
    break;




    }

    system("pause");


}while(option != ESC);

printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
printf("\nXX                                                                          XX");
printf("\nXX   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMMMMMMMMMMssssssssssssssssssssssssssMMMMMMMMMMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMMMMMss'''                          '''ssMMMMMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMyy''                                    ''yyMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMyy''                                            ''yyMMMMMMMM   XX");
printf("\nXX   MMMMMy''                                                    ''yMMMMM   XX");
printf("\nXX   MMMy'                                                          'yMMM   XX");
printf("\nXX   Mh'                                                              'hM   XX");
printf("\nXX   -                                                                  -   XX");
printf("\nXX                                                                          XX");
printf("\nXX   ::                                                                ::   XX");
printf("\nXX   MMhh.        ..hhhhhh..                      ..hhhhhh..        .hhMM   XX");
printf("\nXX   MMMMMh   ..hhMMMMMMMMMMhh.                .hhMMMMMMMMMMhh..   hMMMMM   XX");
printf("\nXX   ---MMM .hMMMMdd:::dMMMMMMMhh..        ..hhMMMMMMMd:::ddMMMMh. MMM---   XX");
printf("\nXX   MMMMMM MMmm''      'mmMMMMMMMMyy.  .yyMMMMMMMMmm'      ''mmMM MMMMMM   XX");
printf("\nXX   ---mMM ''             'mmMMMMMMMM  MMMMMMMMmm'             '' MMm---   XX");
printf("\nXX   yyyym'    .              'mMMMMm'  'mMMMMm'              .    'myyyy   XX");
printf("\nXX   mm''    .y'     ..yyyyy..  ''''      ''''  ..yyyyy..     'y.    ''mm   XX");
printf("\nXX           MN    .sMMMMMMMMMss.   .    .   .ssMMMMMMMMMs.    NM           XX");
printf("\nXX           N`    MMMMMMMMMMMMMN   M    M   NMMMMMMMMMMMMM    `N           XX");
printf("\nXX            +  .sMNNNNNMMMMMN+   `N    N`   +NMMMMMNNNNNMs.  +            XX");
printf("\nXX              o+++     ++++Mo    M      M    oM++++     +++o              XX");
printf("\nXX                                oo      oo                                XX");
printf("\nXX           oM                 oo          oo                 Mo           XX");
printf("\nXX         oMMo                M              M                oMMo         XX");
printf("\nXX       +MMMM                 s              s                 MMMM+       XX");
printf("\nXX      +MMMMM+            +++NNNN+        +NNNN+++            +MMMMM+      XX");
printf("\nXX     +MMMMMMM+       ++NNMMMMMMMMN+    +NMMMMMMMMNN++       +MMMMMMM+     XX");
printf("\nXX     MMMMMMMMMNN+++NNMMMMMMMMMMMMMMNNNNMMMMMMMMMMMMMMNN+++NNMMMMMMMMM     XX");
printf("\nXX     yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy     XX");
printf("\nXX   m  yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy  m   XX");
printf("\nXX   MMm yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy mMM   XX");
printf("\nXX   MMMm .yyMMMMMMMMMMMMMMMM     MMMMMMMMMM     MMMMMMMMMMMMMMMMyy. mMMM   XX");
printf("\nXX   MMMMd   ''''hhhhh       odddo          obbbo        hhhh''''   dMMMM   XX");
printf("\nXX   MMMMMd             'hMMMMMMMMMMddddddMMMMMMMMMMh'             dMMMMM   XX");
printf("\nXX   MMMMMMd              'hMMMMMMMMMMMMMMMMMMMMMMh'              dMMMMMM   XX");
printf("\nXX   MMMMMMM-               ''ddMMMMMMMMMMMMMMdd''               -MMMMMMM   XX");
printf("\nXX   MMMMMMMM                   '::dddddddd::'                   MMMMMMMM   XX");
printf("\nXX   MMMMMMMM-                                                  -MMMMMMMM   XX");
printf("\nXX   MMMMMMMMM                                                  MMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMy                                                yMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMy.                                            .yMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMy.                                        .yMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMMMy.                                    .yMMMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMMMMMs.                                .sMMMMMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMMMMMMMss.           ....           .ssMMMMMMMMMMMMMMMMMM   XX");
printf("\nXX   MMMMMMMMMMMMMMMMMMMMNo         oNNNNo         oNMMMMMMMMMMMMMMMMMMMM   XX");
printf("\nXX                                                                          XX");
printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
printf("\n                                                                              ");
printf("\n    .o88o.                               o8o                .                 ");
printf("\n    888 `'                               `'              .o8                 ");
printf("\n   o888oo   .oooo.o  .ooooo.   .ooooo.  oooo   .ooooo.  .o888oo oooo    ooo   ");
printf("\n    888    d88(  '8 d88' `88b d88' `'Y8 `888  d88' `88b   888    `88.  .8'    ");
printf("\n    888    `'Y88b.  888   888 888        888  888ooo888   888     `88..8'     ");
printf("\n    888    o.  )88b 888   888 888   .o8  888  888    .o   888 .    `888'      ");
printf("\n   o888o   8''888P' `Y8bod8P' `Y8bod8P' o888o `Y8bod8P'   '888'      d8'      ");
printf("\n                                                                .o...P'       ");

return 0;
}


/** ***************** */


/** UTILITIES         */

void muestraMenu(){
    printf("\n1) Menu cliente.");
    printf("\n2) Menu consumo.");

    printf("\n\n");



}

void muestraMenuCliente(){
    char option;
    do{
    system("cls");
    printf("\n1)Dar de alta un cliente.");
    printf("\n2)Dar de baja un cliente.");
    printf("\n3)Modificar un cliente.");
    printf("\n4)Mostrar clientes.");

    printf("\nIngrese una opcion. 0 para salir.            : ");
    option = getch();

    switch(option){
        case 49:
            cargarClienteArchivo();
        break;
        case 50:
            darDeBaja();
        break;
        case 51:
            menuModificar();
        break;
        case 52:
            menuMostrar();
        break;
        default:
            printf("\nIngrese una opcion valida.  ");
        break;
    }


    system("pause");
    }while(option!=ESC);


}

void menuModificar(){
        char option;
    do{
    system("cls");
    printf("\n1)Modificar nombre.");
    printf("\n2)Modificar apellido.");
    printf("\n3)Modificar DNI.");
    printf("\n4)Modificar email.");
    printf("\n5)Modificar domicilio.");
    printf("\n6)Modificar movil.");

    printf("\nIngrese una opcion. ESC para salir.            : ");
    option = getch();

    switch(option){
        case 49:
            modifNombre();
        break;
        case 50:
            modifApellido();
        break;
        case 51:
            modifDNI();
        break;
        case 52:
            modifEmail();
        break;
        case 53:
            modifDomicilio();
        break;
        case 54:
            modifMovil();
        break;
        default:
            printf("\nIngrese una opcion valida.   ");
        break;
    }


    system("pause");
    }while(option!=ESC);
}

void menuMostrar(){
    char option;
    int validos;

    stCliente clientesArr[DIM];

    validos = arch2Arr(clientesArr,DIM);

    do{
        system("cls");
        printf("\n1)Mostrar clientes ordenados por DNI.");
        printf("\n2)Mostrar clientes ordenados por apellido.");
        printf("\n3)Mostrar un cliente específico.");
        option = getch();
        switch(option){
            case 49:
                ordenarArrDni(clientesArr,validos);
                mostrarArr(clientesArr,validos);
            break;
            case 50:
                ordenarArrApellido(clientesArr,validos);
                mostrarArr(clientesArr,validos);
            break;
            case 51:

                buscarClienteEspecif();
            break;


        }

        system("pause");
    }while(option != ESC);
}

 void muestraMenuConsumo(){
    printf("\nNOT DEVELOPED YET.");

 }


int validaEmail(char email[]){
    int valid=strlen(email);
    int i=0;
    int flag=0;
    while(i<valid && flag == 0){
        if(email[i]==64){
            flag=1;
        }
        i++;
    }
    return flag;
}

int buscaUltimoId(){
    stCliente cliente;
    int id=-1;
    FILE *pArchCliente=fopen("clientes.dat", "rb");
    if(pArchCliente){
        fseek(pArchCliente, -1,SEEK_END);
        if(fread(&cliente,sizeof(stCliente),1,pArchCliente) > 0){
            id=cliente.nroCliente;
        }
        fclose(pArchCliente);
    }
return id;
}



/** ARCH TO ARRAY FUNCTION **/
int arch2Arr(stCliente clientesArr[], int dimension){
    stCliente cliente;
    FILE *pArchClientes;
    int i=0;

    pArchClientes = fopen("clientes.dat","rb");
    if(pArchClientes){
        while(fread(&cliente,sizeof(stCliente),1,pArchClientes) > 0){
            if(cliente.baja == 0){
                clientesArr[i] = cliente;
                i++;
            }
        }
    }

return i;
}
/** ********************  **/

/**  ORDENAMIENTOS       **/
void ordenarArrDni(stCliente clientes[], int validos){
     stCliente aux;
    for(int i = 0; i < validos ; i ++)
    {
        for(int j = i+1; j < validos; j++)
        {
            if(clientes[i].dni > clientes[j].dni)
            {
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
        }
    }
}

void ordenarArrApellido(stCliente clientes[], int validos){
     stCliente aux;
    for(int i = 0; i < validos ; i ++)
    {
        for(int j = i+1; j < validos; j++)
        {

            if(strcmpi(clientes[i].apellido , clientes[j].apellido)== 1)
            {
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
        }
    }
}

void buscarClienteEspecif(){
             stCliente clienteBuscado;
            int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    mostrarCliente(clienteBuscado);

}

/** ******************** **/

/** MOSTRAR ARRAY DE CLIENTES **/

void mostrarArr(stCliente clientesArr[],int validos){
    for(int i = 0; i<validos; i++){
        mostrarCliente(clientesArr[i]);
    }


}
/** ******************* **/

/** **************    */


/** CLIENT FUNCTIONS  */
stCliente cargarUnCliente(){
    stCliente cliente;

    do
    {
        printf("\n Ingrese numero de cliente: ");
        scanf("%d",&cliente.nroCliente);
    }
    while(cliente.nroCliente<0 || cliente.nroCliente>9999999 );
    printf(" Ingrese el Nombre..................: ");
    fflush(stdin);
    gets(cliente.nombre);
    printf(" Ingrese el Apellido................: ");
    fflush(stdin);
    gets(cliente.apellido);
    printf(" Ingrese el DNI.....................: ");
    scanf(" %d", &cliente.dni);
    do
    {
        printf(" Ingrese el EMail...................: ");
        fflush(stdin);
        gets(cliente.email);
    }
    while(!validaEmail(cliente.email));
    printf(" Ingrese la Domicilio...................: ");
    fflush(stdin);
    gets(cliente.domicilio);
    printf(" Ingrese el Numero de celular...........: ");
    scanf(" %lu", &cliente.movil);
    cliente.baja=0;



return cliente;
}


void cargarClienteArchivo(){
    char opcion='s';
    stCliente cliente;
    int existe;
    while(opcion =='s'){
        system("cls");
        printf(" ~ ~ ~ CARGA DE CLIENTES ~ ~ ~");
        cliente = cargarUnCliente();
        existe = existeCliente(cliente.dni);
        if(existe == 0){
        cliente.id = buscaUltimoId()+1;
        guardarCliente(cliente);
        }else{
            printf("\nEl cliente no se cargo porque ya existe en nuestro sistema.");
        }

        printf("\nDesea ingresar otro cliente? (s/n) : ");
        scanf("%s",&opcion);

    };


}

void guardarCliente(stCliente cliente){

    FILE *pArchCliente=fopen("clientes.dat", "ab");
    if(pArchCliente){
        fwrite(&cliente,sizeof(stCliente),1,pArchCliente);
        fclose(pArchCliente);
    }
}

void mostrarClientesArch(){
    stCliente cliente;
    FILE *pArchCliente=fopen("clientes.dat","rb");
    if(pArchCliente){
        while(fread(&cliente,sizeof(stCliente),1,pArchCliente)>0){
            mostrarCliente(cliente);
        }
        fclose(pArchCliente);
    }

 }

void mostrarCliente(stCliente cliente){

puts("\n------------------------------------------");
printf("\nNro Cliente: %d",cliente.nroCliente);
printf("\nNombre: %s",cliente.nombre);
printf("\nApellido: %s",cliente.apellido);
printf("\nDNI: %d",cliente.dni);
printf("\nEmail: %s",cliente.email);
printf("\nDomicilio: %s",cliente.domicilio);
printf("\nMovil: %lu",cliente.movil);
printf("\nBaja: %d",cliente.baja);
puts("\n------------------------------------------");
}




int existeCliente(int dni){
    stCliente cliente;
    FILE *pArchiCliente;
    pArchiCliente = fopen("clientes.dat","rb");
    int flag = 0;
    if(pArchiCliente){
        while(fread(&cliente,sizeof(stCliente),1,pArchiCliente)){
                if(cliente.dni == dni){

                flag = 1;
              }
        }
        fclose(pArchiCliente);
    }
    return flag;
}


void modifBaja(stCliente cliente){

    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        cliente.baja=1;
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}



int buscaPosicion(int id){
    stCliente cliente;
    int pos=0;
    int flag = 0;
    FILE *pArchClientes = fopen("clientes.dat","rb");
    if(pArchClientes){
        while(flag==0 && fread(&cliente,sizeof(stCliente),1,pArchClientes)>0){
                pos = pos +1;
            if(cliente.id == id){
                flag=1;
            }
        }
    }
return pos;
}

stCliente buscaCliente(int dni){
        stCliente cliente;
        int flag =0;
        FILE *pArchClientes = fopen("clientes.dat","rb");
        if(pArchClientes){
            while(flag==0 && fread(&cliente,sizeof(stCliente),1,pArchClientes)> 0){
                if(cliente.dni == dni){
                        printf("\nDNI ENCONTRADO");
                    flag = 1;
                }
            }
            fclose(pArchClientes);
        }


    return cliente;
}

void darDeBaja(){
    stCliente clienteBuscado;
    int existe;
    int dni;
    printf("\nIngrese su dni:  ");
    scanf("%d",&dni);

    existe = existeCliente(dni);
    printf("\n existe : %d",existe);
   // if(existe == 1){
     //  printf("\nExiste cliente");
    clienteBuscado = buscaCliente(dni);
    modifBaja(clienteBuscado);
//}

}


void modifNombre(){
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaNombre(clienteBuscado);
}

void cambiaNombre(stCliente cliente){

    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo nombre: ");
        fflush(stdin);
        gets(cliente.nombre);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}

void modifApellido(){
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaApellido(clienteBuscado);
}

void cambiaApellido(stCliente cliente){
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo apellido: ");
        fflush(stdin);
        gets(cliente.apellido);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }

}

void modifDNI(){
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaDNI(clienteBuscado);
}

void cambiaDNI(stCliente cliente){
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo DNI: ");
        fflush(stdin);
        scanf(" %d", &cliente.dni);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}




void modifEmail(){
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaEmail(clienteBuscado);
}

void cambiaEmail(stCliente cliente){
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo Email: ");
        fflush(stdin);
        gets(cliente.email);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}


void modifDomicilio(){
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaDomicilio(clienteBuscado);
}

void cambiaDomicilio(stCliente cliente){
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo Domicilio: ");
        fflush(stdin);
        gets(cliente.domicilio);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);

        fclose(pArchClientes);
    }
}


void modifMovil(){
    stCliente clienteBuscado;
    int dni;
    printf("\nIngrese su dni: ");
    scanf("%d",&dni);
    clienteBuscado = buscaCliente(dni);
    cambiaMovil(clienteBuscado);
}

void cambiaMovil(stCliente cliente){
    int pos=0;
    pos = buscaPosicion(cliente.id);
    FILE *pArchClientes = fopen("clientes.dat", "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET);
        printf("\nIngrese su nuevo Movil: ");
        fflush(stdin);
        scanf("%lu",&cliente.movil);
        fwrite(&cliente, sizeof(stCliente), 1, pArchClientes);
        fclose(pArchClientes);
    }
}

/** **************    */
