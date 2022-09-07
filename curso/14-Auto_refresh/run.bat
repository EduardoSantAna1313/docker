SET CONTAINER_NAME=nginx_auto

SET CURRENT_DIR=%cd%\web

echo %CURRENT_DIR%

cls

docker rm -fv %CONTAINER_NAME%

docker run -dti -p 80:80 -v %CURRENT_DIR%:/usr/share/nginx/html --name %CONTAINER_NAME% nginx:alpine
