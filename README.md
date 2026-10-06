<div align="center">

<img src="https://www.ufc.br/brasao-vertical.svg" alt="Brasão da Universidade Federal do Ceará" width="110">

# 💻 Ciência da Computação
### Repositório de estudos, exercícios e implementações da graduação

![Status](https://img.shields.io/badge/status-em%20progresso-yellow?style=for-the-badge)

</div>

---

## 📑 Sumário

1. [Visão geral](#-visão-geral)
2. [Estrutura do repositório](#-estrutura-do-repositório)
3. [Pré-requisitos](#-pré-requisitos)
4. [Como compilar e executar](#-como-compilar-e-executar)
5. [Módulo: Estrutura de Dados (C++)](#-módulo-estrutura-de-dados-c)
6. [Módulo: Programação Orientada a Objetos (Java)](#-módulo-programação-orientada-a-objetos-java)
7. [Módulo: Fundamentos de Banco de Dados (SQL)](#-módulo-fundamentos-de-banco-de-dados-sql)
8. [Convenções do projeto](#-convenções-do-projeto)
9. [Problemas conhecidos](#-problemas-conhecidos)
10. [Roadmap](#-roadmap)

---

## 👋 Visão geral

Este repositório reúne os estudos da graduação em Ciência da Computação (UFC): exercícios, implementações e pequenos projetos organizados **por disciplina**. Não é uma aplicação única, e sim uma coleção de atividades independentes, cada uma com seu código-fonte e, na maioria dos casos, um `README.md` com o enunciado.

| Módulo | Linguagem | Foco |
|---|---|---|
| [`estrutura-de-dados/`](./estrutura-de-dados) | C++17 | Recursão, TADs, ponteiros, listas sequenciais e encadeadas |
| [`programacao-orientada-a-objetos/`](./programacao-orientada-a-objetos) | Java | Classes, encapsulamento, associação, herança, abstração |
| [`fundamentos-banco-de-dados/`](./fundamentos-banco-de-dados) | SQL (PostgreSQL) | Junções, agregações, subconsultas |

---

## 🌳 Estrutura do repositório

```
computer-science/
├── README.md
├── .vscode/settings.json                  # tema do editor (GitHub Dark Dimmed)
│
├── estrutura-de-dados/                    # C++
│   ├── README.md
│   ├── 1 - Rápida Introdução ao C++/      # 7 exercícios (main.cpp + README)
│   ├── 2 - Recursividade Funções Recursivas/
│   │   ├── 01 … 06                        # 6 exercícios (06 dividido em fogo.cpp/.hpp)
│   │   └── exercicio_complementar/        # lista em PDF + q1–q8 e soma_positivos
│   ├── 3 - TAD - Tipos Abstratos de Dados/
│   │   ├── 01 - Círculo/                  # Point + Circle
│   │   └── 02 - Matriz/                   # Matrix (row-major)
│   ├── 4 - Lista Linear com Alocação Sequencial (Vector)/
│   │   ├── 01 - Implementando uma lista sequencial redimensionável/
│   │   ├── 02  - Iterator/                # exercícios com std::vector
│   │   └── 03 - Node/                     # primeira versão da ForwardList
│   ├── 5 - Ponteiros e Alocação Dinâmica /
│   │   └── exercicio_complementar/        # lista em PDF + q4.cpp
│   ├── 6 - Lista Simplesmente Encadeada/
│   │   └── ForwardList-5-out-2026/        # ForwardList.h + main.cpp
│   └── Atividas_pessoais/                 # Ordenar_Encontrar.cpp
│
├── programacao-orientada-a-objetos/       # Java
│   ├── README.md
│   ├── atividades/
│   │   ├── 01 - Classes e Objetos/        # 6 exercícios
│   │   ├── 02 - Encapsulamento/           # 4 exercícios
│   │   ├── 03 - Associação entre Classes/ # 5 exercícios
│   │   ├── 04 - Herança/                  # 2 exercícios
│   │   ├── 05 - Sobrescrita de Metodos/   # 3 sistemas
│   │   └── 06 - Classes Abstratas e Interfazes/  # 2 exercícios
│   └── praticaEquipe/
│       ├── Código/                        # Nave Artemis (5 arquivos .java)
│       └── Intruções PDF/                 # enunciados em PDF (3)
│
└── fundamentos-banco-de-dados/            # SQL
    └── atividades/
        ├── junções/                       # README + casa-do-dragao.sql
        ├── funções de agregação/          # README + empresa.sql
        └── Subconsultas/                  # PDF do enunciado + veterinario.sql
```

---

## 🧰 Pré-requisitos

| Ferramenta | Para quê | Verificar |
|---|---|---|
| `g++` com suporte a C++17 | Módulo de Estrutura de Dados | `g++ --version` |
| JDK (`javac` e `java`) | Módulo de POO | `javac -version` |
| PostgreSQL 12+ | Scripts SQL (`ILIKE` e a sintaxe dos scripts são do PostgreSQL) | `psql --version` |
| Git | Clonar o repositório | `git --version` |
| VS Code *(opcional)* | Editor usado no projeto | — |

---

## ▶️ Como compilar e executar

> Vários nomes de pasta têm **espaços e acentos**. Use sempre aspas ao entrar nelas.

### C++ (um arquivo)

```bash
cd "estrutura-de-dados/1 - Rápida Introdução ao C++/01 - Pintando a casa"
g++ -std=c++17 -Wall -Wextra main.cpp -o programa
./programa
```

### C++ (vários arquivos)

```bash
cd "estrutura-de-dados/3 - TAD - Tipos Abstratos de Dados/01 - Círculo"
g++ -std=c++17 -Wall -Wextra main.cpp Circle.cpp Point.cpp -o programa
./programa
```

Os módulos 4 (`Vector.h`) e 6 (`ForwardList.h`) são *header-only*: basta compilar o `main.cpp`.

### Java

```bash
cd "programacao-orientada-a-objetos/atividades/03 - Associação entre Classes/05 - Aluguel de carros"
javac *.java
java Exec
```

### SQL

```bash
createdb estudos
psql -d estudos -f "fundamentos-banco-de-dados/atividades/Subconsultas/veterinario.sql"
```

---

## 🌳 Módulo: Estrutura de Dados (C++)

Disciplina **QXD0010 — Estrutura de Dados**, UFC Campus Quixadá (2026.2), prof. Atílio Gomes Luiz. Cada pasta de exercício segue o padrão:

```
NN - Nome do exercício/
├── README.md   → enunciado (contexto, entrada e saída)
└── main.cpp    → solução
```

### 1. Rápida Introdução ao C++

| Exercício | Assunto |
|---|---|
| Pintando a casa | Área de triângulo (fórmula de Heron) |
| Criança, jovem, adulto | Condicionais por faixa etária |
| Fuga em helicóptero — OBI 2016 | Posições em pista circular |
| Pedra na lua | Comparação de lançamentos e pontuação |
| Quantos casais na arca | Vetores e formação de pares |
| Figurinhas repetidas | Vetores e contagem |
| Gomos da cobrinha | Simulação de movimento em plano 2D |

### 2. Recursividade

| Exercício | Assunto |
|---|---|
| De quantas maneiras podemos subir | Relação de recorrência |
| Contando caracteres recursivamente | Recursão em strings |
| Triângulo de Somas | Recursão em vetores |
| Operações básicas | Operações sem laços |
| Torres de Hanói | Recursão clássica |
| Queimada — Tocando fogo na floresta | *Flood fill* em matriz (4 direções); dividido em `main.cpp`, `fogo.cpp`, `fogo.hpp` |

A pasta `exercicio_complementar/` traz a lista de exercícios em PDF e as soluções `q1.cpp` a `q8.cpp` e `soma_positivos.cpp`, com uma `tasks.json` do VS Code para compilar.

### 3. TAD — Tipos Abstratos de Dados

| Exercício | Arquivos | O que implementa |
|---|---|---|
| Círculo | `Point.h/.cpp`, `Circle.h/.cpp`, `main.cpp` | `Circle` composto por um `Point` (centro) e um raio; interface separada da implementação |
| Matriz | `Matrix.h/.cpp`, `main.cpp` | Matriz 2D sobre vetor 1D dinâmico (*row-major*, ver `rowmajor.png`), com soma e multiplicação |

### 4. Lista Linear com Alocação Sequencial

**`01 - …/Vector.h`** — lista sequencial redimensionável de `int`:

| Categoria | Membros |
|---|---|
| Construção / destruição | `Vector()`, `Vector(cap)`, `Vector(const Vector&)`, `~Vector()` (`operator=` está `delete`d) |
| Capacidade | `size()`, `capacity()`, `empty()`, `reserve(newCap)` |
| Acesso | `at(i)`, `operator[]`, `front()`, `back()` (versões `const` incluídas) |
| Inserção | `push_back(val)`, `insert_at(elem, index)` |
| Remoção | `pop_back()`, `remove_at(index)`, `remove_all(elem)` |

Trade-offs estudados: acesso em O(1) e economia de memória (sem ponteiros) versus custo de deslocamento em inserções/remoções e de realocação quando a capacidade acaba.

**`02 - Iterator/`** — exercícios com `std::vector` e iteradores:

| Arquivo | Tarefa |
|---|---|
| `InserirOrdenadorEimprimir.cpp` | Inserir mantendo o vector ordenado (`insert`, `begin`, `size`) |
| `removeTodos.cpp` | Remover todas as ocorrências de `x` com `erase` |
| `rotacaodireita.cpp` | Rotação à direita em `k` posições |
| `Intercalacao.cpp` | Rotação à esquerda de duas formas (`push_back` + `erase` vs. `operator[]` + aritmética modular) |
| `matchingStrings.cpp` | Contar quantas vezes cada string de consulta aparece na lista de busca |

**`03 - Node/Fowardlist.h`** — primeira versão da lista encadeada (`Node`, `push_front`, `push_back`, destrutor).

### 5. Ponteiros e Alocação Dinâmica

Lista de exercícios em PDF; até agora está resolvida a questão 4 (`q4.cpp`): função `MAX` que recebe matriz `n×n` e devolve o maior elemento e sua posição por **ponteiros**.

### 6. Lista Simplesmente Encadeada

`ForwardList.h` implementa uma lista com **nó sentinela**:

| Operação | Complexidade |
|---|---|
| `push_front(value)` | O(1) |
| `push_back(value)` | O(n) |
| `pop_back()` | O(n) |
| `size()`, `print()` | O(1), O(n) |
| `~ForwardList()` | libera todos os nós |

### Atividades pessoais

`Atividas_pessoais/Ordenar_Encontrar.cpp`: *bubble sort* e busca binária (iterativa e recursiva).

---

## ☕ Módulo: Programação Orientada a Objetos (Java)

Cada exercício tem uma classe `Exec` com o `main`. Progressão dos conteúdos:

| Bloco | Exercícios | Conceitos |
|---|---|---|
| 01 — Classes e Objetos | Animal v1, Animal, Conta V1, Livro v1, Lâmpada, Toalha | Atributos, métodos, construtores, `this`, `toString()`, `final` |
| 02 — Encapsulamento | Lâmpada, Toalha, Robô simples, Conta Bancária (Encapsulados) | `private`, getters/setters, regras de negócio |
| 03 — Associação | Conta Bancária × Correntista, Motoca × Pessoa, Feira do Leite, Jogo da Colheita, Aluguel de carros | Objetos que referenciam objetos; atributos/métodos `static` |
| 04 — Herança | Locadora com herança (`Veiculo` → `Carro`, `Moto`); Shapes (`Forma` → `Circulo`, `Quadrado`, `Retangulo`) | `extends`, `super` |
| 05 — Sobrescrita | Sistema de entregas (`Entrega` → `EntregaEconomica`, `EntregaExpressa`); Sistema de veículos; Sistema hospitalar (`Pessoa` → `Medico`, `Paciente`; `Hospital`) | `@Override`, regras específicas por subclasse |
| 06 — Abstração | Figuras geométricas (`Figura`, interface `Desenhavel`, `Circulo`, `Retangulo`); Recursos naturais (`Recurso` abstrata → `Combustivel`, `Madeira`, `Metal`) | Classes abstratas e interfaces |

### 🚀 Prática em equipe — Nave Artemis

Simulação dos sistemas de uma nave, desenvolvida em grupo. Cada integrante implementou uma classe a partir de um PDF de instruções (`Intruções PDF/`).

| Classe | Responsabilidade |
|---|---|
| `TanqueCombustivel` | Tipo e volume de combustível, `injetarCombustivel`, `consumir`, `verificarVazamento` |
| `MotorPropulsao` | Potência, `acelerar` (consome do tanque), superaquecimento e resfriamento de emergência |
| `CanhaoLaser` | Carga e prontidão, `carregarArma` (usa o tanque), `atirar` (usa o motor; sobrecarga com quantidade), `desarmar` |
| `NaveArtemisMain` / `Exec` | Bateria de testes de cada classe (`testarTanqueCombustivel`, `testarMotorPropulsao`, `testarCanhaoLaser`) e um terminal interativo da nave (`iniciarTerminalDaNave`); o lançamento é abortado se algum teste falhar |

---

## 🗄️ Módulo: Fundamentos de Banco de Dados (SQL)

| Atividade | Arquivos | Conceitos |
|---|---|---|
| **Junções** | `README.md`, `casa-do-dragao.sql` | `LEFT JOIN`, `IS NULL`, junção de várias tabelas, `JOIN … ON … OR`, `DISTINCT`, `IN`, intervalo de datas, `ILIKE`, aliases, autojunção, `UNION` / `INTERSECT` / `EXCEPT` |
| **Funções de agregação** | `README.md`, `empresa.sql` | `COUNT`, `SUM`, `AVG`, `MAX`, `MIN`, `COUNT(DISTINCT)`, `GROUP BY`, `HAVING`, diferença entre `WHERE` e `HAVING` |
| **Subconsultas** | PDF do enunciado, `veterinario.sql` | SQL avançado sobre o esquema de uma clínica veterinária |

**Esquemas:**

- **Casa do Dragão** — `PERSONAGENS`, `DRAGOES`, `BATALHAS`, `PARTICIPANTES_BATALHAS`, `RELACOES_FAMILIARES`.
- **Empresa** — esquema clássico Company (`departamento`, `dependente`, `funcionario`, …), exportado com `pg_dump` 16.3.
- **Clínica veterinária** — `Tutor`, `Animal`, `Consulta`, `Procedimento`, `ConsultaProcedimento`. O script já faz `DROP`, `CREATE` e `INSERT`, então pode ser reexecutado do zero.

---

## 📐 Convenções do projeto

- **Idioma:** nomes de pastas, enunciados e comentários em português.
- **Numeração:** pastas prefixadas (`01 - …`, `2 - …`) na ordem em que o conteúdo foi visto.
- **C++:** interface em `.h`/`.hpp`, implementação em `.cpp`; dados em `private`; complexidade anotada nos comentários das funções.
- **Java:** uma classe por arquivo, `Exec` como ponto de entrada de cada exercício.
- **Versões `v1` / sem sufixo:** o mesmo problema revisitado (ex.: `Animal v1` → `Animal`).

---

## ⚠️ Problemas conhecidos

Itens encontrados ao revisar o repositório para esta documentação:

1. **`ForwardList::pop_back()` (módulo 6)** — dentro do `while`, `current = m_head->next;` nunca avança além do primeiro nó; com 3 ou mais elementos o laço não termina. Deveria ser `current = current->next;`.
2. **`praticaEquipe/Código/Exec.java`** declara `public class NaveArtemisMain`, igual ao `NaveArtemisMain.java` (os dois têm praticamente o mesmo conteúdo). O Java exige que a classe pública tenha o nome do arquivo, então `javac *.java` falha nessa pasta. Remover ou renomear um dos dois.
3. **Nomes de pasta com erro de digitação:** `Atividas_pessoais`, `Intruções PDF`, `Classes Abstratas e Interfazes`, `Fowardlist.h`. Renomear exige atualizar os links dos READMEs.
4. **Pasta `5 - Ponteiros e Alocação Dinâmica /`** termina com espaço, o que atrapalha o `cd` e alguns sistemas de arquivos.
5. **README raiz anterior desatualizado:** a árvore citava `código_atividades/` e pastas de POO que não existem mais (a estrutura atual usa `atividades/`).
6. **READMEs dos módulos incompletos:** o de POO cobre só os blocos 01–04, e o de Estrutura de Dados só os módulos 1–4; os blocos 05 e 06 de POO e os módulos 5 e 6 de ED não aparecem lá.
7. **`git clone https://github.com/seu-usuario/seu-repositorio.git`** nos READMEs dos módulos é um placeholder; troque pela URL real.

---

## 🗺️ Roadmap

- [ ] Corrigir os problemas acima
- [ ] Completar o módulo 5 (ponteiros): demais questões da lista
- [ ] ForwardList: `pop_front`, `insert`, `remove`, iteradores e *rule of three*
- [ ] Listas duplamente encadeadas, pilhas, filas e árvores binárias de busca
- [ ] Algoritmos de ordenação (Selection, Insertion, Merge e Quick Sort)
- [ ] POO: `ArrayList`, polimorfismo com listas de `Forma`/`Veiculo`, exceções, JUnit
- [ ] SQL: documentar a atividade de subconsultas e adicionar diagramas ER

---

<div align="center">

📫 Aberto a conversas sobre código, dados ou ensino — sinta-se à vontade para abrir uma *issue* ou entrar em contato.

</div>
