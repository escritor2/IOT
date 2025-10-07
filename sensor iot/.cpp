#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <locale>

using namespace std;

#define TAM 10
#define NUM_NAVIOS 5

typedef struct {
    const char* nome;
    int tamanho;
} Navio;

static const Navio NAVIOS_BASE[NUM_NAVIOS] = {
    {"Porta-aviões", 5},
    {"Encouraçado", 4},
    {"Cruzador", 3},
    {"Submarino", 3},
    {"Destroyer", 2}
};

typedef struct {
    char msg[30];
    char cell[TAM][TAM];
    char mask[TAM][TAM];
} Tabuleiro;

void inicia_tabuleiro(Tabuleiro *t, const char *msg)
{
    for (int l=0; l<TAM; l++)
        for (int c=0; c<TAM; c++) {
            t->cell[l][c] = 0;
            t->mask[l][c] = '.';
        }
    strcpy(t->msg, msg);
}

void mostrar_tabuleiro(Tabuleiro *t)
{
    cout << "\n\n" << t->msg << ":";
    cout << "\n    A B C D E F G H I J";
    for (int l=0; l<TAM; l++) {
        cout << "\n" << (l+1 < 10 ? " " : "") << l+1 << " ";
        for (int c=0; c<TAM; c++) {
            cout << " " << t->mask[l][c];
        }
    }
}

bool pode_colocar(Tabuleiro *t, int id, int l, int c, bool horiz)
{
    int tam = NAVIOS_BASE[id].tamanho;
    for (int i=0; i<tam; i++) {
        int ll = l + (horiz ? 0 : i);
        int cc = c + (horiz ? i : 0);
        if (ll >= TAM || cc >= TAM) return false; // evita sair do tabuleiro
        if (t->cell[ll][cc] != 0) return false;
    }
    return true;
}

void colocar_navio(Tabuleiro *t, int id, int l, int c, bool horiz, bool visivel)
{
    int tam = NAVIOS_BASE[id].tamanho;
    for (int i=0; i<tam; i++) {
        int ll = l + (horiz ? 0 : i);
        int cc = c + (horiz ? i : 0);
        t->cell[ll][cc] = id+1;
        if (visivel)
            t->mask[ll][cc] = 'S';
    }
}

void navios_aleatorios(Tabuleiro *t, bool visivel)
{
    for (int id=0; id<NUM_NAVIOS; id++) {
        bool colocado = false;
        while (!colocado) {
            bool horiz = rand() % 2;
            int l = rand() % TAM;
            int c = rand() % TAM;
            if (pode_colocar(t, id, l, c, horiz)) {
                colocar_navio(t, id, l, c, horiz, visivel);
                colocado = true;
            }
        }
    }
}

void instrucoes()
{
    cout << "==== BATALHA NAVAL (C++, 10x10) ====\n";
    cout << "- Você joga contra o computador.\n";
    cout << "- Formatos de tiro: A5, J10.\n";
    cout << "- Navios (tamanhos): Porta-aviões(5), Encouraçado(4), Cruzador(3), Submarino(3), Destroyer(2).\n";
    cout << "- Seu tabuleiro mostra seus navios. O inimigo fica oculto.\n";
    cout << "===================================\n\n";
}

bool atirar(Tabuleiro *alvo, int l, int c)
{
    if (l>=0 && l<TAM && c>=0 && c<TAM) {
        if (alvo->mask[l][c] != 'X' && alvo->mask[l][c] != '~') {
            if (alvo->cell[l][c] > 0)
                alvo->mask[l][c] = 'X';
            else
                alvo->mask[l][c] = '~';
            return true;
        }
    }
    return false;
}

void turno_jogador(Tabuleiro *cpu)
{
    int c, l;
    char ch;
    cout << "\nLegenda: S=navio (seu lado), X=acerto, ~=água, .=desconhecido";
    while (true) {
        cout << "\n\nSua jogada (ex A5): ";
        cin >> ch >> l;
        ch = toupper(ch);
        c = ch - 'A';
        l = l - 1;
        if (atirar(cpu, l, c))
            break;
        else
            cout << "\nTiro inválido. Tente novamente.";
    }
}

void turno_cpu(Tabuleiro *jog)
{
    while (true) {
        int l = rand() % TAM;
        int c = rand() % TAM;
        if (atirar(jog, l, c)) {
            cout << "\nCPU jogou em " << char(c+'A') << l+1 << ".";
            break;
        }
    }
}

bool todos_afundados(Tabuleiro *t)
{
    for (int l=0; l<TAM; l++)
        for (int c=0; c<TAM; c++)
            if (t->cell[l][c] > 0 && t->mask[l][c] != 'X')
                return false;
    return true;
}

int main()
{
    srand(time(NULL));
    instrucoes();

    Tabuleiro jog, cpu;
    inicia_tabuleiro(&jog, (char*)"Seu tabuleiro");
    inicia_tabuleiro(&cpu, (char*)"Tabuleiro inimigo");

    navios_aleatorios(&jog, true);
    navios_aleatorios(&cpu, false);

    while (true) {
        mostrar_tabuleiro(&jog);
        mostrar_tabuleiro(&cpu);

        turno_jogador(&cpu);
        if (todos_afundados(&cpu)) {
            mostrar_tabuleiro(&jog);
            mostrar_tabuleiro(&cpu);
            cout << "\n*** Você venceu! ***\n";
            break;
        }

        turno_cpu(&jog);
        if (todos_afundados(&jog)) {
            mostrar_tabuleiro(&jog);
            mostrar_tabuleiro(&cpu);
            cout << "\n*** Derrota! Seus navios foram todos afundados. ***\n";
            break;
        }
    }
    cout << "\nObrigado por jogar!\n";
    return 0;
}
