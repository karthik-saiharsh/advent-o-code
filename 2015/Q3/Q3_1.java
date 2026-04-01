// Question: https://adventofcode.com/2015/day/3

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.HashSet;

public class Q3_1 {
    public static void main(String[] args) throws FileNotFoundException {
        File f = new File("input.txt");
        Scanner scanner;

        scanner = new Scanner(f);

        String line = scanner.nextLine();

        scanner.close();

        int current[] = { 0, 0 };

        HashSet<String> visited = new HashSet<>();

        int houseVisited = 1;
        visited.add(current[0] + "," + current[1]);

        for (char c : line.toCharArray()) {
            switch (c) {
                case '^':
                    current[1] = current[1] + 1;
                    break;

                case 'v':
                    current[1] = current[1] - 1;
                    break;
                case '>':
                    current[0] = current[0] + 1;
                    break;
                case '<':
                    current[0] = current[0] - 1;

                default:
                    break;
            }

            if (!visited.contains(current[0] + "," + current[1])) {
                houseVisited++;
            }

            visited.add(current[0] + "," + current[1]);
        }

        System.out.println(houseVisited);
    }
}