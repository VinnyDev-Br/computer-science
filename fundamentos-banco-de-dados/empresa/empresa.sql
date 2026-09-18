--
-- PostgreSQL database dump
--

-- Dumped from database version 16.3
-- Dumped by pg_dump version 16.3

-- Started on 2026-09-10 10:41:12

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 215 (class 1259 OID 60822)
-- Name: departamento; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.departamento (
    dnome character varying(15) NOT NULL,
    dnumero integer NOT NULL,
    cpf_gerente character(11),
    data_inicio_gerente date
);


ALTER TABLE public.departamento OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 60856)
-- Name: dependente; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.dependente (
    fcpf character(11) NOT NULL,
    nome_dependente character varying(15) NOT NULL,
    sexo character(1),
    datanasc date,
    parentesco character varying(8)
);


ALTER TABLE public.dependente OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 60829)
-- Name: funcionario; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.funcionario (
    pnome character varying(15) NOT NULL,
    minicial character(1),
    unome character varying(15) NOT NULL,
    cpf character(11) NOT NULL,
    datanasc date NOT NULL,
    endereco character varying(40),
    sexo character(1),
    salario numeric(10,2),
    cpf_supervisor character(11),
    dnr integer
);


ALTER TABLE public.funcionario OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 60834)
-- Name: localizacao_dep; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.localizacao_dep (
    dnumero integer NOT NULL,
    dlocal character varying(15) NOT NULL
);


ALTER TABLE public.localizacao_dep OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 60844)
-- Name: projeto; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.projeto (
    projnome character varying(15) NOT NULL,
    projnumero integer NOT NULL,
    projlocal character varying(15),
    dnum integer NOT NULL
);


ALTER TABLE public.projeto OWNER TO postgres;

--
-- TOC entry 220 (class 1259 OID 60866)
-- Name: trabalha_em; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.trabalha_em (
    fcpf character(11) NOT NULL,
    pnr integer NOT NULL,
    horas numeric(3,1)
);


ALTER TABLE public.trabalha_em OWNER TO postgres;

--
-- TOC entry 4874 (class 0 OID 60822)
-- Dependencies: 215
-- Data for Name: departamento; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.departamento VALUES ('Pesquisa', 5, '33344555587', '1988-05-22');
INSERT INTO public.departamento VALUES ('Administração', 4, '98765432168', '1995-01-01');
INSERT INTO public.departamento VALUES ('Matriz', 1, '88866555576', '1981-06-19');


--
-- TOC entry 4878 (class 0 OID 60856)
-- Dependencies: 219
-- Data for Name: dependente; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.dependente VALUES ('33344555587', 'Alícia', 'F', '1986-04-05', 'Filha');
INSERT INTO public.dependente VALUES ('33344555587', 'Tiago', 'M', '1983-10-25', 'Filho');
INSERT INTO public.dependente VALUES ('33344555587', 'Janaína', 'F', '1958-05-03', 'Esposa');
INSERT INTO public.dependente VALUES ('98765432168', 'Antonio', 'M', '1942-02-28', 'Marido');
INSERT INTO public.dependente VALUES ('12345678966', 'Michael', 'M', '1988-01-04', 'Filho');
INSERT INTO public.dependente VALUES ('12345678966', 'Alícia', 'F', '1988-12-30', 'Filha');
INSERT INTO public.dependente VALUES ('12345678966', 'Elizabeth', 'F', '1967-05-05', 'Esposa');


--
-- TOC entry 4875 (class 0 OID 60829)
-- Dependencies: 216
-- Data for Name: funcionario; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.funcionario VALUES ('João', 'B', 'Silva', '12345678966', '1965-01-09', 'Rua das flores, 751, São Paulo, SP', 'M', 30000.00, '33344555587', 5);
INSERT INTO public.funcionario VALUES ('Fernando', 'T', 'Wong', '33344555587', '1955-12-08', 'Rua da lapa, 34, São Paulo, SP', 'M', 40000.00, '88866555576', 5);
INSERT INTO public.funcionario VALUES ('Alice', 'J', 'Zelaya', '99988777767', '1968-01-19', 'Rua Souza Lima, 35, Curitiba, PR', 'F', 25000.00, '98765432168', 4);
INSERT INTO public.funcionario VALUES ('Jennifer', 'S', 'Souza', '98765432168', '1941-06-20', 'Av. Arthur de Lima, 54, Santo Andre, SP', 'F', 43000.00, '88866555576', 4);
INSERT INTO public.funcionario VALUES ('Ronaldo', 'K', 'Lima', '66688444476', '1962-09-15', 'Rua Rebouças, 65, Piracicaba, SP', 'M', 38000.00, '33344555587', 5);
INSERT INTO public.funcionario VALUES ('André', 'V', 'Pereira', '98798798733', '1969-03-29', 'Rua Timbira, 35, São Paulo, SP', 'M', 25000.00, '98765432168', 4);
INSERT INTO public.funcionario VALUES ('Jorge', 'E', 'Brito', '88866555576', '1937-11-10', 'Rua do Horto, 35, São Paulo, SP', 'M', 55000.00, NULL, 1);
INSERT INTO public.funcionario VALUES ('Joice', 'A', 'Leite', '45345345376', '1972-07-31', 'Av. Lucas Obes, 74, São Paulo, SP', 'F', 30000.00, '33344555587', 5);


--
-- TOC entry 4876 (class 0 OID 60834)
-- Dependencies: 217
-- Data for Name: localizacao_dep; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.localizacao_dep VALUES (1, 'São Paulo');
INSERT INTO public.localizacao_dep VALUES (4, 'Mauá');
INSERT INTO public.localizacao_dep VALUES (5, 'Santo André');
INSERT INTO public.localizacao_dep VALUES (5, 'Itu');
INSERT INTO public.localizacao_dep VALUES (5, 'São Paulo');


--
-- TOC entry 4877 (class 0 OID 60844)
-- Dependencies: 218
-- Data for Name: projeto; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.projeto VALUES ('ProdutoX', 1, 'Santo André', 5);
INSERT INTO public.projeto VALUES ('ProdutoY', 2, 'Itu', 5);
INSERT INTO public.projeto VALUES ('ProdutoZ', 3, 'São Paulo', 5);
INSERT INTO public.projeto VALUES ('Informatizacao', 10, 'Mauá', 4);
INSERT INTO public.projeto VALUES ('Reorganizacao', 20, 'São Paulo', 1);
INSERT INTO public.projeto VALUES ('NovosBeneficios', 30, 'Mauá', 4);


--
-- TOC entry 4879 (class 0 OID 60866)
-- Dependencies: 220
-- Data for Name: trabalha_em; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.trabalha_em VALUES ('12345678966', 1, 32.5);
INSERT INTO public.trabalha_em VALUES ('12345678966', 2, 7.5);
INSERT INTO public.trabalha_em VALUES ('66688444476', 3, 40.0);
INSERT INTO public.trabalha_em VALUES ('45345345376', 1, 20.0);
INSERT INTO public.trabalha_em VALUES ('45345345376', 2, 20.0);
INSERT INTO public.trabalha_em VALUES ('33344555587', 2, 10.0);
INSERT INTO public.trabalha_em VALUES ('33344555587', 3, 10.0);
INSERT INTO public.trabalha_em VALUES ('33344555587', 10, 10.0);
INSERT INTO public.trabalha_em VALUES ('33344555587', 20, 10.0);
INSERT INTO public.trabalha_em VALUES ('99988777767', 30, 30.0);
INSERT INTO public.trabalha_em VALUES ('99988777767', 10, 10.0);
INSERT INTO public.trabalha_em VALUES ('98798798733', 10, 35.0);
INSERT INTO public.trabalha_em VALUES ('98798798733', 30, 5.0);
INSERT INTO public.trabalha_em VALUES ('98765432168', 30, 20.0);
INSERT INTO public.trabalha_em VALUES ('98765432168', 20, 15.0);
INSERT INTO public.trabalha_em VALUES ('88866555576', 20, NULL);


-- Completed on 2026-09-10 10:41:12

--
-- PostgreSQL database dump complete
--
