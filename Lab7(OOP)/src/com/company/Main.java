package com.company;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        String[] words = str.split("\\s");
        Arrays.sort(words);
        String maxStr = "";
        for(String subStr:words)
        {
            if (maxStr.length() < subStr.length())
                maxStr = subStr;
            System.out.println(subStr);
        }
        System.out.println("Самое длинное слово: " + maxStr);
    }
}

