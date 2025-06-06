# Basis-Image mit GCC
FROM gcc:latest

WORKDIR /app

COPY main.c .

# Kompilieren
RUN gcc main.c -o lookup_error

# Beim Start wird direkt das Programm ausgeführt
ENTRYPOINT ["./lookup_error"]
