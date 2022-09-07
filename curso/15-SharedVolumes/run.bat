docker rm -fv generator

docker rm -fv ngix_generator

cls

docker build -t generator:v1 .

docker run -d --name generator -v %cd%\volume:/opt/ generator:v1

docker run -d -p 80:80 --name ngix_generator -v %cd%\volume:/usr/share/nginx/html nginx:alpine