//
// EPITECH PROJECT, 2018
// comm
// File description:
// hpp
//

class Communication {
public:
	void send_message(int server_fd, std::string buffer);
	std::string recieve_message(int client_fd);
};
