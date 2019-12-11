//UEPB-UNIVERSIDADE ESTADUAL DA PARAIBA
//DISCIPLINA: LABORATORIO DE PROGRAMA��O I
//PROF: DANILO ABREU
//ALUNO; ANTONIO LEOMAR FERREIRA SOARES
//ATIVIDADE: LAB10


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ESTRUTURA QUE ARMAZENARA OS DADOS DO CAMPEONATO
typedef struct {
    char ano[10];
    char campeao[30];
    char vice[30];
    char cidade[30]
}CAMPEONATO;

//ESTRUTURA QUE RECEBER� O CONJUNTO DE DADOS DO CAMPEONATO E O ENDERE�O DO PROXIMO ELEMENTO DA LISTA (O CAMPEONATO A SEGUIR)
typedef struct elemento{
    CAMPEONATO dados;//AQUI, SER� ARMAZENADOS OS DADOS DO CAMEONATO
    struct elemento *ant;//ESTE CAMPO SER� UM PONTEIRO PARA O ANTERIOR ELEMENTO DA LISTA (QUE TAMB�M SER� DO "TIPO" STRUCT ELEMENTO)
    struct elemento *prox;//ESTE CAMPO SER� UM PONTEIRO PARA O PR�XIMO ELEMENTO DA LISTA (QUE TAMB�M SER� DO "TIPO" STRUCT ELEMENTO)
} ELEM;

//A ESTRUTURA ABAIXO TERA O APONTADOR DO PRIMEIRO ELEMENTO DA LISTA
typedef struct{
    ELEM *inicio; //ESTRUTURA QUE RECEBER� O PRIMEIRO ELEMENTO (DADOS DO CONTATO E PROXIMO ELEMENTO) DA LISTA
}LISTA;

//FUN��O QUE RETORNA O ENDERE�O DE MEM�RIA DE UMA LISTA VAZIA.
LISTA* criar(){
    LISTA* li = (LISTA*) malloc(sizeof(LISTA)); //ALOCA O ESPA�O NA MEM�RIA
    if(li != NULL) //SE O SISTEMA OPERACIONAL ALOCAR, ENTRA NO IF.
    {
        li->inicio= NULL; //INICIA A POSI��O INICIAL COM NULL
    }
    return li;//RETORNA O ENDERE�O DA LISTA
}

//FUN��O QUE DESALOCA O ESPA�O NA MEM�RIA DO S.O.
void liberar(LISTA *li){
    if(li !=NULL){
        ELEM * aux;//CRIA UM PONTEIRO DE UMA ESTRUTURA ELEMENTO, PARA SERVIR DE AUXILIAR PARA O PROCESSO DE LIBERA��O
        while(li->inicio!=NULL) //VERIFICA SE A POSI��O INICIA TEM ALGUMA ESTRUTURA. CASO TENHA, ENTRA NO IF
        {
            aux = li->inicio;//O PONTEIRO AUXLIAR RECEBE O ENDERE�O DO PRIMEIRO ELEMENTO DA MINHA LISTA.
            li->inicio = li->inicio->prox;//A POSI��O DE INICIO DA MINHA LISTA PASSA A APONTAR AO VALOR QUE ESTAVA NO CAMPO PROX�MO (APONTAR� AO SEGUNO ELEMENTO)
            free(aux);//COM A POSI��O INICIAL APONTANDO PARA SEGUNDA POSI��O, A PRIMEIRA (QUE ESTAVA GUARDADA NO ELEMENTO AUXILIAR) SER� LIBERADA.
        }//SE A POSI��O DE INICIO APONTAR PARA NULL, SIGINIFICA QUE NAO H� MAIS ELEMENTOS NA MINHA LISTA.
        free(li);//O ESPA�O DE MEM�RIA ALOCADO PARA MINHA LISTA � LIBERADO.
    }
}

//FUN��O QUE IR� INSERIR UM NOVO ELEMENTO NA MINHA LISTA
void inserir(LISTA *li, CAMPEONATO c) //COMO PAR�METROS DA FUN��O, TEREMOS: O ENDERE�O DA LISTA ; E OS DADOS DO CONTATO (QUE SER�O ARMAZENADOS NA MINHA STRUCT CCAMPEONATO)
{
    if(li==NULL) //CASO A LISTA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA
    {
        ELEM *novo = (ELEM*) malloc(sizeof(ELEM));//NESTE PASSO, SER� CRIADO UM NOVO ELEMENTO VAZIO (CRIADO APENAS O ESPA�O NA MEM�RIA)
        if(novo != NULL) //CASO A ALOCA��O DESTE NOVO ELEMENTO TENHA SIDO FEITA
        {
            novo->dados= c;//O CAMPO DADOS, DA MINHA ESTRUTURA ELEMENTO RECEBE OS DADOS DO CONTATO PASSADO POR PAR�METRO DA FUN��O
            if(li->inicio==NULL){//LISTA VAZIA
                novo->prox=NULL;
                novo->ant=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                if(strcmp(li->inicio->dados.ano,novo->dados.ano)>0){//INSER��O NO INICIO
                    novo->ant=NULL;
                    novo->prox=li->inicio;
                    li->inicio->ant=novo;
                    li->inicio=novo;

                }else{
                    if(strcmp(li->inicio->dados.ano,novo->dados.ano)==0){
                       printf("ERRO: NAO PODE CAMPEONATO NO MESMO ANO\n");

                }else{//INSER��O NO MEIO OU FIM
                    ELEM *ante,*aux=li->inicio;
                    while((aux!=NULL)&&(strcmp(aux->dados.ano,novo->dados.ano)<=0)){
                        ante=aux;
                        aux=aux->prox;
                    }
                    ante->prox=novo;
                    novo->ant=ante;
                    novo->prox=aux;
                    if(aux!=NULL)
                        aux->ant=novo;
                }

                }
            printf("\nELEMENTO INSERIDO\n");
        }}
        else  //SE MINHA LISTA NAO ESTIVER ALOCADA...
        {
            printf("\nERRO DE ALOCACAO\n");
        }
    }
}

//FUN�AO QUE REMOVER� UM ELEMENTO DA LISTA. O ELEMENTO A SER REMOVIDO SERA PASSADO POR PARAMETRO

void remover(LISTA *li, int pos){
    if(li==NULL) //SE A LISTA NAO FOR ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA...
    {
        if(li->inicio==NULL) //SE O CAMPO IN�CIO APONTAR PARA NULL, SIGNIFICA QUE A LISTA EST� VAZIA
        {
            printf("\nLISTA VAZIA\n");
        }
        else  //SE NAO ESTIVER VAZIA...
        {
            ELEM *aux=li->inicio;
            int cont=1;
            if(cont==pos){//SE O ELEMENTO FOR O PRIMEIRO DA LISTA
                li->inicio=aux->prox;
                if(aux->prox!=NULL)
                    aux->prox->ant=NULL;
                free(aux);
            }else{//O ELEMENTO NAO ESTA NO INICIO DA LISTA
                ELEM *ant;
                while((aux!=NULL)&&(cont != pos)){
                    ant=aux;
                    aux=aux->prox;
                    cont++;
                }
                if(aux==NULL){
                    return;
                }
                ant->prox = aux->prox;
                if(aux->prox!=NULL)
                    aux->prox->ant=ant;
                free(aux);
            }
            printf("\nELEMENTO REMOVIDO\n");
        }
    }
}

//FUN��O QUE APRESENTAR� OS CAMPEONATOS ARMAZENADOS NA LISTA
void mostrar(LISTA *li)
{
    if(li == NULL)  //SE A LISTA NAO FOR ALOCADA....
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else    //LISTA ALOCADA...
    {
        if(li->inicio==NULL)  //SE O CAMPO FIM FOR IGUAL NULL, A LISTA ESTAR� VAZIA. PODERIA TESTAR TAMB�M A POSI��O INICIAL. TANTO FAZ...
        {
            printf("\nLISTA VAZIA\n");
        }else{//H� ELEMENTO NA LISTA
            int quantidade=0;//VARIAVEL PARA CONTAR OS CAMPEOANTOS
            ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECER� O ENDERE�O DO PRIMEIRO ELEMENTO DA LISTA

            while(aux != NULL){
                quantidade++;
                printf("#:%d\n",quantidade);
                printf("ANO:%s\n",aux->dados.ano);//APRESENTA O NOME DO CONTATO
                printf("CAMPEAO:%s\n",aux->dados.campeao);//APRESENTA O NOME DO CONTATO
                printf("VICE:%s\n",aux->dados.vice);//APRESENTA O NOME DO CONTATO
                printf("CIDADE:%s\n",aux->dados.cidade);//APRESENTA O NOME DO CONTATO
                printf("------------------------------------------------------\n\n");

                aux = aux->prox;
            }//SE ELE FOR DIFERENTE DE NULL, SIGNIFICA QUE H� ELEMENTO NA LISTA. O PROCESSO DE IMPRESS�O SE REPETE
        }
    }
}

//FUN��O QUE APRESENTAR� APENAS 1 CAMPEONATO
void mostrar1(LISTA *li, char ano2[10])
{
    if(li == NULL)  //SE A LISTA NAO FOR ALOCADA....
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else    //LISTA ALOCADA...
    {
        if(li->inicio==NULL)  //SE O CAMPO FIM FOR IGUAL NULL, A LISTA ESTAR� VAZIA. PODERIA TESTAR TAMB�M A POSI��O INICIAL. TANTO FAZ...
        {
            printf("\nLISTA VAZIA\n");
        }else{//H� ELEMENTO NA LISTA
            //int quantidade=0;//VARIAVEL PARA CONTAR OS CONTATOS
            ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECER� O ENDERE�O DO PRIMEIRO ELEMENTO DA LISTA

            while(aux != NULL){
                if(strcmp(aux->dados.ano,ano2)==0){
                    printf("ANO:%s\n",aux->dados.ano);
                    printf("CAMPEAO:%s\n",aux->dados.campeao);
                    printf("VICE:%s\n",aux->dados.vice);
                    printf("CIDADE:%s\n",aux->dados.cidade);
                    if(aux!=li->inicio&&aux->prox!=NULL){
                        printf("CAMPEAO ANTERIOR (%s):%s\n",aux->ant->dados.ano, aux->ant->dados.campeao);
                        printf("CAMPEAO SEGUINTE (%s):%s\n",aux->prox->dados.ano ,aux->prox->dados.campeao);

                    }else{
                        if(aux==li->inicio){ //SE CAMPEONARO FOR O 1� DA LISTA
                            printf("CAMPEAO ANTERIOR: Nao existe\n");
                            printf("CAMPEAO SEGUINTE (%s):%s\n",aux->prox->dados.ano,aux->prox->dados.campeao);
                        }else{ //SE FOR O ULTIMO CAMPEONATO
                            printf("CAMPEAO ANTERIOR (%s):%s\n",aux->ant->dados.ano,aux->ant->dados.campeao);
                            printf("CAMPEAO SEGUINTE:Nao existe\n");
                    }
                }
                    printf("------------------------------------------------------\n\n");
                }
                aux = aux->prox;
            }//SE ELE FOR DIFERENTE DE NULL, SIGNIFICA QUE H� ELEMENTO NA LISTA. O PROCESSO DE IMPRESS�O SE REPETE
        }
    }
}

//FUN��O DE MENU QUE RETONA A OP��O ESCOLHIDA
int menu()
{
    int op;
    printf("ASSOCIACAO PARAIBANA DE ENXADRISTAS\n");
    printf("-----------------------------------\n");
    printf("\n0 - SAIR\n");
    printf("1 - MOSTRAR TODOS CAMPEONATOS\n");
    printf("2 - MOSTRAR UM CAMPEONATO\n");
    printf("3 - INSERIR NOVO CAMPEONATO\n");
    printf("4 - REMOVER CAMPEONATO\n");
    printf("-----------------------------------\n");
    printf("\nOPCAO: ");
    scanf("%d",&op);
    putchar('\n');
    system("cls");
    return op;//INTEIRO COM A OP��O ESCOLHIDA

}

//FUN��O QUE IR� LER OS DADOS DO CAMPEONATO E ARMAZENAR� NA STRUCT CAMPEONATO

void novoCampeonato(CAMPEONATO*c) //RECEBE COMO PAR�METRO O ENDERE�O DA ESTRUTURA CAMPEONATO
{
    printf("DIGITE O ANO DO CAMPEONATO: ");
    setbuf(stdin,NULL);//LIMPA O BUFFER DO TECLADO (COMANDO PARA WINDOWS)
    gets(c->ano);//ADICIONA O CONTE�DO AO CAMPO ANO
    printf("DIGITE O CAMPEAO: ");
    setbuf(stdin,NULL);
    gets(c->campeao);//ADICIONA O NOME DO CAMPEAO
    printf("DIGITE O VICE-CAMPEAO: ");
    setbuf(stdin,NULL);
    gets(c->vice);//ADICIONA O NOME DO VICE CAMPEAO
    printf("DIGITE A CIDADE: ");
    setbuf(stdin,NULL);
    gets(c->cidade);//ADICIONA O NOME DA CIDADE
}

//FUN��O MAIN..
main()
{
    int o, pos;//VARIAVEL PARA RECEBER A OP��O DIGITADA PELO USU�RIO, E VARIAVAL COM A POSICAO DO CAMPEONATO A SER REMOVIDO
    LISTA *li = criar();//CRIA UM PONTEIRO PARA LISTA, QUE RECEBE O ENDERE�O DA LISTA RETORNADO PELA FUN��O CRIAR();

    CAMPEONATO c;//CRIA UMA ESTRUTURA DO "TIPO" STRUCT CONTATO.
    char ano2[10];

    while((o=menu())!=0)
    {
        switch(o)
        {
        case 0://OPCAO PARA TERMINAR O LA�O E SAIR DO PROGRAMA
            break;
        case 1://OP��O QUE MOSTRA OS ELEMENTOS DA LISTA
            mostrar(li);//CHAMA A FUN��O MOSTRAR. PAR�METRO: ENDERE�O DA LISTA CRIADA (FI � UM PONTEIRO)
            break;
        case 2:
            printf("DIGITE O ANO: >> ");
            setbuf(stdin,NULL);
            gets(ano2);
            mostrar1(li,ano2);//MOSTRAR APENAS 1 CAMPEONATO
            break;
        case 3://OK
            novoCampeonato(&c);//CHAMA A FUN��O QUE LER OS CAMPOS DA ESTRUTURA CAMPEONATO.
            inserir(li,c);//CHAMA A FUN��O QUE INSERE UM ELEMENTO NA LISTA.
            break;
        case 4://OP��O PARA REMO��O
            mostrar(li);
            printf("DIGITE O CODIGO DO CAMPEONATO QUE SERA REMOVIDO >> ");
            scanf("%d",&pos);
            remover(li,pos);//CHAMA A FUN��O DE REMO�AO. PAR�METRO: ENDERE�O DA LISTA CRIADA
            break;
        default:
            printf("OPCAO INVALIDA\n\n");
        }
    }
    liberar(li); //AP�S SAIR DO LA�O, SER� CHAMADA A FUN��O QUE DESALOCA O ESPA�O DE MEM�RIA PARA LISTA.
}
