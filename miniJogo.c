// Algumas das importações abaixo foram sugeridas pelo chat do bing, outras, após ter erro de compilação, e ver no StackOverflow que precisava importar.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void jogoPerguntaResposta() {

    int resposta;
    bool jogarNovamente = true;

    while (jogarNovamente) {

        // Perguntas
        printf("\nPergunta 1: Qual eh a capital do Brasil?\n");
        printf("1: Sao Paulo\n");
        printf("2: Rio de Janeiro\n");
        printf("3: Brasilia\n");
        printf("4: Salvador\n");
        printf("Escolha a alternativa correta: ");
        scanf("%d", &resposta);
        if (resposta == 3) {
            printf("Resposta correta!\n");
        } else {
            printf("Resposta incorreta. A resposta correta eh Brasilia.\n");
        }

        printf("\nPergunta 2: Qual eh o maior pais do mundo em area territorial?\n");
        printf("1: Russia\n");
        printf("2: Canada\n");
        printf("3: China\n");
        printf("4: Estados Unidos\n");
        printf("Escolha a alternativa correta: ");
        scanf("%d", &resposta);
        if (resposta == 1) {
            printf("Resposta correta!\n");
        } else {
            printf("Resposta incorreta. A resposta correta eh Russia.\n");
        }

        printf("\nPergunta 3: Quem produz as placas de video GTX e RTX?\n");
        printf("1: AMD\n");
        printf("2: INTEL\n");
        printf("3: HP\n");
        printf("4: NVIDIA\n");
        printf("Escolha a alternativa correta: ");
        scanf("%d", &resposta);
        if (resposta == 4) {
            printf("Resposta correta!\n");
        } else {
            printf("Resposta incorreta. A resposta correta eh NVIDIA.\n");
        }

        printf("\nPergunta 4: Quem produz os processadores RYZEN?\n");
        printf("1: AMD\n");
        printf("2: INTEL\n");
        printf("3: HP\n");
        printf("4: SAMSUNG\n");
        printf("Escolha a alternativa correta: ");
        scanf("%d", &resposta);
        if (resposta == 1) {
            printf("Resposta correta!\n");
        } else {
            printf("Resposta incorreta. A resposta correta eh AMD.\n");
        }

        printf("\nPergunta 5: Segundo Benchmarks, quem lidera o mercado de processadores de Personal Computers?\n");
        printf("1: AMD\n");
        printf("2: INTEL\n");
        printf("3: SNAPDRAGON\n");
        printf("4: EXYNOS\n");
        printf("Escolha a alternativa correta: ");
        scanf("%d", &resposta);
        if (resposta == 2) {
            printf("Resposta correta!\n");
        } else {
            printf("Resposta incorreta. A resposta correta eh INTEL.\n");
        }

        printf("Deseja jogar novamente? (1 para sim, 0 para nao): ");
        scanf("%d", &resposta);
        jogarNovamente = resposta;
    }
}

void jogoCobraNaCaixa() {
    char jogador1[50];
    char jogador2[50];
    int caixas[5] = {0, 0, 0, 0, 0}; // 0 = vazia, 1 = cobra, 2 = botão
    int cobra, botao;
    int escolha;
    bool jogarNovamente = true;
    bool turnoJogador1;
    // A função abaixo e a rand() foi sugerida pelo chat do bing.
    srand(time(NULL));

    printf("\nJogador 1, digite seu primeiro nome: ");
    scanf("%s", jogador1);
    printf("\nJogador 2, digite seu primeiro nome: ");
    scanf("%s", jogador2);

    while (jogarNovamente) {
        // Sorteia a posição da cobra e do botão
        cobra = rand() % 5;
        caixas[cobra] = 1;
        do {
            botao = rand() % 5;
        } while (botao == cobra);
        caixas[botao] = 2;

        // Sorteia quem começa jogando
        turnoJogador1 = rand() % 2;
        if (turnoJogador1) {
            printf("%s comeca!\n", jogador1);
        } else {
            printf("%s comeca!\n", jogador2);
        }

        while (true) {
            if (turnoJogador1) {
                printf("Vez de %s. Escolha uma caixa (1-5): ", jogador1);
            } else {
                printf("Vez de %s. Escolha uma caixa (1-5): ", jogador2);
            }

            scanf("%d", &escolha);
            escolha--;

            if (escolha < 0 || escolha > 4) {
                printf("Escolha invalida. Tente novamente.\n");
                continue;
            }

            if (caixas[escolha] == 0) {
                printf("A caixa esta vazia.\n");
                turnoJogador1 = !turnoJogador1;
            } else if (caixas[escolha] == 1) {
                printf("Voce encontrou a cobra! Fim de jogo.\n");
                break;
            } else if (caixas[escolha] == 2) {
                printf("Voce encontrou o botao! Parabens!\n");
                break;
            }
        }

        // Reseta as caixas
        memset(caixas, 0, sizeof(caixas));

        printf("\nDeseja jogar novamente? (1 para sim, 0 para nao): ");
        scanf("%d", &escolha);
        jogarNovamente = escolha;

        if (escolha == 1) {
            jogarNovamente = true;
        } else {
            jogarNovamente = false;
        }
        

    }
}

int main() {

    int opcao;


    while (opcao != 3) {
    
        printf("\nTITULO DO JOGO\n");
        printf("1: Pergunta e resposta\n");
        printf("2: Cobra na caixa!\n");
        printf("3: Sair.\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            
            case 1:
                printf("\nVoce recebe 5 perguntas no total, e tera 4 alternativas para cada uma.\n");
                printf("\nDeseja comecar? (1 para sim, 0 para nao): ");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    jogoPerguntaResposta();
                }
                break;
            case 2:
                printf("\nVoce e seu colega de trabalho estavam explorando a tumba do farao Neebe quando\nentraram em uma grande sala com escrituras na parede. Enquanto inspecionavam as\nescrituras, voces acidentalmente pressionaram um botao escondido que lacrou as\nportas, prendendo-os la dentro. Entao, cinco caixas apareceram no centro da sala, uma\ndelas contendo o botao para abrir as portas, mas uma delas contem uma cobra mortal!\nVoces decidem jogar turnos para abrir uma caixa de cada vez, na esperança de nao encontrar a cobra.!\n");
                printf("\nDeseja comecar? (1 para sim, 0 para nao): ");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    jogoCobraNaCaixa();
                }
                break;
            default:
                printf("Opcao invalida/Voce saiu.\n");
        }

    }
    return 0;
}