@echo off

SET CONTAINER_NAME=java_maven_corretto

cls

docker rm -f %CONTAINER_NAME%
docker rmi -f %CONTAINER_NAME%:v1

docker build -t %CONTAINER_NAME%:v1 --build-arg project=hello.world -f Dockerfilewithcorretto .

docker run --name %CONTAINER_NAME% %CONTAINER_NAME%:v1