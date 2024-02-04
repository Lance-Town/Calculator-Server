# Client Server Calculator

## Description

A Basic client-server calculator in the TCP domain. The repository contains three code files: one each for the server (`server.c`), client (`client.c`), and calculation functions (`calc.c` and `calc.h`). Additionally, a Makefile is provided for easy compilation.

## Files

1. `server.c`: The server listens for incoming connections on a specified port, receives an equation from the client, tokenizes it using the `calc.h` functions, performs the calculation, and sends the result back to the client.

2. `client.c`: The client connects to the server using the provided hostname and port, prompts the user to enter an equation, sends it to the server, and displays the result received from the server.

3. `calc.c` and `calc.h`: The calculation functions. The header file contains functions for performing basic calculations and tokenizing equations.

4. `Makefile`: Provides rules for compiling the server and client programs.

## Usage

1. Compile the server and client using the provided Makefile:
    ```bash
    make
    ```

2. Run the server in one terminal:
    ```bash
    ./server <port_number>
    ```

3. Run the client in another terminal:
    ```bash
    ./client <hostname> <port_number>
    ```

4. Enter the equation in the client terminal to see the result.

## Makefile Commands

- `all`: Builds both the server and client.
- `server`: Builds the server.
- `client`: Builds the client.
- `clean`: Removes object files.
- `cleanAll`: Cleans all compiled files.
