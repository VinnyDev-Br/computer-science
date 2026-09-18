<div align="center">

<img src="https://www.ufc.br/brasao-vertical.svg" alt="Brasão da Universidade Federal do Ceará" width="110">

# 💻 Ciência da Computação
### Repositório de estudos, exercícios e implementações da graduação


![Status](https://img.shields.io/badge/status-em%20progresso-yellow?style=for-the-badge)

*"Todo especialista já foi, um dia, um iniciante que não desistiu."*

</div>

---

## 👋 Sobre

Este repositório reúne os estudos da minha graduação em Ciência da Computação: exercícios, implementações e pequenos projetos organizados por disciplina, cobrindo desde estrutura de dados e recursão em C++ até programação orientada a objetos em Java. Cada pasta representa um exercício resolvido, com seu próprio README explicando o contexto, a entrada/saída esperada e, quando aplicável, os casos de teste.

## 🧭 Navegação rápida

| Módulo | Linguagem | Conceitos-chave |
|---|---|---|
| [`estrutura-de-dados/`](./estrutura-de-dados) | C++ | Recursão, complexidade, ponteiros, TADs 
| [`programacao-orientada-a-objetos/`](./programacao-orientada-a-objetos) | Java | Encapsulamento, classes, atributos estáticos 
| [`fundamentos-banco-de-dados/`](./fundamentos-banco-de-dados/) | SQL | Modelagem, DDL, consultas |
## 🌳 Estrutura completa do projeto

<details>
<summary><strong>Clique para expandir a árvore de diretórios</strong> 🗂️</summary>

```
# Arvore do diretorio em andamento
```

</details>

## 🔍 Destaques técnicos

Alguns exercícios que valem uma olhada mais de perto:

- **[`Queimada - Tocando fogo na floresta`](<./estrutura-de-dados/código_atividades/Tópico%2002.%20Recursividade%20Funções%20Recursivas/06%20-%20Queimada%20-%20Tocando%20fogo%20na%20floresta>)** — flood fill recursivo em matriz de caracteres, o mesmo algoritmo por trás do "balde de tinta" de editores de imagem.
- **[`Torres de Hanói`](<./estrutura-de-dados/código_atividades/Tópico%2002.%20Recursividade%20Funções%20Recursivas/05%20-%20Torres%20de%20Hanói>)** — recursão clássica, resolvida do zero.
- **[`TAD Círculo`](<./estrutura-de-dados/código_atividades/Tópico%2005.%20TAD%20-%20Tipos%20Abstratos%20de%20Dados/01%20-%20Círculo>)** — TAD `Circle` composto por outro TAD (`Point`), com gerência manual de memória em C++.
- **[`TAD Matriz`](<./estrutura-de-dados/código_atividades/Tópico%2005.%20TAD%20-%20Tipos%20Abstratos%20de%20Dados/02%20-%20Matriz>)** — matriz 2D implementada sobre um vetor 1D alocado dinamicamente (row-major), com soma e multiplicação de matrizes.
- **[`Conta Bancária` → `Conta Bancária Encapsulada`](./programacao-orientada-a-objetos)** — o mesmo domínio revisitado para mostrar, na prática, o antes e o depois de aplicar encapsulamento em Java.
- **[`Aluguel de carros`](./programacao-orientada-a-objetos/Aluguel%20de%20carros)** — quatro classes colaborando (`Carro`, `Pessoa`, `Locadora`, `Exec`) com contador estático de carros alugados.

## 🛠️ Tecnologias

<div>

[![Java](https://img.shields.io/badge/Java-ED8B00?style=flat-square&logo=openjdk&logoColor=white)](https://www.java.com/)
[![C++](https://img.shields.io/badge/C++17-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![SQL](https://img.shields.io/badge/SQL-4479A1?style=flat-square&logo=postgresql&logoColor=white)](https://www.postgresql.org/)
[![Git](https://img.shields.io/badge/Git-F05032?style=flat-square&logo=git&logoColor=white)](https://git-scm.com/)
[![VS Code](https://img.shields.io/badge/VS%20Code-007ACC?style=flat-square&logo=visualstudiocode&logoColor=white)](https://code.visualstudio.com/)

</div>

## 🎯 Objetivo do repositório

Consolidar, na prática, os fundamentos de Ciência da Computação — e ao mesmo tempo servir de portfólio: cada pasta reflete um conceito dominado, do "por quê" ao código funcionando, com testes de entrada e saída documentados nos próprios READMEs dos exercícios.

## 📖 Como navegar

Cada exercício tem seu próprio `README.md` com contexto, entrada/saída esperada e, quando aplicável, casos de teste. Para compilar os exemplos em C++:

```bash
g++ -std=c++17 main.cpp -o programa && ./programa
```

Para rodar os exemplos em Java:

```bash
javac Exec.java && java Exec
```

---

<div align="center">

📫 Aberto a conversas sobre código, dados ou ensino — sinta-se à vontade para abrir uma *issue* ou entrar em contato.

</div>
