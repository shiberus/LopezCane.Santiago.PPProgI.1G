#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
} eVacuna;

float aplicarAumento(float precio);

int reemplazarCaracteres(char *cadena, char objetivo, char reemplazo);

int ordenarVacunas(eVacuna lista[], int tam);


int main()
{
    eVacuna lista[TAM] = {{1,"SputnikV", 'V', 4.5},{1,"Astrazeneca", 'A', 4.5},{1,"Cansino", 'C', 4.5},{1,"Moderna", 'V', 4},{1,"Pfizer", 'V', 9.5}};
    float resultadoPrecio;
    char cadenaEj[] = "batata";

    resultadoPrecio = aplicarAumento(65);
    //reemplazarCaracteres(cadenaEj, 'a', 'o');
    ordenarVacunas(lista, TAM);


    printf("%f         %s\n", resultadoPrecio, cadenaEj);
    return 0;
}

float aplicarAumento(float precio)
{
    return precio + (precio * 0.05);
}

int reemplazarCaracteres(char *cadena, char objetivo, char reemplazo)
{
    int i = 0;
    int contador = 0;
    while(cadena[i] != '\0')
    {
        if(cadena[i] == objetivo)
        {
            cadena[i] = reemplazo;
            contador++;
        }
    }
    return contador;
}

int ordenarVacunas(eVacuna lista[], int tam)
{
    int todoOk = -1;
    eVacuna auxVacuna;

    for(int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if(lista[j].tipo < lista[i].tipo || (lista[j].tipo == lista[i].tipo && lista[j].efectividad < lista[i].efectividad))
            {
                auxVacuna = lista[i];
                lista[i] = lista[j];
                lista[j] = auxVacuna;
            }
        }
    }
    for(int i = 0; i < tam; i++)
    {
        printf("%s\n", lista[i].nombre);
    }

    todoOk = 0;
    return todoOk;
}
