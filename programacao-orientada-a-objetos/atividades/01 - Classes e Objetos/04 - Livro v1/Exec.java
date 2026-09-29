import java.util.Scanner;

public class Exec {

    public static void main(String args[]) {
        // Crie um objeto chamado livro a partir da classe Livro
        Livro livro = new Livro();    
        // Crie um objeto de leitura de dados chamado entrada a partir da classe Scanner
        Scanner entrada = new Scanner(System.in);
        
        livro.titulo = entrada.nextLine();
        livro.autor = entrada.nextLine();

        // Faça uma chamada ao método ler de livro
        livro.ler();
        // Faça uma chamada ao método adicionarPaginas
        livro.adicionarPaginas();
        // Faça uma chamada ao método toString de livro e imprima o resultado
        System.out.println(livro.toString());
        // Faça uma chamada ao método ler de livro
        livro.ler();
        // Faça uma chamada ao método adicionarPaginas
        livro.adicionarPaginas();
        // Faça uma chamada ao método toString de livro e imprima o resultado
        System.out.println(livro.toString());
        // Faça uma chamada ao método finalizarLeitura
        livro.finalizar();
    }
}