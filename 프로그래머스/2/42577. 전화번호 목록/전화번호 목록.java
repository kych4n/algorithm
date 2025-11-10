import java.util.*;
import java.util.stream.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        List<String> phoneNumberList = Arrays.stream(phone_book).collect(Collectors.toList());
        Set<String> phoneNumberSet = phoneNumberList.stream().collect(Collectors.toSet());
        for (String phoneNumber : phoneNumberList) {
            for (int i=1; i<phoneNumber.length(); i++) {
                String target = phoneNumber.substring(0, i);
                if (phoneNumberSet.contains(target)) {
                    return false;
                }
            }    
        }
        return answer;
    }
}