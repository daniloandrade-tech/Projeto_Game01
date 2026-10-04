#include <iostream>
#include <string>
#include <vector>
using namespace std;

class JogoQuebraCabeca {
private:
    char tabuleiro[5][5];
    int linhaEspaco;
    int colunaEspaco;

public:
    // (a) Leitura - entrada e validações do enunciado
    void lerTabuleiro() {
        bool letrasUsadas[256] = {false}; // Para garantir caracteres sem repetição
        int contagemEspaco = 0;

        cout << "Digite as 5 linhas do tabuleiro (5 caracteres por linha, 'A' a 'X' e 1 espaco):\n";

        for (int i = 0; i < 5; i++) {
            string linha;
            bool linhaValida = false;

            while (!linhaValida) {
                cout << "Linha " << i + 1 << ": ";
                getline(cin, linha);

                // 1. Valida tamanho exato de 5 caracteres
                if (linha.length() != 5) {
                    cout << "ERRO: A linha deve ter exatamente 5 caracteres!\n";
                    continue;
                }

                bool erroCaractere = false;
                // Guarda estado temporário para caso precise cancelar a linha por erro
                bool tempUsadas[256];
                for(int k=0; k<256; k++) tempUsadas[k] = letrasUsadas[k];
                int tempEspaco = contagemEspaco;

                for (int j = 0; j < 5; j++) {
                    char c = linha[j];

                    // 2. Valida se é caractere permitido (' ' ou 'A' até 'X')
                    if (c != ' ' && (c < 'A' || c > 'X')) {
                        cout << "ERRO: Caractere invalido '" << c << "'. Use ' ' ou de 'A' a 'X'.\n";
                        erroCaractere = true;
                        break;
                    }

                    // 3. Valida duplicatas
                    if (tempUsadas[(unsigned char)c]) {
                        cout << "ERRO: O caractere '" << c << "' ja foi inserido no tabuleiro!\n";
                        erroCaractere = true;
                        break;
                    }

                    tempUsadas[(unsigned char)c] = true;
                    if (c == ' ') tempEspaco++;
                }

                if (erroCaractere) continue;

                // Se passou em todas as validações da linha, confirma a gravação na matriz
                for(int k=0; k<256; k++) letrasUsadas[k] = tempUsadas[k];
                contagemEspaco = tempEspaco;

                for (int j = 0; j < 5; j++) {
                    tabuleiro[i][j] = linha[j];
                    if (linha[j] == ' ') {
                        linhaEspaco = i;
                        colunaEspaco = j;
                    }
                }
                linhaValida = true;
            }
        }
    }

    // (b) Executa o movimento (8=Cima, 2=Baixo, 4=Esquerda, 6=Direita)
    bool moverEspaco(int direcao) {
        int novaLinha = linhaEspaco;
        int novaColuna = colunaEspaco;

        if (direcao == 8) novaLinha--;      // Cima
        else if (direcao == 2) novaLinha++; // Baixo
        else if (direcao == 4) novaColuna--; // Esquerda
        else if (direcao == 6) novaColuna++; // Direita
        else return false;

        // Verifica os limites da matriz 5x5
        if (novaLinha >= 0 && novaLinha < 5 && novaColuna >= 0 && novaColuna < 5) {
            tabuleiro[linhaEspaco][colunaEspaco] = tabuleiro[novaLinha][novaColuna];
            tabuleiro[novaLinha][novaColuna] = ' ';

            linhaEspaco = novaLinha;
            colunaEspaco = novaColuna;
            return true;
        }
        return false;
    }

    // (c) Imprime o tabuleiro no terminal
    void imprimirTabuleiro() const {
        cout << "\n---------------------\n";
        for (int i = 0; i < 5; i++) {
            cout << "| ";
            for (int j = 0; j < 5; j++) {
                cout << tabuleiro[i][j] << " | ";
            }
            cout << "\n---------------------\n";
        }
    }

    // (d) Retorna 1 se estiver ordenado ou 0 se não estiver
    int estaEmOrdem() const {
        char letraEsperada = 'A';

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 4 && j == 4) {
                    if (tabuleiro[i][j] != ' ') return 0;
                } else {
                    if (tabuleiro[i][j] != letraEsperada) return 0;
                    letraEsperada++;
                }
            }
        }
        return 1;
    }
};

// (e) Função principal
int main() {
    JogoQuebraCabeca jogo;
    jogo.lerTabuleiro();

    while (jogo.estaEmOrdem() != 1) {
        jogo.imprimirTabuleiro();

        int jogada;
        cout << "Digite o movimento (8=Cima, 2=Baixo, 4=Esq, 6=Dir): ";
        cin >> jogada;

        if (!jogo.moverEspaco(jogada)) {
            cout << "Movimento invalido! Tente novamente.\n";
        }
    }

    jogo.imprimirTabuleiro();
    cout << "VOCE VENCEU PARABENS!" << endl;
    return 0;
}
