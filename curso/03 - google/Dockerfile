FROM ubuntu

RUN apt update

RUN apt install -y nginx curl wget

RUN cd /var/www/ && wget -r http://www.google.com -o index.html

COPY google /etc/nginx/sites-enabled/html

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]