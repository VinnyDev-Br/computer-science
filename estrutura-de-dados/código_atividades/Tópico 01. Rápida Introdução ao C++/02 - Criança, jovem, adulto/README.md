[![Moodle UFC](https://moodle2.quixada.ufc.br/pluginfile.php/1/theme_moove/logo/1787762535/Quixada_brasao1_horizontal_cor-01.png)](https://moodle2.quixada.ufc.br/)

# Criança, jovem, adulto

## Contexto

Em um projeto escolar, um professor precisa classificar os alunos de acordo com suas idades. A tarefa é determinar se um aluno é uma criança, jovem, adulto, idoso ou uma múmia, com base em regras específicas. O professor gostaria que a implementação fosse feita de forma clara e eficiente.

Leia o nome da pessoa e um inteiro que representa a idade de uma pessoa e escreva:

-   "crianca" se menor que 12 (não use o ç),
-   "jovem" se menor que 18,
-   "adulto" se menor que 65,
-   "idoso" se menor que 1000,
-   "mumia" caso contrario (não ponha o acento).

### Entrada

-   Na primeira linha o nome da pessoa (uma string)
-   Na segunda linha a idade (um inteiro)

### Saída

-   Uma frase no formato "`<nome>` eh `<classificação>`"

### Restrição

Por simplificações, não faça flexão de gênero (idoso, idosa, adulto, adulta), não use acento, nem ç, nem maiúscula.

## Testes

```
>>>>>>>> INSERT
mario
4
======== EXPECT
mario eh crianca
<<<<<<<< FINISH
```

```
>>>>>>>> INSERT
jose
65
======== EXPECT
jose eh idoso
<<<<<<<< FINISH
```

## Dicas

### Programando em: C++

-   Utilize a técnica do seleção intervalada e termine com um else sem condição:

```cpp
int main() {
    if(x < 12) {
        ...
    }  
    else if(x < 18) {
        ...
    }  
    else if(x < 65) {
        ...
    }  
    else {
        ...
    }
}
```