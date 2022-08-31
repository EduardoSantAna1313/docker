FROM maven:3-openjdk-11-slim as builder

ARG project

COPY $project /app

WORKDIR /app

RUN mvn package -DskipTests

FROM adoptopenjdk/openjdk11:alpine-slim

ARG project

COPY --from=builder /app/target/$project.jar /app.jar

CMD java -jar /app.jar