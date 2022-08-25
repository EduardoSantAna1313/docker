FROM ubuntu

ARG user=application

RUN apt update

RUN apt install -y nginx curl wget unzip

WORKDIR /var/www/html/

ENV FILE=beginner-html-site-styled

# Download source
ADD https://codeload.github.com/mdn/$FILE/zip/refs/heads/gh-pages code.zip

RUN unzip code.zip && mv $FILE-gh-pages/* ./

# create new user "$user"
RUN useradd $user && chown $user:$user /var/www/html/ -R && echo `Created user $user`

USER $user

#removing downloaded files
RUN rm -rf code.zip $FILE-gh-pages/

USER root

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]