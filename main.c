#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

#define MAX_CHAR 300
#define TAM_MATRICULA 9

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

void geraArquivo(char *matricula, char *nomeAluno, char *id, char *lab, char *descricao, char *problema) 
{
    FILE * fp;
    fp = fopen("./file.txt", "w");
    int i;

    if(!fp) {
        printf("Erro. N„o foi possivel gerar o arquivo!\n");
        printf("Pressione enter para voltar ao menu...");
        getchar();
        return;
    }

    // CabeÁalho do arquivo
    fprintf(fp, "\n");
    fprintf(fp, "::####  INSTITUTO FEDERAL\n");
    fprintf(fp, "::###   DE EDUCA«√O, CI NCIA E TECNOLOGIA DE\n");
    fprintf(fp, "::##    S√O PAULO\n");
    
    // Separador 
    for(i = 0; i < 80; i++) 
        fprintf(fp, "_");
    fprintf(fp, "\n\n");

    // Corpo do documento
    fprintf(fp, "Problema relacionado: %s\n\n", problema);
    fprintf(fp, "Nome do aluno: %s\n", nomeAluno);
    fprintf(fp, "Matricula: %s\n\n", matricula);
    fprintf(fp, "ID do computador: %s\n", id);
    fprintf(fp, "LaboratÛrio: %s\n", lab);
    fprintf(fp, "Data: %s\n",  dataSistema());
    fprintf(fp, "DescriÁ„o: %s\n", descricao);

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
            printf("  |              Caso sua impressora n„o esteja             |\n"); 
            printf("  |              funcionando vocÍ poder· salvar             |\n"); 
            printf("  |              o arquivo consigo como backup.             |\n"); 
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
            printf("  |       VocÍ ser· redirecionado para tela de login de     |\n"); 
            printf("  |       seu email. Ao logar, anexe o arquivo gerado e     |\n"); 
            printf("  |       o envie para o seguinte endereÁo:                 |\n"); 
            printf("  |                                                         |\n"); 
            printf("  |                   central_ti@ifsp.edu.br                |\n"); 
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

void telaDeEnvio ()
{

    FILE *fp;
	fp = fopen("file.txt", "r");
	char opcao;
		
	fclose(fp);

    do {
        system("cls");
        printf("  +---------------------------------------------------------+\n");
        printf("  |                                                        |\n"); 
        printf("  |                                                        |\n"); 
        printf("  |                 Escolha a opÁ„o de envio:              |\n");
        printf("  |                                                        |\n"); 
        printf("  |                   _____                                |\n");
        printf("  |                 _|_____|_     +-------+                |\n");
        printf("  |                 | _____-|     |  \\_/  |                |\n");
        printf("  |                 |_|   |_|     +-------+                |\n");
        printf("  |                   |___|                                |\n");
        printf("  |                                                        |\n"); 
        printf("  |                [1] Impresso	 [2] Email                 |\n");
        printf("  |                                                        |\n"); 
        printf("  |                                                        |\n"); 
        printf("  |                                                        |\n"); 
        printf("  +---------------------------------------------------------+\n");
        
        printf("\t\t  OpÁ„o: ");	
        scanf(" %c", &opcao);

        switch(opcao) {
            case '1':
                system("start notepad /p file.txt");
                telaDeInstrucao(1);
                break;
            case '2':
                system("start explorer https://login.live.com/");
                telaDeInstrucao(2);
                break;
        }
        
    } while (opcao < '1' || opcao > '2');
}

char * matriculaAluno()
{   
    char *ptMatricula, matricula[TAM_MATRICULA + 1];
    do {
        printf("   Matricula: ");
        scanf("%s",matricula);

        if(strlen(matricula) != TAM_MATRICULA )
        	printf("   *** Matricula inv·lida! ***\n");

    } while (strlen(matricula) != TAM_MATRICULA );
   
    caixaAlta(matricula);
    ptMatricula = (char *)malloc(strlen(matricula) * sizeof(char));
    strcpy(ptMatricula, matricula);

    return ptMatricula;

}

char * localOcorrencia()
{
    int opcao, i;
    char labs[5][10] = {"Lab 1", "Lab 2", "Lab 3", "Lab 4", "Lab 5"}, *lab;

    do {
        printf("   Local da ocorrÍncia:\n");
        for(i = 0; i < 5; i++)
            printf("        [%d] %s\n", i+1, labs[i]);
        
        printf("   Opcao: ");
        _flushall();
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 5);

    lab = (char *) malloc(5);
    strcpy(lab, labs[opcao - 1]);

    return lab;

}

char * descricaoProblema(char * entradaUsuario)
{
    char *descricao;
    int entradaUsuarioTam;

    printf("   DescriÁ„o (M·x. 300 caracteres): ");
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

    char entradaUsuario[MAX_CHAR], *nomeAluno, *matricula, *id, *lab, *descricao; //*data,
    int entradaUsuarioTam;

    system("cls");
    printf("  +--------------------------------------------------+\n");
    printf("  |                 Abertura de Chamado              |\n");
    printf("  +--------------------------------------------------+\n");
    printf("   Problema: %s\n\n", problema);
    
    printf("  +- Dados do requisitor ----------------------------+\n");

    //Filtro do Nome do Aluno (N„o pode ter n˙mero)
    printf("   Nome do aluno: ");
    _flushall();
    gets(entradaUsuario);

    // Filtro 
    entradaUsuarioTam = strlen(entradaUsuario);
    nomeAluno = (char *) malloc(entradaUsuarioTam * sizeof(char));
    strcpy(nomeAluno, entradaUsuario);
    caixaAlta(nomeAluno);

    //Entrada da matricula do aluno
    matricula = matriculaAluno();
    printf("\n");

    printf("  +- Dados do problema ------------------------------+\n");
    printf("   ID do computador: ");
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    id = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(id, entradaUsuario);
    caixaAlta(id);

    // Escolha do local de ocorrencia do problema
    lab = localOcorrencia();
    
    //Entrada da matricula do aluno
    descricao = descricaoProblema(entradaUsuario);

    _flushall();
    geraArquivo(matricula, nomeAluno, id, lab, descricao, problema);
    telaDeEnvio(); 
    return;
}

int main()
{   
    setlocale(LC_ALL, "Portuguese");
    int loopInfinito = 1;
    char escolha;

    do {
        system("cls");
        printf("                     .  ..___\\  /.  . __.                    \n");        
        printf("                     |\\ |[__  >< |  |(__                     \n");          
        printf("                     | \\|[___/  \\|__|.__)                   \n");        
        printf("                Conectando problemas a soluÁıes               \n");  
        printf("  +---------------------------------------------------------+\n");
        printf("  |        ________________                                 |\n"); 
        printf("  |       /               /|                                |\n"); 
        printf("  |      /_______________/ |      ========= Menu =========  |\n");
        printf("  |      |  __________  |  |      [1] Computador / OS       |\n"); 
        printf("  |      | |          | |  |      [2] Rede / Internet       |\n"); 
        printf("  |      | |   Help!  | |  |      [3] Teclado / Mouse       |\n"); 
        printf("  |      | |    :(    | |  |      [4] Outro                 |\n"); 
        printf("  |      | |__________| | /       [5] Sair                  |\n");  
        printf("  |      |______________|/ ___/\\                            |\n");     
        printf("  |     |____>______<_____/     \\                           |\n");             
        printf("  |    / = ==== ==== ==== /|    _|_                         |\n"); 
        printf("  |   / ========= === == / /   ////                         |\n"); 
        printf("  |  /   ========= ===  / /   /   /                         |\n"); 
        printf("  | <__________________<_/    ØØØØ                          |\n"); 
        printf("  |                                                         |\n"); 
        printf("  +---------------------------------------------------------+\n");

        printf("\n\t\t\t OpÁ„o: ");
        scanf(" %c", &escolha);
        
        if(escolha < '1' || escolha > '5')
            continue;

        switch (escolha)
        {
        case '1':
            entradaDeDados("Computador / OS");
            break;
        case '2':
            entradaDeDados("Rede / Internet");
            break;
        case '3':
            entradaDeDados("Teclado / Mouse");
            break;
        case '4':
            entradaDeDados("Outro Problema");
            break;
        case '5':
            loopInfinito = 0;
            break;
        }
    } while (loopInfinito);

    return 0;
}
//Todos: 
//!IMPORTANTE!
// 0 - Definir o local padrao para salvar o arquivo(area de trabalho) 
// O usuario dever√£o ser informado do local para poder enviar por email

// 1 - Padronizar a interface de usu√°rio(quantidade de linhas, margens, etc..) 
// 2 - Criar fun√ß√µes para os campos de entrada de dados
// 3 - Utilizar a data do sistema 
// 4 - Filtragem das entradas de dados
// 5 - Melhorar os nomes das vari·iveis
// 7 - Checar por poss√≠veis erros de ortografia

