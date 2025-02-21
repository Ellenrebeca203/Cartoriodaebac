#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos strings

int registro() //criando as variáveis/string
{
	//início da criação das variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação das variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string, usado para salvar ela
	
	strcpy (arquivo, cpf); //Responsável por copiar os valores da string
		
	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); //cria o arquivo, "w" significa escrever
	fprintf(file, cpf); //fprintf é para armazenar dentro do arquivo, ou seja salvar o valor da variável
	fclose(file); //fecha o arquivo
	

	file = fopen(arquivo, "a"); //cria arquivo, "a" de atualizar
	fprintf(file, ","); //armazenar dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta informação do usuário
	scanf("%s", nome); //salva a informação dentro da string
	
	file = fopen (arquivo, "a"); //cria arquivo
	fprintf(file, nome); //armazena dentro do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	system ("pause");		
}
	
int consulta()
{

	setlocale(LC_ALL, "Portuguese");//Definindo o idioma 

	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{ 
		printf("O usuário não se encontra no sistema!");
		system("pause");
		
	}
}

int main()
{

	int opcao=0;//Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar a tela, ou seja, deletar tudo que foi escrito
		
		setlocale(LC_ALL, "Portuguese");//Definindo o idioma
	
		printf("### Cartório de registro EBAC ###\n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1- Registrar nomes:\n");
		printf("\t2- Consultar nomes:\n");
		printf("\t3- Deletar nomes:\n\n");//Fim do menu 
		printf("\t4- Sair do sistema\n\n");
		printf("Opção:");
	
		scanf("%d", &opcao);//Armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)//Inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção está indisponível!\n");
			system("pause");
			break;
				
		}//Fim da seleção
	
	
	}	 
}
