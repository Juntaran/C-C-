// ��C����ģ�������IE(http client)����web(http server)����Ϊ

#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main()
{
	// �����ʼ��
    WSADATA wsaData;
    WSAStartup(MAKEWORD(1,1), &wsaData);

	// ����������һ�¶���
	char szWeb[] = "www.baidu.com"; // !!!ǿ��: ���pcһ��Ҫ��pingͨwww.baidu.com, ����������������оͲ�Ҫ������
    HOSTENT *pHost = gethostbyname(szWeb);
    
	// �����ip��ַ
	const char* pIPAddr = inet_ntoa(*((struct in_addr *)pHost->h_addr)) ;
    printf("web server ip is : %s\n", pIPAddr);

	// �����������Ϣ
    SOCKADDR_IN  webServerAddr;
    webServerAddr.sin_family = AF_INET;
    webServerAddr.sin_addr.S_un.S_addr=inet_addr(pIPAddr);
    webServerAddr.sin_port = htons(80);
 
	// �����ͻ���ͨ��socket
    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	// ȥ���Ӷ���
    int nRet = connect(sockClient ,(struct sockaddr*)&webServerAddr, sizeof(webServerAddr));
    if(nRet < 0)
	{
		printf("connect error\n");
		return 1;
	}

	// ׼������﷢��http��GET����
    char szHttpRest[1024] = {0};
	sprintf(szHttpRest, "GET /index.html HTTP/1.1\r\nHost:%s\r\nConnection: Keep-Alive\r\n\r\n", szWeb);
    printf("\n---------------------send is :---------------------\n");
	printf("%s\n", szHttpRest);
 
	// ����tcp����﷢��http��GET����
    nRet = send(sockClient , szHttpRest, strlen(szHttpRest) + 1, 0);
	if(nRet < 0)
	{
		printf("send error\n");
		return 1;
	}

	// �Ѷ��ﷵ�ص���Ϣ�������ļ�test.txt��
	FILE *fp = fopen("test.txt", "w");
	while(1)
	{
			// ÿ�ν���һ���ֽ�
		    char szRecvBuf[2] = {0};
			nRet = recv(sockClient ,szRecvBuf, 1 ,0);
			
			// ���մ���
			if(nRet < 0)
			{
				printf("recv error\n");
				goto LABEL;
			}			
			
			// ���������Ͽ�������
			if(0 == nRet)
			{
				printf("connection has beed closed by web server\n");
				goto LABEL;
			}
			
			static int flag = 0;
			if(0 == flag)
			{
				printf("writing data to file\n");
				flag = 1;
			}

			// �Ѷ��ﷵ�ص���Ϣд���ļ�
			fputc(szRecvBuf[0], fp);
	}


LABEL: // ������ʲ�Ҫд������ �ܶ�ͯЬ����д��
	fclose(fp);
	closesocket(sockClient);  
    WSACleanup();  

    return nRet < 0 ? 1 : 0;
}