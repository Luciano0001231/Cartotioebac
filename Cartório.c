#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço e memória 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca resporável por cuidar de todas as strings
// \t SERVE PARA DAR ESPAÇAMENTO NA MESMA LINHA 
// \n SERVE PARA PULAR QUANTAS LINHAS FOREM DESEJADAS


int registro() //funçao resposavel por cadastrar usuarios no sitema 
{   
    // inicio da ciração de variaveis/string
    char arquivo[40];
  	char cpf[40];
  	char nome[40];
  	char sobrenome[40];
  	char cargo[40];
  	// final da criação de variaveis/string
  	
  	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuario 
  	scanf("%s", cpf); //%s refe-se a strings 
  	
  	strcpy(arquivo, cpf); //Resposável por copiar os valores das strings
  	
  	FILE *file; // Cria o arquivo
  	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever 
  	fprintf(file,cpf); // salva valor da variavel 
  	fclose(file); // fecha o arquivo 
  	
  	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
  	
  	system("pause"); //pausa o sistema na tela atual 
	
	
	
}

int consulta() // funçao resposavel por consultar os usuarios 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
   
    
	if(file == NULL)
	{
		printf("CPF inválido! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //while significa enquanto
	{
		printf("\nInformações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	
		
	}
	    system("pause");
	    
}

int deletar() // funçao responsavel por deletar o usuarios 
{
   char cpf[40];
   
   printf("Digite o Cpf do usuario a ser deletado: ");
   scanf("%s", cpf);
   
   FILE *file;
   file = fopen(cpf,"r");  // Abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
   
   if (file == NULL)  // Em caso de numero digitado não encontrado no arquivo
   {
    
   	printf("CPF inválido! \n"); //Essa mensagem é exibida ao usuario 
   	system("pause"); //Comando que pausa na tela atual 
   	return 0; //Comando que faz o usuario retornar a tela inicial 
   	
   }
   
    fclose(file); //Fechar o arquivo depois de verificar a existecia dele
    
    printf("Deseja deletar este CPF do sitema? "); //Confirmando a escolha do usuario sobre deletar ou nao este aluno
    printf("%s", cpf);
    printf("\nDigite (S) para sim ou digite (N) para não!\n\n"); //Dando escolhas de caracteres para o usuario fazer a escolha 
   
    getchar(); //Funçao para capturar a estrada do usuario atraves de caracteres
   
    char opcao; //Criando variavel opção
    opcao = getchar(); //Definindo que a variavel opçao sera referente ao getchar (caractere que iremos estipular/utilizar
   
    if (opcao == 's' || opcao == 'S') //se o caractere digitado for s minusculo ou S maiusculo 
   {
	if (remove(cpf) == 0) //remove o arquivo cpf e confere se a remoçao foi bem sucedida
   {
   	printf("CPF deletado com sucesso!\n"); //caso bem sucedida, insere a mensagem ao usuario 
   }
    system("pause");
   }
   
   else if (opcao == 'n' || 'N')
   { printf("Retorne ao menu principal\n");
     system("pause");
   }
   
   else 
   { printf("Opção inválida");  //caso cpf do usuario não seja encontrado 
     sytem("pause");
	  }   
    
}

int main ()
{
	int opcao=0; //Definindo variáveis 
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system("cls"); // responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
  
  
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário 
	
		system("cls");
		
		switch(opcao)
		{ 
			case 1:
			registro();
			break;
			
			case 2: 
			consulta();
	     	break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
			
		}
		// >=4 da erro, || significa ou <=0 tambem dará erro e mostrará a mensagem 
	}
}
		
	
	

