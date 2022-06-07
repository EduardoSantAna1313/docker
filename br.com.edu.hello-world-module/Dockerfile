# syntax=docker/dockerfile:1
FROM amazoncorretto:11

RUN mkdir app

ARG JAR_FILE

ADD /target/Main.jar /app/Main.jar

WORKDIR /app

ENTRYPOINT java -jar Main.jar