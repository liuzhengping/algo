import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map.Entry;


public class SetProba {

	static class Par implements Comparable<Par> {
		int x, y;
		public Par(int x, int y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return "(" + x + ", " + y + ")";
		}
		@Override
		public boolean equals(Object o) {
			if( !(o instanceof Par) )
				return false;
			return this.x == ((Par) o).x && this.y == ((Par) o).y;
		}
		public int compareTo(Par p) {
			// TODO Auto-generated method stub
			if(this.x < p.x) return -1;
			if(this.x > p.x) return 1;
			if(this.y == p.y) return 0;
			return 1;
		}
	}
	static class Node {
		Integer x;
		LinkedList<Integer> l;
		public Node(int val) {
			x = new Integer(val);
			l = new LinkedList<Integer>();
		}
		public void add(Integer x) {
			l.add(x);
		}
		@Override
		public boolean equals(Object o) {
			if( !(o instanceof Node) )
				return false;
			return this.x.equals(((Node) o).x);
		}
		public String toString() {
			String s = x.toString() + ": ";
			for(Integer x : l)
				s += " " + x;
			return s;
		}
	}
	
	static HashMap<Integer, Node> mapper;
	
	static void ispis(HashMap<Integer, Node> s) {
		for(Entry<Integer, Node> e : s.entrySet())
			System.out.print(e.getKey() + ">" + e.getValue() + "|");
		System.out.println();
	}
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		mapper = new HashMap<Integer, Node>();
		BufferedReader reader = new BufferedReader( new InputStreamReader(System.in) );
		//input:
		for(String line; (line = reader.readLine()) != null && line.length() > 0; ) {
			String tokens[] = line.split(" ");
			Par p = new Par( Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]) );
			System.out.println("> " + p);
			
			if( !mapper.containsKey(p.x) )
				mapper.put(p.x, new Node(p.x));
			
			mapper.get(p.x).add(p.y);
		}
		
		ispis(mapper);
			
	}
	
}
