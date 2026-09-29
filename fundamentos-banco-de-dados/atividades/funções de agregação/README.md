# 📊 Atividade de SQL: Funções de Agregação, GROUP BY e HAVING

Atividade desenvolvida durante a disciplina de **Banco de Dados** com o objetivo de praticar consultas SQL que **resumem e agrupam dados**, indo além do simples `SELECT`.

As consultas utilizam as tabelas `customers` e `products` (exemplos de vendas) e o esquema clássico **Company** (`FUNCIONARIO` e `DEPARTAMENTO`).

---

## 📚 Novos conceitos praticados

Nesta atividade foram aplicados os seguintes conceitos de SQL:

- Funções de agregação (`COUNT`, `SUM`, `AVG`, `MAX`, `MIN`)
- `COUNT(DISTINCT ...)`
- `COUNT(*)`
- Junção de tabelas (`JOIN ... ON`)
- Apelidos de tabelas (aliases)
- Agrupamento de dados (`GROUP BY`)
- Filtro sobre grupos (`HAVING`)
- Filtro sobre linhas (`WHERE`)
- Diferença entre `WHERE` e `HAVING`

---

## 🧠 Funcionalidade

### `COUNT()`

Conta quantas linhas existem no resultado.

- `COUNT(*)` conta todas as linhas.
- `COUNT(coluna)` conta apenas as linhas em que a coluna não é nula.

```sql
SELECT COUNT(*) FROM FUNCIONARIO;
```

---

### `COUNT(DISTINCT ...)`

Conta apenas os valores **diferentes** de uma coluna, ignorando repetições.

```sql
SELECT COUNT(DISTINCT city) FROM customers;
```

---

### `SUM()`, `AVG()`, `MAX()` e `MIN()`

Funções de agregação que transformam várias linhas em um único valor:

| Função  | O que faz                     |
|---------|-------------------------------|
| `SUM()` | Soma os valores de uma coluna |
| `AVG()` | Calcula a média               |
| `MAX()` | Retorna o maior valor         |
| `MIN()` | Retorna o menor valor         |

---

### `JOIN`

Combina linhas de duas tabelas a partir de uma coluna em comum. Aqui, o funcionário é ligado ao seu departamento por meio de `f.Dnr = d.Dnumero`.

---

### `GROUP BY`

Agrupa as linhas que possuem o mesmo valor em uma coluna, permitindo aplicar as funções de agregação **a cada grupo** (por exemplo, por departamento).

---

### `HAVING`

Filtra os **grupos** depois de eles serem formados. É usado quando a condição envolve uma função de agregação, como `AVG(salario) > 30000`.

---

### `WHERE` vs `HAVING`

| Comando  | Quando age                          | Filtra                        |
|----------|-------------------------------------|-------------------------------|
| `WHERE`  | **Antes** do agrupamento            | Linhas individuais            |
| `HAVING` | **Depois** do agrupamento           | Grupos (resultado agregado)   |

---

## 📝 Questões e consultas

### Questão 1

**Quantas cidades diferentes existem na tabela de clientes?**

```sql
SELECT COUNT(DISTINCT city)
FROM customers;
```

📌 Conta as cidades sem repetir, mesmo que vários clientes morem na mesma cidade.

---

### Questão 2

**Qual é o preço médio dos produtos?**

```sql
SELECT AVG(price)
FROM products;
```

📌 Calcula a média da coluna `price` de todos os produtos.

---

### Questão 3

**Quantos funcionários existem na empresa?**

```sql
SELECT COUNT(*)
FROM FUNCIONARIO;
```

📌 Retorna o total de linhas da tabela `FUNCIONARIO`.

---

### Questão 4

**Qual é a soma, o maior, o menor e a média dos salários dos funcionários?**

```sql
SELECT SUM(salario), MAX(salario), MIN(salario), AVG(salario)
FROM FUNCIONARIO;
```

📌 Usa quatro funções de agregação em uma única consulta.

---

### Questão 5

**Quantos funcionários trabalham no departamento de número 5?**

```sql
SELECT COUNT(*)
FROM FUNCIONARIO f
JOIN DEPARTAMENTO d ON d.Dnumero = f.Dnr
WHERE d.Dnumero = 5;
```

📌 Junta funcionários e departamentos, filtra o departamento 5 com `WHERE` e conta os resultados.

---

### Questão 6

**Para cada departamento cuja média salarial é maior que 30.000, qual é o nome do departamento e o número de funcionários?**

```sql
SELECT d.Dnome, COUNT(*)
FROM DEPARTAMENTO d
JOIN FUNCIONARIO f ON f.Dnr = d.Dnumero
GROUP BY d.Dnome
HAVING AVG(f.salario) > 30000;
```

📌 Agrupa por departamento e usa `HAVING` para manter apenas os grupos com média salarial acima de 30.000. O `COUNT(*)` conta todos os funcionários do departamento.

---

### Questão 7

**Para cada departamento, qual é o nome e o número de funcionários do sexo masculino que ganham mais de 30.000?**

```sql
SELECT d.Dnome, COUNT(*)
FROM FUNCIONARIO f
JOIN DEPARTAMENTO d ON d.Dnumero = f.Dnr
WHERE f.salario > 30000 AND f.sexo = 'M'
GROUP BY d.Dnome;
```

📌 Aqui o `WHERE` filtra os funcionários **antes** do agrupamento. Só depois os que sobraram são contados por departamento.

---

## ⚙️ Funcionalidades praticadas

- ✅ Contagem de registros
- ✅ Contagem de valores distintos
- ✅ Cálculo de soma, média, maior e menor valor
- ✅ Junção entre tabelas
- ✅ Agrupamento de dados por categoria
- ✅ Filtro de linhas com `WHERE`
- ✅ Filtro de grupos com `HAVING`

---

## ▶️ Como executar

1. Crie o banco de dados e as tabelas do esquema **Company** no seu SGBD (por exemplo, PostgreSQL com o pgAdmin).
2. Abra o **Query Tool**.
3. Cole a consulta desejada e execute.

---


## 🎓 Aprendizados

Esta atividade permitiu entender como o SQL vai além de buscar dados: com **funções de agregação**, **GROUP BY** e **HAVING** é possível resumir grandes volumes de informação em respostas objetivas, além de compreender a diferença entre filtrar **linhas** (`WHERE`) e filtrar **grupos** (`HAVING`).

---

## 👨‍💻 Autor

**Vinicius**

---

> Atividade desenvolvida para fins de estudo na disciplina de **QXD QXD0011 Fundamentos Banco de Dados** UFC Campus Quixadá, 2026.2..