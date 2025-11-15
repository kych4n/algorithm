import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int T = Integer.parseInt(stringTokenizer.nextToken());

        for (int t=0; t<T; t++) {
            String answer = "YES";
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int N = Integer.parseInt(stringTokenizer.nextToken());
            String[] phoneNumberList = new String[N];
            for (int i=0; i<N; i++) {
                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                String phoneNumber = stringTokenizer.nextToken();
                phoneNumberList[i] = phoneNumber;
            }

            Arrays.sort(phoneNumberList);
            for (int i=0; i<N-1; i++) {
                if (phoneNumberList[i+1].startsWith(phoneNumberList[i])) {
                    answer = "NO";
                    break;
                }
            }

            System.out.println(answer);
        }
    }
}