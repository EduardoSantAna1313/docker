FROM azul/zulu-openjdk-alpine:11 as packager

# RUN apk --no-cache add openjdk11-jdk openjdk11-jmods

COPY app/ app/

WORKDIR app/

ENV JAVA_MINIMAL=/opt/jre

RUN jlink --verbose \
    --add-modules java.base \
    --compress 2  \
    --no-header-files \
    --no-man-pages \
    --output $JAVA_MINIMAL

FROM alpine

ENV JAVA_MINIMAL=/opt/jre
ENV PATH="$PATH:$JAVA_MINIMAL/bin"

COPY --from=packager "$JAVA_MINIMAL" "$JAVA_MINIMAL"
COPY "app/target/" "."

CMD [ "hello.world.Main" ]

ENTRYPOINT [ "java" ]