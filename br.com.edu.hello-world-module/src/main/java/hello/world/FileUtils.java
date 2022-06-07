package hello.world;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.nio.file.Files;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * @author Eduardo
 *
 */
public class FileUtils {

	static final double KB = 1024d;

	static final double MB = KB * KB;

	static final double GB = MB * KB;

	protected static void criarArquivo() throws Exception {

		File file = new File("teste.txt");
		if (file.exists()) {
			Files.delete(file.toPath());
		}

		final Random rand = new Random();

		final var txt = Stream.iterate(65, a -> a + 1).limit(26).map(a -> String.valueOf((char) (int) a))
				.collect(Collectors.joining());

		try (final BufferedWriter writer = new BufferedWriter(new FileWriter(file));) {
			for (int i = 0; i < 100_000; i++) {

				StringBuilder line = new StringBuilder();
				for (int j = 0; j < 20; j++) {
					line.append(txt.charAt(rand.nextInt(txt.length())));
				}
				writer.append(line.toString());
				writer.newLine();
				writer.flush();
			}
			writer.flush();
		}
	}

	public static String format(long memory) {

		if (memory < 1024) {
			return String.valueOf(memory);
		}
		if (memory < MB) {
			double value = memory / KB;
			return String.format("%.2f", value) + " kb";
		}

		if (memory < GB) {
			double value = memory / MB;
			return String.format("%.2f", value) + " Mb";
		}
		double value = memory / GB;
		return String.format("%.2f", value) + " GB";

	}

	static void printMemory() {
		System.out.println("\n");
		System.out.println("Free mem: " + format(Runtime.getRuntime().freeMemory()));
		System.out.println("Total mem: " + format(Runtime.getRuntime().totalMemory()));
		System.out.println("\n");
	}

}
