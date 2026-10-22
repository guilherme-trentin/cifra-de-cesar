#include <stdio.h>
#include <string.h>

void cifrar_cesar(char *texto, int chave);
void decifrar_cesar(char *texto, int chave);

int main(void){
    char texto[100];
    int chave;
    int opc;


    do{

        printf("---Menu---\n");
        printf("1. Criptografar a mensagem.\n");
        printf("2. Descriptografar a mensagem.\n");
        printf("3. Sair.\n");
        scanf("%d", &opc);
        getchar();

        switch(opc){ 
            
            case 1:
                printf("Digite uma frase: \n");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = '\0';

                printf("Digite o deslocamento da chave: \n");
                scanf("%d", &chave);
                
                cifrar_cesar(texto, chave);
                printf("%s\n", texto);
                break;
            
            case 2:

                printf("Digite uma mensagem: \n");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = '\0';

                printf("Digite o deslocamento da chave: \n");
                scanf("%d", &chave);
                

                decifrar_cesar(texto, chave);
                printf("%s\n", texto);
                break;

            case 3:

                printf("Fim.\n");
                break;

            default:

                printf("Opcao invalida. Digite uma opcao valida.\n");
        }


    }while (opc != 3);
}

void cifrar_cesar(char *texto, int chave){
    int i;
    int pos;                
    int new_pos;            
    int new_letra;          
    char base;

    /*Reduz qualquer chave para 0 a 25. Duas razões: evita estouro do int na soma e trata chave negativa.*/
    chave = ((chave % 26) + 26) % 26;

    for(i = 0; texto[i] != '\0'; i++){
        
        if(texto[i] >= 'a' && texto[i] <= 'z'){ 
            base = 'a';
        }
        else if(texto[i] >= 'A' && texto[i] <= 'Z'){
            base = 'A';
        }
        else{
            /*não é letra: pula para o próximo caractere*/
            continue;
        }
        /*pos: Converte o caractere na posição dele no alfabeto (0 a 25). A base é 'a' ou 'A', conforme o caso.*/
        pos = texto[i] - base;

        /*new_pos: Anda a posição pela chave e dá a volta no alfabeto, é o % 26 que faz a volta.*/
        new_pos = (((pos + chave) % 26) + 26) % 26;

        /*new_letra: Converte a posição de volta em caractere, usando a mesma base.*/
        new_letra = new_pos + base;

        texto[i] = new_letra;
    }
}

void decifrar_cesar(char *texto, int chave){
    /*Reduz antes de negar. Se negasse primeiro, -(-2147483648) estouraria o int. Depois chama cifrar_cesar com a chave negativa, que anda para trás.*/
    chave = -(chave % 26);
    cifrar_cesar(texto, chave);
}