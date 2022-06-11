#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 300

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void geraArquivo(char *matricula, char *nomeAluno, char *id, char *lab, char *data, char *descricao, char *problema) {
    FILE * fp;
    fp = fopen("file.txt", "w");
    int i;

    if(!fp) {
        printf("Erro. Não foi possivel gerar o arquivo!");
        return;
    }

    // Cabeçalho do arquivo
    fprintf(fp, "\n");
    fprintf(fp, "::####  INSTITUTO FEDERAL\n");
    fprintf(fp, "::###   DE EDUCAÇÃO CIÊNCIA E TECNOLOGIA\n");
    fprintf(fp, "::##    São Paulo\n");
    
    // Separador 
    for(i = 0; i < 80; i++) 
        fprintf(fp, "_");
    fprintf(fp, "\n\n");

    // Corpo do documento
    fprintf(fp, "Problema relacionado: %s\n\n", problema);
    fprintf(fp, "Nome do Aluno: %s\n", nomeAluno);
    fprintf(fp, "Matricula: %s\n\n", matricula);
    fprintf(fp, "ID do computador: %s\n", id);
    fprintf(fp, "Laboratório: %s\n", lab);
    fprintf(fp, "Data: %s\n", data);
    fprintf(fp, "Descrição: %s\n", descricao);

    fclose(fp);
}

void imprimeLabs() {
    int i;
    char labs[5][10] = {
        "[1] Lab 1",
        "[2] Lab 2",
        "[3] Lab 3",
        "[4] Lab 4",
        "[5] Lab 5"
    };

    for(i = 0; i < 5; i++)
        printf("%s\n", labs[i]);

}

void entradaDeDados (char *problema) {

    char entradaUsuario[MAX_CHAR], *nomeAluno, *matricula, *id, *lab, *data, *descricao;
    int entradaUsuarioTam;

    system("cls||clear");
    printf("+--------------------------------------------------+\n");
    printf("|                  Abertura de Chamado             |\n");
    printf("+--------------------------------------------------+\n");
    printf("Problema: %s\n\n", problema);

    printf("Nome do aluno: ");
    //Todo: Iniciais do nome devem estar e caixa alta
    //Todo: trocar por _flushall()
    clean_stdin();
    gets(entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    nomeAluno = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(nomeAluno, entradaUsuario);

    //Todo: checar se matricula esta dentro do padrão
    printf("Matricula do aluno: ");
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    matricula = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(matricula, entradaUsuario);
    printf("\n");

    printf("ID do computador: ");
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    id = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(id, entradaUsuario);

    printf("Laboratório: ");
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    lab = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(lab, entradaUsuario);

    //Todo: pegar do sistema?
    printf("Data: ");    
    //Todo: trocar por _flushall()
    clean_stdin();
    scanf("%s", entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    data = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(data, entradaUsuario);

    //Todo: Fazer o controle de limite de caracteres permitido
    printf("Descrição: ");
    //Todo: trocar por _flushall()
    clean_stdin();
    gets(entradaUsuario);
    entradaUsuarioTam = strlen(entradaUsuario);
    descricao = malloc(entradaUsuarioTam * sizeof(char));
    strcpy(descricao, entradaUsuario);

    geraArquivo(matricula, nomeAluno, id, lab, data, descricao, problema);
    telaDeEnvio(); 
    return;
}

int telaDeEnvio () {

    FILE *fp;
	fp = fopen("file.txt", "r");
	char opcao;
		
	fclose(fp);

    do {
        system("clear || cls");
        printf("+---------------------------------------------------------+\n");
        printf("|                                                         |\n"); 
        printf("|                                                         |\n"); 
        printf("|                  Escolha a opção de envio:              |\n");
        printf("|                                                         |\n"); 
        printf("|                    _____                                |\n");
        printf("|                  _|_____|_     +-------+                |\n");
        printf("|                  | _____-|     |  \\_/  |                |\n");
        printf("|                  |_|   |_|     +-------+                |\n");
        printf("|                    |___|                                |\n");
        printf("|                                                         |\n"); 
        printf("|                [1] Impresso	 [2] Email                |\n");
        printf("|                                                         |\n"); 
        printf("|                                                         |\n"); 
        printf("|                                                         |\n"); 
        printf("+---------------------------------------------------------+\n");
        
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

void telaDeInstrucao(int opcao) {
    char tecla;
    switch (opcao)
    {
    case 1:
        do {
            system("clear || cls");
            printf("+---------------------------------------------------------+\n");
            printf("|                                                         |\n"); 
            printf("|                Arquivo gerado com sucesso!              |\n"); 
            printf("|                                                         |\n"); 
            printf("|                              //                         |\n"); 
            printf("|                         \\\\  //                          |\n"); 
            printf("|                          \\\\//                           |\n"); 
            printf("|                           \\/                            |\n"); 
            printf("|                                                         |\n"); 
            printf("|              Caso sua impressora não esteja             |\n"); 
            printf("|              funcionando você podera salvar             |\n"); 
            printf("|              o arquivo consigo como backup              |\n"); 
            printf("|                                                         |\n"); 
            printf("|                                                         |\n"); 
            printf("|         Pressione enter para retornar ao menu...        |\n"); 
            printf("|                                                         |\n"); 
            printf("+---------------------------------------------------------+\n");
            //Todo: trocar por _flushall()
            clean_stdin();
            scanf("%c", &tecla);
        } while (tecla != '\n');
        break;
    
    case 2:
        do {
            system("clear || cls");
            printf("+---------------------------------------------------------+\n");
            printf("|                                                         |\n"); 
            printf("|                Arquivo gerado com sucesso!              |\n"); 
            printf("|                                                         |\n"); 
            printf("|                              //                         |\n"); 
            printf("|                         \\\\  //                          |\n"); 
            printf("|                          \\\\//                           |\n"); 
            printf("|                           \\/                            |\n"); 
            printf("|                                                         |\n"); 
            printf("|       Você será redirecionado para tela de login de     |\n"); 
            printf("|       seu email. Ao logar, anexe o arquivo gerado e     |\n"); 
            printf("|       o envie para o seguinte endereço:                 |\n"); 
            printf("|                   central_ti@ifsp.edu.br                |\n"); 
            printf("|                                                         |\n"); 
            printf("|         Pressione enter para retornar ao menu...        |\n"); 
            printf("|                                                         |\n"); 
            printf("+---------------------------------------------------------+\n");
            //Todo: trocar por _flushall()
            clean_stdin();
            scanf("%c", &tecla);
        } while (tecla != '\n');
        break;
    }
    
}

void main()
{   
    int loopInfinito = 1;
    char escolha;

    do {
        system("clear");
        printf("                  .  ..___\\  /.  . __.                    \n");        
        printf("                  |\\ |[__  >< |  |(__                     \n");          
        printf("                  | \\|[___/  \\|__|.__)                   \n");        
        printf("             Conectando problemas a solucoes               \n");  
        printf("+---------------------------------------------------------+\n");
        printf("|        ________________                                 |\n"); 
        printf("|       /               /|                                |\n"); 
        printf("|      /_______________/ |      ========= Menu =========  |\n");
        printf("|      |  __________  |  |      [1] Computador            |\n"); 
        printf("|      | |          | |  |      [2] Rede / Internet       |\n"); 
        printf("|      | |   Help!  | |  |      [3] Teclado / Mouse       |\n"); 
        printf("|      | |    :(    | |  |      [4] Outro Problema        |\n"); 
        printf("|      | |__________| | /       [5] Sair                  |\n");  
        printf("|      |______________|/ ___/\\                            |\n");     
        printf("|     |____>______<_____/     \\                           |\n");             
        printf("|    / = ==== ==== ==== /|    _|_                         |\n"); 
        printf("|   / ========= === == / /   ////                         |\n"); 
        printf("|  /   ========= ===  / /   /   /                         |\n"); 
        printf("| <__________________<_/    ¯¯¯¯                          |\n"); 
        printf("|                                                         |\n"); 
        printf("+---------------------------------------------------------+\n");

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

//Todos: 
// 1 - Identificar possíveis constantes 
// 2 - Fazer tratamento de strings (nomes com iniciais maiusculas, etc...)
// 3 - Controlar o limite de caracteres digitados
// 4 - Tela de instrução de envio/manipulação do arquivo
// 5 - Ideias para diminuir o código 

