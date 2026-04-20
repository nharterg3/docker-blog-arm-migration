FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY *.h *.cpp ./

RUN g++ -O3 -march=armv8-a+simd -std=c++11 -o benchmark \
    main.cpp \
    matrix_operations.cpp

CMD ["./benchmark"]
