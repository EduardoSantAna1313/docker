package hello.world;

import static hello.world.FileUtils.*;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Predicate;
import java.util.stream.Stream;

/**
 * @author Eduardo
 *
 */
public class Main {

	private static final String COMPARATOR = "ABCD";

	private static final Predicate<String> predicate = a -> a.contains(COMPARATOR);

	public static void main(String[] args) throws Exception {

		System.out.println("Iniciando o app");

		printMemory();

		System.out.println("Dir: " + Paths.get("").toAbsolutePath());

		System.out.println("Criando arquivo teste...");

		criarArquivo();

		System.out.println("Arquivo criado!");

		processStreamLines();

		processReadAllLines();

		processGetAll();

	}

	private static void processStreamLines() throws IOException {

		System.out.println("\n\n");
		System.out.println("Process Files.lines");
		System.out.println("\n\n");
		printMemory();

		final AtomicInteger lineNum = new AtomicInteger(0);
		try (final Stream<String> lines = Files.lines(Path.of("teste.txt"));) {

			lines.forEach(line -> {
				if (predicate.test(line)) {
					System.out.println("Line " + lineNum + " has " + COMPARATOR);
				}
				lineNum.incrementAndGet();
			});

		}
		System.out.println("Lines: " + lineNum);

		printMemory();

	}

	private static void processReadAllLines() throws IOException {

		System.out.println("\n\n");
		System.out.println("Process Files.readAllLines");
		System.out.println("\n\n");
		printMemory();

		final AtomicInteger lineNum = new AtomicInteger(0);

		Files.readAllLines(Path.of("teste.txt")).forEach(line -> {
			if (predicate.test(line)) {
				System.out.println("Line " + lineNum + " has " + COMPARATOR);
			}
			lineNum.incrementAndGet();
		});

		System.out.println("Lines: " + lineNum);

		printMemory();

	}

	private static void processGetAll() {
		System.out.println("\n\n");
		System.out.println("Process all");
		System.out.println("\n\n");

		printMemory();

		try (final InputStream is = new FileInputStream("teste.txt")) {

			final String[] lines = new String(is.readAllBytes()).split(System.lineSeparator());

			int lineNum = 0;
			for (final String line : lines) {
				if (predicate.test(line)) {
					System.out.println("Line " + lineNum + " has " + COMPARATOR);
				}
				lineNum++;
			}
			System.out.println("Lines: " + lineNum);

		} catch (Exception e) {
			e.printStackTrace();
		}
		printMemory();

	}
}
