-- ============================================================
-- SCRIPT POSTGRESQL - CLÍNICA VETERINÁRIA
-- Compatível com PostgreSQL 12+
-- ============================================================

-- ------------------------------------------------------------
-- 1. REMOÇÃO DAS TABELAS
-- ------------------------------------------------------------

DROP TABLE IF EXISTS ConsultaProcedimento;
DROP TABLE IF EXISTS Consulta;
DROP TABLE IF EXISTS Procedimento;
DROP TABLE IF EXISTS Animal;
DROP TABLE IF EXISTS Tutor;


-- ------------------------------------------------------------
-- 2. CRIAÇÃO DAS TABELAS
-- ------------------------------------------------------------

CREATE TABLE Tutor (
    tutor_id   INTEGER PRIMARY KEY,
    nome       VARCHAR(100) NOT NULL
);

CREATE TABLE Animal (
    animal_id  INTEGER PRIMARY KEY,
    nome       VARCHAR(100) NOT NULL,
    especie    VARCHAR(50) NOT NULL,
    tutor_id   INTEGER NOT NULL,

    CONSTRAINT fk_animal_tutor
        FOREIGN KEY (tutor_id)
        REFERENCES Tutor(tutor_id)
);

CREATE TABLE Consulta (
    consulta_id   INTEGER PRIMARY KEY,
    animal_id     INTEGER NOT NULL,
    data_consulta DATE NOT NULL,

    CONSTRAINT fk_consulta_animal
        FOREIGN KEY (animal_id)
        REFERENCES Animal(animal_id)
);

CREATE TABLE Procedimento (
    procedimento_id INTEGER PRIMARY KEY,
    descricao       VARCHAR(100) NOT NULL,
    valor           NUMERIC(10,2) NOT NULL
);

CREATE TABLE ConsultaProcedimento (
    consulta_id     INTEGER NOT NULL,
    procedimento_id INTEGER NOT NULL,

    PRIMARY KEY (consulta_id, procedimento_id),

    CONSTRAINT fk_cp_consulta
        FOREIGN KEY (consulta_id)
        REFERENCES Consulta(consulta_id),

    CONSTRAINT fk_cp_procedimento
        FOREIGN KEY (procedimento_id)
        REFERENCES Procedimento(procedimento_id)
);


-- ------------------------------------------------------------
-- 3. INSERÇÃO DOS TUTORES
-- ------------------------------------------------------------

INSERT INTO Tutor (tutor_id, nome) VALUES
(1,  'Mariana'),
(2,  'Rafael'),
(3,  'Luciana'),
(4,  'Pedro'),
(5,  'Camila'),
(6,  'João'),
(7,  'Beatriz'),
(8,  'Diego'),
(9,  'Fernanda'),
(10, 'André');


-- ------------------------------------------------------------
-- 4. INSERÇÃO DOS ANIMAIS
-- ------------------------------------------------------------

INSERT INTO Animal (animal_id, nome, especie, tutor_id) VALUES
(1,  'Thor',    'Cachorro', 1),
(2,  'Luna',    'Gato',     1),
(3,  'Bob',     'Cachorro', 2),
(4,  'Mel',     'Gato',     3),
(5,  'Nina',    'Cachorro', 5),
(6,  'Simba',   'Gato',     6),
(7,  'Lola',    'Cachorro', 7),
(8,  'Max',     'Cachorro', 8),
(9,  'Pipoca',  'Gato',     9),
(10, 'Zeus',    'Cachorro', 10),
(11, 'Frida',   'Cachorro', 5),
(12, 'Theo',    'Gato',     2),
(13, 'Amora',   'Cachorro', 3),
(14, 'Bento',   'Cachorro', 8),
(15, 'Kiara',   'Gato',     4);


-- ------------------------------------------------------------
-- 5. INSERÇÃO DAS CONSULTAS
-- ------------------------------------------------------------

INSERT INTO Consulta
    (consulta_id, animal_id, data_consulta)
VALUES
(1,  1,  '2024-01-10'),
(2,  2,  '2024-03-15'),
(3,  3,  '2024-04-20'),
(4,  1,  '2025-02-05'),
(5,  3,  '2025-05-12'),
(6,  5,  '2024-06-18'),
(7,  5,  '2025-01-20'),
(8,  6,  '2025-02-14'),
(9,  8,  '2024-08-03'),
(10, 8,  '2025-08-22'),
(11, 9,  '2024-09-10'),
(12, 11, '2025-03-11'),
(13, 12, '2024-11-02'),
(14, 13, '2026-01-17'),
(15, 14, '2024-12-05'),
(16, 2,  '2025-11-18'),
(17, 6,  '2026-02-10'),
(18, 3,  '2026-03-22'),
(19, 10, '2025-12-01'),
(20, 1,  '2026-04-07'),
(21, 5,  '2024-07-22'),
(22, 8,  '2024-10-19');


-- ------------------------------------------------------------
-- 6. INSERÇÃO DOS PROCEDIMENTOS
-- ------------------------------------------------------------

INSERT INTO Procedimento
    (procedimento_id, descricao, valor)
VALUES
(1, 'Vacinação',          120.00),
(2, 'Consulta Clínica',   200.00),
(3, 'Exame de Sangue',    300.00),
(4, 'Cirurgia',          1500.00),
(5, 'Ultrassonografia',   450.00),
(6, 'Radiografia',        380.00),
(7, 'Limpeza Dentária',   250.00),
(8, 'Curativo',            90.00);


-- ------------------------------------------------------------
-- 7. RELACIONAMENTO ENTRE CONSULTAS E PROCEDIMENTOS
-- ------------------------------------------------------------

INSERT INTO ConsultaProcedimento
    (consulta_id, procedimento_id)
VALUES
(1,  1),
(1,  2),

(2,  2),

(3,  3),

(4,  2),
(4,  4),

(5,  2),
(5,  5),

(6,  1),
(6,  2),

(7,  2),
(7,  7),

(8,  3),

(9,  1),
(9,  6),

(10, 2),
(10, 5),

(11, 7),

(12, 3),
(12, 6),

(13, 2),

(14, 5),

(15, 1),
(15, 7),

(16, 2),

(17, 3),

(18, 5),

(19, 4),

(20, 2),
(20, 8),

(21, 1),

(22, 6);