# Cifra de César

Programa de terminal em C que cifra e decifra mensagens de texto com a cifra de César. Você digita a frase e a chave (o deslocamento), e o programa devolve o texto transformado.

## Como funciona

Cada letra é deslocada no alfabeto pela quantidade indicada pela chave. Com chave 3, `a` vira `d` e `x` vira `a` (o alfabeto dá a volta). Para decifrar, o programa desloca as letras na direção contrária.

- Maiúsculas e minúsculas são preservadas.
- Espaços, números e pontuação não são alterados.
- A chave aceita valores que caibam no tipo `int`. Valores negativos também funcionam, e a chave é reduzida ao intervalo de 0 a 25 antes do cálculo.

## Como compilar

É necessário ter o `gcc` instalado. No terminal, dentro da pasta do projeto, execute:

```sh
gcc -Wall -Wextra main.c -o cifra
```

## Como executar

Linux/macOS:

```sh
./cifra
```

Windows (PowerShell):

```powershell
.\cifra.exe
```

## Exemplo de uso

Cifrar `Oi Mundo` com chave 3:

```text
---Menu---
1. Criptografar a mensagem.
2. Descriptografar a mensagem.
3. Sair.
1
Digite uma frase:
Oi Mundo
Digite o deslocamento da chave:
3
Rl Pxqgr
```

Decifrar `Rl Pxqgr` com a mesma chave:

```text
---Menu---
1. Criptografar a mensagem.
2. Descriptografar a mensagem.
3. Sair.
2
Digite uma mensagem:
Rl Pxqgr
Digite o deslocamento da chave:
3
Oi Mundo
```

O menu se repete até você escolher a opção 3.

## Limitações conhecidas

- Letras acentuadas, como `ç`, `ã` e `é`, não são cifradas.
- O programa não valida entradas não numéricas para a opção do menu nem para a chave; elas podem causar comportamento incorreto.
- O texto é armazenado em um buffer de 100 caracteres. Entradas maiores podem ser truncadas, e o trecho restante pode interferir nas leituras seguintes.

## Próximos passos

Este projeto é a primeira etapa de um toolkit de criptografia clássica em C. Planejado:

- [ ] Ler e gravar arquivos
- [ ] Argumentos de linha de comando
- [ ] Cifra de Vigenère
- [ ] Cifra XOR
- [ ] Quebra da cifra de César por análise de frequência
