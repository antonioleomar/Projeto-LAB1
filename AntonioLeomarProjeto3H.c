#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> //biblioteca para uso da função gotoxy e Sleep


//-----------------------------------------------------------------------------------
//Constantes e variáveis Globais
#define ALIN 15 //alinhamento horizontal da tela
//int op1;

// STRUCT: ------------------------------------------------------------------
//-------------------------------------------------------------------------------------
typedef struct{
    char nome[50];
    char cpf[50];
    char contato[50];
    char grupo[50];
}PARTICIPANTE;


typedef struct{
    int capacidade;
    char local[50];
    int cargaHoraria;
    int horario; //considerado horas interias. Ex.: 10h, 11h
    char tema[50];
    char membro[5][50]; //limite de 5 pessoas por grupos
}EVENTO;

typedef struct{
    int capacidade;
    char local[50];
    int cargaHoraria;
    int horario; //considerado horas interias. Ex.: 10h, 11h
    char tema[50];
    PARTICIPANTE *membro; //VARIAVEL TIPO PARTICIPANTE
}EVENTO2;

//ESTRUTURA QUE RECEBERÁ O CONJUNTO DE DADOS DO CONTATO E O ENDEREÇO DO PROXIMO ELEMENTO DA LISTA (O CONTATO A SEGUIR)
typedef struct elemento{
    PARTICIPANTE dados;//AQUI, SERÁ ARMAZENADOS OS DADOS DO CONTATO
    struct elemento *ant;//ESTE CAMPO SERÁ UM PONTEIRO PARA O ANTERIOR ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
    struct elemento *prox;//ESTE CAMPO SERÁ UM PONTEIRO PARA O PRÓXIMO ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
} ELEM;

typedef struct elemento2{
    EVENTO dados;//AQUI, SERÁ ARMAZENADOS OS DADOS DO CONTATO
    struct elemento2 *ant;//ESTE CAMPO SERÁ UM PONTEIRO PARA O ANTERIOR ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
    struct elemento2 *prox;//ESTE CAMPO SERÁ UM PONTEIRO PARA O PRÓXIMO ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
} ELEM2;

//CRIADO NOVO ELEMENTO!!!
typedef struct elemento3{
    EVENTO2 dados;//AQUI, SERÁ ARMAZENADOS OS DADOS DO CONTATO
    struct elemento3 *ant;//ESTE CAMPO SERÁ UM PONTEIRO PARA O ANTERIOR ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
    struct elemento3 *prox;//ESTE CAMPO SERÁ UM PONTEIRO PARA O PRÓXIMO ELEMENTO DA LISTA (QUE TAMBÉM SERÁ DO "TIPO" STRUCT ELEMENTO)
} ELEM3;

//A ESTRUTURA ABAIXO TERA O APONTADOR DO PRIMEIRO ELEMENTO DA LISTA
typedef struct{
    ELEM *inicio; //ESTRUTURA QUE RECEBERÁ O PRIMEIRO ELEMENTO (DADOS DO CONTATO E PROXIMO ELEMENTO) DA LISTA
}LISTA;

typedef struct{
    ELEM2 *inicio; //ESTRUTURA QUE RECEBERÁ O PRIMEIRO ELEMENTO (DADOS DO CONTATO E PROXIMO ELEMENTO) DA LISTA
}LISTA2;

typedef struct{
    ELEM3 *inicio; //ESTRUTURA QUE RECEBERÁ O PRIMEIRO ELEMENTO (DADOS DO CONTATO E PROXIMO ELEMENTO) DA LISTA
}LISTA3;


//-----------------------------------------------------------------------------------
void gotoxy(int x, int y){ //Necessário para rodar a função gotoxy
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

// FUNÇÃO CABEÇALHO: ------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void cabecalho(){
    gotoxy(15,1);printf("------------------------------------------------------\n");
    gotoxy(15,2);printf("------------------------------------------------------\n");
    gotoxy(15,3);printf("ENCONTRO CAMPINENSE DOS ESTUDANTES DE COMPUTACAO-ENCEC\n");
    gotoxy(15,4);printf("------------------------------------------------------\n");
    gotoxy(15,5);printf("------------------------------------------------------\n");
    gotoxy(15,6);printf("------------- 14 e 15 de Dezembro de 2019 ------------\n");
}


// CRIAR: ---------------------------------------------------------------------
//-------------------------------------------------------------------------------------

LISTA* criar(){
    LISTA* li = (LISTA*) malloc(sizeof(LISTA)); //ALOCA O ESPAÇO NA MEMÓRIA
    if(li != NULL) //SE O SISTEMA OPERACIONAL ALOCAR, ENTRA NO IF.
    {
        li->inicio= NULL; //INICIA A POSIÇÃO INICIAL COM NULL
    }
    return li;//RETORNA O ENDEREÇO DA LISTA
}
// CRIAR LISTA DE EVENTOS: ------------------------------------------------------------
//-------------------------------------------------------------------------------------
LISTA* criar2(){
    LISTA2* li = (LISTA2*) malloc(sizeof(LISTA2)); //ALOCA O ESPAÇO NA MEMÓRIA
    if(li != NULL) //SE O SISTEMA OPERACIONAL ALOCAR, ENTRA NO IF.
    {
        li->inicio= NULL; //INICIA A POSIÇÃO INICIAL COM NULL
    }
    return li;//RETORNA O ENDEREÇO DA LISTA
}

// FUNÇÃO MENU 1: ---------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int menu1(){
    system("cls"); //Limpar tela
    system("Color 17"); //muda a cor da fundo e fonte
    int op1;
    //gotoxy(ALIN,30);system ( "date /t" ); //incluir data
    //gotoxy(ALIN,31);system ("time /t"); //incluir hora do sistema
    //int op1; //opção escolhida do usuário no menu 1

    while(1){

        cabecalho();
        gotoxy(ALIN,9);printf("#MENU 1: Escolha a categoria: ________________________");
        gotoxy(ALIN,12);printf("PARTICIPANTES:");
        gotoxy(ALIN,14);printf("[1] PALESTRANTE");
        gotoxy(ALIN,15);printf("[2] CONGRESSISTA");
        gotoxy(ALIN,16);printf("[3] ORGANIZADOR");
        gotoxy(ALIN+30,12);printf("EVENTOS:");
        gotoxy(ALIN+30,14);printf("[4] PALESTRA");
        gotoxy(ALIN+30,15);printf("[5] GRUPOS");
        gotoxy(ALIN+30,16);printf("[6] CURSO");
        gotoxy(ALIN+30,17);printf("[7] OFICINAS");
        gotoxy(ALIN,19);printf("______________________________________________________");
        gotoxy(ALIN,21);printf("Digite o elemento desejado: ");
        gotoxy(ALIN+40,21);printf("(0 para sair)");
        gotoxy(ALIN,22);printf("______________________________________________________");
        gotoxy(ALIN+28,21);scanf("%d",&op1);
        gotoxy(ALIN,22);printf("______________________________________________________");
        if(op1==0||op1==1||op1==2||op1==3||op1==4||op1==5||op1==6||op1==7){
            return op1;//INTEIRO COM A OPÇÃO ESCOLHIDA
            break;
            system("cls");
        }else{
            gotoxy(ALIN,24);printf("STATUS: ERRO: OPCAO INVALIDA! ");
            printf("\a"); //som de bip
            Sleep(1000); //atenção função começa com letra maiuscula
            system("cls");
        }
    }
    system("cls");

}

// FUNÇÃO MENU 2----------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int menu2(int op1){
    char categoria[7][30]={"palestrante","congressita", "organizador", "palestra", "grupos", "curso", "oficinas"}; //Utilizado para alimentar a pergunta do menu2
    system("cls"); //Limpar tela
    system("Color 17"); //cor azul de fundo
    int op2; //opção escolhida do usuário no menu 2

    while(1){
        cabecalho();
        gotoxy(ALIN,9);printf("#MENU 2: O que deseja realizar com %s? ",categoria[op1-1]);
        gotoxy(ALIN,12);printf("[1] CADASTRAR");
        gotoxy(ALIN,13);printf("[2] LISTAR");
        gotoxy(ALIN,14);printf("[3] EDITAR");
        gotoxy(ALIN,15);printf("[4] REMOVER");
        gotoxy(ALIN,16);printf("[5] VOLTAR MENU 1");
        gotoxy(ALIN,19);printf("______________________________________________________");
        gotoxy(ALIN,21);printf("Digite a acao desejada: ");
        gotoxy(ALIN,22);printf("______________________________________________________");
        gotoxy(ALIN+24,21);scanf("%d",&op2);
        gotoxy(ALIN,22);printf("______________________________________________________");
        if(op2==1||op2==2||op2==3||op2==4||op2==5){
            return op2; //INTEIRO COM A OPÇÃO ESCOLHIDA
            system("cls");
            break;
        }else{
            gotoxy(ALIN,24);printf("STATUS: ERRO: OPCAO INVALIDA! ");
            printf("\a"); //som de bip
            Sleep(1000); //atenção função começa com letra maiuscula
            system("cls");
        }
    }
    system("cls"); //Limpar tela
}



// FUNÇÃO CADASTRAR PARTICIPANTES -----------------------------------------------------
//-------------------------------------------------------------------------------------
void cadastrarParticipante(int o1, PARTICIPANTE *c){
    system("cls"); //Limpar tela
    int op;

    cabecalho();
    gotoxy(ALIN,9);printf("#MENU 3: Cadastrar participante");
    gotoxy(ALIN,11);printf("______________________________________________________");
    gotoxy(ALIN,13);printf("NOME:");
    gotoxy(ALIN,15);printf("CPF:");
    gotoxy(ALIN,17);printf("CONTATO:");
    gotoxy(ALIN,19);printf("GRUPO:");
    gotoxy(ALIN,20);printf("______________________________________________________");
    setbuf(stdin,NULL);
    gotoxy(ALIN+5,13);gets(c->nome);
    setbuf(stdin,NULL);
    gotoxy(ALIN+4,15);gets(c->cpf);
    setbuf(stdin,NULL);
    gotoxy(ALIN+8,17);gets(c->contato);
    setbuf(stdin,NULL);
    gotoxy(ALIN+6,19);gets(c->grupo);
    //gotoxy(ALIN,22);system("pause");
}


// FUNÇÃO CADASTRAR EVENTOS> PALESTRA -----------------------------------------------------------
//-------------------------------------------------------------------------------------

void cadastrarEvento(int o1, EVENTO2 *d2, LISTA *li){ //RECEBER LISTA EX.: PALESTRA
    system("cls"); //Limpar tela
    int op, escolha;

    cabecalho();
    gotoxy(ALIN,9);printf("#MENU 3: Cadastrar evento");
    gotoxy(ALIN,11);printf("______________________________________________________");
    gotoxy(ALIN,13);printf("CAPACIDADE:");
    gotoxy(ALIN,14);printf("LOCAL:");
    gotoxy(ALIN,15);printf("CARGA HORARIA:");
    gotoxy(ALIN,16);printf("HORARIO:");
    gotoxy(ALIN,17);printf("TEMA:");
    gotoxy(ALIN,18);printf("CODIGO DO PALESTRANTE:");
    gotoxy(ALIN,20);printf("______________________________________________________");
    setbuf(stdin,NULL);

    if(o1==4){
        gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
        while(d2->capacidade>150){
            gotoxy(ALIN,22);printf("STATUS: CAPACIDADE MAXIMA DE 150");
            //setbuf(stdin,NULL);
            gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
        }
    }else{
        if(o1==5){
            gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
            while(d2->capacidade>50){
                gotoxy(ALIN,22);printf("STATUS: CAPACIDADE MAXIMA DE 50");
                //setbuf(stdin,NULL);
                gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
            }
        }else{
            if(o1==6){
                gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
                while(d2->capacidade>40){
                    gotoxy(ALIN,22);printf("STATUS: CAPACIDADE MAXIMA DE 40");
                    //setbuf(stdin,NULL);
                    gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
                }
            }else{
                gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
                while(d2->capacidade>40){
                    gotoxy(ALIN,22);printf("STATUS: CAPACIDADE MAXIMA DE 40");
                    //setbuf(stdin,NULL);
                    gotoxy(ALIN+11,13);scanf("%d",&d2->capacidade);
                }
            }
        }
    }

    //gotoxy(ALIN+11,13);scanf("%d",&d->capacidade);
    setbuf(stdin,NULL);
    gotoxy(ALIN+6,14);gets(d2->local);
    setbuf(stdin,NULL);
    gotoxy(ALIN+14,15);scanf("%d",&d2->cargaHoraria);
    setbuf(stdin,NULL);
    if(o1==5||o1==6||o1==7){
        gotoxy(ALIN+8,16);scanf("%d",&d2->horario);
        while(d2->horario<12){
            gotoxy(ALIN,22);printf("STATUS: HORARIO APENAS A TARDE");
            //setbuf(stdin,NULL);
            gotoxy(ALIN+8,16);scanf("%d",&d2->horario);
        }
    }else{
        gotoxy(ALIN+8,16);scanf("%d",&d2->horario);
        while(d2->horario>12){
            gotoxy(ALIN,22);printf("STATUS: HORARIO DAS PALESTRAS APENAS PELA MANHA");
            //setbuf(stdin,NULL);
            gotoxy(ALIN+8,16);scanf("%d",&d2->horario);
        }
    }
    //gotoxy(ALIN+8,16);scanf("%d",&d->horario);
    setbuf(stdin,NULL);
    gotoxy(ALIN+5,17);gets(d2->tema);
    setbuf(stdin,NULL);
    gotoxy(ALIN+15,18);scanf("%d",&escolha);


    int quantidade=0;//VARIAVEL PARA CONTAR OS CONTATOS
        ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECERÁ O ENDEREÇO DO PRIMEIRO ELEMENTO DA LISTA

        while(aux != NULL && escolha!=quantidade){
            quantidade++;
            if(quantidade==escolha){
                d2->membro=&(aux->dados.nome);///////////////////  <---------------------MUDANDO AQUI!

            }else{
                gotoxy(ALIN,22);printf("STATUS: PALESTRANTE NAO ENCONTRADO");
            }
            aux = aux->prox;
        }

}

// INSERIR PARTICIPANTE ---------------------------------------------------------------
//-------------------------------------------------------------------------------------

void inserir(LISTA *li, PARTICIPANTE c) //COMO PARÂMETROS DA FUNÇÃO, TEREMOS: O ENDEREÇO DA LISTA ; E OS DADOS DO CONTATO (QUE SERÃO ARMAZENADOS NA MINHA STRUCT CONTATO)
{
    if(li==NULL) //CASO A LISTA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA
    {
        ELEM *novo = (ELEM*) malloc(sizeof(ELEM));//NESTE PASSO, SERÁ CRIADO UM NOVO ELEMENTO VAZIO (CRIADO APENAS O ESPAÇO NA MEMÓRIA)
        if(novo != NULL) //CASO A ALOCAÇÃO DESTE NOVO ELEMENTO TENHA SIDO FEITA
        {
            novo->dados= c;//O CAMPO DADOS, DA MINHA ESTRUTURA ELEMENTO RECEBE OS DADOS DO CONTATO PASSADO POR PARÂMETRO DA FUNÇÃO
            if(li->inicio==NULL){//LISTA VAZIA
                novo->prox=NULL;
                novo->ant=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                if(strcmp(li->inicio->dados.nome,novo->dados.nome)>0){//INSERÇÃO NO INICIO
                    novo->ant=NULL;
                    novo->prox=li->inicio;
                    li->inicio->ant=novo;
                    li->inicio=novo;
                }else{//INSERÇÃO NO MEIO OU FIM
                    ELEM *ante,*aux=li->inicio;
                    while((aux!=NULL)&&(strcmp(aux->dados.nome,novo->dados.nome)<=0)){
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
            gotoxy(ALIN,22);printf("STATUS: Elemento inserido com sucesso!");
        }
        else  //SE MINHA LISTA NAO ESTIVER ALOCADA...
        {
            gotoxy(ALIN,22);printf("STATUS: Erro de alocação!");
        }
    }gotoxy(ALIN,24);system("pause");
}
// INSERIR EVENTO ---------------------------------------------------------------------
//-------------------------------------------------------------------------------------


// INSERIR EVENTO PALESTRA ------------------------------------------------------------
//-------------------------------------------------------------------------------------
void inserirEvento(LISTA3 *li, EVENTO2 d2) //COMO PARÂMETROS DA FUNÇÃO, TEREMOS: O ENDEREÇO DA LISTA ; E OS DADOS DO CONTATO (QUE SERÃO ARMAZENADOS NA MINHA STRUCT CONTATO)
{
    if(li==NULL) //CASO A LISTA NAO TENHA SIDO ALOCADA...
    {
        printf("\nERRO DE ALOCACAO\n");
    }
    else  //LISTA ALOCADA
    {
        ELEM3 *novo = (ELEM3*) malloc(sizeof(ELEM3));//NESTE PASSO, SERÁ CRIADO UM NOVO ELEMENTO VAZIO (CRIADO APENAS O ESPAÇO NA MEMÓRIA)
        if(novo != NULL) //CASO A ALOCAÇÃO DESTE NOVO ELEMENTO TENHA SIDO FEITA
        {
            novo->dados= d2;//O CAMPO DADOS, DA MINHA ESTRUTURA ELEMENTO RECEBE OS DADOS DO CONTATO PASSADO POR PARÂMETRO DA FUNÇÃO
            if(li->inicio==NULL){//LISTA VAZIA
                novo->prox=NULL;
                novo->ant=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                if(strcmp(li->inicio->dados.tema,novo->dados.tema)>0){//INSERÇÃO NO INICIO
                    novo->ant=NULL;
                    novo->prox=li->inicio;
                    li->inicio->ant=novo;
                    li->inicio=novo;
                }else{//INSERÇÃO NO MEIO OU FIM
                    ELEM2 *ante,*aux=li->inicio;
                    while((aux!=NULL)&&(strcmp(aux->dados.tema,novo->dados.tema)<=0)){
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
            gotoxy(ALIN,22);printf("STATUS: Elemento inserido com sucesso!");
        }
        else  //SE MINHA LISTA NAO ESTIVER ALOCADA...
        {
            gotoxy(ALIN,22);printf("STATUS: Erro de alocação!");
        }
    }gotoxy(ALIN,24);system("pause");
}


// LISTAR PARTICIPANTE-----------------------------------------------------------------
//-------------------------------------------------------------------------------------

//FUNÇÃO QUE APRESENTARÁ OS CONTATOS ARMAZENADOS NA LISTA
void listar(LISTA *li){
    system("cls");
    cabecalho();
    int cont=0;
    gotoxy(ALIN,9);printf("#LISTA DOS PARTICIPANTES");
    if(li == NULL)  //SE A LISTA NAO FOR ALOCADA....
    {
        gotoxy(ALIN,11);printf("ERRO DE ALOCACAO");
    }
    else    //LISTA ALOCADA...
    {
        if(li->inicio==NULL)  //SE O CAMPO FIM FOR IGUAL NULL, A LISTA ESTARÁ VAZIA. PODERIA TESTAR TAMBÉM A POSIÇÃO INICIAL. TANTO FAZ...
        {
            gotoxy(ALIN,11);printf("LISTA VAZIA");
        }else{//HÁ ELEMENTO NA LISTA
            int quantidade=0;//VARIAVEL PARA CONTAR OS CONTATOS
            ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECERÁ O ENDEREÇO DO PRIMEIRO ELEMENTO DA LISTA

            while(aux != NULL){
                quantidade++;
                gotoxy(ALIN,11+cont);printf("#:%d",quantidade);
                gotoxy(ALIN,12+cont);printf("NOME:%s",aux->dados.nome);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,13+cont);printf("CPF:%s\n",aux->dados.cpf);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,14+cont);printf("CONTATO:%s\n",aux->dados.contato);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,15+cont);printf("GRUPO:%s\n",aux->dados.grupo);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,16+cont);printf("------------------------------------------------------");
                cont=cont+6;
                aux = aux->prox;//O ELEMENTO AUXILIAR RECEBE O ENDEREÇO DO PRÓXIMO ELEMENTO
            }//SE ELE FOR DIFERENTE DE NULL, SIGNIFICA QUE HÁ ELEMENTO NA LISTA. O PROCESSO DE IMPRESSÃO SE REPETE
        }
    }gotoxy(ALIN,12+cont);system("pause");
}


// LISTAR EVENTO PALESTRA-----------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void listarEvento(LISTA3 *li){
    system("cls");
    cabecalho();
    int cont=0;
    gotoxy(ALIN,9);printf("#LISTA DOS EVENTOS");
    if(li == NULL)  //SE A LISTA NAO FOR ALOCADA....
    {
        gotoxy(ALIN,11);printf("ERRO DE ALOCACAO");
    }
    else    //LISTA ALOCADA...
    {
        if(li->inicio==NULL)  //SE O CAMPO FIM FOR IGUAL NULL, A LISTA ESTARÁ VAZIA. PODERIA TESTAR TAMBÉM A POSIÇÃO INICIAL. TANTO FAZ...
        {
            gotoxy(ALIN,11);printf("LISTA VAZIA");
        }else{//HÁ ELEMENTO NA LISTA
            int quantidade=0;//VARIAVEL PARA CONTAR OS CONTATOS
            ELEM3* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECERÁ O ENDEREÇO DO PRIMEIRO ELEMENTO DA LISTA

            while(aux != NULL){
                quantidade++;
                gotoxy(ALIN,11+cont);printf("#:%d",quantidade);
                gotoxy(ALIN,12+cont);printf("CAPACIDADE:%d",aux->dados.capacidade);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,13+cont);printf("LOCAL:%s\n",aux->dados.local);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,14+cont);printf("CARGA HORARIA:%d\n",aux->dados.cargaHoraria);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,15+cont);printf("HORARIO:%d\n",aux->dados.horario);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,16+cont);printf("TEMA:%s\n",aux->dados.tema);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,17+cont);printf("MEMBRO(S):%s\n",aux->dados.membro);//APRESENTA O NOME DO CONTATO
                gotoxy(ALIN,18+cont);printf("------------------------------------------------------");
                cont=cont+8;
                aux = aux->prox;//O ELEMENTO AUXILIAR RECEBE O ENDEREÇO DO PRÓXIMO ELEMENTO
            }//SE ELE FOR DIFERENTE DE NULL, SIGNIFICA QUE HÁ ELEMENTO NA LISTA. O PROCESSO DE IMPRESSÃO SE REPETE
        }
    }gotoxy(ALIN,12+cont);system("pause");
}

// REMOVER ----------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//FUNÇÃO QUE APRESENTARÁ A LISTA E REMOVERÁ O ELEMENTO ESCOLHIDO
void remover(LISTA *li, int pos){
    //system("cls");
    cabecalho();
    if(li==NULL){
        gotoxy(ALIN,23);printf("STATUS: Erro de alocação da lista");
    }else{
        if(li->inicio==NULL){
            gotoxy(ALIN,23);printf("STATUS: Lista vazia");
        }else{

            ELEM*aux=li->inicio;
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
            gotoxy(ALIN,22);printf("______________________________________________________");
            gotoxy(ALIN,23);printf("STATUS: Elemento removido com sucesso");
        }
    }gotoxy(ALIN,25);system("pause");
}

// REMOVER EVENTO ---------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void removerEvento(LISTA2 *li, int pos){
    //system("cls");
    cabecalho();
    if(li==NULL){
        gotoxy(ALIN,23);printf("STATUS: Erro de alocação da lista");
    }else{
        if(li->inicio==NULL){
            gotoxy(ALIN,23);printf("STATUS: Lista vazia");
        }else{

            ELEM2*aux=li->inicio;
            int cont=1;
            if(cont==pos){//SE O ELEMENTO FOR O PRIMEIRO DA LISTA
                li->inicio=aux->prox;
                if(aux->prox!=NULL)
                    aux->prox->ant=NULL;
                free(aux);
            }else{//O ELEMENTO NAO ESTA NO INICIO DA LISTA
                ELEM2 *ant;
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
            gotoxy(ALIN,22);printf("______________________________________________________");
            gotoxy(ALIN,23);printf("STATUS: Elemento removido com sucesso");
        }
    }gotoxy(ALIN,25);system("pause");
}


// EDITAR -----------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void editar(LISTA *li, int pos){
    system("cls");
    cabecalho();
    if(li==NULL){//ERRO DE ALOCAÇÃO
        gotoxy(ALIN,22);printf("STATUS: Erro de alocação da lista");
    }else{
        if(li->inicio==NULL){ //LISTA VAZIA
            gotoxy(ALIN,22);printf("STATUS: Lista vazia");
        }else{
            ELEM*novo=li->inicio;
            int cont=1;
            while(novo!=NULL){

                if(cont == pos){

                //RECADASTRAR PARTICIPANTE ////////////////////////////////////////////////////////////
                system("cls"); //Limpar tela

                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Editar");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("NOME:");
                gotoxy(ALIN,15);printf("CPF:");
                gotoxy(ALIN,17);printf("CONTATO:");
                gotoxy(ALIN,19);printf("GRUPO:");
                gotoxy(ALIN,20);printf("______________________________________________________");
                setbuf(stdin,NULL);
                gotoxy(ALIN+5,13);gets(novo->dados.nome);
                setbuf(stdin,NULL);
                gotoxy(ALIN+4,15);gets(novo->dados.cpf);
                setbuf(stdin,NULL);
                gotoxy(ALIN+8,17);gets(novo->dados.contato);
                setbuf(stdin,NULL);
                gotoxy(ALIN+6,19);gets(novo->dados.grupo);
                }
                cont++;novo=novo->prox;
            }
            if(pos>cont){
                gotoxy(ALIN,22);printf("STATUS:NAO EXISTE NA LISTA");
            }
        }
        }


    gotoxy(ALIN,23);system("pause");
}

// EDITAR EVENTO ----------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void editar2(LISTA2 *li, int pos){
    system("cls");
    cabecalho();
    if(li==NULL){//ERRO DE ALOCAÇÃO
        gotoxy(ALIN,22);printf("STATUS: Erro de alocação da lista");
    }else{
        if(li->inicio==NULL){ //LISTA VAZIA
            gotoxy(ALIN,22);printf("STATUS: Lista vazia");
        }else{
            ELEM2*novo=li->inicio;
            int cont=1;
            while(novo!=NULL){

                if(cont == pos){

                //RECADASTRAR PARTICIPANTE ////////////////////////////////////////////////////////////
                system("cls"); //Limpar tela

                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Editar");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("CAPACIDADE:");
                gotoxy(ALIN,14);printf("LOCAL:");
                gotoxy(ALIN,15);printf("CARGA HORARIA:");
                gotoxy(ALIN,16);printf("HORARIO:");
                gotoxy(ALIN,17);printf("TEMA:");
                gotoxy(ALIN,18);printf("MEMBRO:");
                gotoxy(ALIN,20);printf("______________________________________________________");
                setbuf(stdin,NULL);
                gotoxy(ALIN+11,13);scanf("%d", &novo->dados.capacidade);
                setbuf(stdin,NULL);
                gotoxy(ALIN+6,14);gets(novo->dados.local);
                setbuf(stdin,NULL);
                gotoxy(ALIN+14,15);scanf("%d",&novo->dados.cargaHoraria);
                setbuf(stdin,NULL);
                gotoxy(ALIN+8,16);scanf("%d",&novo->dados.horario);
                setbuf(stdin,NULL);
                gotoxy(ALIN+5,17);gets(novo->dados.tema);
                setbuf(stdin,NULL);
                gotoxy(ALIN+7,18);gets(novo->dados.membro);
                }
                cont++;novo=novo->prox;
            }
            if(pos>cont){
                gotoxy(ALIN,22);printf("STATUS:NAO EXISTE NA LISTA");
            }
        }
        }

    gotoxy(ALIN,23);system("pause");
}

// QUANTIDADE ----------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int tamanho(LISTA *li){
    if(li==NULL){
        return -1;//CASO MINHA LISTA NAO TENHA SIDO ALOCADA NA MEMÓRIA, MINHA FUNÇÃO RETORNARÁ O VALOR -1
    }
    int cont=0;//VARIAVEL QUE CONTARÁ A QUANTIDADE DE ELEMENTOS
    ELEM *aux = li->inicio;//CRIA UM PONTEIRO AUXILIAR PARA PERCORRER MINHA LISTA. DESTA FORMA, CADA PASSO DADO PELO ELEMENTO AXULIAR SERÁ UM ELEMENTO DA MINHA LISTA
    while(aux != NULL) //ENQUANTO O ELEMENTO AUXILIAR NAO APONTAR PARA NULL,
    {
        cont++;//INCREMENTA A MINHA LISTA (SE ELE ENTROU NO WHILE NA PRIMEIRA INTERAÇÃO, SIGNIFICA QUE HÁ PELO MENOS UM ELEMENTO DA LISTA
        aux= aux->prox;//NESTE MOMENTO, NÓ RECEBERA O ENDEREÇO QUE ESTÁ NO CAMPO PRÓXIMO.
    }//SE ELE FOR IGUAL A NULL. TERMINA O LAÇO. SE NAO, SERÁ CONTABILIZADO UM NOVO ELEMENTO.
    return cont;//FUNÇÃO RETORNA A QUANTIRADE DE ELEMENTOS
}

//------------------------------------------------------------------------------------
main(){

    //LISTAS DOS PARTICIPANTES:
    LISTA *li = criar();//CRIA UM PONTEIRO PARA LISTA, QUE RECEBE O ENDEREÇO DA LISTA RETORNADO PELA FUNÇÃO CRIAR();
    LISTA *liPalestrante = criar(); // LISTA PARA PARTICIPANTES > PALESTRANTES
    LISTA *liCongressista = criar(); // LISTA PARA PARTICIPANTES > CONGRESSISTA
    LISTA *liOrganizadores = criar(); // LISTA PARA PARTICIPANTES > ORGANIZADORES
    //LISTAS DOS EVENTOS:
    LISTA3 *liPalestras = criar2(); // LISTA PARA EVENTOS > PALESTRAS
    LISTA3 *liGrupos = criar2(); // LISTA PARA EVENTOS > GRUPOS
    LISTA3 *liCursos= criar2(); // LISTA PARA EVENTOS > CURSOS
    LISTA3 *liOficinas= criar2(); // LISTA PARA EVENTOS > OFICINAS

    //VARIÁVEIS:
    PARTICIPANTE c;//CRIA UMA ESTRUTURA DO "TIPO" STRUCT PARTICIPANTE.
    EVENTO d; //CRIA UMA ESTRUTURA DO "TIPO" STRUCT EVENTO.
    EVENTO2 d2;
    int o1, o2, pos, tam; //RESPOSTA DO MENU1, MENU2, POSIÇÃO PARA REMOVER ELEMENTO DA LISTA, TAMANHO DA LISTA

    while((o1=menu1())!=0){
        system("cls"); //Limpar tela
        o2=menu2(o1);
        system("cls"); //Limpar tela

        if(o1==1){ //ESCOLHA DE PALESTRANTE
            switch(o2){
            case 1: //INSERIR PALESTRANTE
                cadastrarParticipante(o1,&c);
                inserir(liPalestrante,c);
                break;
            case 2:
                listar(liPalestrante); //LISTAR PALESTRANTE
                break;
            case 3: //EDITAR PALESTRANTE
                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Editar");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("Digite o codigo do contato que sera editado >> ");
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN+48,13);scanf("%d",&pos);
                editar(liPalestrante,pos);break;
            case 4://REMOVER PALESTRANTE
                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Remover");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("Digite o codigo do contato que sera removido >> ");
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN+48,13);scanf("%d",&pos);
                remover(liPalestrante,pos);
            default: //NENHUMA DAS OPÇÕES
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN,23);printf("STATUS: OPCAO INVALIDA");
                }
        }else{
            if(o1==2){ // ESCOLHA DE CONGRESSISTA
                switch(o2){
            case 1: //INSERIR CONGRESSISTA
                tam=tamanho(liCongressista)+1;
                if(tam>300){
                    cabecalho();
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+2,13);printf("STATUS: ATINGIU LIMITE MAXIMO DE 300 CONGRESSISTAS");
                    gotoxy(ALIN,24);system("pause");
                }else{
                    //printf("%d",tam);
                    cadastrarParticipante(o1,&c);
                    inserir(liCongressista,c);
                }
                break;
            case 2: //LISTAR CONGRESSISTA
                listar(liCongressista);
                break;
            case 3: //EDITAR CONGRESSISTA
                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Editar");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("Digite o codigo do contato que sera editado >> ");
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN+48,13);scanf("%d",&pos);
                editar(liCongressista,pos);break;
            case 4://REMOVER CONGRESSISTA
                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Remover");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("Digite o codigo do contato que sera removido >> ");
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN+48,13);scanf("%d",&pos);
                remover(liCongressista,pos);
            default: //NENHUMA DAS OPÇÕES
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN,23);printf("STATUS: OPCAO INVALIDA");
                }

        }else{
            if(o1==3){ // ESCOLHA DOS ORGANIZADORES
                switch(o2){
            case 1: //INSERIR ORGANIZADORES
                cadastrarParticipante(o1,&c);
                inserir(liOrganizadores,c);
                break;
            case 2: //LISTAR ORGANIZADORES
                listar(liOrganizadores);
                break;
            case 3: //EDITAR ORGANIZADORES
                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Editar");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("Digite o codigo do contato que sera editado >> ");
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN+48,13);scanf("%d",&pos);
                editar(liOrganizadores,pos);break;
            case 4: //REMOVER CONGRESSISTA
                cabecalho();
                gotoxy(ALIN,9);printf("#MENU 3: Remover");
                gotoxy(ALIN,11);printf("______________________________________________________");
                gotoxy(ALIN,13);printf("Digite o codigo do contato que sera removido >> ");
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN+48,13);scanf("%d",&pos);
                remover(liOrganizadores,pos);
            default://NENHUMA DAS OPÇÕES
                gotoxy(ALIN,22);printf("______________________________________________________");
                gotoxy(ALIN,23);printf("STATUS: OPCAO INVALIDA");
                }


            // EVENTOS: /////////////////////////////////////////////////////////////////////////////////////////////////

            }else{
            if(o1==4){ // ESCOLHA DE PALESTRAS
                switch(o2){
                case 1: //INSERIR PALESTRAS
                    cadastrarEvento(o1,&d2,liPalestrante);
                    inserirEvento2(liPalestras,d2);
                    break;
                case 2: //LISTAR PALESTRAS
                    listarEvento(liPalestras);
                    break;
                case 3: //EDITAR PALESTRAS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Editar");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera editado >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    editar2(liPalestras,pos);break;
                case 4://REMOVER PALESTRAS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Remover");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera removido >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    removerEvento(liPalestras,pos);
                default: //NENHUMA DAS OPÇÕES
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN,23);printf("STATUS: OPCAO INVALIDA");
                }
            }else{
            if(o1==5){ // ESCOLHA DE GRUPOS
                switch(o2){
                case 1: //INSERIR GRUPOS
                    cadastrarEvento(o1,&d);
                    inserirEvento(liGrupos,d);
                    break;
                case 2: //LISTAR GRUPOS
                    listarEvento(liGrupos);
                    break;
                case 3: //EDITAR GRUPOS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Editar");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera editado >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    editar2(liGrupos,pos);break;
                case 4://REMOVER GRUPOS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Remover");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera removido >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    removerEvento(liGrupos,pos);
                default: //NENHUMA DAS OPÇÕES
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN,23);printf("STATUS: OPCAO INVALIDA");
                }
            }else{
            if(o1==6){ // ESCOLHA DE CURSOS
                switch(o2){
                case 1: //INSERIR CURSOS
                    cadastrarEvento(o1,&d);
                    inserirEvento(liCursos,d);
                    break;
                case 2: //LISTAR CURSOS
                    listarEvento(liCursos);
                    break;
                case 3: //EDITAR CURSOS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Editar");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera editado >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    editar2(liCursos,pos);break;
                case 4://REMOVER CURSOS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Remover");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera removido >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    removerEvento(liCursos,pos);
                default: //NENHUMA DAS OPÇÕES
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN,23);printf("STATUS: OPCAO INVALIDA");
                }
            }else{
            if(o1==7){ // ESCOLHA DE OFICINAS
                switch(o2){
                case 1: //INSERIR OFICINAS
                    cadastrarEvento(o1,&d);
                    inserirEvento(liOficinas,d);
                    break;
                case 2: //LISTAR OFICINAS
                    listarEvento(liOficinas);
                    break;
                case 3: //EDITAR OFICINAS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Editar");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera editado >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    editar2(liOficinas,pos);break;
                case 4://REMOVER OFICINAS
                    cabecalho();
                    gotoxy(ALIN,9);printf("#MENU 3: Remover");
                    gotoxy(ALIN,11);printf("______________________________________________________");
                    gotoxy(ALIN,13);printf("Digite o codigo do evento que sera removido >> ");
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN+48,13);scanf("%d",&pos);
                    removerEvento(liOficinas,pos);
                default: //NENHUMA DAS OPÇÕES
                    gotoxy(ALIN,22);printf("______________________________________________________");
                    gotoxy(ALIN,23);printf("STATUS: OPCAO INVALIDA");
                }
    }}}}}}}}}


