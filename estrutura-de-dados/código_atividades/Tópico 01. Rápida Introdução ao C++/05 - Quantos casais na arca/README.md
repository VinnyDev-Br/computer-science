![Moodle UFC](https://moodle2.quixada.ufc.br/pluginfile.php/1/theme_moove/logo/1787762535/Quixada_brasao1_horizontal_cor-01.png)

# Quantos casais na arca

O dono do zoológico quer construir uma grande arca e colocar os animais dentro dela. Os animais só podem embarcar aos **pares**. Um número inteiro representa uma espécie de animal. Se esse número for **positivo**, representa um animal **macho**; se for **negativo**, representa uma **fêmea**. Um casal válido consiste em um macho e uma fêmea da mesma espécie.

```
descasados = Crie um vetor para armazenar os animais sem pares
para cada animal no zoo:
    animal = leia o valor
    Se ele tiver par na lista de descasado
        marque a posição do par no vetor com 0
        incremente a contagem de pares
    se não
        adicione esse animal na lista de descasados
```