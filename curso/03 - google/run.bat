@echo off

SET CONTAINER_NAME=google_fake

docker stop %CONTAINER_NAME%

docker rm %CONTAINER_NAME%

docker rmi -f %CONTAINER_NAME%:v1

docker build -t %CONTAINER_NAME%:v1 .

cls

docker run -d -p 80:80 --name %CONTAINER_NAME% %CONTAINER_NAME%:v1