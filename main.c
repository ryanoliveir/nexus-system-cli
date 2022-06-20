#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

#define MAX_CHAR 100
#define TAM_MATRICULA 9
#define NOMEALUNO_MAX 30
#define ID_TAM 13

// Protótipos das funções
char * dataSistema();
void caixaAlta();
void geraArquivo();
void telaDeInstrucao();
void telaDeEnvio();
char * matriculaAluno();
char * nomeDoAluno();
char * idComputador();
void entradaDeDados ();

int main()
{   
    setlocale(LC_ALL, "Portuguese");
    int loopInfinito = 1;
    int escolha;

    do {
        system("cls");
        printf("                     .  ..___\\  /.  . __.                    \n");        
        printf("                     |\\ |[__  >< |  |(__                     \n");          
        printf("                     | \\|[___/  \\|__|.__)                   \n");        
        printf("                Conectando problemas a soluções               \n");  
        printf("  +---------------------------------------------------------+\n");
        printf("  |        ________________                                 |\n"); 
        printf("  |       /               /|                                |\n"); 
        printf("  |      /_______________/ |                                |\n");
        printf("  |      |  __________  |  |      +======== Menu ========+  |\n"); 
        printf("  |      | |          | |  |      | [1] Computador / OS  |  |\n"); 
        printf("  |      | |   Help!  | |  |      | [2] Rede / Internet  |  |\n"); 
        printf("  |      | |    :(    | |  |      | [3] Teclado / Mouse  |  |\n"); 
        printf("  |      | |__________| | /       | [4] Outro            |  |\n");  
        printf("  |      |______________|/ ___/\\  | [5] Sair             |  |\n");     
        printf("  |     |____>______<_____/     \\ +----------------------+  |\n");             
        printf("  |    / = ==== ==== ==== /|    _|_                         |\n"); 
        printf("  |   / ========= === == / /   ////                         |\n"); 
        printf("  |  /   ========= ===  / /   /   /                         |\n"); 
        printf("  | <__________________<_/    '--'                          |\n"); 
        printf("  |                                                         |\n"); 
        printf("  +---------------------------------------------------------+\n");

        printf("\n\t\t\t   Opção: ");
        _flushall();
        scanf(" %d", &escolha);
        
        if(escolha < 1 || escolha > 5)
            continue;

        switch (escolha)
        {
        case 1:
            entradaDeDados("Computador / OS");
            break;
        case 2:
            entradaDeDados("Rede / Internet");
            break;
        case 3:
            entradaDeDados("Teclado / Mouse");
            break;
        case 4:
            entradaDeDados("Outro Problema");
            break;
        case 5:
            loopInfinito = 0;
            break;
        }
    } while (loopInfinito);

    return 0;
}

char * dataSistema()
{
    struct tm *p;
    time_t seconds;

    time(&seconds);
    p = localtime(&seconds);

    int dia = p -> tm_mday;
    int mes = p -> tm_mon + 1;
    int ano = p -> tm_year + 1900;

    char * data = malloc(11 * sizeof(char));
    snprintf(data, 11, "%02d/%02d/%d", dia, mes, ano);

    return data;
}

void caixaAlta(char *string)
{
    int tamStr = strlen(string), i;
    for(i = 0; i <= tamStr; i++)
        string[i] = toupper(string[i]);
}

void geraArquivo(char *matricula, char *nome_Aluno, char *id, char *lab, char *descricao, char *problema) 
{
    FILE * fp;
    fp = fopen("./ticket.txt", "w");
    int i;

    if(!fp) {
        printf("Erro. Não foi possivel gerar o arquivo!\n");
        printf("Pressione enter para voltar ao menu...");
        getchar();
        return;
    }

    // Cabeçalho do arquivo
    fprintf(fp, "\n");
    fprintf(fp, "::####  INSTITUTO FEDERAL\n");
    fprintf(fp, "::###   DE EDUCAÇÃO, CIÊNCIA E TECNOLOGIA DE\n");
    fprintf(fp, "::##    SÃO PAULO\n");
    
    // Separador 
    for(i = 0; i < 80; i++) 
        fprintf(fp, "_");
    fprintf(fp, "\n\n");

    // Corpo do documento
    fprintf(fp, "Problema relacionado: %s\n\n", problema);
    fprintf(fp, "Nome do aluno: %s\n", nome_Aluno);
    fprintf(fp, "Matricula: %s\n\n", matricula);
    fprintf(fp, "ID do computador: %s\n", id);
    fprintf(fp, "Laboratório: %s\n", lab);
    fprintf(fp, "Data: %s\n",  dataSistema());
    fprintf(fp, "Descrição: %s\n", descricao);

    fclose(fp);
}

void telaDeInstrucao(int opcao) 
{
    char tecla;
    switch (opcao)
    {
    case 1:
        do {
            system("cls");
            printf("  +---------------------------------------------------------+\n");
            printf("  |                                                         |\n"); 
            printf("  |                Arquivo gerado com sucesso!              |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |                              //                         |\n"); 
            printf("  |                         \\\\  //                          |\n"); 
            printf("  |                          \\\\//                           |\n"); 
            printf("  |                           \\/                            |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |        Caso sua impressora não esteja funcionando,      |\n"); 
            printf("  |        você poderá salvar o arquivo consigo em um       |\n"); 
            printf("  |        dispositivo removível como backup.               |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |         Pressione enter para retornar ao menu...        |\n"); 
            printf("  |                                                         |\n"); 
            printf("  +---------------------------------------------------------+\n");
            _flushall();
            scanf("%c", &tecla);
        } while (tecla != '\n');
        break;
    
    case 2:
        do {
            system("cls");
            printf("  +---------------------------------------------------------+\n");
            printf("  |                                                         |\n"); 
            printf("  |                Arquivo gerado com sucesso!              |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |                              //                         |\n"); 
            printf("  |                         \\\\  //                          |\n"); 
            printf("  |                          \\\\//                           |\n"); 
            printf("  |                           \\/                            |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |       Você será redirecionado para tela de login de     |\n"); 
            printf("  |       seu email. Ao logar, anexe o arquivo gerado e     |\n"); 
            printf("  |       o envie para o seguinte endereço:                 |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |                    cti.jr@ifsp.edu.br                   |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |         Pressione enter para retornar ao menu...        |\n"); 
            printf("  |                                                         |\n"); 
            printf("  +---------------------------------------------------------+\n");
            _flushall();
            scanf("%c", &tecla);
        } while (tecla != '\n');
        break;
    }
}

void escolhaProvedor() {
	int opcao;
    
    do {
        system("cls");
        printf("  +---------------------------------------------------------+\n");
        printf("  |                                                         |\n"); 
        printf("  |                                                         |\n"); 
        printf("  |               Escolha o provedor de email:              |\n");
        printf("  |                                                         |\n"); 
        printf("  |                        __     __              __        |\n");
        printf("  |        /||||\\          |\\\\   //|           __/  \\_      |\n");
        printf("  |        ||  ||          ||\\\\_//||         _/  \\_   \\     |\n");
        printf("  |        ||  ||          || \\_/ ||        /      \\__/     |\n");
        printf("  |        \\||||/          ||     ||        \\______/        |\n");
        printf("  |                                                         |\n"); 
        printf("  |     [1] Outlook        [2] Gmail        [3] ICloud      |\n");
        printf("  |                                                         |\n"); 
        printf("  |                                                         |\n"); 
        printf("  |                                                         |\n"); 
        printf("  +---------------------------------------------------------+\n");
        printf("                           Opção: ");	
        
        _flushall();
        scanf(" %d", &opcao);

        switch(opcao) {
            case 1:
                system("start explorer https://login.live.com/");
                
                break;
            case 2:
                system("start explorer https://gmail.com/");
                
                break;
            case 3:
                system("start explorer https://www.icloud.com/");
                
                break;
        }
    } while (opcao < 1 || opcao > 3);
}

void telaDeEnvio()
{
	char opcao;

    do {
        system("cls");
        printf("  +---------------------------------------------------------+\n");
        printf("  |                                                         |\n"); 
        printf("  |                                                         |\n"); 
        printf("  |                Escolha a opção de envio:                |\n");
        printf("  |                                                         |\n"); 
        printf("  |                _____                                    |\n");
        printf("  |              _|_____|_          +-------+               |\n");
        printf("  |              | _____-|          |  \\_/  |               |\n");
        printf("  |              |_|   |_|          +-------+               |\n");
        printf("  |                |___|                                    |\n");
        printf("  |                                                         |\n"); 
        printf("  |            [1] Impresso         [2] Email               |\n");
        printf("  |                                                         |\n"); 
        printf("  |                                                         |\n"); 
        printf("  |                                                         |\n"); 
        printf("  +---------------------------------------------------------+\n");
        printf("                           Opção: ");	
        
        scanf(" %c", &opcao);

        switch(opcao) {
            case '1':
                system("start notepad /p ticket.txt");
                telaDeInstrucao(1);
                break;
            case '2':
                //system("start explorer https://login.live.com/");
                escolhaProvedor();
                telaDeInstrucao(2);
                break;
        }
        
    } while (opcao < '1' || opcao > '2');
}

char * nomeDoAluno()
{
    char *pnomeAluno, nome_Aluno[NOMEALUNO_MAX];
    int loop = 1, test = 0, i;

    do
    {
        printf("   Nome do aluno: ");
        _flushall();
        gets(nome_Aluno);
        
        for (i = 0; nome_Aluno[i] != '\0'; i++){

            if(isdigit(nome_Aluno[i]) || ispunct(nome_Aluno[i])){
                printf("   *** Valores invalidos! ***\n");
                test++;
                break;
            }
        }

        if(!(test != 0))
            loop = 0;
        test--;
    } while (loop);

    caixaAlta(nome_Aluno);
    pnomeAluno = (char *)malloc(strlen(nome_Aluno) * sizeof(char));
    strcpy(pnomeAluno, nome_Aluno);

    return pnomeAluno;
}

char * matriculaAluno()
{   
    char *ptMatricula, matricula[TAM_MATRICULA + 1];
    do {
        printf("   Matricula: ");
        scanf("%s",matricula);

        if(strlen(matricula) != TAM_MATRICULA )
        	printf("   *** Matricula inválida! ***\n");

    } while (strlen(matricula) != TAM_MATRICULA);
   
    caixaAlta(matricula);
    ptMatricula = (char *)malloc(strlen(matricula) * sizeof(char));
    strcpy(ptMatricula, matricula);

    return ptMatricula;
}

char * idComputador()
{   
    char id[ID_TAM+1], *ptrID;

    do {

        printf("   ID do computador: ");
        scanf("%s", id);
        
        if(strlen(id) != ID_TAM) {
            printf("   *** ID inválido! ***\n");
        }

    } while(strlen(id) != ID_TAM); 

    ptrID = malloc( ID_TAM * sizeof(char));
    caixaAlta(id);
    strcpy(ptrID, id);

    return ptrID;
}
 
char * localOcorrencia()
{
    int opcao, i;
    char labs[5][10] = {"Lab 1", "Lab 2", "Lab 3", "Lab 4", "Lab 5"}, *lab;

    do {
        printf("   Local da ocorrência:\n");
        for(i = 0; i < 5; i++)
            printf("        [%d] %s\n", i+1, labs[i]);
        
        printf("   Opcao: ");
        _flushall();
        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 5)
            printf("   *** Laboratório inexistente! ***\n");

    } while (opcao < 1 || opcao > 5);

    lab = (char *) malloc(5);
    strcpy(lab, labs[opcao - 1]);

    return lab;
}

char * descricaoProblema(char * entradaUsuario)
{
    char *descricao;

    printf("   Descrição (Máx. 100 caracteres): ");
    _flushall();
    fgets(entradaUsuario, MAX_CHAR, stdin);

    descricao = (char *) malloc(strlen(entradaUsuario) * sizeof(char));
    entradaUsuario[strlen(entradaUsuario) - 1] = '\0';
    descricao[0] = toupper(descricao[0]);
    strcpy(descricao, entradaUsuario);
    
    return descricao;
}

void entradaDeDados (char *problema) 
{
    char entradaUsuario[MAX_CHAR], *nomeAluno, *matricula, *id, *lab, *descricao; 

    system("cls");
    printf("  +--------------------------------------------------+\n");
    printf("  |                 Abertura de Chamado              |\n");
    printf("  +--------------------------------------------------+\n");
    printf("   Problema: %s\n\n", problema);
    
    printf("  +- Dados do solicitante ---------------------------+\n");

    //Entrada do nome do aluno
    nomeAluno = nomeDoAluno();

    //Entrada da matricula do aluno
    matricula = matriculaAluno();
    
	printf("\n");
    printf("  +- Dados do problema ------------------------------+\n");
    
    // Escolha do local de ocorrencia do problema
    lab = localOcorrencia();
    
    //Entrada da identificação do computador
    id = idComputador();    
    
    //Entrada da matricula do aluno
    descricao = descricaoProblema(entradaUsuario);

    //_flushall();
    geraArquivo(matricula, nomeAluno, id, lab, descricao, problema);
    telaDeEnvio(); 
    return;
}

/* ##### Explicação da função escolhaProvedor() (linha 204) #### */

// - A função será chamada quando o usuário escolher a opção de envio por email.
// - Irá mostrar as opções disponíveis de provedores para a escolha do usuário.
// - Com a opção escolhida, o programa irá executar a função system() que da acesso
//   ao terminal do sistema.
// - Contendo apenas um argumento, o comando system("start explorer <url>") irá
//   executar o navegador IE/Edge com a url da pagina inicial do provedor escolhido. 