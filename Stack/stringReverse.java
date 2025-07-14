package Rumesh;

import java.util.Stack;

public class stringReverse {
    public String reverse(String str){

        if (str == null) throw new IllegalArgumentException();
        Stack<Character> stack = new Stack<Character>();
//        for(int i = 0; i< str.length(); i++){
//            stack.push(str.charAt(i));
//        }

        // Using for each
        for(char ch : str.toCharArray()){
            stack.push(ch);
        }

        StringBuffer reversed = new StringBuffer();

        while(!stack.empty())
            reversed.append(stack.pop());
        return reversed.toString();

    }
}
