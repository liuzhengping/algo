import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;


public class SpanningTree {
	
	/* liste susjednosti */
	static ArrayList< LinkedList<Integer> > listaSusj;
	/* polje koje kaze dali smo posjetili neki vrh ili nismo */
	static boolean[] bio;
	/* lista s bridovima razapinjajuceg stabla */
	static ArrayList< Brid > stablo;

	static int posjecenih; /* broj posjecenih vrhova tijekom DFS-a */

	static class Brid {
		int from, to;
		Brid(int from, int to) { this.from = from; this. to = to; }
	}

	static void dfs(int id) {
		bio[id] = true; /* obiljezi vrh kao posjecen */
		++posjecenih;
		/* za sve susjede v od cvora s oznakom id */
		for(Integer v : listaSusj.get(id))
			if(!bio[v]) { 
				/* ako susjed nije posjecen, onda sigurno preko njega ne zatvaramo
	         		neki ciklus, pa se zato sirimo i na njega */
				stablo.add(new Brid(id, v)); /* zapamtimo taj brid u listi */
				dfs(v); /* pozovemo rekurziju za susjeda */
			}
	}
	
	public static void main(String[] args) {
		/* V - broj vrhova u grafu; E - broj bridova u grafu */
		int V, E;
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		V = sc.nextInt(); E = sc.nextInt();
		listaSusj = new ArrayList<LinkedList<Integer>>(V);
		for(int i = 0; i < V; ++i)
			listaSusj.add(new LinkedList<Integer>());
		bio = new boolean[V];
		stablo = new ArrayList<Brid>(V);
		for(int i = 0; i < E; ++i) {
			int from, to;
			from = sc.nextInt()-1; to = sc.nextInt()-1; 
			listaSusj.get(from).addFirst(to);
			listaSusj.get(to).addFirst(from);
		}

		/*sad se siri u dubini (Depth First Search)*/
		dfs(0);
		
		if( posjecenih < V ) 
			System.out.println("Ne postoji razapinjajuce stablo jer graf ima vise komponenata.");
		else
			for(Brid b : stablo) 
				System.out.printf("%d %d\n", b.from+1, b.to+1);

	}

}
