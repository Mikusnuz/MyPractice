#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>


DWORD WINAPI sendMessage() {
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2, 2), &wsdata);

	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addr;
	ZeroMemory(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(3001);

	while (1) {
		char msg[100] = "";
		printf("보낼 메세지 : ");
		gets(msg);
		printf("\n");
		sendto(sock, msg, sizeof(msg), 0, (SOCKADDR*)&addr, sizeof(addr));
	}
}

void makeThread() {

	DWORD dwThreadId = 1;
	DWORD dwThrdParam = 1;
	HANDLE hThread = CreateThread(NULL, 0, sendMessage, &dwThrdParam, 0, &dwThreadId);

	printf("The thread ID: %d\n", dwThreadId);

	if (hThread == NULL)
		printf("CreateThread() failed, error : %d\n", GetLastError());
	else
		printf("CreateThread() is OK!\n");
}

int main() {
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2, 2), &wsdata);

	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addr;
	ZeroMemory(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(3000);
	makeThread();

	bind(sock, (SOCKADDR*)&addr, sizeof(addr));

	while (1) {
		char msg[100] = "";
		SOCKADDR_IN clntAddr;
		ZeroMemory(&clntAddr, sizeof(clntAddr));
		int clntAddrSz = sizeof(clntAddr);
		recvfrom(sock, msg, sizeof(msg), 0, (SOCKADDR*)&clntAddr, &clntAddrSz);
		printf("[%s] 수신 데이터 : %s\n", inet_ntoa(clntAddr.sin_addr), msg);
	}

	closesocket(sock);

	WSACleanup();
	return 0;
}