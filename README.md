# minitalk

`minitalk` is a 42 project focused on inter-process communication using UNIX signals. It introduces fundamental concepts of UNIX programming that will be essential in later projects.

## 🛠️ Project Overview

The objective is to create a client and a server program that communicate using signals (`SIGUSR1` and `SIGUSR2`). The client encodes a message bit by bit and sends it to the server, which decodes and prints it.

## 📚 Key Concepts

- Inter-process communication (IPC)
- UNIX signals: `SIGUSR1`, `SIGUSR2`
- Bitwise operations
- Signal handling via `signal()` or `sigaction()`

## 💡 Usage

1. Start the server:

```bash
./server
```

It will display its PID.

2. In another terminal, run the client with the server's PID and your message:

```bash
./client <server_pid> "Hello, world!"
```

## 🔧 Compilation

Use the provided `Makefile` or compile manually with:

```bash
gcc -Wall -Wextra -Werror server.c -o server
gcc -Wall -Wextra -Werror client.c -o client
```

## 📌 Notes

- Only `SIGUSR1` and `SIGUSR2` are allowed
- No use of external libraries
- Must conform to the 42 Norm
- Messages must be reliably transmitted, including special characters and spaces

