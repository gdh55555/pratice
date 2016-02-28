FROM ubuntu:14.04
MAINTAINER Gavin "541246123@qq.com"
ENV REFRESHED_AT 2014-06-01

COPY sources.list /etc/apt/

RUN apt-get update -qq
RUN apt-get -yq install  ruby redis-tools
RUN gem install --no-rdoc --no-ri sinatra json redis

RUN mkdir -p /opt/webapp

EXPOSE 4567

CMD ["/opt/webapp/bin/webapp"]
