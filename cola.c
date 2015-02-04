/*Estructura estática cola implantada dinámicamente en C   */
#include <stdio.h>
#define FALSO 0
typedef struct nod
    int     dato;
    struct nodo *liga;
} elemento_lista;
void Menu (int *opcion);
elemento_lista *AgregaDato (elemento_lista *apuntlista, int dato);
elemento_lista *BorrarDato (elemento_lista *apuntlista);
void ImprCola (elemento_lista *apuntlista);
void LimpCola (elemento_lista *apuntlista);
main () 
{
    elemento_lista *apuntlista;
    int dato, opcion;
    apuntlista = NULL;
    do {
        Menu (&opcion);
        switch (opcion) {
            case 1: 
                printf ("Ingresa un dato que será agregado  ");
                scanf ("%d", &dato);
                apuntlista = AgregaDato (apuntlista, dato);
                break;
            case 2: 
                if (apuntlista == NULL)
                    printf ("¡Cola vacia!\n");
                else
                    apuntlista = BorrarDato (apuntlista);
                break;
            case 3: 
                ImprCola (apuntlista);
                    break;
            case 4: 
                break;
            default: 
                printf ("Opcion no valida - intentar nuevamente\n");
                break;
        }
    } while (opcion != 4);
    LimpCola (apuntlista);
}                               /* fin de main */
void Menu (int *opcion)
{
    char    local;
    printf("\nEntre\t1 para agregar un dato,\n\t2 para borrar un dato,\n\t3 para mostrar el contenido de la cola\n\t4 para salir\n");
    do {
        local = getchar ();
        if ((isdigit (local) == FALSO) && (local != '\n')) 
        {
            printf ("\nSe debe ingresar un entero.\n");
            printf ("Teclee 1 para agregar, 2 para borrar, 3 para imprimir, 4 para salir\n");
        }
    } while (isdigit ((unsigned char) local) == FALSO);
	*opcion = (int) local - '0';
}
elemento_lista *AgregaDato (elemento_lista *apuntlista, int dato) 
{
 elemento_lista *lp = apuntlista;
 if (apuntlista != NULL) {
    while (apuntlista->liga != NULL)
           apuntlista = apuntlista->liga;
    apuntlista->liga = (struct nodo *) malloc(sizeof(elemento_lista));
    apuntlista =  apuntlista -> liga;
    apuntlista->liga = NULL;
    apuntlista->dato = dato;
    return lp;
    }
 else 
    {
     apuntlista =  (struct nodo *) malloc (sizeof (elemento_lista));
     apuntlista->liga = NULL;
     apuntlista->dato = dato;
     return apuntlista;
    }
}
elemento_lista *BorrarDato (elemento_lista *apuntlista) 
{
    elemento_lista *tempp;
    printf ("El elemento borrado es %d\n", apuntlista->dato);
    tempp =  apuntlista->liga;
    free (apuntlista);
    return tempp;
}
void ImprCola (elemento_lista *apuntlista) 
{
    if (apuntlista == NULL)
        printf ("La cola esta vacia !!\n");
    else
        while (apuntlista != NULL) {
            printf ("%d\t", apuntlista->dato);
            apuntlista =  apuntlista->liga;
        }
    printf ("\n");
}
void LimpCola (elemento_lista *apuntlista) 
{
    while (apuntlista != NULL) {
        apuntlista = BorrarDato (apuntlista);
    }
}
