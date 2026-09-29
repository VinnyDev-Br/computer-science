# ☕ Atividades de Programação Orientada a Objetos (POO em Java)

Coleção de exercícios desenvolvidos durante os estudos de **Programação Orientada a Objetos** em **Java**, com o objetivo de praticar, de forma progressiva, os principais pilares da POO.

Os exercícios estão organizados por conteúdo, do mais básico (classes e objetos) até herança, e cada um possui uma classe `Exec` com o método `main` para executar e testar o programa.

---

## 📚 Conceitos praticados

Durante a resolução das atividades foram aplicados os seguintes conceitos:

- Classes e Objetos
- Atributos e Métodos
- Construtores (com sobrecarga)
- Palavra-chave `this`
- Método `toString()`
- Encapsulamento
- Atributos privados (`private`)
- Getters e Setters
- Associação entre classes
- Atributos e métodos estáticos (`static`)
- Classes `final` e construtor privado
- Herança (`extends`)
- Chamada ao construtor da superclasse (`super`)
- Sobrescrita de métodos (`@Override`)
- Entrada de dados com `Scanner`

---

## 🗂️ Conteúdos e exercícios

### 1️⃣ Classes e Objetos

Primeiro contato com a criação de classes, atributos, métodos e objetos.

| Nº | Exercício | Foco |
|----|-----------|------|
| 01 | Animal v1 | Classe simples com atributos e `toString()` |
| 02 | Animal | Evolução do exercício anterior com mais comportamentos |
| 03 | Conta V1 | Operações básicas de uma conta |
| 04 | Livro v1 | Modelagem de um livro e uso de constantes (`final`) |
| 05 | Lâmpada | Controle de estado de um objeto |
| 06 | Toalha | Objeto com estado e regras de negócio |

---

### 2️⃣ Encapsulamento

Os mesmos tipos de problema, agora protegendo os atributos com `private` e expondo o acesso por meio de métodos.

| Nº | Exercício | Foco |
|----|-----------|------|
| 01 | Lâmpada Encapsulada | Atributos privados e getters |
| 02 | Toalha Encapsulada | Versão encapsulada do exercício da toalha |
| 03 | Robô simples | Múltiplos construtores e movimentação por direção |
| 04 | Conta Bancária Encapsulada | Getters, setters e regras de saque/depósito |

---

### 3️⃣ Associação entre Classes

Exercícios em que um objeto guarda referência para outro objeto.

| Nº | Exercício | Foco |
|----|-----------|------|
| 01 | Conta Bancária | `ContaBancaria` associada a um `Correntista` |
| 02 | Crianças Andando de Motoca | `Motoca` que recebe e remove uma `Pessoa` |
| 03 | Feira do Leite | Relação entre produtos, empresas participantes e avaliador |
| 04 | Jogo da Colheita | `Fazendeiro` que colhe e vende objetos `Item` |
| 05 | Aluguel de carros | `Carro` alugado por uma `Pessoa`, com contador estático na `Locadora` |

---

### 4️⃣ Herança

Reaproveitamento de código com superclasses e subclasses.

| Nº | Exercício | Foco |
|----|-----------|------|
| 01 | Locadora com herança | `Carro` e `Moto` herdam de `Veiculo` |
| 02 | Shapes com herança | `Circulo`, `Quadrado` e `Retangulo` herdam de `Forma` |

---

## 🧠 Conceitos de POO utilizados

### Encapsulamento

Os atributos são declarados como `private` e acessados apenas por métodos da própria classe.

```java
private Correntista correntista;
private double saldo;
private boolean contaEhEspecial;
```

O acesso externo é feito por getters:

```java
public double getSaldo(){
    return this.saldo;
}
```

---

### Associação entre Classes

Um objeto pode possuir outro objeto como atributo. Na `Motoca`, por exemplo, a pessoa que está na moto é uma referência para um objeto `Pessoa`:

```java
public class Motoca{
    int potencia;
    int time;
    Pessoa pessoa;
    ...
}
```

Esse relacionamento aparece também em `ContaBancaria` → `Correntista`, `Carro` → `Pessoa` e `Fazendeiro` → `Item`.

---

### Atributos e Métodos Estáticos

No exercício **Aluguel de carros**, a classe `Locadora` é `final`, possui construtor privado e mantém um contador compartilhado por todos os carros:

```java
public final class Locadora{
    public static int totalCarrosAlugados = 0;

    private Locadora(){ }

    public static void registrarAluguel(){
        totalCarrosAlugados++;
    }
}
```

---

### Herança

As subclasses herdam atributos e métodos da superclasse e podem reaproveitar seu construtor com `super`:

```java
public class Moto extends Veiculo{

    public Moto(String placa){
        super(placa);
    }
    ...
}
```

---

### Sobrescrita de Métodos

Uma subclasse pode alterar o comportamento herdado. Na `Moto`, o aluguel possui uma regra própria de idade (entre 18 e 50 anos):

```java
@Override
public boolean alugar(String nome, int idade){
    if (idade < 18 || idade > 50) { return false; }
    ...
}
```

No exercício de formas geométricas, cada subclasse calcula sua própria área e perímetro, e a superclasse `Forma` centraliza a exibição por meio do `toString()`.

---

## ▶️ Como executar

Clone o repositório:

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
```

Acesse a pasta do exercício desejado:

```bash
cd "nome-da-pasta-do-exercicio"
```

Compile todas as classes e execute a classe `Exec`:

```bash
javac *.java
java Exec
```

> É necessário ter o **JDK** instalado. Para conferir, use `java -version` e `javac -version`.

---

## 📌 Melhorias futuras

Algumas melhorias que podem ser implementadas:

- Trocar os atributos `v1`, `v2` e `v3` por listas (`ArrayList`)
- Encapsular os exercícios que ainda usam atributos sem `private`
- Aplicar polimorfismo com vetores/listas de `Forma` e `Veiculo`
- Classes abstratas e interfaces
- Tratamento de exceções para entradas inválidas
- Testes automatizados com JUnit
- Menu interativo no terminal

---

## 🎓 Aprendizados

Estas atividades foram desenvolvidas como parte dos estudos em **Programação Orientada a Objetos com Java**, permitindo praticar a modelagem de classes, o encapsulamento, a associação entre objetos, o uso de membros estáticos e a herança com sobrescrita de métodos.

---

## 👨‍💻 Autor

**Vinicius**

---

> Projeto desenvolvido para fins de estudo em **Java e Programação Orientada a Objetos**.
