import java.util.*;
import java.util.Stack;
import java.util.HashMap;

/* Java Programming
Question 2: Write a fucntion when passed a string containing mixture of bracket charactrs i.e.
'{', '}', '[', ']', '(' and ')' return true if the bracket in the string are correctly balanced
and false otherwise. Non-brackets characters in the string should be ignored
Example:
Input -> "{[(())]()}" will return true
Input -> "{[(()])()}" will return false
*/


/*
Approach: Use a hash table to uniquely store the close brackets as the values corresponding to its open 
bracket as the keys. The balanced bracket in the string can be checked using stack since it is a First-In-
First-Out data structure. 
Mechanisms:
		|	|										|   |
		| [	| -> insert 1 			   -> insert 6  | ] | -> pop 1
		| { | -> insert 2			   -> insert 5	| } | -> pop 2
string  | ( | -> insert 3		stack  -> insert 4	| ) | -> pop 3
		| ) | -> insert 4			   -> insert 3	| ( | -> pop 4
		| }	| -> insert 5			   -> insert 2	| { | -> pop 5
		| ] | -> insert 6			   -> insert 1	| [ | -> pop 6
		|___| 			   							|___|

Each open bracket in the strings are check according to the keys in dictionary and store into stack.
*/	
public class BalancedBrackets{
	private static String strName;
    private static HashMap<Character, Character> createMap(){
        HashMap<Character, Character> map = new HashMap<Character, Character>();

        // Put the key-value pairs
        map.put('(',')');
        map.put('[',']');
        map.put('{','}');
        
        return map;
    }

    /*
	 * Check balanced brackets
	 *
	 * @param string of brackets
	 * @return true or false (balanced or not balanced)
	*/
    private static Boolean checkBrackets(String line){
        HashMap map = createMap();

        // Create stack instance
        Stack<Character> parens = new Stack<Character>();
        char[] charray = line.toCharArray();

        for(char c : charray){
            // store open brackets in stack
            if (map.containsKey(c)){
                parens.push(c);
            }

            // Check for closing brackets store as values
            else if (map.containsValue(c)) {
                // close bracket is not matched with any open bracket
                if (parens.isEmpty()) {
                    return false;
                }

                // return false if close bracket does not match with open bracket
                char topElem = parens.peek();
                if ((Character) map.get(topElem) != c) {
                    return false;
                }

                // pop the open bracket (successfully matched)
                parens.pop();
            }
        }

        // After all brackets are popped and check the stack is empty.
        if (parens.isEmpty()) {
            return true;
        }
        
        return false;
    }

    public static void main(String[] args) {
        try{
            System.out.println("Please input a string with different brackets");
            Scanner input = new Scanner(System.in);
            strName = input.nextLine();
            System.out.println(checkBrackets(strName));
        }
        catch(NumberFormatException e){
            System.err.println("Exception: " +e);
            System.err.println("Invalid input! Must enter string");
            System.out.println();
        }

        
    }

}