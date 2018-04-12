
float suma(float Nro1,float Nro2)
{
    return (Nro1+Nro2);
}

float resta(float Nro1,float Nro2)
{
    return (Nro1-Nro2);
}

float multiplicacion(float Nro1,float Nro2)
{
    return (Nro1*Nro2);
}

float divicion(float Nro1,float Nro2)
{
    return (Nro1/ Nro2);
}

int factorialRecursivo(int numero)
{
    int retorno;
    if(numero == 0)
    {
        retorno = 1; //cláusula de escape para que no desborde la pila
    }
    else
    {
        retorno = numero * factorialRecursivo(numero - 1);
    }
    return retorno;
}


int valida_factorial(float Nro)
{
    int Retorno;
    int ParteEntera=(int)Nro;
    float ParteDecimal=Nro-ParteEntera;
    if(Nro<0)
    {
        sms_error('N');
        pause();
        Retorno=-1;
    }
    if(ParteDecimal>0)
    {
        sms_error('N');
        pause();
        Retorno=-1;
    }
    if((Nro>=0)&&(ParteDecimal==0))
    {
        Retorno=ParteEntera;
    }
    return Retorno;
}

void ImprimeMenu(float A,float B, int FlagAB[2])
{
    system("cls");
    if(FlagAB[0]==0)
    {
        printf("1- Ingresar 1er operando (A=x) \n");
    }
    else
    {
        printf("1- Ingresar 1er operando (A=%f) \n",A);
    }

        if(FlagAB[1]==0)
    {
           printf("2- Ingresar 2do operando (B=y) \n");
    }
    else
    {
        printf("2- Ingresar 2do operando (B=%f) \n",B);
    }
        printf("3- Calcular la suma (A+B) \n");
        printf("4- Calcular la resta (A-B) \n");
        printf("5- Calcular la division (A/B) \n");
        printf("6- Calcular la multiplicacion (A*B) \n");
        printf("7- Calcular el factorial (A!) \n");
        printf("8- Calcular todas las operacione \n");
        printf("9- Salir \n");
        printf("\n\tIngrese Opcion: ");
}


void pause()
{
    printf("\n\n\n Presione una tecla para continuar...");
    getch();
}

void PideValor(float *Numero)
{
    printf("\n Ingrese un Numero: ");
    scanf("%f",Numero);
}

int validaDivicion(float Nro)
{
    if(Nro==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void sms_error(char mensaje)
{
    switch(mensaje)
    {
        case '1':
            printf("\n\n Prueba mensaje de Error: ");
            break;
        case '5':
            printf("\n\n No se puede realizar una divicion por 0");
            printf("\n Por favor reingrese Operador 2 para ejecutar esta opcion.\n");
            break;
        case 'N':
            printf("\n\n No es posible realizar factorial de un Nro negativo.");
            printf("\n Si decea realizar esta operacion, Reingrese el operador 1.");
            break;
        case 'D':
            printf("\n\n No es posible realizar factorial de un Nro con valores decimales.");
            printf("\n Si decea realizar esta operacion, Reingrese el operador 1.");
            break;
    }
}
