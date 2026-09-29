public class Livro{
    String titulo;
    String autor;
    int paginas;
    
    public Livro(){
        
    }
    
    public Livro(String titulo, String autor, int paginas){
        this.titulo = titulo;
        this.autor = autor;
        this.paginas = 0;
    }
    
    public String toString(){
        return this.titulo + " " + this.autor + " " + this.paginas;
    }
    
    public void adicionarPaginas(){
        this.paginas += 10;
    }
    
    public void ler(){
        System.out.println("Lendo " + this.titulo);
    }
    
    public void finalizar(){
        System.out.println("Leitura de " + this.titulo + " finalizada");
    }
    
}
