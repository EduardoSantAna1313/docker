# syntax=docker/dockerfile:1
FROM amazoncorretto:11

RUN echo $' \
public class Hello { \
public static void main(String[] args) { \
System.out.println("Welcome to Amazon Corretto!"); \
} \
}' > Hello.java
RUN javac Hello.java

CMD ["java", "Hello"] 