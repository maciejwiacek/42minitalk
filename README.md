# Minitalk - Simple Client-Server Communication
Minitalk is a small communication project developed as part of the 42 School curriculum. The project showcases the use of signals, bitwise operations, and process control to establish a basic messaging system.

## Table of Contents
- [Features](#features)
- [Usage](#usage)
- [Gained Knowledge](#gained-knowledge)

## Features
- Server that handles incoming messages from multiple clients.
- Client that sends a string to the server by converting it into binary signals.
- The communication using SIGUSR1 and SIGUSR2 signals.

## Usage
1. Clone the repository
```bash
https://github.com/maciejwiacek/42minitalk.git && cd 42minitalk
```
2. Build the project
```bash
make
```
3. Start the server
```bash
./server
```
4. Send a message from the client
```bash
./client [server_pid] "Your message"
```

## Example Usage
1. Run the server
   ```bash
   ./server
   ```
   Example output
   ```bash
   Server PID: 12345
   ```
2. Send a message from client
   ```bash
   ./client 12345 "Hello, World!"
   ```
   Server output
   ```bash
   Hello, World!
   ```

## Gained Knowledge:
- Understanding of UNIX signals and how to use them for inter-process communication.
- Experience with bitwise operations to send and receive data using signals.
- Manage process control, signal handling, ensure reliable communication between a client and server.
