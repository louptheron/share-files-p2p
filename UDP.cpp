#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <cstring>

#include "UDP.h"

	UDP::UDP(int BUFLEN,int  NPACK,int  PORT_SERVER,char * SRV_IP) : BUFLEN(BUFLEN), NPACK(NPACK), PORT_SERVER(PORT_SERVER), SRV_IP(SRV_IP){
		char buf[this->getBufLen()];
		setBuf(buf);
		if(this->setS(socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)))
			perror("Could not create socket");
		}
	 
	int UDP::receive(){
		//create address information's struct
		struct sockaddr_in si_me{};

		si_me.sin_family = AF_INET;
		si_me.sin_port = htons(this->getPort());
		si_me.sin_addr.s_addr = htonl(INADDR_ANY);
		setSi_me(si_me);
	
		setSLen(sizeof(this->getSi_other()));
		
		//assign the address specified by AddrSi_me to the socket S
		if(bind(this->getS(), (struct sockaddr *) this->getAddrSi_me(), sizeof(this->getSi_me()))==-1){
			perror("error bind");
			return -1;
		}
		char mybuf[this->getBufLen()];
		//Check for the number of packet to receive
		for(i=0; i<this->getNPack(); i++){
			if(recvfrom(this->getS(), mybuf, sizeof(mybuf), 0, (struct sockaddr*)this->getAddrSi_other(), this->getAddrSLen())==-1){
				perror("error during receiving");
				return -2;
			}
		printf("Received packet from %s:%d\nData: %s\n\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), mybuf);
		}
	}

	int UDP::send(){
		//create address information's struct
		struct sockaddr_in si_other{};
		si_other.sin_family = AF_INET;
		si_other.sin_port = htons(this->getPort());
		setSi_other(si_other);
		
		//convert ip to binary
		if (inet_aton(this->getSrv_Ip(), this->getSinAddr())==0){
			perror("inet_aton failed\n");
			return -1;
		}
		
		//send the data
		for(i = 0; i<this->getNPack(); i++){
			printf("sending packet %d...", i);
			this->setBuf("This is a packetThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packeThis is a packetttttttttttttttttttt aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaah");
			int count = sendto(this->getS(), this->getBuf(), this->getBufLen(), 0, (struct sockaddr *) this->getAddrSi_other(), this->getSLen());
			if(count < 0){
				perror("Could not send message");
				return -2;
			}else{
				printf("OK (%d)\n", count);
			}
		}
		return 1;
	}

	int main(void){
		UDP myUDP;
		//myUDP.send();
		myUDP.receive();
		close(myUDP.getS());
		return 0;
	}

