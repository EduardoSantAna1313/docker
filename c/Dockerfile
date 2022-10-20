FROM gcc

ARG FILE

COPY $FILE /home/

WORKDIR /home/

RUN gcc -o myapp $FILE

CMD ["./myapp"]