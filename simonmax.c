#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#include<stdbool.h>
#include <cstring>
#define MAX 500
int main(){
    srand(time(NULL));
    printf("Bienvenido/a, a continuación comenzaremos a jugar.\n");
    int gana=0,puntos=0;//gana: 0=perdio, 1=gano, 2=ternima
    while(gana==0){
        printf("Ingresa el nivel para la siguiente partida a iniciar entre “Principiante”, “Intermedio”, y “Avanzado”. Si prefieres terminar el programa ingresa “Fin”.\n");
        char opcionu[13],letra;//opcionu: dificultad que elije el usuario
        int h=0,tiempo;//h:se usa para llenar el arreglo TIEMPO: se usa para las dificultades
        scanf("%c",&letra);
        while(letra=='\n')
            scanf("%c",&letra);
        while(letra!='\n'){
            opcionu[h]=letra;
            h++;
            scanf("%c",&letra);
        }
        opcionu[h]='\0';
        char opcion10[]="p", opcion11[]="P", opcion12[]="principiante",opcion13[]="Principiante"; //opciones para principiante
        if((strcmp(opcionu,opcion10)==0)||(strcmp(opcionu,opcion11)==0)||(strcmp(opcionu,opcion12)==0)||(strcmp(opcionu,opcion13)==0))//principiante
            tiempo=3;
        char opcion20[]="i", opcion21[]="I", opcion22[]="intermedio",opcion23[]="Intermedio";
        if((strcmp(opcionu,opcion20)==0)||(strcmp(opcionu,opcion21)==0)||(strcmp(opcionu,opcion22)==0)||(strcmp(opcionu,opcion23)==0))//intermedio
            tiempo=2;
        char opcion30[]="a", opcion31[]="A", opcion32[]="avanzado",opcion33[]="Avanzado";
        if((strcmp(opcionu,opcion30)==0)||(strcmp(opcionu,opcion31)==0)||(strcmp(opcionu,opcion32)==0)||(strcmp(opcionu,opcion33)==0))//avanzado    
            tiempo=1;
        char opcion40[]="f", opcion41[]="F", opcion42[]="fin",opcion43[]="Fin";
        if((strcmp(opcionu,opcion40)==0)||(strcmp(opcionu,opcion41)==0)||(strcmp(opcionu,opcion42)==0)||(strcmp(opcionu,opcion43)==0))//fin
            gana=2;
        while ((tiempo==1)||(tiempo==2)||(tiempo==3)){
            printf("Ten en cuenta que debes de recordar la secuencia de colores y replicarla al finalizar indicando los diferentes colores “Naranja”, “Verde”, “Rojo”, y “Azul” en el orden adecuado.\n");
            printf("Nueva secuencia:\n");
            sleep(5);
            system("clear");
            int contador=0,colores[MAX],numero;//colores:se usa para guardar los colores
            for(contador;contador<4;contador++){//queremos 4 numeros
                /*Obtenemos un número aleatorio con la función rand(), un uso de función da un solo número*/
                numero=rand();
                numero=(numero%4)+1;//Quiero solo 4 números posibles
                switch(numero){    //switch apra que cada numero se asocie a un color
                    case 1:printf("Azul\n");
                        break;
                    case 2:printf("Verde\n");
                        break;
                    case 3:printf("Rojo\n");
                        break;
                    case 4:printf("Naranja\n");
                        break;
                }
                colores[contador]=numero;//asigna cada numero de el color al arreglo
                sleep(tiempo);
                system("clear");
                sleep(1);
            }
            gana=1;
            while(gana==1){
                int veces=1, j=0;//j=contador para comparar los numeros dentro del arreglo (colores);
                bool perdio=false;
                while (veces<=contador){
                    char entrada[9],color;//arreglo para lo que ingresa el usuario
                    int i=0;//contador para llenar el arreglo
                    scanf("%c",&color);
                    while(color=='\n')
                        scanf("%c",&color);
                    while(color!='\n'){//carga arreglo
                        entrada[i]=color;
                        i++;
                        scanf("%c",&color);
                    }
                    entrada[i]='\0';
                    int c=0;
                    char color10[]="a",color11[]="A",color12[]="azul",color13[]="Azul";
                    if((strcmp(entrada,color10)==0)||(strcmp(entrada,color11)==0)||(strcmp(entrada,color12)==0)||(strcmp(entrada,color13)==0))//azul
                        c=1;
                    char color20[]="v",color21[]="V",color22[]="verde",color23[]="Verde";
                    if((strcmp(entrada,color20)==0)||(strcmp(entrada,color21)==0)||(strcmp(entrada,color22)==0)||(strcmp(entrada,color23)==0))//verde
                        c=2;
                    char color30[]="r",color31[]="R",color32[]="rojo",color33[]="Rojo";
                    if((strcmp(entrada,color30)==0)||(strcmp(entrada,color31)==0)||(strcmp(entrada,color32)==0)||(strcmp(entrada,color33)==0))//rojo
                        c=3;
                    char color40[]="n",color41[]="N",color42[]="naranja",color43[]="Naranja";
                    if((strcmp(entrada,color40)==0)||(strcmp(entrada,color41)==0)||(strcmp(entrada,color42)==0)||(strcmp(entrada,color43)==0))//naranja
                        c=4;
                    if (c==colores[j]){  
                        j++;
                        veces++;
                    }else if(c==0){
                            printf("Error: opción incorrecta, intente nuevamente\n");
                        }else{
                            printf("Has perdido, obtuviste %d puntos\n",puntos);
                            puntos=0;
                            gana=0;
                            veces=contador+1;
                            perdio=true;
                            tiempo=0;
                            sleep(7);
                            system("clear");
                        }    
                }
                if(perdio==false){
                        puntos++;
                        printf("Nueva secuencia:\n");
                        sleep(5);
                        system("clear");
                        gana=1;
                        numero=rand();
                        numero=(numero%4)+1;//Quiero solo 4 números posibles
                        colores[contador]=numero;
                        int k=0;//cantidad de colores que van hasta ahora
                        while(k<=contador){
                            switch(colores[k]){
                                case 1:printf("Azul\n");
                                    break;
                                case 2:printf("Verde\n");
                                    break;
                                case 3:printf("Rojo\n");
                                    break;
                                case 4:printf("Naranja\n");
                                    break;
                            }
                            k++;
                            sleep(tiempo);
                            system("clear");
                            sleep(1);
                        }
                        contador++;
                }
            }
        }
    }
}

