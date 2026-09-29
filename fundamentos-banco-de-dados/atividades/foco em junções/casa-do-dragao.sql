--1. O nome dos personagens que não têm dragões.
SELECT p.nome
FROM PERSONAGENS p
LEFT JOIN DRAGOES d on p.id = d.id_personagem
WHERE d.id is Null;
--2. O nome dos participantes de batalhas cujo resultado foi “Vitória”.
SELECT p.nome, pb.resultado
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
WHERE pb.resultado = 'Vitória'
--3. O nome dos personagens que tem relações familiares onde o tipo de relação contém
--"mãe" ou "filha"
SELECT DISTINCT p.nome
FROM PERSONAGENS p
JOIN RELACOES_FAMILIARES rf ON p.id = rf.id_personagem1 OR p.id = rf.id_personagem2
WHERE rf.relacao in ('Mãe','Filha')
--4. Liste os nomes dos personagens e os nomes de seus dragões.
SELECT p.nome, d.nome
FROM PERSONAGENS p
LEFT JOIN DRAGOES d on d.id_personagem = p.id
--5. Mostre os personagens que participaram de batalhas ocorridas entre 132 e 133.
SELECT p.nome 
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
JOIN BATALHAS b ON pb.id_batalha = b.id
WHERE b.data > '0131-12-30' and b.data < '0134-01-01'

--6. Liste os nomes dos dragões cujos nomes terminam com a letra “r” e seus
--respectivos donos.
SELECT d.nome, p.nome
FROM DRAGOES d
LEFT JOIN PERSONAGENS p ON p.id = d.id_personagem

--7. Liste o nome e a casa dos personagens que têm dragão ou participaram de alguma
--batalha.
SELECT DISTINCT p.nome, p.casa
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id 
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id


----8. Liste o nome dos personagens da casa “Targaryen” que participaram de batalhas.
SELECT DISTINCT p.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
WHERE p.casa = 'Targaryen'
--9. Recupere os nomes dos personagens que têm dragões cujo nome começa com a
--letra S.
SELECT DISTINCT p.nome
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id
WHERE d.nome ilike 's%'
--10. Recupere os nomes dos personagens e os nomes das batalhas que eles venceram.
SELECT p.nome, b.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
JOIN BATALHAS b ON b.id = pb.id_batalha
WHERE pb.resultado = 'Vitória'
--11. Recupere os nomes dos personagens, as relações que eles têm com outros
--personagens e o nome dos personagens que se relacionam.
SELECT p1.nome As Personagem, relacao, p2.nome As Parente
FROM RELACOES_FAMILIARES rf
JOIN PERSONAGENS p1 ON p1.id = rf.id_personagem1
JOIN PERSONAGENS p2 ON p2.id = rf.id_personagem2
--12. Utilizando o operador UNION, liste o nome e a casa dos personagens que possuem
--um dragão ou que participaram de alguma batalha.
SELECT p.nome, p.casa
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id
UNION
SELECT p.nome, p.casa
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb on pb.id_personagem = p.id

--13. Utilizando o operador INTERSECT, liste os nomes dos personagens que pertencem
--à casa “Targaryen” e participaram de alguma batalha.
SELECT p.nome
FROM PERSONAGENS p
WHERE p.casa = 'Targaryen'
INTERSECT
SELECT p.nome
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb on pb.id_personagem = p.id
--14. Utilizando o operador EXCEPT, liste os nomes de todos os personagens que não
--possuem dragão.
SELECT p.nome 
FROM PERSONAGENS p
EXCEPT 
SELECT p.nome
FROM PERSONAGENS p
JOIN DRAGOES d on d.id_personagem = p.id
--15. Utilizando o operador EXCEPT, liste os nomes dos personagens que participaram de
--alguma batalha, mas não possuem dragão.
SELECT p.nome 
FROM PERSONAGENS p
JOIN PARTICIPANTES_BATALHAS pb ON pb.id_personagem = p.id
EXCEPT 
SELECT p.nome 
FROM PERSONAGENS p
JOIN DRAGOES d ON d.id_personagem = p.id