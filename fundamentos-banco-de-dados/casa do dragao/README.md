# 🐉 Atividade de SQL: Junções, Filtros de Texto e Operadores de Conjunto

Atividade desenvolvida durante a disciplina de **Fundamentos Banco de Dados** com o objetivo de praticar consultas SQL que **relacionam várias tabelas** e **combinam resultados de consultas**.

O banco de dados representa um universo de fantasia com personagens, dragões, batalhas e relações familiares.

---

## 🗂️ Tabelas utilizadas

| Tabela                   | O que armazena                                          |
|--------------------------|---------------------------------------------------------|
| `PERSONAGENS`            | Nome e casa de cada personagem                          |
| `DRAGOES`                | Nome do dragão e o personagem dono (`id_personagem`)    |
| `BATALHAS`               | Nome e data de cada batalha                             |
| `PARTICIPANTES_BATALHAS` | Quem participou de cada batalha e o resultado           |
| `RELACOES_FAMILIARES`    | Relação entre dois personagens (`id_personagem1` e `2`) |

---

## 📚 Novos conceitos praticados

- `LEFT JOIN`
- Encontrar registros sem correspondência (`IS NULL`)
- `JOIN` com várias tabelas
- `JOIN` com condição `OR`
- `SELECT DISTINCT`
- Operador `IN`
- Filtro por intervalo de datas
- Busca por padrão de texto (`ILIKE` com `%`)
- Apelidos de colunas (`AS`)
- Autojunção (a mesma tabela usada duas vezes)
- Operadores de conjunto: `UNION`, `INTERSECT` e `EXCEPT`

---

## 🧠 Para que serve cada novidade

### `LEFT JOIN`

Retorna **todas** as linhas da tabela da esquerda, mesmo quando não existe correspondência na tabela da direita. Nesses casos, as colunas da direita vêm como `NULL`.

Diferença para o `JOIN` comum (`INNER JOIN`), que só traz as linhas com correspondência nas duas tabelas.

---

### `LEFT JOIN` + `IS NULL`

Combinação usada para encontrar quem **não tem** algo, como personagens sem dragão:

```sql
LEFT JOIN DRAGOES d ON p.id = d.id_personagem
WHERE d.id IS NULL
```

---

### `DISTINCT`

Remove linhas repetidas do resultado. É útil quando o `JOIN` faz o mesmo personagem aparecer várias vezes.

---

### `IN`

Verifica se um valor está dentro de uma lista, substituindo vários `OR`:

```sql
WHERE rf.relacao IN ('Mãe', 'Filha')
```

---

### `LIKE` / `ILIKE`

Busca por padrão de texto. O símbolo `%` representa "qualquer sequência de caracteres".

| Padrão   | Significado                  |
|----------|------------------------------|
| `'s%'`   | Começa com "s"               |
| `'%r'`   | Termina com "r"              |
| `'%mãe%'`| Contém "mãe"                 |

O `ILIKE` (PostgreSQL) funciona como o `LIKE`, mas **ignora maiúsculas e minúsculas**.

---

### Autojunção

Usar a mesma tabela duas vezes na consulta, com apelidos diferentes (`p1` e `p2`), para relacionar duas linhas dela, como dois personagens parentes.

---

### `UNION`, `INTERSECT` e `EXCEPT`

Operadores que combinam o resultado de duas consultas (que devem ter as mesmas colunas):

| Operador    | Resultado                                                  | Ideia de conjuntos |
|-------------|------------------------------------------------------------|--------------------|
| `UNION`     | Linhas de uma consulta **ou** da outra (sem repetir)       | A ∪ B              |
| `INTERSECT` | Linhas que aparecem nas **duas** consultas                 | A ∩ B              |
| `EXCEPT`    | Linhas da primeira consulta que **não** estão na segunda   | A − B              |

---

## 📝 Questões e consultas

### Questão 1

**Liste o nome dos personagens que não têm dragões.**

```sql
SELECT p.nome
FROM PERSONAGENS p
LEFT JOIN DRAGOES d ON p.id = d.id_personagem
WHERE d.id IS NULL;
```

📌 O `LEFT JOIN` mantém todos os personagens. Os que ficaram com `d.id` nulo não têm dragão.

---

### Questão 2

**Liste o nome dos participantes de batalhas cujo resultado foi "Vitória".**

```sql
SELECT p.nome, pb.resultado
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
WHERE pb.resultado = 'Vitória';
```

📌 Junta personagens e participações e filtra pelo resultado.

---

### Questão 3

**Liste o nome dos personagens que têm relações familiares onde o tipo de relação contém "mãe" ou "filha".**

```sql
SELECT DISTINCT p.nome
FROM PERSONAGENS p
JOIN RELACOES_FAMILIARES rf
  ON p.id = rf.id_personagem1 OR p.id = rf.id_personagem2
WHERE rf.relacao IN ('Mãe', 'Filha');
```

📌 O personagem pode estar em qualquer um dos lados da relação, por isso o `OR` no `JOIN`. O `DISTINCT` evita nomes repetidos.

---

### Questão 4

**Liste os nomes dos personagens e os nomes de seus dragões.**

```sql
SELECT p.nome, d.nome
FROM PERSONAGENS p
LEFT JOIN DRAGOES d ON d.id_personagem = p.id;
```

📌 Mostra todos os personagens. Os que não têm dragão aparecem com o nome do dragão vazio (`NULL`).

---

### Questão 5

**Mostre os personagens que participaram de batalhas ocorridas entre 132 e 133.**

```sql
SELECT DISTINCT p.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
JOIN BATALHAS b ON pb.id_batalha = b.id
WHERE b.data >= '0132-01-01' AND b.data < '0134-01-01';
```

📌 Junta três tabelas e filtra as batalhas pelo intervalo de datas, do início de 132 até o fim de 133.

---

### Questão 6

**Liste os nomes dos dragões cujos nomes terminam com a letra "r" e seus respectivos donos.**

```sql
SELECT d.nome, p.nome
FROM DRAGOES d
LEFT JOIN PERSONAGENS p ON p.id = d.id_personagem
WHERE d.nome ILIKE '%r';
```

📌 O `%r` seleciona os nomes que terminam em "r". O `LEFT JOIN` mantém o dragão mesmo que ele não tenha dono cadastrado.

---

### Questão 7

**Liste o nome e a casa dos personagens que têm dragão ou participaram de alguma batalha.**

```sql
SELECT DISTINCT p.nome, p.casa
FROM PERSONAGENS p
LEFT JOIN DRAGOES d ON d.id_personagem = p.id
LEFT JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
WHERE d.id IS NOT NULL OR pb.id_personagem IS NOT NULL;
```

📌 Os dois `LEFT JOIN` mantêm todos os personagens, e o `WHERE ... OR` fica com quem tem dragão **ou** participou de batalha.

---

### Questão 8

**Liste o nome dos personagens da casa "Targaryen" que participaram de batalhas.**

```sql
SELECT DISTINCT p.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
WHERE p.casa = 'Targaryen';
```

📌 Filtra pela casa e usa `DISTINCT` porque um personagem pode ter lutado em várias batalhas.

---

### Questão 9

**Recupere os nomes dos personagens que têm dragões cujo nome começa com a letra S.**

```sql
SELECT DISTINCT p.nome
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id
WHERE d.nome ILIKE 's%';
```

📌 O `s%` seleciona nomes que começam com "s", e o `ILIKE` aceita "S" ou "s".

---

### Questão 10

**Recupere os nomes dos personagens e os nomes das batalhas que eles venceram.**

```sql
SELECT p.nome, b.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
JOIN BATALHAS b ON b.id = pb.id_batalha
WHERE pb.resultado = 'Vitória';
```

📌 A tabela `PARTICIPANTES_BATALHAS` liga personagens e batalhas, e o `WHERE` fica só com as vitórias.

---

### Questão 11

**Recupere os nomes dos personagens, as relações que eles têm com outros personagens e o nome dos personagens que se relacionam.**

```sql
SELECT p1.nome AS Personagem, rf.relacao, p2.nome AS Parente
FROM RELACOES_FAMILIARES rf
JOIN PERSONAGENS p1 ON p1.id = rf.id_personagem1
JOIN PERSONAGENS p2 ON p2.id = rf.id_personagem2;
```

📌 A tabela `PERSONAGENS` é usada duas vezes (`p1` e `p2`), uma para cada lado da relação. Os `AS` deixam as colunas do resultado com nomes claros.

---

### Questão 12

**Utilizando o operador `UNION`, liste o nome e a casa dos personagens que possuem um dragão ou que participaram de alguma batalha.**

```sql
SELECT p.nome, p.casa
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id
UNION
SELECT p.nome, p.casa
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id;
```

📌 Junta os dois grupos (quem tem dragão e quem lutou) em um só resultado, sem repetir quem está nos dois.

---

### Questão 13

**Utilizando o operador `INTERSECT`, liste os nomes dos personagens que pertencem à casa "Targaryen" e participaram de alguma batalha.**

```sql
SELECT p.nome
FROM PERSONAGENS p
WHERE p.casa = 'Targaryen'
INTERSECT
SELECT p.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id;
```

📌 Retorna só os nomes que aparecem nas duas consultas: são Targaryen **e** lutaram.

---

### Questão 14

**Utilizando o operador `EXCEPT`, liste os nomes de todos os personagens que não possuem dragão.**

```sql
SELECT p.nome
FROM PERSONAGENS p
EXCEPT
SELECT p.nome
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id;
```

📌 Pega todos os personagens e tira os que têm dragão. É outra forma de resolver a Questão 1.

---

### Questão 15

**Utilizando o operador `EXCEPT`, liste os nomes dos personagens que participaram de alguma batalha, mas não possuem dragão.**

```sql
SELECT p.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
EXCEPT
SELECT p.nome
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id;
```

📌 Parte de quem lutou e remove quem tem dragão, sobrando quem lutou sem dragão.

---

## ⚙️ Funcionalidades praticadas

- ✅ Junção de duas ou mais tabelas
- ✅ Busca de registros sem correspondência
- ✅ Filtro por texto, lista e intervalo de datas
- ✅ Remoção de repetições
- ✅ Autojunção
- ✅ União, interseção e diferença de consultas

---

## ▶️ Como executar

1. Crie o banco de dados e as tabelas no seu SGBD (por exemplo, PostgreSQL com o pgAdmin).
2. Abra o **Query Tool**.
3. Cole a consulta desejada e execute.

> O `ILIKE` funciona no PostgreSQL. Em outros SGBDs, use `LOWER(coluna) LIKE '...'`.



## 🎓 Aprendizados

Esta atividade permitiu entender que nem toda relação entre tabelas é um `JOIN` simples: o `LEFT JOIN` ajuda a encontrar o que **falta**, a autojunção relaciona uma tabela com ela mesma, e `UNION`, `INTERSECT` e `EXCEPT` funcionam como operações de conjuntos sobre o resultado das consultas.

---

## 👨‍💻 Autor

**Vinicius**

---

> Atividade desenvolvida para fins de estudo na disciplina de **Fundamentos Banco de Dados** UFC - Campus Quixadá 2026.2 