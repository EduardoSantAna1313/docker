package org.example;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;


public class App 
{
    public static void main( String[] args ) throws Exception {
        System.out.println( "Hello World!" );
        createFile();


        var start = LocalDateTime.now();

        Files.lines(Path.of("teste.txt")).parallel().forEach(l -> l.concat(""));

        System.out.println("Time: " + start.until(LocalDateTime.now(), ChronoUnit.NANOS) + "ns");
    }

    private static void createFile() throws IOException {

        BufferedWriter writer = new BufferedWriter(new FileWriter("teste.txt"));

        for (int i =0; i < 50_000_000; i++) {
            writer.append(i + "\tTESTETESTESTESTETESTETSTETSTETESTETESTESTESTETESTETSTETSTETESTETESTESTESTETESTETSTETSTETESTETESTESTESTETESTETSTETSTE");
            writer.newLine();
        }

        writer.flush();

    }
}
