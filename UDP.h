#ifndef _UDP_H_
#define _UDP_H_


class UDP {
	private:
	const int buflen;
	const int pack_number;
	const int port_server;
	const int PORT_CLIENT = 9000;
	const char * server_ip;
	char *buf;
	struct sockaddr_in si_me, si_other;
	int s, i;
	socklen_t slen;
	


	public:
	UDP(int buflen = 512, int pack_number = 10, int port_server = 8000, char * server_ip = "0");
	int send();
	int receive();
	inline const int getPort(){return this->port_server;}
	inline const int getPortClient(){return this->PORT_CLIENT;}
	inline const int getNPack(){return this->pack_number;}
	inline int getBufLen(){return this->buflen;}
	inline char* getBuf(){return this->buf;}
	inline void setBuf(char *buf){this->buf = buf;}
	inline sockaddr_in getSi_me(){return this->si_me;}
	inline sockaddr_in * getAddrSi_me(){return &si_me;}
	inline void setSi_me(sockaddr_in si_me){this->si_me = si_me;}
	inline sockaddr_in getSi_other(){return this->si_other;}
	inline in_addr * getSinAddr(){return &si_other.sin_addr;}
	inline sockaddr_in * getAddrSi_other(){return &si_other;}
	inline void setSi_other(sockaddr_in si_other){this->si_other = si_other;}
	inline int getS(){return this->s;}
	inline bool setS(int s){
		if(s==-1)
			return true;
		this->s = s;
		return false;
	}
	inline socklen_t getSLen(){return this->slen;}
	inline void setSLen(socklen_t slen){this->slen = slen;}
	inline socklen_t * getAddrSLen(){return &slen;}
	inline const char * getSrv_Ip(){return this->SRV_IP;}
};

#endif
