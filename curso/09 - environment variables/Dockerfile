FROM ubuntu

RUN \
    apt update && \
    apt install -y nginx curl

ENV MY_ENV 123

COPY index.html /var/www/html/index.html

COPY config /etc/nginx/sites-enabled/html

RUN echo $MY_ENV

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]