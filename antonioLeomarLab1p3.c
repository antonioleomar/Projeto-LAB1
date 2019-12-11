#include <stdio.h>

#define LIMITE 100

void imprimir(char vetor[LIMITE][31], char vetor2[LIMITE][31], int cont){
    int i;
    for(i=0;i<cont;i++){
        printf("%s\n",vetor[i]);
        printf("%s\n",vetor2[i]);
    }
}

void traducao(char vetor[LIMITE][31], char vetor2[LIMITE][31], char vetor3[LIMITE][31]){  //frase, palavra, cripto

}

void varredura(char vetor[LIMITE][31], char vetor2[LIMITE][31]){
    int i, p=0, cont=0;
    for(i=0;i<strlen(vetor);i++){
        if(vetor[i]==' '){
            p=i+1; //posição inicial da próxima palavra
            cont+=1; //contagem de palavras
            gets(vetor2[cont]);
        }
    }
    //imprimir string dividida:
    for(i=0;i<cont;i++){
        printf("%s\n",vetor2[i]);}
}


main(){

    int i,d,n;
    char palavra[LIMITE][31];
    char cripto[LIMITE][31];
    char frase[LIMITE][31];
    char stringDividida[LIMITE][31];


    printf("Informe a quantidade de instancias: \n");
    scanf("%d", &i);
    printf("Informe a quantidade de palavras do dicionario (limite de 1 a 100): \n");
    scanf("%d",&d);
    for (i=0;i<d;i++){
        printf("Informe palavra %d: \n", i+1);
        setbuf(stdin, NULL);
        gets(palavra[i]);
        //strcat(palavra, palavra);
        printf("Informe a criptografia da palavra %d: \n", i+1);
        setbuf(stdin, NULL);
        gets(cripto[i]);

    }
    imprimir(palavra,cripto,d);
    printf("\n");

    printf("Informe a quantidade de linhas a criptografar (limite de 1 a 100) : \n");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("Informe a frase %d a criptografar (limite de 60 caracteres por palavras):\n",i+1);
        setbuf(stdin, NULL);
        gets(frase[i]);
    }
    varredura(frase, stringDividida);
    traducao(frase, palavra, cripto);


}
