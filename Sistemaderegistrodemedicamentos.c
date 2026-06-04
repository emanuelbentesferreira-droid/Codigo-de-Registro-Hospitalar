#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Medicamento {
    char nome[50];
    int quantidade;
    char dias[50];
    char horarios[50];
	};


int main(int argc, char *argv[]) {
    struct Medicamento lista[100];
    int total = 0;
	int opcao;
    
	do {
    printf("\n===============================\n");
	printf("\n----- MENU -----\n");
    printf("1 - Cadastrar medicamento\n");
    printf("2 - Listar medicamentos\n");
    printf("3 - Buscar por horario\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
     if (scanf("%d", &opcao) != 1) {
        system("cls");
		printf("Entrada invalida! Digite um numero.\n");

         // limpa o buffer
        while(getchar() != '\n'); //                                                        tudo que tá dentro das chaves do while se repete enquanto a condição -que é o que tá dentro do parêntese - for verdadeira

        opcao = -1; // força erro
        continue;//reinicia o menu com segurança
        }
        
    switch(opcao) {

    case 1:
        system("cls");
		if(total <100){
		printf("Cadastrar...\n");
		printf("Nome: ");
		scanf("%s", lista[total].nome);//E %s pois 
		printf("Quantidade: ");
		scanf("%d", &lista[total].quantidade);
		printf("Dias: ");
		scanf("%s",lista[total].dias);
		printf("Horarios: ");
		scanf("%s", lista[total].horarios);
		
		total++;
		
		FILE *f = fopen("dados.txt", "a");

        if(f != NULL){
        fprintf(f, "%s | %d | %s | %s\n",lista[total-1].nome,
		lista[total-1].quantidade,
		lista[total-1].dias,
		lista[total-1].horarios);
        fclose(f);
}
		
		printf("Medicamentos cadsatrado com sucesso!!!\n");
		
		}else {
		printf("limite foi atingido doido!!!");
		}
		
        break;
    
	case 2:
     system("cls");
	printf("Listar...\n");
	for(int i = 0; i < total; i++) {   //-std=c99?
    printf("\nMedicamento %d\n", i+1);
    printf("Nome: %s\n", lista[i].nome);
    printf("Quantidade: %d\n", lista[i].quantidade);
    printf("Dias: %s\n", lista[i].dias);
    printf("Horarios: %s\n", lista[i].horarios);

    }  
    break;

    case 3:
        system("cls");
        printf("Busca por horario.....\n");
        
		char busca[50];
        int encontrado = 0;
        
        printf("Digite o horario:  ");
        scanf("%s", busca);
        
		for(int i = 0; i < total; i++) {   //-std=c99
        if(strcmp(lista[i].horarios, busca) == 0) { //Compara endereços na memoria
        printf("\nMedicamentos encontrado da lista %d\n", i+1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Quantidade: %d\n", lista[i].quantidade);
        printf("Dias: %s\n", lista[i].dias);
        printf("Horarios: %s\n", lista[i].horarios);
        
		encontrado = 1;
	}
	}
   if(encontrado == 0){
        printf("Nenhum medicamento cadastrado nesse horario.\n");
    }
		break;

    case 4:
        system("cls");
		printf("Saindo...\n");
        break;

    default:
        system("cls");
		printf("Opcao invalida!\n");
}
} while(opcao != 4);
    return 0;
}	
	
	

