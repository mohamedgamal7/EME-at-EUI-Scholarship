import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = socket.gethostname()
server_address = (ip, 12345)
client_socket.connect(server_address)
print("Connected to the Loopback Chat Server.")


while True:
    data = client_socket.recv(1024)
    if not data:
        print("Connection closed by the server.")
        break

    print(f"Jimmy's server: {data.decode('utf-8')}")

    # Send a message to the server
    message = input("Jimmy's client: ")  # Get a message from the client user
    client_socket.send(message.encode('utf-8'))

# Close the client socket
client_socket.close()
