FROM ubuntu

ENV HOME=/home/app

RUN apt update -qq
RUN apt install -y git build-essential cmake gcc libssl-dev
