import java.util.Scanner; 
public class Exec { 
    public static void main(String args[]) { 
        // Crie um objeto chamado e1 a partir da classe EmpresaParticipante 
        EmpresaParticipante e1 = new EmpresaParticipante();
        // Crie um objeto chamado entrada a partir da classe Scanner 
        Scanner entrada = new Scanner(System.in);
        // Leia o nome e a cidade da empresa 
        e1.nome = entrada.nextLine();
        e1.cidade = entrada.nextLine();
        // Leia os dados do primeiro produto 
        e1.p1.nome = entrada.nextLine();
        e1.p1.tipo = entrada.nextLine();
        e1.p1.dataValidade = entrada.nextLine();
        // Leia os dados do segundo produto 
        e1.p2.nome = entrada.nextLine();
        e1.p2.tipo = entrada.nextLine();
        e1.p2.dataValidade = entrada.nextLine();
        // Leia os dados do terceiro produto 
        e1.p3.nome = entrada.nextLine();
        e1.p3.tipo = entrada.nextLine();
        e1.p3.dataValidade = entrada.nextLine();
        // Crie um objeto chamado avaliador a partir da classe Avaliador 
        Avaliador av = new Avaliador();
        // Leia o nome e a experiência do avaliador 
        av.nome = entrada.nextLine();
        av.experiencia = entrada.nextLine();
        // Faça o avaliador avaliar o primeiro produto
        e1.p1.nota = entrada.nextInt();
        // Faça o avaliador avaliar o segundo produto 
        e1.p2.nota = entrada.nextInt();
        // Faça o avaliador avaliar o terceiro produto 
        e1.p3.nota = entrada.nextInt();
        // Imprima na tela os dados da empresa
        System.out.println(e1.toString());
        // Imprima na tela os dados do primeiro produto, incluindo a nota 
        System.out.println(e1.p1.toString());
        // Imprima na tela os dados do segundo produto, incluindo a nota 
        System.out.println(e1.p2.toString());
        // Imprima na tela os dados do terceiro produto, incluindo a nota 
        System.out.println(e1.p3.toString());
        // Imprima na tela os dados do avaliador 
        System.out.print(av.toString() + "\n");
    } 
    
}