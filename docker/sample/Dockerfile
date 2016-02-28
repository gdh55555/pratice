FROM ubuntu:14.04
MAINTAINER Gavin "541246123@qq.com"
ENV REFRESHED_AT 2014-06-01
COPY sources.list /etc/apt/
RUN apt-get update
RUN apt-get -y -q install nginx
RUN mkdir -p /var/www/html
ADD nginx/global.conf /etc/nginx/conf.d/
ADD nginx/nginx.conf /etc/nginx/nginx.conf
EXPOSE 80
