#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro ()                                       //Funcao responsavel por cadastrar os usuarios no sistema
{														//Criando as variaveis/string
	char arquivo[40];                                   
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");         //Coletando informacao do usuario
	scanf("%s", cpf);                                	//Armazenando a informacao do usuario em string
	
	strcpy(arquivo, cpf);            					 //responsavel por copiar os valores das string
	
	FILE *file;                      						// Buscando em arquivos no sistema, criando arquivo
	file = fopen(arquivo, "w");   							   // Abrindo arquivo e "w" funcao de escrita
	fprintf(file,cpf);              							 // salvo o valor da variavel cpf dentro do arquivo
	fclose(file);													// fechar o arquivo
	
	file = fopen(arquivo, "a");      					//Abrindo o arquivo salvo e dando comando de atualizar
	fprintf(file, ",");                                 	//pedindo para salvar informacao 
	fclose(file);                                               //Fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: " );
	scanf ("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");      					
	fprintf(file, ",");                                 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");      					
	fprintf(file, ",");                                 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");                           // Pausando a tela para que o usuario nao volte ao menu automaticamente.
	
}                                              // Fim da funcao Registro

int consulta ()
{
	setlocale(LC_ALL, "Portuguese");         //Definindo Linguagem p/portugues

	char cpf[40];                              //Criando variaveis novamente  
	char conteudo[200];
		
	printf("Digite o CPF a ser consultado: ");     //Pedindo para o usuario inserir o CPF desejado
	scanf("%s", cpf);                                 // armazenando informacoes na variavel cpf
	
	FILE *file;                                             //Localizando o arquivo
	file = fopen(cpf,"r");                                    //Abrindo o arquivo cpf, "r" para leitura

	if(file == NULL)                                            //Caso a informacao nao for encontrada no arquivo...
{
	printf("\n\nNumero de CPF não encontrado! \n\n");               //Exibir essa mensagem ao usuario
	system("pause");
}
	while(fgets(conteudo, 200, file) != NULL)                      //Enquanto obtiver a o conteudo no arquivo, armazena informacao, caso contrario (NULL) volta para o menu
{
	printf("\nEssas são as informaçoes do usuario: \n\n");           //Exibir essa informacao para o usuario com os dados encontrados no arquivo
	printf("%s", conteudo);    
	printf("\n\n");                                                    //Comando para pular linhas na exibicao.
	
	system("pause");                                                      // Pausando a tela para que o usuario nao volte ao menu automaticamente.
}
		
}                                         // Fim da funcao consulta
	
int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do aluno a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;                                 // Abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	file = fopen(cpf,"r");
	
	if (file == NULL)                          // Em caso de numero digitado nao encontrado no arquivo...
	{
		printf("O CPF digitado nao foi encontrado no sistema!. \n");        // Essa mensagem é exibida ao usuario
		system("pause");                                                      // Comando que pausa na tela atual
		return 0;                    // Comando que faz o usuario retornar a tela inicial
	}
	
	fclose(file);                                             // Fechar o arquivo depois de verificar a existencia dele
		
	printf("Deseja deletar este aluno do sistema? ");            // Confirmando a escolha do usuario sobre deletar ou nao este aluno
	printf("%s",cpf);                                                
	printf("\nDigite (s) para sim ou digite (n) para nao! \n\n");  // Dando escolhas de caracteres para o usuario fazer a escolha
	
	getchar();                       // Funcao para capturar a entrada do usuario atraves de caracteres
	
	char opcao;                        // criando variavel opcao
	opcao = getchar();                    // definindo que a variavel opcao sera referente ao getchar (caractere que iremos estipular)
		
	if (opcao == 's' || opcao == 'S')           // se o caractere digitado for s minisculo ou S maiusculo
	{
	if (remove(cpf) == 0)                        // remove o arquivo cpf e confere se a remocao foi bem sucedida
	{
		printf("Aluno deletado com sucesso!\n");     // caso bem sucedida, insere a mensagem para o usuario saber
	}
		system("pause");
	}
	
	
	else if (opcao == 'n' || opcao == 'N')               // se o caractere digitado for n minusculo ou N maiusculo
	{
		printf("Retorne ao menu principal \n");            // Essa mensagem sera mostrada para o usuario
		system("pause");
	}
		
	else
	{
		printf("\nOpcao invalida, retorne ao menu\n\n");                            // Mensagem mostrada caso o usuario digite outro caractere que nao seja (s) ou (n)
		system("pause");
	}
	}                                         // Fim da funcao deletar

	
int main ()
{
    int opcao=0;	        //Definindo variaveis
    int laco=1;
    
    for(laco=1;laco=1;)                         // Criando laco
    {
    	
		system("cls");                         //Apagando mensagens da tela 
		
		setlocale(LC_ALL, "Portuguese");         //Definindo Linguagem para Portugues    
	
		printf("### Cartório da EBAC ###\n\n");                      //Inicio do Menu                       
    	printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
    	printf("\t3 - Deletar nomes \n");      
    	printf("\t4 - Sair do sistema \n\n"); 
    	printf("Opcao:");						                 	//Fim do Menu
	
		scanf("%d", &opcao);				//Armazenando a escolha do usuario de acordo com a variavel
	
		system("cls");                      //Apagando mensagens da tela 
		
		
		switch(opcao)                    //Inicio da selecao MENU
		{
			case 1:                    
			registro();                     //Chamada de funcao Registro
			break;
	
			case 2:
			consulta();                      //Chamada de funcao Consulta
			break;
		
			case 3:
			deletar();                        //Chamada de funcao Deletar
			break;
		
			case 4:
			printf("Obrigado por utilizar o sistema de registros!\n");
			return 0;
			break;
			
			default:
			printf("Essa nao é uma opcao válida\n");               
			system("pause");
			break;
		}                                      //Fim da selecao
		
	}                                             //Fim do laco
	
}                                                    //Fim da funcao int main
