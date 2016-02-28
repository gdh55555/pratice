FROM ubuntu:14.04
MAINTAINER Gavin "541246123@qq.com"
ENV REFRESHED_AT 2014-06-01

COPY sources.list /etc/apt/

RUN apt-get update -yqq
RUN apt-get -yqq install redis-server redis-tools

EXPOSE 6379
ENTRYPOINT ["/usr/bin/redis-server"]

CMD []
