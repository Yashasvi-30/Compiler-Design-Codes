import java.util.*;
class Calculate
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Strings (type 'END' to finish):");
        String vowels_str = "";
        String specialchar_str = "";
        int count_vowels = 0, count_specialchar = 0, count_spaces = 0, count_tabs = 0, count_newlines = 0, count_keywords = 0;
        String new_str = "";
        String[] arr_kw = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "float", "for", "goto", "if", "int", "long", "return", "short", "sizeof", "switch", "typedef", "void", "while"};
String prevLine = "";
        while (sc.hasNextLine()) {
            String str = sc.nextLine();
            if (str.isEmpty() && prevLine.isEmpty()) {
                break;
            }
            prevLine = str;
            int len = str.length();

            for (int i = 0; i < len; i++) {
                char ch = str.charAt(i);
                // Counting Vowels
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                    count_vowels++;
                    vowels_str = vowels_str+","+ch;

                }

                // Counting Special Characters
                if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' ' || ch == '\t' || ch == '\n')) {
                    count_specialchar++;
                    specialchar_str = specialchar_str+","+ ch;
                }

                // Counting Spaces
                if (ch == ' ') {
                    count_spaces++;
                }

                // Counting Tabs
                if (ch == '\t') {
                    count_tabs++;
                }

                // Counting New Lines
                if (ch == '\n') {
                    count_newlines++;
                }
            }

            // Counting Keywords
            for (String keyword : arr_kw) {
                if (str.contains(keyword)) {
                    count_keywords++;
                }
            }

            // Converting to uppercase character by character
            for (int i = 0; i < len; i++) {
                char ch = str.charAt(i);
                ch = Character.toUpperCase(ch);
                new_str = new_str + ch;
            }
            count_newlines++; 
        }

        System.out.println("Number of Vowels : " + count_vowels);
        System.out.println("Number of Special Characters : " + count_specialchar);
        System.out.println("Number of Spaces : " + count_spaces);
        System.out.println("Number of Tabs : " + count_tabs);
        System.out.println("Number of New Lines : " + (count_newlines-1));
        System.out.println("Number of Keywords : " + count_keywords);
        System.out.println("String in Uppercase : " + new_str);
        System.out.println("Vowels : " + vowels_str);
        System.out.println("Special Characters : " + specialchar_str);
    }
}
