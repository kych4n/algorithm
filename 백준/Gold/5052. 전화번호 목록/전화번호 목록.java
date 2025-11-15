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
            Set<String> phoneNumberSet = new HashSet<>();
            String[] phoneNumberList = new String[N];
            for (int i=0; i<N; i++) {
                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                String phoneNumber = stringTokenizer.nextToken();
                phoneNumberSet.add(phoneNumber);
                phoneNumberList[i] = phoneNumber;
            }

            for (int i=0; i<N; i++) {
                String phoneNumber = phoneNumberList[i];
                for (int j=1; j<phoneNumber.length(); j++) {
                    String target = phoneNumber.substring(0, j);
                    if (phoneNumberSet.contains(target)) {
                        answer = "NO";
                        break;
                    }
                }
            }

            System.out.println(answer);
        }
    }
}