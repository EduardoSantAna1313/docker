@echo off

cls

set CONTAINER_NAME=begginer_site

docker stop %CONTAINER_NAME%

docker rm %CONTAINER_NAME%

docker rmi -f %CONTAINER_NAME%:v1

docker build -t %CONTAINER_NAME%:v1 --build-arg user=eduardosantana131 .

docker run -d -p 80:80 --name %CONTAINER_NAME% %CONTAINER_NAME%:v1