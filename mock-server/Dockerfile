FROM node:14.15.4

WORKDIR /app

COPY package.json package.json
COPY package-lock.json package-lock.json

RUN npm ci --production

COPY . . 

EXPOSE 4010

CMD [ "npm", "run", "mock-dynamic" ]