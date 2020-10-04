import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));static PrintWriter out = new PrintWriter(System.out);
    //static BufferedReader reader;static PrintWriter out;static { try { reader = new BufferedReader(new FileReader("input.txt"));out=new PrintWriter(new BufferedWriter(new FileWriter("output.txt"))); } catch (Exception e) { e.printStackTrace(); } }
    public static void main(String[] args) throws Exception {
        Reader sc = new Reader();
        Map<Character,Character> mp=new HashMap<>();
        mp.put('V','0');
        mp.put('U','1');
        mp.put('C','2');
        mp.put('D','3');
        int n=sc.nextInt();
        out.println("COWCULATIONS OUTPUT");
        for (int k = 0; k <n ; k++) {
            char[] s=sc.readLine().toCharArray();
            char[] s1=sc.readLine().toCharArray();
            for (int i = 0; i <s.length ; i++) {
                s[i]=mp.get(s[i]);
                s1[i]=mp.get(s1[i]);
            }
            String a=new BigInteger(String.valueOf(s),4).toString(10);
            String b=new BigInteger(String.valueOf(s1),4).toString(10);
            int num1=Integer.parseInt(a);
            int num2=Integer.parseInt(b);
            for (int i = 0; i <3 ; i++) {
                String t=sc.readLine();
                if(t.charAt(0)=='A'){
                    num2+=num1;
                }
                else if(t.charAt(0)=='R'){
                    num2/=4;
                }
                else if(t.charAt(0)=='L'){
                    num2*=4;
                }
            }
            char[] s2=sc.readLine().toCharArray();
            for (int i = 0; i <s2.length ; i++) {
                s2[i]=mp.get(s2[i]);
            }
            String c=new BigInteger(String.valueOf(s2),4).toString(10);
            int num3=Integer.parseInt(c);
            if(num2==num3) out.println("YES");
            else out.println("NO");
        }
        out.println("END OF OUTPUT");
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

///*
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


//*/
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