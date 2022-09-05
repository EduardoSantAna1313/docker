SET CONTAINER_NAME=copyyocontainer

docker rm -f %CONTAINER_NAME%

docker rmi -f %CONTAINER_NAME%:v1

docker build -t %CONTAINER_NAME%:v1 .

docker run -d -p 80:80 --name %CONTAINER_NAME% %CONTAINER_NAME%:v1