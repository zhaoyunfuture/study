FROM ubuntu:latest
MAINTAINER Jacob

RUN buildDeps='gcc g++ libc6-dev make libevent-dev' \
    && apt-get update \
    && apt-get install  $buildDeps -y \
	&& apt install git -y

