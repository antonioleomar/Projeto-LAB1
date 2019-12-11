//UEPB-UNIVERSIDADE ESTADUAL DA PARAIBA
//DISCIPLINA: LABORATÓRIO DE PROGRAMAÇÃO I
//PROF: DANILO ABREU
//ALUNO; ANTONIO LEOMAR FERREIRA SOARES
//ATIVIDADE: LAB04

#include <stdio.h>
#include <string.h>

void nomeAlunos(char n[20][2][16]){
    int i,j;
    char nome[16];
    //char nome[][2];
    for(i=0;i<20;i++){
        printf("Informe o nome do aluno %d:\n", i+1);
        setbuf(stdin,NULL);
        gets(strupr(n[i][0]));
        strcpy(n[i][1],alunoSituacao(n[i][0]));
    }
}

alunoSituacao(char nome[16]){
    int i;
    float notas[4], soma=0, media;

    for(i=0;i<4;i++){
        printf("Informe a nota %d:\n ", i+1);
        scanf("%f",&notas[i]);
        soma=soma+notas[i];
    }
    media = soma/4;
    printf("A MEDIA DE %s: %.3f\n",strupr(nome), media);
    printf("\n\n");

    if(media>=7){
        return "Aprovado";

    }else{
        return "Reprovado";
    }
}


char mostrar(char n[][2][16]){
    int i;
    printf("\n\n>>>> SITUACAO FINAL\n\n");
    for(i=0;i<20;i++){
        printf("%s ", strupr(n[i][0]));
        printf("%s\n", strupr(n[i][1]));
    }
}

main(){
    char vetor [20][2][16]; //vetor de nomes com 20 alunos e limite de 16 letras por nome

    printf(">>>> INSIRA OS DADOS DOS ALUNOS\n\n");
    nomeAlunos(vetor);
    mostrar(vetor);
}
