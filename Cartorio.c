#include <stdio.h> //Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria.
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o.
#include <string.h> //Biblioteca respons�vel por cuidar das string.

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema.
{
	char arquivo[40];//Inicio Cria��o Vari�vel/string.
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];//Fim Cria��o Variavel/string.
    
    printf("Digitar CPF a ser Cadastrado:");//Coletar Informa��o do Usu�rio.
    scanf("%s", cpf);//%s Refere-se a string,o cpf que sera salvo na string.

    strcpy(arquivo, cpf);//Respons�vel por copiar os valores das string.

    FILE *file;//Cria o Arquivo no Banco de Dados.
    file = fopen(arquivo, "w");//Cria o Arquivo no Banco de Dados.
    fprintf(file,cpf);//Salvando o conte�do da vari�vel cpf dentro do arquivo.
    fclose(file);//Fecho o arquivo.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,",");//Salva aquivo e separa.
    fclose(file);//Fecha o arquivo.
    
    printf("Digite o Nome a ser Cadastrado: ");//Coletar Informa��o do Usu�rio.
    scanf("%s",nome);//%s Refere-se a string,o nome que sera salvo na string.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,nome);//Salvando o conte�do da vari�vel nome dentro do arquivo.
    fclose(file);//Fecha o arquivo.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,",");//Salva aquivo e separa.
    fclose(file);//Fecha o arquivo.
    
    printf("Digite Sobrenome a Cadastrar: ");//Coletar Informa��o do Usu�rio.
    scanf("%s",sobrenome);//%s Refere-se a string,o Sobrenome que sera salvo na string.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,sobrenome);//Salvando o conte�do da vari�vel Sobrenome dentro do arquivo.
    fclose(file);//Fecha o arquivo.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar.
    fprintf(file,",");//Salva aquivo e separa.
    fclose(file);//Fecha o arquivo.
    
    printf("Digitar Cargo a Cadastrar: ");//Coletar Informa��o do Usu�rio.
    scanf("%s",cargo);//%s Refere-se a string,o Cargo que sera salvo na string.
    
    file = fopen(arquivo, "a");//Abrir arquivo salvo e atualizar
    fprintf(file,cargo);//Salvando o conte�do da vari�vel Cargo dentro do arquivo.
    fclose(file);//Fecha o arquivo.
    
    system("pause");//Pausar o programa no menu. 
    
}

int consulta()//Fun��o respons�vel por consultar os usu�rios cadastrados no sistema.
{
	setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem.
	
	char cpf[40];//Criar arquivo cpf.
	char conteudo[200];//Conte�do do arquivo.
	
	printf("Digitar CPF a ser consultado: ");//Consultando o cpf do usu�rio.
	scanf("%s",cpf);//Salvando a consulta da string cpf.
	
	FILE *file;//Consultar arquivo cpf.
	file = fopen(cpf,"r");//Abrir o arquivo cpf e ler.

    if(file == NULL)//Se o arquivo n�o for localizado  null.
    {
    	printf("N�o foi possivel abrir o arquivo, n�o Localizado!.\n");//Caso o arquivo n�o seja localizado aparece na tela a est� msg.	
	}

    while(fgets(conteudo,200, file) != NULL)//Fun��o la�o de repeti��o,esta salvando 200 caracteres que est�o dentro do arquivo,e quando n�o encontrar null.
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//Mostrando na tela as informa��es do usu�rio.
		printf("%s", conteudo);//Salvando o conte�do dentro da string.
		printf("\n\n");//Pular duas linhas.
	} 

     system("pause");//Pausar o programa no menu. 
     
     
}

int deletar()//Fun��o respons�vel por deletar os usu�rios cadastrados no sistema.
{
	char cpf[40];//Criar arquivo cpf.
	
	printf("Digitar CPF do Usu�rio a Deletar: ");//Consultando o cpf do usu�rio.
	scanf("%s",cpf);//%s Refere-se a string,o CPF que sera removido na string.
	
	remove(cpf);//Deletar.
	
	FILE *file;//Consultar arquivo cpf.
	file = fopen(cpf,"r");//Ler o valor da string e abrir.
	 
	if(file == NULL)//Se o arquivo n�o for localizado null.
	{
		printf("O Usu�rio n�o faz parte do sistema!.\n");//Caso o arquivo n�o seja localizado aparece na tela a est� msg.	
		system("pause");//Pausar o programa no menu. 	
	}
	 
}



int main()//Fun��o Principal.
   {
	int opcao=0;//Definindo Vari�veis.
	int laco=1;//Vari�vel. 
	 
	for(laco=1;laco=1;)///la�o de repeti��o para voltar ao Menu Principal.
	{
		
	   system("cls");//Limpar tela.
	
	   setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem.
	
	   printf("### Cart�rio da EBAC ###\n\n");//Inicio Do Menu Principal.
	   printf("Escolha a op��o desejada no menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Op��o:");//Fim do Menu Principal.
	
       scanf("%d", &opcao);//Armazenando a Escolha do Usu�rio.
	
       system("cls");//Limpar a Tela.
       
	    switch(opcao)//Inicio sele��o do Menu.
	    {
	   	  case 1://Vari�vel 1.
	      registro();//Chamada do Case 1.
          break;
          
          case 2://Vari�vel 2.
          consulta();//Chamada do Case 2.
          break;
		  
		  case 3://Vari�vel 3.
		  deletar();//Chamada do Case 3.
		  break;	
		  
		  default://Caso n�o haja vari�vel dispon�vel.
		  printf("Essa Op��o N�o Est� Disponivel\n");
          system("pause");//Pausar o programa no menu .
		  break; //Fim da Sele��o.	  	
	    }
				
   }	
}     
