#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{//ESTRUTURA PARA CADASTRO DE CLIENTE;
    char nome[30], celular[12], motivo[20];
    int idade;
    float plano;
}CadCliente;

typedef struct{//ESTRUTURA PARA CADASTRO DE FUNCIONARIO;
    char nome[50], funcao[20], turno[20], celular[15];
    int idade;
}CadFuncionario;

typedef struct{
    int p, num;
    float pago, plan, troco;
}recibo;

int TelaLogin(){ //TELA DE LOGIN PARA ACESSAR O PROGRAMA;
    char senha[12], usuario[12];
    int *user; //VETOR PARA DETERMINAR O DOMINIO
    user = malloc(sizeof(int));
    printf("================TELA DE LOGIN================\n");
    do{ //ESTRUTURA DE REPETICAOO ATE ACERTAR A SENHA E O USUARIO;
        printf("USUARIO: ");
        gets(usuario);
        printf("SENHA: ");
        gets(senha);
        if (strcmp(senha, "admin") ==0 && strcmp(usuario, "admin") ==0)//USER COM TOTAL DOMINIO, PARA OS GERENTES;
            user = 1;
        else if (strcmp(senha, "recepcao") ==0 && strcmp(usuario, "recepcao") ==0)//USER COM DOMINIO AMPLO, PARA RECEPCAOO;
            user = 2;
        else if (strcmp(senha, "treinador") ==0 && strcmp(usuario, "treinador") ==0)//USER COM DOMINIO MEDIO, PARA CONSULTAS DE CLIENTES;
            user = 3;
        else if (strcmp(senha, "cliente") ==0 && strcmp(usuario, "cliente") ==0)//USER COM POUCO DOMINIO, PARA CADASTRO;
            user = 4;
        else{
            printf("==========USUARIO OU SENHA INVALIDO==========\n===============TENTE NOVAMENTE!==============\n=============================================\n");
        }
    }while(user < 1 || user > 4);
    printf("================LOGIN ACEITO!================\n");
    system("pause");//PAUSA A TELA;
    system("cls"); //LIMPA A TELA;
    return user;
}

int MenuInicial(int user){ //TELA DE MENU INICIAL PARA SELECIONAR A EXECUCAOO "user" DETERMINA QUAIS OPCOES TERA PELO SEU DOMINIO;
    int opcao;
    bool confirmacao = false;
    printf("======BEM VINDO A ACADEMIA========\n==================================\n");
    printf("=========MENU DE OPCOES===========\n\n");
    printf("============CADASTROS=============\n\n[1] CADASTRO DE FUNCIONARIO\n[2] CADASTRO DE CLIENTE\n\n");
    printf("=========ALTERAR DADOS============\n\n[3] ALTERAR DADOS DE FUNCIONARIOS\n[4] ALTERAR DADOS DE CLIENTE\n\n");
    printf("=============LISTAS===============\n\n[5] LISTA DE FUNCIONARIOS\n[6] LISTA DE CLIENTE\n\n");
    printf("==================================\n\n[0] SAIR DO PROGRAMA\n\n");
    printf("OPCAO: ");
    scanf("%d", &opcao);
    while(opcao > 6 || opcao < 0){ //ESTRUTURA DE REPETICAOO PARA ACEITAR APENAS AS OPCOES DISPONIVEIS;
        printf("\n=========OPCAOO INVALIDA===========\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);
    }
    do{ //ESTRUTURA DE REPETICAOO PARA INIBIR ACESSO A FUNCOES FORA DE SEU DOMINIO;
        if ((opcao == 1 || opcao == 3 || opcao == 5 ) && user != 1){
            printf("  VOCE NAO TEM ACESSO A ESSA OPCAO! TENTE NOVAMENTE!!\n");
            printf(" OPCAO: ");
            scanf("%d", &opcao);
        }
        else if((opcao == 2 || opcao == 4) && user > 2){
            printf("  VOCE NAO TEM ACESSO A ESSA OPCAO! TENTE NOVAMENTE!!\n");
            printf(" OPCAO: ");
            scanf("%d", &opcao);
        }
        else if (opcao == 6 && user > 3){
            printf("  VOCE NAO TEM ACESSO A ESSA OPCAO! TENTE NOVAMENTE!!\n");
            printf(" OPCAO: ");
            scanf("%d", &opcao);
        }
        else confirmacao = true;
    }while(confirmacao==false);
    system("pause");//PAUSA A TELA;
    system("cls"); //LIMPA A TELA;
    return opcao;
}

int CadastroF(CadFuncionario **f, int quant, int tam){ //TELA DE CADASTROS PARA ADICIONAR FUNCIONARIOS E CLIENTES
    int escolha;
    CadFuncionario *novo = malloc(sizeof(CadFuncionario));

    if(quant< tam){

        system("cls"); //LIMPA A TELA;
        printf("\n.....................................\n");
        printf("\tCADASTRO DE FUNCIONARIO");
        printf("\n.....................................\n");

        printf(" NOME(SEM ESPACO): ");
        scanf("%s", novo->nome);

        printf(" CELULAR: ");
        scanf("%s", novo->celular);

        printf(" IDADE: ");
        scanf("%d", &novo->idade);


        printf("\n==============FUNCAO==============\n [1] LIMPEZA\n [2] TREINADOR\n [3] RECEPCAO\n [4] ADMINISTRACAO\n OPCAO: ");
        scanf("%d", &escolha);

        while(escolha > 4 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
            printf("TENTE NOVAMENTE!\n");
            scanf("%d", &escolha);
        }
        if (escolha == 1){
            strcpy(novo->funcao, "LIMPEZA");
        }
        else if (escolha == 2){
            strcpy(novo->funcao, "TREINADOR");
        }
        else if (escolha == 3){
            strcpy(novo->funcao, "RECEPCAO");
        }
        else{
            strcpy(novo->funcao, "ADMINISTRACAO");
        }
        printf("\n==============TURNO===============\n [1] MANHA\n [2] TARDE\n [3] NOITE\n OPCAO: ");
        scanf("%d", &escolha);
        while(escolha > 3 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
            printf("TENTE NOVAMENTE!\n");
            scanf("%d", &escolha);
        }
        if (escolha == 1){
            strcpy(novo->turno, "MANHA");
        }
        else if (escolha == 2){
            strcpy(novo->turno, "TARDE");
        }
        else{
            strcpy(novo->turno, "NOITE");
        }
        printf("CADASTRO REALIZADO!!\n");
        f[quant] = novo;
        system("pause");//PAUSA A TELA;
        system("cls"); //LIMPA A TELA;
        return 1;
    }
    else{
        printf("\nLIMITE DE FUNCIONARIOS ATINGIDO!\n");
        system("pause");//PAUSA A TELA;
        system("cls"); //LIMPA A TELA;
        return 0;
    }
}

void SalvarF(CadFuncionario **f, int quant){
    FILE *pont_arq = fopen("cadastrofuncionarios.dat", "ab");
    int i;

    if(pont_arq){
        for(i = 0; i<quant; i++){
            fwrite(f[i], sizeof(CadFuncionario), 1, pont_arq);
        }
    }
    else{
        printf("\n!!!!!ERRO AO ABRIR ARQUIVO!!!!!\n");
    }
    fclose(pont_arq);
}

int LerF(CadFuncionario **f){
    int quant = 0;
    CadFuncionario *novo = malloc(sizeof(CadFuncionario));
    system("cls");
    FILE *pont_arq = fopen("cadastrofuncionarios.dat", "rb"); //ABRE O ARQUIVO CADASTRO DE FUNCIONARIOS COMO FORMA DE LEITURA;

    if (pont_arq){
        while(fread(novo, sizeof(CadFuncionario), 1, pont_arq)){
            f[quant] = novo;
            quant++;
            novo = malloc(sizeof(CadFuncionario));
        }
    }
    else{  //ESTRUTURA DE CONDICAO PARA CASO DE ERRO EM ABRIR O ARQUIVO;
        printf("\n!!!!!ERRO AO ABRIR ARQUIVO!!!!!\n");
    }
    fclose(pont_arq);
}

int ListaF(){
    FILE *pont_arq = fopen("cadastrofuncionarios.dat", "rb+");
    CadFuncionario *f = malloc(sizeof(CadFuncionario));
    int cadf=1;

    if(pont_arq){
    printf("\n.....................................\n");
    printf("\tLISTA DE FUNCIONARIO");
    printf("\n.....................................\n");
    while(fread(f, sizeof(CadFuncionario), 1, pont_arq)){
        printf("\n\tFUNCIONARIO %d \nNOME: %s\nCELULAR: %s\nIDADE: %d\nFUNCAO: %s\nTURNO: %s\n", cadf, f->nome, f->celular, f->idade, f->funcao, f->turno);
        cadf++;
    }
    printf("\n.....................................\n");
    }
    else{
        printf("\n!!!!!ERRO AO ABRIR ARQUIVO!!!!!\n");
    }
    free(f);
    fclose(pont_arq);
    return cadf;
}

void ECadastroF(){
    FILE *pont_arq = fopen("cadastrofuncionarios.dat", "rb+");
    CadFuncionario *novo = malloc(sizeof(CadFuncionario));
    int cad, cadf, escolha;

    if(pont_arq){
        cadf = ListaF();
        fread(novo, sizeof(CadFuncionario), 1, pont_arq);

        printf("\n\tCADASTRO QUE DESEJA ALTERAR: ");
        scanf("%d", &cad);
        getchar();
        cad --;

        if(cad>=0 && cad < cadf-1){
            system("cls"); //LIMPA A TELA;
            printf("\n.....................................\n");
            printf("\tCADASTRO DE FUNCIONARIO");
            printf("\n.....................................\n");

            printf(" NOME(SEM ESPACO): ");
            scanf("%s", novo->nome);

            printf(" CELULAR: ");
            scanf("%s", novo->celular);

            printf(" IDADE: ");
            scanf("%d", &novo->idade);

            printf("\n==============FUNCAO==============\n [1] LIMPEZA\n [2] TREINADOR\n [3] RECEPCAO\n [4] ADMINISTRACAO\n OPCAO: ");
            scanf("%d", &escolha);

            while(escolha > 4 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
                printf("TENTE NOVAMENTE!\n");
                scanf("%d", &escolha);
            }
            if (escolha == 1){
                strcpy(novo->funcao, "LIMPEZA");
            }
            else if (escolha == 2){
                strcpy(novo->funcao, "TREINADOR");
            }
            else if (escolha == 3){
                strcpy(novo->funcao, "RECEPCAO");
            }
            else{
                strcpy(novo->funcao, "ADMINISTRACAO");
            }
            printf("\n==============TURNO===============\n [1] MANHA\n [2] TARDE\n [3] NOITE\n OPCAO: ");
            scanf("%d", &escolha);
            while(escolha > 3 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
                printf("TENTE NOVAMENTE!\n");
                scanf("%d", &escolha);
            }
            if (escolha == 1){
                strcpy(novo->turno, "MANHA");
            }
            else if (escolha == 2){
                strcpy(novo->turno, "TARDE");
            }
            else{
                strcpy(novo->turno, "NOITE");
            }
            printf("\n!!!!!CADASTRO ALTERADO!!!!!\n");
            fseek(pont_arq, cad * sizeof(CadFuncionario), SEEK_SET);
            fwrite(novo, sizeof(CadFuncionario), 1, pont_arq);
        }
    }
    else{
        printf("!!!!!ERRO AO ABRIR ARQUIVO!!!!!");
    }
    free(novo);
    fclose(pont_arq);
}

int CadastroC(CadCliente **c, int quant, int tam){ //TELA DE CADASTROS PARA ADICIONAR CLIENTES
        int escolha;
        float plan;

        if(quant < tam){
            CadCliente *novo = malloc(sizeof(CadCliente));
            system("cls"); //LIMPA A TELA;
            printf("\n.....................................\n");
            printf("\tCADASTRO DE CLIENTE");
            printf("\n.....................................\n");

            printf(" NOME(SEM ESPACO): ");
            scanf("%s", novo->nome);

            printf(" CELULAR: ");
            scanf("%s", novo->celular);

            printf(" IDADE: ");
            scanf("%d", &novo->idade);

            printf("\n==============MOTIVO==============\n [1] FISIOTERAPIA\n [2] HIPERTROFIA\n [3] EMAGRECIMENTO\n OPCAO: ");
            scanf("%d", &escolha);

            while(escolha > 3 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
                printf("TENTE NOVAMENTE!\n");
                scanf("%d", &escolha);
            }
            if (escolha == 1){
                strcpy(novo->motivo, "FISIOTERAPIA");
            }
            else if (escolha == 2){
                strcpy(novo->motivo, "HIPERTROFIA");
            }
            else{
                strcpy(novo->motivo, "EMAGRECIMENTO");
            }
            printf("\n=======PLANOS DISPONIVEIS=========\n");
            printf(" [1] PLANO MENSAL     R$85,00\n");
            printf(" [2] PLANO SEMESTRAL  R$70,00 * 6\n");
            printf(" [3] PLANO ANUAL      R$59,00 * 12\n\n");
            printf(" PLANO: ");
            scanf("%d", &escolha);
            while(escolha > 3 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
                printf("TENTE NOVAMENTE!\n");
                scanf("%d", &escolha);
            }
            novo->plano = Pagamento(escolha);
            printf("\n\tCADASTRO REALIZADO!!\n\n");
            c[quant] = novo;

            system("pause");//PAUSA A TELA;
            system("cls"); //LIMPA A TELA;
            return 1;
        }
        else{
            printf("\nLIMITE DE CLIENTES ATINGIDO!\n");
            system("pause");//PAUSA A TELA;
            system("cls"); //LIMPA A TELA;
            fflush(stdin); //LIMPA O CACHE DE MEMORIA;
            return 0;
        }
}

void SalvarC(CadCliente **c, int quant){
    FILE *pont_arq = fopen("cadastroclientes.dat", "ab");
    int i;

    if(pont_arq){
        for(i = 0; i<quant; i++){
            fwrite(c[i], sizeof(CadCliente), 1, pont_arq);
        }
    }
    else{ //ESTRUTURA DE CONDICAO PARA CASO DE ERRO EM ABRIR O ARQUIVO;
        printf("\n!!!!!ERRO AO ABRIR ARQUIVO!!!!!\n");
    }
    fclose(pont_arq);
}

int LerC(CadCliente **c){
    int quant = 0;
    CadCliente *novo = malloc(sizeof(CadCliente));
    system("cls");
    FILE *pont_arq = fopen("cadastroclientes.dat", "rb"); //ABRE O ARQUIVO CADASTRO DE CLIENTES COMO FORMA DE LEITURA;

    if (pont_arq){
        while(fread(novo, sizeof(CadCliente), 1, pont_arq)){
            c[quant] = novo;
            quant++;
            novo = malloc(sizeof(CadCliente));
        }
    }
    else{  //ESTRUTURA DE CONDICAO PARA CASO DE ERRO EM ABRIR O ARQUIVO;
        printf("\n!!!!!ERRO AO ABRIR ARQUIVO!!!!!\n");
    }
    fclose(pont_arq);
}

int ListaC(){
    FILE *pont_arq = fopen("cadastroclientes.dat", "rb+");
    CadCliente *c = malloc(sizeof(CadCliente));
    int cadc=1;

    if(pont_arq){
        printf("\n.....................................\n");
        printf("\tLISTA DE CLIENTE");
        printf("\n.....................................\n");
        while(fread(c, sizeof(CadCliente), 1, pont_arq)){
            printf("\n\tCLIENTE %d\nNOME: %s\nCELULAR: %s\nIDADE: %d\nMOTIVO: %s\nPLANO: R$%.2f\n",cadc, c->nome, c->celular, c->idade, c->motivo, c->plano);
            cadc++;
        }
        printf("\n.....................................\n");
    }
    else{
        printf("\n!!!!!ERRO AO ABRIR ARQUIVO!!!!!\n");
    }
    free(c);
    return cadc;
}

void ECadastroC(){
    FILE *pont_arq = fopen("cadastroclientes.dat", "rb+");
    CadCliente *novo = malloc(sizeof(CadCliente));
    int cad, cadc, escolha;

    if(pont_arq){
        cadc = ListaC();
        fread(novo, sizeof(CadCliente), 1, pont_arq);

        printf("\n  CADASTRO QUE DESEJA ALTERAR: ");
        scanf("%d", &cad);
        getchar();
        cad --;

        if(cad>=0 && cad < cadc-1){
            system("cls"); //LIMPA A TELA;
            printf("\n.....................................\n");
            printf("\tCADASTRO DE CLIENTE");
            printf("\n.....................................\n");

            printf(" NOME(SEM ESPACO): ");
            scanf("%s", novo->nome);

            printf(" CELULAR: ");
            scanf("%s", novo->celular);

            printf(" IDADE: ");
            scanf("%d", &novo->idade);

            printf("\n==============MOTIVO==============\n [1] FISIOTERAPIA\n [2] HIPERTROFIA\n [3] EMAGRECIMENTO\n OPCAO: ");
            scanf("%d", &escolha);

            while(escolha > 3 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
                printf("TENTE NOVAMENTE!\n");
                scanf("%d", &escolha);
            }
            if (escolha == 1){
                strcpy(novo->motivo, "FISIOTERAPIA");
            }
            else if (escolha == 2){
                strcpy(novo->motivo, "HIPERTROFIA");
            }
            else{
                strcpy(novo->motivo, "EMAGRECIMENTO");
            }
            printf("\n=======PLANOS DISPONIVEIS=========\n");
            printf(" [1] PLANO MENSAL     R$85,00\n");
            printf(" [2] PLANO SEMESTRAL  R$70,00 * 6\n");
            printf(" [3] PLANO ANUAL      R$59,00 * 12\n\n");
            printf(" PLANO: ");
            scanf("%d", &escolha);
            while(escolha > 3 || escolha < 1){ //ESTRUTURA DE REPETICAO PARA ACEITAR SOMENTE AS OPCOES DISPONIVEIS;
                printf("TENTE NOVAMENTE!\n");
                scanf("%d", &escolha);
            }
            novo->plano = Pagamento(escolha);
            printf("\n!!!!!CADASTRO ALTERADO!!!!!\n");
            fseek(pont_arq, cad * sizeof(CadFuncionario), SEEK_SET);
            fwrite(novo, sizeof(CadFuncionario), 1, pont_arq);
        }
    }
    else{
        printf("!!!!!ERRO AO ABRIR ARQUIVO!!!!!");
    }
    free(novo);
    fclose(pont_arq);
}

int Recibo(recibo dados){
    printf("\n.....................................\n");
    printf("\n\tRECIBO\n");
    printf("\n.....................................\n");
    printf("\n\t PLANO  %d : ", dados.num);
    if(dados.num == 1){
        printf("R$%.2f", dados.plan);
        printf("\n\t PARCELAS:  %d", dados.p);
        printf("\n\t PAGAMENTO: R$%.2f\n", dados.pago);
        printf("\n\t  %.2f \n\t- %.2f\n\t-------\n\t  %.2f\n", dados.plan, dados.pago, dados.troco);
        printf("\n\t RETORNAR: R$%.2f", dados.troco);
        printf("\n.....................................\n");
        return 0;
    }
    if(dados.num == 2 || dados.num == 3){
        printf("R$%.2f", dados.plan);
        printf("\n\t PAGAMENTO: R$%.2f", dados.pago);
        if(dados.num == 2){
            printf("\n\t PARCELAS:  %d = R$%d,00", dados.p, (dados.p*70));
            printf("\n\t  %d \n\t- %.2f\n\t-------\n\t  %.2f\n", (dados.p*70), dados.pago, dados.troco);
        }
        else{
            printf("\n\t PARCELAS:  %d = R$%d,00", dados.p, (dados.p*59));
            printf("\n\t  %d \n\t- %.2f\n\t-------\n\t  %.2f\n", (dados.p*59), dados.pago, dados.troco);
        }
        printf("\n\n\t RETORNAR: R$%.2f", dados.troco);
        printf("\n.....................................\n");
        return 0;
    }
}

int Pagamento(int plano){
    int parcela;
    float pag, retorno;
    char resp;
    recibo dados;

    printf("\n.....................................\n");
    printf("\n\tREALIZE O PAGAMENTO(DINHEIRO)\n");
    printf("\n.....................................\n");
    if(plano == 1){
        dados.num = plano;
        plano = 85;
        dados.plan = 85.00;
        dados.p = 0;
        do{
            printf("\nQUANTIA(85.00): R$");
            scanf("%f", &pag);
            dados.pago = pag;
            if(pag < plano){
                printf("\n!!!!!QUANTIA INSUFICIENTE!!!!!\n");
            }
        }while(pag < plano);
        if (pag > plano ){
            retorno = pag - plano;
            dados.troco = retorno;
            printf("\n  RETORNO DE R$%.2f\n", retorno);
        }
        plano = 0;
    }
    else if(plano == 2){
        dados.num = plano;
        plano = (70*6);
        dados.plan = (70*6);
        do{
            printf("\n\tQUANTAS PARCELAS DESEJA PAGAR? \nPARCELAS: ");
            scanf("%d", &parcela);
            dados.p = parcela;
        }while(parcela < 1 || parcela > 6);
        do{
            printf("\nQUANTIA(%d,00): R$", parcela*70);
            scanf("%f", &pag);
            dados.pago = pag;
            if(pag < parcela*70){
                printf("\n!!!!!QUANTIA INSUFICIENTE!!!!!\n");
            }
        }while(pag < parcela*70);
        if (pag > parcela*70 ){
            retorno = pag - parcela*70;
            dados.troco = retorno;
            printf("\n  RETORNO DE R$%.2f\n", retorno);
        }
        plano -= pag;
    }
    else if(plano == 3){
        dados.num = plano;
        plano = (59 * 12);
        dados.plan = (59 * 12);
        do{
            printf("\n\tQUANTAS PARCELAS DESEJA PAGAR? \nPARCELAS: ");
            scanf("%d", &parcela);
            dados.p = parcela;
        }while(parcela < 1 || parcela > 12);
        do{
            if(pag < parcela*59){
                printf("\n!!!!!QUANTIA INSUFICIENTE!!!!!\n");
            }
            printf("QUANTIA(%d,00): R$", parcela*59);
            scanf("%f", &pag);
            dados.pago = pag;
        }while(pag < parcela*59);
        if (pag > parcela*59 ){
            retorno = pag - parcela*59;
            dados.troco = retorno;
            printf("TROCO: R$%.2f\n", retorno);
        }
        plano -= pag;
    }
    printf("\n.....................................\n");
    printf("\tPAGAMENTO REALIZADO!\n");
    printf("\n.....................................\n");
    system("cls");
    while (resp != 'S' && resp != 'N'){
        fflush(stdin);
        printf("\nIMPRIMIR RECIBO? [S/N]: ");
        scanf("%c", &resp);
    }
    if (resp == 'S'){
        Recibo(dados);
        return plano;
    }
    if (resp == 'N'){
        return plano;
    }
    return plano;
}

int main()
{
    int opcao, user, tam = 10, quantf = 0, quantc = 0;
    char resp;
    CadFuncionario *funcionarios[10];
    CadCliente *clientes[10];

    setlocale(LC_ALL, "PORTUGUESE");
    user = TelaLogin();
    do{
        system("cls"); //LIMPA A TELA;
        opcao = MenuInicial(user);
        switch(opcao){
            case 01:{
                quantf += CadastroF(funcionarios, quantf, tam);
                SalvarF(funcionarios, quantf);
                LerF(funcionarios);
                break;
            }
            case 02:{
                quantc += CadastroC(clientes, quantc, tam);
                SalvarC(clientes, quantc);
                LerC(clientes);
                break;
            }
            case 03:{
                ECadastroF();
                break;
            }
            case 04:{
                ECadastroC();
                break;
            }
            case 05:{
                ListaF();
                break;
            }
            case 06:{
                ListaC();
                break;
            }
            case 00:{
                printf("\n**\tOBRIGADO POR UTILIZAR O PROGRAMA!\t**\n**\tATE A PROXIMA\t\t\t\t**\n");
            }
        }
        if (opcao != 0){
            printf("\n DESEJA VER OUTRA OPCAO NO MENU? [S/N]: ");
            fflush(stdin);
            scanf("%c", &resp);
            if (resp == 'N'){
                system("cls");
                printf("\n**\tOBRIGADO POR UTILIZAR O PROGRAMA!\t**\n**\tATE A PROXIMA\t\t\t\t**\n");
                resp = 'N';
            }
        }
    }while(resp == 'S' && opcao != 0);
    return 0;
}
