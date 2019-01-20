#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BIT_NUM 8
#define PARITY_BIT 4

typedef struct { // �׳�.. �迭�� ����ϰ� �Լ��� ���ڷ� �ѱ�� ���� ����ü..
	int arr[BIT_NUM+PARITY_BIT];
	int p_arr[PARITY_BIT];
}binaryCode;

int isPower(int num) { //2�� �������� return
	return num && !((num - 1) & num);
}

binaryCode decimalToBinary(int input_num) { //10���� -> 2������ �ٲ㼭 ����
	binaryCode binary;
	for (int i = BIT_NUM + PARITY_BIT -1; 0 <= i; i--) {
		if (isPower(BIT_NUM + PARITY_BIT - i) || i == BIT_NUM + PARITY_BIT - 1) {
			binary.arr[i] = -1;
		}
		else {
			binary.arr[i] = input_num % 2;
			input_num /= 2;
		}
	}
	return binary;
}

void printArr(int *hamming_binary) { // �迭�� ���ڰ� ���...
	printf("\n");
	for (int i = BIT_NUM + PARITY_BIT; 0 < i; i--) {
		printf(" %2d ", i);
	}
	printf("\n");
	for (int i = 0; i < BIT_NUM + PARITY_BIT; i++) {
		printf(" %2d ", hamming_binary[i]);
	}
	printf("\n");
}

binaryCode returnP(binaryCode binary) { // �ع��ڵ��� �� ĭ(-1)�� ���� ¦���и�Ƽ�� ���Ͽ� ����.
	for (int i = 0; i < PARITY_BIT; i++) {
		int cnt = PARITY_BIT + BIT_NUM - 1;
		int parity_cnt = 0;
		int sum = 0;

		printf("\n");
		while (0 <= cnt) {
			int binary_index = (PARITY_BIT + BIT_NUM) - cnt;
			switch (i) {
			case 0:
				if (binary.arr[cnt] != -1 && cnt % 2 != 0) {
					printf("[ %d ]", binary.arr[cnt]);
					sum += binary.arr[cnt];
					parity_cnt++;
				}
				break;
			case 1:
				if (binary.arr[cnt] != -1 && (binary_index % 4 == 2) || binary_index % 4 == 3) {
					printf("[ %d ]", binary.arr[cnt]);
					sum += binary.arr[cnt];
					parity_cnt++;
				}
				break;
			case 2:
				if (binary.arr[cnt] != -1 && (4 <= (binary_index % 8) && (binary_index % 8) < 8)) {
					printf("[ %d ]", binary.arr[cnt]);
					sum += binary.arr[cnt];
					parity_cnt++;
				}
				break;
			case 3:
				if (binary.arr[cnt] != -1 && (8 <= (binary_index % 16) && (binary_index % 16) < 16)) {
					printf("[ %d ]", binary.arr[cnt]);
					sum += binary.arr[cnt];
					parity_cnt++;
				}
				break;
			}
			cnt--;
		}
		printf("  ¦�� �и�Ƽ ��Ʈ : %d \n", sum % 2 == 0 ? 0 : 1);
		binary.p_arr[i] = sum % 2 == 0 ? 0 : 1;
	}

	return binary;
}

binaryCode mergeHammingCode(binaryCode binary) { // ��ĭ�� �շ��ִ� 2���� �迭�� ��ĭ(-1) ��ġ�� ¦�� �и�Ƽ ����
	int cnt = 0;
	for (int i = PARITY_BIT + BIT_NUM - 1; 0 <= i; i--) {
		if (binary.arr[i] == -1) {
			binary.arr[i] = binary.p_arr[cnt];
			cnt++;
		}
	}
	return binary;
}

int main() {
	int input_num = -1;
	binaryCode binary;
	
	printf("8��Ʈ�� ����(1~255)�� �Է��ϼ���.\n");
	scanf("%d", &input_num);
	while (input_num < 1 || 255 < input_num) {
		printf("�ٽ� �Է��ϼ���\n");
		scanf("%d", &input_num);
	}
	binary = decimalToBinary(input_num);
	printf("\n****************   2������ ��ȯ   ****************");
	printArr(binary.arr);
	printf("**************************************************");
	binary = returnP(binary);
	binary = mergeHammingCode(binary);
	printf("\n****************  �ع��ڵ� ��ȯ  ****************");
	printArr(binary.arr);
	printf("*************************************************");

	scanf("%d",input_num);
	return 0;
}