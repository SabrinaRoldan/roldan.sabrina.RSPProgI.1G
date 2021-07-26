#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1

//1. Dada la estructura eVehiculo crear una función constructora base y una parametrizada
typedef struct{
    int id;
    char marca [20];
    int tipo;
    float peso;
}eVehiculo;

eVehiculo* vehiculo_new();

eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipoStr,char* pesoStr);

int vehiculo_setId(eVehiculo* this,int id);

int vehiculo_setMarca(eVehiculo* this,char* marca);

int vehiculo_setTipo(eVehiculo* this,int tipo);

int vehiculo_setPeso(eVehiculo* this,float peso);


//2. Dada la estructura del punto anterior declarar una variable con valores y guardarla en un archivo de texto.

//3. Dada la estructura del punto anterior declarar una variable con valores y guardarla en un archivo binario.

int main()
{
    eVehiculo* vehiculo1=vehiculo_new();

    if(vehiculo1!=NULL)
    {
        vehiculo1=vehiculo_newParametros(123,"Fiat",3,1000);
    }
    else
    {
        printf("Error al cargar el vehiculo\n");
    }

    int flag;


    FILE* f=fopen("vehiculos.csv","w");

    if(f==NULL)
    {
        printf("No se pudo guardar el archivo\n");
        exit(1);
    }

    fprintf(f,"id,marca,tipo,peso\n");

    for(int i=0;i<TAM;i++)
    {
        if(*(vehiculo1+i)!=NULL)
        {
            cant=fprintf(f,"%d,%s,%d,%.2f\n",
                     (*(vehiculo1+i))->id
                    ,(*(vehiculo1+i))->marca
                    ,(*(vehiculo1+i))->tipo
                    ,(*(vehiculo1+i))->peso);
            if(cant<3)
            {
                flag=1;
                break;
            }
        }
    }

    if(flag)
        {
            printf("Ocurrio un problema al cargar el vehiculo.\n");
        }
        else
        {
            printf("Vehiculo guardado con exito\n");
        }

    fclose(f);


    return 0;
}

eVehiculo* vehiculo_new()
{
    eVehiculo* nuevoVehiculo=(eVehiculo*) malloc(sizeof(eVehiculo));

    if(nuevoVehiculo!=NULL)
    {
        nuevoVehiculo->id=0;
        strcpy(nuevoVehiculo->marca,"");
        nuevoVehiculo->tipo=0;
        nuevoVehiculo->peso=0;
    }

    return nuevoVehiculo;

}

eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipoStr,char* pesoStr)
{
    eVehiculo* nuevoVehiculo=vehiculo_new();

    if(nuevoVehiculo!=NULL)
    {
        if(!(vehiculo_setId(nuevoVehiculo,atoi(idStr)) &&
           vehiculo_setMarca(nuevoVehiculo,marcaStr) &&
           vehiculo_setTipo(nuevoVehiculo,atoi(tipoStr)) &&
           vehiculo_setPeso(nuevoVehiculo,atof(pesoStr))
           ))
        {
            free(nuevoVehiculo);
            nuevoVehiculo=NULL;
        }
    }

    return nuevoVehiculo;
}

int vehiculo_setId(eVehiculo* this,int id)
{
    int retorno=0;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }

    return retorno;
}

int vehiculo_setMarca(eVehiculo* this,char* marca)
{
    int retorno=0;

    if(this!=NULL && marca!=NULL && strlen(marca)>=2 && strlen(marca)<=20)
    {
        strcpy(this->marca,marca);
        retorno=1;
    }

    return retorno;
}

int vehiculo_setTipo(eVehiculo* this,int tipo)
{
    int retorno=0;

    if(this!=NULL && tipo>0)
    {
        this->tipo=tipo;
        retorno=1;
    }

    return retorno;
}

int vehiculo_setPeso(eVehiculo* this,float peso)
{
    int retorno=0;

    if(this!=NULL && peso>0)
    {
        this->peso=peso;
        retorno=1;
    }

    return retorno;
}
