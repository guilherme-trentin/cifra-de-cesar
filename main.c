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
        pos = texto[i] - base;                                /*Descobre a posição, como a = 0, a posição das letras não mudam. Por exemplo: b = 1, b - a = 1 */
        new_pos = (((pos + chave) % 26) + 26) % 26;           /*Descobre a nova posição somando a letra com a chave. Por exemplo: chave = 3, chave + b = 4*/
        new_letra = new_pos + base;                           /*Valor das letras depois de criptografada. Por exemplo: b = 1 e chave = 5, depois de criptografar b = 6*/
        texto[i] = new_letra;
    }
}

void decifrar_cesar(char *texto, int chave){
    chave = -(chave % 26);
    cifrar_cesar(texto, chave);
}