#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "RingBuffer.h"

using namespace std;

CRingBuffer c1;
CRingBuffer c2;
int c = 0;

int main()
{
	const char* inputdata = "1234567890 abcdefghijklmnopqrstuvwxyz 1234567890 abcdefghijklmnopqrstuvwxyz 12345";
	
	char* moveptr = (char*)inputdata;

	char str_input[100] = { 0 };
	char str_output[100] = { 0 };
	char str_peekout[100] = { 0 };
	
	int ret;

	int staticinput = 0;

	while (1)
	{
		int input_randnum = rand() % 82;
		int ouput_randnum = rand() % 82;

		int sendbuffersize = c1.GetFreeSize();

		//������ �ִ�. ���� �� ���� �𸥴ٴ� ��
		//�۽Ź��� ũ�Ⱑ �����ϸ� ©���� ���ٵ� ©�� �����ʹ� ��� ó����?
		//�۽Ź��� ũ�⸦ �����ͼ� , input_randnum���� ���̸� ��.
		if (input_randnum > sendbuffersize)
			input_randnum = sendbuffersize;


		for (int i = 0; i < input_randnum; ++i)
		{
			if (staticinput % 81 == 0)
			{
				moveptr = (char*)inputdata;
				staticinput = 0;
			}
			str_input[i] = *moveptr;
			++moveptr;
			++staticinput;
		}

		int sret = c1.Enqueue(str_input, input_randnum);

		int pret = c1.Peek(str_peekout, ouput_randnum);
		//int pret2 = c1.MoveRear(pret);

		int rret = c1.Dequeue(str_output, ouput_randnum);
		
		if (memcmp(str_peekout, str_output, 100) != 0)
		{
			int w = 4;
		}

		if(!(sret == 0 && rret == 0))
			printf("%s", str_output);
		

		/*
		�����õ��Ϸ���..
		str_output�� �����͵��� ���, ret��ŭ �ݺ��ϰ� ���� 81���� ä���ٸ�
		ī�ǵ� ���ڿ��� ���� �´��� �˻��� ��, strcmp
		���ڿ� NULL�� �ʱ�ȭ ī���ôٽ� 0���� �ݺ�
		
		*/
		

		memset(str_input, '\0', 100);
		memset(str_output, '\0', 100);
		memset(str_peekout, '\0', 100);

		++c;
		if (c == 292189)
		{
			char b = 4;
		}

		if (c == 292192)
		{
			char b = 4;
		}
		if (c == 292193)
		{
			char b = 4;
		}
		if (c == 292194)
		{
			char b = 4;
		}
		if (c == 292200)
		{
			char b = 4;
		}

	}


	return 0;
}