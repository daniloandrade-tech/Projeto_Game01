# Projeto Game01: Quebra-cabeça

### Parte 1 — Quebra-cabeça em C++

O quebra-cabeça abaixo foi popular entre crianças nascidas na década de 80. 
<img width="535" height="234" alt="image" src="https://github.com/user-attachments/assets/862d68e5-5c9a-4c13-a6b9-002eb1a53c44" />


**Objetivo:** Posicionar as letras em ordem alfabética.

Note que existe **um único espaço** que não possui letra alguma. Uma letra pode ser movida para o espaço se, e somente se, o espaço estiver:
* Imediatamente à direita;
* Imediatamente à esquerda;
* Imediatamente acima; ou
* Imediatamente abaixo.

---

### Questões do Quebra-cabeça

#### a) Leitura do Tabuleiro
Faça uma função que leia do teclado 5 *strings* passadas por parâmetro pelo utilizador. 

Cada *string* passada **deve**:
* Representar uma linha da matriz do quebra-cabeça;
* Possuir, exatamente, 5 caracteres;
* Possuir o caractere espaço ou caracteres entre 'A' e 'X';
* Possuir somente caracteres que **ainda não** se encontram na matriz.

#### b) Movimentação de Peças
Faça uma função que receba um inteiro como parâmetro. O tratamento do parâmetro passado **deve** ser:
* **8:** A função deve trocar o elemento espaço com o elemento imediatamente **acima** do espaço.
* **2:** A função deve trocar o elemento espaço com o elemento imediatamente **abaixo** do espaço.
* **4:** A função deve trocar o elemento espaço com o elemento imediatamente à **esquerda** do espaço.
* **6:** A função deve trocar o elemento espaço com o elemento imediatamente à **direita** do espaço.

#### c) Impressão do Tabuleiro
Faça uma função para imprimir o tabuleiro.

#### d) Validação da Vitória
Faça uma função que retorne:
* **1:** Se o tabuleiro estiver em ordem alfabética; ou
* **0:** Se o tabuleiro **não** estiver em ordem alfabética.

> **Nota:** Para verificar se o tabuleiro está em ordem alfabética, utilize o comando `for`.

#### e) Função Principal (`main`)
Crie a função principal, que **deve**:
1. Chamada inicial da função criada no item **(a)** para a leitura do tabuleiro.
2. Solicitar ao utilizador uma jogada (`8`, `2`, `4` ou `6`) e passar esse valor como parâmetro para a função criada no item **(b)**.
3. Após **cada** jogada, o tabuleiro deve ser impresso utilizando a função criada no item **(c)**.
4. O programa deve continuar a solicitar jogadas até que a função criada no item **(d)** retorne `1`.

#### f) Teste de Mesa
Faça o Teste de Mesa testando **todas** as possibilidades pedidas no exercício.
