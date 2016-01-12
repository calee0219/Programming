/*************************************************************************
	> File Name: Scan.java
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: Tue 12 Jan 2016 11:49:57 AM CST
 ************************************************************************/

import java.io.*;
import java.util.*;

public class Scan {
    BufferedReader buffer;
    StringTokenizer tok;

    Scan() {
        buffer = new BufferedReader(new InputStreamReader(System.in));
    }
    boolean hasNext() {
        while(tok == null || !tok.hasMoreElements()) {
            try {
                tok = new StringTokenizer(buffer.readLine());
            } catch(Exception e) {
                return false;
            }
        }
        return true;
    }

    String next() {
        if(hasNext()) return tok.nextToken();
        return null;
    }

    int nextInt() { return Integer.parseInt(next()); }
    long nextlong() { return Long.parseLong(next()); }
    double nextDouble() { return Double.parseDouble(next()); }
}

