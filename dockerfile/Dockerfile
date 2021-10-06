FROM ubuntu:latest
MAINTAINER Jacob

RUN buildDeps='gcc g++ gdb zstd vim libc6-dev libstdc++10-dev make libevent-dev' \
    && apt-get update \
    && apt-get install  $buildDeps -y \
    && apt install git -y

