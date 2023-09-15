import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip = socket.gethostname()
server_address = (ip, 12345)
server_socket.bind(server_address)
server_socket.listen(5)

print("Loopback Server is waiting for connections...")
client_socket, client_address = server_socket.accept()
print(f"Connection from {client_address} established.")

while True:
    message = input("Jimmy's server: ")
    client_socket.send(message.encode('utf-8'))
    data = client_socket.recv(1024)
    if not data:
        print("Jimmy's client ended chat.")
        break

    print(f"Jimmy's client: {data.decode('utf-8')}")



client_socket.close()
server_socket.close()
