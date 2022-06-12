#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_CHAR 300

void caixaAlta(char *nomeAluno)
{
    int tamStr = strlen(nomeAluno), i;
    for(i = 0; i <= tamStr; i++)
        nomeAluno[i] = toupper(nomeAluno[i]);
  
}

void geraArquivo(char *matricula, char *nomeAluno, char *id, char *lab, char *data, char *descricao, char *problema) {
    FILE * fp;
    fp = fopen("./file.txt", "w");
    int i;

    if(!fp) {
        printf("Erro. N�o foi possivel gerar o arquivo!\n");
        printf("Pressione enter para voltar ao menu...");
        getchar();
        return;
    }

    // Cabeçalho do arquivo
    fprintf(fp, "\n");
    fprintf(fp, "::####  INSTITUTO FEDERAL\n");
    fprintf(fp, "::###   DE EDUCA��O, CI�NCIA E TECNOLOGIA DE\n");
    fprintf(fp, "::##    S�O PAULO\n");
    
    // Separador 
    for(i = 0; i < 80; i++) 
        fprintf(fp, "_");
    fprintf(fp, "\n\n");

    // Corpo do documento
    fprintf(fp, "Problema relacionado: %s\n\n", problema);
    fprintf(fp, "Nome do aluno: %s\n", nomeAluno);
    fprintf(fp, "Matricula: %s\n\n", matricula);
    fprintf(fp, "ID do computador: %s\n", id);
    fprintf(fp, "Laborat�rio: %s\n", lab);
    fprintf(fp, "Data: %s\n", data);
    fprintf(fp, "Descri��o: %s\n", descricao);

    fclose(fp);
}

void imprimeLabs()
{
    int i;
    char labs[5][10] = {"Lab 1", "Lab 2", "Lab 3", "Lab 4", "Lab 5"};
    printf("   Local da ocorr�ncia:\n");
    for(i = 0; i < 5; i++)
        printf("        [%d] %s\n", i+1, labs[i]);

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
            printf("  |              Caso sua impressora n�o esteja             |\n"); 
            printf("  |              funcionando voc� poder� salvar             |\n"); 
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
            printf("  |       Voc� ser� redirecionado para tela de login de     |\n"); 
            printf("  |       seu email. Ao logar, anexe o arquivo gerado e     |\n"); 
            printf("  |       o envie para o seguinte endere�o:                 |\n"); 
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

int telaDeEnvio ()
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
        printf("  |                 Escolha a op��o de envio:              |\n");
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
        
        printf("\t\t  Opcao: ");	
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

void entradaDeDados (char *problema) {

    char entradaUsuario[MAX_CHAR], *nomeAluno, *matricula, *id, *lab, *data, *descricao;
    int entradaUsuarioTam;

    system("cls");
    printf("  +--------------------------------------------------+\n");
    printf("  |                 Abertura de Chamado              |\n");
    printf("  +--------------------------------------------------+\n");
    printf("   Problema: %s\n\n", problema);
    
    printf("  +- Dados do requisitor ----------------------------+\n");
    printf("   Nome do aluno: ");
    _flushall();
    gets(entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    nomeAluno = (char *) malloc(entradaUsuarioTam * sizeof(char));
    strcpy(nomeAluno, entradaUsuario);
    caixaAlta(nomeAluno);

    //Todo: checar se matricula esta dentro do padr�o
    printf("   Matricula: ");
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    matricula = (char *) malloc(entradaUsuarioTam * sizeof(char));
    strcpy(matricula, entradaUsuario);
    caixaAlta(matricula);
    printf("\n");

    printf("  +- Dados do problema ------------------------------+\n");
    printf("   ID do computador: ");
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    id = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(id, entradaUsuario);
    caixaAlta(id);

    imprimeLabs();
    printf("   Op��o: ");
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    lab = (char *) malloc(entradaUsuarioTam * sizeof(char));
    strcpy(lab, entradaUsuario);

    //Todo: pegar do sistema?
    printf("   Data: ");    
    _flushall();
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    data = (char *) malloc(entradaUsuarioTam * sizeof(char));
    strcpy(data, entradaUsuario);

    printf("   Descri��o (M�x. 300 caracteres): ");
    _flushall();
    fgets(entradaUsuario, MAX_CHAR, stdin);
    entradaUsuarioTam = strlen(entradaUsuario);
    entradaUsuario[entradaUsuarioTam - 1] = '\0';
    descricao = (char *) malloc(entradaUsuarioTam * sizeof(char));
    strcpy(descricao, entradaUsuario);
    descricao[0] = toupper(descricao[0]);

    _flushall();
    geraArquivo(matricula, nomeAluno, id, lab, data, descricao, problema);
    telaDeEnvio(); 
    return;
}

void main()
{   
    setlocale(LC_ALL, "Portuguese");
    int loopInfinito = 1;
    char escolha;

    do {
        system("cls");
        printf("                     .  ..___\\  /.  . __.                    \n");        
        printf("                     |\\ |[__  >< |  |(__                     \n");          
        printf("                     | \\|[___/  \\|__|.__)                   \n");        
        printf("                Conectando problemas a solu��es               \n");  
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
        printf("  |  /   ========= ===  / /   /___/                         |\n"); 
        printf("  | <__________________<_/                                  |\n"); 
        printf("  |                                                         |\n"); 
        printf("  +---------------------------------------------------------+\n");

        printf("\n\t\t\t Opcao: ");
        scanf(" %c", &escolha);
        
        if(escolha < '1' || escolha > '5')
            continue;

        switch (escolha)
        {
        case '1':
            entradaDeDados("Computador");
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
}
//Todos: 
//!IMPORTANTE!
// 0 - Definir o local padrao para salvar o arquivo(area de trabalho) 
// O usuario dever� ser informado do local para poder enviar por email

// 1 - Padronizar a interface de usu�rio(quantidade de linhas, margens, etc..) 
// 2 - Criar fun��es para os campos de entrada de dados
// 3 - Utilizar a data do sistema 
// 4 - Filtragem das entradas de dados
// 5 - Melhorar os nomes das vari�veis
// 7 - Checar por poss�veis erros de ortografia

