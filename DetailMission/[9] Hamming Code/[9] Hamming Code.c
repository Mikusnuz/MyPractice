#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int searchBitNum(int input) {
	int i = 0;
	while (input > 0) {
		input /= 2;
		i++;
	}
	return i;
}

int* decimalToBinary(int input) {
	int bitNum = searchBitNum(input);
	int *binary = malloc(sizeof(int)*bitNum);
	while (0<bitNum) {//여기까지햇음
		binary[bitNum] = input % 2;
		bitNum /= 2;
		bitNum--;
	}

	printf("사이즈오브%d\n", sizeof(binary));
	return binary;
}
int searchParityBit(int bit) {
	int flag = 1;
	double cnt = 1;
	while (flag) {
		if (bit <= pow(2, (double)cnt) - cnt) {
			printf("비트수:%d, 제곱값:%f 카운트:%f \n", bit, pow(2, (double)cnt),cnt);
			return cnt;
		}
		else {
			cnt++;
		}
	}
}



int main()
{
	int input=-1;
	int *input_binary;
	int bit,parity_bit;
	printf("정수 값을 입력 : \n");
	scanf("%d", &input);
	
	input_binary=decimalToBinary(input);
	bit = sizeof(input_binary);
	printf("비트수 [%d] \n", bit);
	parity_bit = searchParityBit(bit);
	printf(" ㄱㄱ %d 패리티비트",parity_bit);

	scanf("%d", &input);

}
