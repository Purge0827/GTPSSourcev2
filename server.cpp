#include "server.h"

ENetHost* server::m_host;
std::vector<player_t*> server::m_players;
int server::m_netId = 1;

void server::init_server() {
	ENetAddress address;
	address.host = 0;
	address.port = 17091;

	m_host = enet_host_create(&address, 1024, 1, 0, 0);

	if (!m_host) {
		printf("Failed to create enet host\n");
		exit(1);
	}

	m_host->checksum = enet_crc32;
	enet_host_compress_with_range_coder(m_host);

	printf("server host created.\n");
}