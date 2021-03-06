/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int searchBitNum(int input) { // 비트의 갯수 리턴
	int i = 0;
	while (input > 0) {
		input /= 2;
		i++;
	}
	return i;
}

int decimalToBinary(int input) { //10진수 -> 2진수로 바꿔서 리턴
	int bit_num = searchBitNum(input);
	int *binary = malloc(sizeof(int)*bit_num);
	binary[0] = bit_num;
	for (int i = 1; i <= bit_num; i++) {
		binary[i] = input % 2;
		input /= 2;
	}
	return binary;
}

int searchParityBit(int bit) { //패리티 비트의 갯수 리턴
	double cnt = 1;
	while (1) {
		if (bit <= pow(2, cnt) - cnt) {
			return (int)cnt;
		}
		else {
			cnt++;
		}
	}
}

void swap(int *binary, int x, int y) //배열의 앞뒤를 스왑
{
	int temp = binary[x];
	binary[x] = binary[y];
	binary[y] = temp;
}

int sortingBinary(int *binary, int start, int end) { //배열의 앞뒤를 스왑
	if (start < end) {
		swap(binary, start, end);
		sortingBinary(binary, start + 1, end - 1);
	}
	return binary;
}

int isPower(int num) //2의 제곱인지 return
{
	return num && !((num - 1) & num);
}

int createBlank(int parity_bit, int bit_num, int *binary) { //인풋값의 2진수에 해밍부호(blank) 삽입
	int powerCnt = 0;
	int *p_num = malloc(sizeof(int)*(bit_num+parity_bit));
	for (int i = 0; i < parity_bit + bit_num; i++) {
		p_num[i] = -1;
	}
	for (int i = 1; i <= parity_bit + bit_num; i++) {
		if (isPower(i) == 1) {
			powerCnt++;
		}
		else {
			p_num[parity_bit + bit_num - i] = binary[i - powerCnt];
		}
	}
	return p_num;
}

int hammingCode(int *binary,int parity_bit, int bit_num) { //해밍코드 생성
	printf("\n");
	for (int i = 0; i < parity_bit; i++) {
		int pow_index = (i ? pow(2, (double)i) : 1);
		int cnt = parity_bit + bit_num - 1;
		int cursor = 1;
		int flag = 0;
		while (0 <= cnt) {
			if (i==0) {
				if (binary[cnt] != -1 && (((binary[cnt] % 2) != 0))) {
					printf("[%d  ::: %d]", cnt+1, binary[cnt]);
				}
			}
			else {
				if (cursor == pow_index) {
					flag = 1;
				}
				else if (cursor == 0) {
					flag = 0;
					cursor = pow_index;
				}
				if (flag) {
					if (binary[cnt] != -1) {
						printf("[%d  ::: %d ]", cnt+1, binary[cnt]);
					}
					cursor--;
				}
				else {
					cursor++;
				}
			}
			cnt--;
		}
		printf("\n");
	}
	return binary;
}

int main()
{
	int input = -1;
	int *input_binary;
	int bit_num;
	int parity_bit;
	int *p_num; // p1,p2,p3...

	printf("정수 값을 입력 : \n");
	printf("입력   >>   ");
	scanf("%d", &input);

	input_binary = decimalToBinary(input);
	
	bit_num = input_binary[0];
	printf("비트 수 : %d \n", bit_num);
	
	parity_bit = searchParityBit(bit_num);
	
	printf("패리티 비트 갯수 : %d \n", parity_bit);
	printf("\n\n 변환된 2진수 값 \n");
	//10진수에서 변환된 2진수값 출력
	for (int i = 1; i <= bit_num; i++) {
		printf(" %d ", input_binary[i]);
	}

	input_binary = createBlank(parity_bit, bit_num, input_binary);

	//해밍부호가 삽입된 2진수값 출력
	printf("\n\n");
	for (int i = parity_bit + bit_num - 1; 0 <= i; i--) {
		printf("%2d  ",i+1);
	}
	printf("\n");
	printf("*************************************************\n");
	for (int i = 0; i <= parity_bit + bit_num - 1; i++) {
		printf("%2d  ", input_binary[i]);
	}
	printf("\n\n");
	input_binary =  hammingCode(input_binary, parity_bit, bit_num);

	//여기까지가 2진수로 변환 후 내가 원하는 형태로의 전처리 과정...
	//패리티 비트 갯수도 파악했으니 이제 할 일은 input_binary의 1부터 2ⁿ위치에
	//패리티 비트를 삽입하여 해밍코드를 찾는 것.

	//free해주는거잊지말자
	scanf("%d", &input);
	
}
*/