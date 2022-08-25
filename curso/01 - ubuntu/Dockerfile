FROM ubuntu

RUN apt update

RUN apt install -y nginx curl

COPY index.html /var/www/html/index.html

COPY tutorial /etc/nginx/sites-enabled/html

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]