#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 25

/*se crea una estructura de tipo rango
esta contiene parametros para asignar los rangos*/
typedef struct{
int men,may,nt;
}rango;

//se declara el arreglo y la fucion Hilo
int arr[N];
void *Hilo(void *data);


int main(void){
    int i;
    srand(time(NULL));
    
    //se crea el proceso para cada hilo
    pthread_t proc1;
    pthread_t proc2;
    pthread_t proc3;
    pthread_t proc4;
    pthread_t proc5;

    //se declaran una estructura para cada hilo
    rango entrada1;
    rango entrada2;
    rango entrada3;
    rango entrada4;
    rango entrada5;

    //se llena el arreglo con numeros random
    printf("Lista de numeros\n");
    for(i=0; i<N;i++){
        arr[i]=rand()%101;
        printf("%d ",arr[i]);
    }

    //se llena con los rangos y el numero de hilo la estructura
    entrada1.men=0;
    entrada1.may = 5;
    entrada1.nt = 1;

    entrada2.men=5;
    entrada2.may = 10;
    entrada2.nt = 2;

    entrada3.men=10;
    entrada3.may = 15;
    entrada3.nt = 3;

    entrada4.men=15;
    entrada4.may = 20;
    entrada4.nt = 4;

    entrada5.men=20;
    entrada5.may = 25;
    entrada5.nt = 5;

    //se crea el hilo
    //a este se le envia: 
    //la direccion del proceso,null,la funcion del hilo y la estructura
    pthread_create(&proc1,NULL,&Hilo,&entrada1);
    pthread_create(&proc2,NULL,&Hilo,&entrada2);
    pthread_create(&proc3,NULL,&Hilo,&entrada3);
    pthread_create(&proc4,NULL,&Hilo,&entrada4);
    pthread_create(&proc5,NULL,&Hilo,&entrada5);
    
    //se inicia el proceso de cada hilo
    pthread_join(proc1,NULL);
    pthread_join(proc2,NULL);
    pthread_join(proc3,NULL);
    pthread_join(proc4,NULL);
    pthread_join(proc5,NULL);
    return 0;
}

//funcion del hilo
void *Hilo(void *data){
    //se hace un cast pasando de puntero data a tipo estructura
    rango *entradas = (rango *) data;
    //se declaran variables
    int men, may, i, aux=0;
    int arrN[5];

    //imprimimos el N. hilo y el rango del arreglo que usara este hilo
    printf("\n\nHILO: %d\n",entradas->nt);
    printf("minimo: %d maximo: %d\n",entradas->men,entradas->may);

    //guarda e imprime la parte del arreglo que se le asigno al hilo
    printf("trozo que le toca del arreglo\n");
    for(i=entradas->men; i<entradas->may;i++){
        arrN[aux] = arr[i];
        printf("%d ",arrN[aux]);
        aux++;
    }

    //se busca cual es el numero menor del arreglo 
    men=arrN[0];
    may=arrN[0];
    
    for(i=0; i<5;i++){
        if(arrN[i]>may)
            may=arrN[i];
        if(arrN[i]<men)
            men=arrN[i];
    }

    //imprime el numero menor 
    printf("\nEl numero menor es: [%d]\n",men);

}