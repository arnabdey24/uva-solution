import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));static PrintWriter out = new PrintWriter(System.out);
    //static BufferedReader reader;static PrintWriter out;static { try { reader = new BufferedReader(new FileReader("input.txt"));out=new PrintWriter(new BufferedWriter(new FileWriter("output.txt"))); } catch (Exception e) { e.printStackTrace(); } }
    public static void main(String[] args) throws Exception {
        //Reader sc = new Reader();
        Scanner scanner=new Scanner(System.in);
        ArrayList<BigInteger> v=new ArrayList<>();
        while (scanner.hasNext()){
            while (true){
                int t=scanner.nextInt();
                if(t==-999999)break;
                v.add(BigInteger.valueOf(t));
            }
            //System.out.println(v);
            /*for (int i = 1; i < v.size(); i++) {
                v.set(i,v.get(i).multiply(v.get(i-1)));
            }*/
            BigInteger ans=v.get(0);
            for (int i = 0; i < v.size(); i++) {
                BigInteger tmp=BigInteger.ONE;
                for (int j = i; j < v.size(); j++) {
                    tmp=tmp.multiply(v.get(j));
                    if(tmp.compareTo(ans)>0)ans=tmp;
                }
            }
            System.out.println(ans);
            v.clear();
        }






        out.close();
    }



}



class node implements Comparable<node> {
    Integer no;
    Integer cost;
    Vector<node> adj = new Vector<>();

    public node(Integer no, Integer cost) {
        this.no = no;
        this.cost = cost;
    }

    @Override
    public String toString() {
        return "node{" +
                "no=" + no +
                ", cost=" + cost +
                '}';
    }

    @Override
    public int compareTo(node o) {
        return o.cost - this.cost;
    }
}
class edge implements Comparable<edge> {
    tuple u;
    Double cost;

    public edge(tuple u, Double cost) {
        this.u = u;
        this.cost = cost;
    }

    @Override
    public int compareTo(edge o) {
        return this.cost.compareTo(o.cost);
    }

    @Override
    public String toString() {
        return "edge{" +
                "u=" + u +
                ", cost=" + cost +
                '}';
    }
}
class tuple implements Comparable<tuple> {
    Integer a;
    Integer b;

    public tuple(Integer a, Integer b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public int compareTo(tuple o) {
        return (int) (this.b - o.b);
    }

    @Override
    public String toString() {
        return "tuple{" +
                "a=" + a +
                ", b=" + b +
                '}';
    }
}
class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
        byte[] buf = new byte[64];
        int cnt = 0, c;
        while ((c = read()) != -1) {
            if (c == '\n') break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = (c == '-');
        if (neg) c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) return -ret;
        return ret;
    }

    public long nextLong() throws IOException {
        long ret = 0;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = (c == '-');
        if (neg) c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) return -ret;
        return ret;
    }

    public double nextDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = (c == '-');
        if (neg) c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (c == '.') while ((c = read()) >= '0' && c <= '9') ret += (c - '0') / (div *= 10);
        if (neg) return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) buffer[0] = -1;
    }

    private byte read() throws IOException {
        if (bufferPointer == bytesRead) fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException {
        if (din == null) return;
        din.close();
    }
}
