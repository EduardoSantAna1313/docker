FROM amazon/aws-cli:latest as aws

ARG S3_FILE
ARG AWS_ACCESS_KEY_ID
ARG AWS_SECRET_ACCESS_KEY
ARG AWS_DEFAULT_REGION=sa-east-1

RUN \
    # creating output folder
    mkdir /root/downloads/ && \
    #Download file
    aws s3 cp s3://$S3_FILE /root/downloads/

FROM alpine

COPY --from=aws /root/downloads/ /opt/

WORKDIR /opt/

CMD cat $(ls)