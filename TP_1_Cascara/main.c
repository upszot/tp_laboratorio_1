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
                if ((FlagAB[0]==1)&&(FlagAB[1]==1))
                {
                    printf("\n\n A + B = %f  ",suma(A,B));
                }
                else
                {
                    sms_error('1');
                }
                pause();
                break;
            case 4:// (A-B)
                if ((FlagAB[0]==1)&&(FlagAB[1]==1))
                {
                        printf("\n\n A - B = %f  ",resta(A,B));
                }
                else
                {
                    sms_error('1');
                }
                pause();
                break;
            case 5:
                if((FlagAB[0]==1)&&(FlagAB[1]==1))
                {
                    if(validadivision(B)==0)
                    {
                        printf("\n\n A / B = %f  ",division(A,B));
                    }
                    else
                    {
                        sms_error('5');
                    }// FIN if(validadivision(B)==0)
                }
                else
                {
                    sms_error('1');
                }
                pause();
                break;
            case 6://(A*B)
                if ((FlagAB[0]==1)&&(FlagAB[1]==1))
                {
                        printf("\n\n A * B = %f  ",multiplicacion(A,B));
                }
                else
                {
                    sms_error('1');
                }
                pause();
                break;
            case 7: //(A!)
                if(FlagAB[0]==1)
                {
                    Flag_error_factorial=0;
                    Flag_error_factorial= valida_factorial(A);
                    if(Flag_error_factorial != -1 )
                    {
                        printf("\n\n El factorial de (A!) es: %d",factorialRecursivo(Flag_error_factorial));
                    }
                }
                else
                {
                    sms_error('A');
                }
                pause();
                break;
            case 8:
                if ((FlagAB[0]==1)&&(FlagAB[1]==1))
                {
                    printf("\n\n A + B = %f  ",suma(A,B));
                    printf("\n A - B = %f  ",resta(A,B));
                    if(validadivision(B)==0)
                    {
                        printf("\n A / B = %f  ",division(A,B));
                    }
                    else
                    {
                        sms_error('5');
                    }
                    printf("\n A * B = %f  ",multiplicacion(A,B));

                    //Si bien para el factorial solo me interesa FlagAB[0]==1
                    //como eligio la opcion de todas las operaciones... decido no mostrarle ningun resultado
                    //si no carga los 2 operadores...
                    Flag_error_factorial=0;
                    Flag_error_factorial= valida_factorial(A);
                    if(Flag_error_factorial != -1 )
                    {
                        printf("\n El factorial de (A!) es: %d",factorialRecursivo((int) A));
                    }
                }
                else
                {
                    sms_error('1');
                }// FIN if ((FlagAB[0]==1)&&(FlagAB[1]==1))
                pause();
                break;
            case 9:
                seguir = 'n';
                break;
        }//fin switch(opcion)

    }while(seguir=='s');

    return 0;
}
