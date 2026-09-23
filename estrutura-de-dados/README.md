# 🌳 Estrutura de Dados (QXD0010) — C++

Repositório de estudos da disciplina **Estrutura de Dados**, cursada na **Universidade Federal do Ceará (UFC) — Campus Quixadá**, no **2º semestre de 2026**, com o professor **Atílio Gomes Luiz**.

O objetivo do projeto é reunir, de forma organizada, os exercícios e implementações feitos ao longo da disciplina, separados por assunto, para praticar as principais **estruturas de dados** e **algoritmos** utilizando **C++**.

---

## 📚 Conceitos praticados

Durante a disciplina são trabalhados, entre outros, os seguintes conceitos:

- Revisão de C++: entrada e saída, condicionais, laços, vetores e strings
- Arrays, Structs e Ponteiros
- Alocação dinâmica de memória
- Recursão
- Tipos Abstratos de Dados (TAD)
- Classes e Objetos
- Encapsulamento (`private` / `public`)
- Separação em arquivos de cabeçalho (`.h` / `.hpp`) e implementação (`.cpp`)
- Listas sequenciais (Vector)
- Noções de complexidade de algoritmos
- Listas encadeadas, pilhas, filas, árvores e ordenação *(conteúdos futuros)*

---

### Organização de cada exercício

Em geral, cada pasta de exercício contém:

```text
01 - Nome do exercício/
├── README.md    → enunciado do problema (contexto, entrada e saída)
└── main.cpp     → solução em C++
```

Nos exercícios maiores, o código é dividido em vários arquivos (por exemplo `Circle.h`, `Circle.cpp`, `Point.h`, `Point.cpp`).

---

## 🗂️ Módulos

### 1️⃣ Rápida Introdução ao C++

Revisão dos fundamentos de programação em C++, com problemas curtos de lógica, condicionais, laços e vetores.

| Exercício | Assunto |
|---|---|
| Pintando a casa | Cálculo da área de um triângulo (Fórmula de Heron) |
| Criança, jovem, adulto | Classificação por faixa de idade (condicionais) |
| Fuga em helicóptero — OBI 2016 | Posições em uma pista circular |
| Pedra na lua | Comparação de lançamentos e pontuação |
| Quantos casais na arca | Vetores e formação de pares |
| Figurinhas repetidas | Vetores e contagem de elementos |
| Gomos da cobrinha | Simulação de movimento em um plano 2D |

---

### 2️⃣ Recursividade — Funções Recursivas

Exercícios para praticar o raciocínio recursivo: caso base, chamada recursiva e decomposição em subproblemas.

| Exercício | Assunto |
|---|---|
| De quantas maneiras podemos subir | Contagem de possibilidades (relação de recorrência) |
| Contando caracteres recursivamente | Recursão em strings |
| Triângulo de Somas | Recursão em vetores |
| Operações básicas | Operações sobre vetor sem uso de laços |
| Torres de Hanói | Clássico problema recursivo |
| Queimada — Tocando fogo na floresta | Recursão em matrizes (propagação nas 4 direções) |

O exercício da **Queimada** já é dividido em arquivos: `main.cpp`, `fogo.cpp` e `fogo.hpp`.

---

### 3️⃣ TAD — Tipos Abstratos de Dados

Introdução a classes e objetos, com separação entre **interface** (`.h`) e **implementação** (`.cpp`).

| Exercício | Arquivos | Assunto |
|---|---|---|
| Círculo | `Circle.h`, `Circle.cpp`, `Point.h`, `Point.cpp`, `main.cpp` | TAD `Circle` composto por um `Point` (centro) e um raio |
| Matriz | `Matrix.h`, `Matrix.cpp`, `main.cpp` | TAD `Matrix` com armazenamento em ordem de linha (*row-major*) |

---

### 4️⃣ Lista Linear com Alocação Sequencial (Vector)

Implementação de uma **lista sequencial redimensionável**, com os dados armazenados em posições contíguas de memória e encapsulados na classe `Vector`.

Pontos estudados:

- **Vantagens:** economia de memória e acesso em tempo constante a um elemento
- **Desvantagens:** custo de inserção/remoção (deslocamento de elementos) e de realocação quando a lista cresce

Este módulo possui um `README.md` próprio com a explicação teórica.

---

## 💻 Como compilar e executar

Para exercícios com um único arquivo:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o programa
./programa
```

Para exercícios divididos em vários arquivos (exemplo: Círculo):

```bash
g++ -std=c++17 -Wall -Wextra main.cpp Circle.cpp Point.cpp -o programa
./programa
```

Clone o repositório e acesse a pasta do exercício desejado:

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
cd "seu-repositorio/estrutura-de-dados/1 - Rápida Introdução ao C++/01 - Pintando a casa"
```

---

## 🧠 Conceitos de C++ utilizados

### Separação em arquivos

O código de um TAD é dividido entre o cabeçalho, que declara a interface, e o arquivo de implementação:

```cpp
// Circle.h
class Circle {
private:
    Point center;
    double radius;
public:
    double area() const;
};
```

### Encapsulamento

Os dados internos ficam em `private`, e apenas as funções declaradas em `public` são visíveis para quem usa a classe. Assim, é possível mudar a implementação sem alterar os programas que a utilizam.

### Recursão

Toda função recursiva é composta por um **caso base** e uma **chamada recursiva** que aproxima o problema do caso base.

---

## 📌 Próximos passos

Conteúdos que ainda serão adicionados ao repositório conforme a disciplina avança:

- Listas simplesmente encadeadas
- Listas duplamente encadeadas
- Pilhas
- Filas
- Árvores binárias de busca
- Algoritmos de ordenação (Bubble, Selection, Insertion, Mergesort e Quicksort)

---

## 🎓 Aprendizados

Este repositório faz parte dos estudos em **Estrutura de Dados com C++**, permitindo praticar recursão, tipos abstratos de dados, encapsulamento e implementação de estruturas dinâmicas, sempre com atenção à eficiência e à organização do código.

---

## 👨‍💻 Autor

**Vinicius**

---

> Projeto desenvolvido para fins de estudo na disciplina **QXD0010 — Estrutura de Dados**, UFC Campus Quixadá, 2026.2.
