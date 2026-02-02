# *This project has been created as part of the 42 curriculum by tlamit*

## Description

Minitalk is a simple client-server communication project developed as part of the 42 school curriculum. The goal of this project is to create a program where a client can send a string of characters to a server, which then displays it. The communication between the client and the server is done exclusively using UNIX signals, specifically `SIGUSR1` and `SIGUSR2`.

The server starts by displaying its Process ID (PID). The client takes the server's PID and the string to be sent as arguments. The client then encodes the string into a sequence of binary signals (bits), sending `SIGUSR1` for a `1` and `SIGUSR2` for a `0`. The server listens for these signals, reconstructs the characters of the string from the bits, and prints the message once it's fully received. To acknowledge the receipt of each bit, the server sends a signal back to the client.

## Instructions

### 1. Submodule Initialization

This project uses `Libft` as a submodule. To initialize it, run the following command at the root of the repository:

```bash
git submodule update --init --recursive
```

### 2. Compilation

To compile the project, run the `make` command:

```bash
make
```

This will create two executables: `server` and `client`.

Other available `make` commands are:

- `make clean`: Removes the object files.
- `make fclean`: Removes the object files and the executables.
- `make re`: Cleans and rebuilds the project.

### 3. Execution

1. **Run the server:**

    ```bash
    ./server
    ```

    The server will start and print its PID.

2. **Run the client:**

    In another terminal, run the client with the server's PID and the message you want to send:

    ```bash
    ./client <SERVER_PID> "Hello, world!"
    ```

    Replace `<SERVER_PID>` with the PID displayed by the server. The server will then display the message.

## Resources

- **signal.h:** For more information on UNIX signals, you can refer to the `signal.h` manual page:
- [Linux man page for signal](https://man7.org/linux/man-pages/man7/signal.7.html)

- **AI Usage:**
- An AI assistant was used to generate the `README.md` file based on the project's source code and structure. The AI analyzed the `Makefile`, header files, and C source files to understand the project's functionality, build process, and execution flow, and then generated this documentation according to the specified requirements.
