FROM ubuntu

RUN apt update

RUN apt install -y nginx curl wget

WORKDIR /var/www/ 

RUN wget -r http://www.google.com

COPY google /etc/nginx/sites-enabled/html

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]