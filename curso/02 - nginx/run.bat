CLS

set CONTAINER_NAME=custom_nginx

docker rm %CONTAINER_NAME%:v1

docker rmi -f %CONTAINER_NAME%:v1

docker build -t %CONTAINER_NAME%:v1 .

docker run -d -p 80:80 %CONTAINER_NAME%:v1

docker ps