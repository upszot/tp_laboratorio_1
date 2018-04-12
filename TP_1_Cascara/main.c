#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
//#include <curses.h>

int main()
{
    char seguir='s';
    int opcion;
    int FlagAB[2]={};
    int Flag_error_factorial=0;
    float A;
    float B;

    do
    {
        ImprimeMenu(A,B,FlagAB);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                PideValor(&A);
                FlagAB[0]=1;
                break;
            case 2:
                PideValor(&B);
                FlagAB[1]=1;
                break;
            case 3://(A+B)
                printf("\n\n A + B = %f  ",suma(A,B));
                pause();
                break;
            case 4:// (A-B)
                printf("\n\n A - B = %f  ",resta(A,B));
                pause();
                break;
            case 5:
                if(validaDivicion(B)==0)
                {
                    printf("\n\n A / B = %f  ",divicion(A,B));
                }
                else
                {
                    sms_error('5');
                }
                pause();
                break;
            case 6://(A*B)
                printf("\n\n A * B = %f  ",multiplicacion(A,B));
                pause();
                break;
            case 7: //(A!)
                Flag_error_factorial=0;
                Flag_error_factorial= valida_factorial(A);
                if(Flag_error_factorial != -1 )
                {
                        printf("\n\n El factorial de (A!) es: %d",factorialRecursivo(Flag_error_factorial));
                        pause();
                }

                break;
            case 8:
                printf("\n\n A + B = %f  ",suma(A,B));
                printf("\n A - B = %f  ",resta(A,B));
                if(validaDivicion(B)==0)
                {
                    printf("\n A / B = %f  ",divicion(A,B));
                }
                else
                {
                    sms_error('5');
                }
                printf("\n A * B = %f  ",multiplicacion(A,B));
                Flag_error_factorial=0;
                Flag_error_factorial= valida_factorial(A);
                if(Flag_error_factorial != -1 )
                {
                        printf("\n El factorial de (A!) es: %d",factorialRecursivo((int) A));
                }
                pause();
                break;
            case 9:
                seguir = 'n';
                break;
        }//fin switch(opcion)

    }while(seguir=='s');

    return 0;
}
