#include <stdio.h> //Biblioteca de comunicação com o usuário.
#include <stdlib.h> //Biblioteca de alocação de espaço de memória.
#include <locale.h> //Biblioteca de alocações de texto por região.
#include <string.h> //Biblioteca responsável por cuidar das string.

int registro()//Função responsável por cadastrar os usuários no sistema.
{
	char arquivo[40];//Inicio Criação Variável/string.
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];//Fim Criação Variavel/string.
    
    printf("Digitar CPF a ser Cadastrado:");//Coletar Informação do Usuário.
    scanf("%s", cpf);//%s Refere-se a string,o cpf que sera salvo na string.

    strcpy(arquivo, cpf);//Responsável por copiar os valores das string.

    FILE *file;//Cria o Arquivo no Banco de Dados.
    file = fopen(arquivo, "w");//Cria o Arquivo no Banco de Dados.
    fprintf(file,cpf);//Salvando o conteúdo da variável cpf dentro do arquivo.
    fclose(file);//Fecho o arquivo.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,",");//Salva aquivo e separa.
    fclose(file);//Fecha o arquivo.
    
    printf("Digite o Nome a ser Cadastrado: ");//Coletar Informação do Usuário.
    scanf("%s",nome);//%s Refere-se a string,o nome que sera salvo na string.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,nome);//Salvando o conteúdo da variável nome dentro do arquivo.
    fclose(file);//Fecha o arquivo.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,",");//Salva aquivo e separa.
    fclose(file);//Fecha o arquivo.
    
    printf("Digite Sobrenome a Cadastrar: ");//Coletar Informação do Usuário.
    scanf("%s",sobrenome);//%s Refere-se a string,o Sobrenome que sera salvo na string.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,sobrenome);//Salvando o conteúdo da variável Sobrenome dentro do arquivo.
    fclose(file);//Fecha o arquivo.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,",");//Salva aquivo e separa.
    fclose(file);//Fecha o arquivo.
    
    printf("Digitar Cargo a Cadastrar: ");//Coletar Informação do Usuário.
    scanf("%s",cargo);//%s Refere-se a string,o Cargo que sera salvo na string.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar
    fprintf(file,cargo);//Salvando o conteúdo da variável Cargo dentro do arquivo.
    fclose(file);//Fecha o arquivo.
    
    system("pause");//Pausar o programa no menu. 
    
}

int consulta()//Função responsável por consultar os usuários cadastrados no sistema.
{
	setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem.
	
	char cpf[40];//Criar arquivo cpf.
	char conteudo[200];//Conteúdo do arquivo.
	
	printf("Digitar CPF a ser consultado: ");//Consultando o cpf do usuário.
	scanf("%s",cpf);//Salvando a consulta da string cpf.
	
	FILE *file;//Consultar arquivo cpf.
	file = fopen(cpf,"r");//Abrir o arquivo cpf e ler.

    if(file == NULL)//Se o arquivo nâo for localizado  null.
    {
    	printf("Não foi possivel abrir o arquivo, não Localizado!.\n");//Caso o arquivo nâo seja localizado aparece na tela a está msg.	
	}

    while(fgets(conteudo,200, file) != NULL)//Função laço de repetição,esta salvando 200 caracteres que estão dentro do arquivo,e quando não encontrar null.
	{
		printf("\nEssas são as informações do usuário: ");//Mostrando na tela as informações do usuário.
		printf("%s", conteudo);//Salvando o conteúdo dentro da string.
		printf("\n\n");//Pular duas linhas.
	} 

     system("pause");//Pausar o programa no menu. 
     
     
}

int deletar()//Função responsável por deletar os usuários cadastrados no sistema.
{
	char cpf[40];//Criar arquivo cpf.
	
	printf("Digitar CPF do Usuário a Deletar: ");//Consultando o cpf do usuário.
	scanf("%s",cpf);//%s Refere-se a string,o CPF que sera removido na string.
	
	remove(cpf);//Deletar.
	
	FILE *file;//Consultar arquivo cpf.
	file = fopen(cpf,"r");//Ler o valor da string e abrir.
	 
	if(file == NULL)//Se o arquivo nâo for localizado null.
	{
		printf("O Usuário não faz parte do sistema!.\n");//Caso o arquivo nâo seja localizado aparece na tela a está msg.	
		system("pause");//Pausar o programa no menu. 	
	}
	 
}



int main()//Função Principal.
   {
	int opcao=0;//Definindo Variáveis.
	int laco=1;//Variável. 
	 
	for(laco=1;laco=1;)///laço de repetição para voltar ao Menu Principal.
	{
		
	   system("cls");//Limpar tela.
	
	   setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem.
	
	   printf("### Cartório da EBAC ###\n\n");//Inicio Do Menu Principal.
	   printf("Escolha a opção desejada no menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Opção:");//Fim do Menu Principal.
	
       scanf("%d", &opcao);//Armazenando a Escolha do Usuário.
	
       system("cls");//Limpar a Tela.
       
	    switch(opcao)//Inicio seleção do Menu.
	    {
	   	  case 1://Variável 1.
	      registro();//Chamada do Case 1.
          break;
          
          case 2://Variável 2.
          consulta();//Chamada do Case 2.
          break;
		  
		  case 3://Variável 3.
		  deletar();//Chamada do Case 3.
		  break;	
		  
		  default://Caso não haja variável disponível.
		  printf("Essa Opção Não Está Disponivel\n");
          system("pause");//Pausar o programa no menu .
		  break; //Fim da Seleção.	  	
	    }
				
   }	
}     
